
local MainScene = class("MainScene", cc.load("mvc").ViewBase)



local function t_lpack(  )
    require ('pack')
    local num = 0x11
    local _ss = string.pack("b", num)
    print("字节数:",#_ss)
    local neS,valueS = string.unpack(_ss, "b")
    print("解包>>","?:",neS,"原数据",valueS)
    local _tmp = string.pack(">P", "世界那么大，我想去看看!!good!")
    print("字节数:",#_tmp)
    local nesT,valueT = string.unpack(_tmp,">P")
    print("解包>>","?:",nesT,"原数据",valueT)

    print(hex(valueT))
end

local function t_cjson(  )
    local cjson = require ('cjson')
    local data = {hello = 'world'}
    dump(data)
    dump(cjson.decode(cjson.encode({hello='world'})))
end

function MainScene:onCreate()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
        :move(display.cx, display.cy + 200)
        :addTo(self)

    t_lpack()
    t_cjson()

    local lfs = require "lfs"
    print (lfs._VERSION)
end

return MainScene
