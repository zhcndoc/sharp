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

libvips 使用共享线程池来避免创建新线程的开销。

该线程池的大小会根据需求增长，并在空闲时缩小。

默认用于并发处理每张图像的线程数与 CPU 核心数量相同，
但在使用基于 glibc 的 Linux 且未使用 jemalloc 的情况下，默认线程数为 `1`，以帮助减少内存碎片。

可使用 [`sharp.concurrency()`](/api-utility/#concurrency) 来管理每张图像的线程数。

在使用默认的 Linux glibc 内存分配器时，为减少内存碎片，
应在 Node.js 进程启动前设置
[`MALLOC_ARENA_MAX`](https://sourceware.org/glibc/manual/latest/html_node/Memory-Allocation-Tunables.html)
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

- [jimp](https://www.npmjs.com/package/jimp) v1.6.1 - 纯 JavaScript 图像处理。
- [imagemagick](https://www.npmjs.com/package/imagemagick) v0.1.3 - 仅支持文件系统，并且“已经长期无人维护”。
- [gm](https://www.npmjs.com/package/gm) v1.25.1 - GraphicsMagick `gm` 命令行工具的完整封装，但“已经停止维护”。
- sharp v0.35.0 / libvips v8.18.2 - 为确保公平比较，已禁用 libvips 内部缓存。

### 环境

#### AMD64

- AWS EC2 us-west-2 [c8a.xlarge](https://aws.amazon.com/ec2/instance-types/c8a/) (4x AMD EPYC 9R45)
- Ubuntu 25.10
- Node.js 24.15.0

#### ARM64

- AWS EC2 us-west-2 [c8g.xlarge](https://aws.amazon.com/ec2/instance-types/c8g/) (4x ARM Graviton4)
- Ubuntu 25.10
- Node.js 24.15.0

### 任务：JPEG

解压一个 2725x2225 的 JPEG 图像，
使用 Lanczos 3 重采样（可用时）调整大小至 720x588，
然后以“质量”设置 80 重新压缩为 JPEG。

注意：jimp 不支持 Lanczos 3，改用双三次重采样。

#### 结果：JPEG（AMD64）

| Package     | I/O    | Ops/sec | Speed-up |
| :---------- | :----- | ------: | -------: |
| jimp        | buffer |    3.44 |      1.0 |
| jimp        | file   |    3.65 |      1.1 |
| imagemagick | file   |   16.23 |      4.7 |
| gm          | buffer |   20.92 |      6.1 |
| gm          | file   |   21.04 |      6.1 |
| sharp       | stream |   82.87 |     24.1 |
| sharp       | file   |   88.21 |     25.6 |
| sharp       | buffer |   89.63 |     26.1 |

#### 结果：JPEG（ARM64）

| Package     | I/O    | Ops/sec | Speed-up |
| :---------- | :----- | ------: | -------: |
| jimp        | buffer |    2.20 |      1.0 |
| jimp        | file   |    2.45 |      1.1 |
| imagemagick | file   |    5.85 |      2.7 |
| gm          | file   |   13.72 |      6.2 |
| gm          | buffer |   13.82 |      6.3 |
| sharp       | stream |   49.82 |     22.6 |
| sharp       | file   |   52.42 |     23.8 |
| sharp       | buffer |   53.83 |     24.5 |

### 任务：PNG

解压一个 2048x1536 RGBA PNG 图像，
预乘 alpha 通道，
使用 Lanczos 3 重采样（可用时）调整大小至 720x540，
取消预乘，然后以默认 zlib 压缩级别 6 且不使用自适应过滤压缩为 PNG。

注意：jimp 不支持预乘/取消预乘。

#### 结果：PNG（AMD64）

| Package     | I/O    | Ops/sec | Speed-up |
| :---------- | :----- | ------: | -------: |
| imagemagick | file   |   10.37 |      1.0 |
| gm          | file   |   13.35 |      1.3 |
| jimp        | buffer |   17.04 |      1.6 |
| jimp        | file   |   17.15 |      1.7 |
| sharp       | file   |   47.17 |      4.5 |
| sharp       | buffer |   47.74 |      4.6 |

#### 结果：PNG（ARM64）

| Package     | I/O    | Ops/sec | Speed-up |
| :---------- | :----- | ------: | -------: |
| imagemagick | file   |    4.39 |      1.0 |
| gm          | file   |    9.45 |      2.2 |
| jimp        | buffer |   10.36 |      2.4 |
| jimp        | file   |   10.52 |      2.4 |
| sharp       | file   |   28.04 |      6.4 |
| sharp       | buffer |   28.57 |      6.5 |

## 运行基准测试

需要 Docker。

```sh frame="none"
git clone https://github.com/lovell/sharp.git
cd sharp/test/bench
./run-with-docker.sh
```
