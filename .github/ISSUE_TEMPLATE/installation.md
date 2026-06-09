---
name: 安装
about: 在执行 `npm install sharp` 或 `import "sharp"` 时出现了问题
labels: installation

---

<!-- 请尽可能回答以下问题。 -->

## 可能的安装时或加载时问题

<!-- 请在复选框中填入 [x] 以确认。 -->

- [ ] 我已阅读并理解所有与安装相关的[文档](https://sharp.pixelplumbing.com/install)。
- [ ] 我已搜索与我所使用的包管理器相关的已知问题。

在继续之前，你必须确认以上两项。

### 你是否使用的是最新版的 sharp？

<!-- 请在复选框中填入 [x] 以确认。 -->

- [ ] 我使用的是 `npm view sharp dist-tags.latest` 所报告的最新版本 `sharp`。

如果你无法确认这一点，请先升级到最新版本并重试，然后再提交 issue。

如果你使用的是另一个依赖于非最新版本 `sharp` 的包，
请改为向该包提交 issue。

### 你是否使用受支持的运行时？

<!-- 请在相关复选框中填入 [x] 以确认。 -->

- [ ] 我使用的是满足 `>=20.9.0` 的 Node.js 版本
- [ ] 我使用的是 Deno
- [ ] 我使用的是 Bun

如果你无法确认以上任一项，
请先升级到最新版本
并重试，然后再提交 issue。

### 你是否使用受支持的包管理器，并安装了可选依赖？

<!-- 请在复选框中填入 [x] 以确认。 -->

- [ ] 我使用的是带有 `--include=optional` 的 npm >= 10.1.0
- [ ] 我使用的是 yarn >= 3.2.0
- [ ] 我使用的是带有 `--no-optional=false` 的 pnpm >= 7.1.0
- [ ] 我使用的是 Deno
- [ ] 我使用的是 Bun

如果你无法确认以上任一项，请先升级到你所选择的包管理器的最新版本，
并确保在提交 issue 前允许安装可选或多平台依赖。

### 完整的错误信息是什么，包括完整的堆栈跟踪？

<!-- 请在此处提供错误信息和堆栈跟踪。 -->

### 在空目录中运行 `npm install --verbose --foreground-scripts sharp` 的完整输出是什么？

<details>

<!-- 请在此处提供在空目录中运行 `npm install --verbose --foreground-scripts sharp` 的输出。 -->

</details>

### 运行 `npx envinfo --binaries --system --npmPackages=sharp --npmGlobalPackages=sharp` 的输出是什么？

<!-- 请在此处提供运行 `npx envinfo --binaries --system --npmPackages=sharp --npmGlobalPackages=sharp` 的输出。 -->
