---
name: Possible bug
about: sharp 的安装已成功，但随后在使用其某个功能时发生了意料之外的情况
labels: triage

---

<!-- 如果此问题与安装相关，请改用 https://github.com/lovell/sharp/issues/new?labels=installation&template=installation.md 。 -->

## 可能的 bug

### 这是否是 sharp 某个功能中的一个可能 bug，且与安装无关？

<!-- 请在方框中填写 [x] 以确认。 -->

- [ ] 运行 `npm install sharp` 完成时没有错误。
- [ ] 运行 `node -e "import 'sharp'"` 完成时没有错误。

如果你无法同时确认以上两点，请改为提交一个[安装问题](https://github.com/lovell/sharp/issues/new?labels=installation&template=installation.md)。

### 你是否正在使用 sharp 的最新版本？

<!-- 请在方框中填写 [x] 以确认。 -->

- [ ] 我使用的是 `sharp` 的最新版本，如 `npm view sharp dist-tags.latest` 所示。

如果你无法确认这一点，请先升级到最新版本并重试，然后再提交问题。

如果你使用的是另一个依赖于非最新 `sharp` 版本的包，请改为向该包提交问题。

### 运行 `npx envinfo --binaries --system --npmPackages=sharp --npmGlobalPackages=sharp` 的输出是什么？

<!-- 请在此处提供上述命令的输出。 -->

### 这个问题是否与文件缓存有关？

libvips 的默认行为是缓存输入文件，这可能会在 Windows 上导致 `EBUSY` 或 `EPERM` 错误。
使用 [`sharp.cache(false)`](https://sharp.pixelplumbing.com/api-utility#cache) 可关闭此功能。

- [ ] 添加 `sharp.cache(false)` 并不能解决此问题。

### 这个问题是否与图像看起来被旋转了 90 度有关？

包含 EXIF Orientation 元数据的图像不会自动按方向调整。默认情况下，EXIF 元数据会被移除。

- 要自动按像素值调整方向，请使用不带参数的 [`rotate()`](https://sharp.pixelplumbing.com/api-operation#rotate) 操作。
- 要保留 EXIF Orientation，请使用 [`keepExif()`](https://sharp.pixelplumbing.com/api-output#keepexif)。

- [ ] 使用 `rotate()` 或 `keepExif()` 并不能解决此问题。

### 复现步骤是什么？

<!-- 请在此处填写复现步骤。 -->

### 预期行为是什么？

<!-- 请在此处填写预期行为。 -->

### 请提供一个最小的、独立的代码示例，不依赖其他内容，用于演示这个问题

<!-- 请提供格式化后的代码，或提供一个仓库/gist 链接，以便他人复现。 -->

### 请提供有助于说明该问题的示例图片

<!-- 请在此处提供一个或多个图片链接。 -->
