---
layout: post
title: 24/6/24 log grapesjs-tui-image-editor
author: JeremyZhang
feature-img: "assets/img/Screenshot 2024-06-24 at 11.45.29.png"              # Add a feature-image to the post
thumbnail: "assets/img/Screenshot 2024-06-24 at 11.45.29.png"  # Add a thumbnail image on blog view
tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---
Myself and My classmate Asa found out that it's hard to place images with proper size. This reminds me the GrapesJS plugin. I am trying to enhance the image related function with plugins, but I encountered several issues while integrating the GrapesJS plugin [`grapesjs-tui-image-editor`](https://github.com/GrapesJS/tui-image-editor).  <!--more-->
I added it to the client-side by modifying the `index.ts` file at `Silex/src/ts/client/grapesjs/index.ts`.

```javascript
import tuiImage from 'grapesjs-tui-image-editor';
// original code
const plugins = [
  { name: 'grapesjs-tui-image-editor', value: tuiImage },
// rest of the code
```

The UI and functionality work well and appear in the editor.

![screenshot](https://raw.githubusercontent.com/JeremyZXi/jeremyzxi.github.io/master/assets/img/Screenshot%202024-06-24%20at%2011.45.29.png)

However, I encountered the following issue when trying to publish a page that contains a image edited by the tui image editor to file system hosting:

```
PayloadTooLargeError: request entity too large
    at readStream (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/raw-body/index.js:163:17)
    at getRawBody (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/raw-body/index.js:116:12)
    at read (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/body-parser/lib/read.js:79:3)
    at jsonParser (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/body-parser/lib/types/json.js:138:5)
    at Layer.handle [as handle_request] (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/express/lib/router/layer.js:95:5)
    at trim_prefix (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/express/lib/router/index.js:328:13)
    at /Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/express/lib/router/index.js:286:9
    at Function.process_params (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/express/lib/router/index.js:346:12)
    at next (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/express/lib/router/index.js:280:10)
    at compression (/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/node_modules/compression/index.js:220:5)
```

Another error I ran into was
```
An error occured, your site is not published. Error publishing the website. ENAMETOOLONG: name too long, open '/Users/xiyan.zhang/IdeaProjects/silex_test4/Silex/silex/default/assets/data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAT4AAACzCAYAAAAQYXCCAAAAAXNSR0IArs4c6QAAIABJREFUeF7dnQm8ZVlV3vcbauyunulucERUECFxQIxzjIgRx8RZ0AQ1DAZRo0bFqIiAA4KKoCZqFMWIiRocQCPGiCgoKiggIgoqoEA30GN1dY0vfufedeq73/3W2vu+qgaS+4Nf17v3nL3XXsN/rb3PPudsXX755Xtt+dna2op/zv/d25t/Xvktjo3f9Vw+D/O2ubv+Rx8n/UdgmR94/eRc7W/7e3tlTHG766frH33vRs7d6S6XDNCMh6nI6d3p2Mea09XoU8cpzpSWzjZdfw8Xt
```
with a lot more behind...
I haven't figured out what operation will lead to either of the errors. In general, they appear if I use the tui-image-editor.

I asked this issue in the [silex community forum](https://community.silex.me/d/84-integrating-grapesjs-tui-image-editor), waiting for replies...


### some interesting stuff about grapesjs
https://medium.com/kunduzinc/how-to-publish-amazing-landing-pages-a820918c8a49