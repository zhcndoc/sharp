# sharp

<img src="https://sharp.zhcndoc.com/image/sharp-logo.svg" width="160" height="160" alt="sharp logo" align="right">

这个高速 Node-API 模块的典型用例是将常见格式的大型图像转换为更小的、适合网络的 JPEG、PNG、WebP、GIF 和 AVIF 图像，尺寸各异。

它可以与所有支持 Node-API v9 的 JavaScript 运行时一起使用，包括 Node.js >= 18.17.0、Deno 和 Bun。

调整图像大小的速度通常比使用最快的 ImageMagick 和 GraphicsMagick 设置快 4 到 5 倍，这要归功于它使用的 [libvips](https://github.com/libvips/libvips)。

色彩空间、嵌入的 ICC 配置文件和 alpha 透明通道都得到了正确处理。Lanczos 重采样确保速度的提高不会牺牲质量。

除了图像调整大小外，还提供旋转、裁剪、合成和伽马校正等操作。

大多数现代 macOS、Windows 和 Linux 系统不需要任何额外的安装或运行时依赖。

### 格式

该模块支持读取 JPEG、PNG、WebP、GIF、AVIF、TIFF 和 SVG 图像。

输出图像可以为 JPEG、PNG、WebP、GIF、AVIF 和 TIFF 格式，以及未压缩的原始像素数据。

可以使用流、Buffer 对象和文件系统进行输入和输出。

单个输入流可以拆分为多个处理管道和输出流。

可以生成深度缩放图像金字塔，适用于与“滑动地图”瓦片查看器如 [OpenSeadragon](https://github.com/openseadragon/openseadragon) 一起使用。

### 快速

该模块由极速的 [libvips](https://github.com/libvips/libvips) 图像处理库驱动，该库最早于 1989 年在 Birkbeck College 创建，目前由 [John Cupitt](https://github.com/jcupitt) 领导的小团队维护。

在任何时候，只会在内存中持有和处理小区域的未压缩图像数据，充分利用多个 CPU 核心和 L1/L2/L3 缓存。

得益于 _libuv_，所有操作都保持非阻塞，没有子进程被生成，同时支持 Promises/async/await。

### 优化

可以使用 `mozjpeg` 和 `pngquant` 的功能分别优化 JPEG 和 PNG 图像的文件大小，而无需调用单独的 `imagemin` 进程。

在生成 JPEG 输出图像时，可优化哈夫曼表，而无需使用像 [jpegoptim](https://github.com/tjko/jpegoptim) 和 [jpegtran](http://jpegclub.org/jpegtran/) 这样的单独命令行工具。

PNG 过滤默认是禁用的，这对于图表和线条艺术而言，通常产生与 [pngcrush](https://pmt.sourceforge.io/pngcrush/) 相同的效果。

动画 GIF 输出的文件大小经过优化，无需使用像 [gifsicle](https://www.lcdf.org/gifsicle/) 这样的单独命令行工具。

### 贡献

[贡献者指南](https://github.com/lovell/sharp/blob/main/.github/CONTRIBUTING.md) 涵盖了报告错误、请求功能和提交代码更改。

### 许可

版权所有 2013 Lovell Fuller 等。

根据 Apache 许可证第 2.0 版（“许可证”）授权；您不能在不遵守许可证的情况下使用此文件。您可以在 [https://www.apache.org/licenses/LICENSE-2.0](https://www.apache.org/licenses/LICENSE-2.0) 获得许可证的副本。

除非适用法律要求或书面同意，否则根据许可证分发的软件都是在“按现状”基础上分发的，没有任何形式的担保或条件，无论是明示还是暗示。有关许可证的具体语言、治理权限和限制，请参阅许可证。
