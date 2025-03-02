### versions
> versions

一个包含 sharp、libvips 以及（使用预构建二进制文件时）其依赖项版本号的对象。

**示例**  
```js
console.log(sharp.versions);
```

### interpolators
> interpolators : <code>enum</code>

一个包含可用插值器及其正确值的对象。

**只读**: true  
**属性**

| 名称 | 类型 | 默认值 | 描述 |
| --- | --- | --- | --- |
| nearest | <code>string</code> | <code>"nearest"</code> | [最近邻插值](http://en.wikipedia.org/wiki/Nearest-neighbor_interpolation)。仅适用于图像放大。 |
| bilinear | <code>string</code> | <code>"bilinear"</code> | [双线性插值](http://en.wikipedia.org/wiki/Bilinear_interpolation)。比双三次插值快，但结果不够平滑。 |
| bicubic | <code>string</code> | <code>"bicubic"</code> | [双三次插值](http://en.wikipedia.org/wiki/Bicubic_interpolation)（默认）。 |
| locallyBoundedBicubic | <code>string</code> | <code>"lbb"</code> | [LBB插值](https://github.com/libvips/libvips/blob/master/libvips/resample/lbb.cpp#L100)。防止了一些“[锐度](http://en.wikipedia.org/wiki/Acutance)”问题，但通常会将性能降低2倍。 |
| nohalo | <code>string</code> | <code>"nohalo"</code> | [Nohalo插值](http://eprints.soton.ac.uk/268086/)。防止了锐度问题，但通常会将性能降低3倍。 |
| vertexSplitQuadraticBasisSpline | <code>string</code> | <code>"vsqbs"</code> | [VSQBS插值](https://github.com/libvips/libvips/blob/master/libvips/resample/vsqbs.cpp#L48)。在放大时防止“阶梯效应”。 |

### format
> format ⇒ <code>Object</code>

一个包含嵌套布尔值的对象，表示可用的输入和输出格式/方法。

**示例**  
```js
console.log(sharp.format);
```

### queue
> queue

一个 EventEmitter，当任务处于以下状态时会触发 `change` 事件：
- 已排队，等待 _libuv_ 提供工作线程
- 已完成

**示例**  
```js
sharp.queue.on('change', function(queueLength) {
  console.log('队列包含 ' + queueLength + ' 个任务');
});
```

### cache
> cache([options]) ⇒ <code>Object</code>

获取或（当提供选项时）设置 _libvips_ 操作缓存的限制。在更改限制后，缓存中的现有条目将被修剪。此方法始终返回缓存统计信息，有助于确定特定任务所需的工作内存。

| 参数 | 类型 | 默认值 | 描述 |
| --- | --- | --- | --- |
| [options] | <code>Object</code> \| <code>boolean</code> | <code>true</code> | 具有以下属性的对象，或布尔值，其中 true 使用默认缓存设置，false 移除所有缓存 |
| [options.memory] | <code>number</code> | <code>50</code> | 用于此缓存的最大内存（MB） |
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

### concurrency
> concurrency([concurrency]) ⇒ <code>number</code>

获取或（当提供并发数时）设置 _libvips_ 应用于 _每个图像_ 的最大线程数。这些线程来自由 glib 管理的线程池，有助于避免创建新线程的开销。

此方法始终返回当前并发数。

默认值是 CPU 核心数，但在使用 glibc 基础的 Linux 且未使用 jemalloc 时，默认值为 `1`，以帮助减少内存碎片。

值为 `0` 将重置为 CPU 核心数。

一些图像格式库会启动额外的线程，例如 libaom 在编码 AVIF 图像时会管理自己的 4 个线程，这些线程与此处设置的值无关。

sharp 可以并行处理的最大图像数由 libuv 的 `UV_THREADPOOL_SIZE` 环境变量控制，默认值为 4。

[https://nodejs.org/api/cli.html#uv_threadpool_sizesize](https://nodejs.org/api/cli.html#uv_threadpool_sizesize)  

例如，默认情况下，具有 8 个 CPU 核心的机器将并行处理 4 个图像，每个图像最多使用 8 个线程，因此最多将有 32 个并发线程。

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

### counters
> counters() ⇒ <code>Object</code>

提供对内部任务计数器的访问。
- queue 是此模块已排队等待 _libuv_ 从其线程池中提供工作线程的任务数。
- process 是当前正在处理的调整大小任务数。

**示例**  
```js
const counters = sharp.counters(); // { queue: 2, process: 4 }
```

### simd
> simd([simd]) ⇒ <code>boolean</code>

获取和设置 SIMD 向量指令的使用。需要 libvips 在编译时支持 highway。

通过利用 CPU 的 SIMD 向量单元（例如 Intel SSE 和 ARM NEON），提高 `resize`、`blur` 和 `sharpen` 操作的性能。

| 参数 | 类型 | 默认值 |
| --- | --- | --- |
| [simd] | <code>boolean</code> | <code>true</code> | 

**示例**  
```js
const simd = sharp.simd();
// 如果当前启用了 highway 运行时使用，simd 为 `true`
```
**示例**  
```js
const simd = sharp.simd(false);
// 防止 libvips 在运行时使用 highway
```

### block
> block(options)

在运行时阻止 libvips 操作。

这补充了 `VIPS_BLOCK_UNTRUSTED` 环境变量，当设置时，将阻止所有“不受信任”的操作。

**自**: 0.32.4  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> | |
| options.operation | <code>Array.&lt;string&gt;</code> | 要阻止的 libvips 低级操作名称列表。 |

**示例** *(阻止所有 TIFF 输入。)*  
```js
sharp.block({
  operation: ['VipsForeignLoadTiff']
});
```

### unblock
> unblock(options)

在运行时解除 libvips 操作的阻止。

这对于定义允许的操作列表很有用。

**自**: 0.32.4  

| 参数 | 类型 | 描述 |
| --- | --- | --- |
| options | <code>Object</code> | |
| options.operation | <code>Array.&lt;string&gt;</code> | 要解除阻止的 libvips 低级操作名称列表。 |

**示例** *(阻止所有输入，除了从文件系统的 WebP。)*  
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadWebpFile']
});
```
**示例** *(阻止所有输入，除了从 Buffer 或 Stream 的 JPEG 和 PNG。)*  
```js
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadJpegBuffer', 'VipsForeignLoadPngBuffer']
});
```
