## 版本
> 版本

一个包含 sharp、libvips 及其依赖项（当使用预构建的二进制文件时）的版本号的对象。


**示例**  
```js
console.log(sharp.versions);
```


## 插值器
> 插值器 : <code>枚举</code>

一个包含可用插值器及其相应值的对象。


**只读**: true  
**属性**

| 名称 | 类型 | 默认值 | 描述 |
| --- | --- | --- | --- |
| nearest | <code>字符串</code> | <code>&quot;nearest&quot;</code> | [最近邻插值](http://en.wikipedia.org/wiki/Nearest-neighbor_interpolation)。仅适用于图像放大。 |
| bilinear | <code>字符串</code> | <code>&quot;bilinear&quot;</code> | [双线性插值](http://en.wikipedia.org/wiki/Bilinear_interpolation)。比双三次插值快，但结果平滑性较差。 |
| bicubic | <code>字符串</code> | <code>&quot;bicubic&quot;</code> | [双三次插值](http://en.wikipedia.org/wiki/Bicubic_interpolation)（默认值）。 |
| locallyBoundedBicubic | <code>字符串</code> | <code>&quot;lbb&quot;</code> | [LBB插值](https://github.com/libvips/libvips/blob/master/libvips/resample/lbb.cpp#L100)。防止某些“[清晰度](http://en.wikipedia.org/wiki/Acutance)”，但通常会将性能减半。 |
| nohalo | <code>字符串</code> | <code>&quot;nohalo&quot;</code> | [Nohalo插值](http://eprints.soton.ac.uk/268086/)。防止清晰度，但通常会将性能降低三分之一。 |
| vertexSplitQuadraticBasisSpline | <code>字符串</code> | <code>&quot;vsqbs&quot;</code> | [VSQBS插值](https://github.com/libvips/libvips/blob/master/libvips/resample/vsqbs.cpp#L48)。在放大时防止“阶梯效应”。 |


## 格式
> 格式 ⇒ <code>对象</code>

一个包含嵌套布尔值的对象，表示可用的输入和输出格式/方法。


**示例**  
```js
console.log(sharp.format);
```


## 队列
> 队列

一个 EventEmitter，当任务被以下情况之一时发出 `change` 事件：
- 已排队，等待 _libuv_ 提供工作线程
- 完成


**示例**  
```js
sharp.queue.on('change', function(queueLength) {
  console.log('队列包含 ' + queueLength + ' 个任务');
});
```


## 缓存
> 缓存([选项]) ⇒ <code>对象</code>

获取或在提供选项时设置 _libvips_ 操作缓存的限制。
缓存中的现有条目将在限制改变后被修剪。
此方法始终返回缓存统计信息，
对于确定特定任务所需的工作内存非常有用。



| 参数 | 类型 | 默认值 | 描述 |
| --- | --- | --- | --- |
| [选项] | <code>对象</code> \| <code>布尔值</code> | <code>true</code> | 具有以下属性的对象，或布尔值，其中 true 使用默认缓存设置，false 则移除所有缓存 |
| [选项.memory] | <code>数字</code> | <code>50</code> | 为此缓存使用的最大内存（MB） |
| [选项.files] | <code>数字</code> | <code>20</code> | 允许保持打开的最大文件数 |
| [选项.items] | <code>数字</code> | <code>100</code> | 允许缓存的最大操作数 |

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


## 并发
> 并发([并发]) ⇒ <code>数字</code>

获取或在提供并发时设置 _libvips_ 应该用于处理 _每个图像_ 的最大线程数。
这些线程来自由 glib 管理的线程池，
这有助于避免创建新线程的开销。

此方法始终返回当前并发。

默认值为 CPU 核心数，
但在未使用 jemalloc 的基于 glibc 的 Linux 中，默认值为 `1` 以帮助减少内存碎片。

值为 `0` 将重置为 CPU 核心数。

某些图像格式库会生成附加线程，
例如 libaom 在编码 AVIF 图像时管理自己的 4 个线程，
这些线程与此处设置的值无关。

sharp 可以并行处理的最大图像数
由 libuv 的 `UV_THREADPOOL_SIZE` 环境变量控制，
默认为 4。

https://nodejs.org/api/cli.html#uv_threadpool_sizesize

例如，默认情况下，具有 8 个 CPU 核心的机器将并行处理
4 个图像，并为每个图像使用最多 8 个线程，
因此将会有最多 32 个并发线程。


**返回**: <code>数字</code> - 并发  

| 参数 | 类型 |
| --- | --- |
| [并发] | <code>数字</code> | 

**示例**  
```js
const threads = sharp.concurrency(); // 4
sharp.concurrency(2); // 2
sharp.concurrency(0); // 4
```


## 计数器
> 计数器() ⇒ <code>对象</code>

提供对内部任务计数器的访问。
- queue 是此模块排队等待 _libuv_ 从其池中提供工作线程的任务数量。
- process 是当前正在处理的调整大小任务数量。


**示例**  
```js
const counters = sharp.counters(); // { queue: 2, process: 4 }
```


## SIMD
> SIMD([simd]) ⇒ <code>布尔值</code>

获取和设置 SIMD 向量单元指令的使用。
需要 libvips 被编译为支持 highway。

通过利用 CPU 的 SIMD 向量单元（如 Intel SSE 和 ARM NEON），
提高 `resize`、`blur` 和 `sharpen` 操作的性能。



| 参数 | 类型 | 默认值 |
| --- | --- | --- |
| [simd] | <code>布尔值</code> | <code>true</code> | 

**示例**  
```js
const simd = sharp.simd();
// 如果当前启用了 highway 的运行时使用，simd 为 `true`
```
**示例**  
```js
const simd = sharp.simd(false);
// 防止 libvips 在运行时使用 highway
```


## 阻止
> 阻止(选项)

在运行时阻止 libvips 操作。

这是在 `VIPS_BLOCK_UNTRUSTED` 环境变量之外设置的，
在设置时将阻止所有“未受信任”的操作。


**自**: 0.32.4  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| 选项 | <code>对象</code> |  |
| 选项.operation | <code>数组.&lt;字符串&gt;</code> | 要阻止的 libvips 低级操作名称列表。 |

**示例** *(阻止所有 TIFF 输入。)*  
```js
sharp.block({
  operation: ['VipsForeignLoadTiff']
});
```


## 解除阻止
> 解除阻止(选项)

在运行时解除阻止 libvips 操作。

这对于定义被允许的操作列表很有用。


**自**: 0.32.4  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| 选项 | <code>对象</code> |  |
| 选项.operation | <code>数组.&lt;字符串&gt;</code> | 要解除阻止的 libvips 低级操作名称列表。 |

**示例** *(阻止所有文件系统中的输入，除了 WebP。)*  
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadWebpFile']
});
```
**示例** *(阻止所有输入，除了来自 Buffer 或 Stream 的 JPEG 和 PNG。)*  
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadJpegBuffer', 'VipsForeignLoadPngBuffer']
});
```