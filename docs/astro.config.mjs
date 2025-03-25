// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

export default defineConfig({
  site: 'https://sharp.zhcndoc.com',
  integrations: [
    starlight({
      title: 'Sharp 中文文档',
      description:
        '高性能 Node.js 图像处理。最快的模块用于调整 JPEG、PNG、WebP 和 TIFF 图像的大小。',
      titleDelimiter: ' - ',
      defaultLocale: 'root',
      locales: {
        root: {
          label: '简体中文',
          lang: 'zh-CN',
        },
      },
      logo: {
        src: './src/assets/sharp-logo.svg',
        alt: '#'
      },
      customCss: ['./src/styles/custom.css'],
      head: [{
        tag: 'meta',
        attrs: {
          'http-equiv': 'Content-Security-Policy',
          content: "default-src 'self'; connect-src 'self'; object-src 'none'; style-src 'self' 'unsafe-inline'; img-src 'self' data: https://cdn.jsdelivr.net/gh/lovell/; script-src 'self' 'unsafe-inline' 'unsafe-eval' https://static.cloudflareinsights.com/beacon.min.js/;"
        }
      }, {
        tag: 'link',
        attrs: {
          rel: 'author',
          href: '/humans.txt',
          type: 'text/plain'
        }
      }, {
        tag: 'script',
        attrs: {
          async: true,
          href: 'https://www.zhcndoc.com/js/common.js',
        }
      }, {
        tag: 'script',
        attrs: {
          type: 'application/ld+json'
        },
        content: JSON.stringify({
          '@context': 'https://schema.org',
          '@type': 'SoftwareSourceCode',
          name: 'sharp',
          description: '高性能 Node.js 图像处理库',
          url: 'https://sharp.zhcndoc.com',
          codeRepository: 'https://github.com/lovell/sharp',
          programmingLanguage: ['JavaScript', 'C++'],
          runtimePlatform: 'Node.js',
          copyrightHolder: {
            '@context': 'https://schema.org',
            '@type': 'Person',
            name: 'Lovell Fuller'
          },
          copyrightYear: 2013,
          license: 'https://www.apache.org/licenses/LICENSE-2.0'
        })
      }],
      sidebar: [
        { label: '首页', link: '/' },
        { label: '安装', slug: 'install' },
        {
          label: 'API',
          items: [
            { label: '构造函数', slug: 'api-constructor' },
            { label: '输入元数据', slug: 'api-input' },
            { label: '输出选项', slug: 'api-output' },
            { label: '调整图像大小', slug: 'api-resize' },
            { label: '合成图像', slug: 'api-composite' },
            { label: '图像操作', slug: 'api-operation' },
            { label: '颜色操作', slug: 'api-colour' },
            { label: '频道操作', slug: 'api-channel' },
            { label: '全局属性', slug: 'api-utility' }
          ]
        },
        { label: '性能', slug: 'performance' },
        { label: '更新日志', slug: 'changelog' }
      ],
      social: {
        openCollective: 'https://opencollective.com/libvips',
        github: 'https://github.com/lovell/sharp'
      }
    })
  ]
});
