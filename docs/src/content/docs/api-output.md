---
# 该文件是从 JSDoc 在 lib/output.js 自动生成的
title: 输出选项
---

## toFile
> toFile(fileOut, [callback]) ⇒ <code>Promise.&lt;Object&gt;</code>

将输出图像数据写入文件。

如果未选择明确的输出格式，则将根据扩展名推断格式，支持 JPEG、PNG、WebP、AVIF、TIFF、GIF、DZI 以及 libvips 的 V 格式。请注意，仅支持为缓冲区输出提供原始像素数据。

默认情况下，所有元数据将被移除，包括基于 EXIF 的方向。有关此方面的控制，请参见 [withMetadata](#withmetadata)。

调用者负责确保目录结构和权限存在。

当未提供 `callback` 时，将返回一个 `Promise`。

**返回**: <code>Promise.&lt;Object&gt;</code> - 未提供回调时  
**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| fileOut | <code>string</code> | 写入图像数据的路径。 |
| [callback] | <code>function</code> | 完成时调用，传递两个参数 `(err, info)`。`info` 包含输出图像的 `format`、`size`（字节）、`width`、`height`、`channels` 和 `premultiplied`（指示是否使用了预乘）。当使用裁剪策略时，还包含 `cropOffsetLeft` 和 `cropOffsetTop`。使用注意裁剪策略时，还包含 `attentionX` 和 `attentionY`，表示裁剪区域的焦点。动画输出还将包含 `pageHeight` 和 `pages`。如果图像是从文本创建的，也可能包含 `textAutofitDpi`（字体渲染时的 DPI）。 |

**示例**  
```js
sharp(input)
  .toFile('output.png', (err, info) => { ... });
```
**示例**  
```js
sharp(input)
  .toFile('output.png')
  .then(info => { ... })
  .catch(err => { ... });
```


## toBuffer
> toBuffer([options], [callback]) ⇒ <code>Promise.&lt;Buffer&gt;</code>

将输出写入 Buffer。支持 JPEG、PNG、WebP、AVIF、TIFF、GIF 和原始像素数据输出。

使用 [toFormat](#toformat) 或其他格式特定函数，如 [jpeg](#jpeg)、[png](#png) 等来设置输出格式。

如果未设置明确的格式，则输出格式将与输入图像匹配，除非输入为 SVG，则输出将为 PNG。

默认情况下，所有元数据将被移除，包括基于 EXIF 的方向。有关此方面的控制，请参见 [withMetadata](#withmetadata)。

`callback`（如果存在）接收三个参数 `(err, data, info)`，其中：
- `err` 是一个错误（如果有）。
- `data` 是输出图像数据。
- `info` 包含输出图像的 `format`、`size`（字节）、`width`、`height`、`channels` 和 `premultiplied`（指示是否使用了预乘）。当使用裁剪策略时，还包含 `cropOffsetLeft` 和 `cropOffsetTop`。动画输出还将包含 `pageHeight` 和 `pages`。如果图像是从文本创建的，也可能包含 `textAutofitDpi`（字体渲染时的 DPI）。

当未提供 `callback` 时，将返回一个 `Promise`。

**返回**: <code>Promise.&lt;Buffer&gt;</code> - 未提供回调时  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [options] | <code>Object</code> |  |
| [options.resolveWithObject] | <code>boolean</code> | 用包含 `data` 和 `info` 属性的对象解析 Promise，而不是仅用 `data`。 |
| [callback] | <code>function</code> |  |

**示例**  
```js
sharp(input)
  .toBuffer((err, data, info) => { ... });
```
**示例**  
```js
sharp(input)
  .toBuffer()
  .then(data => { ... })
  .catch(err => { ... });
```
**示例**  
```js
sharp(input)
  .png()
  .toBuffer({ resolveWithObject: true })
  .then(({ data, info }) => { ... })
  .catch(err => { ... });
```
**示例**  
```js
const { data, info } = await sharp('my-image.jpg')
  // 输出原始像素
  .raw()
  .toBuffer({ resolveWithObject: true });

// 创建一种更安全的方式来处理原始像素数据
// 这不会复制数据，而是会改变 `data` 的底层 ArrayBuffer
// 因此 `data` 和 `pixelArray` 指向相同的内存位置
const pixelArray = new Uint8ClampedArray(data.buffer);

// 当你完成更改 pixelArray 后，sharp 将 `pixelArray` 作为输入
const { width, height, channels } = info;
await sharp(pixelArray, { raw: { width, height, channels } })
  .toFile('my-changed-image.jpg');
```


## keepExif
> keepExif() ⇒ <code>Sharp</code>

在输出图像中保留输入图像的所有 EXIF 元数据。

TIFF 输出不支持 EXIF 元数据。


**自**: 0.33.0  
**示例**  
```js
const outputWithExif = await sharp(inputWithExif)
  .keepExif()
  .toBuffer();
```


## withExif
> withExif(exif) ⇒ <code>Sharp</code>

在输出图像中设置 EXIF 元数据，忽略输入图像中的任何 EXIF。


**抛出**:

- <code>Error</code> 无效参数

**自**: 0.33.0  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| exif | <code>Object.&lt;string, Object.&lt;string, string&gt;&gt;</code> | 按 IFD0、IFD1 等键入的对象，键值对写入为 EXIF 数据。 |

**示例**  
```js
const dataWithExif = await sharp(input)
  .withExif({
    IFD0: {
      Copyright: '国家美术馆'
    },
    IFD3: {
      GPSLatitudeRef: 'N',
      GPSLatitude: '51/1 30/1 3230/100',
      GPSLongitudeRef: 'W',
      GPSLongitude: '0/1 7/1 4366/100'
    }
  })
  .toBuffer();
```


## withExifMerge
> withExifMerge(exif) ⇒ <code>Sharp</code>

在输出图像中更新输入图像的 EXIF 元数据。


**抛出**:

- <code>Error</code> 无效参数

**自**: 0.33.0  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| exif | <code>Object.&lt;string, Object.&lt;string, string&gt;&gt;</code> | 按 IFD0、IFD1 等键入的对象，键值对写入为 EXIF 数据。 |

**示例**  
```js
const dataWithMergedExif = await sharp(inputWithExif)
  .withExifMerge({
    IFD0: {
      Copyright: '国家美术馆'
    }
  })
  .toBuffer();
```


## keepIccProfile
> keepIccProfile() ⇒ <code>Sharp</code>

在输出图像中保留输入图像的 ICC 配置文件。

如有必要，将尝试将输出颜色空间转换以匹配该配置文件。


**自**: 0.33.0  
**示例**  
```js
const outputWithIccProfile = await sharp(inputWithIccProfile)
  .keepIccProfile()
  .toBuffer();
```


## withIccProfile
> withIccProfile(icc, [options]) ⇒ <code>Sharp</code>

使用 ICC 配置文件进行转换并附加到输出图像。

这可以是绝对文件系统路径或内置配置文件名称（`srgb`、`p3`、`cmyk`）。


**抛出**:

- <code>Error</code> 无效参数

**自**: 0.33.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| icc | <code>string</code> |  | 输出 ICC 配置文件的绝对文件系统路径或内置配置文件名称（srgb、p3、cmyk）。 |
| [options] | <code>Object</code> |  |  |
| [options.attach] | <code>number</code> | <code>true</code> | 是否将 ICC 配置文件包含在输出图像的元数据中？ |

**示例**  
```js
const outputWithP3 = await sharp(input)
  .withIccProfile('p3')
  .toBuffer();
```


## keepXmp
> keepXmp() ⇒ <code>Sharp</code>

在输出图像中保留输入图像的 XMP 元数据。


**自**: 0.34.3  
**示例**  
```js
const outputWithXmp = await sharp(inputWithXmp)
  .keepXmp()
  .toBuffer();
```


## withXmp
> withXmp(xmp) ⇒ <code>Sharp</code>

在输出图像中设置 XMP 元数据。

支持 PNG、JPEG、WebP 和 TIFF 输出。


**抛出**:

- <code>Error</code> Invalid parameters

**Since**: 0.34.3  

| Param | Type | Description |
| --- | --- | --- |
| xmp | <code>string</code> | 包含要嵌入输出图像的 XMP 元数据的字符串。 |

**示例**  
```js
const xmpString = `
  <?xml version="1.0"?>
  <x:xmpmeta xmlns:x="adobe:ns:meta/">
    <rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
      <rdf:Description rdf:about="" xmlns:dc="http://purl.org/dc/elements/1.1/">
        <dc:creator><rdf:Seq><rdf:li>John Doe</rdf:li></rdf:Seq></dc:creator>
      </rdf:Description>
    </rdf:RDF>
  </x:xmpmeta>`;

const data = await sharp(input)
  .withXmp(xmpString)
  .toBuffer();
```


## keepMetadata
> keepMetadata() ⇒ <code>Sharp</code>

在输出图像中保留输入图像的所有元数据（EXIF、ICC、XMP、IPTC）。

当未使用 `keepMetadata` 时，默认行为是转换为设备独立的 sRGB 颜色空间并剥离所有元数据，包括移除任何 ICC 配置文件。


**自**: 0.33.0  
**示例**  
```js
const outputWithMetadata = await sharp(inputWithMetadata)
  .keepMetadata()
  .toBuffer();
```


## withMetadata
> withMetadata([options]) ⇒ <code>Sharp</code>

在输出图像中保留输入图像的大多数元数据（EXIF、XMP、IPTC）。

如果适用，这还将转换并添加一个适于网络的 sRGB ICC 配置文件。

允许设置或更新方向和密度。


**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [options] | <code>Object</code> |  |
| [options.orientation] | <code>number</code> | 用于更新 EXIF `Orientation` 标签，整数在 1 和 8 之间。 |
| [options.density] | <code>number</code> | 每英寸的像素数（DPI）。 |

**示例**  
```js
const outputSrgbWithMetadata = await sharp(inputRgbWithMetadata)
  .withMetadata()
  .toBuffer();
```
**示例**  
```js
// 将输出元数据设置为 96 DPI
const data = await sharp(input)
  .withMetadata({ density: 96 })
  .toBuffer();
```


## toFormat
> toFormat(format, options) ⇒ <code>Sharp</code>

强制输出为给定格式。


**抛出**:

- <code>Error</code> 不支持的格式或选项


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| format | <code>string</code> \| <code>Object</code> | 作为字符串或带有 'id' 属性的对象 |
| options | <code>Object</code> | 输出选项 |

**示例**  
```js
// 将任何输入转换为 PNG 输出
const data = await sharp(input)
  .toFormat('png')
  .toBuffer();
```


## jpeg
> jpeg([options]) ⇒ <code>Sharp</code>

使用这些 JPEG 选项设置输出图像。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数 1-100 |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:2:0&#x27;&quot;</code> | 设置为 '4:4:4' 以防止色度子采样，否则默认使用 '4:2:0' 色度子采样 |
| [options.optimiseCoding] | <code>boolean</code> | <code>true</code> | 优化哈夫曼编码表 |
| [options.optimizeCoding] | <code>boolean</code> | <code>true</code> | 优化哈夫曼编码表的另一种拼写 |
| [options.mozjpeg] | <code>boolean</code> | <code>false</code> | 使用 mozjpeg 默认值，相当于 `{ trellisQuantisation: true, overshootDeringing: true, optimiseScans: true, quantisationTable: 3 }` |
| [options.trellisQuantisation] | <code>boolean</code> | <code>false</code> | 应用 trellis 量化 |
| [options.overshootDeringing] | <code>boolean</code> | <code>false</code> | 应用过冲去锯齿 |
| [options.optimiseScans] | <code>boolean</code> | <code>false</code> | 优化渐进扫描，强制渐进 |
| [options.optimizeScans] | <code>boolean</code> | <code>false</code> | 优化渐进扫描的另一种拼写 |
| [options.quantisationTable] | <code>number</code> | <code>0</code> | 要使用的量化表，整数 0-8 |
| [options.quantizationTable] | <code>number</code> | <code>0</code> | 量化表的另一种拼写 |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 JPEG 输出，否则尝试使用输入格式 |

**示例**  
```js
// 将任何输入转换为非常高质量的 JPEG 输出
const data = await sharp(input)
  .jpeg({
    quality: 100,
    chromaSubsampling: '4:4:4'
  })
  .toBuffer();
```
**示例**  
```js
// 使用 mozjpeg 减小输出 JPEG 文件大小（较慢）
const data = await sharp(input)
  .jpeg({ mozjpeg: true })
  .toBuffer();
```


## png
> png([options]) ⇒ <code>Sharp</code>

使用这些 PNG 选项设置输出图像。

默认情况下，PNG 输出为每像素 8 位的全彩色。

1、2 或 4 位每像素的索引 PNG 输入转换为 8 位每像素。
设置 `palette` 为 `true` 以获取较慢、索引的 PNG 输出。

对于 16 位每像素输出，通过 [toColourspace](/api-colour#tocolourspace) 转换为 `rgb16`。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.compressionLevel] | <code>number</code> | <code>6</code> | zlib 压缩级别，0（最快、最大）到 9（最慢、最小） |
| [options.adaptiveFiltering] | <code>boolean</code> | <code>false</code> | 使用自适应行过滤 |
| [options.palette] | <code>boolean</code> | <code>false</code> | 量化为支持 alpha 透明的调色板图像 |
| [options.quality] | <code>number</code> | <code>100</code> | 使用实现给定质量所需的最低颜色数，设置 `palette` 为 `true` |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力程度，在 1（最快）和 10（最慢）之间，设置 `palette` 为 `true` |
| [options.colours] | <code>number</code> | <code>256</code> | 最大调色板条目数，设置 `palette` 为 `true` |
| [options.colors] | <code>number</code> | <code>256</code> | `options.colours` 的另一种拼写，设置 `palette` 为 `true` |
| [options.dither] | <code>number</code> | <code>1.0</code> | Floyd-Steinberg 错误扩散的水平，设置 `palette` 为 `true` |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 PNG 输出，否则尝试使用输入格式 |

**示例**  
```js
// 将任何输入转换为全彩色 PNG 输出
const data = await sharp(input)
  .png()
  .toBuffer();
```
**示例**  
```js
// 将任何输入转换为索引 PNG 输出（较慢）
const data = await sharp(input)
  .png({ palette: true })
  .toBuffer();
```
**示例**  
```js
// 输出 16 位每像素 RGB(A)
const data = await sharp(input)
 .toColourspace('rgb16')
 .png()
 .toBuffer();
```


## webp
> webp([options]) ⇒ <code>Sharp</code>

使用这些 WebP 选项设置输出图像。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数 1-100 |
| [options.alphaQuality] | <code>number</code> | <code>100</code> | alpha 层质量，整数 0-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩模式 |
| [options.nearLossless] | <code>boolean</code> | <code>false</code> | 使用近无损压缩模式 |
| [options.smartSubsample] | <code>boolean</code> | <code>false</code> | 使用高质量的色度子采样 |
| [options.smartDeblock] | <code>boolean</code> | <code>false</code> | 自动调整去块过滤器，可以改善低对比度边缘（较慢） |
| [options.preset] | <code>string</code> | <code>&quot;&#x27;default&#x27;&quot;</code> | 预处理/过滤的命名预设，选项为：default、photo、picture、drawing、icon、text |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力程度，在 0（最快）和 6（最慢）之间 |
| [options.loop] | <code>number</code> | <code>0</code> | 动画迭代次数，使用 0 表示无限动画 |
| [options.delay] | <code>number</code> \| <code>Array.&lt;number&gt;</code> |  | 动画帧之间的延迟（以毫秒为单位） |
| [options.minSize] | <code>boolean</code> | <code>false</code> | 防止使用动画关键帧以最小化文件大小（较慢） |
| [options.mixed] | <code>boolean</code> | <code>false</code> | 允许损失和无损动画帧的混合（较慢） |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 WebP 输出，否则尝试使用输入格式 |

**示例**  
```js
// 将任何输入转换为无损 WebP 输出
const data = await sharp(input)
  .webp({ lossless: true })
  .toBuffer();
```
**示例**  
```js
// 优化动画 WebP 的文件大小
const outputWebp = await sharp(inputWebp, { animated: true })
  .webp({ effort: 6 })
  .toBuffer();
```


## gif
> gif([options]) ⇒ <code>Sharp</code>

使用这些 GIF 选项为输出图像设置。

调色板中的第一个条目保留用于透明度。

如果可能，将重新使用输入图像的调色板。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.30.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.reuse] | <code>boolean</code> | <code>true</code> | 重新使用现有调色板，否则生成新的（较慢） |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.colours] | <code>number</code> | <code>256</code> | 最大调色板条目数，包括透明度，范围在 2 到 256 之间 |
| [options.colors] | <code>number</code> | <code>256</code> | `options.colours` 的另一种拼写 |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力程度，在 1（最快）和 10（最慢）之间 |
| [options.dither] | <code>number</code> | <code>1.0</code> | Floyd-Steinberg 错误扩散的水平，在 0（最少）和 1（最多）之间 |
| [options.interFrameMaxError] | <code>number</code> | <code>0</code> | 透明度的最大帧间误差，范围在 0（无损）和 32 之间 |
| [options.interPaletteMaxError] | <code>number</code> | <code>3</code> | 调色板重用的最大帧间误差，范围在 0 到 256 之间 |
| [options.keepDuplicateFrames] | <code>boolean</code> | <code>false</code> | 在输出中保留重复帧，而不是将它们合并。 |
| [options.loop] | <code>number</code> | <code>0</code> | 动画迭代次数，使用 0 表示无限动画 |
| [options.delay] | <code>number</code> \| <code>Array.&lt;number&gt;</code> |  | 动画帧之间的延迟（以毫秒为单位） |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 GIF 输出，否则尝试使用输入格式 |

**示例**  
```js
// 将 PNG 转换为 GIF
await sharp(pngBuffer)
  .gif()
  .toBuffer();
```
**示例**  
```js
// 将动画 WebP 转换为动画 GIF
await sharp('animated.webp', { animated: true })
  .toFile('animated.gif');
```
**示例**  
```js
// 创建一个 128x128 像素、裁剪的、非抖动的动画缩略图
const out = await sharp('in.gif', { animated: true })
  .resize({ width: 128, height: 128 })
  .gif({ dither: 0 })
  .toBuffer();
```
**示例**  
```js
// 动画 GIF 的有损文件大小缩减
await sharp('in.gif', { animated: true })
  .gif({ interFrameMaxError: 8 })
  .toFile('optim.gif');
```


## jp2
> jp2([options]) ⇒ <code>Sharp</code>

使用这些 JP2 选项设置输出图像。

需要使用 OpenJPEG 编译的 libvips。
预构建的二进制文件不包括此项 - 请参阅
[安装自定义 libvips](https://sharp.pixelplumbing.com/install#custom-libvips)。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.29.1  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩模式 |
| [options.tileWidth] | <code>number</code> | <code>512</code> | 水平瓦片大小 |
| [options.tileHeight] | <code>number</code> | <code>512</code> | 垂直瓦片大小 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度子采样 |

**示例**  
```js
// 将任何输入转换为无损 JP2 输出
const data = await sharp(input)
  .jp2({ lossless: true })
  .toBuffer();
```
**示例**  
```js
// 将任何输入转换为非常高质量 JP2 输出
const data = await sharp(input)
  .jp2({
    quality: 100,
    chromaSubsampling: '4:4:4'
  })
  .toBuffer();
```


## tiff
> tiff([options]) ⇒ <code>Sharp</code>

使用这些 TIFF 选项设置输出图像。

通过 [withMetadata](#withmetadata) 可以以每英寸像素设置 `density`，而不是提供 `xres` 和 `yres` 以每毫米像素。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数 1-100 |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 TIFF 输出，否则尝试使用输入格式 |
| [options.compression] | <code>string</code> | <code>&quot;&#x27;jpeg&#x27;&quot;</code> | 压缩选项：none、jpeg、deflate、packbits、ccittfax4、lzw、webp、zstd、jp2k |
| [options.predictor] | <code>string</code> | <code>&quot;&#x27;horizontal&#x27;&quot;</code> | 压缩预测选项：none、horizontal、float |
| [options.pyramid] | <code>boolean</code> | <code>false</code> | 写入图像金字塔 |
| [options.tile] | <code>boolean</code> | <code>false</code> | 写入切片 TIFF |
| [options.tileWidth] | <code>number</code> | <code>256</code> | 水平瓦片大小 |
| [options.tileHeight] | <code>number</code> | <code>256</code> | 垂直瓦片大小 |
| [options.xres] | <code>number</code> | <code>1.0</code> | 每毫米像素的水平分辨率 |
| [options.yres] | <code>number</code> | <code>1.0</code> | 每毫米像素的垂直分辨率 |
| [options.resolutionUnit] | <code>string</code> | <code>&quot;&#x27;inch&#x27;&quot;</code> | 分辨率单位选项：inch、cm |
| [options.bitdepth] | <code>number</code> | <code>8</code> | 将位深度减少到 1、2 或 4 位 |
| [options.miniswhite] | <code>boolean</code> | <code>false</code> | 以白色小图像表示 1 位图像 |

**示例**  
```js
// 将 SVG 输入转换为 LZW 压缩、每像素 1 位 TIFF 输出
sharp('input.svg')
  .tiff({
    compression: 'lzw',
    bitdepth: 1
  })
  .toFile('1-bpp-output.tiff')
  .then(info => { ... });
```


## avif
> avif([options]) ⇒ <code>Sharp</code>

使用这些 AVIF 选项设置输出图像。

不支持 AVIF 图像序列。
预构建的二进制文件仅支持 8 位深度。

此功能在 Windows ARM64 平台上是实验性的，并且需要支持 ARM64v8.4 或更高版本的 CPU。

**抛出**:

- <code>Error</code> 无效选项

**自**: 0.27.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>50</code> | 质量，整数 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力程度，在 0（最快）和 9（最慢）之间 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度子采样 |
| [options.bitdepth] | <code>number</code> | <code>8</code> | 将位深度设置为 8、10 或 12 位 |

**示例**  
```js
const data = await sharp(input)
  .avif({ effort: 2 })
  .toBuffer();
```
**示例**  
```js
const data = await sharp(input)
  .avif({ lossless: true })
  .toBuffer();
```


## heif
> heif(options) ⇒ <code>Sharp</code>

使用这些 HEIF 选项设置输出图像。

对使用 `hevc` 压缩的受专利保护的 HEIC 图像的支持需要使用全局安装的 libvips 编译，并支持 libheif、libde265 和 x265。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.23.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| options | <code>Object</code> |  | 输出选项 |
| options.compression | <code>string</code> |  | 压缩格式：av1，hevc |
| [options.quality] | <code>number</code> | <code>50</code> | 质量，整数 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力程度，在 0（最快）和 9（最慢）之间 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度子采样 |
| [options.bitdepth] | <code>number</code> | <code>8</code> | 将位深度设置为 8、10 或 12 位 |

**示例**  
```js
const data = await sharp(input)
  .heif({ compression: 'hevc' })
  .toBuffer();
```


## jxl
> jxl([options]) ⇒ <code>Sharp</code>

使用这些 JPEG-XL (JXL) 选项设置输出图像。

此功能为实验性，请勿在生产系统中使用。

需要支持 libjxl 的 libvips 编译。
预构建的二进制文件不包括此项 - 请参阅
[安装自定义 libvips](https://sharp.pixelplumbing.com/install#custom-libvips)。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.31.3  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.distance] | <code>number</code> | <code>1.0</code> | 最大编码错误，范围在 0（最高质量）到 15（最低质量）之间 |
| [options.quality] | <code>number</code> |  | 根据 JPEG 类似质量计算 `distance`，范围在 1 到 100 之间，如果指定了则覆盖距离 |
| [options.decodingTier] | <code>number</code> | <code>0</code> | 目标解码速度层，范围在 0（最高质量）到 4（最低质量）之间 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力程度，在 1（最快）和 9（最慢）之间 |
| [options.loop] | <code>number</code> | <code>0</code> | 动画迭代次数，使用 0 表示无限动画 |
| [options.delay] | <code>number</code> \| <code>Array.&lt;number&gt;</code> |  | 动画帧之间的延迟（以毫秒为单位） |



## raw
> raw([options]) ⇒ <code>Sharp</code>

强制输出为原始的、无压缩的像素数据。
像素顺序为从左到右、从上到下，不带填充。
通道顺序将是 RGB 或 RGBA，适用于非灰度颜色空间。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.depth] | <code>string</code> | <code>&quot;&#x27;uchar&#x27;&quot;</code> | 位深度，值之一：char、uchar（默认）、short、ushort、int、uint、float、complex、double、dpcomplex |

**示例**  
```js
// 从 JPEG 输入提取原始的无符号 8 位 RGB 像素数据
const { data, info } = await sharp('input.jpg')
  .raw()
  .toBuffer({ resolveWithObject: true });
```
**示例**  
```js
// 从 PNG 输入提取 alpha 通道作为原始的无符号 16 位像素数据
const data = await sharp('input.png')
  .ensureAlpha()
  .extractChannel(3)
  .toColourspace('b-w')
  .raw({ depth: 'ushort' })
  .toBuffer();
```


## tile
> tile([options]) ⇒ <code>Sharp</code>

使用基于瓦片的深度缩放（图像金字塔）输出。

通过 `toFormat`、`jpeg`、`png` 或 `webp` 函数设置瓦片图像的格式和选项。
使用 `.zip` 或 `.szi` 文件扩展名与 `toFile` 一起写入压缩归档文件格式。

当输出为缓冲区或流时，容器将被设置为 `zip`，否则默认为 `fs`。


**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.size] | <code>number</code> | <code>256</code> | 瓦片大小（以像素为单位），值范围在 1 到 8192 之间。 |
| [options.overlap] | <code>number</code> | <code>0</code> | 瓦片重叠（以像素为单位），值范围在 0 到 8192 之间。 |
| [options.angle] | <code>number</code> | <code>0</code> | 瓦片的旋转角度，必须是 90 的倍数。 |
| [options.background] | <code>string</code> \| <code>Object</code> | <code>&quot;{r: 255, g: 255, b: 255, alpha: 1}&quot;</code> | 背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为无透明度的白色。 |
| [options.depth] | <code>string</code> |  | 要制作金字塔的深度，可能的值为 `onepixel`、`onetile` 或 `one`，默认基于布局。 |
| [options.skipBlanks] | <code>number</code> | <code>-1</code> | 跳过瓦片生成的阈值。范围为 0-255（8 位图像），0-65535（16 位图像）。默认值为 `google` 布局的 5，否则为 -1（无跳过）。 |
| [options.container] | <code>string</code> | <code>&quot;&#x27;fs&#x27;&quot;</code> | 瓦片容器，值为 `fs`（文件系统）或 `zip`（压缩文件）。 |
| [options.layout] | <code>string</code> | <code>&quot;&#x27;dz&#x27;&quot;</code> | 文件系统布局，可能的值为 `dz`、`iiif`、`iiif3`、`zoomify` 或 `google`。 |
| [options.centre] | <code>boolean</code> | <code>false</code> | 在瓦片中居中图像。 |
| [options.center] | <code>boolean</code> | <code>false</code> | `centre` 的另一种拼写。 |
| [options.id] | <code>string</code> | <code>&quot;&#x27;https://example.com/iiif&#x27;&quot;</code> | 当 `layout` 为 `iiif`/`iiif3` 时，设置 `info.json` 的 `@id`/`id` 属性 |
| [options.basename] | <code>string</code> |  | 当容器为 zip 时，zip 文件中的目录名称。 |

**示例**  
```js
sharp('input.tiff')
  .png()
  .tile({
    size: 512
  })
  .toFile('output.dz', function(err, info) {
    // output.dzi 是 Deep Zoom XML 定义
    // output_files 包含按缩放级别分组的 512x512 瓦片
  });
```
**示例**  
```js
const zipFileWithTiles = await sharp(input)
  .tile({ basename: "tiles" })
  .toBuffer();
```
**示例**  
```js
const iiififier = sharp().tile({ layout: "iiif" });
readableStream
  .pipe(iiififier)
  .pipe(writeableStream);
```


## timeout
> timeout(options) ⇒ <code>Sharp</code>

为处理设置超时（以秒为单位）。
使用零值以无限期继续处理，默认行为。

时钟在 libvips 打开输入图像进行处理时开始。
等待 libuv 线程可用的时间不包括在内。


**自**: 0.29.2  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> |  |
| options.seconds | <code>number</code> | 超时处理后停止的秒数 |

**示例**  
```js
// 确保处理时间不超过 3 秒
try {
  const data = await sharp(input)
    .blur(1000)
    .timeout({ seconds: 3 })
    .toBuffer();
} catch (err) {
  if (err.message.includes('timeout')) { ... }
}
```
