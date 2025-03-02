## Sharp
> Sharp

**发出**: <code>Sharp#event:info</code>, <code>Sharp#event:warning</code>  
<a name="new_Sharp_new"></a>

### new
> new Sharp([input], [options])

构造函数工厂，用于创建 `sharp` 的实例，后续方法可以链式调用。

JPEG、PNG、WebP、GIF、AVIF 或 TIFF 格式的图像数据可以从此对象流式输出。  
当使用基于流的输出时，可以从 `info` 事件中获取派生属性。

在处理过程中遇到的非关键性问题将作为 `warning` 事件发出。

实现了 [stream.Duplex](http://nodejs.org/api/stream.html#stream_class_stream_duplex) 类。

当加载动画图像的多个页面/帧时，这些页面将合并为一个垂直堆叠的“卫生纸”图像，其中整体高度是 `pageHeight` 乘以 `pages` 的数量。

**抛出**:

- <code>Error</code> 无效参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [input] | <code>Buffer</code> \| <code>ArrayBuffer</code> \| <code>Uint8Array</code> \| <code>Uint8ClampedArray</code> \| <code>Int8Array</code> \| <code>Uint16Array</code> \| <code>Int16Array</code> \| <code>Uint32Array</code> \| <code>Int32Array</code> \| <code>Float32Array</code> \| <code>Float64Array</code> \| <code>string</code> |  | 如果出现，可以是一个包含 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像数据的 Buffer / ArrayBuffer / Uint8Array / Uint8ClampedArray，或一个包含原始像素图像数据的 TypedArray，或一个包含 JPEG、PNG、WebP、AVIF、GIF、SVG 或 TIFF 图像文件的文件系统路径的字符串。当不存在时，可以将 JPEG、PNG、WebP、AVIF、GIF、SVG、TIFF 或原始像素图像数据流式输入到对象中。 |
| [options] | <code>Object</code> |  | 如果出现，则为一个具有可选属性的对象。 |
| [options.failOn] | <code>string</code> | <code>&quot;&#x27;warning&#x27;&quot;</code> | 何时中止无效像素数据的处理，选其中之一（按敏感性顺序，从低到高）: 'none'，'truncated'，'error'，'warning'。更高的级别意味着较低的级别。无效的元数据将始终中止。 |
| [options.limitInputPixels] | <code>number</code> \| <code>boolean</code> | <code>268402689</code> | 不处理像素数量（宽度 x 高度）超过此限制的输入图像。假设输入元数据中包含的图像维度可以被信任。有效像素数量，零或false以移除限制，true使用默认限制267402689（0x3FFF x 0x3FFF）。 |
| [options.unlimited] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以移除帮助防止内存耗尽的安全功能（JPEG、PNG、SVG、HEIF）。 |
| [options.sequentialRead] | <code>boolean</code> | <code>true</code> | 设置为 `false` 以使用随机访问而不是顺序读取。一些操作会自动执行此操作。 |
| [options.density] | <code>number</code> | <code>72</code> | 一个表示矢量图像 DPI 的数字，范围为 1 到 100000。 |
| [options.ignoreIcc] | <code>number</code> | <code>false</code> | 是否应忽略嵌入的 ICC 配置文件（如果有）。 |
| [options.pages] | <code>number</code> | <code>1</code> | 要提取的多页输入的页数（GIF、WebP、TIFF），使用 -1 提取所有页面。 |
| [options.page] | <code>number</code> | <code>0</code> | 从多页输入中提取的起始页码（GIF、WebP、TIFF），基于零。 |
| [options.subifd] | <code>number</code> | <code>-1</code> | 要提取的 OME-TIFF 的 subIFD（子图像文件目录），默认为主图像。 |
| [options.level] | <code>number</code> | <code>0</code> | 从多级输入（OpenSlide）中提取的级别，基于零。 |
| [options.pdfBackground] | <code>string</code> \| <code>Object</code> |  | 当 PDF 部分透明时使用的背景颜色。由 [color](https://www.npmjs.org/package/color) 模块解析，以提取红色、绿色、蓝色和 alpha 的值。需要使用全局安装的 libvips，并编译时支持 PDFium、Poppler、ImageMagick 或 GraphicsMagick。 |
| [options.animated] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以读取动画图像的所有帧/页（GIF、WebP、TIFF），相当于将 `pages` 设置为 `-1`。 |
| [options.raw] | <code>Object</code> |  | 描述要创建的原始像素输入图像数据。有关像素排序，请参见 `raw()`。 |
| [options.raw.width] | <code>number</code> |  | 整数像素宽度。 |
| [options.raw.height] | <code>number</code> |  | 整数像素高度。 |
| [options.raw.channels] | <code>number</code> |  | 整数通道数，介于 1 和 4 之间。 |
| [options.raw.premultiplied] | <code>boolean</code> |  | 指定原始输入已经过预乘，设置为 `true` 以避免在图像中进行锐化预乘。（可选，默认 `false`） |
| [options.create] | <code>Object</code> |  | 描述要创建的新图像。 |
| [options.create.width] | <code>number</code> |  | 整数像素宽度。 |
| [options.create.height] | <code>number</code> |  | 整数像素高度。 |
| [options.create.channels] | <code>number</code> |  | 整数通道数，可以是 3（RGB）或 4（RGBA）。 |
| [options.create.background] | <code>string</code> \| <code>Object</code> |  | 由 [color](https://www.npmjs.org/package/color) 模块解析，以提取红色、绿色、蓝色和 alpha 的值。 |
| [options.create.noise] | <code>Object</code> |  | 描述要创建的噪声。 |
| [options.create.noise.type] | <code>string</code> |  | 生成噪声的类型，目前仅支持 `gaussian`。 |
| [options.create.noise.mean] | <code>number</code> |  | 生成噪声中像素的均值。 |
| [options.create.noise.sigma] | <code>number</code> |  | 生成噪声中像素的标准偏差。 |
| [options.text] | <code>Object</code> |  | 描述要创建的新文本图像。 |
| [options.text.text] | <code>string</code> |  | 作为 UTF-8 字符串呈现的文本。可以包含 Pango 标记，例如 `<i>Le</i>Monde`。 |
| [options.text.font] | <code>string</code> |  | 用于渲染的字体名称。 |
| [options.text.fontfile] | <code>string</code> |  | 可以供 `font` 使用的字体文件的绝对文件系统路径。 |
| [options.text.width] | <code>number</code> | <code>0</code> | 文本换行的整数像素数。超过此宽度的文本行将在单词边界处断开。 |
| [options.text.height] | <code>number</code> | <code>0</code> | 最大整数像素高度。当定义时，将忽略 `dpi`，文本将自动适合由 `width` 和 `height` 定义的像素分辨率。如果未指定 `width` 或设置为 0，则将被忽略。 |
| [options.text.align] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 多行文本的对齐风格（`'left'`，`'centre'`，`'center'`，`'right'`）。 |
| [options.text.justify] | <code>boolean</code> | <code>false</code> | 设置为 true 以对文本应用对齐。 |
| [options.text.dpi] | <code>number</code> | <code>72</code> | 呈现文本时的分辨率（大小）。如果指定了 `height` 则不生效。 |
| [options.text.rgba] | <code>boolean</code> | <code>false</code> | 设置为 true 以启用 RGBA 输出。对于颜色 emoji 渲染或支持 Pango 标记特性，如 `<span foreground="red">Red!</span>`，这非常有用。 |
| [options.text.spacing] | <code>number</code> | <code>0</code> | 文本行高（以点为单位）。如果未指定，将使用字体的行高。 |
| [options.text.wrap] | <code>string</code> | <code>&quot;&#x27;word&#x27;&quot;</code> | 提供宽度时的单词换行样式，之一为：'word'，'char'，'word-char'（优先选择单词，退回到字符）或 'none'。 |

**示例**  
```js
sharp('input.jpg')
  .resize(300, 200)
  .toFile('output.jpg', function(err) {
    // output.jpg 是一张宽 300 像素、高 200 像素的图像
    // 包含 input.jpg 的缩放和裁剪版本
  });
```
**示例**  
```js
// 从远程 URL 读取图像数据，
// 缩放到宽 300 像素，
// 发出一个 'info' 事件，包含计算后的尺寸，
// 最后将图像数据写入 writableStream
const { body } = fetch('https://...');
const readableStream = Readable.fromWeb(body);
const transformer = sharp()
  .resize(300)
  .on('info', ({ height }) => {
    console.log(`图像高度为 ${height}`);
  });
readableStream.pipe(transformer).pipe(writableStream);
```
**示例**  
```js
// 创建一张空白的 300x200 PNG 图像，像素为半透明红色
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
// 生成 RGB 高斯噪声
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
// 使用 Pango 标记和字体从文本生成 RGBA 图像
await sharp({
  text: {
    text: '<span foreground="red">Red!</span><span background="cyan">blue</span>',
    font: 'sans',
    rgba: true,
    dpi: 300
  }
}).toFile('text_rgba.png');
```

## clone
> clone() ⇒ [<code>Sharp</code>](#Sharp)

对 Sharp 实例进行“快照”，返回一个新实例。  
克隆的实例继承其父实例的输入。  
这允许多个输出流，因此多个处理管道可以共享单个输入流。

**示例**  
```js
const pipeline = sharp().rotate();
pipeline.clone().resize(800, 600).pipe(firstWritableStream);
pipeline.clone().extract({ left: 20, top: 20, width: 100, height: 100 }).pipe(secondWritableStream);
readableStream.pipe(pipeline);
// firstWritableStream 接收自动旋转、调整大小的 readableStream
// secondWritableStream 接收自动旋转、提取区域的 readableStream
```
**示例**  
```js
// 创建一个管道，将下载图像、调整大小并将其格式化为不同文件
// 使用 Promise 确定管道何时完成
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
    console.error("处理文件时出错，让我们清理一下", err);
    try {
      fs.unlinkSync("originalFile.jpg");
      fs.unlinkSync("optimized-500.jpg");
      fs.unlinkSync("optimized-500.webp");
    } catch (e) {}
  });
```