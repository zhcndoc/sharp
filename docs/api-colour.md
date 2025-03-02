## tint
> tint(tint) ⇒ <code>Sharp</code>

使用提供的颜色给图像上色。
可能存在 alpha 通道，并且此操作不会更改它。

**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| tint | <code>string</code> \| <code>Object</code> | 由 [color](https://www.npmjs.org/package/color) 模块解析。 |

**示例**  
```js
const output = await sharp(input)
  .tint({ r: 255, g: 240, b: 16 })
  .toBuffer();
```


## greyscale
> greyscale([greyscale]) ⇒ <code>Sharp</code>

转换为 8 位灰度；256 种灰度。
这是一个线性操作。如果输入图像处于非线性颜色空间（例如 sRGB），请使用 `gamma()` 和 `greyscale()` 以获得最佳效果。
默认情况下，输出图像将为网页友好的 sRGB，并包含三个（相同的）颜色通道。
这可以通过其他 sharp 操作来覆盖，例如 `toColourspace('b-w')`，这将生成一个包含一个颜色通道的输出图像。
可能存在 alpha 通道，并且此操作不会更改它。

| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [greyscale] | <code>Boolean</code> | <code>true</code> | 

**示例**  
```js
const output = await sharp(input).greyscale().toBuffer();
```


## grayscale
> grayscale([grayscale]) ⇒ <code>Sharp</code>

`greyscale` 的替代拼写。


| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [grayscale] | <code>Boolean</code> | <code>true</code> | 



## pipelineColourspace
> pipelineColourspace([colourspace]) ⇒ <code>Sharp</code>

设置管道颜色空间。

输入图像将在管道开始时转换为提供的颜色空间。
所有操作将使用此颜色空间，然后再转换为输出颜色空间，如 [toColourspace](#tocolourspace) 所定义。

**抛出**：

- <code>Error</code> 无效参数

**自**：0.29.0  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colourspace] | <code>string</code> | 管道颜色空间，例如 `rgb16`、`scrgb`、`lab`、`grey16` [...](https://github.com/libvips/libvips/blob/41cff4e9d0838498487a00623462204eb10ee5b8/libvips/iofuncs/enumtypes.c#L774) |

**示例**  
```js
// 在每通道 16 位 RGB 下运行管道，同时将最终结果转换为每通道 8 位 sRGB。
await sharp(input)
 .pipelineColourspace('rgb16')
 .toColourspace('srgb')
 .toFile('16bpc-pipeline-to-8bpc-output.png')
```


## pipelineColorspace
> pipelineColorspace([colorspace]) ⇒ <code>Sharp</code>

`pipelineColourspace` 的替代拼写。


**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colorspace] | <code>string</code> | 管道颜色空间。 |



## toColourspace
> toColourspace([colourspace]) ⇒ <code>Sharp</code>

设置输出颜色空间。
默认情况下，输出图像将为网页友好的 sRGB，额外通道将被解释为 alpha 通道。

**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colourspace] | <code>string</code> | 输出颜色空间，例如 `srgb`、`rgb`、`cmyk`、`lab`、`b-w` [...](https://github.com/libvips/libvips/blob/3c0bfdf74ce1dc37a6429bed47fa76f16e2cd70a/libvips/iofuncs/enumtypes.c#L777-L794) |

**示例**  
```js
// 输出每像素 16 位 RGB
await sharp(input)
 .toColourspace('rgb16')
 .toFile('16-bpp.png')
```


## toColorspace
> toColorspace([colorspace]) ⇒ <code>Sharp</code>

`toColourspace` 的替代拼写。


**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colorspace] | <code>string</code> | 输出颜色空间。 |