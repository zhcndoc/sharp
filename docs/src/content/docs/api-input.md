---
# 此文件是从 lib/input.js 中的 JSDoc 自动生成的
title: 输入元数据
---

## 元数据
> metadata([callback]) ⇒ <code>Promise.&lt;Object&gt;</code> \| <code>Sharp</code>

快速访问（未缓存的）图像元数据，无需解码任何压缩的像素数据。

这从输入图像的头部读取。它不考虑任何将应用于输出图像的操作，例如调整大小或旋转。

响应中的尺寸将遵循
[构造函数参数](/api-constructor#parameters) 的 `page` 和 `pages` 属性。

当未提供 `callback` 时，将返回一个 `Promise`。

- `format`：用于解压图像数据的解码器名称，例如 `jpeg`、`png`、`webp`、`gif`、`svg`
- `size`：图像的总大小（以字节为单位），仅适用于 Stream 和 Buffer 输入
- `width`：宽度的像素数量（不考虑 EXIF 方向，见下面的示例）
- `height`：高度的像素数量（不考虑 EXIF 方向，见下面的示例）
- `space`：颜色空间解释的名称，例如 `srgb`、`rgb`、`cmyk`、`lab`、`b-w` [...](https://www.libvips.org/API/current/VipsImage.html#VipsInterpretation)
- `channels`：波段数量，例如 `3` 表示 sRGB，`4` 表示 CMYK
- `depth`：像素深度格式的名称，例如 `uchar`、`char`、`ushort`、`float` [...](https://www.libvips.org/API/current/VipsImage.html#VipsBandFormat)
- `density`：每英寸的像素数量（DPI），如果存在
- `chromaSubsampling`：包含 JPEG 色度子采样的字符串，RGB 为 `4:2:0` 或 `4:4:4`，CMYK 为 `4:2:0:4` 或 `4:4:4:4`
- `isProgressive`：布尔值，指示图像是否使用渐进扫描交错
- `isPalette`：布尔值，指示图像是否基于调色板（GIF、PNG）。
- `bitsPerSample`：每个通道的每个样本的位数（GIF、PNG、HEIF）。
- `pages`：包含在图像中的页/帧数量，支持 TIFF、HEIF、PDF、动画 GIF 和动画 WebP
- `pageHeight`：多页图像中每页的像素高度。
- `loop`：循环动画图像的次数，零表示连续循环。
- `delay`：动画图像中每页之间的延迟（以毫秒为单位），提供为整数数组。
- `pagePrimary`：HEIF 图像中的主页面编号
- `levels`：多级图像中每个级别的详细信息，提供为对象数组，需要编译支持 OpenSlide 的 libvips
- `subifds`：OME-TIFF 图像中的子图像文件目录数量
- `background`：PNG（bKGD）和 GIF 图像的默认背景颜色（如果存在）
- `compression`：用于压缩 HEIF 文件的编码器，`av1`（AVIF）或 `hevc`（HEIC）
- `resolutionUnit`：分辨率的单位（密度），可以是 `inch` 或 `cm`，如果存在
- `hasProfile`：布尔值，指示嵌入的 ICC 配置文件的存在
- `hasAlpha`：布尔值，指示 alpha 透明通道的存在
- `orientation`：EXIF Orientation 头的数字值，如果存在
- `exif`：包含原始 EXIF 数据的缓冲区，如果存在
- `icc`：包含原始 [ICC](https://www.npmjs.com/package/icc) 配置文件数据的缓冲区，如果存在
- `iptc`：包含原始 IPTC 数据的缓冲区，如果存在
- `xmp`：包含原始 XMP 数据的缓冲区，如果存在
- `tifftagPhotoshop`：包含原始 TIFFTAG_PHOTOSHOP 数据的缓冲区，如果存在
- `formatMagick`：包含通过 *magick 加载的图像格式的字符串
- `comments`：表示 PNG 文本块的关键字/文本对数组（如果存在）。

| Param | Type | Description |
| --- | --- | --- |
| [callback] | <code>function</code> | 带有参数 `(err, metadata)` 调用 |

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
    // data 包含原始 JPEG 图像宽度和高度的一半的 WebP 图像
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

- `channels`：图像中每个通道的统计信息数组。每个通道统计信息包含
    - `min`（通道中的最小值）
    - `max`（通道中的最大值）
    - `sum`（通道中所有值的总和）
    - `squaresSum`（通道中平方值的总和）
    - `mean`（通道中值的平均值）
    - `stdev`（通道中值的标准偏差）
    - `minX`（最小值所在像素的 x 坐标）
    - `minY`（最小值所在像素的 y 坐标）
    - `maxX`（最大值所在像素的 x 坐标）
    - `maxY`（最大值所在像素的 y 坐标）
- `isOpaque`：图像是否完全不透明？如果图像没有 alpha 通道或每个像素都是完全不透明的，则为 `true`。
- `entropy`：基于直方图的灰度熵估计，丢弃 alpha 通道（如果有）。
- `sharpness`：基于拉普拉斯卷积的标准偏差的灰度锐度估计，丢弃 alpha 通道（如果有）。
- `dominant`：包含基于 4096-bin 3D 直方图的最主导 sRGB 颜色的对象。

**注意**：统计信息来自原始输入图像。对图像执行的任何操作必须首先写入缓冲区，以便在结果上运行 `stats`（见第三个示例）。

| Param | Type | Description |
| --- | --- | --- |
| [callback] | <code>function</code> | 带有参数 `(err, stats)` 调用 |

**示例**  
```js
const image = sharp(inputJpg);
image
  .stats()
  .then(function(stats) {
     // stats 包含按通道统计的数组和 isOpaque 值
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
// 创建新实例以获取提取区域的统计信息
const stats = await sharp(part).stats();
```
