## rotate
> rotate([angle], [options]) ⇒ <code>Sharp</code>

通过显式角度或根据 EXIF `Orientation` 标签自动旋转输出图像。

如果提供了角度，它会被转换为有效的正度数旋转。
例如， `-450` 将产生 270 度的旋转。

当旋转的角度不是 90 的倍数时，可以使用 `background` 选项提供背景颜色。

如果没有提供角度，则会根据 EXIF 数据确定。
支持镜像并可能推测使用翻转操作。

使用 `rotate` 而不指定角度会删除 EXIF `Orientation` 标签（如果存在）。

每个管道仅能进行一次旋转。
在相同管道中的前一个 `rotate` 调用将被忽略。

多页图像只能旋转 180 度。

在旋转、调整大小和/或提取区域时，方法的顺序很重要，
例如 `.rotate(x).extract(y)` 将与 `.extract(y).rotate(x)` 产生不同的结果。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [angle] | <code>number</code> | <code>auto</code> | 旋转角度。 |
| [options] | <code>Object</code> |  | 如果存在，则为具有可选属性的 Object。 |
| [options.background] | <code>string</code> \| <code>Object</code> | <code>&quot;\&quot;#000000\&quot;&quot;</code> | 使用 [color](https://www.npmjs.org/package/color) 模块解析以提取红色、绿色、蓝色和 alpha 的值。 |

**示例**  
```js
const pipeline = sharp()
  .rotate()
  .resize(null, 200)
  .toBuffer(function (err, outputBuffer, info) {
    // outputBuffer 包含 200px 高的 JPEG 图像数据，
    // 使用 EXIF Orientation 标签进行自动旋转
    // info.width 和 info.height 包含调整大小后的图像的维度
  });
readableStream.pipe(pipeline);
```
**示例**  
```js
const rotateThenResize = await sharp(input)
  .rotate(90)
  .resize({ width: 16, height: 8, fit: 'fill' })
  .toBuffer();
const resizeThenRotate = await sharp(input)
  .resize({ width: 16, height: 8, fit: 'fill' })
  .rotate(90)
  .toBuffer();
```

## flip
> flip([flip]) ⇒ <code>Sharp</code>

沿 x 轴垂直镜像图像（上下）。  
如果存在任何旋转，始终在旋转之前执行此操作。

此操作对多页图像不正确。

| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [flip] | <code>Boolean</code> | <code>true</code> | 

**示例**  
```js
const output = await sharp(input).flip().toBuffer();
```

## flop
> flop([flop]) ⇒ <code>Sharp</code>

沿 y 轴水平镜像图像（左右）。  
如果存在任何旋转，始终在旋转之前执行此操作。

| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [flop] | <code>Boolean</code> | <code>true</code> | 

**示例**  
```js
const output = await sharp(input).flop().toBuffer();
```

## affine
> affine(matrix, [options]) ⇒ <code>Sharp</code>

对图像执行仿射变换。 此操作将始终在调整大小、提取和旋转之后执行（如果存在）。

您必须提供一个长度为 4 的数组或一个 2x2 的仿射变换矩阵。  
默认情况下，新像素用黑色背景填充。您可以使用 `background` 选项提供背景颜色。  
也可以指定特定的插值器。将 `interpolator` 选项设置为 `sharp.interpolators` 对象的属性，例如 `sharp.interpolators.nohalo`。

在 2x2 矩阵的情况下，变换如下：
- X = `matrix[0, 0]` \* (x + `idx`) + `matrix[0, 1]` \* (y + `idy`) + `odx`
- Y = `matrix[1, 0]` \* (x + `idx`) + `matrix[1, 1]` \* (y + `idy`) + `ody`

其中：
- x 和 y 是输入图像中的坐标。
- X 和 Y 是输出图像中的坐标。
- (0,0) 是左上角。

**抛出**：

- <code>Error</code> 无效的参数

**自**：0.27.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| matrix | <code>Array.&lt;Array.&lt;number&gt;&gt;</code> \| <code>Array.&lt;number&gt;</code> |  | 仿射变换矩阵 |
| [options] | <code>Object</code> |  | 如果存在，则为具有可选属性的 Object。 |
| [options.background] | <code>String</code> \| <code>Object</code> | <code>&quot;#000000&quot;</code> | 使用 [color](https://www.npmjs.org/package/color) 模块解析以提取红色、绿色、蓝色和 alpha 的值。 |
| [options.idx] | <code>Number</code> | <code>0</code> | 输入水平偏移量 |
| [options.idy] | <code>Number</code> | <code>0</code> | 输入垂直偏移量 |
| [options.odx] | <code>Number</code> | <code>0</code> | 输出水平偏移量 |
| [options.ody] | <code>Number</code> | <code>0</code> | 输出垂直偏移量 |
| [options.interpolator] | <code>String</code> | <code>sharp.interpolators.bicubic</code> | 插值器 |

**示例**  
```js
const pipeline = sharp()
  .affine([[1, 0.3], [0.1, 0.7]], {
     background: 'white',
     interpolator: sharp.interpolators.nohalo
  })
  .toBuffer((err, outputBuffer, info) => {
     // outputBuffer 包含变换后的图像
     // info.width 和 info.height 包含新维度
  });

inputStream
  .pipe(pipeline);
```

## sharpen
> sharpen([options], [flat], [jagged]) ⇒ <code>Sharp</code>

锐化图像。

在没有参数的情况下，执行快速、温和的输出图像锐化。

当提供 `sigma` 时，在 LAB 色彩空间中对 L 通道执行更慢、更准确的锐化。  
可以对“平坦”（m1）和“锯齿状”（m2）区域的锐化级别进行细致控制。

请参阅 [libvips sharpen](https://www.libvips.org/API/current/libvips-convolution.html#vips-sharpen) 操作。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> \| <code>number</code> |  | 如果存在，则为具有属性的 Object |
| [options.sigma] | <code>number</code> |  | 高斯掩模的 sigma，其中 `sigma = 1 + radius / 2`，范围在 0.000001 到 10 之间 |
| [options.m1] | <code>number</code> | <code>1.0</code> | 应用到“平坦”区域的锐化级别，范围在 0 到 1000000 之间 |
| [options.m2] | <code>number</code> | <code>2.0</code> | 应用到“锯齿状”区域的锐化级别，范围在 0 到 1000000 之间 |
| [options.x1] | <code>number</code> | <code>2.0</code> | “平坦”和“锯齿状”之间的阈值，范围在 0 到 1000000 之间 |
| [options.y2] | <code>number</code> | <code>10.0</code> | 最大的亮度增加量，范围在 0 到 1000000 之间 |
| [options.y3] | <code>number</code> | <code>20.0</code> | 最大的暗度减少量，范围在 0 到 1000000 之间 |
| [flat] | <code>number</code> |  | (已弃用) 请参阅 `options.m1`。 |
| [jagged] | <code>number</code> |  | (已弃用) 请参阅 `options.m2`。 |

**示例**  
```js
const data = await sharp(input).sharpen().toBuffer();
```
**示例**  
```js
const data = await sharp(input).sharpen({ sigma: 2 }).toBuffer();
```
**示例**  
```js
const data = await sharp(input)
  .sharpen({
    sigma: 2,
    m1: 0,
    m2: 3,
    x1: 3,
    y2: 15,
    y3: 15,
  })
  .toBuffer();
```

## median
> median([size]) ⇒ <code>Sharp</code>

应用中值滤波器。  
在没有参数的情况下，默认窗口为 3x3。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [size] | <code>number</code> | <code>3</code> | 平方掩模大小：size x size |

**示例**  
```js
const output = await sharp(input).median().toBuffer();
```
**示例**  
```js
const output = await sharp(input).median(5).toBuffer();
```

## blur
> blur([options]) ⇒ <code>Sharp</code>

模糊图像。

在没有参数的情况下，执行快速的 3x3 方框模糊（相当于方框线性滤波器）。

当提供 `sigma` 时，执行更慢、更准确的高斯模糊。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> \| <code>number</code> \| <code>Boolean</code> |  |  |
| [options.sigma] | <code>number</code> |  | 一个范围在 0.3 到 1000 之间的值，代表高斯掩模的 sigma，其中 `sigma = 1 + radius / 2`。 |
| [options.precision] | <code>string</code> | <code>&quot;&#x27;integer&#x27;&quot;</code> | 操作的准确程度，选项为：integer、float、approximate。 |
| [options.minAmplitude] | <code>number</code> | <code>0.2</code> | 在 0.001 到 1 之间的值。较小的值将生成更大、更准确的掩模。 |

**示例**  
```js
const boxBlurred = await sharp(input)
  .blur()
  .toBuffer();
```
**示例**  
```js
const gaussianBlurred = await sharp(input)
  .blur(5)
  .toBuffer();
```

## flatten
> flatten([options]) ⇒ <code>Sharp</code>

合并 alpha 透明度通道（如果存在），与背景合并，然后删除 alpha 通道。

另请参阅 [removeAlpha](/api-channel#removealpha)。

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.background] | <code>string</code> \| <code>Object</code> | <code>&quot;{r: 0, g: 0, b: 0}&quot;</code> | 背景颜色，由 [color](https://www.npmjs.org/package/color) 模块解析，默认为黑色。 |

**示例**  
```js
await sharp(rgbaInput)
  .flatten({ background: '#F0A703' })
  .toBuffer();
```

## unflatten
> unflatten()

确保图像具有 alpha 通道，其所有白色像素值变为完全透明。

非白色像素的现有 alpha 通道值保持不变。

此功能是实验性的，API 可能会发生变化。

**自**：0.32.1  
**示例**  
```js
await sharp(rgbInput)
  .unflatten()
  .toBuffer();
```
**示例**  
```js
await sharp(rgbInput)
  .threshold(128, { grayscale: false }) // 转换明亮像素为白色
  .unflatten()
  .toBuffer();
```

## gamma
> gamma([gamma], [gammaOut]) ⇒ <code>Sharp</code>

通过在缩放之前以 `1/gamma` 的因子降低编码（变暗），然后在缩放之后以 `gamma` 的因子增加编码（变亮）来应用 gamma 校正。  
这可以改善非线性色彩空间中调整大小图像的感知亮度。  
对 JPEG 和 WebP 输入图像应用 gamma 校正时，将无法利用加载时的缩小性能优化。

提供第二个参数以使用不同的输出 gamma 值，否则第一个值将在两种情况下使用。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [gamma] | <code>number</code> | <code>2.2</code> | 介于 1.0 到 3.0 之间的值。 |
| [gammaOut] | <code>number</code> |  | 介于 1.0 到 3.0 之间的值。 （可选，默认为与 `gamma` 相同） |

## negate
> negate([options]) ⇒ <code>Sharp</code>

生成图像的“负片”。

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.alpha] | <code>Boolean</code> | <code>true</code> | 是否对任何 alpha 通道进行反转 |

**示例**  
```js
const output = await sharp(input)
  .negate()
  .toBuffer();
```
**示例**  
```js
const output = await sharp(input)
  .negate({ alpha: false })
  .toBuffer();
```

## normalise
> normalise([options]) ⇒ <code>Sharp</code>

通过拉伸其亮度以覆盖整个动态范围来增强输出图像的对比度。

使用基于直方图的方法，默认范围为 1% 到 99%，以减少对极端噪声的敏感性。

低于 `lower` 百分位数的亮度值将通过截断为零而曝光不足。  
高于 `upper` 百分位数的亮度值将通过截断为最大像素值而曝光过度。

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.lower] | <code>number</code> | <code>1</code> | 低于此值的亮度值将曝光不足的百分位数。 |
| [options.upper] | <code>number</code> | <code>99</code> | 超过此值的亮度值将曝光过度的百分位数。 |

**示例**  
```js
const output = await sharp(input)
  .normalise()
  .toBuffer();
```
**示例**  
```js
const output = await sharp(input)
  .normalise({ lower: 0, upper: 100 })
  .toBuffer();
```

## normalize
> normalize([options]) ⇒ <code>Sharp</code>

normalise 的替代拼写。

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> |  |  |
| [options.lower] | <code>number</code> | <code>1</code> | 低于此值的亮度值将曝光不足的百分位数。 |
| [options.upper] | <code>number</code> | <code>99</code> | 超过此值的亮度值将曝光过度的百分位数。 |

**示例**  
```js
const output = await sharp(input)
  .normalize()
  .toBuffer();
```

## clahe
> clahe(options) ⇒ <code>Sharp</code>

执行对比度限制自适应直方图均衡
[CLAHE](https://en.wikipedia.org/wiki/Adaptive_histogram_equalization#Contrast_Limited_AHE)。

通常，这将通过突出较暗的细节来增强图像的清晰度。

**抛出**：

- <code>Error</code> 无效的参数

**自**：0.28.3  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| options | <code>Object</code> |  |  |
| options.width | <code>number</code> |  | 搜索窗口的宽度，单位为像素。 |
| options.height | <code>number</code> |  | 搜索窗口的高度，单位为像素。 |
| [options.maxSlope] | <code>number</code> | <code>3</code> | 明亮程度的积分水平，范围在 0 到 100 之间，0 将禁用对比度限制。 |

**示例**  
```js
const output = await sharp(input)
  .clahe({
    width: 3,
    height: 3,
  })
  .toBuffer();
```

## convolve
> convolve(kernel) ⇒ <code>Sharp</code>

使用指定的内核对图像进行卷积。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| kernel | <code>Object</code> |  |  |
| kernel.width | <code>number</code> |  | 内核的宽度（单位为像素）。 |
| kernel.height | <code>number</code> |  | 内核的高度（单位为像素）。 |
| kernel.kernel | <code>Array.&lt;number&gt;</code> |  | 长度为 `width*height` 的数组，包含内核值。 |
| [kernel.scale] | <code>number</code> | <code>sum</code> | 内核的缩放（单位为像素）。 |
| [kernel.offset] | <code>number</code> | <code>0</code> | 内核的偏移量（单位为像素）。 |

**示例**  
```js
sharp(input)
  .convolve({
    width: 3,
    height: 3,
    kernel: [-1, 0, 1, -2, 0, 2, -1, 0, 1]
  })
  .raw()
  .toBuffer(function(err, data, info) {
    // data 包含表示输入图像与水平 Sobel 操作的卷积的原始像素数据
  });
```

## threshold
> threshold([threshold], [options]) ⇒ <code>Sharp</code>

任何大于或等于阈值的像素值将被设置为 255，否则将被设置为 0。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [threshold] | <code>number</code> | <code>128</code> | 一个范围在 0-255 之间的值，表示将应用阈值的水平。 |
| [options] | <code>Object</code> |  |  |
| [options.greyscale] | <code>Boolean</code> | <code>true</code> | 转换为单通道灰度图。 |
| [options.grayscale] | <code>Boolean</code> | <code>true</code> | 灰度的另一种拼写方式。 |

## boolean
> boolean(operand, operator, [options]) ⇒ <code>Sharp</code>

与操作数图像执行按位布尔操作。

此操作创建一个输出图像，其中每个像素是输入图像对应像素之间所选按位布尔 `operation` 的结果。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| operand | <code>Buffer</code> \| <code>string</code> | 包含图像数据的缓冲区或包含图像文件路径的字符串。 |
| operator | <code>string</code> | 选择要执行的按位操作之一，`and`、`or` 或 `eor`，分别对应于 C 逻辑运算符 `&`、`|` 和 `^`。 |
| [options] | <code>Object</code> |  |
| [options.raw] | <code>Object</code> | 描述原操作数中的原始像素数据。 |
| [options.raw.width] | <code>number</code> |  |
| [options.raw.height] | <code>number</code> |  |
| [options.raw.channels] | <code>number</code> |  |

## linear
> linear([a], [b]) ⇒ <code>Sharp</code>

对图像应用线性公式 `a` * 输入 + `b` 来调整图像级别。

当提供一个单一数字时，它将用于所有图像通道。  
当提供一个数字数组时，数组的长度必须与通道数匹配。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [a] | <code>number</code> \| <code>Array.&lt;number&gt;</code> | <code>[]</code> | 乘数 |
| [b] | <code>number</code> \| <code>Array.&lt;number&gt;</code> | <code>[]</code> | 偏移量 |

**示例**  
```js
await sharp(input)
  .linear(0.5, 2)
  .toBuffer();
```
**示例**  
```js
await sharp(rgbInput)
  .linear(
    [0.25, 0.5, 0.75],
    [150, 100, 50]
  )
  .toBuffer();
```

## recomb
> recomb(inputMatrix) ⇒ <code>Sharp</code>

根据指定矩阵重新组合图像。

**抛出**：

- <code>Error</code> 无效的参数

**自**：0.21.1  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| inputMatrix | <code>Array.&lt;Array.&lt;number&gt;&gt;</code> | 3x3 或 4x4 重新组合矩阵 |

**示例**  
```js
sharp(input)
  .recomb([
   [0.3588, 0.7044, 0.1368],
   [0.2990, 0.5870, 0.1140],
   [0.2392, 0.4696, 0.0912],
  ])
  .raw()
  .toBuffer(function(err, data, info) {
    // data 包含应用矩阵后的原始像素数据
    // 使用该示例输入，已应用 sepia 滤镜
  });
```

## modulate
> modulate([options]) ⇒ <code>Sharp</code>

使用亮度、饱和度、色调旋转和亮度对图像进行转换。
亮度和亮度都在亮度上操作，区别在于亮度是乘法的而亮度是加法的。

**自**：0.22.1  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [options] | <code>Object</code> |  |
| [options.brightness] | <code>number</code> | 亮度乘数 |
| [options.saturation] | <code>number</code> | 饱和度乘数 |
| [options.hue] | <code>number</code> | 色调旋转的度数 |
| [options.lightness] | <code>number</code> | 亮度加数 |

**示例**  
```js
// 将亮度增加 2 倍
const output = await sharp(input)
  .modulate({
    brightness: 2
  })
  .toBuffer();
```
**示例**  
```js
// 将色调旋转 180 度
const output = await sharp(input)
  .modulate({
    hue: 180
  })
  .toBuffer();
```
**示例**  
```js
// 将亮度增加 +50
const output = await sharp(input)
  .modulate({
    lightness: 50
  })
  .toBuffer();
```
**示例**  
```js
// 同时降低亮度和饱和度并将色调旋转 90 度
const output = await sharp(input)
  .modulate({
    brightness: 0.5,
    saturation: 0.5,
    hue: 90,
  })
  .toBuffer();
```