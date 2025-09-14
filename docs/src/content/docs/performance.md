---
title: 性能
---

## 并行与并发

Node.js 在处理对原生模块（如 sharp）的异步调用时使用 libuv 管理的线程池。

sharp 可以并行处理的最大图像数量由 libuv 的 
[`UV_THREADPOOL_SIZE`](https://nodejs.org/api/cli.html#uv_threadpool_sizesize) 
环境变量控制，默认值为 4。

当使用超过 4 个物理 CPU 核心时，应在 Node.js 进程启动前设置此环境变量，以增加线程池大小。

```sh frame="none"
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

```sh frame="none"
export MALLOC_ARENA_MAX="2"
```

## 基准测试

一个用来比较本模块与其他替代方案性能的测试。

启用缓存（默认）且使用 8 核以上机器时，可以预期 libvips 性能更佳，
尤其是具有较大 L1/L2 CPU 缓存的机器。

相关（解）压缩库的 I/O 限制通常决定最大吞吐量。

### 竞争者

- [jimp](https://www.npmjs.com/package/jimp) v1.6.0 - 纯 JavaScript 实现的图像处理。
- [imagemagick](https://www.npmjs.com/package/imagemagick) v0.1.3 - 仅支持文件系统，且“_长期未维护_”。
- [gm](https://www.npmjs.com/package/gm) v1.25.1 - 完整封装 GraphicsMagick 的 `gm` 命令行工具，但“_已停用_”。
- sharp v0.34.3 / libvips v8.17.0 - 禁用 libvips 内部缓存以确保公平比较。

### 环境

#### AMD64

- AWS EC2 us-west-2 [c7a.xlarge](https://aws.amazon.com/ec2/instance-types/c7a/) (4x AMD EPYC 9R14)
- Ubuntu 25.04
- Node.js 24.3.0

#### ARM64

- AWS EC2 us-west-2 [c8g.xlarge](https://aws.amazon.com/ec2/instance-types/c8g/) (4x ARM Graviton4)
- Ubuntu 25.04
- Node.js 24.3.0

### 任务：JPEG

解压一个 2725x2225 的 JPEG 图像，
使用 Lanczos 3 重采样（可用时）调整大小至 720x588，
然后以“质量”设置 80 重新压缩为 JPEG。

注意：jimp 不支持 Lanczos 3，改用双三次重采样。

#### 结果：JPEG（AMD64）

| 包           | I/O    | 每秒操作数 | 加速比   |
| :---------- | :----- | ---------: | -------: |
| jimp        | buffer |       2.40 |      1.0 |
| jimp        | file   |       2.60 |      1.1 |
| imagemagick | file   |       9.70 |      4.0 |
| gm          | buffer |      11.60 |      4.8 |
| gm          | file   |      11.72 |      4.9 |
| sharp       | stream |      59.40 |     24.8 |
| sharp       | file   |      62.67 |     26.1 |
| sharp       | buffer |      64.42 |     26.8 |

#### 结果：JPEG（ARM64）

| 包           | I/O    | 每秒操作数 | 加速比   |
| :---------- | :----- | ---------: | -------: |
| jimp        | buffer |       2.24 |      1.0 |
| jimp        | file   |       2.47 |      1.1 |
| imagemagick | file   |      10.42 |      4.7 |
| gm          | buffer |      12.80 |      5.7 |
| gm          | file   |      12.88 |      5.7 |
| sharp       | stream |      45.58 |     20.3 |
| sharp       | file   |      47.99 |     21.4 |
| sharp       | buffer |      49.20 |     22.0 |

### 任务：PNG

解压一个 2048x1536 RGBA PNG 图像，
预乘 alpha 通道，
使用 Lanczos 3 重采样（可用时）调整大小至 720x540，
取消预乘，然后以默认 zlib 压缩级别 6 且不使用自适应过滤压缩为 PNG。

注意：jimp 不支持预乘/取消预乘。

#### 结果：PNG（AMD64）

| 包           | I/O    | 每秒操作数 | 加速比   |
| :---------- | :----- | ---------: | -------: |
| imagemagick | file   |       6.06 |      1.0 |
| gm          | file   |       8.44 |      1.4 |
| jimp        | buffer |      10.98 |      1.8 |
| sharp       | file   |      28.26 |      4.7 |
| sharp       | buffer |      28.70 |      4.7 |

#### 结果：PNG（ARM64）

| 包           | I/O    | 每秒操作数 | 加速比   |
| :---------- | :----- | ---------: | -------: |
| imagemagick | file   |       7.09 |      1.0 |
| gm          | file   |       8.93 |      1.3 |
| jimp        | buffer |      10.28 |      1.5 |
| sharp       | file   |      23.81 |      3.4 |
| sharp       | buffer |      24.19 |      3.4 |

## 运行基准测试

需要 Docker。

```sh frame="none"
git clone https://github.com/lovell/sharp.git
cd sharp/test/bench
./run-with-docker.sh
```