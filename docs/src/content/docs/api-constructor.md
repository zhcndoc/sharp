---
# 该文件是从 lib/constructor.js 中的 JSDoc 自动生成的
title: 构造函数
---

## Sharp
> Sharp


**发出**: <code>Sharp#event:info</code>, <code>Sharp#event:warning</code>  
<a name="new_Sharp_new"></a>

### new
> new Sharp([input], [options])

构造函数工厂，用于创建 `sharp` 的实例，随后可以链式调用其他方法。

可以从此对象流出 JPEG、PNG、WebP、GIF、AVIF 或 TIFF 格式的图像数据。当使用基于流的输出时，可以从 `info` 事件中获得派生属性。

在处理过程中遇到的非关键问题将作为 `warning` 事件发出。

实现了 [stream.Duplex](http://nodejs.org/api/stream.html#stream_class_stream_duplex) 类。

当加载多个页面/帧的动画图像时，这些将组合成一个垂直堆叠的“厕纸卷”图像，其整体高度为 `pageHeight` 乘以 `pages` 的数量。

**抛出**:

- <code>Error</code> 无效参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [input] | <code>Buffer</code> \| <code>ArrayBuffer</code> \| <code>Uint8Array</code> \| <code>Uint8ClampedArray</code> \| <code>Int8Array</code> \| <code>Uint16Array</code> \| <code>Int16Array</code> \| <code>Uint32Array</code> \| <code>Int32Array</code> \| <code>Float32Array</code> \| <code>Float64Array</code> \| <code>string</code> \| <code>Array</code> |  | 如果提供，可以是包含 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像数据的 Buffer / ArrayBuffer / Uint8Array / Uint8ClampedArray，或包含原始像素图像数据的 TypedArray，或包含指向 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像文件的文件系统路径的字符串。也可以提供输入数组，这些输入会被拼接在一起。未提供时，可以将 JPEG、PNG、WebP、AVIF、GIF、SVG、TIFF 或原始像素图像数据通过流输入到对象中。 |
| [options] | <code>Object</code> |  | 如果提供，则为带有可选属性的对象。 |
| [options.failOn] | <code>string</code> | <code>&quot;&#x27;warning&#x27;&quot;</code> | 何时中止对无效像素数据的处理，可选值按敏感度从低到高依次为：'none'、'truncated'、'error'、'warning'。更高等级包含更低等级。无效元数据总会中止。对不受信任的输入请使用默认的 'warning' 等级。 |
| [options.limitInputPixels] | <code>number</code> \| <code>boolean</code> | <code>268402689</code> | 不处理像素总数（宽 x 高）超过此限制的输入图像。假定输入元数据中包含的图像尺寸是可信的。像素总数的整数值，设为 zero 或 false 可移除限制，设为 true 可使用默认限制 268402689（0x3FFF x 0x3FFF）。 |
| [options.limitInputChannels] | <code>number</code> \| <code>boolean</code> | <code>5</code> | 不处理通道数超过此限制的输入图像。假定图像元数据是可信的。通道数的整数值，设为 zero 或 false 可移除限制，设为 true 可使用默认限制 5。 |
| [options.unlimited] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可移除有助于防止内存耗尽的安全特性（JPEG、PNG、SVG、HEIF）。 |
| [options.autoOrient] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可旋转/翻转图像以匹配 EXIF `Orientation`（如果存在）。 |
| [options.sequentialRead] | <code>boolean</code> | <code>true</code> | 将其设为 `false` 可使用随机访问而不是顺序读取。某些操作会自动这样做。 |
| [options.density] | <code>number</code> | <code>72</code> | 渲染 SVG 和 PDF 图像时使用的 DPI，范围为 1 到 100000。 |
| [options.ignoreIcc] | <code>number</code> | <code>false</code> | 是否忽略嵌入的 ICC 配置文件（如果有）。 |
| [options.pages] | <code>number</code> | <code>1</code> | 多页输入（GIF、WebP、TIFF）要提取的页数，全部页数使用 -1。 |
| [options.page] | <code>number</code> | <code>0</code> | 多页输入（GIF、WebP、TIFF）从第几页开始提取，基于零。 |
| [options.animated] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可读取动画图像（GIF、WebP、TIFF）的所有帧/页，相当于将 `pages` 设为 `-1`。 |
| [options.raw] | <code>Object</code> |  | 描述原始像素输入图像数据。像素排列请参见 `raw()`。 |
| [options.raw.width] | <code>number</code> |  | 像素宽度的整数值。 |
| [options.raw.height] | <code>number</code> |  | 像素高度的整数值。 |
| [options.raw.channels] | <code>number</code> |  | 通道数的整数值，介于 1 和 4 之间。 |
| [options.raw.premultiplied] | <code>boolean</code> |  | 指定原始输入已经预乘，设为 `true` 可避免 sharp 对图像进行预乘。（可选，默认 `false`） |
| [options.raw.pageHeight] | <code>number</code> |  | 动画图像每一页/帧的像素高度，必须是 `raw.height` 的整数因子。 |
| [options.create] | <code>Object</code> |  | 描述要创建的新图像。 |
| [options.create.width] | <code>number</code> |  | 像素宽度的整数值。 |
| [options.create.height] | <code>number</code> |  | 像素高度的整数值。 |
| [options.create.channels] | <code>number</code> |  | 通道数的整数值，取 3（RGB）或 4（RGBA）。 |
| [options.create.background] | <code>string</code> \| <code>Object</code> |  | 由 [color](https://www.npmjs.org/package/color) 模块解析，以提取红、绿、蓝和 alpha 的值。 |
| [options.create.pageHeight] | <code>number</code> |  | 动画图像每一页/帧的像素高度，必须是 `create.height` 的整数因子。 |
| [options.create.noise] | <code>Object</code> |  | 描述要创建的噪声。 |
| [options.create.noise.type] | <code>string</code> |  | 生成噪声的类型，目前仅支持 `gaussian`。 |
| [options.create.noise.mean] | <code>number</code> | <code>128</code> | 生成噪声中像素值的均值。 |
| [options.create.noise.sigma] | <code>number</code> | <code>30</code> | 生成噪声中像素值的标准差。 |
| [options.text] | <code>Object</code> |  | 描述要创建的新文本图像。 |
| [options.text.text] | <code>string</code> |  | 要渲染的 UTF-8 字符串文本。可以包含 Pango 标记，例如 `<i>Le</i>Monde`。 |
| [options.text.font] | <code>string</code> |  | 要使用的字体名称。 |
| [options.text.fontfile] | <code>string</code> |  | 可供 `font` 使用的字体文件的绝对文件系统路径。 |
| [options.text.width] | <code>number</code> | <code>0</code> | 用于自动换行的像素整数宽度。宽于此值的文本行将按单词边界断行。 |
| [options.text.height] | <code>number</code> | <code>0</code> | 最大像素高度整数。定义后，`dpi` 将被忽略，文本会自动适配由 `width` 和 `height` 定义的像素分辨率。若未指定 `width` 或将其设为 0，则会被忽略。 |
| [options.text.align] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 多行文本的对齐样式（`'left'`、`'centre'`、`'center'`、`'right'`）。 |
| [options.text.justify] | <code>boolean</code> | <code>false</code> | 将其设为 true 可对文本应用两端对齐。 |
| [options.text.dpi] | <code>number</code> | <code>72</code> | 渲染文本时的分辨率（尺寸）。若指定了 `height`，则不生效。 |
| [options.text.rgba] | <code>boolean</code> | <code>false</code> | 将其设为 true 可启用 RGBA 输出。这对于彩色表情符号渲染，或支持诸如 `<span foreground="red">Red!</span>` 之类的 pango 标记功能很有用。 |
| [options.text.spacing] | <code>number</code> | <code>0</code> | 文本行高，单位为 point。若未指定，则使用字体行高。 |
| [options.text.wrap] | <code>string</code> | <code>&quot;&#x27;word&#x27;&quot;</code> | 提供宽度时的自动换行样式，可选：'word'、'char'、'word-char'（优先按单词，失败时按字符）或 'none'。 |
| [options.join] | <code>Object</code> |  | 描述数组中的输入图像应如何连接。 |
| [options.join.across] | <code>number</code> | <code>1</code> | 水平连接的图像数量。 |
| [options.join.animated] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可将这些图像连接为动画图像。 |
| [options.join.shim] | <code>number</code> | <code>0</code> | 在连接图像之间插入的像素数。 |
| [options.join.background] | <code>string</code> \| <code>Object</code> |  | 由 [color](https://www.npmjs.org/package/color) 模块解析，以提取红、绿、蓝和 alpha 的值。 |
| [options.join.halign] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 水平连接图像的水平对齐样式（`'left'`、`'centre'`、`'center'`、`'right'`）。 |
| [options.join.valign] | <code>string</code> | <code>&quot;&#x27;top&#x27;&quot;</code> | 垂直连接图像的垂直对齐样式（`'top'`、`'centre'`、`'center'`、`'bottom'`）。 |
| [options.tiff] | <code>Object</code> |  | TIFF 特定选项的描述。 |
| [options.tiff.subifd] | <code>number</code> | <code>-1</code> | 为 OME-TIFF 提取的子图像文件目录，默认使用主图像。 |
| [options.svg] | <code>Object</code> |  | SVG 特定选项的描述。 |
| [options.svg.stylesheet] | <code>string</code> |  | SVG 输入的自定义 CSS，在 CSS 级联中使用用户来源应用。 |
| [options.svg.highBitdepth] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可将 SVG 输入渲染为每通道 32 位（总计 128 位）的 RGBA，而不是每通道 8 位（总计 32 位）。 |
| [options.pdf] | <code>Object</code> |  | PDF 特定选项的描述。需要使用全局安装的、编译时支持 PDFium、Poppler、ImageMagick 或 GraphicsMagick 的 libvips。 |
| [options.pdf.background] | <code>string</code> \| <code>Object</code> |  | 当 PDF 部分透明时使用的背景颜色。由 [color](https://www.npmjs.org/package/color) 模块解析，以提取红、绿、蓝和 alpha 的值。 |
| [options.openSlide] | <code>Object</code> |  | OpenSlide 特定选项的描述。需要使用全局安装的、编译时支持 OpenSlide 的 libvips。 |
| [options.openSlide.level] | <code>number</code> | <code>0</code> | 要从多层输入中提取的层级，基于零。 |
| [options.jp2] | <code>Object</code> |  | JPEG 2000 特定选项的描述。需要使用全局安装的、编译时支持 OpenJPEG 的 libvips。 |
| [options.jp2.oneshot] | <code>boolean</code> | <code>false</code> | 将其设为 `true` 可一次性解码平铺的 JPEG 2000 图像，以提高兼容性。 |

**示例**  
```js
sharp('input.jpg')
  .resize(300, 200)
  .toFile('output.jpg', function(err) {
    // output.jpg 是一个宽 300 像素、高 200 像素的图像
    // 包含了 input.jpg 的缩放和裁剪版本
  });
```
**示例**  
```js
// 从远程 URL 读取图像数据,
// 调整到 300 像素宽,
// 发出包含计算后尺寸的 'info' 事件
// 最后将图像数据写入 writableStream
const { body } = await fetch('https://...');
const readableStream = Readable.fromWeb(body);
const transformer = sharp()
  .resize(300)
  .on('info', ({ height }) => {
    console.log(`图像高度是 ${height}`);
  });
readableStream.pipe(transformer).pipe(writableStream);
```
**示例**  
```js
// Web Streams API，需要 Node.js >= 24.15.0
import { Duplex } from 'node:stream';

const { body } = await fetch('https://...');
const transformer = Duplex.toWeb(
  sharp().resize(300),
  { readableType: 'bytes' }
);
body.pipeThrough(transformer).pipeTo(writable);
```
**Example**  
```js
// 创建一个 300x200 的空白 PNG 图像，像素为半透明红色
sharp({
  create: {
    width: 300,
    height: 200,
    channels: 4,
    background: { r: 255, g: 0, b: 0, alpha: 0.5 }
  }
})
.png()
.toBuffer()
.then( ... );
```
**示例**  
```js
// 将动画 GIF 转换为动画 WebP
await sharp('in.gif', { animated: true }).toFile('out.webp');
```
**示例**  
```js
// 读取原始像素数组并保存为 png
const input = Uint8Array.from([255, 255, 255, 0, 0, 0]); // 或 Uint8ClampedArray
const image = sharp(input, {
  // 因为输入不包含其维度或通道数
  // 我们需要在构造函数选项中指定
  raw: {
    width: 2,
    height: 1,
    channels: 3
  }
});
await image.toFile('my-two-pixels.png');
```
**示例**  
```js
// 生成 RGB 高斯噪音
await sharp({
  create: {
    width: 300,
    height: 200,
    channels: 3,
    noise: {
      type: 'gaussian',
      mean: 128,
      sigma: 30
    }
 }
}).toFile('noise.png');
```
**示例**  
```js
// 从文本生成图像
await sharp({
  text: {
    text: 'Hello, world!',
    width: 400, // 最大宽度
    height: 300 // 最大高度
  }
}).toFile('text_bw.png');
```
**示例**  
```js
// 使用 pango 标记和字体从文本生成 rgba 图像
await sharp({
  text: {
    text: '<span foreground="red">Red!</span><span background="cyan">blue</span>',
    font: 'sans',
    rgba: true,
    dpi: 300
  }
}).toFile('text_rgba.png');
```
**示例**  
```js
// 将四个输入图像作为 2x2 网格连接，间隔 4 像素
const data = await sharp(
 [image1, image2, image3, image4],
 { join: { across: 2, shim: 4 } }
).toBuffer();
```
**示例**  
```js
// 从表情符号生成一个两帧的动画图像
const images = ['😀', '😛'].map(text => ({
  text: { text, width: 64, height: 64, channels: 4, rgba: true }
}));
await sharp(images, { join: { animated: true } }).toFile('out.gif');
```


## clone
> clone() ⇒ [<code>Sharp</code>](#Sharp)

快照 Sharp 实例，返回一个新的实例。克隆的实例继承其父实例的输入。这使得多个输出流，并因此多个处理管道能够共享单个输入流。

**示例**  
```js
// firstWritableStream 接收自动旋转、调整大小后的 readableStream
// secondWritableStream 接收自动旋转、提取区域后的 readableStream

const pipeline = sharp().rotate();
pipeline
  .clone()
  .resize(800, 600)
  .pipe(firstWritableStream);
pipeline
  .clone()
  .extract({ left: 20, top: 20, width: 100, height: 100 })
  .pipe(secondWritableStream);
readableStream.pipe(pipeline);
```
**示例**  
```js
// 创建一个管道，用于下载图片、调整大小并将其格式化为不同文件
// 使用 Promises 来判断管道何时完成

const sharpStream = sharp();

const promises = [];
promises.push(
  sharpStream
    .clone()
    .jpeg({ quality: 100 })
    .toFile("originalFile.jpg")
);
promises.push(
  sharpStream
    .clone()
    .resize({ width: 500 })
    .jpeg({ quality: 80 })
    .toFile("optimized-500.jpg")
);
promises.push(
  sharpStream
    .clone()
    .resize({ width: 500 })
    .webp({ quality: 80 })
    .toFile("optimized-500.webp")
);

const res = await fetch("https://www.example.com/some-file.jpg")
Readable.fromWeb(res.body).pipe(sharpStream);
await Promise.all(promises);
```