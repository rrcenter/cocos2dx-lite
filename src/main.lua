
cc.FileUtils:getInstance():setPopupNotify(false)

require "config"
require "cocos.init"

function hex(s)
    s = string.gsub(s,"(.)",function (x) return string.format("%02X",string.byte(x)) end)
    return s
end

local function main()
    --
    math.randomseed( tonumber(tostring(os.time()):reverse():sub(1,6)) )

    require("app.MyApp"):create():run()
    print('hello')
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
