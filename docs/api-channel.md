## removeAlpha
> removeAlpha() ⇒ <code>Sharp</code>

移除 alpha 通道（如果有的话）。如果图像没有 alpha 通道，则此操作无效。

另见 [flatten](/api-operation#flatten)。

**示例**  
```js
sharp('rgba.png')
  .removeAlpha()
  .toFile('rgb.png', function(err, info) {
    // rgb.png 是一个没有 alpha 通道的 3 通道图像
  });
```

## ensureAlpha
> ensureAlpha([alpha]) ⇒ <code>Sharp</code>

确保输出图像具有 alpha 透明通道。
如果缺失，添加的 alpha 通道将具有指定的透明级别，默认值为完全不透明（1）。
如果图像已经具有 alpha 通道，则此操作无效。

**抛出**：

- <code>Error</code> 无效的 alpha 透明级别

**自**: 0.21.2  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [alpha] | <code>number</code> | <code>1</code> | alpha 透明级别 (0=完全透明, 1=完全不透明) |

**示例**  
```js
// rgba.png 将是一个带有完全不透明 alpha 通道的 4 通道图像
await sharp('rgb.jpg')
  .ensureAlpha()
  .toFile('rgba.png')
```
**示例**  
```js
// rgba 是一个具有完全透明 alpha 通道的 4 通道图像
const rgba = await sharp(rgb)
  .ensureAlpha(0)
  .toBuffer();
```

## extractChannel
> extractChannel(channel) ⇒ <code>Sharp</code>

从多通道图像中提取单个通道。

**抛出**：

- <code>Error</code> 无效的通道

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| channel | <code>number</code> \| <code>string</code> | 要提取的零索引通道/波段编号，或 `red`、`green`、`blue` 或 `alpha`。 |

**示例**  
```js
// green.jpg 是一个包含输入绿色通道的灰度图像
await sharp(input)
  .extractChannel('green')
  .toFile('green.jpg');
```
**示例**  
```js
// red1 是第一个像素的红色值，red2 是第二个像素等。
const [red1, red2, ...] = await sharp(input)
  .extractChannel(0)
  .raw()
  .toBuffer();
```

## joinChannel
> joinChannel(images, options) ⇒ <code>Sharp</code>

将一个或多个通道合并到图像中。
添加的通道的意义取决于使用 `toColourspace()` 设置的输出颜色空间。
默认情况下，输出图像将是网络友好型的 sRGB，附加通道被解读为 alpha 通道。
通道顺序遵循 vips 约定：
- sRGB: 0: 红色，1: 绿色，2: 蓝色，3: Alpha。
- CMYK: 0: 品红，1: 青色，2: 黄色，3: 黑色，4: Alpha。

缓冲区可以是任何由 sharp 支持的图像格式。
对于原始像素输入，`options` 对象应包含一个 `raw` 属性，其格式与 `sharp()` 构造函数中同名属性的格式相同。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| images | <code>Array.&lt;(string\|Buffer)&gt;</code> \| <code>string</code> \| <code>Buffer</code> | 一个或多个图像（文件路径，缓冲区）。 |
| options | <code>Object</code> | 图像选项，见 `sharp()` 构造函数。 |

## bandbool
> bandbool(boolOp) ⇒ <code>Sharp</code>

对所有输入图像通道（波段）执行按位布尔操作，以生成单通道输出图像。

**抛出**：

- <code>Error</code> 无效的参数

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| boolOp | <code>string</code> | 其中一个 `and`、`or` 或 `eor`，以执行相应的按位操作，如 C 逻辑运算符 `&`、`|` 和 `^`。 |

**示例**  
```js
sharp('3-channel-rgb-input.png')
  .bandbool(sharp.bool.and)
  .toFile('1-channel-output.png', function (err, info) {
    // 输出将是一个单通道图像，其中每个像素 `P = R & G & B`。
    // 如果 `I(1,1) = [247, 170, 14] = [0b11110111, 0b10101010, 0b00001111]`
    // 那么 `O(1,1) = 0b11110111 & 0b10101010 & 0b00001111 = 0b00000010 = 2`。
  });
```
