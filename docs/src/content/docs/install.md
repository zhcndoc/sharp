---
title: 安装
---

与您选择的 JavaScript 包管理器兼容。

:::caution
请确保您的包管理器配置为安装可选依赖项
:::

如果包管理器的锁定文件必须支持多个平台，请参见 [跨平台](#cross-platform) 部分以帮助决定哪个包管理器适合。

```sh
npm install sharp
```

```sh
pnpm add sharp
```

使用 `pnpm` 时，您可能需要将 `sharp` 添加到 [ignoredBuiltDependencies](https://pnpm.io/settings#ignoredbuiltdependencies) 以消除警告。

```sh
yarn add sharp
```

```sh
bun add sharp
```

```sh
deno run --allow-ffi ...
```

## 先决条件

* Node-API v9 兼容的运行时，例如 Node.js ^18.17.0 或 >=20.3.0。

## 预构建的二进制文件

为最常见的平台提供已编译的 sharp 和 libvips 二进制文件：

* macOS x64 (>= 10.15)
* macOS ARM64
* Linux ARM (glibc >= 2.31)
* Linux ARM64 (glibc >= 2.26, musl >= 1.2.2)
* Linux ppc64 (glibc >= 2.36)
* Linux s390x (glibc >= 2.36)
* Linux x64 (glibc >= 2.26, musl >= 1.2.2, 支持 SSE4.2 的 CPU)
* Windows x64
* Windows x86
* Windows ARM64 (实验性，所有功能均需 ARMv8.4 的 CPU)

这为 JPEG、PNG、WebP、AVIF（限制为 8 位深度）、TIFF、GIF 和 SVG（输入）图像格式提供支持。

## 跨平台

在安装时，包管理器会自动选择可用的当前 OS 平台和 CPU 架构的预构建二进制文件。

一些包管理器支持在同一安装树和/或使用相同的锁定文件中支持多个平台和架构。

### npm v10+

:::caution
多个平台共享的 npm `package-lock.json` 文件可能会由于 [npm bug #4828](https://github.com/npm/cli/issues/4828) 而导致安装问题
:::

通过 `--os`、`--cpu` 和 `--libc` 标志提供有限的支持。

要支持 macOS 的 Intel x64 和 ARM64 CPU：
```sh
npm install --cpu=x64 --os=darwin sharp
npm install --cpu=arm64 --os=darwin sharp
```

当目标是 Linux 时，必须指定 C 标准库。

要支持 glibc（例如 Debian）和 musl（例如 Alpine）Linux 的 Intel x64 CPU：
```sh
npm install --cpu=x64 --os=linux --libc=glibc sharp
npm install --cpu=x64 --os=linux --libc=musl sharp
```

### yarn v3+

使用 [supportedArchitectures](https://yarnpkg.com/configuration/yarnrc#supportedArchitectures) 配置。

### pnpm v8+

使用 [supportedArchitectures](https://pnpm.io/settings#supportedarchitectures) 配置。

## 自定义 libvips

要使用自定义的全局安装的 libvips，而不是提供的二进制文件，确保它至少是 `package.json` 文件中 `config.libvips` 下列出的版本并且可以使用 `pkg-config --modversion vips-cpp` 进行定位。

有关编译 libvips 及其依赖项的帮助，请参见 [从源代码构建 libvips](https://www.libvips.org/install.html#building-libvips-from-source)。

在 Windows 上不支持使用全局安装的 libvips，并且在 Rosetta 下运行 Node.js 的 macOS 上也不支持。

## 从源代码构建

当检测到全局安装的 libvips 或者使用 `npm install --build-from-source` 标志时，该模块将在 `npm install` 时从源代码编译。

可以通过设置 `SHARP_IGNORE_GLOBAL_LIBVIPS`（从不尝试使用它）或 `SHARP_FORCE_GLOBAL_LIBVIPS`（始终尝试使用它，即使缺失或过时）环境变量来跳过检测全局安装的 libvips 的逻辑。

从源代码构建需要：

* C++17 编译器
* [node-addon-api](https://www.npmjs.com/package/node-addon-api) 版本 7+
* [node-gyp](https://github.com/nodejs/node-gyp#installation) 版本 9+ 及其依赖项

这些依赖项在安装时会进行检查。如果无法找到 `node-addon-api` 或 `node-gyp`，请尝试通过以下命令添加：

```sh
npm install --save node-addon-api node-gyp
```

使用 `pnpm` 时，您可能需要将 `sharp` 添加到 [onlyBuiltDependencies](https://pnpm.io/settings#onlybuiltdependencies) 以确保安装脚本可以运行。

对于交叉编译，可以使用 `--platform`、`--arch` 和 `--libc` npm 标志（或 `npm_config_platform`，`npm_config_arch` 和 `npm_config_libc` 环境变量）来配置目标环境。

## WebAssembly

为提供多线程 Wasm 通过 Workers 的运行时环境提供实验性支持。

在 Web 浏览器中使用不受支持。

原生文本渲染不受支持。

不支持 [基于瓷砖的输出](/api-output#tile)。

```sh
npm install --cpu=wasm32 sharp
```

## FreeBSD

必须在运行 `npm install` 之前安装 `vips` 包。

```sh
pkg install -y pkgconf vips
```

```sh
cd /usr/ports/graphics/vips/ && make install clean
```

## Linux 内存分配器

在大多数基于 glibc 的 Linux 系统（例如 Debian、Red Hat）上，默认的内存分配器不适合涉及大量小内存分配的长时间运行的多线程流程。

因此，默认情况下，sharp 会在运行时检测到 glibc 分配器时限制线程基础的 [并发](/api-utility#concurrency) 的使用。

为帮助避免碎片并提高这些系统的性能，建议使用替代的内存分配器，例如 [jemalloc](https://github.com/jemalloc/jemalloc)。

使用基于 musl 的 Linux（例如 Alpine）和非 Linux 系统的用户不受影响。

## AWS Lambda

[部署包](https://docs.aws.amazon.com/lambda/latest/dg/nodejs-package.html) 的 `node_modules` 目录必须包括适用于 linux-x64 或 linux-arm64 平台的二进制文件，具体取决于选择的架构。

在架构与目标架构不同的机器上构建部署包时，请参见 [跨平台](#cross-platform) 部分以帮助决定哪个包管理器适合以及如何配置它。

一些包管理器使用符号链接但 AWS Lambda 不支持在部署包中使用这些符号链接。

要获得最佳性能，选择最大可用内存。1536 MB 的函数提供的 CPU 时间约为 128 MB 函数的 12 倍。

在与 AWS API Gateway 集成时，请确保其配置了相关的 [二进制媒体类型](https://docs.aws.amazon.com/apigateway/latest/developerguide/api-gateway-payload-encodings.html)。

## 打包工具

### webpack

确保通过 [externals](https://webpack.js.org/configuration/externals/) 配置将 sharp 排除在打包之外。

```js
externals: {
  'sharp': 'commonjs sharp'
}
```

### esbuild

确保通过 [external](https://esbuild.github.io/api/#external) 配置将 sharp 排除在打包之外。

```js
buildSync({
  entryPoints: ['app.js'],
  bundle: true,
  platform: 'node',
  external: ['sharp'],
})
```

```sh
esbuild app.js --bundle --platform=node --external:sharp
```

对于 `serverless-esbuild`，请确保通过 `serverless.yml` 配置安装特定平台的二进制文件。

```yaml
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

确保使用 [asarUnpack](https://www.electron.build/app-builder-lib.interface.platformspecificbuildoptions#asarunpack) 选项将 `sharp` 从 ASAR 存档文件中解包。

```json
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

确保使用 [unpack](https://js.electronforge.io/interfaces/_electron_forge_maker_squirrel.InternalOptions.Options.html#asar) 选项将 `sharp` 从 ASAR 存档文件中解包。

```json
{
  "packagerConfig": {
    "asar": {
      "unpack": "**/node_modules/{sharp,@img}/**/*"
    }
  }
}
```

在使用 `electron-forge` 和 [Webpack](#webpack) 时，您可能还需要添加 [forge-externals-plugin](https://www.npmjs.com/package/@timfish/forge-externals-plugin)。

### vite

确保通过 [build.rollupOptions](https://vitejs.dev/config/build-options.html) 配置将 sharp 排除在打包之外。

```js
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

TypeScript 定义自 v0.32.0 起作为 `sharp` 包的一部分发布。

以前通过 `@types/sharp` 包提供，现已不再使用。

使用 TypeScript 时，请确保 `devDependencies` 包含 `@types/node` 包。

## 字体

在创建文本图像或渲染包含文本元素的 SVG 图像时，使用 `fontconfig` 找到相关字体。

在 Windows 和 macOS 系统上，所有系统字体都可供使用。

在使用 Homebrew 的 macOS 系统上，您可能需要将 `PANGOCAIRO_BACKEND` 环境变量设置为 `fontconfig` 的值以确保用于字体发现，而不是使用 Core Text。

在 Linux 系统上，通过包管理器安装时，如果包含相关 [`fontconfig` 配置](https://www.freedesktop.org/software/fontconfig/fontconfig-user.html)，则字体可供使用。

如果找不到 `fontconfig` 配置，将发生以下错误：
```
Fontconfig error: Cannot load default config file
```

在没有控制字体包的无服务器环境中，使用 `FONTCONFIG_PATH` 环境变量指向自定义位置。

嵌入的 SVG 字体不受支持。

## 已知冲突

### Canvas 和 Windows

如果在同一 Windows 进程中同时使用 `canvas` 和 `sharp` 模块，可能会发生以下错误：
```
指定的过程无法找到。
```
