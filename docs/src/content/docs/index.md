---
title: "高性能的 Node.js 图像处理库"
---

<img src="/sharp-logo.svg" width="160" height="160" alt="sharp logo" align="right" style="margin-left: 19px">

这个高速 Node-API 模块的典型用例是将常见格式的大图像转换为更小的、适合网页的 JPEG、PNG、WebP、GIF 和 AVIF 图像，尺寸各异。

它可以与所有提供 Node-API v9 支持的 JavaScript 运行时一起使用，包括 Node.js >= 18.17.0、Deno 和 Bun。

将图像调整大小的速度通常比使用最快的 ImageMagick 和 GraphicsMagick 设置快 4 倍到 5 倍，这得益于它使用的 [libvips](https://github.com/libvips/libvips)。

色彩空间、嵌入的 ICC 配置文件和 alpha 透明通道都得到了正确的处理。Lanczos 重采样确保了质量不会为了速度而妥协。

除了图像调整大小外，还可以进行旋转、提取、合成和伽马校正等操作。

大多数现代 macOS、Windows 和 Linux 系统不需要额外的安装或运行时依赖。

```sh
npm install sharp
```

## 格式

该模块支持读取 JPEG、PNG、WebP、GIF、AVIF、TIFF 和 SVG 图像。

输出图像可以为 JPEG、PNG、WebP、GIF、AVIF 和 TIFF 格式，也可以为未压缩的原始像素数据。

可以使用流、Buffer 对象和文件系统进行输入和输出。

单个输入流可以分割成多个处理管道和输出流。

可以生成 Deep Zoom 图像金字塔，适用于与“滑动地图”瓦片查看器如 [OpenSeadragon](https://github.com/openseadragon/openseadragon) 一起使用。

## 快速

该模块由极快的 [libvips](https://github.com/libvips/libvips) 图像处理库驱动，该库最初于 1989 年在比克贝克学院创建，目前由一个小团队维护，团队由 [John Cupitt](https://github.com/jcupitt) 领导。

每次只在内存中保留并处理小区域的未压缩图像数据，充分利用多个 CPU 核心和 L1/L2/L3 缓存。

由于 **libuv** 的作用，一切都保持非阻塞，不会生成子进程，并支持 Promises/async/await。

## 最优

可以使用 `mozjpeg` 和 `pngquant` 的特性分别优化 JPEG 和 PNG 图像的文件大小，无需调用单独的 `imagemin` 进程。

生成 JPEG 输出图像时，哈夫曼表被优化，无需使用像 [jpegoptim](https://github.com/tjko/jpegoptim) 和 [jpegtran](http://jpegclub.org/jpegtran/) 这样的单独命令行工具。

PNG 过滤器默认为禁用，这对于图表和线条艺术通常产生与 [pngcrush](https://pmt.sourceforge.io/pngcrush/) 相同的结果。

无需使用像 [gifsicle](https://www.lcdf.org/gifsicle/) 这样的单独命令行工具，就可以优化动画 GIF 输出的文件大小。

## 贡献

一份 [贡献者指南](https://github.com/lovell/sharp/blob/main/.github/CONTRIBUTING.md) 涵盖了报告错误、请求功能和提交代码变更。

## 许可

版权 2013 Lovell Fuller 和其他人。

根据 Apache 许可证第 2.0 版（“许可证”）获得许可；除非遵守该许可证，否则您不得使用此文件。您可以在 [https://www.apache.org/licenses/LICENSE-2.0](https://www.apache.org/licenses/LICENSE-2.0) 获取许可证的副本。

除非适用法律要求或书面同意，依据本许可证分发的软件按“原样”分发，不提供任何形式的明示或暗示的担保或条件。请参阅许可证以获取有关许可证下的权限和限制的具体语言。
