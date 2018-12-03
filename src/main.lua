
package.path = '?.lua;src/?.lua;src/packages/?.lua'
local fs = cc.FileUtils:getInstance()
fs:setPopupNotify(false)

local STP = require "StackTracePlus"
local _traceback = debug.traceback
debug.traceback = STP.stacktrace

local winsize = cc.Director:getInstance():getWinSize()
local target = cc.Application:getInstance():getTargetPlatform()
__G__TRACKBACK__ = function ( msg )

    local message = msg
    local msg, origin_error = debug.traceback(msg, 3)
    print(msg)

    -- report lua exception
    if target == 4 or target == 5 then -- ios
        -- buglyReportLuaException(tostring(message), _traceback())
    elseif target == 2 then -- mac
        local indx = 2
        local info = debug.getinfo(indx)

        while info do
            if info.what == 'Lua' then break end
            indx = indx + 1
            info = debug.getinfo(indx)
        end

        local infoLabel = cc.Label:createWithSystemFont(message, 'sans', 32)
        infoLabel:setWidth(winsize.width)
        infoLabel:setAnchorPoint({x=0,y=1})
        infoLabel:setPosition(0, winsize.height)
        infoLabel:setTextColor({r=255,g=0,b=0,a=255})

        local scene = cc.Director:getInstance():getRunningScene()
        if not scene then
            scene = cc.Scene:create()
            cc.Director:getInstance():runWithScene(scene)
        end
        scene:addChild(infoLabel, 998)

        local function onTouchBegan(touch, event)
            return true
        end
        local function onTouchEnded(touch, event)
            -- use 'Subline Text' to edit the file
            local cmd = string.format('subl %s:%d', cc.FileUtils:getInstance():fullPathForFilename(info.source), info.currentline)
            os.execute(cmd)
            infoLabel:removeSelf()
        end

        local listener = cc.EventListenerTouchOneByOne:create()
        listener:registerScriptHandler(onTouchBegan,40)--cc.Handler.EVENT_TOUCH_BEGAN
        listener:registerScriptHandler(onTouchEnded,42)--cc.Handler.EVENT_TOUCH_ENDED
        local eventDispatcher = infoLabel:getEventDispatcher()
        eventDispatcher:addEventListenerWithSceneGraphPriority(listener, infoLabel)
    end

    return msg
end

local function main()
    require "config"
    require "cocos.init"

    require 'pack'
    require 'pbc.pbc'
    --
    math.randomseed( tonumber(tostring(os.time()):reverse():sub(1,6)) )

    -- require("app.MyApp"):create():run()

    local app = require('app.App'):instance()
    app:run('LoginController')

    local xxtea = require 'xxtea'
    local s = xxtea.encrypt('abc', 'xx')
    print(xxtea.decrypt(s, 'xx') == 'abc')

    local md5 = require 'md5'
    print(md5.sum('helloworld'))

    -- pbc test
    require 'test.pbctest'
    require 'test.bittest'

    --
    require 'test.cryptoNumbTest'
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    -- print(msg)
end
