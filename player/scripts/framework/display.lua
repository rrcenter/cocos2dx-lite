--[[

Copyright (c) 2011-2014 chukong-inc.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

--[[--

与显示图像、场景有关的功能

<br />

display 模块封装了绝大部分与显示有关的功能，并负责根据 config.lua 中定义的分辨率设定计算屏幕的设计分辨率。

<br />

框架初始化后，display 模块提供下列属性：

-   display.sizeInPixels.width,
-   display.sizeInPixels.height 屏幕的像素分辨率
-   display.widthInPixels,
-   display.heightInPixels 屏幕的像素分辨率
-   display.contentScaleFactor 内容缩放因子
-   display.size.width,
-   display.size.height 屏幕的设计分辨率
-   display.width,
-   display.height 屏幕的设计分辨率
-   display.cx,
-   display.cy 屏幕中央的 x 坐标和 y 坐标
-   display.left,
-   display.top,
-   display.right,
-   display.bottom 屏幕四边的坐标
-   display.c_left,
-   display.c_top,
-   display.c_right,
-   display.c_bottom 当父对象在屏幕中央时，屏幕四边的坐标

<br />

颜色：

-   display.COLOR_WHITE 白色, ccc3(255, 255, 255)
-   display.COLOR_BLACK 黑色, ccc3(0, 0, 0)

]]

local display = {}

local director = cc.Director:getInstance()
local textureCache = director:getTextureCache()
local spriteFrameCache = cc.SpriteFrameCache:getInstance()
local animationCache = cc.AnimationCache:getInstance()

-- check device screen size
local glview = director:getOpenGLView()
if nil == glview then
    glview = cc.GLViewImpl:createWithRect("QuickCocos",
        cc.rect(0, 0, CONFIG_SCREEN_WIDTH or 900, CONFIG_SCREEN_HEIGHT or 640))
    director:setOpenGLView(glview)
end

local size = glview:getFrameSize()
display.sizeInPixels = {width = size.width, height = size.height}

local w = display.sizeInPixels.width
local h = display.sizeInPixels.height

if CONFIG_SCREEN_WIDTH == nil or CONFIG_SCREEN_HEIGHT == nil then
    CONFIG_SCREEN_WIDTH = w
    CONFIG_SCREEN_HEIGHT = h
end

if not CONFIG_SCREEN_AUTOSCALE then
    if w > h then
        CONFIG_SCREEN_AUTOSCALE = "FIXED_HEIGHT"
    else
        CONFIG_SCREEN_AUTOSCALE = "FIXED_WIDTH"
    end
else
    CONFIG_SCREEN_AUTOSCALE = string.upper(CONFIG_SCREEN_AUTOSCALE)
end

local scale, scaleX, scaleY

if CONFIG_SCREEN_AUTOSCALE and CONFIG_SCREEN_AUTOSCALE ~="NONE" then
    if type(CONFIG_SCREEN_AUTOSCALE_CALLBACK) == "function" then
        scaleX, scaleY = CONFIG_SCREEN_AUTOSCALE_CALLBACK(w, h, device.model)
    end

    if CONFIG_SCREEN_AUTOSCALE == "FILL_ALL" then
        CONFIG_SCREEN_WIDTH = w
        CONFIG_SCREEN_HEIGHT = h
        scale = 1.0
        if cc.bPlugin_ then
            glview:setDesignResolutionSize(CONFIG_SCREEN_WIDTH, CONFIG_SCREEN_HEIGHT, cc.ResolutionPolicy.NO_BORDER)
        else
            glview:setDesignResolutionSize(CONFIG_SCREEN_WIDTH, CONFIG_SCREEN_HEIGHT, cc.ResolutionPolicy.FILL_ALL)
        end
    else
        if not scaleX or not scaleY then
            scaleX, scaleY = w / CONFIG_SCREEN_WIDTH, h / CONFIG_SCREEN_HEIGHT
        end

        if CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH" then
            scale = scaleX
            CONFIG_SCREEN_HEIGHT = h / scale
        elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT" then
            scale = scaleY
            CONFIG_SCREEN_WIDTH = w / scale
        else
            scale = 1.0
            printError(string.format("display - invalid CONFIG_SCREEN_AUTOSCALE \"%s\"", CONFIG_SCREEN_AUTOSCALE))
        end
        glview:setDesignResolutionSize(CONFIG_SCREEN_WIDTH, CONFIG_SCREEN_HEIGHT, cc.ResolutionPolicy.NO_BORDER)
    end
else
    CONFIG_SCREEN_WIDTH = w
    CONFIG_SCREEN_HEIGHT = h
    scale = 1.0
end

local winSize = director:getWinSize()
display.contentScaleFactor = director:getContentScaleFactor()
display.size               = {width = winSize.width, height = winSize.height}
display.width              = display.size.width
display.height             = display.size.height
display.cx                 = display.width / 2
display.cy                 = display.height / 2
display.c_left             = -display.width / 2
display.c_right            = display.width / 2
display.c_top              = display.height / 2
display.c_bottom           = -display.height / 2
display.left               = 0
display.right              = display.width
display.top                = display.height
display.bottom             = 0
display.center             = cc.p(display.cx, display.cy)
display.left_top           = cc.p(display.left, display.top)
display.left_bottom        = cc.p(display.left, display.bottom)
display.left_center        = cc.p(display.left, display.cy)
display.right_top          = cc.p(display.right, display.top)
display.right_bottom       = cc.p(display.right, display.bottom)
display.right_center       = cc.p(display.right, display.cy)
display.top_center         = cc.p(display.cx, display.top)
display.top_bottom         = cc.p(display.cx, display.bottom)

printInfo(string.format("# display.sizeInPixels         = {width = %0.2f, height = %0.2f}", display.sizeInPixels.width, display.sizeInPixels.height))
printInfo(string.format("# display.size                 = {width = %0.2f, height = %0.2f}", display.size.width, display.size.height))
printInfo(string.format("# display.contentScaleFactor   = %0.2f", display.contentScaleFactor))
printInfo(string.format("# display.width                = %0.2f", display.width))
printInfo(string.format("# display.height               = %0.2f", display.height))
printInfo(string.format("# display.cx                   = %0.2f", display.cx))
printInfo(string.format("# display.cy                   = %0.2f", display.cy))
printInfo(string.format("# display.left                 = %0.2f", display.left))
printInfo(string.format("# display.right                = %0.2f", display.right))
printInfo(string.format("# display.top                  = %0.2f", display.top))
printInfo(string.format("# display.bottom               = %0.2f", display.bottom))
printInfo(string.format("# display.c_left               = %0.2f", display.c_left))
printInfo(string.format("# display.c_right              = %0.2f", display.c_right))
printInfo(string.format("# display.c_top                = %0.2f", display.c_top))
printInfo(string.format("# display.c_bottom             = %0.2f", display.c_bottom))
printInfo(string.format("# display.center               = {x = %0.2f, y = %0.2f}", display.center.x, display.center.y))
printInfo(string.format("# display.left_top             = {x = %0.2f, y = %0.2f}", display.left_top.x, display.left_top.y))
printInfo(string.format("# display.left_bottom          = {x = %0.2f, y = %0.2f}", display.left_bottom.x, display.left_bottom.y))
printInfo(string.format("# display.left_center          = {x = %0.2f, y = %0.2f}", display.left_center.x, display.left_center.y))
printInfo(string.format("# display.right_top            = {x = %0.2f, y = %0.2f}", display.right_top.x, display.right_top.y))
printInfo(string.format("# display.right_bottom         = {x = %0.2f, y = %0.2f}", display.right_bottom.x, display.right_bottom.y))
printInfo(string.format("# display.right_center         = {x = %0.2f, y = %0.2f}", display.right_center.x, display.right_center.y))
printInfo(string.format("# display.top_center           = {x = %0.2f, y = %0.2f}", display.top_center.x, display.top_center.y))
printInfo(string.format("# display.top_bottom           = {x = %0.2f, y = %0.2f}", display.top_bottom.x, display.top_bottom.y))
printInfo("#")

function display.setAutoScale(configs)
    if type(configs) ~= "table" then return end

    checkResolution(configs)
    if type(configs.callback) == "function" then
        local c = configs.callback(framesize)
        for k, v in pairs(c or {}) do
            configs[k] = v
        end
        checkResolution(configs)
    end

    setDesignResolution(configs, framesize)

    printInfo(string.format("# design resolution size       = {width = %0.2f, height = %0.2f}", configs.width, configs.height))
    printInfo(string.format("# design resolution autoscale  = %s", configs.autoscale))
end

if type(CC_DESIGN_RESOLUTION) == "table" then
    display.setAutoScale(CC_DESIGN_RESOLUTION)
end

display.COLOR_WHITE = cc.c3b(255, 255, 255)
display.COLOR_BLACK = cc.c3b(0, 0, 0)
display.COLOR_RED   = cc.c3b(255, 0, 0)
display.COLOR_GREEN = cc.c3b(0, 255, 0)
display.COLOR_BLUE  = cc.c3b(0, 0, 255)

display.AUTO_SIZE      = 0
display.FIXED_SIZE     = 1
display.LEFT_TO_RIGHT  = 0
display.RIGHT_TO_LEFT  = 1
display.TOP_TO_BOTTOM  = 2
display.BOTTOM_TO_TOP  = 3

display.CENTER        = cc.p(0.5, 0.5)
display.LEFT_TOP      = cc.p(0, 1)
display.LEFT_BOTTOM   = cc.p(0, 0)
display.LEFT_CENTER   = cc.p(0, 0.5)
display.RIGHT_TOP     = cc.p(1, 1)
display.RIGHT_BOTTOM  = cc.p(1, 0)
display.RIGHT_CENTER  = cc.p(1, 0.5)
display.CENTER_TOP    = cc.p(0.5, 1)
display.CENTER_BOTTOM = cc.p(0.5, 0)

display.SCENE_TRANSITIONS = {
    CROSSFADE       = {cc.TransitionCrossFade},
    FADE            = {cc.TransitionFade, cc.c3b(0, 0, 0)},
    FADEBL          = {cc.TransitionFadeBL},
    FADEDOWN        = {cc.TransitionFadeDown},
    FADETR          = {cc.TransitionFadeTR},
    FADEUP          = {cc.TransitionFadeUp},
    FLIPANGULAR     = {cc.TransitionFlipAngular, cc.TRANSITION_ORIENTATION_LEFT_OVER},
    FLIPX           = {cc.TransitionFlipX, cc.TRANSITION_ORIENTATION_LEFT_OVER},
    FLIPY           = {cc.TransitionFlipY, cc.TRANSITION_ORIENTATION_UP_OVER},
    JUMPZOOM        = {cc.TransitionJumpZoom},
    MOVEINB         = {cc.TransitionMoveInB},
    MOVEINL         = {cc.TransitionMoveInL},
    MOVEINR         = {cc.TransitionMoveInR},
    MOVEINT         = {cc.TransitionMoveInT},
    PAGETURN        = {cc.TransitionPageTurn, false},
    ROTOZOOM        = {cc.TransitionRotoZoom},
    SHRINKGROW      = {cc.TransitionShrinkGrow},
    SLIDEINB        = {cc.TransitionSlideInB},
    SLIDEINL        = {cc.TransitionSlideInL},
    SLIDEINR        = {cc.TransitionSlideInR},
    SLIDEINT        = {cc.TransitionSlideInT},
    SPLITCOLS       = {cc.TransitionSplitCols},
    SPLITROWS       = {cc.TransitionSplitRows},
    TURNOFFTILES    = {cc.TransitionTurnOffTiles},
    ZOOMFLIPANGULAR = {cc.TransitionZoomFlipAngular},
    ZOOMFLIPX       = {cc.TransitionZoomFlipX, cc.TRANSITION_ORIENTATION_LEFT_OVER},
    ZOOMFLIPY       = {cc.TransitionZoomFlipY, cc.TRANSITION_ORIENTATION_UP_OVER},
}

display.TEXTURES_PIXEL_FORMAT = {}

display.DEFAULT_TTF_FONT        = "Arial"
display.DEFAULT_TTF_FONT_SIZE   = 32

-- start --

--------------------------------
-- 创建一个新场景，并返回 Scene 场景对象。
-- @function [parent=#display] newScene
-- @param string name 场景名称
-- @return Scene#Scene ret (return value: cc.Scene)  场景对象
-- @see Scene

-- end --

function display.newScene(name)
    local scene = cc.Scene:create()
    scene:setNodeEventEnabled(true)
    scene:setAutoCleanupEnabled()
    scene.name = name or "<unknown-scene>"
    return scene
end

-- start --

--------------------------------
-- 创建一个新场景，并返回 Scene 场景对象。
-- @function [parent=#display] newPhysicsScene
-- @param string name 场景名称
-- @return Scene#Scene ret (return value: cc.Scene)  场景对象
-- @see Scene

-- end --

function display.newPhysicsScene(name)
    local scene = cc.Scene:createWithPhysics()
    scene:setNodeEventEnabled(true)
    scene:setAutoCleanupEnabled()
    scene.name = name or "<unknown-scene>"
    return scene
end

--[[--

用场景切换过渡效果包装场景对象，并返回场景过渡对象。

~~~ lua

-- 创建一个新场景
local nextScene = display.newScene("NextScene")
-- 包装过渡效果
local transition = display.wrapSceneWithTransition(nextScene, "fade", 0.5)
-- 切换到新场景
display.replaceScene(nextScene)

~~~

可用的过渡效果有：

-   crossFade 淡出当前场景的同时淡入下一个场景
-   fade 淡出当前场景到指定颜色，默认颜色为 ccc3(0, 0, 0)，可用 wrapSceneWithTransition() 的最后一个参数指定颜色
-   fadeBL 从左下角开始淡出场景
-   fadeDown 从底部开始淡出场景
-   fadeTR 从右上角开始淡出场景
-   fadeUp 从顶部开始淡出场景
-   flipAngular 当前场景倾斜后翻转成下一个场景，默认从左边开始翻转，可以指定为：
    -   kCCTransitionOrientationLeftOver 从左边开始
    -   kCCTransitionOrientationRightOver 从右边开始
    -   kCCTransitionOrientationUpOver 从顶部开始
    -   kCCTransitionOrientationDownOver 从底部开始
-   flipX 水平翻转，默认从左往右翻转，可用的附加参数同上
-   flipY 垂直翻转，默认从上往下翻转，可用的附加参数同上
-   zoomFlipAngular 倾斜翻转的同时放大，可用的附加参数同上
-   zoomFlipX 水平翻转的同时放大，可用的附加参数同上
-   zoomFlipY 垂直翻转的同时放大，可用的附加参数同上
-   jumpZoom 跳跃放大切换场景
-   moveInB 新场景从底部进入，直接覆盖现有场景
-   moveInL 新场景从左侧进入，直接覆盖现有场景
-   moveInR 新场景从右侧进入，直接覆盖现有场景
-   moveInT 新场景从顶部进入，直接覆盖现有场景
-   pageTurn 翻页效果，如果指定附加参数为 true，则表示从左侧往右翻页
-   rotoZoom 旋转放大切换场景
-   shrinkGrow 收缩交叉切换场景
-   slideInB 新场景从底部进入，现有场景同时从顶部退出
-   slideInL 新场景从左侧进入，现有场景同时从右侧退出
-   slideInR 新场景从右侧进入，现有场景同时从左侧退出
-   slideInT 新场景从顶部进入，现有场景同时从底部退出
-   splitCols 分成多列切换入新场景
-   splitRows 分成多行切换入新场景，类似百叶窗
-   turnOffTiles 当前场景分成多个块，逐渐替换为新场景

@param CCScene scene 场景对象
@param string transitionType 过渡效果名
@param number time 过渡时间
@param string more 过渡效果附加参数

@return CCScene 场景对象

]]
function display.wrapSceneWithTransition(scene, transitionType, time, more)
    local key = string.upper(tostring(transitionType))
    if string.sub(key, 1, 12) == "CCTRANSITION" then
        key = string.sub(key, 13)
    end

    if key == "RANDOM" then
        local keys = table.keys(display.SCENE_TRANSITIONS)
        key = keys[math.random(1, #keys)]
    end

    if display.SCENE_TRANSITIONS[key] then
        local cls, count, default = unpack(display.SCENE_TRANSITIONS[key])
        time = time or 0.2

        if count == 3 then
            scene = cls:create(time, scene, more or default)
        else
            scene = cls:create(time, scene)
        end
    else
        printError("display.wrapSceneWithTransition() - invalid transitionType %s", tostring(transitionType))
    end
    return scene
end

--[[--

切换到新场景

~~~ lua

-- 使用红色做过渡色
display.replaceScene(nextScene, "fade", 0.5, ccc3(255, 0, 0))

~~~

@param CCScene newScene 场景对象
@param string transitionType 过渡效果名
@param number time 过渡时间
@param mixed more 过渡效果附加参数

]]
function display.replaceScene(newScene, transitionType, time, more)
    if director:getRunningScene() then
        if transitionType then
            newScene = display.wrapSceneWithTransition(newScene, transitionType, time, more)
        end
        director:replaceScene(newScene)
    else
        director:runWithScene(newScene)
    end
end

--[[--

返回当前正在运行的场景对象

@return CCScene 场景对象

]]
function display.getRunningScene()
    return director:getRunningScene()
end

--[[--

暂停当前场景

]]
function display.pause()
    director:pause()
end

--[[--

恢复当前暂停的场景

]]
function display.resume()
    director:resume()
end

--[[--

创建并返回一个 cc.Node 对象

cc.Node 对象并不能显示对象，但可以作为其他显示对象的容器（起到群组的作用）。具体请参考 cc.Node 。

~~~ lua

local group = display.newNode()     -- 创建一个容器
group:addChild(sprite1)             -- 添加显示对象到容器中
group:addChild(sprite2)             -- 添加显示对象到容器中

-- 移动容器时，其中包含的子对象也会同时移动
transition.moveBy(group, {time = 2.0, x = 100})

~~~

@return cc.Node cc.Node对象

@see cc.Node

]]
function display.newNode()
    return cc.Node:create()
end

--[[--

创建一个层

~~~ lua

-- 创建一个全屏的、黑颜色的层
display.newLayer()

-- 创建一个全屏、指定颜色的层
display.newLayer({r = 100, g = 100, b = 100, a = 200})

-- 创建一个指定宽高和颜色的层
display.newLayer({r = 100, g = 100, b = 100, a = 200}, {w = 100, h = 100})


~~~

@param mixed 附加参数
]]
function display.newLayer(...)
    local params = {...}
    local c = #params
    local layer
    if c == 0 then
        -- /** creates a fullscreen black layer */
        -- static Layer *create();
        layer = cc.Layer:create()
    elseif c == 1 then
        -- /** creates a Layer with color. Width and height are the window size. */
        -- static LayerColor * create(const Color4B& color);
        layer = cc.LayerColor:create(cc.convertColor(params[1], "4b"))
    elseif c == 2 then
        -- /** creates a Layer with color, width and height in Points */
        -- static LayerColor * create(const Color4B& color, const Size& size);
        --
        -- /** Creates a full-screen Layer with a gradient between start and end. */
        -- static LayerGradient* create(const Color4B& start, const Color4B& end);
        local color1 = cc.convertColor(params[1], "4b")
        local p2 = params[2]
        assert(type(p2) == "table" and (p2.width or p2.r), "display.newLayer() - invalid paramerter 2")
        if p2.r then
            layer = cc.LayerGradient:create(color1, cc.convertColor(p2, "4b"))
        else
            layer = cc.LayerColor:create(color1, p2.width, p2.height)
        end
    elseif c == 3 then
        -- /** creates a Layer with color, width and height in Points */
        -- static LayerColor * create(const Color4B& color, GLfloat width, GLfloat height);
        --
        -- /** Creates a full-screen Layer with a gradient between start and end in the direction of v. */
        -- static LayerGradient* create(const Color4B& start, const Color4B& end, const Vec2& v);
        local color1 = cc.convertColor(params[1], "4b")
        local p2 = params[2]
        local p2type = type(p2)
        if p2type == "table" then
            layer = cc.LayerGradient:create(color1, cc.convertColor(p2, "4b"), params[3])
        else
            layer = cc.LayerColor:create(color1, p2, params[3])
        end
    end
    return layer
end

-- start --

--------------------------------
-- 创建并返回一个 ClippingRectangleNode 对象。
-- @function [parent=#display] newClippingRectangleNode
-- @param table rect 指定的区域
-- @return ClippingRectangleNode#ClippingRectangleNode ret (return value: cc.ClippingRectangleNode)  ClippingRectangleNode


--[[--

创建并返回一个 ClippingRectangleNode 对象。

创建 ClippingRectangleNode 对象时需要指定一个屏幕区域，然后在显示时，所以加入 ClippingRectangleNode 对象的内容都会进行剪裁，超出指定区域的内容不会显示。

~~~ lua

-- 剪裁区域从屏幕左下角靠内 100 点，到屏幕右上角
local rect = cc.rect(display.left + 100,
                    display.bottom + 100,
                    display.width - 200,
                    display.height - 200)
local clipnode = display.newClippingRegionNode(rect)

clipnode:addChild(sprite1)
clipnode:addChild(sprite2)

scene:addChild(clipnode)

~~~

注意：ClippingRectangleNode 的父对象其坐标必须是 0, 0。

]]
-- end --

if cc.ClippingRectangleNode then
    cc.ClippingRegionNode = cc.ClippingRectangleNode
else
    cc.ClippingRectangleNode = cc.ClippingRegionNode
end

function display.newClippingRectangleNode(rect)
    if rect then
        return cc.ClippingRegionNode:create(rect)
    else
        return cc.ClippingRegionNode:create()
    end
end

-- start --

--------------------------------
-- 创建并返回一个 Sprite 显示对象。
-- @function [parent=#display] newSprite
-- @param mixed 图像名或SpriteFrame对象
-- @param number x
-- @param number y
-- @param table params
-- @return Sprite#Sprite ret (return value: cc.Sprite)
-- @see Sprite


--[[--

创建并返回一个 Sprite 显示对象。

display.newSprite() 有三种方式创建显示对象：

-   从图片文件创建
-   从缓存的图像帧创建
-   从 SpriteFrame 对象创建

~~~ lua

-- 从图片文件创建显示对象
local sprite1 = display.newSprite("hello1.png")

-- 从缓存的图像帧创建显示对象
-- 图像帧的名字就是图片文件名，但为了和图片文件名区分，所以此处需要在文件名前添加 “#” 字符
-- 添加 “#” 的规则适用于所有需要区分图像和图像帧的地方
local sprite2 = display.newSprite("#frame0001.png")

-- 从 SpriteFrame 对象创建
local frame = display.newFrame("frame0002.png")
local sprite3 = display.newSprite(frame)

~~~

如果指定了 x,y 参数，那么创建显示对象后会调用对象的 setPosition() 方法设置对象位置。

]]
-- end --
function display.newSprite(filename, x, y, params)
    local spriteClass = nil
    local size = nil

    if params then
        spriteClass = params.class
        size = params.size
    end
    if not spriteClass then spriteClass = cc.Sprite end

    local t = type(filename)
    if t == "userdata" then t = tolua.type(filename) end
    local sprite

    if not filename or filename == '' then
        sprite = spriteClass:create()
    elseif t == "string" then
        if string.byte(filename) == 35 then -- first char is #
            local frame = display.newSpriteFrame(string.sub(filename, 2))
            if frame then
                if params and params.capInsets then
                    sprite = spriteClass:createWithSpriteFrame(frame, params.capInsets)
                else
                    sprite = spriteClass:createWithSpriteFrame(frame)
                end
            end
        else
            if display.TEXTURES_PIXEL_FORMAT[filename] then
                cc.Texture2D:setDefaultAlphaPixelFormat(display.TEXTURES_PIXEL_FORMAT[filename])
                sprite = spriteClass:create(filename)
                cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2D_PIXEL_FORMAT_RGBA8888)
            else
                if params and params.capInsets then
                    sprite = spriteClass:create(params.capInsets, filename)
                else
                    sprite = spriteClass:create(filename)
                end
            end
        end
    elseif t == "cc.SpriteFrame" then
        sprite = spriteClass:createWithSpriteFrame(filename)
    elseif t == "cc.Texture2D" then
        sprite = spriteClass:createWithTexture(filename)
    else
        printError("display.newSprite() - invalid filename value type")
        sprite = spriteClass:create()
    end

    if sprite then
        if x and y then sprite:setPosition(x, y) end
        if size then sprite:setContentSize(size) end
    else
        printError("display.newSprite() - create sprite failure, filename %s", tostring(filename))
        sprite = spriteClass:create()
    end

    return sprite
end

-- start --

--------------------------------
-- 创建并返回一个 Sprite9Scale 显示对象。
-- @function [parent=#display] newScale9Sprite
-- @param string filename 图像名
-- @param integer x
-- @param integer y
-- @param table size
-- @return Scale9Sprite#Scale9Sprite ret (return value: ccui.Scale9Sprite) Sprite9Scale显示对象


--[[--

创建并返回一个 Sprite9Scale 显示对象。

格式：

sprite = display.newScale9Sprite(图像名, [x, y], [size 对象])

Sprite9Scale 就是通常所說的“九宫格”图像。一个矩形图像会被分为 9 部分，然后根据要求拉伸图像，同时保证拉伸后的图像四边不变形。

~~~ lua

-- 创建一个 Scale9 图像，并拉伸到 400, 300 点大小
local sprite = display.newScale9Sprite("Box.png", 0, 0, cc.size(400, 300))

~~~

]]
-- end --

function display.newScale9Sprite(filename, x, y, size, capInsets)
    local scale9sp = ccui.Scale9Sprite or cc.Scale9Sprite
    return display.newSprite(filename, x, y, {class = scale9sp, size = size, capInsets = capInsets})
end


-- start --

--------------------------------
-- 将指定的 Sprite Sheets 材质文件及其数据文件载入图像帧缓存。
-- @function [parent=#display] addSpriteFrames
-- @param string plistFilename 数据文件名
-- @param string image 材质文件名
-- @see Sprite Sheets


--[[--

将指定的 Sprite Sheets 材质文件及其数据文件载入图像帧缓存。

格式：

display.addSpriteFrames(数据文件名, 材质文件名)

~~~ lua

-- 同步加载纹理
display.addSpriteFrames("Sprites.plist", "Sprites.png")

-- 异步加载纹理
local cb = function(plist, image)
    -- do something
end
display.addSpriteFrames("Sprites.plist", "Sprites.png", cb)

~~~

Sprite Sheets 通俗一点解释就是包含多张图片的集合。Sprite Sheets 材质文件由多张图片组成，而数据文件则记录了图片在材质文件中的位置等信息。

]]
-- end --

function display.addSpriteFrames(plistFilename, image, handler)
    local async = type(handler) == "function"
    local asyncHandler = nil
    if async then
        asyncHandler = function()
            local texture = textureCache:getTextureForKey(image)
            assert(texture, string.format("The texture %s, %s is unavailable.", plistFilename, image))
            spriteFrameCache:addSpriteFrames(plistFilename, texture)
            handler(plistFilename, image)
        end
    end

    if display.TEXTURES_PIXEL_FORMAT[image] then
        cc.Texture2D:setDefaultAlphaPixelFormat(display.TEXTURES_PIXEL_FORMAT[image])
        if async then
            textureCache:addImageAsync(image, asyncHandler)
        else
            spriteFrameCache:addSpriteFrames(plistFilename, image)
        end
        cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_BGR_A8888)
    else
        if async then
            textureCache:addImageAsync(image, asyncHandler)
        else
            if image then
                spriteFrameCache:addSpriteFrames(plistFilename, image)
            else
                spriteFrameCache:addSpriteFrames(plistFilename)
            end
        end
    end
end

--[[--

创建并返回一个图像帧对象。

~~~ lua

display.addSpriteFramesWithFile("Sprites.plist", "Sprites.png")

-- 创建一个 CCSprite
local sprite = display.newSprite("#Yes.png")

-- 创建一个图像帧
local frameNo = display.newSpriteFrame("No.png")

-- 在需要时，修改 CCSprite 的显示内容
sprite:setDisplayFrame(frameNo)

~~~

@param string 图像帧名称

@return CCSpriteFrameCache

]]
function display.newSpriteFrame(frameName)
    local frame = spriteFrameCache:getSpriteFrame(frameName)
    if not frame then
        printError("display.newSpriteFrame() - invalid frameName %s", tostring(frameName))
    end
    return frame
end


--[[--

以特定模式创建一个包含多个图像帧对象的数组。

~~~ lua

-- 创建一个数组，包含 Walk0001.png 到 Walk0008.png 的 8 个图像帧对象
local frames = display.newFrames("Walk%04d.png", 1, 8)

-- 创建一个数组，包含 Walk0008.png 到 Walk0001.png 的 8 个图像帧对象
local frames = display.newFrames("Walk%04d.png", 1, 8, true)

~~~

@param string pattern 模式字符串
@param integer begin 起始索引
@param integer length 长度
@param boolean isReversed 是否是递减索引

@return table 图像帧数组

]]
function display.newFrames(pattern, begin, length, isReversed)
    local frames = {}
    local step = 1
    local last = begin + length - 1
    if isReversed then
        last, begin = begin, last
        step = -1
    end

    for index = begin, last, step do
        local frameName = string.format(pattern, index)
        local frame = spriteFrameCache:getSpriteFrame(frameName)
        if not frame then
            error(string.format("display.newFrames() - invalid frame name %s", tostring(frameName)), 0)
        end
        frames[#frames + 1] = frame
    end
    return frames
end

--[[--

以包含图像帧的数组创建一个动画对象。

~~~ lua

local frames = display.newFrames("Walk%04d.png", 1, 8)
local animation = display.newAnimation(frames, 0.5 / 8) -- 0.5 秒播放 8 桢
sprite:playAnimationOnce(animation) -- 播放一次动画

~~~

@param table frames 图像帧的数组
@param number time 每一桢动画之间的间隔时间


@return CCAnimation CCAnimation对象

]]
function display.newAnimation(frames, time)
    local count = #frames
    time = time or 1.0 / count
    return cc.Animation:createWithSpriteFrames(frames, time)
end

function display.loadImage(imageFilename, callback)
    if not callback then
        return textureCache:addImage(imageFilename)
    else
        textureCache:addImageAsync(imageFilename, callback)
    end
end

local fileUtils = cc.FileUtils:getInstance()
function display.getImage(imageFilename)
    local fullpath = fileUtils:fullPathForFilename(imageFilename)
    return textureCache:getTextureForKey(fullpath)
end

function display.removeImage(imageFilename)
    textureCache:removeTextureForKey(imageFilename)
end

function display.loadSpriteFrames(dataFilename, imageFilename, callback)
    if display.TEXTURES_PIXEL_FORMAT[imageFilename] then
        cc.Texture2D:setDefaultAlphaPixelFormat(display.TEXTURES_PIXEL_FORMAT[imageFilename])
    end
    if not callback then
        spriteFrameCache:addSpriteFrames(dataFilename, imageFilename)
    else
        spriteFrameCache:addSpriteFramesAsync(dataFilename, imageFilename, callback)
    end
    if display.TEXTURES_PIXEL_FORMAT[imageFilename] then
        cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_BGR_A8888)
    end
end

function display.removeSpriteFrames(dataFilename, imageFilename)
    spriteFrameCache:removeSpriteFramesFromFile(dataFilename)
    if imageFilename then
        display.removeImage(imageFilename)
    end
end

function display.removeSpriteFrame(imageFilename)
    spriteFrameCache:removeSpriteFrameByName(imageFilename)
end

function display.setTexturePixelFormat(imageFilename, format)
    display.TEXTURES_PIXEL_FORMAT[imageFilename] = format
end

function display.setAnimationCache(name, animation)
    animationCache:addAnimation(animation, name)
end

function display.getAnimationCache(name)
    return animationCache:getAnimation(name)
end

function display.removeAnimationCache(name)
    animationCache:removeAnimation(name)
end

function display.removeUnusedSpriteFrames()
    spriteFrameCache:removeUnusedSpriteFrames()
    textureCache:removeUnusedTextures()
end

--[[--

将指定的显示对象按照特定锚点对齐。

格式：

display.align(显示对象, 锚点位置, [x, y])

显示对象锚点位置：

-   display.CENTER 图像中央
-   display.LEFT_TOP,
-   display.TOP_LEFT 图像左上角
-   display.CENTER_TOP,
-   display.TOP_CENTER 图像顶部的中间
-   display.RIGHT_TOP,
-   display.TOP_RIGHT 图像顶部的中间
-   display.CENTER_LEFT,
-   display.LEFT_CENTER 图像左边的中间
-   display.CENTER_RIGHT,
-   display.RIGHT_CENTER 图像右边的中间
-   display.BOTTOM_LEFT,
-   display.LEFT_BOTTOM 图像左边的底部
-   display.BOTTOM_RIGHT,
-   display.RIGHT_BOTTOM 图像右边的底部
-   display.BOTTOM_CENTER,
-   display.CENTER_BOTTOM 图像中间的底部

~~~ lua

-- 将图像按左上角对齐，并放置在屏幕左上角
display.align(sprite, display.LEFT_TOP, 0, 0)

~~~

@param CCSprite target 显示对象
@param integer anchorPoint 锚点位置
@param integer x
@param integer y

]]
function display.align(target, anchorPoint, x, y)
    target:setAnchorPoint(display.ANCHOR_POINTS[anchorPoint])
    if x and y then target:setPosition(x, y) end
end

return display
