---
layout: post
title: Quick Start Guide
author: JeremyZhang
tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---
# Development

To develop the project, you need to run it from the source. Therefore, using `Docker` or `npx` might not work well. The source code of our edition is stored on [GitHub](https://github.com/JeremyZXi/Silex).

To get started, open a terminal and navigate to the directory where you want the project to be located:

```sh
$ cd <your chosen directory>
```

Next, clone the repository and navigate to the project directory:

```sh
$ git clone https://github.com/JeremyZXi/Silex.git
$ cd Silex
```

Install the project dependencies:

```sh
$ npm install
```

Build the project:

```sh
$ npm run build
```

My understanding is that you need to modify the TypeScript files in the `src/` directory and then use `npm run build` to compile the code into a runnable format. The plugin management for `GrapesJS` is located at `Silex/src/ts/client/grapesjs/index.ts`.

I added a `GrapesJS` plugin using the following code:

```javascript
import { yourPluginName } from 'your-plugin';
// rest of the code......
const plugins = [
    { name: 'your-plugin', value: yourPluginName },
];
```
The additional GrapesJS plugins that have been successfully integrated are:

```
grapesjs-tui-image-editor
grapesjs-typed
grapesjs-tabs
grapesjs-component-countdown
grapesjs-navbar
```

Additionally, I modified the options in `grapesjs-blocks-basic` to enable all blocks.
