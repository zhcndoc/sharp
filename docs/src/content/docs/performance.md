---
title: 性能
---

## 并行与并发

Node.js 在处理对原生模块（如 sharp）的异步调用时使用 libuv 管理的线程池。

sharp 可以并行处理的最大图像数量由 libuv 的 
[`UV_THREADPOOL_SIZE`](https://nodejs.org/api/cli.html#uv_threadpool_sizesize) 
环境变量控制，默认值为 4。

当使用超过 4 个物理 CPU 核心时，应在 Node.js 进程启动前设置此环境变量，以增加线程池大小。

```sh
export UV_THREADPOOL_SIZE="$(lscpu -p | egrep -v "^#" | sort -u -t, -k 2,4 | wc -l)"
```

libvips 使用 glib 管理的线程池来避免频繁创建新线程带来的开销。

默认用于并发处理每张图像的线程数与 CPU 核心数量相同，
但在使用基于 glibc 的 Linux 且未使用 jemalloc 的情况下，默认线程数为 `1`，以帮助减少内存碎片。

可使用 [`sharp.concurrency()`](/api-utility/#concurrency) 来管理每张图像的线程数。

在使用默认的 Linux glibc 内存分配器时，为减少内存碎片，
应在 Node.js 进程启动前设置
[`MALLOC_ARENA_MAX`](https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation-Tunables.html)
环境变量以减少内存池数量。

```sh
export MALLOC_ARENA_MAX="2"
```

## 基准测试

一个用来比较本模块与其他替代方案性能的测试。

启用缓存（默认）且使用 8 核以上机器时，可以预期 libvips 性能更佳，
尤其是具有较大 L1/L2 CPU 缓存的机器。

相关（解）压缩库的 I/O 限制通常决定最大吞吐量。

### 竞争者

* [jimp](https://www.npmjs.com/package/jimp) v1.6.0 - 纯 JavaScript 图像处理。
* [imagemagick](https://www.npmjs.com/package/imagemagick) v0.1.3 - 仅支持文件系统，且“*已经很长时间没有维护*”。
* [gm](https://www.npmjs.com/package/gm) v1.25.1 - 功能完整的 GraphicsMagick `gm` 命令行工具封装库，但“*已被废弃*”。
* sharp v0.34.0 / libvips v8.16.1 - 关闭 libvips 缓存，以保证测试的公平性。

### 环境

#### AMD64

* AWS EC2 us-west-2 [c7a.xlarge](https://aws.amazon.com/ec2/instance-types/c7a/)（4x AMD EPYC 9R14）
* Ubuntu 24.10 [fad5ba7223f8](https://hub.docker.com/layers/library/ubuntu/24.10/images/sha256-fad5ba7223f8d87179dfa23211d31845d47e07a474ac31ad5258afb606523c0d)
* Node.js 22.14.0

#### ARM64

* AWS EC2 us-west-2 [c8g.xlarge](https://aws.amazon.com/ec2/instance-types/c8g/)（4x ARM Graviton4）
* Ubuntu 24.10 [133f2e05cb69](https://hub.docker.com/layers/library/ubuntu/24.10/images/sha256-133f2e05cb6958c3ce7ec870fd5a864558ba780fb7062315b51a23670bff7e76)
* Node.js 22.14.0

### 任务：JPEG

解压一张 2725x2225 的 JPEG 图像，
使用 Lanczos 3 重采样（可用时）调整大小为 720x588，
然后以“质量”为 80 压缩成 JPEG。

注意：jimp 不支持 Lanczos 3，改用双三次（bicubic）重采样。

#### 结果：JPEG（AMD64）

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    2.35 |      1.0 |
| imagemagick        | file   | file   |   10.51 |      4.5 |
| gm                 | buffer | buffer |   11.67 |      5.0 |
| gm                 | file   | file   |   11.75 |      5.1 |
| sharp              | stream | stream |   60.72 |     25.8 |
| sharp              | file   | file   |   62.37 |     26.5 |
| sharp              | buffer | buffer |   65.15 |     27.7 |

#### 结果：JPEG（ARM64）

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    2.13 |      1.0 |
| imagemagick        | file   | file   |   12.95 |      6.1 |
| gm                 | buffer | buffer |   13.53 |      6.4 |
| gm                 | file   | file   |   13.52 |      6.4 |
| sharp              | stream | stream |   46.58 |     21.9 |
| sharp              | file   | file   |   48.42 |     22.7 |
| sharp              | buffer | buffer |   50.16 |     23.6 |

### 任务：PNG

解压一张 2048x1536 的 RGBA PNG 图像，
对 alpha 通道进行预乘，
使用 Lanczos 3 重采样（可用时）调整大小为 720x540，
取消预乘后以 PNG 格式压缩，使用默认 zlib 压缩等级（6），且不启用自适应滤波。

注意：jimp 不支持预乘和取消预乘。

#### 结果：PNG（AMD64）

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| gm                 | file   | file   |    8.66 |      1.0 |
| imagemagick        | file   | file   |    8.79 |      1.0 |
| jimp               | buffer | buffer |   11.26 |      1.3 |
| sharp              | file   | file   |   27.93 |      3.2 |
| sharp              | buffer | buffer |   28.69 |      3.3 |

#### 结果：PNG（ARM64）

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| gm                 | file   | file   |    9.65 |      1.0 |
| imagemagick        | file   | file   |    9.72 |      1.0 |
| jimp               | buffer | buffer |   10.68 |      1.1 |
| sharp              | file   | file   |   23.90 |      2.5 |
| sharp              | buffer | buffer |   24.48 |      2.5 |

## 运行基准测试

需要 Docker。

```sh
git clone https://github.com/lovell/sharp.git
cd sharp/test/bench
./run-with-docker.sh
```