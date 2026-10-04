### 安全政策

在 npm 上发布的最新版本会获得安全更新支持。
```sh frame="none"
npm view sharp dist-tags.latest
```

如需报告漏洞，请使用[电子邮件](https://github.com/lovell/sharp/blob/main/package.json#L5)。
如果你是报告真实问题的人类，我们会在 48 小时内回复。
提前感谢。

### 安全特性

所有输入都被视为不受信任；如果解码尝试期间出现任何警告，输入将被拒绝。

各种输入格式可在运行时使用 [block](/api-utility/#block) 和 [unblock](/api-utility/#unblock) 进行控制。
例如，只允许 JPEG 输入：
```sh frame="none"
sharp.block({
  operation: ['VipsForeignLoad']
});
sharp.unblock({
  operation: ['VipsForeignLoadJpeg']
});
```

对于*受信任*的输入，可以使用以下构造函数选项来放宽各种与安全相关的检查。

- [failOn](/api-constructor/#:~:text=options.failOn)
- [limitInputPixels](/api-constructor/#:~:text=options.limitInputPixels)
- [limitInputChannels](/api-constructor/#:~:text=options.limitInputChannels)
- [unlimited](/api-constructor/#:~:text=options.unlimited)

预构建二进制文件中的 C、C++ 和 Rust 依赖项的最新版本会持续进行模糊测试。
潜在的安全问题会经过协调和修复，并在公开细节前发布修复信息。

### 安全注意事项

#### 减少内存相关漏洞的影响

高严重性问题通常与堆缓冲区溢出有关，其影响可以通过地址空间布局随机化（ASLR）来缓解。

当 Node.js 二进制文件是位置无关可执行文件（PIE）时，Linux 支持此功能，几乎所有操作系统包管理器都已使用此方式。

但请注意，[官方 Node.js 二进制文件](https://nodejs.org/download/release/)
并未以这种方式进行安全加固，在处理不受信任的内容时应避免使用。

#### 限制运行时资源

为了防止内存无限增长或 CPU 资源耗尽，请在控制组中运行 Node.js 进程，以限制资源消耗。
