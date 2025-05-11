---
title: 更新日志
---

## v0.34 - *hat*

Requires libvips v8.16.1

### v0.34.2 - TBD

* 确保动画 GIF 转换为 WebP 时保留循环（在 0.34.0 中出现回归）。
  [#3394](https://github.com/lovell/sharp/issues/3394)

* 确保使用 `pdfBackground` 构造函数的属性。
  [#4207](https://github.com/lovell/sharp/pull/4207)

* 添加对预构建的 Windows ARM64 二进制文件的支持。
  [#4375](https://github.com/lovell/sharp/pull/4375)
  [@hans00](https://github.com/hans00)

* TypeScript：确保在 WebP 定义中包含 `smartDeblock` 属性。
  [#4387](https://github.com/lovell/sharp/pull/4387)
  [@Stephen-X](https://github.com/Stephen-X)

### v0.34.1 - 2025 年 4 月 7 日

* TypeScript：确保新的 `autoOrient` 属性是可选的。
  [#4362](https://github.com/lovell/sharp/pull/4362)
  [@styfle](https://github.com/styfle)

### v0.34.0 - 2025 年 4 月 4 日

* 最新消息：支持将多张输入图片拼接或制作成动画。
  [#1580](https://github.com/lovell/sharp/issues/1580)

* 突发：确保 `removeAlpha` 移除所有 alpha 通道。
  [#2266](https://github.com/lovell/sharp/issues/2266)

* 突发消息：非动画 GIF 输出默认设置为不循环，而不是永久循环。
  [#3394](https://github.com/lovell/sharp/issues/3394)

* 突发：通过升级到 C++17 支持宽字符系统上的 `info.size`。
  [#3943](https://github.com/lovell/sharp/issues/3943)

* 突发：确保 `background` 元数据可以被 `color` 包解析。
  [#4090](https://github.com/lovell/sharp/issues/4090)

* 将 `isPalette` 和 `bitsPerSample` 添加到元数据中，弃用 `paletteBitDepth`。

* 暴露 WebP `smartDeblock` 输出选项。

* 防止使用具有 v1 微架构的 linux-x64 二进制文件。

* 添加 `autoOrient` 操作和构造函数选项。
  [#4151](https://github.com/lovell/sharp/pull/4151)
  [@happycollision](https://github.com/happycollision)

* TypeScript：确保通道计数使用正确的范围。
  [#4197](https://github.com/lovell/sharp/pull/4197)
  [@DavidVaness](https://github.com/DavidVaness)

* 改进对 ppc64le 架构的支持。
  [#4203](https://github.com/lovell/sharp/pull/4203)
  [@sumitd2](https://github.com/sumitd2)

* 添加 `pdfBackground` 构造函数属性。
  [#4207](https://github.com/lovell/sharp/pull/4207)
  [@calebmer](https://github.com/calebmer)

* 公开腐蚀与膨胀操作。
  [#4243](https://github.com/lovell/sharp/pull/4243)
  [@qpincon](https://github.com/qpincon)

* 添加对 RGBE 图像的支持。需要编译了辐射支持的 libvips。
  [#4316](https://github.com/lovell/sharp/pull/4316)
  [@florentzabera](https://github.com/florentzabera)

* 允许在更高位深下输出宽色域 HEIF。
  [#4344](https://github.com/lovell/sharp/issues/4344)

## v0.33 - *gauge*

需要 libvips v8.15.5-rc1

### v0.33.5 - 2024 年 8 月 16 日

* 升级到 libvips v8.15.3 以修复上游的漏洞。

* 在多页输出的响应中添加 `pageHeight` 和 `pages`。
  [#3411](https://github.com/lovell/sharp/issues/3411)

* 确保强制使用全局安装的 libvips 的选项能够正确工作。
  [#4111](https://github.com/lovell/sharp/pull/4111)
  [@project0](https://github.com/project0)

* 最小化 `engines` 属性的使用以改进对 yarn v1 的支持。
  [#4130](https://github.com/lovell/sharp/issues/4130)

* 确保在使用预编译二进制文件时，`sharp.format.heif` 仅包含 AVIF。
  [#4132](https://github.com/lovell/sharp/issues/4132)

* 添加对 recomb 操作的 4x4 矩阵的支持。
  [#4147](https://github.com/lovell/sharp/pull/4147)
  [@ton11797](https://github.com/ton11797)

* 将 PNG 文本块公开为 `comments` 元数据。
  [#4157](https://github.com/lovell/sharp/pull/4157)
  [@nkeynes](https://github.com/nkeynes)

* 公开 `blur` 操作的可选 `precision` 和 `minAmplitude` 参数。
  [#4168](https://github.com/lovell/sharp/pull/4168)
  [#4172](https://github.com/lovell/sharp/pull/4172)
  [@marcosc90](https://github.com/marcosc90)

* 确保 `keepIccProfile` 尽可能避免颜色转换。
  [#4186](https://github.com/lovell/sharp/issues/4186)

* TypeScript：`chromaSubsampling` 元数据是可选的。
  [#4191](https://github.com/lovell/sharp/pull/4191)
  [@DavidVaness](https://github.com/DavidVaness)

### v0.33.4 - 2024 年 5 月 16 日

* 移除 `pipelineColourspace` 的实验性状态。

* 当检测到 musl 线程超订阅时减少默认并发数。

* TypeScript：添加 `OverlayOptions` 的缺失定义。
  [#4048](https://github.com/lovell/sharp/pull/4048)
  [@ike-gg](https://github.com/ike-gg)

* 安装：添加高级选项以强制使用全局安装的 libvips。
  [#4060](https://github.com/lovell/sharp/issues/4060)

* 公开 `bilinear` 缩放内核（以及插值器）。
  [#4061](https://github.com/lovell/sharp/issues/4061)

* 确保 `extend` 操作在多页 TIFF 中保持顺序（在 0.32.0 中的回归）。
  [#4069](https://github.com/lovell/sharp/issues/4069)

* 加强对构造函数 `text` 整数属性的验证。
  [#4071](https://github.com/lovell/sharp/issues/4071)

* 简化内部 StaySequential 逻辑。
  [#4074](https://github.com/lovell/sharp/pull/4074)
  [@kleisauke](https://github.com/kleisauke)

* 确保 negate 操作在配置文件转换之后发生。
  [#4096](https://github.com/lovell/sharp/pull/4096)
  [@adriaanmeuris](https://github.com/adriaanmeuris)

### v0.33.3 - 2024 年 3 月 23 日

* 升级到 libvips v8.15.2 以修复上游的漏洞。

* 确保 `keepIccProfile` 保留 P3 和 CMYK 输入配置文件。
  [#3906](https://github.com/lovell/sharp/issues/3906)
  [#4008](https://github.com/lovell/sharp/issues/4008)

* 确保 `text.wrap` 属性可以接受 `word-char` 作为值。
  [#4028](https://github.com/lovell/sharp/pull/4028)
  [@yolopunk](https://github.com/yolopunk)

* 确保 `clone` 对现有选项进行深拷贝。
  [#4029](https://github.com/lovell/sharp/issues/4029)

* 添加 `bitdepth` 选项到 `heif` 输出（预编译二进制文件仅支持 8 位）。
  [#4036](https://github.com/lovell/sharp/pull/4036)
  [@mertalev](https://github.com/mertalev)

### v0.33.2 - 2024 年 1 月 12 日

* 升级到 libvips v8.15.1 以修复上游的漏洞。

* TypeScript：添加 `keepMetadata` 的定义。
  [#3914](https://github.com/lovell/sharp/pull/3914)
  [@abhi0498](https://github.com/abhi0498)

* 确保 `extend` 操作在复制时保持顺序（在 0.32.0 中的回归）。
  [#3928](https://github.com/lovell/sharp/issues/3928)

* 改进对不受支持的多页旋转的错误处理。
  [#3940](https://github.com/lovell/sharp/issues/3940)

### v0.33.1 - 2023 年 12 月 17 日

* 添加对 Yarn Plug'n'Play 文件系统布局的支持。
  [#3888](https://github.com/lovell/sharp/issues/3888)

* 在尝试使用无效的 ICC 配置文件时发出警告。
  [#3895](https://github.com/lovell/sharp/issues/3895)

* 确保尊重 `VIPS_NOVECTOR` 环境变量。
  [#3897](https://github.com/lovell/sharp/pull/3897)
  [@icetee](https://github.com/icetee)

### v0.33.0 - 2023 年 11 月 29 日

* 停止支持 Node.js 14 和 16，现在需要 Node.js ^18.17.0 或 >= 20.3.0

* 通过 npm 注册表分发预编译二进制文件，并通过包管理器安装。

* 从源代码构建需要依赖 `node-addon-api`。

* 移除 `sharp.vendor`。

* 部分弃用 `withMetadata()`，使用 `withExif()` 和 `withIccProfile()`。

* 添加对基于 WebAssembly 的运行时的实验性支持。
  [@RReverser](https://github.com/RReverser)

* `trim` 操作的选项必须是对象，添加新的 `lineArt` 选项。
  [#2363](https://github.com/lovell/sharp/issues/2363)

* 通过加权函数改进 `tint` 操作的亮度。
  [#3338](https://github.com/lovell/sharp/issues/3338)
  [@jcupitt](https://github.com/jcupitt)

* 确保所有 `Error` 对象包含 `stack` 属性。
  [#3653](https://github.com/lovell/sharp/issues/3653)

* 使 `heif` 的 `compression` 选项成为必需的，以帮助减少 HEIF 和 HEIC 的混淆。
  [#3740](https://github.com/lovell/sharp/issues/3740)

* 确保正确解释 16 位原始输入。
  [#3808](https://github.com/lovell/sharp/issues/3808)

* 添加对使用 TIFF 输出时的 `miniswhite` 的支持。
  [#3812](https://github.com/lovell/sharp/pull/3812)
  [@dnsbty](https://github.com/dnsbty)

* TypeScript：添加 `withMetadata` 布尔值的缺失定义。
  [#3823](https://github.com/lovell/sharp/pull/3823)
  [@uhthomas](https://github.com/uhthomas)

* 添加对输出元数据的更细粒度控制。
  [#3824](https://github.com/lovell/sharp/issues/3824)

* 确保多页提取保持顺序。
  [#3837](https://github.com/lovell/sharp/issues/3837)

## v0.32 - *flow*

需要 libvips v8.14.5

### v0.32.6 - 2023 年 9 月 18 日

* 升级到 libvips v8.14.5 以修复上游的漏洞。

* 确保复合平铺图像被完全解码（在 0.32.0 中的回归）。
  [#3767](https://github.com/lovell/sharp/issues/3767)

* 确保 `withMetadata` 可以为 RGB16 输出添加 ICC 配置文件。
  [#3773](https://github.com/lovell/sharp/issues/3773)

* 确保 `withMetadata` 不会将 16 位图像减少到 8 位（在 0.32.5 中的回归）。
  [#3773](https://github.com/lovell/sharp/issues/3773)

* TypeScript：为 block 和 unblock 添加定义。
  [#3799](https://github.com/lovell/sharp/pull/3799)
  [@ldrick](https://github.com/ldrick)

### v0.32.5 - 2023 年 8 月 15 日

* 升级到 libvips v8.14.4 以修复上游的漏洞。

* TypeScript：在定义中添加缺失的 `WebpPresetEnum`。
  [#3748](https://github.com/lovell/sharp/pull/3748)
  [@pilotso11](https://github.com/pilotso11)

* 确保使用 musl v1.2.4 进行编译。
  [#3755](https://github.com/lovell/sharp/pull/3755)
  [@kleisauke](https://github.com/kleisauke)

* 确保 `fit` 为 `inside` 的缩放尊重 90/270 度旋转。
  [#3756](https://github.com/lovell/sharp/issues/3756)

* TypeScript：确保 `WebpOptions` 的 `minSize` 属性为布尔值。
  [#3758](https://github.com/lovell/sharp/pull/3758)
  [@sho-xizz](https://github.com/sho-xizz)

* 确保 `withMetadata` 添加默认的 sRGB 配置文件。
  [#3761](https://github.com/lovell/sharp/issues/3761)

### v0.32.4 - 2023 年 7 月 21 日

* 升级到 libvips v8.14.3 以修复上游的漏洞。

* 公开按名称（un）阻止低级 libvips 操作的能力。

* 预编译二进制文件：恢复对基于平铺的输出的支持。
  [#3581](https://github.com/lovell/sharp/issues/3581)

### v0.32.3 - 2023 年 7 月 14 日

* 公开 WebP 输出的 `preset` 选项。
  [#3639](https://github.com/lovell/sharp/issues/3639)

* 确保所有操作的解码保持顺序（在 0.32.2 中的回归）。
  [#3725](https://github.com/lovell/sharp/issues/3725)

### v0.32.2 - 2023 年 7 月 11 日

* 将 HEIF 输出尺寸限制为 16384x16384，与 libvips 一致。

* 确保在终止时不会抛出异常。
  [#3569](https://github.com/lovell/sharp/issues/3569)

* 确保所有输入使用相同的访问方法（在 0.32.0 中的回归）。
  [#3669](https://github.com/lovell/sharp/issues/3669)

* 改进对 jp2 文件名扩展名的检测。
  [#3674](https://github.com/lovell/sharp/pull/3674)
  [@bianjunjie1981](https://github.com/bianjunjie1981)

* 保护智能裁剪预乘选项的使用以防止警告（在 0.32.1 中的回归）。
  [#3710](https://github.com/lovell/sharp/issues/3710)

* 在调整大小之前，防止在基于仿射的旋转中出现过度计算。
  [#3722](https://github.com/lovell/sharp/issues/3722)

* 允许顺序读取用于 EXIF 基础的自动方向调整。
  [#3725](https://github.com/lovell/sharp/issues/3725)

### v0.32.1 - 2023 年 4 月 27 日

* 添加实验性的 `unflatten` 操作。
  [#3461](https://github.com/lovell/sharp/pull/3461)
  [@antonmarsden](https://github.com/antonmarsden)

* 确保使用 `flip` 操作时强制使用随机访问读取（在 0.32.0 中的回归）。
  [#3600](https://github.com/lovell/sharp/issues/3600)

* 确保 `linear` 操作适用于 16 位输入（在 0.31.3 中的回归）。
  [#3605](https://github.com/lovell/sharp/issues/3605)

* 安装：确保代理 URL 被正确记录。
  [#3615](https://github.com/lovell/sharp/pull/3615)
  [@TomWis97](https://github.com/TomWis97)

* 确保无配置文件的 CMYK 到 CMYK 的往返跳过颜色空间转换。
  [#3620](https://github.com/lovell/sharp/issues/3620)

* 添加对使用非 sRGB 管道颜色空间时的 `modulate` 操作的支持。
  [#3620](https://github.com/lovell/sharp/issues/3620)

* 确保 `trim` 操作适用于 CMYK 图像（在 0.31.0 中的回归）。
  [#3636](https://github.com/lovell/sharp/issues/3636)

* 安装：将 libc 版本强制转换为 semver。
  [#3641](https://github.com/lovell/sharp/issues/3641)

### v0.32.0 - 2023 年 3 月 24 日

* 默认情况下，尽可能使用顺序读取而不是随机访问读取。

* 用 `reuse` 替换 GIF 输出的 `optimise` / `optimize` 选项。

* 为 GIF 输出添加 `progressive` 选项以进行交错。

* 为文本图像创建添加 `wrap` 选项。

* 为通过 *magick 加载的图像的元数据添加 `formatMagick` 属性。

* 优先使用整数（un）预乘法以加快 RGBA 图像的缩放。

* 添加 `ignoreIcc` 输入选项以忽略嵌入的 ICC 配置文件。

* 允许使用 GPS (IFD3) EXIF 元数据。
  [#2767](https://github.com/lovell/sharp/issues/2767)

* TypeScript 定义现在直接维护和发布，弃用 `@types/sharp` 包。
  [#3369](https://github.com/lovell/sharp/issues/3369)

* 预编译二进制文件：确保支持 macOS 10.13+，如文档所述。
  [#3438](https://github.com/lovell/sharp/issues/3438)

* 预编译二进制文件：防止使用 glib 切片分配器，提高 QEMU 支持。
  [#3448](https://github.com/lovell/sharp/issues/3448)

* 在使用基于注意力的裁剪时，将焦点坐标添加到输出中。
  [#3470](https://github.com/lovell/sharp/pull/3470)
  [@ejoebstl](https://github.com/ejoebstl)

* 将 sharp 版本公开为 `sharp.versions.sharp`。
  [#3471](https://github.com/lovell/sharp/issues/3471)

* 尊重 WebP 输入的 `fastShrinkOnLoad` 缩放选项。
  [#3516](https://github.com/lovell/sharp/issues/3516)

* 将 sharpen `sigma` 最大值从 10000 减少到 10。
  [#3521](https://github.com/lovell/sharp/issues/3521)

* 添加对 `ArrayBuffer` 输入的支持。
  [#3548](https://github.com/lovell/sharp/pull/3548)
  [@kapouer](https://github.com/kapouer)

* 为 `extend` 操作添加对 `extendWith` 的支持，允许复制/镜像/重复。
  [#3556](https://github.com/lovell/sharp/pull/3556)
  [@janaz](https://github.com/janaz)

* 确保所有异步 JS 回调都被包装以帮助避免可能的竞态条件。
  [#3569](https://github.com/lovell/sharp/issues/3569)

* 预编译二进制文件：由于许可问题，暂时移除对基于平铺的输出的支持。
  [#3581](https://github.com/lovell/sharp/issues/3581)

* 为 `normalise` 添加对 `lower` 和 `upper` 百分位数的支持。
  [#3583](https://github.com/lovell/sharp/pull/3583)
  [@LachlanNewman](https://github.com/LachlanNewman)

## v0.31 - *eagle*

需要 libvips v8.13.3

### v0.31.3 - 2022 年 12 月 21 日

* 添加对 JPEG-XL 图像的实验性支持。需要使用 libjxl 编译的 libvips。
  [#2731](https://github.com/lovell/sharp/issues/2731)

* 运行时检测 V8 内存笼，确保与 Electron 21 及更高版本的兼容性。
  [#3384](https://github.com/lovell/sharp/issues/3384)

* 公开 GIF 优化属性 `interFrameMaxError` 和 `interPaletteMaxError`。
  [#3401](https://github.com/lovell/sharp/issues/3401)

* 允许在 Linux 上安装，例如 Fedora 38 的 glibc 补丁版本。
  [#3423](https://github.com/lovell/sharp/issues/3423)

* 扩展现有 `sharpen` 参数的范围以匹配 libvips。
  [#3427](https://github.com/lovell/sharp/issues/3427)

* 防止在基于流的输入的元数据等待时出现可能的竞态条件。
  [#3451](https://github.com/lovell/sharp/issues/3451)

* 改进 `extractChannel` 对 16 位输出颜色空间的支持。
  [#3453](https://github.com/lovell/sharp/issues/3453)

* 在计算图像统计信息时忽略 `sequentialRead` 选项。
  [#3462](https://github.com/lovell/sharp/issues/3462)

* 对引入非不透明背景的操作进行小幅性能改进。
  [#3465](https://github.com/lovell/sharp/issues/3465)

* 确保 `linear` 操作的整数输出。
  [#3468](https://github.com/lovell/sharp/issues/3468)

### v0.31.2 - 2022 年 11 月 4 日

* 升级到 libvips v8.13.3 以修复上游的漏洞。

* 确保手动翻转、旋转、缩放操作顺序（在 0.31.1 中的回归）
  [#3391](https://github.com/lovell/sharp/issues/3391)

* 确保在没有缩放的情况下自动旋转正常工作（在 0.31.1 中的回归）
  [#3422](https://github.com/lovell/sharp/issues/3422)

### v0.31.1 - 2022 年 9 月 29 日

* 升级到 libvips v8.13.2 以修复上游的漏洞。

* 确保 `close` 事件在基于流的输出的 `end` 事件之后发生。
  [#3313](https://github.com/lovell/sharp/issues/3313)

* 确保 `limitInputPixels` 构造函数选项使用 uint64。
  [#3349](https://github.com/lovell/sharp/pull/3349)
  [@marcosc90](https://github.com/marcosc90)

* 确保自动旋转与加载时缩小和提取一起正常工作（在 0.31.0 中的回归）。
  [#3352](https://github.com/lovell/sharp/issues/3352)

* 确保 AVIF 输出始终为 8 位。
  [#3358](https://github.com/lovell/sharp/issues/3358)

* 确保灰度图像可以被裁剪（在 0.31.0 中的回归）。
  [#3386](https://github.com/lovell/sharp/issues/3386)

### v0.31.0 - 2022 年 9 月 5 日

* 停止支持 Node.js 12，现在需要 Node.js >= 14.15.0。

* GIF 输出现在在可能的情况下重用输入调色板。使用 `reoptimise` 选项生成新的调色板。

* 为 WebP 动画帧添加更多控制的 `minSize` 和 `mixed` 选项。

* 移除已弃用的 WebP `reductionEffort` 和 HEIF `speed` 选项。使用 `effort` 控制这些。

* `flip` 和 `flop` 操作现在将在 `rotate` 操作之前发生。

* 通过使用直方图改进 `normalise` 操作。
  [#200](https://github.com/lovell/sharp/issues/200)

* 对于 `trim` 操作，使用 alpha 和非 alpha 通道的组合边界框。
  [#2166](https://github.com/lovell/sharp/issues/2166)

* 为平铺输出添加 Buffer 和 Stream 支持。
  [#2238](https://github.com/lovell/sharp/issues/2238)

* 在 `format` 信息中添加输入 `fileSuffix` 和输出 `alias`。
  [#2642](https://github.com/lovell/sharp/issues/2642)

* 重新引入灰度 ICC 配置文件的支持（在 0.30.2 中暂时移除）。
  [#3114](https://github.com/lovell/sharp/issues/3114)

* 为 TIFF 输出添加对 WebP 和 PackBits `compression` 选项的支持。
  [#3198](https://github.com/lovell/sharp/issues/3198)

* 确保 OpenSlide 和 FITS 输入与自定义 libvips 一起正常工作。
  [#3226](https://github.com/lovell/sharp/issues/3226)

* 确保 `trim` 操作在会将图像裁剪为无内容时成为无操作。
  [#3223](https://github.com/lovell/sharp/issues/3223)

* 公开 `vips_text` 以创建包含渲染文本的图像。
  [#3252](https://github.com/lovell/sharp/pull/3252)
  [@brahima](https://github.com/brahima)

* 确保仅解析 `withMetadata` EXIF 对象拥有的属性。
  [#3292](https://github.com/lovell/sharp/issues/3292)

* 扩展 `linear` 操作以允许使用每个通道的数组。
  [#3303](https://github.com/lovell/sharp/pull/3303)
  [@antonmarsden](https://github.com/antonmarsden)

* 确保尽可能尊重 `rotate`、`resize` 和 `extend` 操作的顺序。在同一流水线中的先前调用将被忽略时发出警告。
  [#3319](https://github.com/lovell/sharp/issues/3319)

* 确保非调色板输出的 PNG bitdepth 可以设置。
  [#3322](https://github.com/lovell/sharp/issues/3322)

* 为 `trim` 添加提供特定背景颜色的选项。
  [#3332](https://github.com/lovell/sharp/pull/3332)
  [@mart-jansink](https://github.com/mart-jansink)

* 确保在合成之前对调整大小的图像进行 unpremultiply。
  [#3334](https://github.com/lovell/sharp/issues/3334)

## v0.30 - *dresser*

需要 libvips v8.12.2

### v0.30.7 - 2022 年 6 月 22 日

* 确保平铺合成始终与外部缩放一起正常工作。
  [#3227](https://github.com/lovell/sharp/issues/3227)

* 允许 WebP 编码努力为 0。
  [#3261](https://github.com/lovell/sharp/pull/3261)
  [@AlexanderTheGrey](https://github.com/AlexanderTheGrey)

* 防止通过 libwebp 进行上采样。
  [#3267](https://github.com/lovell/sharp/pull/3267)
  [@blacha](https://github.com/blacha)

### v0.30.6 - 2022 年 5 月 30 日

* 允许 `limitInputPixels` 的值大于 32 位。
  [#3238](https://github.com/lovell/sharp/issues/3238)

* 确保可以检测到通过 brew 安装的 `vips`（在 0.30.5 中的回归）。
  [#3239](https://github.com/lovell/sharp/issues/3239)

### v0.30.5 - 2022 年 5 月 23 日

* 安装：通过环境变量传递 `PKG_CONFIG_PATH` 而不是替换。
  [@dwisiswant0](https://github.com/dwisiswant0)

* 添加对 `--libc` 标志的支持，以改进跨平台安装。
  [#3160](https://github.com/lovell/sharp/pull/3160)
  [@joonamo](https://github.com/joonamo)

* 允许从文件系统安装预编译的 libvips 二进制文件。
  [#3196](https://github.com/lovell/sharp/pull/3196)
  [@ankurparihar](https://github.com/ankurparihar)

* 修复 EXIF 方向 2 的旋转-提取问题。
  [#3218](https://github.com/lovell/sharp/pull/3218)
  [@jakob0fischl](https://github.com/jakob0fischl)

### v0.30.4 - 2022 年 4 月 18 日

* 通过 `failOn` 增加对无效图像的敏感性控制，弃用 `failOnError`（等同于 `failOn: 'warning'`）。

* 确保 `create` 输入图像具有正确的位深和颜色空间。
  [#3139](https://github.com/lovell/sharp/issues/3139)

* 添加对带有 `byteOffset` 和 `length` 的 `TypedArray` 输入的支持。
  [#3146](https://github.com/lovell/sharp/pull/3146)
  [@codepage949](https://github.com/codepage949)

* 改进尝试渲染大于 32767x32767 的 SVG 输入时的错误消息。
  [#3167](https://github.com/lovell/sharp/issues/3167)

* 在 'Input file is missing' 错误消息中添加缺失的文件名。
  [#3178](https://github.com/lovell/sharp/pull/3178)
  [@Brodan](https://github.com/Brodan)

### v0.30.3 - 2022 年 3 月 14 日

* 允许更一致地将 `sharpen` 选项作为对象提供。
  [#2561](https://github.com/lovell/sharp/issues/2561)

* 公开 `sharpen` 操作的 `x1`、`y2` 和 `y3` 参数。
  [#2935](https://github.com/lovell/sharp/issues/2935)

* 防止在某些合成混合模式下出现双重 unpremultiply（在 0.30.2 中的回归）。
  [#3118](https://github.com/lovell/sharp/issues/3118)

### v0.30.2 - 2022 年 3 月 2 日

* 改进合成多张图像时的性能和准确性。
  [#2286](https://github.com/lovell/sharp/issues/2286)

* 扩展 pkgconfig 搜索路径以支持更广泛的 BSD。
  [#3106](https://github.com/lovell/sharp/issues/3106)

* 确保 Windows C++ 运行时被静态链接（在 0.30.0 中的回归）。
  [#3110](https://github.com/lovell/sharp/pull/3110)
  [@kleisauke](https://github.com/kleisauke)

* 暂时忽略灰度 ICC 配置文件以解决 lcms 漏洞。
  [#3112](https://github.com/lovell/sharp/issues/3112)

### v0.30.1 - 2022 年 2 月 9 日

* 允许在同一个实例上使用 `toBuffer` 和 `toFile`。
  [#3044](https://github.com/lovell/sharp/issues/3044)

* 跳过已知 libjpeg 四舍五入误差的加载时缩小。
  [#3066](https://github.com/lovell/sharp/issues/3066)
  [@kleisauke](https://github.com/kleisauke)

* 确保 `withoutReduction` 不会干扰 contain/crop/embed。
  [#3081](https://github.com/lovell/sharp/pull/3081)
  [@kleisauke](https://github.com/kleisauke)

* 确保仿射插值器被正确终止。
  [#3083](https://github.com/lovell/sharp/pull/3083)
  [@kleisauke](https://github.com/kleisauke)

### v0.30.0 - 2022 年 2 月 1 日

* 添加对预编译二进制文件的 GIF 输出的支持。

* 将 Linux ARM64v8 的 glibc 最低要求降低到 2.17。

* 使用 Subresource Integrity 检查验证预编译二进制文件。

* 标准化 WebP `effort` 选项名称，弃用 `reductionEffort`。

* 标准化 HEIF `effort` 选项名称，弃用 `speed`。

* 添加对 IIIF v3 平铺输出的支持。

* 公开用于调色板化 PNG 输出的 CPU 努力控制。
  [#2541](https://github.com/lovell/sharp/issues/2541)

* 改进动画（多页）图像的缩放和提取。
  [#2789](https://github.com/lovell/sharp/pull/2789)
  [@kleisauke](https://github.com/kleisauke)

* 公开供应商二进制文件的平台和架构作为 `sharp.vendor`。
  [#2928](https://github.com/lovell/sharp/issues/2928)

* 确保 16 位 PNG 输出使用正确的位深。
  [#2958](https://github.com/lovell/sharp/pull/2958)
  [@gforge](https://github.com/gforge)

* 正确发出 duplex streams 的 close 事件。
  [#2976](https://github.com/lovell/sharp/pull/2976)
  [@driannaude](https://github.com/driannaude)

* 公开 `unlimited` 选项用于 SVG 和 PNG 输入，关闭安全功能。
  [#2984](https://github.com/lovell/sharp/issues/2984)

* 添加 `withoutReduction` 选项到缩放操作。
  [#3006](https://github.com/lovell/sharp/pull/3006)
  [@christopherbradleybanks](https://github.com/christopherbradleybanks)

* 添加 `resolutionUnit` 作为 TIFF 选项并在元数据中公开。
  [#3023](https://github.com/lovell/sharp/pull/3023)
  [@ompal-sisodiya](https://github.com/ompal-sisodiya)

* 确保 rotate-then-extract 与 EXIF 镜像一起正常工作。
  [#3024](https://github.com/lovell/sharp/issues/3024)

## v0.29 - *circle*

需要 libvips v8.11.3

### v0.29.3 - 2021 年 11 月 14 日

* 确保在包含图像缩放到 1px 时的正确尺寸。
  [#2951](https://github.com/lovell/sharp/issues/2951)

* 从 `withMetadata` 提供的 `density` 推断 TIFF `xres`/`yres`。
  [#2952](https://github.com/lovell/sharp/pull/2952)
  [@mbklein](https://github.com/mbklein)

### v0.29.2 - 2021 年 10 月 21 日

* 添加 `timeout` 函数以限制处理时间。

* 确保 `sharp.versions` 从供应商 libvips 中填充。

* 从单页图像中移除动画属性。
  [#2890](https://github.com/lovell/sharp/issues/2890)

* 允许使用 'tif' 选择 TIFF 输出。
  [#2893](https://github.com/lovell/sharp/pull/2893)
  [@erf](https://github.com/erf)

* 改进 Windows 上的版本冲突错误消息。
  [#2918](https://github.com/lovell/sharp/pull/2918)
  [@dkrnl](https://github.com/dkrnl)

* 在检测到无效二进制文件时抛出错误而不是退出。
  [#2931](https://github.com/lovell/sharp/issues/2931)

### v0.29.1 - 2021 年 9 月 7 日

* 添加 `lightness` 选项到 `modulate` 操作。
  [#2846](https://github.com/lovell/sharp/pull/2846)

* 确保根据颜色数量设置正确的 PNG bitdepth。
  [#2855](https://github.com/lovell/sharp/issues/2855)

* 确保在合成时背景始终为 premultiplied。
  [#2858](https://github.com/lovell/sharp/issues/2858)

* 确保具有 P3 配置文件的图像保留全色域。
  [#2862](https://github.com/lovell/sharp/issues/2862)

* 添加对使用 OpenJPEG 编译的 libvips 的支持。
  [#2868](https://github.com/lovell/sharp/pull/2868)

* 从 AVIF 输出中移除不受支持的动画属性。
  [#2870](https://github.com/lovell/sharp/issues/2870)

* 在比较输入/输出文件名之前解析路径。
  [#2878](https://github.com/lovell/sharp/pull/2878)
  [@rexxars](https://github.com/rexxars)

* 允许在 HEIF 编码中使用速度 9（最快）。
  [#2879](https://github.com/lovell/sharp/pull/2879)
  [@rexxars](https://github.com/rexxars)

### v0.29.0 - 2021 年 8 月 17 日

* 停止支持 Node.js 10，现在需要 Node.js >= 12.13.0。

* 添加 PNG 和 GIF 图像元数据的 `background` 属性。

* 添加 HEIF 图像元数据的 `compression` 属性。
  [#2504](https://github.com/lovell/sharp/issues/2504)

* AVIF 编码现在默认使用 `4:4:4` 色度子采样。
  [#2562](https://github.com/lovell/sharp/issues/2562)

* 允许在同一个 `node_modules` 安装树中使用多个平台-架构二进制文件。
  [#2575](https://github.com/lovell/sharp/issues/2575)

* 当使用 `extractChannel` 时，默认使用单通道 `b-w` 空间。
  [#2658](https://github.com/lovell/sharp/issues/2658)

* 允许安装目录中包含空格（在 v0.26.0 中的回归）。
  [#2777](https://github.com/lovell/sharp/issues/2777)

* 添加 `pipelineColourspace` 操作以设置处理空间。
  [#2704](https://github.com/lovell/sharp/pull/2704)
  [@Daiz](https://github.com/Daiz)

* 允许在原始输入和输出时设置位深。
  [#2762](https://github.com/lovell/sharp/pull/2762)
  [@mart-jansink](https://github.com/mart-jansink)

* 允许 `negate` 仅作用于非 alpha 通道。
  [#2808](https://github.com/lovell/sharp/pull/2808)
  [@rexxars](https://github.com/rexxars)

## v0.28 - *bijou*

需要 libvips v8.10.6

### v0.28.3 - 2021 年 5 月 24 日

* 在调用 node-gyp 之前确保存在 libvips，无论是供应商的还是全局的。

* 跳过多页 WebP 的加载时缩小。
  [#2714](https://github.com/lovell/sharp/issues/2714)

* 添加对比度限制自适应直方图均衡化（CLAHE）操作。
  [#2726](https://github.com/lovell/sharp/pull/2726)
  [@baparham](https://github.com/baparham)

### v0.28.2 - 2021 年 5 月 10 日

* 允许 `withMetadata` 设置 `density`。
  [#967](https://github.com/lovell/sharp/issues/967)

* 在一个维度小于 4px 时跳过加载时缩小。
  [#2653](https://github.com/lovell/sharp/issues/2653)

* 允许转义代理凭据。
  [#2664](https://github.com/lovell/sharp/pull/2664)
  [@msalettes](https://github.com/msalettes)

* 添加 `premultiplied` 标志用于原始像素数据输入。
  [#2685](https://github.com/lovell/sharp/pull/2685)
  [@mnutt](https://github.com/mnutt)

* 检测空输入并抛出有用的错误。
  [#2687](https://github.com/lovell/sharp/pull/2687)
  [@JakobJingleheimer](https://github.com/JakobJingleheimer)

* 添加安装时标志以跳过版本兼容性检查。
  [#2692](https://github.com/lovell/sharp/pull/2692)
  [@xemle](https://github.com/xemle)

### v0.28.1 - 2021 年 4 月 5 日

* 确保所有安装错误都带有更明显的前缀。

* 允许 `withMetadata` 设置和更新 EXIF 元数据。
  [#650](https://github.com/lovell/sharp/issues/650)

* 添加对 OME-TIFF 子图像文件目录（subIFD）的支持。
  [#2557](https://github.com/lovell/sharp/issues/2557)

* 允许 `ensureAlpha` 设置 alpha 透明度级别。
  [#2634](https://github.com/lovell/sharp/issues/2634)

### v0.28.0 - 2021 年 3 月 29 日

* 预编译二进制文件现在包括 mozjpeg 和 libimagequant（BSD 2-Clause）。

* 预编译二进制文件将 AVIF 支持限制为最常见的 8 位深度。

* 添加 `jpeg` 方法的 `mozjpeg` 选项，设置 mozjpeg 默认值。

* 将默认 PNG `compressionLevel` 减少到更常用的 6。

* 在使用默认内存分配器的 glibc-based Linux 上减少并发，以帮助防止碎片化。

* 将 extend 操作的缺失边缘属性默认为零。
  [#2578](https://github.com/lovell/sharp/issues/2578)

* 确保合成不会裁剪顶部和左侧偏移。
  [#2594](https://github.com/lovell/sharp/pull/2594)
  [@SHG42](https://github.com/SHG42)

* 改进安装时网络故障的错误处理。
  [#2608](https://github.com/lovell/sharp/pull/2608)
  [@abradley](https://github.com/abradley)

* 确保 `@id` 属性可以为 IIIF 平铺输出设置。
  [#2612](https://github.com/lovell/sharp/issues/2612)
  [@edsilv](https://github.com/edsilv)

* 确保合成在居中重力下复制正确数量的平铺。
  [#2626](https://github.com/lovell/sharp/issues/2626)

## v0.27 - *avif*

需要 libvips v8.10.5

### v0.27.2 - 2021 年 2 月 22 日

* macOS：防止在 Rosetta x64 仿真下使用全局安装的 ARM64 libvips。
  [#2460](https://github.com/lovell/sharp/issues/2460)

* Linux (musl)：防止在 musl >= 1.2.0 时使用预编译的 linuxmusl-x64 二进制文件。
  [#2570](https://github.com/lovell/sharp/issues/2570)

* 通过使用 libvips 的 `has_alpha` 检测改进 16 位灰度+alpha 支持。
  [#2569](https://github.com/lovell/sharp/issues/2569)

* 允许 `toFormat` 使用非小写扩展名。
  [#2581](https://github.com/lovell/sharp/pull/2581)
  [@florian-busch](https://github.com/florian-busch)

* 允许 `recomb` 操作使用单通道输入。
  [#2584](https://github.com/lovell/sharp/issues/2584)

### v0.27.1 - 2021 年 1 月 27 日

* 确保在使用浮点预测器时进行类型转换。
  [#2502](https://github.com/lovell/sharp/pull/2502)
  [@randyridge](https://github.com/randyridge)

* 添加对 Uint8Array 和 Uint8ClampedArray 输入的支持。
  [#2511](https://github.com/lovell/sharp/pull/2511)
  [@leon](https://github.com/leon)

* 反转：确保所有平台都使用 fontconfig 进行字体渲染。
  [#2515](https://github.com/lovell/sharp/issues/2515)

* 公开 libvips gaussnoise 操作以允许创建高斯噪声。
  [#2527](https://github.com/lovell/sharp/pull/2527)
  [@alza54](https://github.com/alza54)

### v0.27.0 - 2020 年 12 月 22 日

* 添加对预编译二进制文件的 AVIF 支持。

* 移除 `heif` 输出的实验性状态，现在默认以 AVIF 为中心。

* 允许合成操作使用负的顶部/左侧偏移。
  [#2391](https://github.com/lovell/sharp/pull/2391)
  [@CurosMJ](https://github.com/CurosMJ)

* 确保所有平台都使用 fontconfig 进行字体渲染。
  [#2399](https://github.com/lovell/sharp/issues/2399)

## v0.26 - *zoom*

需要 libvips v8.10.0

### v0.26.3 - 2020 年 11 月 16 日

* 公开 libvips 的仿射操作。
  [#2336](https://github.com/lovell/sharp/pull/2336)
  [@guillevc](https://github.com/guillevc)

* 如果不可用 Brotli，则回退到 tar.gz 用于预编译 libvips。
  [#2412](https://github.com/lovell/sharp/pull/2412)
  [@ascorbic](https://github.com/ascorbic)

### v0.26.2 - 2020 年 10 月 14 日

* 添加对 EXR 输入的支持。需要使用 OpenEXR 编译的 libvips。
  [#698](https://github.com/lovell/sharp/issues/698)

* 确保支持 yarn v2。
  [#2379](https://github.com/lovell/sharp/pull/2379)
  [@jalovatt](https://github.com/jalovatt)

* 添加平铺输出的中心/居中选项。
  [#2397](https://github.com/lovell/sharp/pull/2397)
  [@beig](https://github.com/beig)

### v0.26.1 - 2020 年 9 月 20 日

* 确保在验证多页图像尺寸时正确的 pageHeight。
  [#2343](https://github.com/lovell/sharp/pull/2343)
  [@derom](https://github.com/derom)

* 允许输入密度范围达到 100000 DPI。
  [#2348](https://github.com/lovell/sharp/pull/2348)
  [@stefanprobst](https://github.com/stefanprobst)

* 确保动画相关的属性可以用于基于流的输入。
  [#2369](https://github.com/lovell/sharp/pull/2369)
  [@AcrylicShrimp](https://github.com/AcrylicShrimp)

* 确保 `stats` 可以计算 1x1 输入。
  [#2372](https://github.com/lovell/sharp/issues/2372)

* 确保动画 GIF 输出经过优化。
  [#2376](https://github.com/lovell/sharp/issues/2376)

### v0.26.0 - 2020 年 8 月 25 日

* 预编译的 libvips 二进制文件现在是静态链接并使用 Brotli 压缩，需要 Node.js 10.16.0+。

* TIFF 输出的 `squash` 被 `bitdepth` 替换，以减少到 1、2 或 4 位。

* JPEG 输出的 `quality` >= 90 不再自动将 `chromaSubsampling` 设置为 `4:4:4`。

* 添加图像 `stats` 中的最主导颜色。
  [#640](https://github.com/lovell/sharp/issues/640)

* 添加对动画 GIF（需要 \*magick）和 WebP 输出的支持。
  [#2012](https://github.com/lovell/sharp/pull/2012)
  [@deftomat](https://github.com/deftomat)

* 添加对 libvips ImageMagick v7 加载器的支持。
  [#2258](https://github.com/lovell/sharp/pull/2258)
  [@vouillon](https://github.com/vouillon)

* 允许通过 \*magick 使用多页输入。
  [#2259](https://github.com/lovell/sharp/pull/2259)
  [@vouillon](https://github.com/vouillon)

* 添加 `withMetadata` 对自定义 ICC 配置文件的支持。
  [#2271](https://github.com/lovell/sharp/pull/2271)
  [@roborourke](https://github.com/roborourke)

* 确保在使用 Electron 时，ARM 的预编译二进制文件默认使用 v7。
  [#2292](https://github.com/lovell/sharp/pull/2292)
  [@diegodev3](https://github.com/diegodev3)

## v0.25 - *yield*

需要 libvips v8.9.1

### v0.25.4 - 2020 年 6 月 12 日

* 允许在版本附加时覆盖 libvips 二进制文件位置。
  [#2217](https://github.com/lovell/sharp/pull/2217)
  [@malice00](https://github.com/malice00)

* 启用 PNG 调色板，当设置质量、颜色、颜色或抖动时。
  [#2226](https://github.com/lovell/sharp/pull/2226)
  [@romaleev](https://github.com/romaleev)

* 添加 `level` 构造函数选项以使用多级图像的特定级别。
  公开多级图像的 `levels` 元数据。
  [#2222](https://github.com/lovell/sharp/issues/2222)

* 添加对 `extractChannel` 操作的命名 `alpha` 通道的支持。
  [#2138](https://github.com/lovell/sharp/issues/2138)

* 添加实验性的 `sharpness` 计算到 `stats()` 响应。
  [#2251](https://github.com/lovell/sharp/issues/2251)

* 发出 `warning` 事件以处理非关键的处理问题。
  [#2032](https://github.com/lovell/sharp/issues/2032)

### v0.25.3 - 2020 年 5 月 17 日

* 确保 libvips 仅初始化一次，提高 worker 线程安全性。
  [#2143](https://github.com/lovell/sharp/issues/2143)

* 确保 npm 平台标志在复制 DLL 时被尊重。
  [#2188](https://github.com/lovell/sharp/pull/2188)
  [@dimadeveatii](https://github.com/dimadeveatii)

* 允许解析带有内联图像的 SVG 输入。
  [#2195](https://github.com/lovell/sharp/issues/2195)

### v0.25.2 - 2020 年 3 月 20 日

* 为 Linux ARM64v8 提供预编译二进制文件。

* 添加 IIIF 布局支持到平铺输出。
  [#2098](https://github.com/lovell/sharp/pull/2098)
  [@edsilv](https://github.com/edsilv)

* 确保输入选项被一致且正确地检测。
  [#2118](https://github.com/lovell/sharp/issues/2118)

* 确保 N-API 预编译二进制文件在 RHEL7 及其衍生版本上工作。
  [#2119](https://github.com/lovell/sharp/issues/2119)

* 确保 AsyncWorker 选项被持久化。
  [#2130](https://github.com/lovell/sharp/issues/2130)

### v0.25.1 - 2020 年 3 月 7 日

* 确保预编译二进制文件根据 N-API 版本被获取。
  [#2117](https://github.com/lovell/sharp/issues/2117)

### v0.25.0 - 2020 年 3 月 7 日

* 移除之前在 v0.24.0 中弃用的 `limitInputPixels` 和 `sequentialRead`。

* 将内部迁移到 N-API。
  [#1282](https://github.com/lovell/sharp/issues/1282)

* 添加对 32 位 Windows 的支持。
  [#2088](https://github.com/lovell/sharp/issues/2088)

* 确保 rotate-then-trim 操作的正确顺序。
  [#2087](https://github.com/lovell/sharp/issues/2087)

* 确保 composite 接受 `limitInputPixels` 和 `sequentialRead` 输入选项。
  [#2099](https://github.com/lovell/sharp/issues/2099)

## v0.24 - "*wit*"

需要 libvips v8.9.0。

### v0.24.1 - 2020 年 2 月 15 日

* 防止在基于 EXIF 的旋转操作中使用 sequentialRead。
  [#2042](https://github.com/lovell/sharp/issues/2042)

* 确保 RGBA LZW TIFF 返回正确的通道数量。
  [#2064](https://github.com/lovell/sharp/issues/2064)

### v0.24.0 - 2020 年 1 月 16 日

* 停止支持 Node.js 8。
  [#1910](https://github.com/lovell/sharp/issues/1910)

* 停止支持在提供选项的情况下使用未定义的输入。
  [#1768](https://github.com/lovell/sharp/issues/1768)

* 将 `limitInputPixels` 和 `sequentialRead` 移到输入选项，弃用同名函数。

* 公开动画图像的 `delay` 和 `loop` 元数据。
  [#1905](https://github.com/lovell/sharp/issues/1905)

* 确保 16 位、2 通道 PNG 输入带有 ICC 配置文件的正确颜色输出。
  [#2013](https://github.com/lovell/sharp/issues/2013)

* 防止在旋转操作中使用 sequentialRead。
  [#2016](https://github.com/lovell/sharp/issues/2016)

* 正确绑定在使用 withoutEnlargement 时的最大宽度和高度值。
  [#2024](https://github.com/lovell/sharp/pull/2024)
  [@BrychanOdlum](https://github.com/BrychanOdlum)

* 添加对带有 16 位 RGB 配置文件的输入的支持。
  [#2037](https://github.com/lovell/sharp/issues/2037)

## v0.23 - "*vision*"

需要 libvips v8.8.1。

### v0.23.4 - 2019 年 12 月 5 日

* 在使用 Node.js v13.2.0+ 时处理零长度 Buffer 对象。

* 公开原始 TIFFTAG_PHOTOSHOP 元数据。
  [#1600](https://github.com/lovell/sharp/issues/1600)

* 通过在更新元数据时使用写时复制改进线程安全性。
  [#1986](https://github.com/lovell/sharp/issues/1986)

### v0.23.3 - 2019 年 11 月 17 日

* 确保 `trim` 操作支持包含在 alpha 通道中的图像。
  [#1597](https://github.com/lovell/sharp/issues/1597)

* 确保平铺 `overlap` 选项按预期工作。
  [#1921](https://github.com/lovell/sharp/pull/1921)
  [@rustyguts](https://github.com/rustyguts)

* 允许在 FreeBSD 及其变体上进行编译（自 v0.23.0 以来已损坏）
  [#1952](https://github.com/lovell/sharp/pull/1952)
  [@pouya-eghbali](https://github.com/pouya-eghbali)

* 确保 `modulate` 和其他基于颜色的操作可以共存。
  [#1958](https://github.com/lovell/sharp/issues/1958)

### v0.23.2 - 2019 年 10 月 28 日

* 添加 `background` 选项到平铺输出操作。
  [#1924](https://github.com/lovell/sharp/pull/1924)
  [@neave](https://github.com/neave)

* 添加对 Node.js 13 的支持。
  [#1932](https://github.com/lovell/sharp/pull/1932)
  [@MayhemYDG](https://github.com/MayhemYDG)

### v0.23.1 - 2019 年 9 月 26 日

* 确保 `sharp.format.vips` 存在且正确（仅限文件系统）。
  [#1813](https://github.com/lovell/sharp/issues/1813)

* 确保在 `resize` 中提供无效的 `width` 和 `height` 选项时抛出错误。
  [#1817](https://github.com/lovell/sharp/issues/1817)

* 允许在 `toFormat` 中使用 'heic' 和 'heif' 标识符。
  [#1834](https://github.com/lovell/sharp/pull/1834)
  [@jaubourg](https://github.com/jaubourg)

* 添加 `premultiplied` 选项到 `composite` 操作。
  [#1835](https://github.com/lovell/sharp/pull/1835)
  [@Andargor](https://github.com/Andargor)

* 允许在不同的 `toBuffer` 选项下重用实例。
  [#1860](https://github.com/lovell/sharp/pull/1860)
  [@RaboliotTheGrey](https://github.com/RaboliotTheGrey)

* 确保在尝试 trim 操作之前图像至少为 3x3 像素。

### v0.23.0 - 2019 年 7 月 29 日

* 移除之前在 v0.22.0 中弃用的 `overlayWith`。

* 添加对 HEIF 图像的实验性支持。需要使用 libheif 编译的 libvips。
  [#1105](https://github.com/lovell/sharp/issues/1105)

* 公开 libwebp 的 `smartSubsample` 和 `reductionEffort` 选项。
  [#1545](https://github.com/lovell/sharp/issues/1545)

* 添加对 Worker Threads 的实验性支持。
  [#1558](https://github.com/lovell/sharp/issues/1558)

* 在需要时使用 libvips 内置的 CMYK 和 sRGB 配置文件。
  [#1619](https://github.com/lovell/sharp/issues/1619)

* 停止支持 Node.js 版本 6 和 11。
  [#1674](https://github.com/lovell/sharp/issues/1674)

* 公开平铺输出的 `skipBlanks` 选项。
  [#1687](https://github.com/lovell/sharp/pull/1687)
  [@RaboliotTheGrey](https://github.com/RaboliotTheGrey)

* 允许在基于流的输入中使用 `failOnError` 选项。
  [#1691](https://github.com/lovell/sharp/issues/1691)

* 修复非 90 角度的旋转/提取顺序。
  [#1755](https://github.com/lovell/sharp/pull/1755)
  [@iovdin](https://github.com/iovdin)

## v0.22 - "*uptake*"

需要 libvips v8.7.4。

### v0.22.1 - 2019 年 4 月 25 日

* 添加 `modulate` 操作以调整亮度、饱和度和色调。
  [#1601](https://github.com/lovell/sharp/pull/1601)
  [@Goues](https://github.com/Goues)

* 改进帮助消息，以防 `require("sharp")` 失败。
  [#1638](https://github.com/lovell/sharp/pull/1638)
  [@sidharthachatterjee](https://github.com/sidharthachatterjee)

* 添加对 Node 12 的支持。
  [#1668](https://github.com/lovell/sharp/issues/1668)

### v0.22.0 - 2019 年 3 月 18 日

* 移除之前在 v0.21.0 中弃用的函数：
    `background`、`crop`、`embed`、`ignoreAspectRatio`、`max`、`min` 和 `withoutEnlargement`。

* 添加支持多个图像和混合模式的 `composite` 操作；弃用 `overlayWith`。
  [#728](https://github.com/lovell/sharp/issues/728)

* 添加对多页输入的 `pages` 输入选项的支持。
  [#1566](https://github.com/lovell/sharp/issues/1566)

* 允许基于流的原始像素数据输入。
  [#1579](https://github.com/lovell/sharp/issues/1579)

* 添加对 GIF 和 PDF 的 `page` 输入选项的支持。
  [#1595](https://github.com/lovell/sharp/pull/1595)
  [@ramiel](https://github.com/ramiel)

## v0.21 - "*teeth*"

需要 libvips v8.7.0。

### v0.21.3 - 2019 年 1 月 19 日

* 输入图像解码现在快速失败，可以通过设置 `failOnError` 来更改此行为。

* 失败的基于文件系统的输入现在将缺少文件和无效格式错误分开。
  [#1542](https://github.com/lovell/sharp/issues/1542)

### v0.21.2 - 2019 年 1 月 13 日

* 确保除非使用 `withMetadata`，否则 PNG 输出中所有元数据都被移除。

* 确保在调整大小后最短边至少为一个像素。
  [#1003](https://github.com/lovell/sharp/issues/1003)

* 添加 `ensureAlpha` 操作以在缺失时添加 alpha 通道。
  [#1153](https://github.com/lovell/sharp/issues/1153)

* 公开多页输入图像的 `pages` 和 `pageHeight` 元数据。
  [#1205](https://github.com/lovell/sharp/issues/1205)

* 公开需要 libimagequant 的 PNG 输出选项。
  [#1484](https://github.com/lovell/sharp/issues/1484)

* 公开无效输入的底层错误消息。
  [#1505](https://github.com/lovell/sharp/issues/1505)

* 防止传递给 `jpeg` 的选项被修改。
  [#1516](https://github.com/lovell/sharp/issues/1516)

* 确保在输出链中正确应用强制输出格式。
  [#1528](https://github.com/lovell/sharp/issues/1528)

### v0.21.1 - 2018 年 12 月 7 日

* 安装：支持 `sharp_dist_base_url` npm 配置，类似于现有的 `SHARP_DIST_BASE_URL`。
  [#1422](https://github.com/lovell/sharp/pull/1422)
  [@SethWen](https://github.com/SethWen)

* 确保原始、灰度输出的 `channel` 元数据正确。
  [#1425](https://github.com/lovell/sharp/issues/1425)

* 添加对图像缩减的 "mitchell" 内核的支持。
  [#1438](https://github.com/lovell/sharp/pull/1438)
  [@Daiz](https://github.com/Daiz)

* 允许分别设置伽马编码和解码的参数。
  [#1439](https://github.com/lovell/sharp/pull/1439)
  [@Daiz](https://github.com/Daiz)

* 使用 `Object.assign` 构建原型以允许压缩。
  [#1475](https://github.com/lovell/sharp/pull/1475)
  [@jaubourg](https://github.com/jaubourg)

* 公开 libvips 的重组矩阵操作。
  [#1477](https://github.com/lovell/sharp/pull/1477)
  [@fromkeith](https://github.com/fromkeith)

* 公开 libvips 的金字塔/平铺选项用于 TIFF 输出。
  [#1483](https://github.com/lovell/sharp/pull/1483)
  [@mbklein](https://github.com/mbklein)

### v0.21.0 - 2018 年 10 月 4 日

* 弃用以下与调整大小相关的函数：
    `crop`、`embed`、`ignoreAspectRatio`、`max`、`min` 和 `withoutEnlargement`。
  现在可以通过传递给 `resize` 函数的选项来访问这些函数。
  例如：
    `embed('north')` 现在是 `resize(width, height, { fit: 'contain', position: 'north' })`，
    `crop('attention')` 现在是 `resize(width, height, { fit: 'cover', position: 'attention' })`，
    `max().withoutEnlargement()` 现在是 `resize(width, height, { fit: 'inside', withoutEnlargement: true })`。
  [相关议题 #1135](https://github.com/lovell/sharp/issues/1135)

* 弃用 `background` 函数。
  每个操作的 `background` 选项已添加到 `resize`、`extend` 和 `flatten` 操作中。
  [相关议题 #1392](https://github.com/lovell/sharp/issues/1392)

* 在 `metadata` 响应中添加 `size`（仅限 Stream 和 Buffer 输入）。
  [相关议题 #695](https://github.com/lovell/sharp/issues/695)

* 从自定义的裁剪操作切换到 `vips_find_trim`。
  [相关议题 #914](https://github.com/lovell/sharp/issues/914)

* 在 `metadata` 响应中添加 `chromaSubsampling` 和 `isProgressive` 属性。
  [相关议题 #1186](https://github.com/lovell/sharp/issues/1186)

* 停止支持 Node 4。
  [相关议题 #1212](https://github.com/lovell/sharp/issues/1212)

* 默认启用 SIMD 卷积。
  [相关议题 #1213](https://github.com/lovell/sharp/issues/1213)

* 为基于 musl 的 Linux 添加实验性的预编译二进制文件。
  [相关议题 #1379](https://github.com/lovell/sharp/issues/1379)

* 通过 `vips_rotate` 支持任意旋转角度。
  [相关议题 #1385](https://github.com/lovell/sharp/pull/1385)
  [作者：freezy](https://github.com/freezy)

## v0.20 - "*prebuild*"

需要 libvips v8.6.1。

### v0.20.8 - 2018 年 9 月 5 日

* 在安装过程中创建目录时避免竞态条件。
  [相关议题 #1358](https://github.com/lovell/sharp/pull/1358)
  [作者：ajhool](https://github.com/ajhool)

* 接受输入密度参数的浮点值。
  [相关议题 #1362](https://github.com/lovell/sharp/pull/1362)
  [作者：aeirola](https://github.com/aeirola)

### v0.20.7 - 2018 年 8 月 21 日

* 如果重命名操作在安装过程中失败，则使用 copy+unlink。
  [相关议题 #1345](https://github.com/lovell/sharp/issues/1345)

### v0.20.6 - 2018 年 8 月 20 日

* 添加 `removeAlpha` 操作以移除 alpha 通道（如果存在）。
  [相关议题 #1248](https://github.com/lovell/sharp/issues/1248)

* 公开 mozjpeg 的 `quant_table` 标志。
  [相关议题 #1285](https://github.com/lovell/sharp/pull/1285)
  [作者：rexxars](https://github.com/rexxars)

* 允许 WebP 的 `alphaQuality` 范围为 0-100。
  [相关议题 #1290](https://github.com/lovell/sharp/pull/1290)
  [作者：sylvaindumont](https://github.com/sylvaindumont)

* 缓存 libvips 二进制文件以减少重新安装的时间。
  [相关议题 #1301](https://github.com/lovell/sharp/issues/1301)

* 确保供应商平台不匹配时在安装时抛出错误。
  [相关议题 #1303](https://github.com/lovell/sharp/issues/1303)

* 改进 FreeBSD 用户的安装错误消息。
  [相关议题 #1310](https://github.com/lovell/sharp/issues/1310)

* 确保 `extractChannel` 支持 16 位图像。
  [相关议题 #1330](https://github.com/lovell/sharp/issues/1330)

* 公开平铺输出的 `depth` 选项。
  [相关议题 #1342](https://github.com/lovell/sharp/pull/1342)
  [作者：alundavies](https://github.com/alundavies)

* 添加统计响应中的实验性熵字段。

### v0.20.5 - 2018 年 6 月 27 日

* 公开 libjpeg 的 `optimize_coding` 标志。
  [相关议题 #1265](https://github.com/lovell/sharp/pull/1265)
  [作者：tomlokhorst](https://github.com/tomlokhorst)

### v0.20.4 - 2018 年 6 月 20 日

* 防止在使用 `shrink-on-load` 和 90/270 度旋转时可能出现的舍入错误。
  [相关议题 #1241](https://github.com/lovell/sharp/issues/1241)
  [作者：anahit42](https://github.com/anahit42)

* 确保 `extractChannel` 设置正确的单通道颜色空间解释。
  [相关议题 #1257](https://github.com/lovell/sharp/issues/1257)
  [作者：jeremychone](https://github.com/jeremychone)

### v0.20.3 - 2018 年 5 月 29 日

* 修复色调操作，确保 LAB 解释并允许负值。
  [相关议题 #1235](https://github.com/lovell/sharp/issues/1235)
  [作者：wezside](https://github.com/wezside)

### v0.20.2 - 2018 年 4 月 28 日

* 添加色调操作以设置图像的色度。
  [相关议题 #825](https://github.com/lovell/sharp/pull/825)
  [作者：rikh42](https://github.com/rikh42)

* 添加环境变量以忽略全局安装的 libvips。
  [相关议题 #1165](https://github.com/lovell/sharp/pull/1165)
  [作者：oncletom](https://github.com/oncletom)

* 添加对多页输入（GIF/TIFF）的页面选择支持。
  [相关议题 #1204](https://github.com/lovell/sharp/pull/1204)
  [作者：woolite64](https://github.com/woolite64)

* 添加对 TIFF 输出的 Group4 (CCITTFAX4) 压缩支持。
  [相关议题 #1208](https://github.com/lovell/sharp/pull/1208)
  [作者：woolite64](https://github.com/woolite64)

### v0.20.1 - 2018 年 3 月 17 日

* 改进安装体验，当检测到低于最低要求版本的全局安装 libvips 时。
  [相关议题 #1148](https://github.com/lovell/sharp/issues/1148)

* 防止在累积舍入低于目标大小时出现 smartcrop 错误。
  [相关议题 #1154](https://github.com/lovell/sharp/issues/1154)
  [作者：ralrom](https://github.com/ralrom)

* 公开 libvips 的中值滤波操作。
  [相关议题 #1161](https://github.com/lovell/sharp/pull/1161)
  [作者：BiancoA](https://github.com/BiancoA)

### v0.20.0 - 2018 年 3 月 5 日

* 添加对常见平台上预编译 sharp 二进制文件的支持。
  [相关议题 #186](https://github.com/lovell/sharp/issues/186)

## v0.19 - "*suit*"

需要 libvips v8.6.1。

### v0.19.1 - 2018 年 2 月 24 日

* 公开 libvips 的线性变换功能。
  [相关议题 #1024](https://github.com/lovell/sharp/pull/1024)
  [作者：3epnm](https://github.com/3epnm)

* 公开平铺输出的角度选项。
  [相关议题 #1121](https://github.com/lovell/sharp/pull/1121)
  [作者：BiancoA](https://github.com/BiancoA)

* 防止在图像已达到或低于目标尺寸时进行裁剪操作。
  [相关议题 #1134](https://github.com/lovell/sharp/issues/1134)
  [作者：pieh](https://github.com/pieh)

### v0.19.0 - 2018 年 1 月 11 日

* 公开基于策略的裁剪的偏移坐标。
  [相关议题 #868](https://github.com/lovell/sharp/issues/868)
  [作者：mirohristov-com](https://github.com/mirohristov-com)

* PNG 输出现在默认为 `adaptiveFiltering=false`，`compressionLevel=9`。
  [相关议题 #872](https://github.com/lovell/sharp/issues/872)
  [作者：wmertens](https://github.com/wmertens)

* 添加统计功能以获取基于像素的图像统计信息。
  [相关议题 #915](https://github.com/lovell/sharp/pull/915)
  [作者：rnanwani](https://github.com/rnanwani)

* 添加 `failOnError` 选项以在输入图像数据错误时快速失败。
  [相关议题 #976](https://github.com/lovell/sharp/pull/976)
  [作者：mceachen](https://github.com/mceachen)

* 调整大小：切换到 libvips 的实现，使 `fastShrinkOnLoad` 可选，移除 `interpolator` 和 `centreSampling` 选项。
  [相关议题 #977](https://github.com/lovell/sharp/pull/977)
  [作者：jardakotesovec](https://github.com/jardakotesovec)

* 仅对基于流的输入的克隆附加完成事件监听器。
  [相关议题 #995](https://github.com/lovell/sharp/issues/995)
  [作者：whmountains](https://github.com/whmountains)

* 在 smartcrop 之前添加 tilecache 以避免之前操作的过度计算。
  [相关议题 #1028](https://github.com/lovell/sharp/issues/1028)
  [作者：coffeebite](https://github.com/coffeebite)

* 防止 `toFile` 扩展名优先于请求的格式。
  [相关议题 #1037](https://github.com/lovell/sharp/issues/1037)
  [作者：tomgallagher](https://github.com/tomgallagher)

* 添加对现有嵌入功能的 `gravity` 选项支持。
  [相关议题 #1038](https://github.com/lovell/sharp/pull/1038)
  [作者：AzureByte](https://github.com/AzureByte)

* 在可用时公开 IPTC 和 XMP 元数据。
  [相关议题 #1079](https://github.com/lovell/sharp/pull/1079)
  [作者：oaleynik](https://github.com/oaleynik)

* TIFF 输出：将默认预测器从 'none' 切换为 'horizontal' 以匹配 libvips 的行为。

## v0.18 - "*ridge*"

需要 libvips v8.5.5。

### v0.18.4 - 2017 年 9 月 18 日

* 确保输入 Buffer 真正被标记为持久化，防止标记清除垃圾回收。
  [相关议题 #950](https://github.com/lovell/sharp/issues/950)
  [作者：lfdoherty](https://github.com/lfdoherty)

### v0.18.3 - 2017 年 9 月 13 日

* 在裁剪时跳过 `shrink-on-load`。
  [相关议题 #888](https://github.com/lovell/sharp/pull/888)
  [作者：kleisauke](https://github.com/kleisauke)

* 从 got 迁移到 simple-get 以支持基本身份验证。
  [相关议题 #945](https://github.com/lovell/sharp/pull/945)
  [作者：pbomb](https://github.com/pbomb)

### v0.18.2 - 2017 年 7 月 1 日

* 公开 libvips 的 xres 和 yres 属性用于 TIFF 输出。
  [相关议题 #828](https://github.com/lovell/sharp/pull/828)
  [作者：YvesBos](https://github.com/YvesBos)

* 确保 flip 和 flop 操作与自动旋转一起正常工作。
  [相关议题 #837](https://github.com/lovell/sharp/issues/837)
  [作者：rexxars](https://github.com/rexxars)

* 允许通过 SHARP_DIST_BASE_URL 环境变量覆盖二进制下载 URL。
  [相关议题 #841](https://github.com/lovell/sharp/issues/841)

* 添加对 Solus Linux 的支持。
  [相关议题 #857](https://github.com/lovell/sharp/pull/857)
  [作者：ekremkaraca](https://github.com/ekremkaraca)

### v0.18.1 - 2017 年 5 月 30 日

* 移除可能导致不正确缩小计算的回归（来自 #781）。
  [相关议题 #831](https://github.com/lovell/sharp/issues/831)
  [作者：suprMax](https://github.com/suprMax)

### v0.18.0 - 2017 年 5 月 30 日

* 移除之前弃用的输出格式 "option" 函数：
    `quality`、`progressive`、`compressionLevel`、`withoutAdaptiveFiltering`、
    `withoutChromaSubsampling`、`trellisQuantisation`、`trellisQuantization`、
    `overshootDeringing`、`optimiseScans` 和 `optimizeScans`。
  现在可以通过输出格式函数访问这些函数，例如 `quality(n)` 现在是 `jpeg({quality: n})` 和/或 `webp({quality: n})`。

* 确保最大输出尺寸基于要使用的格式。
  [相关议题 #176](https://github.com/lovell/sharp/issues/176)
  [作者：stephanebachelier](https://github.com/stephanebachelier)

* 避免在不进行调整大小/合成时进行昂贵的 (un)premultiply 操作。
  [相关议题 #573](https://github.com/lovell/sharp/issues/573)
  [作者：strarsis](https://github.com/strarsis)

* 在读取元数据时包括像素深度（例如 "uchar"）。
  [相关议题 #577](https://github.com/lovell/sharp/issues/577)
  [作者：moedusa](https://github.com/moedusa)

* 添加对基于 Buffer 和 Stream 的 TIFF 输出的支持。
  [相关议题 #587](https://github.com/lovell/sharp/issues/587)
  [作者：strarsis](https://github.com/strarsis)

* 通过 NODE_DEBUG=sharp 环境变量公开 libvips 的警告。
  [相关议题 #607](https://github.com/lovell/sharp/issues/607)
  [作者：puzrin](https://github.com/puzrin)

* 切换到 libvips 的 "attention" 和 "entropy" 裁剪策略的实现。
  [相关议题 #727](https://github.com/lovell/sharp/issues/727)

* 改进最近邻积分上采样的性能和准确性。
  [相关议题 #752](https://github.com/lovell/sharp/issues/752)
  [作者：MrIbby](https://github.com/MrIbby)

* 构造函数单参数 API：允许普通对象，拒绝 null/undefined。
  [相关议题 #768](https://github.com/lovell/sharp/issues/768)
  [作者：kub1x](https://github.com/kub1x)

* 确保 ARM64 预编译二进制文件使用正确的 C++11 ABI 版本。
  [相关议题 #772](https://github.com/lovell/sharp/issues/772)
  [作者：ajiratech2](https://github.com/ajiratech2)

* 通过使用动态值进行缩小（加载时缩小）来防止混叠。
  [相关议题 #781](https://github.com/lovell/sharp/issues/781)
  [作者：kleisauke](https://github.com/kleisauke)

* 公开 libvips 的 "squash" 参数以启用 1 位 TIFF 输出。
  [相关议题 #783](https://github.com/lovell/sharp/pull/783)
  [作者：YvesBos](https://github.com/YvesBos)

* 添加支持使用任何 +/-90 度的倍数进行旋转。
  [相关议题 #791](https://github.com/lovell/sharp/pull/791)
  [作者：ncoden](https://github.com/ncoden)

* 添加 "jpg" 别名到 `toFormat` 作为 "jpeg" 的简写形式。
  [相关议题 #814](https://github.com/lovell/sharp/pull/814)
  [作者：jingsam](https://github.com/jingsam)

## v0.17 - "*quill*"

需要 libvips v8.4.2。

### v0.17.3 - 2017 年 4 月 1 日

* 允许 `toBuffer` 可选地解析为包含 info 和 data 的 Promise。
  [相关议题 #143](https://github.com/lovell/sharp/issues/143)
  [作者：salzhrani](https://github.com/salzhrani)

* 创建指定宽度、高度、通道和背景的空白图像。
  [相关议题 #470](https://github.com/lovell/sharp/issues/470)
  [作者：pjarts](https://github.com/pjarts)

* 添加对图像缩减的 "nearest" 内核的支持。
  [相关议题 #732](https://github.com/lovell/sharp/pull/732)
  [作者：alice0meta](https://github.com/alice0meta)

* 添加对 TIFF 压缩和预测器选项的支持。
  [相关议题 #738](https://github.com/lovell/sharp/pull/738)
  [作者：kristojorg](https://github.com/kristojorg)

### v0.17.2 - 2017 年 2 月 11 日

* 确保 Stream 的可读端在可写端完成后可以开始流动。
  [相关议题 #671](https://github.com/lovell/sharp/issues/671)
  [作者：danhaller](https://github.com/danhaller)

* 公开 WebP 的 alpha 质量、无损和近无损输出选项。
  [相关议题 #685](https://github.com/lovell/sharp/pull/685)
  [作者：rnanwani](https://github.com/rnanwani)

### v0.17.1 - 2017 年 1 月 15 日

* 改进无效参数的错误消息。
  [作者：spikeon](https://github.com/spikeon)
  [相关议题 #644](https://github.com/lovell/sharp/pull/644)

* 简化查找 vips-cpp libdir 的表达式。
  [相关议题 #656](https://github.com/lovell/sharp/pull/656)

* 允许在下载预编译依赖项时使用 HTTPS-over-HTTP 代理。
  [作者：wangzhiwei1888](https://github.com/wangzhiwei1888)
  [相关议题 #679](https://github.com/lovell/sharp/issues/679)

### v0.17.0 - 2016 年 12 月 11 日

* 停止支持低于 v4 的 Node 版本。

* 弃用以下输出格式 "option" 函数：
    `quality`、`progressive`、`compressionLevel`、`withoutAdaptiveFiltering`、
    `withoutChromaSubsampling`、`trellisQuantisation`、`trellisQuantization`、
    `overshootDeringing`、`optimiseScans` 和 `optimizeScans`。
  现在可以通过输出格式函数访问这些函数，例如 `quality(n)` 
  现在是 `jpeg({quality: n})` 和/或 `webp({quality: n})`。

* 如果未指定其他格式，自动将 GIF 和 SVG 输入转换为 PNG 输出。

* 公开 libvips 的 "centre" 调整大小选项，以模仿 \*magick 的 +0.5px 约定。
  [相关议题 #568](https://github.com/lovell/sharp/issues/568)

* 确保支持嵌入在 SVG 中的 base64 PNG 和 JPEG 图像。
  [相关议题 #601](https://github.com/lovell/sharp/issues/601)
  [作者：dynamite-ready](https://github.com/dynamite-ready)

* 确保 premultiply 操作在 box filter 缩小之前发生。
  [相关议题 #605](https://github.com/lovell/sharp/issues/605)
  [作者：CmdrShepardsPie](https://github.com/CmdrShepardsPie)
  [作者：teroparvinen](https://github.com/teroparvinen)

* 添加对 PNG 和 WebP 平铺输出格式的支持（除了 JPEG）。
  [相关议题 #622](https://github.com/lovell/sharp/pull/622)
  [作者：ppaskaris](https://github.com/ppaskaris)

* 允许使用 extend 与灰度输入。
  [相关议题 #623](https://github.com/lovell/sharp/pull/623)
  [作者：ppaskaris](https://github.com/ppaskaris)

* 允许非 RGB 输入嵌入/扩展到带有 alpha 通道的背景。
  [相关议题 #646](https://github.com/lovell/sharp/issues/646)
  [作者：DaGaMs](https://github.com/DaGaMs)

## v0.16 - "*pencil*"

需要 libvips v8.3.3。

### v0.16.2 - 2016 年 10 月 22 日

* 将 readelf 的使用限制为仅在 Linux 上检测全局 libvips 版本。
  [相关议题 #602](https://github.com/lovell/sharp/issues/602)
  [作者：caoko](https://github.com/caoko)

### v0.16.1 - 2016 年 10 月 13 日

* C++11 ABI 版本现在自动检测，移除 sharp-cxx11 安装标志。

* 添加实验性的 'attention' 裁剪策略。
  [相关议题 #295](https://github.com/lovell/sharp/issues/295)

* 包括 .node 扩展名以用于 Meteor 的 require() 实现。
  [相关议题 #537](https://github.com/lovell/sharp/issues/537)
  [作者：isjackwild](https://github.com/isjackwild)

* 确保卷积核比例被限制为最小值 1。
  [相关议题 #561](https://github.com/lovell/sharp/issues/561)
  [作者：abagshaw](https://github.com/abagshaw)

* 修正固定点叠加图像时 y 轴位置的计算。
  [相关议题 #566](https://github.com/lovell/sharp/issues/566)
  [作者：Nateowami](https://github.com/Nateowami)

### v0.16.0 - 2016 年 8 月 18 日

* 添加对 OS X、ARMv7 和 ARMv8 的预编译 libvips 的支持。
  [相关议题 #312](https://github.com/lovell/sharp/issues/312)

* 确保 boolean、bandbool、extractChannel 操作在 sRGB 转换之前发生。
  [相关议题 #504](https://github.com/lovell/sharp/pull/504)
  [作者：mhirsch](https://github.com/mhirsch)

* 在 WebP `shrink-on-load` 之后重新计算因子以避免舍入为零的错误。
  [相关议题 #508](https://github.com/lovell/sharp/issues/508)
  [作者：asilvas](https://github.com/asilvas)

* 防止在 extract 操作期间发生 boolean 错误。
  [相关议题 #511](https://github.com/lovell/sharp/pull/511)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加 joinChannel 和 toColourspace/toColorspace 操作。
  [相关议题 #513](https://github.com/lovell/sharp/pull/513)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加对原始像素数据与 boolean 和 withOverlay 操作的支持。
  [相关议题 #516](https://github.com/lovell/sharp/pull/516)
  [作者：mhirsch](https://github.com/mhirsch)

* 防止 bandbool 创建单通道 sRGB 图像。
  [相关议题 #519](https://github.com/lovell/sharp/pull/519)
  [作者：mhirsch](https://github.com/mhirsch)

* 确保 ICC 配置文件从 PNG 输出中移除，除非使用 withMetadata。
  [相关议题 #521](https://github.com/lovell/sharp/issues/521)
  [作者：ChrisPinewood](https://github.com/ChrisPinewood)

* 添加 alpha 通道（如果缺失）到 overlayWith 图像。
  [相关议题 #540](https://github.com/lovell/sharp/pull/540)
  [作者：cmtt](https://github.com/cmtt)

* 移除已弃用的 interpolateWith 方法 - 使用 resize(w, h, { interpolator: ... })。
  [相关议题 #310](https://github.com/lovell/sharp/issues/310)

## v0.15 - "*outfit*"

需要 libvips v8.3.1。

### v0.15.1 - 2016 年 7 月 12 日

* 将基于 Stream 的输入连接为单个操作，性能提升约 +3%，减少垃圾回收。
  [相关议题 #429](https://github.com/lovell/sharp/issues/429)
  [作者：papandreou](https://github.com/papandreou)

* 在 extend 操作之前，如果需要，添加 alpha 通道。
  [相关议题 #439](https://github.com/lovell/sharp/pull/439)
  [作者：frulo](https://github.com/frulo)

* 允许通过 tile 选项在整张图像上重复叠加图像。
  [相关议题 #443](https://github.com/lovell/sharp/pull/443)
  [作者：lemnisk8](https://github.com/lemnisk8)

* 添加 cutout 选项到 overlayWith 功能，仅应用叠加图像的 alpha 通道。
  [相关议题 #448](https://github.com/lovell/sharp/pull/448)
  [作者：kleisauke](https://github.com/kleisauke)

* 确保独立计算缩放因子以防止舍入错误。
  [相关议题 #452](https://github.com/lovell/sharp/issues/452)
  [作者：puzrin](https://github.com/puzrin)

* 添加 --sharp-cxx11 标志以使用 gcc 的新 C++11 ABI 进行编译。
  [相关议题 #456](https://github.com/lovell/sharp/pull/456)
  [作者：kapouer](https://github.com/kapouer)

* 添加 top/left 偏移支持到 overlayWith 操作。
  [相关议题 #473](https://github.com/lovell/sharp/pull/473)
  [作者：rnanwani](https://github.com/rnanwani)

* 添加 convolve 操作以进行基于内核的卷积。
  [相关议题 #479](https://github.com/lovell/sharp/pull/479)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加 greyscale 选项到 threshold 操作以控制颜色空间转换。
  [相关议题 #480](https://github.com/lovell/sharp/pull/480)
  [作者：mhirsch](https://github.com/mhirsch)

* 确保 ICC 配置文件已获得分发许可。
  [相关议题 #486](https://github.com/lovell/sharp/issues/486)
  [作者：kapouer](https://github.com/kapouer)

* 允许带有 alpha 通道的图像使用基于 LAB 颜色空间的 sharpen。
  [相关议题 #490](https://github.com/lovell/sharp/issues/490)
  [作者：jwagner](https://github.com/jwagner)

* 添加 trim 操作以移除 "无聊" 的边缘。
  [相关议题 #492](https://github.com/lovell/sharp/pull/492)
  [作者：kleisauke](https://github.com/kleisauke)

* 添加 bandbool 功能以进行逐通道的布尔操作。
  [相关议题 #496](https://github.com/lovell/sharp/pull/496)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加 extractChannel 操作以从图像中提取一个通道。
  [相关议题 #497](https://github.com/lovell/sharp/pull/497)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加读取和写入原生 libvips .v 文件的能力。
  [相关议题 #500](https://github.com/lovell/sharp/pull/500)
  [作者：mhirsch](https://github.com/mhirsch)

* 添加 boolean 功能以进行位图像操作。
  [相关议题 #501](https://github.com/lovell/sharp/pull/501)
  [作者：mhirsch](https://github.com/mhirsch)

### v0.15.0 - 2016 年 5 月 21 日

* 使用 libvips 的新 Lanczos 3 内核作为图像缩减的默认内核。
  弃用 interpolateWith 方法，现在作为 resize 选项提供。
  [相关议题 #310](https://github.com/lovell/sharp/issues/310)
  [作者：jcupitt](https://github.com/jcupitt)

* 利用 libvips v8.3 的功能。
  添加对 libvips 的新 GIF 和 SVG 加载器的支持。
  预编译二进制文件现在包括 giflib 和 librsvg，排除 *magick。
  对 WebP 输入使用 shrink-on-load。
  修改现有的 sharpen API 以接受 sigma 并提高精度。
  [相关议题 #369](https://github.com/lovell/sharp/issues/369)

* 移除不必要的 (un)premultiply 操作，当不进行调整大小/合成时。
  [相关议题 #413](https://github.com/lovell/sharp/issues/413)
  [作者：jardakotesovec](https://github.com/jardakotesovec)

## v0.14 - "*needle*"

需要 libvips v8.2.3。

### v0.14.1 - 2016 年 4 月 16 日

* 允许通过 limitInputPixels 移除对输入像素计数的限制。使用时请小心。
  [相关议题 #250](https://github.com/lovell/sharp/issues/250)
  [相关议题 #316](https://github.com/lovell/sharp/pull/316)
  [作者：anandthakker](https://github.com/anandthakker)
  [作者：kentongray](https://github.com/kentongray)

* 使用最终输出图像作为传递给回调的元数据。
  [相关议题 #399](https://github.com/lovell/sharp/pull/399)
  [作者：salzhrani](https://github.com/salzhrani)

* 添加对将平铺图像写入 zip 容器的支持。
  [相关议题 #402](https://github.com/lovell/sharp/pull/402)
  [作者：felixbuenemann](https://github.com/felixbuenemann)

* 允许使用 embed 与 1 和 2 通道的图像。
  [相关议题 #411](https://github.com/lovell/sharp/issues/411)
  [作者：janaz](https://github.com/janaz)

* 改进 Electron 的兼容性，允许在没有 npm 的情况下使用 node-gyp 重建。
  [相关议题 #412](https://github.com/lovell/sharp/issues/412)
  [作者：nouh](https://github.com/nouh)

### v0.14.0 - 2016 年 4 月 2 日

* 添加扩展（填充）图像边缘的能力。
  [相关议题 #128](https://github.com/lovell/sharp/issues/128)
  [作者：blowsie](https://github.com/blowsie)

* 添加对 Zoomify 和 Google 平铺布局的支持。破坏现有的平铺 API。
  [相关议题 #223](https://github.com/lovell/sharp/issues/223)
  [作者：bdunnette](https://github.com/bdunnette)

* 改进 overlayWith：不同的大小/格式、gravity、缓冲区输入。
  [相关议题 #239](https://github.com/lovell/sharp/issues/239)
  [作者：chrisriley](https://github.com/chrisriley)

* 添加基于熵的裁剪策略以移除最不有趣的边缘。
  [相关议题 #295](https://github.com/lovell/sharp/issues/295)
  [作者：rightaway](https://github.com/rightaway)

* 公开密度元数据；从矢量输入设置图像的密度。
  [相关议题 #338](https://github.com/lovell/sharp/issues/338)
  [作者：lookfirst](https://github.com/lookfirst)

* 为 Stream 输出发出后处理 'info' 事件。
  [相关议题 #367](https://github.com/lovell/sharp/issues/367)
  [作者：salzhrani](https://github.com/salzhrani)

* 确保输出图像的 EXIF Orientation 值在 1-8 范围内。
  [相关议题 #385](https://github.com/lovell/sharp/pull/385)
  [作者：jtobinisaniceguy](https://github.com/jtobinisaniceguy)

* 确保在旋转 90/270 度并忽略宽高比时，比例不会互换。
  [相关议题 #387](https://github.com/lovell/sharp/issues/387)
  [作者：kleisauke](https://github.com/kleisauke)

* 移除已弃用的调用 extract API 的风格。破坏使用位置参数的调用。
  [相关议题 #276](https://github.com/lovell/sharp/issues/276)

## v0.13 - "*mind*"

需要 libvips v8.2.2。

### v0.13.1 - 2016 年 2 月 27 日

* 修复嵌入到透明背景的问题；在 v0.13.0 中引入的回归。
  [相关议题 #366](https://github.com/lovell/sharp/issues/366)
  [作者：diegocsandrim](https://github.com/diegocsandrim)

### v0.13.0 - 2016 年 2 月 15 日

* 通过允许控制密度/DPI 改进矢量图像支持。
  从 Imagemagick 切换到 Graphicsmagick 的预编译库。
  [相关议题 #110](https://github.com/lovell/sharp/issues/110)
  [作者：bradisbell](https://github.com/bradisbell)

* 添加对原始、未压缩像素 Buffer/Stream 输入的支持。
  [相关议题 #220](https://github.com/lovell/sharp/issues/220)
  [作者：mikemorris](https://github.com/mikemorris)

* 从 libvips 的 C 切换到 C++ 绑定，需要升级到 v8.2.2。
  [相关议题 #299](https://github.com/lovell/sharp/issues/299)

* 控制 libvips 缓存中的打开文件数量；破坏现有的 `cache` 行为。
  [相关议题 #315](https://github.com/lovell/sharp/issues/315)
  [作者：impomezia](https://github.com/impomezia)

* 确保 16 位输入图像可以被归一化并嵌入到透明背景。
  [相关议题 #339](https://github.com/lovell/sharp/issues/339)
  [相关议题 #340](https://github.com/lovell/sharp/issues/340)
  [作者：janaz](https://github.com/janaz)

* 确保选定的格式优先于任何未知的输出文件名扩展。
  [相关议题 #344](https://github.com/lovell/sharp/issues/344)
  [作者：ubaltaci](https://github.com/ubaltaci)

* 添加对 libvips 的 PBM、PGM、PPM 和 FITS 图像格式加载器的支持。
  [相关议题 #347](https://github.com/lovell/sharp/issues/347)
  [作者：oaleynik](https://github.com/oaleynik)

* 确保默认的裁剪 gravity 是 center/centre。
  [相关议题 #351](https://github.com/lovell/sharp/pull/351)
  [作者：joelmukuthu](https://github.com/joelmukuthu)

* 改进对 musl libc 系统的支持，例如 Alpine Linux。
  [相关议题 #354](https://github.com/lovell/sharp/issues/354)
  [相关议题 #359](https://github.com/lovell/sharp/pull/359)
  [作者：download13](https://github.com/download13)
  [作者：wjordan](https://github.com/wjordan)

* 在按整数因子缩减时进行小的优化，优先选择 shrink 而不是 affine。

* 添加对带有 alpha 通道的图像的伽马校正支持。

## v0.12 - "*look*"

需要 libvips v8.2.0。

### v0.12.2 - 2016 年 1 月 16 日

* 升级 libvips 到 v8.2.0 以改进 vips_shrink。

* 添加对 ARMv6+ CPU 的预编译 libvips 的支持。

* 确保 16 位输入图像与 embed 选项一起正常工作。
  [相关议题 #325](https://github.com/lovell/sharp/issues/325)
  [作者：janaz](https://github.com/janaz)

* 允许使用 gmake 进行编译以提供 FreeBSD 支持。
  [相关议题 #326](https://github.com/lovell/sharp/issues/326)
  [作者：c0decafe](https://github.com/c0decafe)

* 尝试在安装后移除临时文件。
  [相关议题 #331](https://github.com/lovell/sharp/issues/331)
  [作者：dtoubelis](https://github.com/dtoubelis)

### v0.12.1 - 2015 年 12 月 12 日

* 允许使用 SIMD 向量指令（通过 liborc）进行开关。
  [相关议题 #172](https://github.com/lovell/sharp/issues/172)
  [作者：bkw](https://github.com/bkw)
  [作者：puzrin](https://github.com/puzrin)

* 确保嵌入的 ICC 配置文件以感知意图输出。
  [相关议题 #321](https://github.com/lovell/sharp/issues/321)
  [作者：vlapo](https://github.com/vlapo)

* 使用 NPM 配置的 HTTPS 代理（如果有）进行二进制下载。

### v0.12.0 - 2015 年 11 月 23 日

* 为 64 位 Linux 和 Windows 打包预编译的 libvips 及其依赖项。
  [相关议题 #42](https://github.com/lovell/sharp/issues/42)

* 利用 libvips v8.1.0+ 的功能。
  [相关议题 #152](https://github.com/lovell/sharp/issues/152)

* 添加对 64 位 Windows 的支持。停止支持 32 位 Windows。
  [相关议题 #224](https://github.com/lovell/sharp/issues/224)
  [作者：sabrehagen](https://github.com/sabrehagen)

* 将默认插值切换为双三次插值。
  [相关议题 #289](https://github.com/lovell/sharp/issues/289)
  [作者：mahnunchik](https://github.com/mahnunchik)

* 预提取旋转不应交换宽度/高度。
  [相关议题 #296](https://github.com/lovell/sharp/issues/296)
  [作者：asilvas](https://github.com/asilvas)

* 确保 16 位 + alpha 输入图像被正确地 (un)premultiplied。
  [相关议题 #301](https://github.com/lovell/sharp/issues/301)
  [作者：izaakschroeder](https://github.com/izaakschroeder)

* 添加 `threshold` 操作。
  [相关议题 #303](https://github.com/lovell/sharp/pull/303)
  [作者：dacarley](https://github.com/dacarley)

* 添加 `negate` 操作。
  [相关议题 #306](https://github.com/lovell/sharp/pull/306)
  [作者：dacarley](https://github.com/dacarley)

* 支持 `options` 对象与现有的 `extract` 操作。
  [相关议题 #309](https://github.com/lovell/sharp/pull/309)
  [作者：papandreou](https://github.com/papandreou)

## v0.11 - "*knife*"

### v0.11.4 - 2015 年 11 月 5 日

* 添加角落选项，例如 `northeast`，到现有的 `gravity` 选项。
  [相关议题 #291](https://github.com/lovell/sharp/pull/291)
  [作者：brandonaaron](https://github.com/brandonaaron)

* 确保 EXIF Orientation 值 2 和 4 的正确自动旋转。
  [相关议题 #288](https://github.com/lovell/sharp/pull/288)
  [作者：brandonaaron](https://github.com/brandonaaron)

* 通过 `--runtime_link` 安装选项使静态链接成为可能。
  [相关议题 #287](https://github.com/lovell/sharp/pull/287)
  [作者：vlapo](https://github.com/vlapo)

### v0.11.3 - 2015 年 9 月 8 日

* 将 blurSigma、sharpenFlat 和 sharpenJagged 解释为双精度。
  [相关议题 #263](https://github.com/lovell/sharp/pull/263)
  [作者：chrisriley](https://github.com/chrisriley)

### v0.11.2 - 2015 年 8 月 28 日

* 允许将裁剪 gravity 作为字符串提供。
  [相关议题 #255](https://github.com/lovell/sharp/pull/255)
  [作者：papandreou](https://github.com/papandreou)
* 添加对 io.js v3 和 Node v4 的支持。
  [相关议题 #246](https://github.com/lovell/sharp/issues/246)

### v0.11.1 - 2015 年 8 月 12 日

* 静默处理 MSVC 警告：“C4530: 使用了 C++ 异常处理程序，但未启用展开语义”。
  [相关议题 #244](https://github.com/lovell/sharp/pull/244)
  [作者：TheThing](https://github.com/TheThing)

* 对于带有 alpha 透明度的输入图像，抑制伽马校正。
  [相关议题 #249](https://github.com/lovell/sharp/issues/249)
  [作者：compeak](https://github.com/compeak)

### v0.11.0 - 2015 年 7 月 15 日

* 允许通过新的 `overlayWith` 方法进行 alpha 透明度合成。
  [相关议题 #97](https://github.com/lovell/sharp/issues/97)
  [作者：gasi](https://github.com/gasi)

* 在使用 `metadata` 时，将原始 ICC 配置文件数据公开为 Buffer。
  [相关议题 #129](https://github.com/lovell/sharp/issues/129)
  [作者：homerjam](https://github.com/homerjam)

* 允许通过传递给现有 `withMetadata` 方法的参数更新图像头。
  提供对 EXIF `Orientation` 标签的初始支持，
  如果存在，现在在使用 `rotate`、`flip` 或 `flop` 时将其移除。
  [相关议题 #189](https://github.com/lovell/sharp/issues/189)
  [作者：h2non](https://github.com/h2non)

* 加强构造函数参数检查。
  [相关议题 #221](https://github.com/lovell/sharp/issues/221)
  [作者：mikemorris](https://github.com/mikemorris)

* 允许通过新的 `clone` 方法共享一个输入 Stream 与两个或多个输出 Stream。
  [相关议题 #235](https://github.com/lovell/sharp/issues/235)
  [作者：jaubourg](https://github.com/jaubourg)

* 在自动缩放尺寸时使用 `round` 而不是 `floor` 以避免浮点舍入错误。
  [相关议题 #238](https://github.com/lovell/sharp/issues/238)
  [作者：richardadjogah](https://github.com/richardadjogah)

## v0.10 - "*judgment*"

### v0.10.1 - 2015 年 6 月 1 日

* 允许将带有 alpha 透明度的图像嵌入到非透明背景。
  [相关议题 #204](https://github.com/lovell/sharp/issues/204)
  [作者：mikemliu](https://github.com/mikemliu)

* 包括 C 标准库以用于 `atoi`，因为 Xcode 6.3 似乎不再这样做。
  [相关议题 #228](https://github.com/lovell/sharp/issues/228)
  [作者：doggan](https://github.com/doggan)

### v0.10.0 - 2015 年 4 月 23 日

* 添加对 Windows (x86) 的支持。
  [相关议题 #19](https://github.com/lovell/sharp/issues/19)
  [作者：DullReferenceException](https://github.com/DullReferenceException)
  [作者：itsananderson](https://github.com/itsananderson)

* 添加对 Openslide 输入和 DeepZoom 输出的支持。
  [相关议题 #146](https://github.com/lovell/sharp/issues/146)
  [作者：mvictoras](https://github.com/mvictoras)

* 允许在调整图像大小时使用新的 `ignoreAspectRatio` 方法设置任意宽高比。
  [相关议题 #192](https://github.com/lovell/sharp/issues/192)
  [作者：skedastik](https://github.com/skedastik)

* 通过新的 `normalize` 方法增强输出图像的对比度，通过拉伸其亮度来覆盖完整的动态范围。
  [相关议题 #194](https://github.com/lovell/sharp/issues/194)
  [作者：bkw](https://github.com/bkw)
  [作者：codingforce](https://github.com/codingforce)
  