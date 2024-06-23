---
layout: post
title: Quick Start Guide
author: JeremyZhang
tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---
<!--more-->
# Development

To develop the project, you need to run it from the source. Therefore, using `Docker` or `npx` might not work well. The source code of our edition is stored on [GitHub](https://github.com/JeremyZXi/Silex).

To get started, open a terminal and navigate to the directory where you want the project to be located(you may ignore this step if you do not care):

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
Run dev/start
```sh
$ npm run dev
#or
$ npm run start
```
Sliex will be run on `http://localhost:6805`, and the hosting system on `http://localhost:8080/`
My understanding is that you need to modify the TypeScript files in the `src/` directory and then use `npm run build` to compile the code into a runnable format. 

