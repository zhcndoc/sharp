## composite
> composite(images) ⇒ <code>Sharp</code>

在处理过的（调整大小、提取等）图像上合成图像。

要合成的图像必须与处理后的图像大小相同或更小。
如果同时提供了 `top` 和 `left` 选项，则它们优先于 `gravity`。

在同一处理管道中的任何调整大小、旋转或提取操作
将始终在合成之前应用于输入图像。

`blend` 选项可以是 `clear`、`source`、`over`、`in`、`out`、`atop`、
`dest`、`dest-over`、`dest-in`、`dest-out`、`dest-atop`、
`xor`、`add`、`saturate`、`multiply`、`screen`、`overlay`、`darken`、`lighten`、
`colour-dodge`、`color-dodge`、`colour-burn`、`color-burn`、
`hard-light`、`soft-light`、`difference`、`exclusion` 中的一个。

有关混合模式的更多信息，请访问
https://www.libvips.org/API/current/libvips-conversion.html#VipsBlendMode
以及 https://www.cairographics.org/operators/

**抛出**：

- <code>Error</code> 无效参数

**自**: 0.22.0  

| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| images | <code>Array.&lt;Object&gt;</code> |  | 要合成的图像的有序列表 |
| [images[].input] | <code>Buffer</code> \| <code>String</code> |  | 包含图像数据的缓冲区，或者包含图像文件路径的字符串，或者创建对象（见下文） |
| [images[].input.create] | <code>Object</code> |  | 描述要创建的空白覆盖层。 |
| [images[].input.create.width] | <code>Number</code> |  |  |
| [images[].input.create.height] | <code>Number</code> |  |  |
| [images[].input.create.channels] | <code>Number</code> |  | 3-4 |
| [images[].input.create.background] | <code>String</code> \| <code>Object</code> |  | 通过 [color](https://www.npmjs.org/package/color) 模块解析以提取红、绿、蓝和阿尔法的值。 |
| [images[].input.text] | <code>Object</code> |  | 描述要创建的新文本图像。 |
| [images[].input.text.text] | <code>string</code> |  | 作为 UTF-8 字符串呈现的文本。可以包含 Pango 标记，例如 `<i>Le</i>Monde`。 |
| [images[].input.text.font] | <code>string</code> |  | 要使用的字体名称。 |
| [images[].input.text.fontfile] | <code>string</code> |  | 可以被 `font` 使用的字体文件的绝对文件系统路径。 |
| [images[].input.text.width] | <code>number</code> | <code>0</code> | 单词换行的像素整数数。宽于此的文本行将在单词边界处断开。 |
| [images[].input.text.height] | <code>number</code> | <code>0</code> | 像素高度的完整数。定义时将忽略 `dpi`，并且文本将自动适应由 `width` 和 `height` 定义的像素分辨率。如果未指定 `width` 或设置为 0，将被忽略。 |
| [images[].input.text.align] | <code>string</code> | <code>&quot;&#x27;left&#x27;&quot;</code> | 文本对齐方式（`'left'`、`'centre'`、`'center'`、`'right'`）。 |
| [images[].input.text.justify] | <code>boolean</code> | <code>false</code> | 设置为 true 以对文本应用对齐。 |
| [images[].input.text.dpi] | <code>number</code> | <code>72</code> | 渲染文本的分辨率（大小）。如果指定了 `height`，则不生效。 |
| [images[].input.text.rgba] | <code>boolean</code> | <code>false</code> | 设置为 true 以启用 RGBA 输出。这对于颜色 emoji 渲染或支持 Pango 标记功能（如 `<span foreground="red">Red!</span>`）非常有用。 |
| [images[].input.text.spacing] | <code>number</code> | <code>0</code> | 文本行高，以点为单位。如果未指定，则使用字体行高。 |
| [images[].blend] | <code>String</code> | <code>&#x27;over&#x27;</code> | 如何将此图像与下面的图像混合。 |
| [images[].gravity] | <code>String</code> | <code>&#x27;centre&#x27;</code> | 将覆盖物放置的重力。 |
| [images[].top] | <code>Number</code> |  | 从顶部边缘的像素偏移量。 |
| [images[].left] | <code>Number</code> |  | 从左边缘的像素偏移量。 |
| [images[].tile] | <code>Boolean</code> | <code>false</code> | 设置为 true，以根据给定的 `gravity` 在整个图像上重复覆盖层图像。 |
| [images[].premultiplied] | <code>Boolean</code> | <code>false</code> | 设置为 true 以避免对下面的图像进行预乘。相当于 `--premultiplied` vips 选项。 |
| [images[].density] | <code>Number</code> | <code>72</code> | 表示矢量覆盖图像的 DPI 的数字。 |
| [images[].raw] | <code>Object</code> |  | 描述使用原始像素数据时的覆盖层。 |
| [images[].raw.width] | <code>Number</code> |  |  |
| [images[].raw.height] | <code>Number</code> |  |  |
| [images[].raw.channels] | <code>Number</code> |  |  |
| [images[].animated] | <code>boolean</code> | <code>false</code> | 设置为 `true` 以读取动画图像的所有帧/页面。 |
| [images[].failOn] | <code>string</code> | <code>&quot;&#x27;warning&#x27;&quot;</code> | @see [构造函数参数](/api-constructor#parameters) |
| [images[].limitInputPixels] | <code>number</code> \| <code>boolean</code> | <code>268402689</code> | @see [构造函数参数](/api-constructor#parameters) |

**示例**  
```js
await sharp(background)
  .composite([
    { input: layer1, gravity: 'northwest' },
    { input: layer2, gravity: 'southeast' },
  ])
  .toFile('combined.png');
```
**示例**  
```js
const output = await sharp('input.gif', { animated: true })
  .composite([
    { input: 'overlay.png', tile: true, blend: 'saturate' }
  ])
  .toBuffer();
```
**示例**  
```js
sharp('input.png')
  .rotate(180)
  .resize(300)
  .flatten( { background: '#ff6600' } )
  .composite([{ input: 'overlay.png', gravity: 'southeast' }])
  .sharpen()
  .withMetadata()
  .webp( { quality: 90 } )
  .toBuffer()
  .then(function(outputBuffer) {
    // outputBuffer 包含翻转、300 像素宽、透明通道压平
    // 到橙色背景，合成了 overlay.png 和 SE 重力，
    // 锐化，带有元数据，90% 质量的 WebP 图像数据。哎呀！
  });
```