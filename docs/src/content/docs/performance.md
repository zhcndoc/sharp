---
title: 性能
---

一个测试，用于基准测试该模块相对于替代方案的性能。

启用缓存（默认情况下）并使用 8 核以上的机器，特别是那些具有较大 L1/L2 CPU 缓存的机器，可以期待更高的 libvips 性能。

相关的（解）压缩库的 I/O 限制通常会决定最大吞吐量。

## 竞争者

* [jimp](https://www.npmjs.com/package/jimp) v1.6.0 - 纯 JavaScript 图像处理。
* [imagemagick](https://www.npmjs.com/package/imagemagick) v0.1.3 - 仅支持文件系统，并且“*已经很长时间没有维护*”。
* [gm](https://www.npmjs.com/package/gm) v1.25.1 - 完整功能的 GraphicsMagick `gm` 命令行工具的包装器，但“*已被停用*”。
* sharp v0.34.0 / libvips v8.16.1 - 在 libvips 中禁用缓存，以确保公正的比较。

## 环境

### AMD64

* AWS EC2 us-west-2 [c7a.xlarge](https://aws.amazon.com/ec2/instance-types/c7a/) (4x AMD EPYC 9R14)
* Ubuntu 24.10 [fad5ba7223f8](https://hub.docker.com/layers/library/ubuntu/24.10/images/sha256-fad5ba7223f8d87179dfa23211d31845d47e07a474ac31ad5258afb606523c0d)
* Node.js 22.14.0

### ARM64

* AWS EC2 us-west-2 [c8g.xlarge](https://aws.amazon.com/ec2/instance-types/c8g/) (4x ARM Graviton4)
* Ubuntu 24.10 [133f2e05cb69](https://hub.docker.com/layers/library/ubuntu/24.10/images/sha256-133f2e05cb6958c3ce7ec870fd5a864558ba780fb7062315b51a23670bff7e76)
* Node.js 22.14.0

## 任务：JPEG

解压一个 2725x2225 的 JPEG 图像，
使用 Lanczos 3 重采样将其调整为 720x588（如果可用），
然后以“质量”设置为 80 压缩为JPEG。

注意：jimp 不支持 Lanczos 3，因此使用了双三次重采样。

#### 结果：JPEG (AMD64)

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    2.35 |      1.0 |
| imagemagick        | file   | file   |   10.51 |      4.5 |
| gm                 | buffer | buffer |   11.67 |      5.0 |
| gm                 | file   | file   |   11.75 |      5.1 |
| sharp              | stream | stream |   60.72 |     25.8 |
| sharp              | file   | file   |   62.37 |     26.5 |
| sharp              | buffer | buffer |   65.15 |     27.7 |

#### 结果：JPEG (ARM64)

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    2.13 |      1.0 |
| imagemagick        | file   | file   |   12.95 |      6.1 |
| gm                 | buffer | buffer |   13.53 |      6.4 |
| gm                 | file   | file   |   13.52 |      6.4 |
| sharp              | stream | stream |   46.58 |     21.9 |
| sharp              | file   | file   |   48.42 |     22.7 |
| sharp              | buffer | buffer |   50.16 |     23.6 |

## 任务：PNG

解压一个 2048x1536 RGBA PNG 图像，对 Alpha 通道进行预乘，使用 Lanczos 3 重采样将其调整为 720x540（如果可用），去预乘后再以 zlib 压缩级别 6 压缩为 PNG 并且不进行自适应过滤。

注意：jimp 不支持预乘/去预乘。

### 结果：PNG (AMD64)

| 模块               | 输入   | 输出   | ops/秒  | 加速   |
| :----------------- | :----- | :----- | ------: | -------: |
| gm                 | file   | file   |    8.66 |      1.0 |
| imagemagick        | file   | file   |    8.79 |      1.0 |
| jimp               | buffer | buffer |   11.26 |      1.3 |
| sharp              | file   | file   |   27.93 |      3.2 |
| sharp              | buffer | buffer |   28.69 |      3.3 |

### 结果：PNG (ARM64)

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
