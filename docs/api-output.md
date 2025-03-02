## toFile
> toFile(fileOut, [callback]) ⇒ <code>Promise.&lt;Object&gt;</code>

将输出图像数据写入文件。

如果未显式选择输出格式，则将根据扩展名推断，支持 JPEG、PNG、WebP、AVIF、TIFF、GIF、DZI 和 libvips 的 V 格式。请注意，仅支持缓冲区输出的原始像素数据。

默认情况下，所有元数据将被删除，包括基于 EXIF 的方向。有关控制此设置，请参见 [withMetadata](#withmetadata)。

调用者负责确保目录结构和权限存在。

如果没有提供 `callback`，则返回一个 `Promise`。

**返回**: <code>Promise.&lt;Object&gt;</code> - - 当未提供回调时  
**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| fileOut | <code>string</code> | 写入图像数据的路径。 |
| [callback] | <code>function</code> | 在完成时调用，带有两个参数 `(err, info)`。`info` 包含输出图像的 `format`、`size`（字节）、`width`、`height`、`channels` 和 `premultiplied`（指示是否使用了预乘）。使用裁剪策略时还包含 `cropOffsetLeft` 和 `cropOffsetTop`。使用注意力裁剪策略时还包含 `attentionX` 和 `attentionY`，是裁剪区域的焦点。动态图像输出还将包含 `pageHeight` 和 `pages`。如果图像是从文本创建的，可能还会包含 `textAutofitDpi`（字体渲染时的 DPI）。 |

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

将输出写入缓冲区。
支持 JPEG、PNG、WebP、AVIF、TIFF、GIF 和原始像素数据输出。

使用 [toFormat](#toformat) 或其他格式特定函数，如 [jpeg](#jpeg)、[png](#png) 等来设置输出格式。

如果未设置显式格式，则输出格式将与输入图像匹配，SVG 输入将转换为 PNG 输出。

默认情况下，所有元数据将被删除，包括基于 EXIF 的方向。有关控制此设置，请参见 [withMetadata](#withmetadata)。

`callback`（如果存在）会接收三个参数 `(err, data, info)`，其中：
- `err` 是错误（如果存在）。
- `data` 是输出的图像数据。
- `info` 包含输出图像的 `format`、`size`（字节）、`width`、`height`、`channels` 和 `premultiplied`（指示是否使用了预乘）。使用裁剪策略时还包含 `cropOffsetLeft` 和 `cropOffsetTop`。动态图像输出还将包含 `pageHeight` 和 `pages`。如果图像是从文本创建的，可能还会包含 `textAutofitDpi`（字体渲染时的 DPI）。

如果未提供 `callback`，则返回一个 `Promise`。

**返回**: <code>Promise.&lt;Buffer&gt;</code> - - 当未提供回调时  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [options] | <code>Object</code> |  |
| [options.resolveWithObject] | <code>boolean</code> | 使用包含 `data` 和 `info` 属性的对象解析 Promise，而不是仅使用 `data`。 |
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

// 创建更安全的方式来处理原始像素数据
// 这不会复制数据，而是会更改 `data` 的底层 ArrayBuffer
// 因此 `data` 和 `pixelArray` 指向同一内存位置
const pixelArray = new Uint8ClampedArray(data.buffer);

// 完成更改 pixelArray 后，sharp 将 `pixelArray` 作为输入
const { width, height, channels } = info;
await sharp(pixelArray, { raw: { width, height, channels } })
  .toFile('my-changed-image.jpg');
```


## keepExif
> keepExif() ⇒ <code>Sharp</code>

保留输入图像的所有 EXIF 元数据到输出图像中。

对于 TIFF 输出，不支持 EXIF 元数据。

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
| exif | <code>Object.&lt;string, Object.&lt;string, string&gt;&gt;</code> | 按 IFD0、IFD1 等键入的对象，包含要作为 EXIF 数据写入的键/值字符串对。 |

**示例**  
```js
const dataWithExif = await sharp(input)
  .withExif({
    IFD0: {
      Copyright: 'The National Gallery'
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

更新输出图像中的 EXIF 元数据，使用输入图像的 EXIF 元数据。

**抛出**:

- <code>Error</code> 无效参数

**自**: 0.33.0  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| exif | <code>Object.&lt;string, Object.&lt;string, string&gt;&gt;</code> | 按 IFD0、IFD1 等键入的对象，包含要作为 EXIF 数据写入的键/值字符串对。 |

**示例**  
```js
const dataWithMergedExif = await sharp(inputWithExif)
  .withExifMerge({
    IFD0: {
      Copyright: 'The National Gallery'
    }
  })
  .toBuffer();
```


## keepIccProfile
> keepIccProfile() ⇒ <code>Sharp</code>

从输入图像中保留 ICC 配置文件到输出图像中。

在必要时，将尝试将输出颜色空间转换为匹配配置文件。

**自**: 0.33.0  
**示例**  
```js
const outputWithIccProfile = await sharp(inputWithIccProfile)
  .keepIccProfile()
  .toBuffer();
```


## withIccProfile
> withIccProfile(icc, [options]) ⇒ <code>Sharp</code>

使用 ICC 配置文件进行变换并附加到输出图像。

这可以是绝对文件系统路径或内置配置文件名称（`srgb`、`p3`、`cmyk`）。


**抛出**:

- <code>Error</code> 无效参数

**自**: 0.33.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| icc | <code>string</code> |  | 输出 ICC 配置文件的绝对文件系统路径或内置配置文件名称（srgb、p3、cmyk）。 |
| [options] | <code>Object</code> |  |  |
| [options.attach] | <code>number</code> | <code>true</code> | 是否将 ICC 配置文件包含在输出图像元数据中？ |

**示例**  
```js
const outputWithP3 = await sharp(input)
  .withIccProfile('p3')
  .toBuffer();
```


## keepMetadata
> keepMetadata() ⇒ <code>Sharp</code>

保留输入图像中的所有元数据（EXIF、ICC、XMP、IPTC）到输出图像中。

当未使用 `keepMetadata` 时，默认行为是转换为与设备无关的 sRGB 颜色空间并删除所有元数据，包括移除任何 ICC 配置文件。

**自**: 0.33.0  
**示例**  
```js
const outputWithMetadata = await sharp(inputWithMetadata)
  .keepMetadata()
  .toBuffer();
```


## withMetadata
> withMetadata([options]) ⇒ <code>Sharp</code>

从输入图像中保留大多数元数据（EXIF、XMP、IPTC）到输出图像中。

这还将转换并添加一个适合网页的 sRGB ICC 配置文件（如果合适）。

允许设置或更新方向和密度。

**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [options] | <code>Object</code> |  |
| [options.orientation] | <code>number</code> | 用于更新 EXIF `Orientation` 标签，整数范围在 1 到 8 之间。 |
| [options.density] | <code>number</code> | 每英寸像素数（DPI）。 |

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

使用这些 JPEG 选项进行输出图像。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数范围 1-100 |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:2:0&#x27;&quot;</code> | 设置为 '4:4:4' 以防止色度下采样，否则默认为 '4:2:0' 色度下采样 |
| [options.optimiseCoding] | <code>boolean</code> | <code>true</code> | 优化哈夫曼编码表 |
| [options.optimizeCoding] | <code>boolean</code> | <code>true</code> | 优化哈夫曼编码表的另一种拼写 |
| [options.mozjpeg] | <code>boolean</code> | <code>false</code> | 使用 mozjpeg 默认值，相当于 `{ trellisQuantisation: true, overshootDeringing: true, optimiseScans: true, quantisationTable: 3 }` |
| [options.trellisQuantisation] | <code>boolean</code> | <code>false</code> | 应用棋盘量化 |
| [options.overshootDeringing] | <code>boolean</code> | <code>false</code> | 应用过冲去锯齿 |
| [options.optimiseScans] | <code>boolean</code> | <code>false</code> | 优化渐进扫描，强制渐进 |
| [options.optimizeScans] | <code>boolean</code> | <code>false</code> | 优化扫描的另一种拼写 |
| [options.quantisationTable] | <code>number</code> | <code>0</code> | 使用的量化表，整数范围 0-8 |
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

使用这些 PNG 选项进行输出图像。

默认情况下，PNG 输出为每像素 8 位全色。

1、2 或 4 位每像素的索引 PNG 输入将转换为 8 位每像素。将 `palette` 设置为 `true` 可以生成较慢的索引 PNG 输出。

对于 16 位每像素输出，通过 [toColourspace](/api-colour#tocolourspace) 转换为 `rgb16`。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.compressionLevel] | <code>number</code> | <code>6</code> | zlib 压缩级别，0（最快、最大）到 9（最慢、最小） |
| [options.adaptiveFiltering] | <code>boolean</code> | <code>false</code> | 使用自适应行过滤 |
| [options.palette] | <code>boolean</code> | <code>false</code> | 量化为支持 alpha 透明度的调色板图像 |
| [options.quality] | <code>number</code> | <code>100</code> | 使用最低数量的颜色以达到给定质量，设置 `palette` 为 `true` |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力程度，范围在 1（最快）和 10（最慢）之间，设置 `palette` 为 `true` |
| [options.colours] | <code>number</code> | <code>256</code> | 最大调色板项数，设置 `palette` 为 `true` |
| [options.colors] | <code>number</code> | <code>256</code> | `options.colours` 的另一种拼写，设置 `palette` 为 `true` |
| [options.dither] | <code>number</code> | <code>1.0</code> | Floyd-Steinberg 错误扩散级别，设置 `palette` 为 `true` |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 PNG 输出，否则尝试使用输入格式 |

**示例**  
```js
// 将任何输入转换为全色 PNG 输出
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

使用这些 WebP 选项进行输出图像。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数范围 1-100 |
| [options.alphaQuality] | <code>number</code> | <code>100</code> | alpha 图层的质量，整数范围 0-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩模式 |
| [options.nearLossless] | <code>boolean</code> | <code>false</code> | 使用近无损压缩模式 |
| [options.smartSubsample] | <code>boolean</code> | <code>false</code> | 使用高质量色度下采样 |
| [options.preset] | <code>string</code> | <code>&quot;&#x27;default&#x27;&quot;</code> | 预处理/过滤的命名预设，值包括：default、photo、picture、drawing、icon、text |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力，范围在 0（最快）和 6（最慢）之间 |
| [options.loop] | <code>number</code> | <code>0</code> | 动画迭代次数，使用 0 表示无限动画 |
| [options.delay] | <code>number</code> \| <code>Array.&lt;number&gt;</code> |  | 动画帧之间的延迟（以毫秒为单位） |
| [options.minSize] | <code>boolean</code> | <code>false</code> | 防止使用动画关键帧来最小化文件大小（较慢） |
| [options.mixed] | <code>boolean</code> | <code>false</code> | 允许混合有损和无损动画帧（较慢） |
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

使用这些 GIF 选项进行输出图像。

调色板的第一个条目保留透明。

如果可能，将重用输入图像的调色板。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.30.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.reuse] | <code>boolean</code> | <code>true</code> | 重用现有的调色板，否则生成新的（较慢） |
| [options.progressive] | <code>boolean</code> | <code>false</code> | 使用渐进（交错）扫描 |
| [options.colours] | <code>number</code> | <code>256</code> | 最大调色板条目数，包括透明度，范围在 2 到 256 之间 |
| [options.colors] | <code>number</code> | <code>256</code> | `options.colours` 的另一种拼写 |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力，范围在 1（最快）和 10（最慢）之间 |
| [options.dither] | <code>number</code> | <code>1.0</code> | Floyd-Steinberg 错误扩散级别，范围在 0（最少）和 1（最多）之间 |
| [options.interFrameMaxError] | <code>number</code> | <code>0</code> | 透明度的最大帧间错误，范围在 0（无损）和 32 之间 |
| [options.interPaletteMaxError] | <code>number</code> | <code>3</code> | 重新使用调色板的最大帧间错误，范围在 0 到 256 之间 |
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
// 创建 128x128 的裁剪、无抖动、动画缩略图的动画 GIF
const out = await sharp('in.gif', { animated: true })
  .resize({ width: 128, height: 128 })
  .gif({ dither: 0 })
  .toBuffer();
```
**示例**  
```js
// 动画 GIF 的有损文件大小减小
await sharp('in.gif', { animated: true })
  .gif({ interFrameMaxError: 8 })
  .toFile('optim.gif');
```


## jp2
> jp2([options]) ⇒ <code>Sharp</code>

使用这些 JP2 选项进行输出图像。

需要编译支持 OpenJPEG 的 libvips。
预构建的二进制文件不包含此功能 - 请参见
[安装自定义 libvips](https://sharp.pixelplumbing.com/install#custom-libvips)。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.29.1  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数范围 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩模式 |
| [options.tileWidth] | <code>number</code> | <code>512</code> | 横向瓦片大小 |
| [options.tileHeight] | <code>number</code> | <code>512</code> | 纵向瓦片大小 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度下采样 |

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

使用这些 TIFF 选项进行输出图像。

`density` 可以通过 [withMetadata](#withmetadata) 设置为每英寸像素，而不是提供以每毫米像素为单位的 `xres` 和 `yres`。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>80</code> | 质量，整数范围 1-100 |
| [options.force] | <code>boolean</code> | <code>true</code> | 强制 TIFF 输出，否则尝试使用输入格式 |
| [options.compression] | <code>string</code> | <code>&quot;&#x27;jpeg&#x27;&quot;</code> | 压缩选项：none、jpeg、deflate、packbits、ccittfax4、lzw、webp、zstd、jp2k |
| [options.predictor] | <code>string</code> | <code>&quot;&#x27;horizontal&#x27;&quot;</code> | 压缩预测选项：none、horizontal、float |
| [options.pyramid] | <code>boolean</code> | <code>false</code> | 写入图像金字塔 |
| [options.tile] | <code>boolean</code> | <code>false</code> | 写入平铺 TIFF |
| [options.tileWidth] | <code>number</code> | <code>256</code> | 横向瓦片大小 |
| [options.tileHeight] | <code>number</code> | <code>256</code> | 纵向瓦片大小 |
| [options.xres] | <code>number</code> | <code>1.0</code> | 每毫米的横向分辨率 |
| [options.yres] | <code>number</code> | <code>1.0</code> | 每毫米的纵向分辨率 |
| [options.resolutionUnit] | <code>string</code> | <code>&quot;&#x27;inch&#x27;&quot;</code> | 分辨率单位选项：inch、cm |
| [options.bitdepth] | <code>number</code> | <code>8</code> | 将位深度减少到 1、2 或 4 位 |
| [options.miniswhite] | <code>boolean</code> | <code>false</code> | 将 1 位图像写为 miniswhite |

**示例**  
```js
// 将 SVG 输入转换为 LZW 压缩的 1 位每像素 TIFF 输出
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

使用这些 AVIF 选项进行输出图像。

不支持 AVIF 图像序列。
预构建的二进制文件仅支持 8 位深度。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.27.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.quality] | <code>number</code> | <code>50</code> | 质量，整数范围 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力，范围在 0（最快）和 9（最慢）之间 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度下采样 |
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

使用这些 HEIF 选项进行输出图像。

支持使用 `hevc` 压缩的专利受限 HEIC 图像需要使用
安装了支持 libheif、libde265 和 x265 的全球安装的 libvips。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.23.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| options | <code>Object</code> |  | 输出选项 |
| options.compression | <code>string</code> |  | 压缩格式：av1、hevc |
| [options.quality] | <code>number</code> | <code>50</code> | 质量，整数范围 1-100 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>4</code> | CPU 努力，范围在 0（最快）和 9（最慢）之间 |
| [options.chromaSubsampling] | <code>string</code> | <code>&quot;&#x27;4:4:4&#x27;&quot;</code> | 设置为 '4:2:0' 以使用色度下采样 |
| [options.bitdepth] | <code>number</code> | <code>8</code> | 将位深度设置为 8、10 或 12 位 |

**示例**  
```js
const data = await sharp(input)
  .heif({ compression: 'hevc' })
  .toBuffer();
```


## jxl
> jxl([options]) ⇒ <code>Sharp</code>

使用这些 JPEG-XL (JXL) 选项进行输出图像。

此功能仍在实验阶段，请勿在生产系统中使用。

需要编译支持 libjxl 的 libvips。
预构建的二进制文件不包含此功能 - 请参见
[安装自定义 libvips](https://sharp.pixelplumbing.com/install#custom-libvips)。

图像元数据（EXIF、XMP）不受支持。


**抛出**:

- <code>Error</code> 无效选项

**自**: 0.31.3  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.distance] | <code>number</code> | <code>1.0</code> | 最大编码错误，范围在 0（最高质量）到 15（最低质量）之间 |
| [options.quality] | <code>number</code> |  | 根据 JPEG 类似质量计算 `distance`，在 1 到 100 之间，若指定则覆盖 `distance` |
| [options.decodingTier] | <code>number</code> | <code>0</code> | 目标解码速度层，范围在 0（最高质量）到 4（最低质量）之间 |
| [options.lossless] | <code>boolean</code> | <code>false</code> | 使用无损压缩 |
| [options.effort] | <code>number</code> | <code>7</code> | CPU 努力，范围在 3（最快）和 9（最慢）之间 |



## raw
> raw([options]) ⇒ <code>Sharp</code>

强制输出为原始、无压缩的像素数据。
像素顺序为从左到右、从上到下，不带填充。
频道顺序将是 RGB 或 RGBA，适用于非灰度色彩空间。


**抛出**:

- <code>Error</code> 无效选项


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  | 输出选项 |
| [options.depth] | <code>string</code> | <code>&quot;&#x27;uchar&#x27;&quot;</code> | 位深度，取值之一：char、uchar（默认）、short、ushort、int、uint、float、complex、double、dpcomplex |

**示例**  
```js
// 从 JPEG 输入提取原始、无符号 8 位 RGB 像素数据
const { data, info } = await sharp('input.jpg')
  .raw()
  .toBuffer({ resolveWithObject: true });
```
**示例**  
```js
// 从 PNG 输入提取 alpha 通道作为原始、无符号 16 位像素数据
const data = await sharp('input.png')
  .ensureAlpha()
  .extractChannel(3)
  .toColourspace('b-w')
  .raw({ depth: 'ushort' })
  .toBuffer();
```


## tile
> tile([options]) ⇒ <code>Sharp</code>

使用基于瓷砖的深度缩放（图像金字塔）输出。

通过在 `toFormat`、`jpeg`、`png` 或 `webp` 函数中设置格式和选项来配置瓷砖图像。
使用 `.zip` 或 `.szi` 文件扩展名与 `toFile` 一起写入压缩档案文件格式。

当输出是缓冲区或流时，容器将设置为 `zip`，否则默认为 `fs`。

需要编译支持 libgsf 的 libvips。
预构建的二进制文件不包含此功能 - 请参见
[安装自定义 libvips](https://sharp.pixelplumbing.com/install#custom-libvips)。

**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.size] | <code>number</code> | <code>256</code> | 瓷砖大小（像素），范围在 1 到 8192 之间。 |
| [options.overlap] | <code>number</code> | <code>0</code> | 瓷砖重叠（像素），范围在 0 到 8192 之间。 |
| [options.angle] | <code>number</code> | <code>0</code> | 瓷砖旋转角度，必须是 90 的倍数。 |
| [options.background] | <code>string</code> \| <code>Object</code> | <code>&quot;{r: 255, g: 255, b: 255, alpha: 1}&quot;</code> | 背景颜色，通过 [color](https://www.npmjs.org/package/color) 模块解析，默认为不透明的白色。 |
| [options.depth] | <code>string</code> |  | 金字塔的深度，可能的值为 `onepixel`、`onetile` 或 `one`，默认基于布局。 |
| [options.skipBlanks] | <code>number</code> | <code>-1</code> | 跳过瓷砖生成的阈值。8 位图像范围为 0-255，16 位图像范围为 0-65535。默认对 `google` 布局为 5，-1（不跳过）则为其他情况。 |
| [options.container] | <code>string</code> | <code>&quot;&#x27;fs&#x27;&quot;</code> | 瓷砖容器，值为 `fs`（文件系统）或 `zip`（压缩文件）。 |
| [options.layout] | <code>string</code> | <code>&quot;&#x27;dz&#x27;&quot;</code> | 文件系统布局，可能的值为 `dz`、`iiif`、`iiif3`、`zoomify` 或 `google`。 |
| [options.centre] | <code>boolean</code> | <code>false</code> | 将图像居中在瓷砖中。 |
| [options.center] | <code>boolean</code> | <code>false</code> | `center` 的另一种拼写。 |
| [options.id] | <code>string</code> | <code>&quot;&#x27;https://example.com/iiif&#x27;&quot;</code> | 当 `layout` 为 `iiif` 或 `iiif3` 时，设置 `info.json` 的 `@id`/`id` 属性 |
| [options.basename] | <code>string</code> |  | 当容器为 `zip` 时，设置 zip 文件中目录的名称。 |

**示例**  
```js
sharp('input.tiff')
  .png()
  .tile({
    size: 512
  })
  .toFile('output.dz', function(err, info) {
    // output.dzi 是深度缩放 XML 定义
    // output_files 包含按缩放级别分组的 512x512 瓷砖
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

设置处理超时（以秒为单位）。
使用零值继续无限处理，这是默认行为。

计时从 libvips 打开输入图像进行处理时开始。
等待 libuv 线程变为可用的时间不包括在内。

**自**: 0.29.2  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> |  |
| options.seconds | <code>number</code> | 处理将在多少秒后停止 |

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