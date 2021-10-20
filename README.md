# BLUEDHOOK
  本项目支持 `Blued`、`Blued 极速版`。
  非越狱机型请通过 `Monkeydev` 环境打包 ipa 或 dylib/deb 进行重签名，越狱机型直接安装 release deb 即可。

## 已知问题
- 重签后不支持 apns 推送
同时安装 `Blued`、`Blued 极速版` 并登录同一账号，其中   `Blued` 安装 App Store 版用于接收推送，`Blued 极速版` 使用重签版本。不需要推送的可以忽略这些缺陷。
- 消息防撤回时必须保持在前台
错过原始消息后，服务器不会发送原始消息，这是消息通讯模型特性决定的，暂时没有很好的解决办法。

## see more
[初入iOSRE - 逆向全国最大同性交友App](https://iosre.com/t/topic/20694)
