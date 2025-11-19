---
title: 安装
---

支持您选择的任意 JavaScript 包管理器。

:::caution
请确保您的包管理器已配置为安装可选依赖项
:::

如果包管理器的锁定文件必须支持多个平台，
请参阅 [跨平台](#cross-platform) 部分
以帮助决定使用哪个包管理器更合适。

```sh frame="none"
npm install sharp
```

```sh frame="none"
pnpm add sharp
```

在使用 `pnpm` 时，将 `sharp` 添加到 [ignoredBuiltDependencies](https://pnpm.io/settings#ignoredbuiltdependencies) 以消除警告。

```sh frame="none"
yarn add sharp
```

```sh frame="none"
bun add sharp
```

```sh frame="none"
deno add --quiet npm:sharp
deno run --allow-env --allow-ffi --allow-read --allow-sys ...
```

## 先决条件

* 兼容 Node-API v9 的运行时环境，例如 Node.js ^18.17.0 或 >=20.3.0。

## 预编译二进制文件

为最常用的平台提供了预编译的 sharp 和 libvips 二进制文件：

* macOS x64 (>= 10.15)
* macOS ARM64
* Linux ARM (glibc >= 2.31)
* Linux ARM64 (glibc >= 2.26, musl >= 1.2.2)
* Linux RISC-V 64-bit (glibc >= 2.41)
* Linux ppc64 (glibc >= 2.36)
* Linux s390x (glibc >= 2.36)
* Linux x64 (glibc >= 2.26, musl >= 1.2.2, 具备 SSE4.2 的 CPU)
* Windows x64
* Windows x86
* Windows ARM64（实验性，所有功能需 CPU 支持 ARMv8.4）

这提供了对 JPEG、PNG、WebP、AVIF（仅限 8 位深度）、TIFF、GIF 和 SVG（输入格式）图像格式的支持。

## 跨平台

安装时，包管理器会自动针对当前操作系统平台和 CPU 架构选择预编译二进制文件（如果有可用）。

部分包管理器支持在同一安装树和/或使用同一锁定文件下，支持多平台和多架构。

### npm v10+

:::caution
多平台共享的 npm `package-lock.json` 文件可能会因 [npm bug #4828](https://github.com/npm/cli/issues/4828) 导致安装问题
:::

通过 `--os`、`--cpu` 和 `--libc` 标志提供有限支持。

要支持搭载 Intel x64 和 ARM64 CPU 的 macOS：
```sh frame="none"
npm install --cpu=x64 --os=darwin sharp
npm install --cpu=arm64 --os=darwin sharp
```

当交叉目标为 Linux 时，必须指定 C 标准库。

要支持搭载 Intel x64 CPU 的 glibc（例如 Debian）和 musl（例如 Alpine）Linux：
```sh frame="none"
npm install --cpu=x64 --os=linux --libc=glibc sharp
npm install --cpu=x64 --os=linux --libc=musl sharp
```

### yarn v3+

使用 [supportedArchitectures](https://yarnpkg.com/configuration/yarnrc#supportedArchitectures) 配置。

### pnpm v8+

使用 [supportedArchitectures](https://pnpm.io/settings#supportedarchitectures) 配置。

## 自定义 libvips

若要使用自定义的全局安装版本 libvips 替代所提供的二进制文件，
请确保其版本至少为 `package.json` 中 `config.libvips` 标明的版本，
且可通过 `pkg-config --modversion vips-cpp` 定位。

有关编译 libvips 及其依赖的帮助，请参阅
[从源代码构建 libvips](https://www.libvips.org/install.html#building-libvips-from-source)。

在 Windows 平台及在 macOS 上通过 Rosetta 运行 Node.js 时，不支持使用全局安装的 libvips。

## 从源代码构建

当出现以下情况时，此模块将从源代码编译：

* 检测到全局安装的 libvips，或
* 使用 `npm explore sharp -- npm run build`，或
* 在 `npm install` 时使用已弃用的 `npm run --build-from-source`。

检测全局安装 libvips 的逻辑可通过设置环境变量进行跳过：
`SHARP_IGNORE_GLOBAL_LIBVIPS`（永远不尝试使用）或
`SHARP_FORCE_GLOBAL_LIBVIPS`（始终尝试使用，即使缺失或版本过旧）。

从源码构建需要：

* C++17 编译器
* 版本 7 及以上的 [node-addon-api](https://www.npmjs.com/package/node-addon-api)
* 版本 9 及以上的 [node-gyp](https://github.com/nodejs/node-gyp#installation) 及其依赖

安装时会检查这些依赖。
如果找不到 `node-addon-api` 或 `node-gyp`，尝试通过以下命令添加：

```sh frame="none"
npm install --save node-addon-api node-gyp
```

使用 `pnpm` 时，您可能需要将 `sharp` 添加到
[onlyBuiltDependencies](https://pnpm.io/settings#onlybuiltdependencies)
以确保安装脚本能运行。

对于交叉编译，可以使用 npm 标志 `--platform`、`--arch` 和 `--libc`
（或环境变量 `npm_config_platform`、`npm_config_arch` 和 `npm_config_libc`）
来配置目标环境。

## WebAssembly

为支持通过 Worker 提供多线程 Wasm 的运行时环境提供实验性支持。

不支持在网页浏览器中使用。

不支持本地文本渲染。

不支持[基于瓦片的输出](/api-output#tile)。

```sh frame="none"
npm install --cpu=wasm32 sharp
```

## FreeBSD

必须先安装 `vips` 包，然后再运行 `npm install`，此外还需安装额外的[从源代码构建](#building-from-source)依赖。

```sh frame="none"
pkg install -y pkgconf vips
```

```sh frame="none"
cd /usr/ports/graphics/vips/ && make install clean
```

## Linux 内存分配器

大多数基于 glibc 的 Linux 系统
（例如 Debian、Red Hat）默认的内存分配器不适合长时间运行的多线程进程，
且涉及大量小内存分配。

因此，默认为防止碎片，sharp 在运行时检测到 glibc 分配器时
会限制线程基础的 [并发](/api-utility#concurrency) 使用。

为帮助减少碎片并提升性能，推荐在这些系统使用替代的内存分配器，如
[jemalloc](https://github.com/jemalloc/jemalloc)。

使用 musl 的 Linux（如 Alpine）和非 Linux 系统不受影响。

## AWS Lambda

部署包的 `node_modules` 目录必须包含对应所选架构的 linux-x64 或 linux-arm64 平台的二进制文件。

当在与目标架构不同的机器上构建部署包时，
请参考[跨平台](#cross-platform) 部分帮助确定合适的包管理器并进行配置。

部分包管理器会使用符号链接，
但 AWS Lambda 不支持部署包中的符号链接。

为获得最佳性能，选择最大可用内存。
1536 MB 的函数提供约 12 倍于 128 MB 函数的 CPU 时间。

与 AWS API Gateway 集成时，确保配置了相关
[二进制媒体类型](https://docs.aws.amazon.com/apigateway/latest/developerguide/api-gateway-payload-encodings.html)。

## 打包工具

### webpack

确保通过
[externals](https://webpack.js.org/configuration/externals/)
配置将 sharp 排除在打包之外。

```js frame="none"
externals: {
  'sharp': 'commonjs sharp'
}
```

### esbuild

确保通过
[external](https://esbuild.github.io/api/#external)
配置将 sharp 排除在打包之外。

```js frame="none"
buildSync({
  entryPoints: ['app.js'],
  bundle: true,
  platform: 'node',
  external: ['sharp'],
})
```

```sh frame="none"
esbuild app.js --bundle --platform=node --external:sharp
```

对于 `serverless-esbuild`，确保通过 `serverless.yml` 配置安装特定平台的二进制文件。

```yaml frame="none"
custom:
  esbuild:
    external:
      - sharp
    packagerOptions:
      scripts:
        - npm install --os=linux --cpu=x64 sharp
```

### electron

#### electron-builder

确保使用
[asarUnpack](https://www.electron.build/app-builder-lib.interface.platformspecificbuildoptions#asarunpack)
选项将 `sharp` 从 ASAR 归档文件中解包。

```json frame="none"
{
  "build": {
    "asar": true,
    "asarUnpack": [
      "**/node_modules/sharp/**/*",
      "**/node_modules/@img/**/*"
    ]
  }
}
```

#### electron-forge

确保使用
[unpack](https://js.electronforge.io/interfaces/_electron_forge_maker_squirrel.InternalOptions.Options.html#asar)
选项将 `sharp` 从 ASAR 归档文件中解包。

```json frame="none"
{
  "packagerConfig": {
    "asar": {
      "unpack": "**/node_modules/{sharp,@img}/**/*"
    }
  }
}
```

使用带有 [Webpack](#webpack) 的 `electron-forge` 时，
您可能还需要添加
[forge-externals-plugin](https://www.npmjs.com/package/@timfish/forge-externals-plugin)。

### vite

确保通过
[build.rollupOptions](https://vitejs.dev/config/build-options.html)
配置将 `sharp` 排除在打包之外。

```js frame="none"
import { defineConfig } from 'vite';

export default defineConfig({
  build: {
    rollupOptions: {
      external: [
        "sharp"
      ]
    }
  }
});
```

## TypeScript

自 v0.32.0 版本起，TypeScript 类型定义作为 `sharp` 包的一部分发布。

早期版本通过 `@types/sharp` 包提供，现已弃用。

使用 TypeScript 时，请确保 `devDependencies` 中包含 `@types/node` 包。

## 字体

创建文本图像或渲染包含文本元素的 SVG 图像时，
使用 `fontconfig` 查找相关字体。

在 Windows 和 macOS 系统上，所有系统字体均可使用。

在使用 Homebrew 的 macOS 系统上，您可能需要将
`PANGOCAIRO_BACKEND` 环境变量设置为 `fontconfig`
以确保使用它进行字体查找，而非 Core Text。

在 Linux 系统上，通过包管理器安装且包含相关
[`fontconfig` 配置](https://www.freedesktop.org/software/fontconfig/fontconfig-user.html)的字体可用。

如果找不到 `fontconfig` 配置，将出现以下错误：
```
Fontconfig error: Cannot load default config file
```

在无法控制字体包的无服务器环境中，
请使用 `FONTCONFIG_PATH` 环境变量指向自定义路径。

嵌入式 SVG 字体不被支持。

## 已知冲突

### Canvas 和 Windows

如果在同一个 Windows 进程中同时使用 `canvas` 和 `sharp` 模块，可能会发生以下错误：
```
The specified procedure could not be found.
```
