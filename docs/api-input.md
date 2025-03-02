## metadata
> metadata([callback]) ⇒ <code>Promise.&lt;Object&gt;</code> \| <code>Sharp</code>

快速访问（未缓存的）图像元数据，而无需解码任何压缩的像素数据。

这些信息是从输入图像的头部读取的。
它不考虑将应用于输出图像的任何操作，比如调整大小或旋转。

响应中的维度将尊重 [构造函数参数](/api-constructor#parameters) 的 `page` 和 `pages` 属性。

当未提供 `callback` 时，会返回一个 `Promise`。

- `format`: 用于解压缩图像数据的解码器名称，例如 `jpeg`，`png`，`webp`，`gif`，`svg`
- `size`: 图像的总大小（以字节为单位），仅适用于流和缓冲区输入
- `width`: 宽度的像素数量（不考虑 EXIF 方向，见下面示例）
- `height`: 高度的像素数量（不考虑 EXIF 方向，见下面示例）
- `space`: 色彩空间解释的名称，例如 `srgb`，`rgb`，`cmyk`，`lab`，`b-w` [...](https://www.libvips.org/API/current/VipsImage.html#VipsInterpretation)
- `channels`: 色带数量，例如 `3` 表示 sRGB，`4` 表示 CMYK
- `depth`: 像素深度格式的名称，例如 `uchar`，`char`，`ushort`，`float` [...](https://www.libvips.org/API/current/VipsImage.html#VipsBandFormat)
- `density`: 每英寸像素数量（DPI），如果有的话
- `chromaSubsampling`: 包含 JPEG 色度子采样的字符串，例如 `4:2:0` 或 `4:4:4` 对于 RGB，`4:2:0:4` 或 `4:4:4:4` 对于 CMYK
- `isProgressive`: 布尔值，指示图像是否使用渐进扫描交错
- `pages`: 图像中包含的页/帧数，支持 TIFF、HEIF、PDF、动画 GIF 和动画 WebP
- `pageHeight`: 多页图像中每页的高度像素数量。
- `paletteBitDepth`: 基于调色板的图像（GIF、PNG）的位深度。
- `loop`: 动画图像循环的次数，零表示连续循环。
- `delay`: 动画图像中每页之间的延迟（以毫秒为单位），提供为整数数组。
- `pagePrimary`: HEIF 图像中主要页面的编号
- `levels`: 多级图像中每个级别的详细信息，提供为对象数组，需要编译了 OpenSlide 支持的 libvips
- `subifds`: OME-TIFF 图像中的子图像文件目录数量
- `background`: PNG（bKGD）和 GIF 图像的默认背景颜色（如果存在），可以是 RGB 对象或单个灰度值
- `compression`: 用于压缩 HEIF 文件的编码器，`av1` (AVIF) 或 `hevc` (HEIC)
- `resolutionUnit`: 分辨率单位（密度），可以是 `inch` 或 `cm`，如果存在
- `hasProfile`: 布尔值，指示嵌入的 ICC 配置文件是否存在
- `hasAlpha`: 布尔值，指示 Alpha 透明通道是否存在
- `orientation`: EXIF Orientation 头的数值（如果存在）
- `exif`: 包含原始 EXIF 数据的缓冲区（如果存在）
- `icc`: 包含原始 [ICC](https://www.npmjs.com/package/icc) 配置文件数据的缓冲区（如果存在）
- `iptc`: 包含原始 IPTC 数据的缓冲区（如果存在）
- `xmp`: 包含原始 XMP 数据的缓冲区（如果存在）
- `tifftagPhotoshop`: 包含原始 TIFFTAG_PHOTOSHOP 数据的缓冲区（如果存在）
- `formatMagick`: 包含通过 *magick 加载的图像格式的字符串
- `comments`: 表示 PNG 文本块的关键词/文本对的数组（如果存在）。



| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [callback] | <code>function</code> | 使用参数 `(err, metadata)` 调用 |

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
    // data 包含宽度和高度为原始 JPEG 一半的 WebP 图像
  });
```
**示例**  
```js
// 基于 EXIF 旋转元数据，获取正立的宽度和高度：

const size = getNormalSize(await sharp(input).metadata());

function getNormalSize({ width, height, orientation }) {
  return (orientation || 0) >= 5
    ? { width: height, height: width }
    : { width, height };
}
```


## stats
> stats([callback]) ⇒ <code>Promise.&lt;Object&gt;</code>

访问图像中每个通道的基于像素的图像统计信息。
当未提供 `callback` 时，会返回一个 `Promise`。

- `channels`: 数组，包括图像中每个通道的通道统计信息。每个通道统计信息包含：
    - `min` (通道中的最小值)
    - `max` (通道中的最大值)
    - `sum` (通道中所有值的总和)
    - `squaresSum` (通道中平方值的总和)
    - `mean` (通道中值的平均数)
    - `stdev` (通道中值的标准差)
    - `minX` (最小值像素的 x 坐标)
    - `minY` (最小值像素的 y 坐标)
    - `maxX` (最大值像素的 x 坐标)
    - `maxY` (最大值像素的 y 坐标)
- `isOpaque`: 图像是否完全不透明？如果图像没有 Alpha 通道或每个像素完全不透明，则为 `true`。
- `entropy`: 基于直方图的灰度熵估计，丢弃任何 Alpha 通道。
- `sharpness`: 基于拉普拉斯卷积的标准差的灰度锐度估计，丢弃任何 Alpha 通道。
- `dominant`: 对象，包含基于 4096-bin 3D 直方图的最主导 sRGB 颜色。

**注意**: 统计数据是从原始输入图像得出的。对图像执行的任何操作必须首先写入缓冲区，以便在结果上运行 `stats`（见第三个示例）。



| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [callback] | <code>function</code> | 使用参数 `(err, stats)` 调用 |

**示例**  
```js
const image = sharp(inputJpg);
image
  .stats()
  .then(function(stats) {
     // stats 包含通道统计数组和 isOpaque 值
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
// 创建新的实例以获取提取区域的统计信息
const stats = await sharp(part).stats();
```