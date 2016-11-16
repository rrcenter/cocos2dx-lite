
require("config")
require("framework.init")
local scheduler = require('framework.scheduler')

-- define global module
game = {}

function game.startup()
    cc.FileUtils:getInstance():addSearchPath("res/")
    display.addSpriteFrames('AllSprites.plist')
    game.benchmark()
end

function game.exit()
    os.exit()
end

function game.benchmark()
    local sharedDirector = cc.Director:getInstance()
    sharedDirector:setDisplayStats(DEBUG_FPS or true)
    local scene = cc.Scene:create()
    sharedDirector:runWithScene(scene)

    local size = sharedDirector:getWinSize()

    local label = cc.Label:createWithSystemFont("hello, cocos2dx-lite!", "sans", 64)
    -- local label = cc.Label:createWithTTF("Hello", "fonts/arial.ttf", 64)
    label:setPosition(size.width/2, size.height/2)
    scene:addChild(label)

    coil = require "coil"
    coil.add(function()
        for i = 1,5 do
            print("hello")
            coil.wait(1) -- wait 1s
        end
    end)

    scheduler.scheduleUpdateGlobal(function(dt)
        coil.update(dt)
    end)


    --
    local frames = display.newFrames("CoinSpin%02d.png", 1, 8)
    local animation = display.newAnimation(frames, 0.5 / 8) -- 0.5 秒播放 8 桢

    display.newSprite('')
        :center()
        :addTo(scene)
        :playForever(animation)
end
