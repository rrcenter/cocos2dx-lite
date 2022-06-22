cocos2dx-lite
=========



*NOTE*: 从开始，这个仓库只提供一个可运行的 lua 应用和一个重命名的工具。这样方便提供一个完整的程序，比如：

1. 登陆（微信、微博等）
2. 分享（微信、微博等）
3. 支付（微信、苹果支付等）
4. 广告 sdk（[AdMob](https://www.google.com/admob/)、 [Chartboost](https://www.chartboost.com/)、 [UnityAds](https://unityads.unity3d.com/admin/)）
5. 缺陷追踪工具 [bugly](https://bugly.qq.com/v2/) 等工具。
6. 统计分析 （[flurry](https://y.flurry.com/)、[umeng](www.umeng.com)）



去掉 3d 等功能不是因为要裁剪包的大小，是因为少代码，少运行点代码，程序稳定点。

提供这么多功能是有代价的，就是仓库很大。


## 工作流

原始的场景文件放在 `raw` 文件夹，每个场景一个 `.ccs` ，降低同时编辑场景文件时造成冲突。
一个 `mvc` 的文件目录结构:

```
raw
├── LobbyView.ccs
├── LobbyView.cfg
├── LobbyView.udf
├── cocosstudio
│   └── views
│       ├── LobbyView.csd
│       ├── LobbyView.udf
res
└── views
    ├── LobbyView.csb
src
├── app
│   ├── App.lua
│   ├── MyApp.lua
│   ├── controllers
│   │   ├── LobbyController.lua
│   └── views
│       ├── LobbyView.lua
│       └── MainScene.lua

```

使用 `creatormvc.py` 来创建以上文件。
快捷测试场景 `require('app.App'):instance():run('LobbyController')`



注意：其中场景文件为可选，如果没有场景文件，`View.ui` 节点下就没有场景。



2020.03.27 记：其实做这些代码清理的意义并不大。