
cocos2dx-lite
=========

[中文](https://github.com/c0i/cocos2dx-lite/blob/master/README_zh.md)

*NOTE* : From [tag v5](https://github.com/c0i/cocos2dx-lite/tree/v5), this repo remove all *templates*, just provide a runable lua app and a tool for rename the app.

It bases on [cocos2d-x](https://github.com/cocos2d/cocos2d-x) v3 branch, but remove 3D and other features.
It works on iOS, Android, macOSand Windows.

The major change:

- Only support iOS,OS X,Android and Windows.
- Remove 3D features
- Remove support for JS script
- Remove deprecated classes and functions
- Remove Camera
- Remove Physics integration
- Remove C++ implementations of Component
- ~~Remove C++ implementations of CocoStudio parser~~
- Remove C++ implementations of CocosBuilder parser
- Remove AssetsManager, AssetsManagerEX
- Remove support for WebP,S3TC,ATITC
- ~~Remove FastTileMap, TileMap~~
- Remove *Menu*
- Improve module compile `cocos/base/ccConfigUser.h`
- Improve curl library, only support `socket` and `http` protocol
- Add [CC_MINI_2D / CC_USE_FREETYPE / CC_ONLY_PNG](https://github.com/c0i/cocos2dx-lite/blob/master/cocos/base/ccConfigUser.h)
- Add CC_USE_SPINE
- Add CC_USE_AUDIO_ENGINE
- Add CC_USE_NETWORK
- Restore ui module (NOT depend CocoStudio)
- Restore `Focus` event (need by `ui`)
- Restore `CocoStudio` module
- Keep working with `CocosStudio` after 3.14.1 ([https://github.com/cocos2d/cocos2d-x/pull/17349#issuecomment-279629919](https://github.com/cocos2d/cocos2d-x/pull/17349#issuecomment-279629919))



### Lua

0.  [lua 5.1.x](https://www.lua.org/) as default, not [LuaJIT](http://luajit.org/)
1.  [lua-cjson](https://github.com/mpx/lua-cjson)
2.  [luafilesystem Version 1.7.0 [15/Sep/2017]](https://github.com/keplerproject/luafilesystem)
3.  [lpeg](http://www.inf.puc-rio.br/~roberto/lpeg/)
4.  [lpack](https://github.com/LuaDist/lpack)
5.  [luasocket](https://github.com/diegonehab/luasocket)
6.  [lsocket 1.4.1](http://tset.de/lsocket/index.html)
7.  [pbc](https://github.com/cloudwu/pbc)
8.  [LuaBitOp 1.0.2](http://bitop.luajit.org/)

## How to start

1. setup env

    ```
    $ # clone repo
    $ git clone https://github.com/c0i/cocos2dx-lite.git
    $ cd cocos2dx-lite
    $ ./setup.py
    $ source ~/.bash_profile
    ```

2. try with player project

    ```
    $ open player/proj.ios_mac/player.xcodeproj/
    $ or
    $ cocos run -p mac # ios, android
    ```

## Contributing to the Project

Cocos2dx-lite is licensed under the [MIT License](https://opensource.org/licenses/MIT). We welcome participation!

## Others

There are lots of better cocos2d-x forks:

- https://github.com/stubma/cocos2dx-classical (v2)
- https://github.com/IppClub/Dorothy (v2)
- https://github.com/Sheado/cocos2d-x (v3)
- https://github.com/mafiagame/quick-cocos2d-x (v3)
