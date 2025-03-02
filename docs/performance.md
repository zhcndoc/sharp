# 性能

一个测试，基准测试该模块相对于其他替代方案的性能。

启用缓存（默认）并使用 8 核以上的机器，特别是具有更大 L1/L2 CPU 缓存的机器，可以期望获得更好的 libvips 性能。

相关的（解压缩）库的 I/O 限制通常会决定最大吞吐量。

## 竞争者

* [jimp](https://www.npmjs.com/package/jimp) v0.22.10 - 纯 JavaScript 的图像处理。
* [imagemagick](https://www.npmjs.com/package/imagemagick) v0.1.3 - 仅支持文件系统，并且“*已经很长时间没有维护*”。
* [gm](https://www.npmjs.com/package/gm) v1.25.0 - 围绕 GraphicsMagick 的 `gm` 命令行工具的全面封装。
* [@squoosh/lib](https://www.npmjs.com/package/@squoosh/lib) v0.5.3 - 编译为 WebAssembly 的图像库，包括 GPLv3 代码，但“*项目不再维护*”。
* [@squoosh/cli](https://www.npmjs.com/package/@squoosh/cli) v0.7.3 - 围绕 `@squoosh/lib` 的命令行封装，通过生成进程避免 GPLv3，但“*项目不再维护*”。
* sharp v0.33.0 / libvips v8.15.0 - 禁用 libvips 中的缓存以确保公平比较。

## 环境

### AMD64

* AWS EC2 us-east-2 [c7a.xlarge](https://aws.amazon.com/ec2/instance-types/c7a/) (4x AMD EPYC 9R14)
* Ubuntu 23.10 [13f233a16be2](https://hub.docker.com/layers/library/ubuntu/23.10/images/sha256-13f233a16be210b57907b98b0d927ceff7571df390701e14fe1f3901b2c4a4d7)
* Node.js 20.10.0

### ARM64

* AWS EC2 us-east-2 [c7g.xlarge](https://aws.amazon.com/ec2/instance-types/c7g/) (4x ARM Graviton3)
* Ubuntu 23.10 [7708743264cb](https://hub.docker.com/layers/library/ubuntu/23.10/images/sha256-7708743264cbb7f6cf7fc13e915faece45a6cdda455748bc55e58e8de3d27b63)
* Node.js 20.10.0

## 任务：JPEG

解压一个 2725x2225 的 JPEG 图像，
使用 Lanczos 3 重采样将其调整为 720x588（如果可用），
然后以“质量”设置为 80 压缩为 JPEG。

注意：jimp 不支持 Lanczos 3，改用双立方重采样。

#### 结果：JPEG (AMD64)

| 模块               | 输入   | 输出   | Ops/sec | 加速比 |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    0.84 |      1.0 |
| squoosh-cli        | file   | file   |    1.54 |      1.8 |
| squoosh-lib        | buffer | buffer |    2.24 |      2.7 |
| imagemagick        | file   | file   |   11.75 |     14.0 |
| gm                 | buffer | buffer |   12.66 |     15.1 |
| gm                 | file   | file   |   12.72 |     15.1 |
| sharp              | stream | stream |   48.31 |     57.5 |
| sharp              | file   | file   |   51.42 |     61.2 |
| sharp              | buffer | buffer |   52.41 |     62.4 |

#### 结果：JPEG (ARM64)

| 模块               | 输入   | 输出   | Ops/sec | 加速比 |
| :----------------- | :----- | :----- | ------: | -------: |
| jimp               | buffer | buffer |    0.88 |      1.0 |
| squoosh-cli        | file   | file   |    1.18 |      1.3 |
| squoosh-lib        | buffer | buffer |    1.99 |      2.3 |
| gm                 | buffer | buffer |    6.06 |      6.9 |
| gm                 | file   | file   |   10.81 |     12.3 |
| imagemagick        | file   | file   |   10.95 |     12.4 |
| sharp              | stream | stream |   33.15 |     37.7 |
| sharp              | file   | file   |   34.99 |     39.8 |
| sharp              | buffer | buffer |   36.05 |     41.0 |

## 任务：PNG

解压一个 2048x1536 的 RGBA PNG 图像，
预乘 Alpha 通道，
使用 Lanczos 3 重采样将其调整为 720x540（如果可用），
取消预乘然后以“默认”zlib 压缩级别 6 压缩为 PNG
且不使用自适应过滤。

注意：jimp 不支持预乘/取消预乘。

### 结果：PNG (AMD64)

| 模块               | 输入   | 输出   | Ops/sec | 加速比 |
| :----------------- | :----- | :----- | ------: | -------: |
| squoosh-cli        | file   | file   |    0.34 |      1.0 |
| squoosh-lib        | buffer | buffer |    0.51 |      1.5 |
| jimp               | buffer | buffer |    3.59 |     10.6 |
| gm                 | file   | file   |    8.54 |     25.1 |
| imagemagick        | file   | file   |    9.23 |     27.1 |
| sharp              | file   | file   |   25.43 |     74.8 |
| sharp              | buffer | buffer |   25.70 |     75.6 |

### 结果：PNG (ARM64)

| 模块               | 输入   | 输出   | Ops/sec | 加速比 |
| :----------------- | :----- | :----- | ------: | -------: |
| squoosh-cli        | file   | file   |    0.33 |      1.0 |
| squoosh-lib        | buffer | buffer |    0.46 |      1.4 |
| jimp               | buffer | buffer |    3.51 |     10.6 |
| gm                 | file   | file   |    7.47 |     22.6 |
| imagemagick        | file   | file   |    8.06 |     24.4 |
| sharp              | file   | file   |   17.31 |     52.5 |
| sharp              | buffer | buffer |   17.66 |     53.5 |

## 运行基准测试

需要 Docker。

```sh
git clone https://github.com/lovell/sharp.git
cd sharp/test/bench
./run-with-docker.sh
```
