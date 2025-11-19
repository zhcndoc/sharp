---
# 此文件是由 lib/colour.js 中的 JSDoc 自动生成的
title: 颜色操作
---

## tint
> tint(tint) ⇒ <code>Sharp</code>

使用提供的颜色为图像上色。
可能存在 alpha 通道，并且在操作中不会被更改。


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

转换为 8 位灰度图；256 种灰度。这是一个线性操作。如果输入图像处于非线性色彩空间（例如 sRGB），请使用 `gamma()` 和 `greyscale()` 来获得最佳效果。默认情况下，输出图像将是网络友好的 sRGB，并包含三个（相同的）颜色通道。可以通过其他 sharp 操作覆盖，例如 `toColourspace('b-w')`，这将产生一个包含一个颜色通道的输出图像。可能存在 alpha 通道，并且在操作中不会被更改。

| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [greyscale] | <code>Boolean</code> | <code>true</code> |

**示例**
```js
const output = await sharp(input).greyscale().toBuffer();
```

## grayscale
> grayscale([grayscale]) ⇒ <code>Sharp</code>

`greyscale` 的另一种拼写。

| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [grayscale] | <code>Boolean</code> | <code>true</code> |

## pipelineColourspace
> pipelineColourspace([colourspace]) ⇒ <code>Sharp</code>

设置管道色彩空间。

输入图像将在管道开始时转换为提供的色彩空间。所有操作将在此色彩空间中进行，然后转换到输出色彩空间，由 [toColourspace](#tocolourspace) 定义。


**抛出**：

- <code>Error</code> 无效参数

**自**: 0.29.0

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colourspace] | <code>string</code> | 管道色彩空间，例如 `rgb16`、`scrgb`、`lab`、`grey16` [...](https://www.libvips.org/API/current/enum.Interpretation.html) |

**示例**
```js
// 在每通道 16 位 RGB 的情况下运行管道，同时将最终结果转换为每通道 8 位 sRGB。
await sharp(input)
 .pipelineColourspace('rgb16')
 .toColourspace('srgb')
 .toFile('16bpc-pipeline-to-8bpc-output.png')
```


## pipelineColorspace
> pipelineColorspace([colorspace]) ⇒ <code>Sharp</code>

`pipelineColourspace` 的另一种拼写。


**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colorspace] | <code>string</code> | 管道色彩空间。 |



## toColourspace
> toColourspace([colourspace]) ⇒ <code>Sharp</code>

设置输出色彩空间。默认情况下，输出图像将是网络友好的 sRGB，并且附加通道将被解释为 alpha 通道。


**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colourspace] | <code>string</code> | 输出色彩空间，例如 `srgb`、`rgb`、`cmyk`、`lab`、`b-w` [...](https://www.libvips.org/API/current/enum.Interpretation.html) |

**示例**
```js
// 输出每像素 16 位 RGB
await sharp(input)
 .toColourspace('rgb16')
 .toFile('16-bpp.png')
```


## toColorspace
> toColorspace([colorspace]) ⇒ <code>Sharp</code>

`toColourspace` 的另一种拼写。


**抛出**：

- <code>Error</code> 无效参数


| 参数 | 类型 | 描述 |
| --- | --- | --- |
| [colorspace] | <code>string</code> | 输出色彩空间。 |
