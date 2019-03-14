
local Controller = require('mvc.Controller')
local LobbyController = class("LobbyController", Controller)

function LobbyController:ctor()
    cc.bind(self, 'event')
end

function LobbyController:viewDidLoad()
    self.view:layout()
end

function LobbyController:clickLogout(  )
    --[[
    local app = require('app.App'):instance()
    app:switch('LoginController')
    --]]

    self:pop('LoginController')
end

function LobbyController:pop(ctrlName, ...)
    local app = require("app.App"):instance()

    local ctrl = Controller.load(ctrlName, ...)
    dump(ctrl)
    ctrl:on("exit", function ()
      end)
    self:add(ctrl)

    local root = app.layers.ui
    root:addChild(ctrl.view)

    return ctrl
end

return LobbyController
