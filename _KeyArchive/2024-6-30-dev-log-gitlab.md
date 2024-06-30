---
layout: post
title: 24/6/30 log Connectors & Storage
author: JeremyZhang

tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---


man what can i say.
<!--more-->
The dashboard suddenly went down by stop user from logging in.

```sh
Gitlab API error (1) 401 Unauthorized {
  url: 'https://gitlab.com/api/v4/user?access_token=undefined&',
  method: 'GET',
  body: null,
  params: {},
  text: '{"message":"401 Unauthorized"}',
  message: 'Unauthorized'
}
```

Specifically, once somebody authorizes the application, they will be redirected to the dashboard and instantly redirected back to the login page.

For some reason, destroy the old application and create a new one solved the issue....