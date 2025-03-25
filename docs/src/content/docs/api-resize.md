---
# 该文件是从 lib/resize.js 中的 JSDoc 自动生成的
title: 调整图像大小
---

## resize
> resize([width], [height], [options]) ⇒ <code>Sharp</code>

将图像调整为 `width`、`height` 或 `width x height`。

当同时提供 `width` 和 `height` 时，符合这些尺寸的图像应当**适配**的可能方法有：
- `cover`：（默认）保持宽高比，尽量确保图像覆盖提供的两个尺寸，通过裁剪/剪切以适应。
- `contain`：保持宽高比，在必要时使用“宽屏效果”使图像包含在提供的两个尺寸内。
- `fill`：忽略输入的宽高比，拉伸到提供的两个尺寸。
- `inside`：保持宽高比，调整图像，使其尽可能大，同时确保其尺寸不大于指定的尺寸。
- `outside`：保持宽高比，调整图像，使其尽可能小，同时确保其尺寸不小于指定的尺寸。

这些值中的一些基于 [object-fit](https://developer.mozilla.org/en-US/docs/Web/CSS/object-fit) CSS 属性。

<img alt="调整大小时适配属性的各种值示例" width="100%" style="aspect-ratio: 998/243" src="https://cdn.jsdelivr.net/gh/lovell/sharp@main/docs/image/api-resize-fit.svg">

使用 **fit** 为 `cover` 或 `contain` 时，默认 **position** 为 `centre`。其他选项有：
- `sharp.position`：`top`、`right top`、`right`、`right bottom`、`bottom`、`left bottom`、`left`、`left top`。
- `sharp.gravity`：`north`、`northeast`、`east`、`southeast`、`south`、`southwest`、`west`、`northwest`、`center` 或 `centre`。
- `sharp.strategy`：仅限 `cover`，使用 `entropy` 或 `attention` 策略动态裁剪。

这些值中的一些基于 [object-position](https://developer.mozilla.org/en-US/docs/Web/CSS/object-position) CSS 属性。

基于策略的方法最初将图像调整为一维达到目标长度，然后重复排名边缘区域，丢弃得分最低的边缘，基于所选策略。
- `entropy`：关注具有最高 [香农熵](https://en.wikipedia.org/wiki/Entropy_%28information_theory%29) 的区域。
- `attention`：关注具有最高亮度频率、颜色饱和度和肤色存在的区域。

可能的下采样内核有：
- `nearest`：使用 [最近邻插值](http://en.wikipedia.org/wiki/Nearest-neighbor_interpolation)。
- `linear`：使用 [三角滤波器](https://en.wikipedia.org/wiki/Triangular_function)。
- `cubic`：使用 [Catmull-Rom 样条](https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline)。
- `mitchell`：使用 [Mitchell-Netravali 样条](https://www.cs.utexas.edu/~fussell/courses/cs384g-fall2013/lectures/mitchell/Mitchell.pdf)。
- `lanczos2`：使用 `a=2` 的 [Lanczos 内核](https://en.wikipedia.org/wiki/Lanczos_resampling#Lanczos_kernel)。
- `lanczos3`：使用默认的 `a=3` 的 Lanczos 内核。

上采样时，这些内核映射到 `nearest`、`linear` 和 `cubic` 插值器。
没有匹配的上采样插值器的下采样内核映射为 `cubic`。

每个管道只能进行一次调整大小。
在同一管道中之前对 `resize` 的调用将被忽略。


**抛出**：

- <code>Error</code> 无效的参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [width] | <code>number</code> |  | 生成图像的宽度（像素数）。使用 `null` 或 `undefined` 自动缩放宽度以匹配高度。 |
| [height] | <code>number</code> |  | 生成图像的高度（像素数）。使用 `null` 或 `undefined` 自动缩放高度以匹配宽度。 |
| [options] | <code>Object</code> |  |  |
| [options.width] | <code>number</code> |  | 指定 `width` 的另一种方式。如果两者都存在，这个优先。 |
| [options.height] | <code>number</code> |  | 指定 `height` 的另一种方式。如果两者都存在，这个优先。 |
| [options.fit] | <code>String</code> | <code>&#x27;cover&#x27;</code> | 图像应如何调整大小/裁剪以适应目标尺寸，可以是 `cover`、`contain`、`fill`、`inside` 或 `outside`。 |
| [options.position] | <code>String</code> | <code>&#x27;centre&#x27;</code> | 当 `fit` 为 `cover` 或 `contain` 时使用的位置、重力或策略。 |
| [options.background] | <code>String</code> \| <code>Object</code> | <code>{r: 0, g: 0, b: 0, alpha: 1}</code> | 当 `fit` 为 `contain` 时的背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为不透明的黑色。 |
| [options.kernel] | <code>String</code> | <code>&#x27;lanczos3&#x27;</code> | 用于图像缩减的内核和用于上采样的推断插值器。使用 `fastShrinkOnLoad` 选项控制内核和加载时缩小的关系。 |
| [options.withoutEnlargement] | <code>Boolean</code> | <code>false</code> | 如果宽度 *或* 高度已经小于目标尺寸，则不进行放大，相当于 GraphicsMagick 的 `>` 几何选项。这可能导致输出尺寸小于目标尺寸。 |
| [options.withoutReduction] | <code>Boolean</code> | <code>false</code> | 如果宽度 *或* 高度已经大于目标尺寸，则不进行缩小，相当于 GraphicsMagick 的 `<` 几何选项。这仍可能导致裁剪以达到目标尺寸。 |
| [options.fastShrinkOnLoad] | <code>Boolean</code> | <code>true</code> | 更充分利用 JPEG 和 WebP 的加载时缩小特性，这可能导致轻微的摩尔图案或自动缩放尺寸的四舍五入。 |

**示例**  
```js
sharp(input)
  .resize({ width: 100 })
  .toBuffer()
  .then(data => {
    // 100 像素宽，自动缩放高度
  });
```
**示例**  
```js
sharp(input)
  .resize({ height: 100 })
  .toBuffer()
  .then(data => {
    // 100 像素高，自动缩放宽度
  });
```
**示例**  
```js
sharp(input)
  .resize(200, 300, {
    kernel: sharp.kernel.nearest,
    fit: 'contain',
    position: 'right top',
    background: { r: 255, g: 255, b: 255, alpha: 0.5 }
  })
  .toFile('output.png')
  .then(() => {
    // output.png 是一幅宽 200 像素、高 300 像素的图像
    // 包含了最近邻缩放的版本
    // 被包裹在半透明白色画布的东北角
  });
```
**示例**  
```js
const transformer = sharp()
  .resize({
    width: 200,
    height: 200,
    fit: sharp.fit.cover,
    position: sharp.strategy.entropy
  });
// 从 readableStream 读取图像数据
// 将 200px 正方形的自动裁剪图像数据写入 writableStream
readableStream
  .pipe(transformer)
  .pipe(writableStream);
```
**示例**  
```js
sharp(input)
  .resize(200, 200, {
    fit: sharp.fit.inside,
    withoutEnlargement: true
  })
  .toFormat('jpeg')
  .toBuffer()
  .then(function(outputBuffer) {
    // outputBuffer 包含 JPEG 图像数据
    // 宽度和高度均不超过 200 像素
    // 不大于输入图像
  });
```
**示例**  
```js
sharp(input)
  .resize(200, 200, {
    fit: sharp.fit.outside,
    withoutReduction: true
  })
  .toFormat('jpeg')
  .toBuffer()
  .then(function(outputBuffer) {
    // outputBuffer 包含 JPEG 图像数据
    // 至少 200 像素宽和 200 像素高，同时保持宽高比
    // 不小于输入图像
  });
```
**示例**  
```js
const scaleByHalf = await sharp(input)
  .metadata()
  .then(({ width }) => sharp(input)
    .resize(Math.round(width * 0.5))
    .toBuffer()
  );
```


## extend
> extend(extend) ⇒ <code>Sharp</code>

通过提供的背景颜色或从图像衍生的像素扩展/填充/突出图像的一个或多个边缘。
此操作总是在调整大小和提取后发生（如果有）。

**抛出**：

- <code>Error</code> 无效的参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| extend | <code>number</code> \| <code>Object</code> |  | 要添加到所有边缘的单个像素数，或包含每个边缘计数的对象 |
| [extend.top] | <code>number</code> | <code>0</code> |  |
| [extend.left] | <code>number</code> | <code>0</code> |  |
| [extend.bottom] | <code>number</code> | <code>0</code> |  |
| [extend.right] | <code>number</code> | <code>0</code> |  |
| [extend.extendWith] | <code>String</code> | <code>&#x27;background&#x27;</code> | 使用此方法填充新像素，可以是：background、copy、repeat、mirror。 |
| [extend.background] | <code>String</code> \| <code>Object</code> | <code>{r: 0, g: 0, b: 0, alpha: 1}</code> | 背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为不透明的黑色。 |

**示例**  
```js
// 调整为 140 像素宽，然后在顶部、左侧和右边添加 10 个透明像素，在底部边缘添加 20 个
sharp(input)
  .resize(140)
  .extend({
    top: 10,
    bottom: 20,
    left: 10,
    right: 10,
    background: { r: 0, g: 0, b: 0, alpha: 0 }
  })
  ...
```
**示例**  
```js
// 在底部添加一排 10 个红色像素
sharp(input)
  .extend({
    bottom: 10,
    background: 'red'
  })
  ...
```
**示例**  
```js
// 向右突出 8 像素，镜像现有的右边缘
sharp(input)
  .extend({
    right: 8,
    background: 'mirror'
  })
  ...
```


## extract
> extract(options) ⇒ <code>Sharp</code>

提取/裁剪图像的区域。

- 在调整大小之前使用 `extract` 进行预裁剪。
- 在调整大小之后使用 `extract` 进行后裁剪。
- 使用 `extract` 两次并使用 `resize` 一次来实现提取-然后调整大小-再提取的固定操作顺序。

**抛出**：

- <code>Error</code> 无效的参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> | 描述使用整数像素值提取的区域 |
| options.left | <code>number</code> | 从左边缘的零索引偏移 |
| options.top | <code>number</code> | 从顶部边缘的零索引偏移 |
| options.width | <code>number</code> | 要提取的区域宽度 |
| options.height | <code>number</code> | 要提取的区域高度 |

**示例**  
```js
sharp(input)
  .extract({ left: left, top: top, width: width, height: height })
  .toFile(output, function(err) {
    // 从输入图像中提取区域，保存为相同格式。
  });
```
**示例**  
```js
sharp(input)
  .extract({ left: leftOffsetPre, top: topOffsetPre, width: widthPre, height: heightPre })
  .resize(width, height)
  .extract({ left: leftOffsetPost, top: topOffsetPost, width: widthPost, height: heightPost })
  .toFile(output, function(err) {
    // 提取区域、调整大小，然后从调整后的图像中提取
  });
```


## trim
> trim([options]) ⇒ <code>Sharp</code>

修剪所有边缘上与给定背景颜色相似的像素，默认背景颜色为左上角像素的颜色。

具有 alpha 通道的图像将使用 alpha 和非 alpha 通道的组合边界框。

如果该操作的结果会将图像修剪为无内容，则不进行更改。

`info` 响应对象将包含 `trimOffsetLeft` 和 `trimOffsetTop` 属性。

**抛出**：

- <code>Error</code> 无效的参数


| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.background] | <code>string</code> \| <code>Object</code> | <code>&quot;&#x27;左上角像素&#x27;&quot;</code> | 背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为左上角像素的颜色。 |
| [options.threshold] | <code>number</code> | <code>10</code> | 允许的颜色差异，正数。 |
| [options.lineArt] | <code>boolean</code> | <code>false</code> | 输入更像线条艺术（例如矢量）而不是摄影吗？ |

**示例**  
```js
// 修剪与左上角像素颜色相似的像素。
await sharp(input)
  .trim()
  .toFile(output);
```
**示例**  
```js
// 仅修剪与左上角像素颜色完全相同的像素。
await sharp(input)
  .trim({
    threshold: 0
  })
  .toFile(output);
```
**示例**  
```js
// 假设输入是线条艺术，仅修剪与红色相似的像素。
const output = await sharp(input)
  .trim({
    background: "#FF0000",
    lineArt: true
  })
  .toBuffer();
```
**示例**  
```js
// 修剪所有“黄色的”像素，在更高的阈值下更宽容。
const output = await sharp(input)
  .trim({
    background: "yellow",
    threshold: 42,
  })
  .toBuffer();
```