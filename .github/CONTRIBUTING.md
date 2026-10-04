感谢你有兴趣参与贡献！

### 报告错误

请创建一个包含问题复现步骤的[新问题](https://github.com/lovell/sharp/issues)。
新错误在调查期间会被标记为 `triage`。

### 请求新功能

如果已经存在[类似请求](https://github.com/lovell/sharp/labels/enhancement)，
直接评论说明你的需求通常是最快的方式。
如果 libvips [已经支持](https://www.libvips.org/API/current/function-list.html)
所需功能，实现通常很直接。

### 提交修复错误的 Pull Request

谢谢！为防止问题再次发生，请添加原本会失败的单元测试。

请将 `main` 分支选为 Pull Request 的目标分支，以便将你的修复纳入下一个次版本发布。
请使用类似 `git rebase -i upstream/main` 的命令将你的更改压缩为一个提交。

从 ESM 构建 CJS：
```sh frame="none"
npm run build:dist
```

构建 C++：
```sh frame="none"
npm run build
```

### 提交包含新功能的 Pull Request

请添加用于覆盖新功能的 JavaScript [单元测试](https://github.com/lovell/sharp/tree/main/test/unit)。
在可行的情况下，功能测试使用基于 [dHash](http://www.hackerfactor.com/blog/index.php?/archives/529-Kind-of-Like-That.html)
的渐变感知哈希来比较预期图像与实际图像。
还请更新 [TypeScript 定义](https://github.com/lovell/sharp/tree/main/lib/index.d.ts)以及[类型定义测试](https://github.com/lovell/sharp/tree/main/test/types/sharp.test-d.ts)。

请使用类似 `git rebase -i upstream/<wip-branch>` 的命令将你的更改压缩为一个提交。
任何修改现有公共 API 的更改都应添加到相关的进行中分支，以便纳入下一个主版本。

欢迎你将自己的信息添加到[人员列表](https://github.com/lovell/sharp/blob/main/docs/public/humans.txt)。

#### 添加新的公共方法

API 尽可能采用流畅的调用方式。
图像处理概念遵循 libvips 的命名约定，在较小程度上也遵循 ImageMagick 的命名约定。
大多数方法都有可选参数，并采用合理的默认值。
请尽可能确保向后兼容。

修改公共 API 的 Pull Request 也请一并更新文档。
公共 API 通过带有 [JSDoc](https://jsdoc.app/) 注释的代码进行文档说明。
可以运行以下命令将其转换为 Markdown：
```sh frame="none"
npm run docs-build
```

如果想就 API 更改收集反馈，欢迎创建[新问题](https://github.com/lovell/sharp/issues)。

#### 移除现有公共方法

要移除的方法应在下一个主版本中弃用，然后在后续主版本中移除。
例如，v0.20.0 中的 `background()` 方法在 v0.21.0 中弃用，并在 v0.22.0 中移除。

### AI 贡献政策

#### 不要让 LLM 替你发言

问题和 Pull Request 中的评论和描述应使用你自己的措辞和声音来撰写。

与其追求拼写和语法无误，不如保持内容清晰、简洁且有人情味。
请勿使用或复制粘贴 LLM 生成的摘要。

#### 不要让 LLM 替你思考

你可以使用基于 LLM 的工具来探索想法并生成小段代码。
请确保你完全理解提交的代码，承担其法律责任，并能够对其进行推理。

为开源软件做贡献应帮助你以人的身份学习，也是成为长期维护者的重要一步。

### 最后

如需帮助，欢迎通过公开的[新问题](https://github.com/lovell/sharp/issues)寻求帮助。

如果你无法公开发布详细信息，请通过[电子邮件](https://github.com/lovell/sharp/blob/main/package.json#L5)
联系以获取付费的私人咨询。
