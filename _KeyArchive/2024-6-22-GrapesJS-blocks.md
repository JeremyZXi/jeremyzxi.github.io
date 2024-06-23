---
layout: post
title: Integration of GrapesJS plugins
author: JeremyZhang
tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---
The plugin management for `GrapesJS` is located at `Silex/src/ts/client/grapesjs/index.ts`.
<!--more-->
I added a `GrapesJS` plugin using the following code:

```javascript
import { yourPluginName } from 'your-plugin';
// rest of the code......
const plugins = [
    { name: 'your-plugin', value: yourPluginName },
];
```
![Figure1]({{ "_KeyArchive/image/GrapesJSBlocks-24-6-22.png" | relative_url}})
The additional GrapesJS plugins that have been successfully integrated are:

```
grapesjs-tui-image-editor
grapesjs-typed
grapesjs-tabs
grapesjs-component-countdown
grapesjs-navbar
```

Additionally, I modified the options in `grapesjs-blocks-basic` to enable all blocks.

