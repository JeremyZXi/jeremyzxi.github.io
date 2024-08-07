---
layout: post
title: 24/6/25 log Connectors & Storage
author: JeremyZhang

tags: [Test, Keystone,CAS]
excerpt_separator: <!--more-->
---
Currently, there's two different solutions that might lead to our final product... 
<!--more-->First, if we are able to sort out the hosting system and the connector, we can connect the editor with github. In this case, the website our clients create will be store & host on their github acount as a github page. An Alternative plan for this would be: we open a sub-site for each user in the way of `xxx.example.com` where `xxx` is the user's uid or user name. The editor will be on `xxx.example.com/edit`. Essentially, `xxx.example.com/edit` is port `6805`, and `xxx.example.com` is port `8080`. 

Here I tried to add connectors to the editor, but it failed for some reason. Only FTP showed up, but the big one here should be gitlab...

```javascript
/*
 * Silex website builder, free/libre no-code tool for makers.
 * Copyright (c) 2023 lexoyo and Silex Labs foundation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @fileoverview This file is loaded by Silex at startup, after the user config if you specify one
 */

const SslPlugin = require('./dist/plugins/server/plugins/server/SslPlugin').default
const StaticPlugin = require('./dist/plugins/server/plugins/server/StaticPlugin').default

const { ConnectorType } = require('@silexlabs/silex/dist/server/types')
const FtpConnector = require('@silexlabs/silex/dist/plugins/server/plugins/server/FtpConnector').default
const GitlabConnector = require('@silexlabs/silex/dist/plugins/server/plugins/server/GitlabConnector').default
const DownloadConnector = require('@silexlabs/silex/dist/plugins/server/plugins/server/DownloadConnector').default
const GitlabHostingConnector = require('@silexlabs/silex/dist/plugins/server/plugins/server/GitlabHostingConnector').default
const dash = require('@silexlabs/silex-dashboard')
const {join} = require("path");

const env = {
  STORAGE_CONNECTORS: process.env.STORAGE_CONNECTORS || 'ftp,gitlab',
  HOSTING_CONNECTORS: process.env.HOSTING_CONNECTORS || 'ftp,gitlab,download',
  SILEX_FS_ROOT: process.env.SILEX_FS_ROOT || join(process.cwd(), '/silex/storage'),
  SILEX_FS_HOSTING_ROOT: process.env.SILEX_FS_HOSTING_ROOT || join(process.cwd(), '/silex/hosting'),
  GITLAB_DISPLAY_NAME: process.env.GITLAB_DISPLAY_NAME || 'Gitlab',
  GITLAB_CLIENT_ID: process.env.GITLAB_CLIENT_ID||'022e032f748835e641255572c028af6bdee07910cae7d0b897a7010b7f708709',
  GITLAB_CLIENT_SECRET: process.env.GITLAB_CLIENT_SECRET||'gloas-68a8a8880f620659bd50537652d0c915dadd1fbee0a3e784da44f1fdd57378ef',
  GITLAB_DOMAIN: process.env.GITLAB_DOMAIN||'https://gitlab.com',
  FTP_STORAGE_PATH: process.env.FTP_STORAGE_PATH || '/silex/storage',
  FTP_HOSTING_PATH: process.env.FTP_HOSTING_PATH || '/silex/hosting',

}
module.exports = async function(config, options) {
  try {
    await config.addPlugin([
      SslPlugin,
      StaticPlugin,
      dash
    ])
    initConnectors(config)

  } catch(e) {
    console.error(e)
  }

  // Return an object to be merged with Silex config
  return {}
}

function initConnectors(config) {
  // Add storage and hosting connectors from env vars
  if (env.STORAGE_CONNECTORS) {
    config.setStorageConnectors([])
    const connectors = env.STORAGE_CONNECTORS.split(',')
    connectors.forEach((connector) => {
      console.info('> Add storage connector from env var:', connector)
      switch (connector) {
        case 'fs':
          config.addStorageConnector(new FsStorage(config, {
            path: env.SILEX_FS_ROOT,
          }))
          break
        case 'gitlab':
          config.addStorageConnector(new GitlabConnector1(config, {
            clientId: env.GITLAB_CLIENT_ID,
            clientSecret: env.GITLAB_CLIENT_SECRET,
            domain: env.GITLAB_DOMAIN,
          }))
          break
        case 'ftp':
          config.addStorageConnector(new FtpConnector(config, {
            type: ConnectorType.STORAGE,
            path: env.FTP_STORAGE_PATH,
          }))
          break
        default:
          console.error('Unknown storage connector', connector)
          throw new Error(`Unknown storage connector ${connector}`)
      }
    })
  }

  if (env.HOSTING_CONNECTORS) {
    config.setHostingConnectors([])
    const connectors = env.HOSTING_CONNECTORS.split(',')
    connectors.forEach((connector) => {
      console.info('> Add hosting connector from env var:', connector)
      switch (connector) {
        case 'fs':
          config.addHostingConnector(new FsHosting(config, {
            path: env.SILEX_FS_HOSTING_ROOT,
          }))
          break
        case 'gitlab':
          config.addHostingConnector(new GitlabHostingConnector1(config, {
            clientId: env.GITLAB_CLIENT_ID,
            clientSecret: env.GITLAB_CLIENT_SECRET,
            domain: env.GITLAB_DOMAIN,
          }))
          break
        case 'gitlab2':
          config.addHostingConnector(new GitlabHostingConnector2(config, {
            clientId: env.GITLAB2_CLIENT_ID,
            clientSecret: env.GITLAB2_CLIENT_SECRET,
            domain: env.GITLAB2_DOMAIN,
          }))
          break
        case 'ftp':
          config.addHostingConnector(new FtpConnector(config, {
            type: ConnectorType.HOSTING,
            path: env.FTP_HOSTING_PATH,
          }))
          break
        case 'download':
          config.addHostingConnector(new DownloadConnector(config))
          break
        default:
          console.error('Unknown hosting connector', connector)
          throw new Error(`Unknown hosting connector ${connector}`)
      }
    })
  }
}
```