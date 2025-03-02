# 安装

支持您选择的 JavaScript 包管理器。

> ⚠️  **请确保您的包管理器已配置为安装可选依赖**

如果包管理器的锁定文件必须支持多个平台，请参见 [跨平台](#cross-platform) 部分以帮助决定哪个包管理器适合。

```sh
npm install sharp
```

```sh
pnpm add sharp
```

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

* 兼容 Node-API v9 的运行时，例如 Node.js ^18.17.0 或 >=20.3.0。

## 预构建的二进制文件

提供了用于最常见平台的已编译的 sharp 和 libvips 二进制文件：

* macOS x64 (>= 10.13)
* macOS ARM64
* Linux ARM (glibc >= 2.28)
* Linux ARM64 (glibc >= 2.26, musl >= 1.2.2)
* Linux ppc64 (glibc >= 2.31)
* Linux s390x (glibc >= 2.31)
* Linux x64 (glibc >= 2.26, musl >= 1.2.2, 支持 SSE4.2 的 CPU)
* Windows x64
* Windows x86

这支持
JPEG、PNG、WebP、AVIF（限于 8 位深度）、TIFF、GIF 和 SVG（输入）图像格式。

## 跨平台

在安装时，包管理器将自动选择适合当前操作系统平台和 CPU 架构的预构建二进制文件（如果可用）。

某些包管理器支持在同一个安装树和/或使用同一个锁定文件中支持多个平台和架构。

### npm v10+

> ⚠️ **npm 的 `package-lock.json` 文件可能因 [npm bug #4828](https://github.com/npm/cli/issues/4828) 而导致安装问题**

通过 `--os`、`--cpu` 和 `--libc` 标志提供有限的支持。

要支持 macOS 上的 Intel x64 和 ARM64 CPU：
```sh
npm install --cpu=x64 --os=darwin sharp
npm install --cpu=arm64 --os=darwin sharp
```

当交叉目标为 Linux 时，必须指定 C 标准库。

要支持 glibc（例如 Debian）和 musl（例如 Alpine）Linux 上的 Intel x64 CPU：
```sh
npm install --cpu=x64 --os=linux --libc=glibc sharp
npm install --cpu=x64 --os=linux --libc=musl sharp
```

### yarn v3+

使用 [supportedArchitectures](https://yarnpkg.com/configuration/yarnrc#supportedArchitectures) 配置。

### pnpm v8+

使用 [supportedArchitectures](https://pnpm.io/package_json#pnpmsupportedarchitectures) 配置。

## 自定义 libvips

要使用自定义的全局安装版本的 libvips 而不是提供的二进制文件，请确保它至少是 `package.json` 文件中 `config.libvips` 下列出的版本，并且可以通过 `pkg-config --modversion vips-cpp` 找到。

有关编译 libvips 及其依赖项的帮助，请参见 [从源代码构建 libvips](https://www.libvips.org/install.html#building-libvips-from-source)。

在 Windows 上和在 Rosetta 下运行 Node.js 的 macOS 上都不支持使用全局安装的 libvips。

## 从源代码构建

当检测到全局安装的 libvips 或使用 `npm install --build-from-source` 标志时，此模块将在 `npm install` 时从源代码编译。

可以通过设置环境变量 `SHARP_IGNORE_GLOBAL_LIBVIPS`（永远不尝试使用它）或 `SHARP_FORCE_GLOBAL_LIBVIPS`（即使缺失或过时也始终尝试使用它）跳过检测全局安装的 libvips 的逻辑。

从源代码构建需要：

* C++11 编译器
* [node-addon-api](https://www.npmjs.com/package/node-addon-api) 版本 7+
* [node-gyp](https://github.com/nodejs/node-gyp#installation) 版本 9+ 及其依赖项

安装时会检查这些依赖项。如果找不到 `node-addon-api` 或 `node-gyp`，请尝试通过以下方式添加：

```sh
npm install --save node-addon-api node-gyp
```

对于交叉编译，可以使用 `--platform`、`--arch` 和 `--libc` npm 标志（或 `npm_config_platform`、`npm_config_arch` 和 `npm_config_libc` 环境变量）来配置目标环境。

## WebAssembly

对提供多线程 Wasm 的运行时环境提供实验性支持。

在 Web 浏览器中不支持使用。

不支持本地文本渲染。

```sh
npm install --cpu=wasm32 sharp
```

## FreeBSD

在运行 `npm install` 之前，必须安装 `vips` 包。

```sh
pkg install -y pkgconf vips
```

```sh
cd /usr/ports/graphics/vips/ && make install clean
```

## Linux 内存分配器

大多数基于 glibc 的 Linux 系统（例如 Debian、Red Hat）上的默认内存分配器不适合长时间运行、涉及大量小内存分配的多线程进程。

因此，默认情况下，sharp 在运行时检测到 glibc 分配器时将限制线程基于 [并发](api-utility#concurrency) 的使用。

为了避免碎片化并提高这些系统上的性能，建议使用替代内存分配器，例如 [jemalloc](https://github.com/jemalloc/jemalloc)。

使用 musl 基于的 Linux（例如 Alpine）和非 Linux 系统的用户不受影响。

## AWS Lambda

[部署包](https://docs.aws.amazon.com/lambda/latest/dg/nodejs-package.html) 的 `node_modules` 目录必须包含适合选择的架构的 linux-x64 或 linux-arm64 平台的二进制文件。

在与目标架构不同的机器上构建部署包时，请参见 [跨平台](#cross-platform) 部分以帮助决定哪个包管理器合适以及如何配置。

某些包管理器使用符号链接，但 AWS Lambda 不支持在部署包中使用这些符号链接。

为了获得最佳性能，请选择可用的最大内存。1536 MB 的函数提供约 12 倍于 128 MB 函数的 CPU 时间。

与 AWS API Gateway 集成时，请确保其配置了相关的 [二进制媒体类型](https://docs.aws.amazon.com/apigateway/latest/developerguide/api-gateway-payload-encodings.html)。

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

对于 `serverless-esbuild`，请确保通过 `serverless.yml` 配置安装特定于平台的二进制文件。

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

确保使用 [asarUnpack](https://www.electron.build/configuration/configuration.html) 选项将 `sharp` 从 ASAR 存档文件中解压。

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

从 v0.32.0 开始，TypeScript 定义作为 `sharp` 包的一部分发布。

以前这些定义通过 `@types/sharp` 包提供，现在已被弃用。

在使用 TypeScript 时，请确保 `devDependencies` 包含 `@types/node` 包。

## 字体

当创建文本图像或渲染包含文本元素的 SVG 图像时，使用 `fontconfig` 查找相关字体。

在 Windows 和 macOS 系统上，所有系统字体均可用。

在使用 Homebrew 的 macOS 系统上，您可能需要将 `PANGOCAIRO_BACKEND` 环境变量设置为 `fontconfig` 的值，以确保它用于字体发现，而不是 Core Text。

在 Linux 系统上，通过包管理器安装时包含相关 [`fontconfig` 配置](https://www.freedesktop.org/software/fontconfig/fontconfig-user.html) 的字体可供使用。

如果未找到 `fontconfig` 配置，将发生以下错误：
```
Fontconfig error: Cannot load default config file
```

在无法控制字体包的无服务器环境中，使用 `FONTCONFIG_PATH` 环境变量指向自定义位置。

不支持嵌入的 SVG 字体。

## 已知冲突

### Canvas 和 Windows

如果在同一个 Windows 进程中同时使用 `canvas` 和 `sharp` 模块，可能会发生以下错误：
```
指定的过程找不到。
```