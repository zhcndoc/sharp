## resize
> resize([width], [height], [options]) ⇒ <code>Sharp</code>

将图像调整为 `width`、`height` 或 `width x height`。

当同时提供 `width` 和 `height` 时，图像应该如何 **适应** 这两个尺寸的方法有：
- `cover`: （默认）保持纵横比，尝试确保图像覆盖提供的两个尺寸，通过裁剪/剪切以适应。
- `contain`: 保持纵横比，在必要时使用“信箱式”（letterboxing）确保图像包含在提供的两个尺寸内。
- `fill`: 忽略输入的纵横比，拉伸填充到提供的两个尺寸。
- `inside`: 保持纵横比，调整图像大小，使其尽可能大，同时确保尺寸小于或等于指定的两个尺寸。
- `outside`: 保持纵横比，调整图像大小，使其尽可能小，同时确保尺寸大于或等于指定的两个尺寸。

其中一些值基于 [object-fit](https://developer.mozilla.org/en-US/docs/Web/CSS/object-fit) CSS 属性。

<img alt="调整大小时适配属性的各种值示例" width="100%" style="aspect-ratio: 998/243" src="https://cdn.jsdelivr.net/gh/lovell/sharp@main/docs/image/api-resize-fit.svg">

使用 **fit** 为 `cover` 或 `contain` 时，默认 **position** 为 `centre`。其他选项包括：
- `sharp.position`: `top`, `right top`, `right`, `right bottom`, `bottom`, `left bottom`, `left`, `left top`。
- `sharp.gravity`: `north`, `northeast`, `east`, `southeast`, `south`, `southwest`, `west`, `northwest`, `center` 或 `centre`。
- `sharp.strategy`: 仅 `cover`，使用 `entropy` 或 `attention` 策略动态裁剪。

其中一些值基于 [object-position](https://developer.mozilla.org/en-US/docs/Web/CSS/object-position) CSS 属性。

基于策略的方法首先调整大小，使一个维度达到目标长度，然后反复对边缘区域进行评分，丢弃基于所选策略的最低评分边缘。
- `entropy`: 专注于具有最高 [香农熵](https://en.wikipedia.org/wiki/Entropy_%28information_theory%29) 的区域。
- `attention`: 专注于具有最高亮度频率、颜色饱和度和皮肤色调存在的区域。

可能的降采样内核包括：
- `nearest`: 使用 [最近邻插值](http://en.wikipedia.org/wiki/Nearest-neighbor_interpolation)。
- `linear`: 使用 [三角滤波器](https://en.wikipedia.org/wiki/Triangular_function)。
- `cubic`: 使用 [Catmull-Rom 样条](https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline)。
- `mitchell`: 使用 [Mitchell-Netravali 样条](https://www.cs.utexas.edu/~fussell/courses/cs384g-fall2013/lectures/mitchell/Mitchell.pdf)。
- `lanczos2`: 使用 `a=2` 的 [Lanczos 核](https://en.wikipedia.org/wiki/Lanczos_resampling#Lanczos_kernel)。
- `lanczos3`: 使用 `a=3` 的 Lanczos 核（默认）。

在上采样时，这些内核映射到 `nearest`、`linear` 和 `cubic` 插值器。
没有匹配上采样插值器的降采样内核映射到 `cubic`。

每个管道只能进行一次调整大小。
在同一管道中之前的 `resize` 调用将被忽略。

**抛出**：

- <code>Error</code> 无效参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [width] | <code>number</code> |  | 结果图像的宽度，单位为像素。使用 `null` 或 `undefined` 自动缩放宽度以匹配高度。 |
| [height] | <code>number</code> |  | 结果图像的高度，单位为像素。使用 `null` 或 `undefined` 自动缩放高度以匹配宽度。 |
| [options] | <code>Object</code> |  |  |
| [options.width] | <code>number</code> |  | 指定 `width` 的另一种方法。如果同时存在，优先采用此值。 |
| [options.height] | <code>number</code> |  | 指定 `height` 的另一种方法。如果同时存在，优先采用此值。 |
| [options.fit] | <code>String</code> | <code>&#x27;cover&#x27;</code> | 图像应该如何调整大小/裁剪以适应目标尺寸，取值为 `cover`、`contain`、`fill`、`inside` 或 `outside`。 |
| [options.position] | <code>String</code> | <code>&#x27;centre&#x27;</code> | 在 `fit` 为 `cover` 或 `contain` 时使用的位置、重力或策略。 |
| [options.background] | <code>String</code> \| <code>Object</code> | <code>{r: 0, g: 0, b: 0, alpha: 1}</code> | 当 `fit` 为 `contain` 时的背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为不透明的黑色。 |
| [options.kernel] | <code>String</code> | <code>&#x27;lanczos3&#x27;</code> | 用于图像缩减的内核以及用于上采样的推导插值器。使用 `fastShrinkOnLoad` 选项来控制内核与加载时缩小的选择。 |
| [options.withoutEnlargement] | <code>Boolean</code> | <code>false</code> | 如果宽度 *或* 高度已经小于目标尺寸，则不进行放大，相当于 GraphicsMagick 的 `>` 几何选项。这可能导致输出尺寸小于目标尺寸。 |
| [options.withoutReduction] | <code>Boolean</code> | <code>false</code> | 如果宽度 *或* 高度已经大于目标尺寸，则不进行缩小，相当于 GraphicsMagick 的 `<` 几何选项。这仍可能导致裁剪以达到目标尺寸。 |
| [options.fastShrinkOnLoad] | <code>Boolean</code> | <code>true</code> | 更好地利用 JPEG 和 WebP 加载时缩小的特性，这可能导致轻微的摩尔纹或自动缩放尺寸的四舍五入。 |

**示例**  
```js
sharp(input)
  .resize({ width: 100 })
  .toBuffer()
  .then(data => {
    // 宽度为 100 像素，高度自动缩放
  });
```
**示例**  
```js
sharp(input)
  .resize({ height: 100 })
  .toBuffer()
  .then(data => {
    // 高度为 100 像素，宽度自动缩放
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
    // output.png 是一个宽 200 像素，高 300 像素的图像
    // 包含一个最近邻缩放版本
    // 被包含在一个半透明白色画布的东北角
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
// 从可读流中读取图像数据
// 将 200px 方形自动裁剪的图像数据写入可写流
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
    // 且不大于输入图像
  });
```
**示例**  
```js
sharp(input)
  .resize(200, 200, {
