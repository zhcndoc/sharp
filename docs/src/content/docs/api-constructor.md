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
| [input] | <code>Buffer</code> \| <code>ArrayBuffer</code> \| <code>Uint8Array</code> \| <code>Uint8ClampedArray</code> \| <code>Int8Array</code> \| <code>Uint16Array</code> \| <code>Int16Array</code> \| <code>Uint32Array</code> \| <code>Int32Array</code> \| <code>Float32Array</code> \| <code>Float64Array</code> \| <code>string</code> \| <code>Array</code> |  | 若存在，则可以是包含 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像数据的 Buffer / ArrayBuffer / Uint8Array / Uint8ClampedArray，或包含原始像素图像数据的 TypedArray，或包含 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像文件系统路径的字符串。也可以提供输入数组，这些将被合并。当未提供时，可通过流传入 JPEG、PNG、WebP、AVIF、GIF、SVG、TIFF 或原始像素图像数据。 |
| [options] | <code>Object</code> |  | 若存在，则是带有可选属性的对象。 |
| [options.failOn] | <code>string</code> | <code>&quot;&#x27;warning&#x27;&quot;</code> | 在何种情况下中止无效像素数据的处理，选项之一（按灵敏度排列，从低到高）：'none'，'truncated'，'error'，'warning'。较高级别含有较低级别的含义。无效元数据将始终中止。 |
| [options.limitInputPixels] | <code>number</code> \| <code>boolean</code> | <code>268402689</code> | 不处理像素数量（宽 x 高）超过此限制的输入图像。假设输入元数据中的图像尺寸是可信的。整数像素数，0 或 false 去除限制，true 使用默认限制 268402689 (0x3FFF x 0x3FFF)。 |
| [options.unlimited] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以移除防止内存耗尽的安全措施（针对 JPEG、PNG、SVG、HEIF）。 |
| [options.autoOrient] | <code>boolean</code> | <code>false</code> | 设置为 `true` 根据 EXIF `Orientation` 旋转/翻转图像（如果存在）。 |
| [options.sequentialRead] | <code>boolean</code> | <code>true</code> | 设置为 `false` 使用随机访问而非顺序读取。一些操作会自动使用随机访问。 |
| [options.density] | <code>number</code> | <code>72</code> | 表示矢量图像 DPI 的数值，范围是 1 到 100000。 |
| [options.ignoreIcc] | <code>number</code> | <code>false</code> | 是否忽略内嵌的 ICC 配置文件（如果有）。 |
| [options.pages] | <code>number</code> | <code>1</code> | 多页输入（GIF、WebP、TIFF）要提取的页数，使用 -1 表示所有页。 |
| [options.page] | <code>number</code> | <code>0</code> | 多页输入（GIF、WebP、TIFF）开始提取的页码，基于 0。 |
| [options.animated] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以读取动画图像（GIF、WebP、TIFF）的所有帧/页，相当于设置 `pages` 为 `-1`。 |
| [options.raw] | <code>Object</code> |  | 描述原始像素输入图像数据。参见 `raw()` 了解像素排序。 |
| [options.raw.width] | <code>number</code> |  | 整数宽度（像素）。 |
| [options.raw.height] | <code>number</code> |  | 整数高度（像素）。 |
| [options.raw.channels] | <code>number</code> |  | 通道数量，介于 1 到 4 之间的整数。 |
| [options.raw.premultiplied] | <code>boolean</code> |  | 指定原始输入已经预乘，如果是则设置为 `true` 以避免 sharp 再次预乘图像。（可选，默认 `false`） |
| [options.raw.pageHeight] | <code>number</code> |  | 动画图像每页/帧的像素高度，必须是 `raw.height` 的整数倍数。 |
| [options.create] | <code>Object</code> |  | 描述要创建的新图像。 |
| [options.create.width] | <code>number</code> |  | 整数宽度（像素）。 |
| [options.create.height] | <code>number</code> |  | 整数高度（像素）。 |
| [options.create.channels] | <code>number</code> |  | 通道数，3（RGB）或 4（RGBA）。 |
| [options.create.background] | <code>string</code> \| <code>Object</code> |  | 通过 [color](https://www.npmjs.org/package/color) 模块解析以获取红、绿、蓝和透明度值。 |
| [options.create.pageHeight] | <code>number</code> |  | 动画图像每页/帧像素高度，必须是 `create.height` 的整数倍数。 |
| [options.create.noise] | <code>Object</code> |  | 描述要创建的噪声。 |
| [options.create.noise.type] | <code>string</code> |  | 生成的噪声类型，目前仅支持 `gaussian`。 |
| [options.create.noise.mean] | <code>number</code> | <code>128</code> | 生成噪声中像素的均值。 |
| [options.create.noise.sigma] | <code>number</code> | <code>30</code> | 生成噪声中像素值的标准差。 |
| [options.text] | <code>Object</code> |  | 描述新文本图像。 |
| [options.text.text] | <code>string</code> |  | 作为 UTF-8 字符串要渲染的文本。可包含 Pango 标记，如 `<i>Le</i>Monde`。 |
| [options.text.font] | <code>string</code> |  | 渲染所用字体名称。 |
| [options.text.fontfile] | <code>string</code> |  | 字体文件的绝对文件系统路径，可用于 `font`。 |
| [options.text.width] | <code>number</code> | <code>0</code> | 整数像素宽度，用于自动换行。超出此宽度的文本行将在词边界处折行。 |
| [options.text.height] | <code>number</code> | <code>0</code> | 最大整数像素高度。定义后，将忽略 `dpi`，文本将自动适应由 `width` 和 `height` 定义的像素分辨率。如果未指定或为 0，则忽略该属性。 |
| [options.text.align] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 多行文本的对齐方式（'left'、'centre'、'center'、'right'）。 |
| [options.text.justify] | <code>boolean</code> | <code>false</code> | 设置为 true 应用文本两端对齐。 |
| [options.text.dpi] | <code>number</code> | <code>72</code> | 文本渲染分辨率（大小）。指定了 `height` 时无效。 |
| [options.text.rgba] | <code>boolean</code> | <code>false</code> | 设置为 true 以启用 RGBA 输出。适用于彩色表情符号渲染或支持 pango 标记功能，如 `<span foreground="red">Red!</span>`。 |
| [options.text.spacing] | <code>number</code> | <code>0</code> | 文本行高（单位：点）。未指定时使用字体默认行高。 |
| [options.text.wrap] | <code>string</code> | <code>&quot;&#x27;word&#x27;&quot;</code> | 提供宽度时的换行方式，选项为：'word'、'char'、'word-char'（优先词边界，回退字符边界）或 'none'。 |
| [options.join] | <code>Object</code> |  | 描述如何合并输入图像数组。 |
| [options.join.across] | <code>number</code> | <code>1</code> | 水平合并图像的数量。 |
| [options.join.animated] | <code>boolean</code> | <code>false</code> | 设置为 `true` 将图像合并为动画图像。 |
| [options.join.shim] | <code>number</code> | <code>0</code> | 合并图像间的间距像素数。 |
| [options.join.background] | <code>string</code> \| <code>Object</code> |  | 通过 [color](https://www.npmjs.org/package/color) 模块解析以获取红、绿、蓝和透明度值。 |
| [options.join.halign] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 水平合并图像时的对齐方式（'left'、'centre'、'center'、'right'）。 |
| [options.join.valign] | <code>string</code> | <code>&quot;&#x27;top&#x27;&quot;</code> | 垂直合并图像时的对齐方式（'top'、'centre'、'center'、'bottom'）。 |
| [options.tiff] | <code>Object</code> |  | 描述 TIFF 特定选项。 |
| [options.tiff.subifd] | <code>number</code> | <code>-1</code> | 用于提取 OME-TIFF 子图像文件目录，默认主图像。 |
| [options.svg] | <code>Object</code> |  | 描述 SVG 特定选项。 |
| [options.svg.stylesheet] | <code>string</code> |  | SVG 输入的自定义 CSS，在 CSS 级联期间以用户来源应用。 |
| [options.svg.highBitdepth] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以 32 位/通道（128 位）渲染 SVG 输入，而非 8 位/通道（32 位）RGBA。 |
| [options.pdf] | <code>Object</code> |  | 描述 PDF 特定选项。需要全局安装的 libvips，编译时支持 PDFium、Poppler、ImageMagick 或 GraphicsMagick。 |
| [options.pdf.background] | <code>string</code> \| <code>Object</code> |  | PDF 部分透明时使用的背景色。通过 [color](https://www.npmjs.org/package/color) 模块解析为红绿蓝和透明度值。 |
| [options.openSlide] | <code>Object</code> |  | 描述 OpenSlide 特定选项。需要全局安装的 libvips，编译时支持 OpenSlide。 |
| [options.openSlide.level] | <code>number</code> | <code>0</code> | 多级输入中提取的层级，基于 0。 |
| [options.jp2] | <code>Object</code> |  | 描述 JPEG 2000 特定选项。需要全局安装的 libvips，编译时支持 OpenJPEG。 |
| [options.jp2.oneshot] | <code>boolean</code> | <code>false</code> | 设置为 `true` 单次操作解码瓦片 JPEG 2000 图像，提高兼容性。 |

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
// 从远程 URL 读取图像数据，
// 调整宽度到 300 像素，
// 发出一个 'info' 事件，带有计算的维度，
// 最后将图像数据写入 writableStream
const { body } = fetch('https://...');
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
// 创建一个 300x200 的 PNG 图像，像素是半透明的红色
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
const pipeline = sharp().rotate();
pipeline.clone().resize(800, 600).pipe(firstWritableStream);
pipeline.clone().extract({ left: 20, top: 20, width: 100, height: 100 }).pipe(secondWritableStream);
readableStream.pipe(pipeline);
// firstWritableStream 接收自动旋转、调整大小的 readableStream
// secondWritableStream 接收自动旋转，提取的 readableStream 区域
```
**示例**  
```js
// 创建一个管道，将会下载图像，调整大小并格式化为不同文件
// 使用承诺来知道管道何时完成
const fs = require("fs");
const got = require("got");
const sharpStream = sharp({ failOn: 'none' });

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

// https://github.com/sindresorhus/got/blob/main/documentation/3-streams.md
got.stream("https://www.example.com/some-file.jpg").pipe(sharpStream);

Promise.all(promises)
  .then(res => { console.log("完成!", res); })
  .catch(err => {
    console.error("处理文件时出错，清理一下", err);
    try {
      fs.unlinkSync("originalFile.jpg");
      fs.unlinkSync("optimized-500.jpg");
      fs.unlinkSync("optimized-500.webp");
    } catch (e) {}
  });
```