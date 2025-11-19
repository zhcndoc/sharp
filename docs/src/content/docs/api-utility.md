---
# 该文件是从 lib/utility.js 的 JSDoc 自动生成的
title: 全局属性
---

## versions
> versions

一个对象，包含了 sharp、libvips 的版本号和（在使用预构建的二进制文件时）其依赖项的版本号。


**示例**
```js
console.log(sharp.versions);
```


## interpolators
> interpolators : <code>enum</code>

一个对象，包含可用的插值器及其正确值


**只读**: true
**属性**

| 名称 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| nearest | <code>string</code> | <code>&quot;nearest&quot;</code> | [最近邻插值](http://en.wikipedia.org/wiki/Nearest-neighbor_interpolation)。仅适用于图像放大。 |
| bilinear | <code>string</code> | <code>&quot;bilinear&quot;</code> | [双线性插值](http://en.wikipedia.org/wiki/Bilinear_interpolation)。比三次插值快，但平滑效果较差。 |
| bicubic | <code>string</code> | <code>&quot;bicubic&quot;</code> | [三次插值](http://en.wikipedia.org/wiki/Bicubic_interpolation)（默认）。 |
| locallyBoundedBicubic | <code>string</code> | <code>&quot;lbb&quot;</code> | [LBB 插值](https://github.com/libvips/libvips/blob/master/libvips/resample/lbb.cpp#L100)。防止一些“[锐度](http://en.wikipedia.org/wiki/Acutance)”，但通常会将性能降低一半。 |
| nohalo | <code>string</code> | <code>&quot;nohalo&quot;</code> | [无晕影插值](http://eprints.soton.ac.uk/268086/)。防止锐度，但通常会将性能降低三分之一。 |
| vertexSplitQuadraticBasisSpline | <code>string</code> | <code>&quot;vsqbs&quot;</code> | [VSQBS 插值](https://github.com/libvips/libvips/blob/master/libvips/resample/vsqbs.cpp#L48)。防止放大时出现“阶梯化”。 |


## format
> format ⇒ <code>Object</code>

一个对象，包含表示可用输入和输出格式/方法的嵌套布尔值。


**示例**
```js
console.log(sharp.format);
```


## queue
> queue

一个 EventEmitter，当任务被：
- 排队，等待 _libuv_ 提供工作线程
- 完成时发出 `change` 事件


**示例**
```js
sharp.queue.on('change', function(queueLength) {
  console.log('队列中包含 ' + queueLength + ' 个任务');
});
```


## cache
> cache([options]) ⇒ <code>Object</code>

获取或在提供选项时设置 _libvips_ 操作缓存的限制。
在限制更改后，缓存中的现有条目将被修剪。
该方法始终返回缓存统计信息，
有助于确定特定任务所需的工作内存量。



| 参数 | 类型 | 默认 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> \| <code>boolean</code> | <code>true</code> | 具有以下属性的对象，或布尔值，其中 true 使用默认缓存设置，false 则删除所有缓存 |
| [options.memory] | <code>number</code> | <code>50</code> | 用于此缓存的最大内存（以 MB 为单位） |
| [options.files] | <code>number</code> | <code>20</code> | 最大打开文件数 |
| [options.items] | <code>number</code> | <code>100</code> | 最大缓存操作数 |

**示例**
```js
const stats = sharp.cache();
```
**示例**
```js
sharp.cache( { items: 200 } );
sharp.cache( { files: 0 } );
sharp.cache(false);
```


## concurrency
> concurrency([concurrency]) ⇒ <code>number</code>

获取或在提供并发数时设置 libvips 应该使用的处理 **每个图像** 的最大线程数。这些线程来自 glib 管理的线程池，该管理帮助避免创建新线程的开销。

该方法始终返回当前并发值。

默认值为 CPU 核心数，但在不使用 jemalloc 的基于 glibc 的 Linux 系统上，默认值为 `1`，以帮助减少内存碎片。

值为 `0` 将重置为 CPU 核心数。

一些图像格式库会生成额外线程，例如 libaom 在编码 AVIF 图像时管理其自己的 4 个线程，这些线程与此处设置的值无关。

:::note
还可进一步[控制性能表现](/performance/)。
:::


**返回**: <code>number</code> - 并发数

| 参数 | 类型 |
| --- | --- |
| [concurrency] | <code>number</code> |

**示例**
```js
const threads = sharp.concurrency(); // 4
sharp.concurrency(2); // 2
sharp.concurrency(0); // 4
```


## counters
> counters() ⇒ <code>Object</code>

提供对内部任务计数器的访问。
- queue 是该模块已排队等待 libuv 提供其池中工作线程的任务数量。
- process 是当前正在处理的调整大小任务数量。


**示例**
```js
const counters = sharp.counters(); // { queue: 2, process: 4 }
```


## simd
> simd([simd]) ⇒ <code>boolean</code>

获取和设置 SIMD 矢量单元指令的使用。
需要 libvips 已编译为支持 highway。

通过利用 CPU 的 SIMD 矢量单元（例如 Intel SSE 和 ARM NEON），改善 `resize`、`blur` 和 `sharpen` 操作的性能。



| 参数 | 类型 | 默认 |
| --- | --- | --- |
| [simd] | <code>boolean</code> | <code>true</code> |

**示例**
```js
const simd = sharp.simd();
// simd 是 `true`，如果当前启用了 highway 的运行时使用
```
**示例**
```js
const simd = sharp.simd(false);
// 在运行时防止 libvips 使用 highway
```


## block
> block(options)

在运行时阻止 libvips 操作。

这与 `VIPS_BLOCK_UNTRUSTED` 环境变量相结合使用，
该变量设置后将阻止所有“不受信任”的操作。


**自**: 0.32.4

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> |  |
| options.operation | <code>Array.&lt;string&gt;</code> | 要阻止的 libvips 低级操作名称列表。 |

**示例** (阻止所有 TIFF 输入)
```js
sharp.block({
  operation: ['VipsForeignLoadTiff']
});
```


## unblock
> unblock(options)

在运行时解除 libvips 操作的阻止。

这对于定义允许的操作列表非常有用。


**自**: 0.32.4

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> |  |
| options.operation | <code>Array.&lt;string&gt;</code> | 要解除阻止的 libvips 低级操作名称列表。 |

**示例** (阻止除了文件系统中的 WebP 输入外的所有输入)
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadWebpFile']
});
```
**示例** (阻止除 JPEG 和 PNG 从 Buffer 或 Stream 输入之外的所有输入)
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadJpegBuffer', 'VipsForeignLoadPngBuffer']
});
```
