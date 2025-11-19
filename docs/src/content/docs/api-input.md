---
# 此文件是从 lib/input.js 中的 JSDoc 自动生成的
title: 输入元数据
---

## 元数据
> metadata([callback]) ⇒ <code>Promise.&lt;Object&gt;</code> \| <code>Sharp</code>

快速访问（未缓存的）图像元数据，无需解码任何压缩的像素数据。

这些信息是从输入图像的头部读取的。
它不考虑任何将应用于输出图像的操作，
例如调整大小或旋转。

响应中的尺寸将遵循
[构造函数参数](/api-constructor/)中的 `page` 和 `pages` 属性。

如果没有提供 `callback`，则返回一个 `Promise`。

- `format`：用于解压缩图像数据的解码器名称，例如 `jpeg`、`png`、`webp`、`gif`、`svg`
- `size`：图像的总字节大小，仅针对 Stream 和 Buffer 输入
- `width`：宽度的像素数（不考虑 EXIF 方向，详见下面示例）
- `height`：高度的像素数（不考虑 EXIF 方向，详见下面示例）
- `space`：颜色空间解释名称，例如 `srgb`、`rgb`、`cmyk`、`lab`、`b-w` [...](https://www.libvips.org/API/current/enum.Interpretation.html)
- `channels`：波段数，例如 sRGB 为 `3`，CMYK 为 `4`
- `depth`：像素深度格式名称，例如 `uchar`、`char`、`ushort`、`float` [...](https://www.libvips.org/API/current/enum.BandFormat.html)
- `density`：每英寸像素数 (DPI)，如果存在
- `chromaSubsampling`：包含 JPEG 色度子采样的字符串，RGB 为 `4:2:0` 或 `4:4:4`，CMYK 为 `4:2:0:4` 或 `4:4:4:4`
- `isProgressive`：布尔值，指示图像是否使用渐进扫描交错显示
- `isPalette`：布尔值，指示图像是否基于调色板（GIF，PNG）
- `bitsPerSample`：每个通道的每样本位数（GIF，PNG，HEIF）
- `pages`：图像包含的页数/帧数，支持 TIFF、HEIF、PDF、动画 GIF 和动画 WebP
- `pageHeight`：多页图像中每页的像素高度
- `loop`：动画循环次数，零表示无限循环
- `delay`：动画每页之间的延迟（毫秒），以整数数组形式提供
- `pagePrimary`：HEIF 图像中主页面编号
- `levels`：多级图像中各级详情，作为对象数组提供，需使用支持 OpenSlide 的 libvips 编译
- `subifds`：OME-TIFF 图像中子图像文件目录的数量
- `background`：PNG（bKGD）和 GIF 图像的默认背景色（如果存在）
- `compression`：压缩 HEIF 文件使用的编码器，`av1`（AVIF）或 `hevc`（HEIC）
- `resolutionUnit`：分辨率（密度）的单位，为 `inch` 或 `cm`，如果存在
- `hasProfile`：布尔值，指示是否存在嵌入的 ICC 配置文件
- `hasAlpha`：布尔值，指示是否存在 alpha 透明通道
- `orientation`：EXIF Orientation 头的数值（如果存在）
- `exif`：包含原始 EXIF 数据的 Buffer（如果存在）
- `icc`：包含原始 [ICC](https://www.npmjs.com/package/icc) 配置文件数据的 Buffer（如果存在）
- `iptc`：包含原始 IPTC 数据的 Buffer（如果存在）
- `xmp`：包含原始 XMP 数据的 Buffer（如果存在）
- `xmpAsString`：包含 XMP 数据的字符串（如果为有效 UTF-8）
- `tifftagPhotoshop`：包含原始 TIFFTAG_PHOTOSHOP 数据的 Buffer（如果存在）
- `formatMagick`：通过 *magick 加载的图像格式字符串
- `comments`：表示 PNG 文本块的关键字/文本对数组（如果存在）

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [callback] | <code>function</code> | 带有参数 `(err, metadata)` 的回调函数 |

**示例**
```js
const metadata = await sharp(input).metadata();
```
**示例**
```js
const image = sharp(inputJpg);
image
  .metadata()
  .then(function(metadata) {
    return image
      .resize(Math.round(metadata.width / 2))
      .webp()
      .toBuffer();
  })
  .then(function(data) {
    // data 是宽度和高度均为原 JPEG 图像一半的 WebP 图像
  });
```
**示例**
```js
// 获取考虑 EXIF 方向的尺寸。
const { autoOrient } = await sharp(input).metadata();
const { width, height } = autoOrient;
```


## 统计
> stats([callback]) ⇒ <code>Promise.&lt;Object&gt;</code>

访问图像中每个通道的像素衍生统计信息。当未提供 `callback` 时，将返回一个 `Promise`。

- `channels`：图像中每个通道的统计信息数组。每个通道统计信息包含：
    - `min`（该通道的最小值）
    - `max`（该通道的最大值）
    - `sum`（该通道所有值的总和）
    - `squaresSum`（该通道平方值的总和）
    - `mean`（该通道值的平均值）
    - `stdev`（该通道值的标准偏差）
    - `minX`（最小值像素的 x 坐标）
    - `minY`（最小值像素的 y 坐标）
    - `maxX`（最大值像素的 x 坐标）
    - `maxY`（最大值像素的 y 坐标）
- `isOpaque`：图像是否完全不透明？如果图像没有 alpha 通道或每个像素都完全不透明，则为 `true`。
- `entropy`：基于直方图的灰度熵估计，忽略 alpha 通道（如果存在）。
- `sharpness`：基于拉普拉斯卷积的灰度锐度估计的标准偏差，忽略 alpha 通道（如果存在）。
- `dominant`：包含基于 4096-bin 3D 直方图的最主导 sRGB 颜色的对象。

**注意**：统计信息基于原始输入图像。对图像执行的任何操作必须先写入缓冲区，才可在结果上运行 `stats`（见第三个示例）。

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [callback] | <code>function</code> | 带有参数 `(err, stats)` 的回调函数 |

**示例**
```js
const image = sharp(inputJpg);
image
  .stats()
  .then(function(stats) {
     // stats 包含按通道的统计数组和 isOpaque 值
  });
```
**示例**
```js
const { entropy, sharpness, dominant } = await sharp(input).stats();
const { r, g, b } = dominant;
```
**示例**
```js
const image = sharp(input);
// 存储中间结果
const part = await image.extract(region).toBuffer();
// 新建实例以获取提取区域的统计信息
const stats = await sharp(part).stats();
```
