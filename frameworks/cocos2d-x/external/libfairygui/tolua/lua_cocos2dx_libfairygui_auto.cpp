#include "lua_cocos2dx_libfairygui_auto.hpp"
#include "FairyGUI.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_libfairygui_UIConfig_registerFont(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIConfig:registerFont");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.UIConfig:registerFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIConfig_registerFont'", nullptr);
            return 0;
        }
        fairygui::UIConfig::registerFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIConfig:registerFont",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIConfig_registerFont'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIConfig_getRealFontName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIConfig:getRealFontName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIConfig_getRealFontName'", nullptr);
            return 0;
        }
        const std::string& ret = fairygui::UIConfig::getRealFontName(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIConfig:getRealFontName");
        #pragma warning NO CONVERSION TO NATIVE FOR bool*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIConfig_getRealFontName'", nullptr);
            return 0;
        }
        const std::string& ret = fairygui::UIConfig::getRealFontName(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIConfig:getRealFontName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIConfig_getRealFontName'.",&tolua_err);
#endif
    return 0;
}
static int lua_libfairygui_UIConfig_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIConfig)");
    return 0;
}

int lua_register_libfairygui_UIConfig(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.UIConfig");
    tolua_cclass(tolua_S,"UIConfig","fgui.UIConfig","",nullptr);

    tolua_beginmodule(tolua_S,"UIConfig");
        tolua_function(tolua_S,"registerFont", lua_libfairygui_UIConfig_registerFont);
        tolua_function(tolua_S,"getRealFontName", lua_libfairygui_UIConfig_getRealFontName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::UIConfig).name();
    g_luaType[typeName] = "fgui.UIConfig";
    g_typeCast["UIConfig"] = "fgui.UIConfig";
    return 1;
}

int lua_libfairygui_UIEventDispatcher_isDispatchingEvent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIEventDispatcher_isDispatchingEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:isDispatchingEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_isDispatchingEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->isDispatchingEvent(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIEventDispatcher:isDispatchingEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIEventDispatcher_isDispatchingEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIEventDispatcher_dispatchEvent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIEventDispatcher_dispatchEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:dispatchEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_dispatchEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->dispatchEvent(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        void* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:dispatchEvent");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_dispatchEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->dispatchEvent(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        void* arg1;
        cocos2d::Value arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:dispatchEvent");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ccvalue(tolua_S, 4, &arg2, "fgui.UIEventDispatcher:dispatchEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_dispatchEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->dispatchEvent(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIEventDispatcher:dispatchEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIEventDispatcher_dispatchEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIEventDispatcher_bubbleEvent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIEventDispatcher_bubbleEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:bubbleEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_bubbleEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->bubbleEvent(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        void* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:bubbleEvent");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_bubbleEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->bubbleEvent(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        void* arg1;
        cocos2d::Value arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIEventDispatcher:bubbleEvent");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ccvalue(tolua_S, 4, &arg2, "fgui.UIEventDispatcher:bubbleEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_bubbleEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->bubbleEvent(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIEventDispatcher:bubbleEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIEventDispatcher_bubbleEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIEventDispatcher_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIEventDispatcher_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::UIEventDispatcher();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.UIEventDispatcher");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIEventDispatcher:UIEventDispatcher",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIEventDispatcher_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_UIEventDispatcher_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIEventDispatcher)");
    return 0;
}

int lua_register_libfairygui_UIEventDispatcher(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.UIEventDispatcher");
    tolua_cclass(tolua_S,"UIEventDispatcher","fgui.UIEventDispatcher","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"UIEventDispatcher");
        tolua_function(tolua_S,"new",lua_libfairygui_UIEventDispatcher_constructor);
        tolua_function(tolua_S,"isDispatchingEvent",lua_libfairygui_UIEventDispatcher_isDispatchingEvent);
        tolua_function(tolua_S,"dispatchEvent",lua_libfairygui_UIEventDispatcher_dispatchEvent);
        tolua_function(tolua_S,"bubbleEvent",lua_libfairygui_UIEventDispatcher_bubbleEvent);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::UIEventDispatcher).name();
    g_luaType[typeName] = "fgui.UIEventDispatcher";
    g_typeCast["UIEventDispatcher"] = "fgui.UIEventDispatcher";
    return 1;
}

int lua_libfairygui_GObject_setGroup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GGroup* arg0;

        ok &= luaval_to_object<fairygui::GGroup>(tolua_S, 2, "fgui.GGroup",&arg0, "fgui.GObject:setGroup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setGroup'", nullptr);
            return 0;
        }
        cobj->setGroup(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setGroup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getSortingOrder(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getSortingOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getSortingOrder'", nullptr);
            return 0;
        }
        int ret = cobj->getSortingOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getSortingOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getSortingOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isGrayed'", nullptr);
            return 0;
        }
        bool ret = cobj->isGrayed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isGrayed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getGroup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getGroup'", nullptr);
            return 0;
        }
        fairygui::GGroup* ret = cobj->getGroup();
        object_to_luaval<fairygui::GGroup>(tolua_S, "fgui.GGroup",(fairygui::GGroup*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_treeNode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_treeNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_treeNode'", nullptr);
            return 0;
        }
        fairygui::GTreeNode* ret = cobj->treeNode();
        object_to_luaval<fairygui::GTreeNode>(tolua_S, "fgui.GTreeNode",(fairygui::GTreeNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:treeNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_treeNode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setRotation(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setRotation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setRotation'", nullptr);
            return 0;
        }
        cobj->setRotation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setRotation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setPixelSnapping(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setPixelSnapping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:setPixelSnapping");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setPixelSnapping'", nullptr);
            return 0;
        }
        cobj->setPixelSnapping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setPixelSnapping",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setPixelSnapping'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setScaleY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setScaleY'", nullptr);
            return 0;
        }
        cobj->setScaleY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setScaleY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setScaleX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setScaleX'", nullptr);
            return 0;
        }
        cobj->setScaleX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setScaleX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isPixelSnapping(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isPixelSnapping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isPixelSnapping'", nullptr);
            return 0;
        }
        bool ret = cobj->isPixelSnapping();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isPixelSnapping",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isPixelSnapping'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setDraggable(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setDraggable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:setDraggable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setDraggable'", nullptr);
            return 0;
        }
        cobj->setDraggable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setDraggable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setDraggable'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setYMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setYMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setYMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setYMin'", nullptr);
            return 0;
        }
        cobj->setYMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setYMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setYMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setXMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setXMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setXMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setXMin'", nullptr);
            return 0;
        }
        cobj->setXMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setXMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setXMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_onStage(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_onStage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_onStage'", nullptr);
            return 0;
        }
        bool ret = cobj->onStage();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:onStage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_onStage'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getIcon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getIcon'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getIcon();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getIcon",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setPivot(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setPivot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setPivot");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setPivot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setPivot'", nullptr);
            return 0;
        }
        cobj->setPivot(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setPivot");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setPivot");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.GObject:setPivot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setPivot'", nullptr);
            return 0;
        }
        cobj->setPivot(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setPivot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setPivot'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getAlpha(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getAlpha'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getAlpha'", nullptr);
            return 0;
        }
        double ret = cobj->getAlpha();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getAlpha",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getAlpha'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setSkewX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setSkewX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setSkewX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setSkewX'", nullptr);
            return 0;
        }
        cobj->setSkewX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setSkewX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setSkewX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setSkewY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setSkewY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setSkewY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setSkewY'", nullptr);
            return 0;
        }
        cobj->setSkewY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setSkewY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setSkewY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setSize");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setSize'", nullptr);
            return 0;
        }
        cobj->setSize(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setSize");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setSize");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.GObject:setSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setSize'", nullptr);
            return 0;
        }
        cobj->setSize(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setSize",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getTooltips(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getTooltips'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getTooltips'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getTooltips();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getTooltips",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getTooltips'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_startDrag(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_startDrag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_startDrag'", nullptr);
            return 0;
        }
        cobj->startDrag();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:startDrag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_startDrag'", nullptr);
            return 0;
        }
        cobj->startDrag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:startDrag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_startDrag'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isDraggable(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isDraggable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isDraggable'", nullptr);
            return 0;
        }
        bool ret = cobj->isDraggable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isDraggable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isDraggable'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setTouchable(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setTouchable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:setTouchable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setTouchable'", nullptr);
            return 0;
        }
        cobj->setTouchable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setTouchable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setTouchable'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_globalToLocal(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_globalToLocal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::Rect arg0;
            ok &= luaval_to_rect(tolua_S, 2, &arg0, "fgui.GObject:globalToLocal");

            if (!ok) { break; }
            cocos2d::Rect ret = cobj->globalToLocal(arg0);
            rect_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Vec2 arg0;
            ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GObject:globalToLocal");

            if (!ok) { break; }
            cocos2d::Vec2 ret = cobj->globalToLocal(arg0);
            vec2_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GObject:globalToLocal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_globalToLocal'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_constructFromResource(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_constructFromResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_constructFromResource'", nullptr);
            return 0;
        }
        cobj->constructFromResource();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:constructFromResource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_constructFromResource'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_addDisplayLock(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_addDisplayLock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_addDisplayLock'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->addDisplayLock();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:addDisplayLock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_addDisplayLock'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isTouchable(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isTouchable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isTouchable'", nullptr);
            return 0;
        }
        bool ret = cobj->isTouchable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isTouchable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isTouchable'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getResourceURL(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getResourceURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getResourceURL'", nullptr);
            return 0;
        }
        std::string ret = cobj->getResourceURL();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getResourceURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getResourceURL'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_makeFullScreen(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_makeFullScreen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_makeFullScreen'", nullptr);
            return 0;
        }
        cobj->makeFullScreen();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:makeFullScreen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_makeFullScreen'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isPivotAsAnchor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isPivotAsAnchor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isPivotAsAnchor'", nullptr);
            return 0;
        }
        bool ret = cobj->isPivotAsAnchor();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isPivotAsAnchor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isPivotAsAnchor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getDragBounds(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getDragBounds'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getDragBounds'", nullptr);
            return 0;
        }
        cocos2d::Rect* ret = cobj->getDragBounds();
        object_to_luaval<cocos2d::Rect>(tolua_S, "cc.Rect",(cocos2d::Rect*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getDragBounds",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getDragBounds'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setCustomData(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setCustomData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Value arg0;

        ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, "fgui.GObject:setCustomData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setCustomData'", nullptr);
            return 0;
        }
        cobj->setCustomData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setCustomData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setCustomData'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getGear(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getGear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:getGear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getGear'", nullptr);
            return 0;
        }
        fairygui::GearBase* ret = cobj->getGear(arg0);
        object_to_luaval<fairygui::GearBase>(tolua_S, "fgui.GearBase",(fairygui::GearBase*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getGear",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getGear'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_isVisible(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_isVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_isVisible'", nullptr);
            return 0;
        }
        bool ret = cobj->isVisible();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:isVisible",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_isVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getText(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getText'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getText();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getText'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getWidth(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_displayObject(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_displayObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_displayObject'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->displayObject();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:displayObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_displayObject'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getRotation(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getRotation'", nullptr);
            return 0;
        }
        double ret = cobj->getRotation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setWidth(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setWidth'", nullptr);
            return 0;
        }
        cobj->setWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setTooltips(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setTooltips'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GObject:setTooltips");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setTooltips'", nullptr);
            return 0;
        }
        cobj->setTooltips(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setTooltips",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setTooltips'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getPackageItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getPackageItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getPackageItem'", nullptr);
            return 0;
        }
        fairygui::PackageItem* ret = cobj->getPackageItem();
        object_to_luaval<fairygui::PackageItem>(tolua_S, "fgui.PackageItem",(fairygui::PackageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getPackageItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getPackageItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_relations(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_relations'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_relations'", nullptr);
            return 0;
        }
        fairygui::Relations* ret = cobj->relations();
        object_to_luaval<fairygui::Relations>(tolua_S, "fgui.Relations",(fairygui::Relations*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:relations",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_relations'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getSkewX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getSkewX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getSkewX'", nullptr);
            return 0;
        }
        double ret = cobj->getSkewX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getSkewX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getSkewX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getSkewY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getSkewY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getSkewY'", nullptr);
            return 0;
        }
        double ret = cobj->getSkewY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getSkewY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getSkewY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_releaseDisplayLock(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_releaseDisplayLock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "fgui.GObject:releaseDisplayLock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_releaseDisplayLock'", nullptr);
            return 0;
        }
        cobj->releaseDisplayLock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:releaseDisplayLock",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_releaseDisplayLock'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setHeight(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setHeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setHeight'", nullptr);
            return 0;
        }
        cobj->setHeight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setHeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getPosition'", nullptr);
            return 0;
        }
        const cocos2d::Vec2& ret = cobj->getPosition();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getRoot(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getRoot'", nullptr);
            return 0;
        }
        fairygui::GRoot* ret = cobj->getRoot();
        object_to_luaval<fairygui::GRoot>(tolua_S, "fgui.GRoot",(fairygui::GRoot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getParent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getParent'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = cobj->getParent();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getParent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getCustomData(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getCustomData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getCustomData'", nullptr);
            return 0;
        }
        const cocos2d::Value& ret = cobj->getCustomData();
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getCustomData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getCustomData'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GObject:setIcon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setIcon'", nullptr);
            return 0;
        }
        cobj->setIcon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_hitTest(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_hitTest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Vec2 arg0;
        const cocos2d::Camera* arg1;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GObject:hitTest");

        ok &= luaval_to_object<const cocos2d::Camera>(tolua_S, 3, "cc.Camera",&arg1, "fgui.GObject:hitTest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_hitTest'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->hitTest(arg0, arg1);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:hitTest",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_hitTest'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setDragBounds(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setDragBounds'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "fgui.GObject:setDragBounds");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setDragBounds'", nullptr);
            return 0;
        }
        cobj->setDragBounds(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setDragBounds",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setDragBounds'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getXMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getXMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getXMin'", nullptr);
            return 0;
        }
        double ret = cobj->getXMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getXMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getXMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_removeRelation(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_removeRelation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        fairygui::RelationType arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GObject:removeRelation");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GObject:removeRelation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_removeRelation'", nullptr);
            return 0;
        }
        cobj->removeRelation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:removeRelation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_removeRelation'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setProp(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setProp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::ObjectPropID arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:setProp");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "fgui.GObject:setProp");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setProp'", nullptr);
            return 0;
        }
        cobj->setProp(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setProp",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setProp'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setScale");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GObject:setScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setScale'", nullptr);
            return 0;
        }
        cobj->setScale(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setScale",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getX'", nullptr);
            return 0;
        }
        double ret = cobj->getX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getY'", nullptr);
            return 0;
        }
        double ret = cobj->getY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_stopDrag(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_stopDrag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_stopDrag'", nullptr);
            return 0;
        }
        cobj->stopDrag();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:stopDrag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_stopDrag'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getScaleY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getScaleY'", nullptr);
            return 0;
        }
        double ret = cobj->getScaleY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getScaleY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getScaleX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getScaleX'", nullptr);
            return 0;
        }
        double ret = cobj->getScaleX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getScaleX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getHeight(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setSortingOrder(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setSortingOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:setSortingOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setSortingOrder'", nullptr);
            return 0;
        }
        cobj->setSortingOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setSortingOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setSortingOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setAlpha(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setAlpha'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setAlpha");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setAlpha'", nullptr);
            return 0;
        }
        cobj->setAlpha(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setAlpha",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setAlpha'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_localToGlobal(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_localToGlobal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::Rect arg0;
            ok &= luaval_to_rect(tolua_S, 2, &arg0, "fgui.GObject:localToGlobal");

            if (!ok) { break; }
            cocos2d::Rect ret = cobj->localToGlobal(arg0);
            rect_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Vec2 arg0;
            ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GObject:localToGlobal");

            if (!ok) { break; }
            cocos2d::Vec2 ret = cobj->localToGlobal(arg0);
            vec2_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GObject:localToGlobal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_localToGlobal'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getData(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_checkGearController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_checkGearController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        fairygui::GController* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:checkGearController");

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 3, "fgui.GController",&arg1, "fgui.GObject:checkGearController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_checkGearController'", nullptr);
            return 0;
        }
        bool ret = cobj->checkGearController(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:checkGearController",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_checkGearController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setData(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setData'", nullptr);
            return 0;
        }
        cobj->setData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setData'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_transformRect(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_transformRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Rect arg0;
        fairygui::GObject* arg1;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "fgui.GObject:transformRect");

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 3, "fgui.GObject",&arg1, "fgui.GObject:transformRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_transformRect'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->transformRect(arg0, arg1);
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:transformRect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_transformRect'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_removeFromParent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_removeFromParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_removeFromParent'", nullptr);
            return 0;
        }
        cobj->removeFromParent();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:removeFromParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_removeFromParent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_findParent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_findParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_findParent'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->findParent();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:findParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_findParent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getYMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getYMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getYMin'", nullptr);
            return 0;
        }
        double ret = cobj->getYMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getYMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getYMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getScale'", nullptr);
            return 0;
        }
        const cocos2d::Vec2& ret = cobj->getScale();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setX(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setX'", nullptr);
            return 0;
        }
        cobj->setX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setX'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setY(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GObject:setY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setY'", nullptr);
            return 0;
        }
        cobj->setY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setY'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getProp(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getProp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ObjectPropID arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:getProp");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getProp'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getProp(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getProp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getProp'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_center(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_center'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_center'", nullptr);
            return 0;
        }
        cobj->center();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GObject:center");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_center'", nullptr);
            return 0;
        }
        cobj->center(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:center",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_center'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_setText(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_setText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GObject:setText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_setText'", nullptr);
            return 0;
        }
        cobj->setText(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:setText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_setText'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_addRelation(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_addRelation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        fairygui::RelationType arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GObject:addRelation");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GObject:addRelation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_addRelation'", nullptr);
            return 0;
        }
        cobj->addRelation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        fairygui::GObject* arg0;
        fairygui::RelationType arg1;
        bool arg2;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GObject:addRelation");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GObject:addRelation");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.GObject:addRelation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_addRelation'", nullptr);
            return 0;
        }
        cobj->addRelation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:addRelation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_addRelation'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_getPivot(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObject_getPivot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getPivot'", nullptr);
            return 0;
        }
        const cocos2d::Vec2& ret = cobj->getPivot();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:getPivot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getPivot'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObject_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_create'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = fairygui::GObject::create();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GObject:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GObject_getDraggingObject(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_getDraggingObject'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = fairygui::GObject::getDraggingObject();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GObject:getDraggingObject",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_getDraggingObject'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GObject_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObject_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GObject();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GObject");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObject:GObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObject_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GObject)");
    return 0;
}

int lua_register_libfairygui_GObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GObject");
    tolua_cclass(tolua_S,"GObject","fgui.GObject","fgui.UIEventDispatcher",nullptr);

    tolua_beginmodule(tolua_S,"GObject");
        tolua_function(tolua_S,"new",lua_libfairygui_GObject_constructor);
        tolua_function(tolua_S,"setGroup",lua_libfairygui_GObject_setGroup);
        tolua_function(tolua_S,"getSize",lua_libfairygui_GObject_getSize);
        tolua_function(tolua_S,"getSortingOrder",lua_libfairygui_GObject_getSortingOrder);
        tolua_function(tolua_S,"isGrayed",lua_libfairygui_GObject_isGrayed);
        tolua_function(tolua_S,"getGroup",lua_libfairygui_GObject_getGroup);
        tolua_function(tolua_S,"treeNode",lua_libfairygui_GObject_treeNode);
        tolua_function(tolua_S,"setRotation",lua_libfairygui_GObject_setRotation);
        tolua_function(tolua_S,"setPixelSnapping",lua_libfairygui_GObject_setPixelSnapping);
        tolua_function(tolua_S,"setScaleY",lua_libfairygui_GObject_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_libfairygui_GObject_setScaleX);
        tolua_function(tolua_S,"isPixelSnapping",lua_libfairygui_GObject_isPixelSnapping);
        tolua_function(tolua_S,"setDraggable",lua_libfairygui_GObject_setDraggable);
        tolua_function(tolua_S,"setYMin",lua_libfairygui_GObject_setYMin);
        tolua_function(tolua_S,"setXMin",lua_libfairygui_GObject_setXMin);
        tolua_function(tolua_S,"onStage",lua_libfairygui_GObject_onStage);
        tolua_function(tolua_S,"getIcon",lua_libfairygui_GObject_getIcon);
        tolua_function(tolua_S,"setPivot",lua_libfairygui_GObject_setPivot);
        tolua_function(tolua_S,"getAlpha",lua_libfairygui_GObject_getAlpha);
        tolua_function(tolua_S,"setSkewX",lua_libfairygui_GObject_setSkewX);
        tolua_function(tolua_S,"setSkewY",lua_libfairygui_GObject_setSkewY);
        tolua_function(tolua_S,"setSize",lua_libfairygui_GObject_setSize);
        tolua_function(tolua_S,"getTooltips",lua_libfairygui_GObject_getTooltips);
        tolua_function(tolua_S,"startDrag",lua_libfairygui_GObject_startDrag);
        tolua_function(tolua_S,"isDraggable",lua_libfairygui_GObject_isDraggable);
        tolua_function(tolua_S,"setTouchable",lua_libfairygui_GObject_setTouchable);
        tolua_function(tolua_S,"globalToLocal",lua_libfairygui_GObject_globalToLocal);
        tolua_function(tolua_S,"constructFromResource",lua_libfairygui_GObject_constructFromResource);
        tolua_function(tolua_S,"addDisplayLock",lua_libfairygui_GObject_addDisplayLock);
        tolua_function(tolua_S,"isTouchable",lua_libfairygui_GObject_isTouchable);
        tolua_function(tolua_S,"getResourceURL",lua_libfairygui_GObject_getResourceURL);
        tolua_function(tolua_S,"makeFullScreen",lua_libfairygui_GObject_makeFullScreen);
        tolua_function(tolua_S,"isPivotAsAnchor",lua_libfairygui_GObject_isPivotAsAnchor);
        tolua_function(tolua_S,"setPosition",lua_libfairygui_GObject_setPosition);
        tolua_function(tolua_S,"getDragBounds",lua_libfairygui_GObject_getDragBounds);
        tolua_function(tolua_S,"setVisible",lua_libfairygui_GObject_setVisible);
        tolua_function(tolua_S,"setCustomData",lua_libfairygui_GObject_setCustomData);
        tolua_function(tolua_S,"getGear",lua_libfairygui_GObject_getGear);
        tolua_function(tolua_S,"isVisible",lua_libfairygui_GObject_isVisible);
        tolua_function(tolua_S,"getText",lua_libfairygui_GObject_getText);
        tolua_function(tolua_S,"getWidth",lua_libfairygui_GObject_getWidth);
        tolua_function(tolua_S,"displayObject",lua_libfairygui_GObject_displayObject);
        tolua_function(tolua_S,"getRotation",lua_libfairygui_GObject_getRotation);
        tolua_function(tolua_S,"setWidth",lua_libfairygui_GObject_setWidth);
        tolua_function(tolua_S,"setTooltips",lua_libfairygui_GObject_setTooltips);
        tolua_function(tolua_S,"getPackageItem",lua_libfairygui_GObject_getPackageItem);
        tolua_function(tolua_S,"relations",lua_libfairygui_GObject_relations);
        tolua_function(tolua_S,"getSkewX",lua_libfairygui_GObject_getSkewX);
        tolua_function(tolua_S,"getSkewY",lua_libfairygui_GObject_getSkewY);
        tolua_function(tolua_S,"releaseDisplayLock",lua_libfairygui_GObject_releaseDisplayLock);
        tolua_function(tolua_S,"setHeight",lua_libfairygui_GObject_setHeight);
        tolua_function(tolua_S,"setGrayed",lua_libfairygui_GObject_setGrayed);
        tolua_function(tolua_S,"getPosition",lua_libfairygui_GObject_getPosition);
        tolua_function(tolua_S,"getRoot",lua_libfairygui_GObject_getRoot);
        tolua_function(tolua_S,"getParent",lua_libfairygui_GObject_getParent);
        tolua_function(tolua_S,"getCustomData",lua_libfairygui_GObject_getCustomData);
        tolua_function(tolua_S,"setIcon",lua_libfairygui_GObject_setIcon);
        tolua_function(tolua_S,"hitTest",lua_libfairygui_GObject_hitTest);
        tolua_function(tolua_S,"setDragBounds",lua_libfairygui_GObject_setDragBounds);
        tolua_function(tolua_S,"getXMin",lua_libfairygui_GObject_getXMin);
        tolua_function(tolua_S,"removeRelation",lua_libfairygui_GObject_removeRelation);
        tolua_function(tolua_S,"setProp",lua_libfairygui_GObject_setProp);
        tolua_function(tolua_S,"setScale",lua_libfairygui_GObject_setScale);
        tolua_function(tolua_S,"getX",lua_libfairygui_GObject_getX);
        tolua_function(tolua_S,"getY",lua_libfairygui_GObject_getY);
        tolua_function(tolua_S,"stopDrag",lua_libfairygui_GObject_stopDrag);
        tolua_function(tolua_S,"getScaleY",lua_libfairygui_GObject_getScaleY);
        tolua_function(tolua_S,"getScaleX",lua_libfairygui_GObject_getScaleX);
        tolua_function(tolua_S,"getHeight",lua_libfairygui_GObject_getHeight);
        tolua_function(tolua_S,"setSortingOrder",lua_libfairygui_GObject_setSortingOrder);
        tolua_function(tolua_S,"setAlpha",lua_libfairygui_GObject_setAlpha);
        tolua_function(tolua_S,"localToGlobal",lua_libfairygui_GObject_localToGlobal);
        tolua_function(tolua_S,"getData",lua_libfairygui_GObject_getData);
        tolua_function(tolua_S,"checkGearController",lua_libfairygui_GObject_checkGearController);
        tolua_function(tolua_S,"setData",lua_libfairygui_GObject_setData);
        tolua_function(tolua_S,"transformRect",lua_libfairygui_GObject_transformRect);
        tolua_function(tolua_S,"removeFromParent",lua_libfairygui_GObject_removeFromParent);
        tolua_function(tolua_S,"findParent",lua_libfairygui_GObject_findParent);
        tolua_function(tolua_S,"getYMin",lua_libfairygui_GObject_getYMin);
        tolua_function(tolua_S,"getScale",lua_libfairygui_GObject_getScale);
        tolua_function(tolua_S,"setX",lua_libfairygui_GObject_setX);
        tolua_function(tolua_S,"setY",lua_libfairygui_GObject_setY);
        tolua_function(tolua_S,"getProp",lua_libfairygui_GObject_getProp);
        tolua_function(tolua_S,"center",lua_libfairygui_GObject_center);
        tolua_function(tolua_S,"setText",lua_libfairygui_GObject_setText);
        tolua_function(tolua_S,"addRelation",lua_libfairygui_GObject_addRelation);
        tolua_function(tolua_S,"getPivot",lua_libfairygui_GObject_getPivot);
        tolua_function(tolua_S,"create", lua_libfairygui_GObject_create);
        tolua_function(tolua_S,"getDraggingObject", lua_libfairygui_GObject_getDraggingObject);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GObject).name();
    g_luaType[typeName] = "fgui.GObject";
    g_typeCast["GObject"] = "fgui.GObject";
    return 1;
}

int lua_libfairygui_UIPackage_getName(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIPackage_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIPackage:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIPackage_getId(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIPackage_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIPackage:getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIPackage_getItemByName(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIPackage_getItemByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getItemByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getItemByName'", nullptr);
            return 0;
        }
        fairygui::PackageItem* ret = cobj->getItemByName(arg0);
        object_to_luaval<fairygui::PackageItem>(tolua_S, "fgui.PackageItem",(fairygui::PackageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIPackage:getItemByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getItemByName'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIPackage_getItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_UIPackage_getItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getItem'", nullptr);
            return 0;
        }
        fairygui::PackageItem* ret = cobj->getItem(arg0);
        object_to_luaval<fairygui::PackageItem>(tolua_S, "fgui.PackageItem",(fairygui::PackageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIPackage:getItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_UIPackage_createObjectFromURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:createObjectFromURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_createObjectFromURL'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = fairygui::UIPackage::createObjectFromURL(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:createObjectFromURL",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_createObjectFromURL'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_removePackage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:removePackage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_removePackage'", nullptr);
            return 0;
        }
        fairygui::UIPackage::removePackage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:removePackage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_removePackage'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getItemURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getItemURL");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.UIPackage:getItemURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getItemURL'", nullptr);
            return 0;
        }
        std::string ret = fairygui::UIPackage::getItemURL(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getItemURL",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getItemURL'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_normalizeURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:normalizeURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_normalizeURL'", nullptr);
            return 0;
        }
        std::string ret = fairygui::UIPackage::normalizeURL(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:normalizeURL",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_normalizeURL'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getVar(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getVar'", nullptr);
            return 0;
        }
        const std::string& ret = fairygui::UIPackage::getVar(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getVar",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getVar'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_removeAllPackages(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_removeAllPackages'", nullptr);
            return 0;
        }
        fairygui::UIPackage::removeAllPackages();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:removeAllPackages",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_removeAllPackages'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_createObject(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:createObject");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.UIPackage:createObject");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_createObject'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = fairygui::UIPackage::createObject(arg0, arg1);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:createObject",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_createObject'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getByName'", nullptr);
            return 0;
        }
        fairygui::UIPackage* ret = fairygui::UIPackage::getByName(arg0);
        object_to_luaval<fairygui::UIPackage>(tolua_S, "fgui.UIPackage",(fairygui::UIPackage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getByName'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_addPackage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:addPackage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_addPackage'", nullptr);
            return 0;
        }
        fairygui::UIPackage* ret = fairygui::UIPackage::addPackage(arg0);
        object_to_luaval<fairygui::UIPackage>(tolua_S, "fgui.UIPackage",(fairygui::UIPackage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:addPackage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_addPackage'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getById(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getById'", nullptr);
            return 0;
        }
        fairygui::UIPackage* ret = fairygui::UIPackage::getById(arg0);
        object_to_luaval<fairygui::UIPackage>(tolua_S, "fgui.UIPackage",(fairygui::UIPackage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getById",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getById'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getBranch(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getBranch'", nullptr);
            return 0;
        }
        const std::string& ret = fairygui::UIPackage::getBranch();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getBranch",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getBranch'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_setBranch(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:setBranch");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_setBranch'", nullptr);
            return 0;
        }
        fairygui::UIPackage::setBranch(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:setBranch",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_setBranch'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getItemByURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:getItemByURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getItemByURL'", nullptr);
            return 0;
        }
        fairygui::PackageItem* ret = fairygui::UIPackage::getItemByURL(arg0);
        object_to_luaval<fairygui::PackageItem>(tolua_S, "fgui.PackageItem",(fairygui::PackageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getItemByURL",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getItemByURL'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_getEmptyTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_getEmptyTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = fairygui::UIPackage::getEmptyTexture();
        object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D",(cocos2d::Texture2D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:getEmptyTexture",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_getEmptyTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_setVar(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIPackage:setVar");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.UIPackage:setVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_setVar'", nullptr);
            return 0;
        }
        fairygui::UIPackage::setVar(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIPackage:setVar",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_setVar'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIPackage_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::UIPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIPackage_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::UIPackage();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.UIPackage");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.UIPackage:UIPackage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIPackage_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_UIPackage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIPackage)");
    return 0;
}

int lua_register_libfairygui_UIPackage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.UIPackage");
    tolua_cclass(tolua_S,"UIPackage","fgui.UIPackage","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"UIPackage");
        tolua_function(tolua_S,"new",lua_libfairygui_UIPackage_constructor);
        tolua_function(tolua_S,"getName",lua_libfairygui_UIPackage_getName);
        tolua_function(tolua_S,"getId",lua_libfairygui_UIPackage_getId);
        tolua_function(tolua_S,"getItemByName",lua_libfairygui_UIPackage_getItemByName);
        tolua_function(tolua_S,"getItem",lua_libfairygui_UIPackage_getItem);
        tolua_function(tolua_S,"createObjectFromURL", lua_libfairygui_UIPackage_createObjectFromURL);
        tolua_function(tolua_S,"removePackage", lua_libfairygui_UIPackage_removePackage);
        tolua_function(tolua_S,"getItemURL", lua_libfairygui_UIPackage_getItemURL);
        tolua_function(tolua_S,"normalizeURL", lua_libfairygui_UIPackage_normalizeURL);
        tolua_function(tolua_S,"getVar", lua_libfairygui_UIPackage_getVar);
        tolua_function(tolua_S,"removeAllPackages", lua_libfairygui_UIPackage_removeAllPackages);
        tolua_function(tolua_S,"createObject", lua_libfairygui_UIPackage_createObject);
        tolua_function(tolua_S,"getByName", lua_libfairygui_UIPackage_getByName);
        tolua_function(tolua_S,"addPackage", lua_libfairygui_UIPackage_addPackage);
        tolua_function(tolua_S,"getById", lua_libfairygui_UIPackage_getById);
        tolua_function(tolua_S,"getBranch", lua_libfairygui_UIPackage_getBranch);
        tolua_function(tolua_S,"setBranch", lua_libfairygui_UIPackage_setBranch);
        tolua_function(tolua_S,"getItemByURL", lua_libfairygui_UIPackage_getItemByURL);
        tolua_function(tolua_S,"getEmptyTexture", lua_libfairygui_UIPackage_getEmptyTexture);
        tolua_function(tolua_S,"setVar", lua_libfairygui_UIPackage_setVar);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::UIPackage).name();
    g_luaType[typeName] = "fgui.UIPackage";
    g_typeCast["UIPackage"] = "fgui.UIPackage";
    return 1;
}

int lua_libfairygui_GImage_setFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FillMethod arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GImage:setFillMethod");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setFillMethod'", nullptr);
            return 0;
        }
        cobj->setFillMethod(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setFillMethod",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_setFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GImage:setFillClockwise");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setFillClockwise'", nullptr);
            return 0;
        }
        cobj->setFillClockwise(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setFillClockwise",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GImage:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_getColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_getFlip(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_getFlip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_getFlip'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFlip();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:getFlip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_getFlip'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_getFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_getFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_getFillMethod'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillMethod();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:getFillMethod",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_getFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_setFlip(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setFlip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FlipType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GImage:setFlip");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setFlip'", nullptr);
            return 0;
        }
        cobj->setFlip(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setFlip",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setFlip'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_setFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GImage:setFillAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setFillAmount'", nullptr);
            return 0;
        }
        cobj->setFillAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setFillAmount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_isFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_isFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_isFillClockwise'", nullptr);
            return 0;
        }
        bool ret = cobj->isFillClockwise();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:isFillClockwise",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_isFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_getFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_getFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_getFillAmount'", nullptr);
            return 0;
        }
        double ret = cobj->getFillAmount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:getFillAmount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_getFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_getFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_getFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_getFillOrigin'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillOrigin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:getFillOrigin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_getFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_setFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GImage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GImage_setFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FillOrigin arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GImage:setFillOrigin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_setFillOrigin'", nullptr);
            return 0;
        }
        cobj->setFillOrigin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:setFillOrigin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_setFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GImage_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GImage",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_create'", nullptr);
            return 0;
        }
        fairygui::GImage* ret = fairygui::GImage::create();
        object_to_luaval<fairygui::GImage>(tolua_S, "fgui.GImage",(fairygui::GImage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GImage:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GImage_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GImage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GImage_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GImage();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GImage");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GImage:GImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GImage_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GImage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GImage)");
    return 0;
}

int lua_register_libfairygui_GImage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GImage");
    tolua_cclass(tolua_S,"GImage","fgui.GImage","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GImage");
        tolua_function(tolua_S,"new",lua_libfairygui_GImage_constructor);
        tolua_function(tolua_S,"setFillMethod",lua_libfairygui_GImage_setFillMethod);
        tolua_function(tolua_S,"setFillClockwise",lua_libfairygui_GImage_setFillClockwise);
        tolua_function(tolua_S,"setColor",lua_libfairygui_GImage_setColor);
        tolua_function(tolua_S,"getColor",lua_libfairygui_GImage_getColor);
        tolua_function(tolua_S,"getFlip",lua_libfairygui_GImage_getFlip);
        tolua_function(tolua_S,"getFillMethod",lua_libfairygui_GImage_getFillMethod);
        tolua_function(tolua_S,"setFlip",lua_libfairygui_GImage_setFlip);
        tolua_function(tolua_S,"setFillAmount",lua_libfairygui_GImage_setFillAmount);
        tolua_function(tolua_S,"isFillClockwise",lua_libfairygui_GImage_isFillClockwise);
        tolua_function(tolua_S,"getFillAmount",lua_libfairygui_GImage_getFillAmount);
        tolua_function(tolua_S,"getFillOrigin",lua_libfairygui_GImage_getFillOrigin);
        tolua_function(tolua_S,"setFillOrigin",lua_libfairygui_GImage_setFillOrigin);
        tolua_function(tolua_S,"create", lua_libfairygui_GImage_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GImage).name();
    g_luaType[typeName] = "fgui.GImage";
    g_typeCast["GImage"] = "fgui.GImage";
    return 1;
}

int lua_libfairygui_GMovieClip_advance(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_advance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GMovieClip:advance");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_advance'", nullptr);
            return 0;
        }
        cobj->advance(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:advance",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_advance'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GMovieClip:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setTimeScale'", nullptr);
            return 0;
        }
        cobj->setTimeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GMovieClip:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setFrame'", nullptr);
            return 0;
        }
        cobj->setFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_getColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_getFlip(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_getFlip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_getFlip'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFlip();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:getFlip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_getFlip'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_getFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_getFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_getFrame'", nullptr);
            return 0;
        }
        int ret = cobj->getFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:getFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_getFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setFlip(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setFlip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FlipType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setFlip");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setFlip'", nullptr);
            return 0;
        }
        cobj->setFlip(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setFlip",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setFlip'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GMovieClip:setPlaying");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaying'", nullptr);
            return 0;
        }
        cobj->setPlaying(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setPlaying",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_setPlaySettings(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setPlaySettings");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GMovieClip:setPlaySettings");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GMovieClip:setPlaySettings");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GMovieClip:setPlaySettings");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        std::function<void ()> arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GMovieClip:setPlaySettings");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:setPlaySettings",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_setPlaySettings'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GMovieClip_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_getTimeScale'", nullptr);
            return 0;
        }
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GMovieClip_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_create'", nullptr);
            return 0;
        }
        fairygui::GMovieClip* ret = fairygui::GMovieClip::create();
        object_to_luaval<fairygui::GMovieClip>(tolua_S, "fgui.GMovieClip",(fairygui::GMovieClip*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GMovieClip:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GMovieClip_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GMovieClip_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GMovieClip();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GMovieClip");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GMovieClip:GMovieClip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GMovieClip_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GMovieClip_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GMovieClip)");
    return 0;
}

int lua_register_libfairygui_GMovieClip(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GMovieClip");
    tolua_cclass(tolua_S,"GMovieClip","fgui.GMovieClip","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GMovieClip");
        tolua_function(tolua_S,"new",lua_libfairygui_GMovieClip_constructor);
        tolua_function(tolua_S,"advance",lua_libfairygui_GMovieClip_advance);
        tolua_function(tolua_S,"setTimeScale",lua_libfairygui_GMovieClip_setTimeScale);
        tolua_function(tolua_S,"setColor",lua_libfairygui_GMovieClip_setColor);
        tolua_function(tolua_S,"setFrame",lua_libfairygui_GMovieClip_setFrame);
        tolua_function(tolua_S,"getColor",lua_libfairygui_GMovieClip_getColor);
        tolua_function(tolua_S,"getFlip",lua_libfairygui_GMovieClip_getFlip);
        tolua_function(tolua_S,"getFrame",lua_libfairygui_GMovieClip_getFrame);
        tolua_function(tolua_S,"setFlip",lua_libfairygui_GMovieClip_setFlip);
        tolua_function(tolua_S,"setPlaying",lua_libfairygui_GMovieClip_setPlaying);
        tolua_function(tolua_S,"setPlaySettings",lua_libfairygui_GMovieClip_setPlaySettings);
        tolua_function(tolua_S,"isPlaying",lua_libfairygui_GMovieClip_isPlaying);
        tolua_function(tolua_S,"getTimeScale",lua_libfairygui_GMovieClip_getTimeScale);
        tolua_function(tolua_S,"create", lua_libfairygui_GMovieClip_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GMovieClip).name();
    g_luaType[typeName] = "fgui.GMovieClip";
    g_typeCast["GMovieClip"] = "fgui.GMovieClip";
    return 1;
}

int lua_libfairygui_ActionMovieClip_advance(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_advance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.ActionMovieClip:advance");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_advance'", nullptr);
            return 0;
        }
        cobj->advance(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:advance",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_advance'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.ActionMovieClip:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setTimeScale'", nullptr);
            return 0;
        }
        cobj->setTimeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_setFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_setFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.ActionMovieClip:setFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setFrame'", nullptr);
            return 0;
        }
        cobj->setFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:setFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_setFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_getFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_getFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_getFrame'", nullptr);
            return 0;
        }
        int ret = cobj->getFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:getFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_getFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_setPlaySettings(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_setPlaySettings'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.ActionMovieClip:setPlaySettings");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        std::function<void ()> arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.ActionMovieClip:setPlaySettings");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.ActionMovieClip:setPlaySettings");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setPlaySettings'", nullptr);
            return 0;
        }
        cobj->setPlaySettings(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:setPlaySettings",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_setPlaySettings'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_setAnimation(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_setAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Animation* arg0;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:setAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setAnimation'", nullptr);
            return 0;
        }
        cobj->setAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Animation* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:setAnimation");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.ActionMovieClip:setAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setAnimation'", nullptr);
            return 0;
        }
        cobj->setAnimation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        cocos2d::Animation* arg0;
        double arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:setAnimation");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.ActionMovieClip:setAnimation");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.ActionMovieClip:setAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_setAnimation'", nullptr);
            return 0;
        }
        cobj->setAnimation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:setAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_setAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::ActionMovieClip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_ActionMovieClip_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_getTimeScale'", nullptr);
            return 0;
        }
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_ActionMovieClip_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.ActionMovieClip",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Animation* arg0;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_create'", nullptr);
            return 0;
        }
        fairygui::ActionMovieClip* ret = fairygui::ActionMovieClip::create(arg0);
        object_to_luaval<fairygui::ActionMovieClip>(tolua_S, "fgui.ActionMovieClip",(fairygui::ActionMovieClip*)ret);
        return 1;
    }
    if (argc == 2)
    {
        cocos2d::Animation* arg0;
        double arg1;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.ActionMovieClip:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_create'", nullptr);
            return 0;
        }
        fairygui::ActionMovieClip* ret = fairygui::ActionMovieClip::create(arg0, arg1);
        object_to_luaval<fairygui::ActionMovieClip>(tolua_S, "fgui.ActionMovieClip",(fairygui::ActionMovieClip*)ret);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::Animation* arg0;
        double arg1;
        bool arg2;
        ok &= luaval_to_object<cocos2d::Animation>(tolua_S, 2, "cc.Animation",&arg0, "fgui.ActionMovieClip:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.ActionMovieClip:create");
        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.ActionMovieClip:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_create'", nullptr);
            return 0;
        }
        fairygui::ActionMovieClip* ret = fairygui::ActionMovieClip::create(arg0, arg1, arg2);
        object_to_luaval<fairygui::ActionMovieClip>(tolua_S, "fgui.ActionMovieClip",(fairygui::ActionMovieClip*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.ActionMovieClip:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_ActionMovieClip_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::ActionMovieClip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_ActionMovieClip_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::ActionMovieClip();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.ActionMovieClip");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.ActionMovieClip:ActionMovieClip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_ActionMovieClip_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_ActionMovieClip_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ActionMovieClip)");
    return 0;
}

int lua_register_libfairygui_ActionMovieClip(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.ActionMovieClip");
    tolua_cclass(tolua_S,"ActionMovieClip","fgui.ActionMovieClip","cc.Action",nullptr);

    tolua_beginmodule(tolua_S,"ActionMovieClip");
        tolua_function(tolua_S,"new",lua_libfairygui_ActionMovieClip_constructor);
        tolua_function(tolua_S,"advance",lua_libfairygui_ActionMovieClip_advance);
        tolua_function(tolua_S,"setTimeScale",lua_libfairygui_ActionMovieClip_setTimeScale);
        tolua_function(tolua_S,"setFrame",lua_libfairygui_ActionMovieClip_setFrame);
        tolua_function(tolua_S,"getFrame",lua_libfairygui_ActionMovieClip_getFrame);
        tolua_function(tolua_S,"setPlaySettings",lua_libfairygui_ActionMovieClip_setPlaySettings);
        tolua_function(tolua_S,"setAnimation",lua_libfairygui_ActionMovieClip_setAnimation);
        tolua_function(tolua_S,"getTimeScale",lua_libfairygui_ActionMovieClip_getTimeScale);
        tolua_function(tolua_S,"create", lua_libfairygui_ActionMovieClip_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::ActionMovieClip).name();
    g_luaType[typeName] = "fgui.ActionMovieClip";
    g_typeCast["ActionMovieClip"] = "fgui.ActionMovieClip";
    return 1;
}

int lua_libfairygui_GTextField_setAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::AutoSizeType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GTextField:setAutoSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setAutoSize'", nullptr);
            return 0;
        }
        cobj->setAutoSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setAutoSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getFontSize'", nullptr);
            return 0;
        }
        double ret = cobj->getFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GTextField:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GTextField:setSingleLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setSingleLine'", nullptr);
            return 0;
        }
        cobj->setSingleLine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setSingleLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_isUBBEnabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_isUBBEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_isUBBEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isUBBEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:isUBBEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_isUBBEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setTemplateVars(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setTemplateVars'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::unordered_map<std::string, cocos2d::Value>* arg0;

        ok &= luaval_to_object<std::unordered_map<std::string, cocos2d::Value>>(tolua_S, 2, "std::unordered_map<std::string, cocos2d::Value>*",&arg0, "fgui.GTextField:setTemplateVars");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setTemplateVars'", nullptr);
            return 0;
        }
        cobj->setTemplateVars(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setTemplateVars",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setTemplateVars'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setVar(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GTextField:setVar");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "fgui.GTextField:setVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setVar'", nullptr);
            return 0;
        }
        fairygui::GTextField* ret = cobj->setVar(arg0, arg1);
        object_to_luaval<fairygui::GTextField>(tolua_S, "fgui.GTextField",(fairygui::GTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setVar",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setVar'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getOutlineColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getOutlineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getOutlineColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getOutlineColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getOutlineColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getOutlineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setUBBEnabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setUBBEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GTextField:setUBBEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setUBBEnabled'", nullptr);
            return 0;
        }
        cobj->setUBBEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setUBBEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setUBBEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getTemplateVars(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getTemplateVars'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getTemplateVars'", nullptr);
            return 0;
        }
        std::unordered_map<std::string, cocos2d::Value>* ret = cobj->getTemplateVars();
        object_to_luaval<std::unordered_map<std::string, cocos2d::Value>>(tolua_S, "std::unordered_map<std::string, cocos2d::Value>*",(std::unordered_map<std::string, cocos2d::Value>*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getTemplateVars",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getTemplateVars'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getAutoSize'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getAutoSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getAutoSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GTextField:setFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setFontSize'", nullptr);
            return 0;
        }
        cobj->setFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_flushVars(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_flushVars'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_flushVars'", nullptr);
            return 0;
        }
        cobj->flushVars();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:flushVars",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_flushVars'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_applyTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_applyTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_applyTextFormat'", nullptr);
            return 0;
        }
        cobj->applyTextFormat();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:applyTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_applyTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_setOutlineColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_setOutlineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GTextField:setOutlineColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_setOutlineColor'", nullptr);
            return 0;
        }
        cobj->setOutlineColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:setOutlineColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_setOutlineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getTextFormat'", nullptr);
            return 0;
        }
        fairygui::TextFormat* ret = cobj->getTextFormat();
        object_to_luaval<fairygui::TextFormat>(tolua_S, "fgui.TextFormat",(fairygui::TextFormat*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_isSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_isSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_isSingleLine'", nullptr);
            return 0;
        }
        bool ret = cobj->isSingleLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:isSingleLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_isSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextField_getTextSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextField_getTextSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextField_getTextSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getTextSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextField:getTextSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextField_getTextSize'.",&tolua_err);
#endif

    return 0;
}
static int lua_libfairygui_GTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTextField)");
    return 0;
}

int lua_register_libfairygui_GTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GTextField");
    tolua_cclass(tolua_S,"GTextField","fgui.GTextField","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GTextField");
        tolua_function(tolua_S,"setAutoSize",lua_libfairygui_GTextField_setAutoSize);
        tolua_function(tolua_S,"getFontSize",lua_libfairygui_GTextField_getFontSize);
        tolua_function(tolua_S,"setColor",lua_libfairygui_GTextField_setColor);
        tolua_function(tolua_S,"setSingleLine",lua_libfairygui_GTextField_setSingleLine);
        tolua_function(tolua_S,"isUBBEnabled",lua_libfairygui_GTextField_isUBBEnabled);
        tolua_function(tolua_S,"getColor",lua_libfairygui_GTextField_getColor);
        tolua_function(tolua_S,"setTemplateVars",lua_libfairygui_GTextField_setTemplateVars);
        tolua_function(tolua_S,"setVar",lua_libfairygui_GTextField_setVar);
        tolua_function(tolua_S,"getOutlineColor",lua_libfairygui_GTextField_getOutlineColor);
        tolua_function(tolua_S,"setUBBEnabled",lua_libfairygui_GTextField_setUBBEnabled);
        tolua_function(tolua_S,"getTemplateVars",lua_libfairygui_GTextField_getTemplateVars);
        tolua_function(tolua_S,"getAutoSize",lua_libfairygui_GTextField_getAutoSize);
        tolua_function(tolua_S,"setFontSize",lua_libfairygui_GTextField_setFontSize);
        tolua_function(tolua_S,"flushVars",lua_libfairygui_GTextField_flushVars);
        tolua_function(tolua_S,"applyTextFormat",lua_libfairygui_GTextField_applyTextFormat);
        tolua_function(tolua_S,"setOutlineColor",lua_libfairygui_GTextField_setOutlineColor);
        tolua_function(tolua_S,"getTextFormat",lua_libfairygui_GTextField_getTextFormat);
        tolua_function(tolua_S,"isSingleLine",lua_libfairygui_GTextField_isSingleLine);
        tolua_function(tolua_S,"getTextSize",lua_libfairygui_GTextField_getTextSize);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GTextField).name();
    g_luaType[typeName] = "fgui.GTextField";
    g_typeCast["GTextField"] = "fgui.GTextField";
    return 1;
}

int lua_libfairygui_GBasicTextField_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GBasicTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GBasicTextField_create'", nullptr);
            return 0;
        }
        fairygui::GBasicTextField* ret = fairygui::GBasicTextField::create();
        object_to_luaval<fairygui::GBasicTextField>(tolua_S, "fgui.GBasicTextField",(fairygui::GBasicTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GBasicTextField:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GBasicTextField_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GBasicTextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GBasicTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GBasicTextField_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GBasicTextField();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GBasicTextField");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GBasicTextField:GBasicTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GBasicTextField_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GBasicTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GBasicTextField)");
    return 0;
}

int lua_register_libfairygui_GBasicTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GBasicTextField");
    tolua_cclass(tolua_S,"GBasicTextField","fgui.GBasicTextField","fgui.GTextField",nullptr);

    tolua_beginmodule(tolua_S,"GBasicTextField");
        tolua_function(tolua_S,"new",lua_libfairygui_GBasicTextField_constructor);
        tolua_function(tolua_S,"create", lua_libfairygui_GBasicTextField_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GBasicTextField).name();
    g_luaType[typeName] = "fgui.GBasicTextField";
    g_typeCast["GBasicTextField"] = "fgui.GBasicTextField";
    return 1;
}

int lua_libfairygui_GRichTextField_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GRichTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRichTextField_create'", nullptr);
            return 0;
        }
        fairygui::GRichTextField* ret = fairygui::GRichTextField::create();
        object_to_luaval<fairygui::GRichTextField>(tolua_S, "fgui.GRichTextField",(fairygui::GRichTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GRichTextField:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRichTextField_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GRichTextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRichTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRichTextField_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GRichTextField();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GRichTextField");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRichTextField:GRichTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRichTextField_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GRichTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GRichTextField)");
    return 0;
}

int lua_register_libfairygui_GRichTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GRichTextField");
    tolua_cclass(tolua_S,"GRichTextField","fgui.GRichTextField","fgui.GTextField",nullptr);

    tolua_beginmodule(tolua_S,"GRichTextField");
        tolua_function(tolua_S,"new",lua_libfairygui_GRichTextField_constructor);
        tolua_function(tolua_S,"create", lua_libfairygui_GRichTextField_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GRichTextField).name();
    g_luaType[typeName] = "fgui.GRichTextField";
    g_typeCast["GRichTextField"] = "fgui.GRichTextField";
    return 1;
}

int lua_libfairygui_GTextInput_setKeyboardType(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextInput_setKeyboardType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GTextInput:setKeyboardType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_setKeyboardType'", nullptr);
            return 0;
        }
        cobj->setKeyboardType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:setKeyboardType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_setKeyboardType'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextInput_setPrompt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextInput_setPrompt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GTextInput:setPrompt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_setPrompt'", nullptr);
            return 0;
        }
        cobj->setPrompt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:setPrompt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_setPrompt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextInput_setMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextInput_setMaxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GTextInput:setMaxLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_setMaxLength'", nullptr);
            return 0;
        }
        cobj->setMaxLength(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:setMaxLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_setMaxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextInput_setRestrict(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextInput_setRestrict'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GTextInput:setRestrict");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_setRestrict'", nullptr);
            return 0;
        }
        cobj->setRestrict(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:setRestrict",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_setRestrict'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextInput_setPassword(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTextInput_setPassword'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GTextInput:setPassword");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_setPassword'", nullptr);
            return 0;
        }
        cobj->setPassword(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:setPassword",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_setPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTextInput_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_create'", nullptr);
            return 0;
        }
        fairygui::GTextInput* ret = fairygui::GTextInput::create();
        object_to_luaval<fairygui::GTextInput>(tolua_S, "fgui.GTextInput",(fairygui::GTextInput*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTextInput:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTextInput_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTextInput_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GTextInput();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GTextInput");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTextInput:GTextInput",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTextInput_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GTextInput_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTextInput)");
    return 0;
}

int lua_register_libfairygui_GTextInput(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GTextInput");
    tolua_cclass(tolua_S,"GTextInput","fgui.GTextInput","fgui.GTextField",nullptr);

    tolua_beginmodule(tolua_S,"GTextInput");
        tolua_function(tolua_S,"new",lua_libfairygui_GTextInput_constructor);
        tolua_function(tolua_S,"setKeyboardType",lua_libfairygui_GTextInput_setKeyboardType);
        tolua_function(tolua_S,"setPrompt",lua_libfairygui_GTextInput_setPrompt);
        tolua_function(tolua_S,"setMaxLength",lua_libfairygui_GTextInput_setMaxLength);
        tolua_function(tolua_S,"setRestrict",lua_libfairygui_GTextInput_setRestrict);
        tolua_function(tolua_S,"setPassword",lua_libfairygui_GTextInput_setPassword);
        tolua_function(tolua_S,"create", lua_libfairygui_GTextInput_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GTextInput).name();
    g_luaType[typeName] = "fgui.GTextInput";
    g_typeCast["GTextInput"] = "fgui.GTextInput";
    return 1;
}

int lua_libfairygui_GGraph_drawEllipse(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_drawEllipse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        double arg0;
        double arg1;
        int arg2;
        cocos2d::Color4F arg3;
        cocos2d::Color4F arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GGraph:drawEllipse");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GGraph:drawEllipse");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GGraph:drawEllipse");

        ok &=luaval_to_color4f(tolua_S, 5, &arg3, "fgui.GGraph:drawEllipse");

        ok &=luaval_to_color4f(tolua_S, 6, &arg4, "fgui.GGraph:drawEllipse");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawEllipse'", nullptr);
            return 0;
        }
        cobj->drawEllipse(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:drawEllipse",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_drawEllipse'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GGraph:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_drawPolygon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_drawPolygon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        int arg0;
        cocos2d::Color4F arg1;
        cocos2d::Color4F arg2;
        const cocos2d::Vec2* arg3;
        int arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGraph:drawPolygon");

        ok &=luaval_to_color4f(tolua_S, 3, &arg1, "fgui.GGraph:drawPolygon");

        ok &=luaval_to_color4f(tolua_S, 4, &arg2, "fgui.GGraph:drawPolygon");

        ok &= luaval_to_object<const cocos2d::Vec2>(tolua_S, 5, "cc.Vec2",&arg3, "fgui.GGraph:drawPolygon");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "fgui.GGraph:drawPolygon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawPolygon'", nullptr);
            return 0;
        }
        cobj->drawPolygon(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:drawPolygon",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_drawPolygon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_getColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_drawRegularPolygon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_drawRegularPolygon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        cocos2d::Color4F arg1;
        cocos2d::Color4F arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 3, &arg1, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 4, &arg2, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GGraph:drawRegularPolygon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawRegularPolygon'", nullptr);
            return 0;
        }
        cobj->drawRegularPolygon(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        cocos2d::Color4F arg1;
        cocos2d::Color4F arg2;
        int arg3;
        double arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 3, &arg1, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 4, &arg2, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "fgui.GGraph:drawRegularPolygon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawRegularPolygon'", nullptr);
            return 0;
        }
        cobj->drawRegularPolygon(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 6) 
    {
        int arg0;
        cocos2d::Color4F arg1;
        cocos2d::Color4F arg2;
        int arg3;
        double arg4;
        const float* arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 3, &arg1, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 4, &arg2, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "fgui.GGraph:drawRegularPolygon");

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawRegularPolygon'", nullptr);
            return 0;
        }
        cobj->drawRegularPolygon(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 7) 
    {
        int arg0;
        cocos2d::Color4F arg1;
        cocos2d::Color4F arg2;
        int arg3;
        double arg4;
        const float* arg5;
        int arg6;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 3, &arg1, "fgui.GGraph:drawRegularPolygon");

        ok &=luaval_to_color4f(tolua_S, 4, &arg2, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "fgui.GGraph:drawRegularPolygon");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "fgui.GGraph:drawRegularPolygon");

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "fgui.GGraph:drawRegularPolygon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawRegularPolygon'", nullptr);
            return 0;
        }
        cobj->drawRegularPolygon(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:drawRegularPolygon",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_drawRegularPolygon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_isEmpty(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_isEmpty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_isEmpty'", nullptr);
            return 0;
        }
        bool ret = cobj->isEmpty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:isEmpty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_isEmpty'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_drawRect(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGraph_drawRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        double arg0;
        double arg1;
        int arg2;
        cocos2d::Color4F arg3;
        cocos2d::Color4F arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GGraph:drawRect");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GGraph:drawRect");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GGraph:drawRect");

        ok &=luaval_to_color4f(tolua_S, 5, &arg3, "fgui.GGraph:drawRect");

        ok &=luaval_to_color4f(tolua_S, 6, &arg4, "fgui.GGraph:drawRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_drawRect'", nullptr);
            return 0;
        }
        cobj->drawRect(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:drawRect",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_drawRect'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGraph_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_create'", nullptr);
            return 0;
        }
        fairygui::GGraph* ret = fairygui::GGraph::create();
        object_to_luaval<fairygui::GGraph>(tolua_S, "fgui.GGraph",(fairygui::GGraph*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GGraph:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GGraph_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGraph_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GGraph();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GGraph");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGraph:GGraph",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGraph_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GGraph_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GGraph)");
    return 0;
}

int lua_register_libfairygui_GGraph(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GGraph");
    tolua_cclass(tolua_S,"GGraph","fgui.GGraph","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GGraph");
        tolua_function(tolua_S,"new",lua_libfairygui_GGraph_constructor);
        tolua_function(tolua_S,"drawEllipse",lua_libfairygui_GGraph_drawEllipse);
        tolua_function(tolua_S,"setColor",lua_libfairygui_GGraph_setColor);
        tolua_function(tolua_S,"drawPolygon",lua_libfairygui_GGraph_drawPolygon);
        tolua_function(tolua_S,"getColor",lua_libfairygui_GGraph_getColor);
        tolua_function(tolua_S,"drawRegularPolygon",lua_libfairygui_GGraph_drawRegularPolygon);
        tolua_function(tolua_S,"isEmpty",lua_libfairygui_GGraph_isEmpty);
        tolua_function(tolua_S,"drawRect",lua_libfairygui_GGraph_drawRect);
        tolua_function(tolua_S,"create", lua_libfairygui_GGraph_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GGraph).name();
    g_luaType[typeName] = "fgui.GGraph";
    g_typeCast["GGraph"] = "fgui.GGraph";
    return 1;
}

int lua_libfairygui_GLoader_getURL(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getURL'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getURL();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getURL'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getFillAmount'", nullptr);
            return 0;
        }
        double ret = cobj->getFillAmount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getFillAmount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getFillOrigin'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillOrigin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getFillOrigin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setVerticalAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setVerticalAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setVerticalAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setVerticalAlign'", nullptr);
            return 0;
        }
        cobj->setVerticalAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setVerticalAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setVerticalAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FillMethod arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setFillMethod");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFillMethod'", nullptr);
            return 0;
        }
        cobj->setFillMethod(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFillMethod",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getFrame'", nullptr);
            return 0;
        }
        int ret = cobj->getFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getFillMethod'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillMethod();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getFillMethod",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_isFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_isFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_isFillClockwise'", nullptr);
            return 0;
        }
        bool ret = cobj->isFillClockwise();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:isFillClockwise",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_isFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getComponent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getComponent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getComponent'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = cobj->getComponent();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getComponent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getComponent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getContentSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::FillOrigin arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setFillOrigin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFillOrigin'", nullptr);
            return 0;
        }
        cobj->setFillOrigin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFillOrigin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getVerticalAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getVerticalAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getVerticalAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getVerticalAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getVerticalAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getVerticalAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setAlign'", nullptr);
            return 0;
        }
        cobj->setAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setURL(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GLoader:setURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setURL'", nullptr);
            return 0;
        }
        cobj->setURL(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setURL",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setURL'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GLoader:setPlaying");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setPlaying'", nullptr);
            return 0;
        }
        cobj->setPlaying(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setPlaying",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GLoader:setFillClockwise");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFillClockwise'", nullptr);
            return 0;
        }
        cobj->setFillClockwise(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFillClockwise",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_isShrinkOnly(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_isShrinkOnly'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_isShrinkOnly'", nullptr);
            return 0;
        }
        bool ret = cobj->isShrinkOnly();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:isShrinkOnly",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_isShrinkOnly'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GLoader:setAutoSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setAutoSize'", nullptr);
            return 0;
        }
        cobj->setAutoSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setAutoSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setShrinkOnly(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setShrinkOnly'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GLoader:setShrinkOnly");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setShrinkOnly'", nullptr);
            return 0;
        }
        cobj->setShrinkOnly(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setShrinkOnly",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setShrinkOnly'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GLoader:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFrame'", nullptr);
            return 0;
        }
        cobj->setFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getFill(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getFill'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getFill'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFill();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getFill",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getFill'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GLoader:setFillAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFillAmount'", nullptr);
            return 0;
        }
        cobj->setFillAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFillAmount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_getAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_getAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_getAutoSize'", nullptr);
            return 0;
        }
        bool ret = cobj->getAutoSize();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:getAutoSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_getAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_setFill(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLoader_setFill'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::LoaderFillType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLoader:setFill");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_setFill'", nullptr);
            return 0;
        }
        cobj->setFill(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:setFill",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_setFill'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLoader_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_create'", nullptr);
            return 0;
        }
        fairygui::GLoader* ret = fairygui::GLoader::create();
        object_to_luaval<fairygui::GLoader>(tolua_S, "fgui.GLoader",(fairygui::GLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GLoader:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GLoader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLoader_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GLoader();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GLoader");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLoader:GLoader",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLoader_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GLoader)");
    return 0;
}

int lua_register_libfairygui_GLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GLoader");
    tolua_cclass(tolua_S,"GLoader","fgui.GLoader","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GLoader");
        tolua_function(tolua_S,"new",lua_libfairygui_GLoader_constructor);
        tolua_function(tolua_S,"getURL",lua_libfairygui_GLoader_getURL);
        tolua_function(tolua_S,"getFillAmount",lua_libfairygui_GLoader_getFillAmount);
        tolua_function(tolua_S,"getFillOrigin",lua_libfairygui_GLoader_getFillOrigin);
        tolua_function(tolua_S,"setVerticalAlign",lua_libfairygui_GLoader_setVerticalAlign);
        tolua_function(tolua_S,"setFillMethod",lua_libfairygui_GLoader_setFillMethod);
        tolua_function(tolua_S,"getAlign",lua_libfairygui_GLoader_getAlign);
        tolua_function(tolua_S,"getFrame",lua_libfairygui_GLoader_getFrame);
        tolua_function(tolua_S,"getFillMethod",lua_libfairygui_GLoader_getFillMethod);
        tolua_function(tolua_S,"isFillClockwise",lua_libfairygui_GLoader_isFillClockwise);
        tolua_function(tolua_S,"getComponent",lua_libfairygui_GLoader_getComponent);
        tolua_function(tolua_S,"getContentSize",lua_libfairygui_GLoader_getContentSize);
        tolua_function(tolua_S,"setFillOrigin",lua_libfairygui_GLoader_setFillOrigin);
        tolua_function(tolua_S,"getVerticalAlign",lua_libfairygui_GLoader_getVerticalAlign);
        tolua_function(tolua_S,"setAlign",lua_libfairygui_GLoader_setAlign);
        tolua_function(tolua_S,"getColor",lua_libfairygui_GLoader_getColor);
        tolua_function(tolua_S,"setURL",lua_libfairygui_GLoader_setURL);
        tolua_function(tolua_S,"setPlaying",lua_libfairygui_GLoader_setPlaying);
        tolua_function(tolua_S,"setFillClockwise",lua_libfairygui_GLoader_setFillClockwise);
        tolua_function(tolua_S,"isPlaying",lua_libfairygui_GLoader_isPlaying);
        tolua_function(tolua_S,"isShrinkOnly",lua_libfairygui_GLoader_isShrinkOnly);
        tolua_function(tolua_S,"setAutoSize",lua_libfairygui_GLoader_setAutoSize);
        tolua_function(tolua_S,"setShrinkOnly",lua_libfairygui_GLoader_setShrinkOnly);
        tolua_function(tolua_S,"setColor",lua_libfairygui_GLoader_setColor);
        tolua_function(tolua_S,"setFrame",lua_libfairygui_GLoader_setFrame);
        tolua_function(tolua_S,"getFill",lua_libfairygui_GLoader_getFill);
        tolua_function(tolua_S,"setFillAmount",lua_libfairygui_GLoader_setFillAmount);
        tolua_function(tolua_S,"getAutoSize",lua_libfairygui_GLoader_getAutoSize);
        tolua_function(tolua_S,"setFill",lua_libfairygui_GLoader_setFill);
        tolua_function(tolua_S,"create", lua_libfairygui_GLoader_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GLoader).name();
    g_luaType[typeName] = "fgui.GLoader";
    g_typeCast["GLoader"] = "fgui.GLoader";
    return 1;
}

int lua_libfairygui_GGroup_setAutoSizeDisabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setAutoSizeDisabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GGroup:setAutoSizeDisabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setAutoSizeDisabled'", nullptr);
            return 0;
        }
        cobj->setAutoSizeDisabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setAutoSizeDisabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setAutoSizeDisabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_getColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_getColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_getColumnGap'", nullptr);
            return 0;
        }
        int ret = cobj->getColumnGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:getColumnGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_getColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_resizeChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_resizeChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GGroup:resizeChildren");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GGroup:resizeChildren");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_resizeChildren'", nullptr);
            return 0;
        }
        cobj->resizeChildren(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:resizeChildren",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_resizeChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_getMainGridMinSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_getMainGridMinSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_getMainGridMinSize'", nullptr);
            return 0;
        }
        int ret = cobj->getMainGridMinSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:getMainGridMinSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_getMainGridMinSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setMainGridMinSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setMainGridMinSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGroup:setMainGridMinSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setMainGridMinSize'", nullptr);
            return 0;
        }
        cobj->setMainGridMinSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setMainGridMinSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setMainGridMinSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setLayout(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GroupLayoutType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGroup:setLayout");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setLayout'", nullptr);
            return 0;
        }
        cobj->setLayout(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setLayout",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_getMainGridIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_getMainGridIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_getMainGridIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getMainGridIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:getMainGridIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_getMainGridIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGroup:setColumnGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setColumnGap'", nullptr);
            return 0;
        }
        cobj->setColumnGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setColumnGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setBoundsChangedFlag(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setBoundsChangedFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setBoundsChangedFlag'", nullptr);
            return 0;
        }
        cobj->setBoundsChangedFlag();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GGroup:setBoundsChangedFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setBoundsChangedFlag'", nullptr);
            return 0;
        }
        cobj->setBoundsChangedFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setBoundsChangedFlag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setBoundsChangedFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_isAutoSizeDisabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_isAutoSizeDisabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_isAutoSizeDisabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isAutoSizeDisabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:isAutoSizeDisabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_isAutoSizeDisabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_moveChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_moveChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GGroup:moveChildren");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GGroup:moveChildren");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_moveChildren'", nullptr);
            return 0;
        }
        cobj->moveChildren(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:moveChildren",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_moveChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_getLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_getLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_getLineGap'", nullptr);
            return 0;
        }
        int ret = cobj->getLineGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:getLineGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_getLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setMainGridIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setMainGridIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGroup:setMainGridIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setMainGridIndex'", nullptr);
            return 0;
        }
        cobj->setMainGridIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setMainGridIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setMainGridIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setExcludeInvisibles(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setExcludeInvisibles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GGroup:setExcludeInvisibles");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setExcludeInvisibles'", nullptr);
            return 0;
        }
        cobj->setExcludeInvisibles(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setExcludeInvisibles",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setExcludeInvisibles'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_setLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_setLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GGroup:setLineGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_setLineGap'", nullptr);
            return 0;
        }
        cobj->setLineGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:setLineGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_setLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_isExcludeInvisibles(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_isExcludeInvisibles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_isExcludeInvisibles'", nullptr);
            return 0;
        }
        bool ret = cobj->isExcludeInvisibles();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:isExcludeInvisibles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_isExcludeInvisibles'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_getLayout(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GGroup_getLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_getLayout'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getLayout();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:getLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_getLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GGroup_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_create'", nullptr);
            return 0;
        }
        fairygui::GGroup* ret = fairygui::GGroup::create();
        object_to_luaval<fairygui::GGroup>(tolua_S, "fgui.GGroup",(fairygui::GGroup*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GGroup:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GGroup_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GGroup_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GGroup();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GGroup");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GGroup:GGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GGroup_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GGroup_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GGroup)");
    return 0;
}

int lua_register_libfairygui_GGroup(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GGroup");
    tolua_cclass(tolua_S,"GGroup","fgui.GGroup","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GGroup");
        tolua_function(tolua_S,"new",lua_libfairygui_GGroup_constructor);
        tolua_function(tolua_S,"setAutoSizeDisabled",lua_libfairygui_GGroup_setAutoSizeDisabled);
        tolua_function(tolua_S,"getColumnGap",lua_libfairygui_GGroup_getColumnGap);
        tolua_function(tolua_S,"resizeChildren",lua_libfairygui_GGroup_resizeChildren);
        tolua_function(tolua_S,"getMainGridMinSize",lua_libfairygui_GGroup_getMainGridMinSize);
        tolua_function(tolua_S,"setMainGridMinSize",lua_libfairygui_GGroup_setMainGridMinSize);
        tolua_function(tolua_S,"setLayout",lua_libfairygui_GGroup_setLayout);
        tolua_function(tolua_S,"getMainGridIndex",lua_libfairygui_GGroup_getMainGridIndex);
        tolua_function(tolua_S,"setColumnGap",lua_libfairygui_GGroup_setColumnGap);
        tolua_function(tolua_S,"setBoundsChangedFlag",lua_libfairygui_GGroup_setBoundsChangedFlag);
        tolua_function(tolua_S,"isAutoSizeDisabled",lua_libfairygui_GGroup_isAutoSizeDisabled);
        tolua_function(tolua_S,"moveChildren",lua_libfairygui_GGroup_moveChildren);
        tolua_function(tolua_S,"getLineGap",lua_libfairygui_GGroup_getLineGap);
        tolua_function(tolua_S,"setMainGridIndex",lua_libfairygui_GGroup_setMainGridIndex);
        tolua_function(tolua_S,"setExcludeInvisibles",lua_libfairygui_GGroup_setExcludeInvisibles);
        tolua_function(tolua_S,"setLineGap",lua_libfairygui_GGroup_setLineGap);
        tolua_function(tolua_S,"isExcludeInvisibles",lua_libfairygui_GGroup_isExcludeInvisibles);
        tolua_function(tolua_S,"getLayout",lua_libfairygui_GGroup_getLayout);
        tolua_function(tolua_S,"create", lua_libfairygui_GGroup_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GGroup).name();
    g_luaType[typeName] = "fgui.GGroup";
    g_typeCast["GGroup"] = "fgui.GGroup";
    return 1;
}

int lua_libfairygui_GComponent_addChild(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_addChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:addChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_addChild'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->addChild(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:addChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_addChild'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getHitArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getHitArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getHitArea'", nullptr);
            return 0;
        }
        fairygui::IHitTest* ret = cobj->getHitArea();
        object_to_luaval<fairygui::IHitTest>(tolua_S, "fgui.IHitTest",(fairygui::IHitTest*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getHitArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getHitArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_applyAllControllers(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_applyAllControllers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_applyAllControllers'", nullptr);
            return 0;
        }
        cobj->applyAllControllers();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:applyAllControllers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_applyAllControllers'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getOpaque(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getOpaque'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getOpaque'", nullptr);
            return 0;
        }
        bool ret = cobj->getOpaque();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getOpaque",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getOpaque'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setChildrenRenderOrder(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setChildrenRenderOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ChildrenRenderOrder arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:setChildrenRenderOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setChildrenRenderOrder'", nullptr);
            return 0;
        }
        cobj->setChildrenRenderOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setChildrenRenderOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setChildrenRenderOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setOpaque(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setOpaque'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GComponent:setOpaque");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setOpaque'", nullptr);
            return 0;
        }
        cobj->setOpaque(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setOpaque",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setOpaque'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getViewWidth(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getViewWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getViewWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getViewWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getViewWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getViewWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getTransitions(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getTransitions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getTransitions'", nullptr);
            return 0;
        }
        const cocos2d::Vector<fairygui::Transition *>& ret = cobj->getTransitions();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getTransitions",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getTransitions'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getViewHeight(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getViewHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getViewHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getViewHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getViewHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getViewHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_ensureBoundsCorrect(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_ensureBoundsCorrect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_ensureBoundsCorrect'", nullptr);
            return 0;
        }
        cobj->ensureBoundsCorrect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:ensureBoundsCorrect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_ensureBoundsCorrect'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_isAncestorOf(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_isAncestorOf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const fairygui::GObject* arg0;

        ok &= luaval_to_object<const fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:isAncestorOf");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_isAncestorOf'", nullptr);
            return 0;
        }
        bool ret = cobj->isAncestorOf(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:isAncestorOf",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_isAncestorOf'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildren'", nullptr);
            return 0;
        }
        const cocos2d::Vector<fairygui::GObject *>& ret = cobj->getChildren();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildren",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getMask(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getMask'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getMask();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getMask",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getMask'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_adjustRadioGroupDepth(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_adjustRadioGroupDepth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        fairygui::GController* arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:adjustRadioGroupDepth");

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 3, "fgui.GController",&arg1, "fgui.GComponent:adjustRadioGroupDepth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_adjustRadioGroupDepth'", nullptr);
            return 0;
        }
        cobj->adjustRadioGroupDepth(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:adjustRadioGroupDepth",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_adjustRadioGroupDepth'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComponent:getController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getController'", nullptr);
            return 0;
        }
        fairygui::GController* ret = cobj->getController(arg0);
        object_to_luaval<fairygui::GController>(tolua_S, "fgui.GController",(fairygui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setApexIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setApexIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:setApexIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setApexIndex'", nullptr);
            return 0;
        }
        cobj->setApexIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setApexIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setApexIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getTransition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getTransition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComponent:getTransition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getTransition'", nullptr);
            return 0;
        }
        fairygui::Transition* ret = cobj->getTransition(arg0);
        object_to_luaval<fairygui::Transition>(tolua_S, "fgui.Transition",(fairygui::Transition*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getTransition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getTransition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getFirstChildInView(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getFirstChildInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getFirstChildInView'", nullptr);
            return 0;
        }
        int ret = cobj->getFirstChildInView();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getFirstChildInView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getFirstChildInView'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_isChildInView(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_isChildInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:isChildInView");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_isChildInView'", nullptr);
            return 0;
        }
        bool ret = cobj->isChildInView(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:isChildInView",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_isChildInView'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setBoundsChangedFlag(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setBoundsChangedFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setBoundsChangedFlag'", nullptr);
            return 0;
        }
        cobj->setBoundsChangedFlag();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setBoundsChangedFlag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setBoundsChangedFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_addChildAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_addChildAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        int arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:addChildAt");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:addChildAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_addChildAt'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->addChildAt(arg0, arg1);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:addChildAt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_addChildAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_removeChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_removeChildren'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:removeChildren");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:removeChildren");

            if (!ok) { break; }
            cobj->removeChildren(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->removeChildren();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GComponent:removeChildren",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_removeChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_removeChildAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_removeChildAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:removeChildAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_removeChildAt'", nullptr);
            return 0;
        }
        cobj->removeChildAt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:removeChildAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_removeChildAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChild(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComponent:getChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChild'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getChild(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChild'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_addController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_addController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GComponent:addController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_addController'", nullptr);
            return 0;
        }
        cobj->addController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:addController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_addController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_childSortingOrderChanged(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_childSortingOrderChanged'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        fairygui::GObject* arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:childSortingOrderChanged");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:childSortingOrderChanged");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GComponent:childSortingOrderChanged");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_childSortingOrderChanged'", nullptr);
            return 0;
        }
        cobj->childSortingOrderChanged(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:childSortingOrderChanged",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_childSortingOrderChanged'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_applyController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_applyController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GComponent:applyController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_applyController'", nullptr);
            return 0;
        }
        cobj->applyController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:applyController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_applyController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getControllers(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getControllers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getControllers'", nullptr);
            return 0;
        }
        const cocos2d::Vector<fairygui::GController *>& ret = cobj->getControllers();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getControllers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getControllers'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setMask(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui.GComponent:setMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setMask'", nullptr);
            return 0;
        }
        cobj->setMask(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        bool arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui.GComponent:setMask");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GComponent:setMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setMask'", nullptr);
            return 0;
        }
        cobj->setMask(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setMask'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setChildIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setChildIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        int arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:setChildIndex");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:setChildIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setChildIndex'", nullptr);
            return 0;
        }
        cobj->setChildIndex(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setChildIndex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setChildIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setViewWidth(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setViewWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GComponent:setViewWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setViewWidth'", nullptr);
            return 0;
        }
        cobj->setViewWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setViewWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setViewWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildById(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComponent:getChildById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildById'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getChildById(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildById'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const fairygui::GObject* arg0;

        ok &= luaval_to_object<const fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:getChildIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getChildIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getControllerAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getControllerAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:getControllerAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getControllerAt'", nullptr);
            return 0;
        }
        fairygui::GController* ret = cobj->getControllerAt(arg0);
        object_to_luaval<fairygui::GController>(tolua_S, "fgui.GController",(fairygui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getControllerAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getControllerAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getSnappingPosition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getSnappingPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GComponent:getSnappingPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getSnappingPosition'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getSnappingPosition(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getSnappingPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getSnappingPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:getChildAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildAt'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getChildAt(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getApexIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getApexIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getApexIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getApexIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getApexIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getApexIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getScrollPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getScrollPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getScrollPane'", nullptr);
            return 0;
        }
        fairygui::ScrollPane* ret = cobj->getScrollPane();
        object_to_luaval<fairygui::ScrollPane>(tolua_S, "fgui.ScrollPane",(fairygui::ScrollPane*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getScrollPane",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getScrollPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getTransitionAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getTransitionAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:getTransitionAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getTransitionAt'", nullptr);
            return 0;
        }
        fairygui::Transition* ret = cobj->getTransitionAt(arg0);
        object_to_luaval<fairygui::Transition>(tolua_S, "fgui.Transition",(fairygui::Transition*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getTransitionAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getTransitionAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildInGroup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildInGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const fairygui::GGroup* arg0;
        std::string arg1;

        ok &= luaval_to_object<const fairygui::GGroup>(tolua_S, 2, "fgui.GGroup",&arg0, "fgui.GComponent:getChildInGroup");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.GComponent:getChildInGroup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildInGroup'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getChildInGroup(arg0, arg1);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildInGroup",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildInGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_removeController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_removeController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GComponent:removeController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_removeController'", nullptr);
            return 0;
        }
        cobj->removeController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:removeController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_removeController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildByPath(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildByPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComponent:getChildByPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildByPath'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getChildByPath(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildByPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildByPath'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setChildIndexBefore(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setChildIndexBefore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        int arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:setChildIndexBefore");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:setChildIndexBefore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setChildIndexBefore'", nullptr);
            return 0;
        }
        int ret = cobj->setChildIndexBefore(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setChildIndexBefore",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setChildIndexBefore'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setHitArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setHitArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::IHitTest* arg0;

        ok &= luaval_to_object<fairygui::IHitTest>(tolua_S, 2, "fgui.IHitTest",&arg0, "fgui.GComponent:setHitArea");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setHitArea'", nullptr);
            return 0;
        }
        cobj->setHitArea(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setHitArea",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setHitArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_swapChildrenAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_swapChildrenAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComponent:swapChildrenAt");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GComponent:swapChildrenAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_swapChildrenAt'", nullptr);
            return 0;
        }
        cobj->swapChildrenAt(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:swapChildrenAt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_swapChildrenAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_numChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_numChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_numChildren'", nullptr);
            return 0;
        }
        int ret = cobj->numChildren();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:numChildren",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_numChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_removeChild(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_removeChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:removeChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_removeChild'", nullptr);
            return 0;
        }
        cobj->removeChild(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:removeChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_removeChild'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_swapChildren(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_swapChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::GObject* arg0;
        fairygui::GObject* arg1;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:swapChildren");

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 3, "fgui.GObject",&arg1, "fgui.GComponent:swapChildren");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_swapChildren'", nullptr);
            return 0;
        }
        cobj->swapChildren(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:swapChildren",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_swapChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_childStateChanged(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_childStateChanged'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GComponent:childStateChanged");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_childStateChanged'", nullptr);
            return 0;
        }
        cobj->childStateChanged(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:childStateChanged",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_childStateChanged'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_getChildrenRenderOrder(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_getChildrenRenderOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_getChildrenRenderOrder'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getChildrenRenderOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:getChildrenRenderOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_getChildrenRenderOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_setViewHeight(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComponent_setViewHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GComponent:setViewHeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_setViewHeight'", nullptr);
            return 0;
        }
        cobj->setViewHeight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:setViewHeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_setViewHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComponent_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_create'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = fairygui::GComponent::create();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GComponent:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GComponent_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComponent_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GComponent();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GComponent");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComponent:GComponent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComponent_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GComponent_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GComponent)");
    return 0;
}

int lua_register_libfairygui_GComponent(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GComponent");
    tolua_cclass(tolua_S,"GComponent","fgui.GComponent","fgui.GObject",nullptr);

    tolua_beginmodule(tolua_S,"GComponent");
        tolua_function(tolua_S,"new",lua_libfairygui_GComponent_constructor);
        tolua_function(tolua_S,"addChild",lua_libfairygui_GComponent_addChild);
        tolua_function(tolua_S,"getHitArea",lua_libfairygui_GComponent_getHitArea);
        tolua_function(tolua_S,"applyAllControllers",lua_libfairygui_GComponent_applyAllControllers);
        tolua_function(tolua_S,"getOpaque",lua_libfairygui_GComponent_getOpaque);
        tolua_function(tolua_S,"setChildrenRenderOrder",lua_libfairygui_GComponent_setChildrenRenderOrder);
        tolua_function(tolua_S,"setOpaque",lua_libfairygui_GComponent_setOpaque);
        tolua_function(tolua_S,"getViewWidth",lua_libfairygui_GComponent_getViewWidth);
        tolua_function(tolua_S,"getTransitions",lua_libfairygui_GComponent_getTransitions);
        tolua_function(tolua_S,"getViewHeight",lua_libfairygui_GComponent_getViewHeight);
        tolua_function(tolua_S,"ensureBoundsCorrect",lua_libfairygui_GComponent_ensureBoundsCorrect);
        tolua_function(tolua_S,"isAncestorOf",lua_libfairygui_GComponent_isAncestorOf);
        tolua_function(tolua_S,"getChildren",lua_libfairygui_GComponent_getChildren);
        tolua_function(tolua_S,"getMask",lua_libfairygui_GComponent_getMask);
        tolua_function(tolua_S,"adjustRadioGroupDepth",lua_libfairygui_GComponent_adjustRadioGroupDepth);
        tolua_function(tolua_S,"getController",lua_libfairygui_GComponent_getController);
        tolua_function(tolua_S,"setApexIndex",lua_libfairygui_GComponent_setApexIndex);
        tolua_function(tolua_S,"getTransition",lua_libfairygui_GComponent_getTransition);
        tolua_function(tolua_S,"getFirstChildInView",lua_libfairygui_GComponent_getFirstChildInView);
        tolua_function(tolua_S,"isChildInView",lua_libfairygui_GComponent_isChildInView);
        tolua_function(tolua_S,"setBoundsChangedFlag",lua_libfairygui_GComponent_setBoundsChangedFlag);
        tolua_function(tolua_S,"addChildAt",lua_libfairygui_GComponent_addChildAt);
        tolua_function(tolua_S,"removeChildren",lua_libfairygui_GComponent_removeChildren);
        tolua_function(tolua_S,"removeChildAt",lua_libfairygui_GComponent_removeChildAt);
        tolua_function(tolua_S,"getChild",lua_libfairygui_GComponent_getChild);
        tolua_function(tolua_S,"addController",lua_libfairygui_GComponent_addController);
        tolua_function(tolua_S,"childSortingOrderChanged",lua_libfairygui_GComponent_childSortingOrderChanged);
        tolua_function(tolua_S,"applyController",lua_libfairygui_GComponent_applyController);
        tolua_function(tolua_S,"getControllers",lua_libfairygui_GComponent_getControllers);
        tolua_function(tolua_S,"setMask",lua_libfairygui_GComponent_setMask);
        tolua_function(tolua_S,"setChildIndex",lua_libfairygui_GComponent_setChildIndex);
        tolua_function(tolua_S,"setViewWidth",lua_libfairygui_GComponent_setViewWidth);
        tolua_function(tolua_S,"getChildById",lua_libfairygui_GComponent_getChildById);
        tolua_function(tolua_S,"getChildIndex",lua_libfairygui_GComponent_getChildIndex);
        tolua_function(tolua_S,"getControllerAt",lua_libfairygui_GComponent_getControllerAt);
        tolua_function(tolua_S,"getSnappingPosition",lua_libfairygui_GComponent_getSnappingPosition);
        tolua_function(tolua_S,"getChildAt",lua_libfairygui_GComponent_getChildAt);
        tolua_function(tolua_S,"getApexIndex",lua_libfairygui_GComponent_getApexIndex);
        tolua_function(tolua_S,"getScrollPane",lua_libfairygui_GComponent_getScrollPane);
        tolua_function(tolua_S,"getTransitionAt",lua_libfairygui_GComponent_getTransitionAt);
        tolua_function(tolua_S,"getChildInGroup",lua_libfairygui_GComponent_getChildInGroup);
        tolua_function(tolua_S,"removeController",lua_libfairygui_GComponent_removeController);
        tolua_function(tolua_S,"getChildByPath",lua_libfairygui_GComponent_getChildByPath);
        tolua_function(tolua_S,"setChildIndexBefore",lua_libfairygui_GComponent_setChildIndexBefore);
        tolua_function(tolua_S,"setHitArea",lua_libfairygui_GComponent_setHitArea);
        tolua_function(tolua_S,"swapChildrenAt",lua_libfairygui_GComponent_swapChildrenAt);
        tolua_function(tolua_S,"numChildren",lua_libfairygui_GComponent_numChildren);
        tolua_function(tolua_S,"removeChild",lua_libfairygui_GComponent_removeChild);
        tolua_function(tolua_S,"swapChildren",lua_libfairygui_GComponent_swapChildren);
        tolua_function(tolua_S,"childStateChanged",lua_libfairygui_GComponent_childStateChanged);
        tolua_function(tolua_S,"getChildrenRenderOrder",lua_libfairygui_GComponent_getChildrenRenderOrder);
        tolua_function(tolua_S,"setViewHeight",lua_libfairygui_GComponent_setViewHeight);
        tolua_function(tolua_S,"create", lua_libfairygui_GComponent_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GComponent).name();
    g_luaType[typeName] = "fgui.GComponent";
    g_typeCast["GComponent"] = "fgui.GComponent";
    return 1;
}

int lua_libfairygui_GLabel_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_setTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GLabel:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_setTitle'", nullptr);
            return 0;
        }
        cobj->setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:setTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_setTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_getTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_getTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_getTitleFontSize'", nullptr);
            return 0;
        }
        int ret = cobj->getTitleFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:getTitleFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_getTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_getTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_getTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_getTitleColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getTitleColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:getTitleColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_getTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_getTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_getTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_getTitle'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getTitle();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:getTitle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_getTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_getTextField(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_getTextField'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_getTextField'", nullptr);
            return 0;
        }
        fairygui::GTextField* ret = cobj->getTextField();
        object_to_luaval<fairygui::GTextField>(tolua_S, "fgui.GTextField",(fairygui::GTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:getTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_getTextField'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_setTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GLabel:setTitleFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_setTitleFontSize'", nullptr);
            return 0;
        }
        cobj->setTitleFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:setTitleFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_setTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GLabel_setTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GLabel:setTitleColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_setTitleColor'", nullptr);
            return 0;
        }
        cobj->setTitleColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:setTitleColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_setTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GLabel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_create'", nullptr);
            return 0;
        }
        fairygui::GLabel* ret = fairygui::GLabel::create();
        object_to_luaval<fairygui::GLabel>(tolua_S, "fgui.GLabel",(fairygui::GLabel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GLabel:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GLabel_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GLabel_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GLabel();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GLabel");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GLabel:GLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GLabel_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GLabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GLabel)");
    return 0;
}

int lua_register_libfairygui_GLabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GLabel");
    tolua_cclass(tolua_S,"GLabel","fgui.GLabel","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GLabel");
        tolua_function(tolua_S,"new",lua_libfairygui_GLabel_constructor);
        tolua_function(tolua_S,"setTitle",lua_libfairygui_GLabel_setTitle);
        tolua_function(tolua_S,"getTitleFontSize",lua_libfairygui_GLabel_getTitleFontSize);
        tolua_function(tolua_S,"getTitleColor",lua_libfairygui_GLabel_getTitleColor);
        tolua_function(tolua_S,"getTitle",lua_libfairygui_GLabel_getTitle);
        tolua_function(tolua_S,"getTextField",lua_libfairygui_GLabel_getTextField);
        tolua_function(tolua_S,"setTitleFontSize",lua_libfairygui_GLabel_setTitleFontSize);
        tolua_function(tolua_S,"setTitleColor",lua_libfairygui_GLabel_setTitleColor);
        tolua_function(tolua_S,"create", lua_libfairygui_GLabel_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GLabel).name();
    g_luaType[typeName] = "fgui.GLabel";
    g_typeCast["GLabel"] = "fgui.GLabel";
    return 1;
}

int lua_libfairygui_GButton_getRelatedController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getRelatedController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getRelatedController'", nullptr);
            return 0;
        }
        fairygui::GController* ret = cobj->getRelatedController();
        object_to_luaval<fairygui::GController>(tolua_S, "fgui.GController",(fairygui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getRelatedController",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getRelatedController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setChangeStateOnClick(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setChangeStateOnClick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GButton:setChangeStateOnClick");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setChangeStateOnClick'", nullptr);
            return 0;
        }
        cobj->setChangeStateOnClick(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setChangeStateOnClick",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setChangeStateOnClick'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setSelectedTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setSelectedTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GButton:setSelectedTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setSelectedTitle'", nullptr);
            return 0;
        }
        cobj->setSelectedTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setSelectedTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setSelectedTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setSelected(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setSelected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GButton:setSelected");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setSelected'", nullptr);
            return 0;
        }
        cobj->setSelected(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setSelected",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setSelected'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setRelatedController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setRelatedController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GButton:setRelatedController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setRelatedController'", nullptr);
            return 0;
        }
        cobj->setRelatedController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setRelatedController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setRelatedController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GButton:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setTitle'", nullptr);
            return 0;
        }
        cobj->setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getTitleFontSize'", nullptr);
            return 0;
        }
        int ret = cobj->getTitleFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getTitleFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getSelectedIcon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getSelectedIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getSelectedIcon'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getSelectedIcon();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getSelectedIcon",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getSelectedIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_isSelected(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_isSelected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_isSelected'", nullptr);
            return 0;
        }
        bool ret = cobj->isSelected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:isSelected",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_isSelected'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getTitleColor'", nullptr);
            return 0;
        }
        cocos2d::Color3B ret = cobj->getTitleColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getTitleColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getSelectedTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getSelectedTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getSelectedTitle'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getSelectedTitle();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getSelectedTitle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getSelectedTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getTitle'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getTitle();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getTitle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setSelectedIcon(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setSelectedIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GButton:setSelectedIcon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setSelectedIcon'", nullptr);
            return 0;
        }
        cobj->setSelectedIcon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setSelectedIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setSelectedIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_getTextField(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_getTextField'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_getTextField'", nullptr);
            return 0;
        }
        fairygui::GTextField* ret = cobj->getTextField();
        object_to_luaval<fairygui::GTextField>(tolua_S, "fgui.GTextField",(fairygui::GTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:getTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_getTextField'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_isChangeStateOnClick(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_isChangeStateOnClick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_isChangeStateOnClick'", nullptr);
            return 0;
        }
        bool ret = cobj->isChangeStateOnClick();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:isChangeStateOnClick",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_isChangeStateOnClick'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GButton:setTitleFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setTitleFontSize'", nullptr);
            return 0;
        }
        cobj->setTitleFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setTitleFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GButton_setTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GButton:setTitleColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_setTitleColor'", nullptr);
            return 0;
        }
        cobj->setTitleColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:setTitleColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_setTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_create'", nullptr);
            return 0;
        }
        fairygui::GButton* ret = fairygui::GButton::create();
        object_to_luaval<fairygui::GButton>(tolua_S, "fgui.GButton",(fairygui::GButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GButton:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GButton_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GButton();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GButton");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GButton:GButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GButton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GButton)");
    return 0;
}

int lua_register_libfairygui_GButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GButton");
    tolua_cclass(tolua_S,"GButton","fgui.GButton","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GButton");
        tolua_function(tolua_S,"new",lua_libfairygui_GButton_constructor);
        tolua_function(tolua_S,"getRelatedController",lua_libfairygui_GButton_getRelatedController);
        tolua_function(tolua_S,"setChangeStateOnClick",lua_libfairygui_GButton_setChangeStateOnClick);
        tolua_function(tolua_S,"setSelectedTitle",lua_libfairygui_GButton_setSelectedTitle);
        tolua_function(tolua_S,"setSelected",lua_libfairygui_GButton_setSelected);
        tolua_function(tolua_S,"setRelatedController",lua_libfairygui_GButton_setRelatedController);
        tolua_function(tolua_S,"setTitle",lua_libfairygui_GButton_setTitle);
        tolua_function(tolua_S,"getTitleFontSize",lua_libfairygui_GButton_getTitleFontSize);
        tolua_function(tolua_S,"getSelectedIcon",lua_libfairygui_GButton_getSelectedIcon);
        tolua_function(tolua_S,"isSelected",lua_libfairygui_GButton_isSelected);
        tolua_function(tolua_S,"getTitleColor",lua_libfairygui_GButton_getTitleColor);
        tolua_function(tolua_S,"getSelectedTitle",lua_libfairygui_GButton_getSelectedTitle);
        tolua_function(tolua_S,"getTitle",lua_libfairygui_GButton_getTitle);
        tolua_function(tolua_S,"setSelectedIcon",lua_libfairygui_GButton_setSelectedIcon);
        tolua_function(tolua_S,"getTextField",lua_libfairygui_GButton_getTextField);
        tolua_function(tolua_S,"isChangeStateOnClick",lua_libfairygui_GButton_isChangeStateOnClick);
        tolua_function(tolua_S,"setTitleFontSize",lua_libfairygui_GButton_setTitleFontSize);
        tolua_function(tolua_S,"setTitleColor",lua_libfairygui_GButton_setTitleColor);
        tolua_function(tolua_S,"create", lua_libfairygui_GButton_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GButton).name();
    g_luaType[typeName] = "fgui.GButton";
    g_typeCast["GButton"] = "fgui.GButton";
    return 1;
}

int lua_libfairygui_GObjectPool_getObject(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObjectPool_getObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GObjectPool:getObject");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObjectPool_getObject'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getObject(arg0);
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObjectPool:getObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObjectPool_getObject'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObjectPool_returnObject(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GObjectPool_returnObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GObjectPool:returnObject");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObjectPool_returnObject'", nullptr);
            return 0;
        }
        cobj->returnObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObjectPool:returnObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObjectPool_returnObject'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GObjectPool_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GObjectPool_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GObjectPool();
        tolua_pushusertype(tolua_S,(void*)cobj,"fgui.GObjectPool");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GObjectPool:GObjectPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GObjectPool_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GObjectPool_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GObjectPool)");
    return 0;
}

int lua_register_libfairygui_GObjectPool(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GObjectPool");
    tolua_cclass(tolua_S,"GObjectPool","fgui.GObjectPool","",nullptr);

    tolua_beginmodule(tolua_S,"GObjectPool");
        tolua_function(tolua_S,"new",lua_libfairygui_GObjectPool_constructor);
        tolua_function(tolua_S,"getObject",lua_libfairygui_GObjectPool_getObject);
        tolua_function(tolua_S,"returnObject",lua_libfairygui_GObjectPool_returnObject);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GObjectPool).name();
    g_luaType[typeName] = "fgui.GObjectPool";
    g_typeCast["GObjectPool"] = "fgui.GObjectPool";
    return 1;
}

int lua_libfairygui_GList_selectAll(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_selectAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_selectAll'", nullptr);
            return 0;
        }
        cobj->selectAll();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:selectAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_selectAll'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getColumnGap'", nullptr);
            return 0;
        }
        int ret = cobj->getColumnGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getColumnGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getLineCount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getLineCount'", nullptr);
            return 0;
        }
        int ret = cobj->getLineCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setVirtualAndLoop(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setVirtualAndLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setVirtualAndLoop'", nullptr);
            return 0;
        }
        cobj->setVirtualAndLoop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setVirtualAndLoop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setVirtualAndLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setLayout(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ListLayoutType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setLayout");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setLayout'", nullptr);
            return 0;
        }
        cobj->setLayout(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setLayout",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_refreshVirtualList(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_refreshVirtualList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_refreshVirtualList'", nullptr);
            return 0;
        }
        cobj->refreshVirtualList();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:refreshVirtualList",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_refreshVirtualList'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_removeSelection(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_removeSelection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:removeSelection");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_removeSelection'", nullptr);
            return 0;
        }
        cobj->removeSelection(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:removeSelection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_removeSelection'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setColumnGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setColumnGap'", nullptr);
            return 0;
        }
        cobj->setColumnGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setColumnGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getColumnCount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getColumnCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getColumnCount'", nullptr);
            return 0;
        }
        int ret = cobj->getColumnCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getColumnCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getColumnCount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setVirtual'", nullptr);
            return 0;
        }
        cobj->setVirtual();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setNumItems(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setNumItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setNumItems");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setNumItems'", nullptr);
            return 0;
        }
        cobj->setNumItems(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setNumItems",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setNumItems'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setVerticalAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setVerticalAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setVerticalAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setVerticalAlign'", nullptr);
            return 0;
        }
        cobj->setVerticalAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setVerticalAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setVerticalAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_resizeToFit(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_resizeToFit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:resizeToFit");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GList:resizeToFit");

            if (!ok) { break; }
            cobj->resizeToFit(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:resizeToFit");

            if (!ok) { break; }
            cobj->resizeToFit(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GList:resizeToFit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_resizeToFit'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setSelectionController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setSelectionController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GList:setSelectionController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setSelectionController'", nullptr);
            return 0;
        }
        cobj->setSelectionController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setSelectionController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setSelectionController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_returnToPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_returnToPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GList:returnToPool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_returnToPool'", nullptr);
            return 0;
        }
        cobj->returnToPool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:returnToPool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_returnToPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_clearSelection(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_clearSelection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_clearSelection'", nullptr);
            return 0;
        }
        cobj->clearSelection();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:clearSelection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_clearSelection'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getNumItems(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getNumItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getNumItems'", nullptr);
            return 0;
        }
        int ret = cobj->getNumItems();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getNumItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getNumItems'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setColumnCount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setColumnCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setColumnCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setColumnCount'", nullptr);
            return 0;
        }
        cobj->setColumnCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setColumnCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setColumnCount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_removeChildToPoolAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_removeChildToPoolAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:removeChildToPoolAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_removeChildToPoolAt'", nullptr);
            return 0;
        }
        cobj->removeChildToPoolAt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:removeChildToPoolAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_removeChildToPoolAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_addItemFromPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_addItemFromPool'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GList:addItemFromPool");

            if (!ok) { break; }
            fairygui::GObject* ret = cobj->addItemFromPool(arg0);
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            fairygui::GObject* ret = cobj->addItemFromPool();
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GList:addItemFromPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_addItemFromPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_selectReverse(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_selectReverse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_selectReverse'", nullptr);
            return 0;
        }
        cobj->selectReverse();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:selectReverse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_selectReverse'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setLineCount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setLineCount'", nullptr);
            return 0;
        }
        cobj->setLineCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setLineCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setAutoResizeItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setAutoResizeItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GList:setAutoResizeItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setAutoResizeItem'", nullptr);
            return 0;
        }
        cobj->setAutoResizeItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setAutoResizeItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setAutoResizeItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getVerticalAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getVerticalAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getVerticalAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getVerticalAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getVerticalAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getVerticalAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_removeChildrenToPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_removeChildrenToPool'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:removeChildrenToPool");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GList:removeChildrenToPool");

            if (!ok) { break; }
            cobj->removeChildrenToPool(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->removeChildrenToPool();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GList:removeChildrenToPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_removeChildrenToPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setAlign'", nullptr);
            return 0;
        }
        cobj->setAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_isVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_isVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_isVirtual'", nullptr);
            return 0;
        }
        bool ret = cobj->isVirtual();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:isVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_isVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getSelectedIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getSelectedIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getSelectedIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getSelection(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getSelection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<int> arg0;

        ok &= luaval_to_std_vector_int(tolua_S, 2, &arg0, "fgui.GList:getSelection");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getSelection'", nullptr);
            return 0;
        }
        cobj->getSelection(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getSelection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getSelection'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_itemIndexToChildIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_itemIndexToChildIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:itemIndexToChildIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_itemIndexToChildIndex'", nullptr);
            return 0;
        }
        int ret = cobj->itemIndexToChildIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:itemIndexToChildIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_itemIndexToChildIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getItemPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getItemPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getItemPool'", nullptr);
            return 0;
        }
        fairygui::GObjectPool* ret = cobj->getItemPool();
        object_to_luaval<fairygui::GObjectPool>(tolua_S, "fgui.GObjectPool",(fairygui::GObjectPool*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getItemPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getItemPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getSelectionController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getSelectionController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getSelectionController'", nullptr);
            return 0;
        }
        fairygui::GController* ret = cobj->getSelectionController();
        object_to_luaval<fairygui::GController>(tolua_S, "fgui.GController",(fairygui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getSelectionController",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getSelectionController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getLineGap'", nullptr);
            return 0;
        }
        int ret = cobj->getLineGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getLineGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_scrollToView(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_scrollToView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:scrollToView");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_scrollToView'", nullptr);
            return 0;
        }
        cobj->scrollToView(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:scrollToView");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GList:scrollToView");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_scrollToView'", nullptr);
            return 0;
        }
        cobj->scrollToView(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        bool arg1;
        bool arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:scrollToView");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GList:scrollToView");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.GList:scrollToView");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_scrollToView'", nullptr);
            return 0;
        }
        cobj->scrollToView(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:scrollToView",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_scrollToView'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_handleArrowKey(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_handleArrowKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:handleArrowKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_handleArrowKey'", nullptr);
            return 0;
        }
        cobj->handleArrowKey(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:handleArrowKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_handleArrowKey'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getAlign(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getFromPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getFromPool'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GList:getFromPool");

            if (!ok) { break; }
            fairygui::GObject* ret = cobj->getFromPool(arg0);
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            fairygui::GObject* ret = cobj->getFromPool();
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GList:getFromPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getFromPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getDefaultItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getDefaultItem'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getDefaultItem();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getDefaultItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getDefaultItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getSelectionMode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getSelectionMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getSelectionMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getSelectionMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getSelectionMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getSelectionMode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setDefaultItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GList:setDefaultItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setDefaultItem'", nullptr);
            return 0;
        }
        cobj->setDefaultItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setDefaultItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setDefaultItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setSelectedIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setSelectedIndex'", nullptr);
            return 0;
        }
        cobj->setSelectedIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setSelectedIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setSelectionMode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setSelectionMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ListSelectionMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setSelectionMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setSelectionMode'", nullptr);
            return 0;
        }
        cobj->setSelectionMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setSelectionMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setSelectionMode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_addSelection(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_addSelection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:addSelection");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GList:addSelection");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_addSelection'", nullptr);
            return 0;
        }
        cobj->addSelection(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:addSelection",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_addSelection'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_childIndexToItemIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_childIndexToItemIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:childIndexToItemIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_childIndexToItemIndex'", nullptr);
            return 0;
        }
        int ret = cobj->childIndexToItemIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:childIndexToItemIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_childIndexToItemIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getAutoResizeItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getAutoResizeItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getAutoResizeItem'", nullptr);
            return 0;
        }
        bool ret = cobj->getAutoResizeItem();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getAutoResizeItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getAutoResizeItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_setLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_setLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setLineGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_setLineGap'", nullptr);
            return 0;
        }
        cobj->setLineGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:setLineGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_setLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_removeChildToPool(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_removeChildToPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GList:removeChildToPool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_removeChildToPool'", nullptr);
            return 0;
        }
        cobj->removeChildToPool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:removeChildToPool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_removeChildToPool'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_getLayout(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GList_getLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_getLayout'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getLayout();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:getLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_getLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GList_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GList",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_create'", nullptr);
            return 0;
        }
        fairygui::GList* ret = fairygui::GList::create();
        object_to_luaval<fairygui::GList>(tolua_S, "fgui.GList",(fairygui::GList*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GList:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GList_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GList_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GList();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GList");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GList:GList",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GList_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GList_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GList)");
    return 0;
}

int lua_register_libfairygui_GList(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GList");
    tolua_cclass(tolua_S,"GList","fgui.GList","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GList");
        tolua_function(tolua_S,"new",lua_libfairygui_GList_constructor);
        tolua_function(tolua_S,"selectAll",lua_libfairygui_GList_selectAll);
        tolua_function(tolua_S,"getColumnGap",lua_libfairygui_GList_getColumnGap);
        tolua_function(tolua_S,"getLineCount",lua_libfairygui_GList_getLineCount);
        tolua_function(tolua_S,"setVirtualAndLoop",lua_libfairygui_GList_setVirtualAndLoop);
        tolua_function(tolua_S,"setLayout",lua_libfairygui_GList_setLayout);
        tolua_function(tolua_S,"refreshVirtualList",lua_libfairygui_GList_refreshVirtualList);
        tolua_function(tolua_S,"removeSelection",lua_libfairygui_GList_removeSelection);
        tolua_function(tolua_S,"setColumnGap",lua_libfairygui_GList_setColumnGap);
        tolua_function(tolua_S,"getColumnCount",lua_libfairygui_GList_getColumnCount);
        tolua_function(tolua_S,"setVirtual",lua_libfairygui_GList_setVirtual);
        tolua_function(tolua_S,"setNumItems",lua_libfairygui_GList_setNumItems);
        tolua_function(tolua_S,"setVerticalAlign",lua_libfairygui_GList_setVerticalAlign);
        tolua_function(tolua_S,"resizeToFit",lua_libfairygui_GList_resizeToFit);
        tolua_function(tolua_S,"setSelectionController",lua_libfairygui_GList_setSelectionController);
        tolua_function(tolua_S,"returnToPool",lua_libfairygui_GList_returnToPool);
        tolua_function(tolua_S,"clearSelection",lua_libfairygui_GList_clearSelection);
        tolua_function(tolua_S,"getNumItems",lua_libfairygui_GList_getNumItems);
        tolua_function(tolua_S,"setColumnCount",lua_libfairygui_GList_setColumnCount);
        tolua_function(tolua_S,"removeChildToPoolAt",lua_libfairygui_GList_removeChildToPoolAt);
        tolua_function(tolua_S,"addItemFromPool",lua_libfairygui_GList_addItemFromPool);
        tolua_function(tolua_S,"selectReverse",lua_libfairygui_GList_selectReverse);
        tolua_function(tolua_S,"setLineCount",lua_libfairygui_GList_setLineCount);
        tolua_function(tolua_S,"setAutoResizeItem",lua_libfairygui_GList_setAutoResizeItem);
        tolua_function(tolua_S,"getVerticalAlign",lua_libfairygui_GList_getVerticalAlign);
        tolua_function(tolua_S,"removeChildrenToPool",lua_libfairygui_GList_removeChildrenToPool);
        tolua_function(tolua_S,"setAlign",lua_libfairygui_GList_setAlign);
        tolua_function(tolua_S,"isVirtual",lua_libfairygui_GList_isVirtual);
        tolua_function(tolua_S,"getSelectedIndex",lua_libfairygui_GList_getSelectedIndex);
        tolua_function(tolua_S,"getSelection",lua_libfairygui_GList_getSelection);
        tolua_function(tolua_S,"itemIndexToChildIndex",lua_libfairygui_GList_itemIndexToChildIndex);
        tolua_function(tolua_S,"getItemPool",lua_libfairygui_GList_getItemPool);
        tolua_function(tolua_S,"getSelectionController",lua_libfairygui_GList_getSelectionController);
        tolua_function(tolua_S,"getLineGap",lua_libfairygui_GList_getLineGap);
        tolua_function(tolua_S,"scrollToView",lua_libfairygui_GList_scrollToView);
        tolua_function(tolua_S,"handleArrowKey",lua_libfairygui_GList_handleArrowKey);
        tolua_function(tolua_S,"getAlign",lua_libfairygui_GList_getAlign);
        tolua_function(tolua_S,"getFromPool",lua_libfairygui_GList_getFromPool);
        tolua_function(tolua_S,"getDefaultItem",lua_libfairygui_GList_getDefaultItem);
        tolua_function(tolua_S,"getSelectionMode",lua_libfairygui_GList_getSelectionMode);
        tolua_function(tolua_S,"setDefaultItem",lua_libfairygui_GList_setDefaultItem);
        tolua_function(tolua_S,"setSelectedIndex",lua_libfairygui_GList_setSelectedIndex);
        tolua_function(tolua_S,"setSelectionMode",lua_libfairygui_GList_setSelectionMode);
        tolua_function(tolua_S,"addSelection",lua_libfairygui_GList_addSelection);
        tolua_function(tolua_S,"childIndexToItemIndex",lua_libfairygui_GList_childIndexToItemIndex);
        tolua_function(tolua_S,"getAutoResizeItem",lua_libfairygui_GList_getAutoResizeItem);
        tolua_function(tolua_S,"setLineGap",lua_libfairygui_GList_setLineGap);
        tolua_function(tolua_S,"removeChildToPool",lua_libfairygui_GList_removeChildToPool);
        tolua_function(tolua_S,"getLayout",lua_libfairygui_GList_getLayout);
        tolua_function(tolua_S,"create", lua_libfairygui_GList_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GList).name();
    g_luaType[typeName] = "fgui.GList";
    g_typeCast["GList"] = "fgui.GList";
    return 1;
}

int lua_libfairygui_GComboBox_refresh(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_refresh'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_refresh'", nullptr);
            return 0;
        }
        cobj->refresh();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:refresh",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_refresh'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComboBox:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComboBox:setSelectedIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setSelectedIndex'", nullptr);
            return 0;
        }
        cobj->setSelectedIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setSelectedIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getItems(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getItems'", nullptr);
            return 0;
        }
        std::vector<std::string>& ret = cobj->getItems();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getItems'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getSelectedIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getSelectedIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getSelectedIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GComboBox:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setTitle'", nullptr);
            return 0;
        }
        cobj->setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getTitleFontSize'", nullptr);
            return 0;
        }
        int ret = cobj->getTitleFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getTitleFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getValue'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getValue();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getDropdown(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getDropdown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getDropdown'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getDropdown();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getDropdown",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getDropdown'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getTitleColor'", nullptr);
            return 0;
        }
        const cocos2d::Color3B ret = cobj->getTitleColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getTitleColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getIcons(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getIcons'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getIcons'", nullptr);
            return 0;
        }
        std::vector<std::string>& ret = cobj->getIcons();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getIcons",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getIcons'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getTitle(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getTitle'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getTitle();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getTitle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getSelectionController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getSelectionController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getSelectionController'", nullptr);
            return 0;
        }
        fairygui::GController* ret = cobj->getSelectionController();
        object_to_luaval<fairygui::GController>(tolua_S, "fgui.GController",(fairygui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getSelectionController",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getSelectionController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getValues(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getValues'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getValues'", nullptr);
            return 0;
        }
        std::vector<std::string>& ret = cobj->getValues();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getValues",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getValues'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setSelectionController(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setSelectionController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GController* arg0;

        ok &= luaval_to_object<fairygui::GController>(tolua_S, 2, "fgui.GController",&arg0, "fgui.GComboBox:setSelectionController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setSelectionController'", nullptr);
            return 0;
        }
        cobj->setSelectionController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setSelectionController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setSelectionController'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GComboBox:setTitleFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setTitleFontSize'", nullptr);
            return 0;
        }
        cobj->setTitleFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setTitleFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_setTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui.GComboBox:setTitleColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_setTitleColor'", nullptr);
            return 0;
        }
        cobj->setTitleColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:setTitleColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_setTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_getTextField(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GComboBox_getTextField'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_getTextField'", nullptr);
            return 0;
        }
        fairygui::GTextField* ret = cobj->getTextField();
        object_to_luaval<fairygui::GTextField>(tolua_S, "fgui.GTextField",(fairygui::GTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:getTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_getTextField'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GComboBox_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GComboBox",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_create'", nullptr);
            return 0;
        }
        fairygui::GComboBox* ret = fairygui::GComboBox::create();
        object_to_luaval<fairygui::GComboBox>(tolua_S, "fgui.GComboBox",(fairygui::GComboBox*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GComboBox:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GComboBox_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GComboBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GComboBox_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GComboBox();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GComboBox");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GComboBox:GComboBox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GComboBox_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GComboBox_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GComboBox)");
    return 0;
}

int lua_register_libfairygui_GComboBox(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GComboBox");
    tolua_cclass(tolua_S,"GComboBox","fgui.GComboBox","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GComboBox");
        tolua_function(tolua_S,"new",lua_libfairygui_GComboBox_constructor);
        tolua_function(tolua_S,"refresh",lua_libfairygui_GComboBox_refresh);
        tolua_function(tolua_S,"setValue",lua_libfairygui_GComboBox_setValue);
        tolua_function(tolua_S,"setSelectedIndex",lua_libfairygui_GComboBox_setSelectedIndex);
        tolua_function(tolua_S,"getItems",lua_libfairygui_GComboBox_getItems);
        tolua_function(tolua_S,"getSelectedIndex",lua_libfairygui_GComboBox_getSelectedIndex);
        tolua_function(tolua_S,"setTitle",lua_libfairygui_GComboBox_setTitle);
        tolua_function(tolua_S,"getTitleFontSize",lua_libfairygui_GComboBox_getTitleFontSize);
        tolua_function(tolua_S,"getValue",lua_libfairygui_GComboBox_getValue);
        tolua_function(tolua_S,"getDropdown",lua_libfairygui_GComboBox_getDropdown);
        tolua_function(tolua_S,"getTitleColor",lua_libfairygui_GComboBox_getTitleColor);
        tolua_function(tolua_S,"getIcons",lua_libfairygui_GComboBox_getIcons);
        tolua_function(tolua_S,"getTitle",lua_libfairygui_GComboBox_getTitle);
        tolua_function(tolua_S,"getSelectionController",lua_libfairygui_GComboBox_getSelectionController);
        tolua_function(tolua_S,"getValues",lua_libfairygui_GComboBox_getValues);
        tolua_function(tolua_S,"setSelectionController",lua_libfairygui_GComboBox_setSelectionController);
        tolua_function(tolua_S,"setTitleFontSize",lua_libfairygui_GComboBox_setTitleFontSize);
        tolua_function(tolua_S,"setTitleColor",lua_libfairygui_GComboBox_setTitleColor);
        tolua_function(tolua_S,"getTextField",lua_libfairygui_GComboBox_getTextField);
        tolua_function(tolua_S,"create", lua_libfairygui_GComboBox_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GComboBox).name();
    g_luaType[typeName] = "fgui.GComboBox";
    g_typeCast["GComboBox"] = "fgui.GComboBox";
    return 1;
}

int lua_libfairygui_GProgressBar_setMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_setMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GProgressBar:setMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_setMin'", nullptr);
            return 0;
        }
        cobj->setMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:setMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_setMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GProgressBar:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_tweenValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_tweenValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GProgressBar:tweenValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GProgressBar:tweenValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_tweenValue'", nullptr);
            return 0;
        }
        cobj->tweenValue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:tweenValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_tweenValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_setMax(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_setMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GProgressBar:setMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_setMax'", nullptr);
            return 0;
        }
        cobj->setMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:setMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_setMax'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_update(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GProgressBar:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_update'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_getValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_getValue'", nullptr);
            return 0;
        }
        double ret = cobj->getValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:getValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_getTitleType(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_getTitleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_getTitleType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getTitleType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:getTitleType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_getTitleType'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_getMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_getMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_getMin'", nullptr);
            return 0;
        }
        double ret = cobj->getMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:getMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_getMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_getMax(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_getMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_getMax'", nullptr);
            return 0;
        }
        double ret = cobj->getMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:getMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_getMax'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_setTitleType(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GProgressBar_setTitleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ProgressTitleType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GProgressBar:setTitleType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_setTitleType'", nullptr);
            return 0;
        }
        cobj->setTitleType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:setTitleType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_setTitleType'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GProgressBar_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_create'", nullptr);
            return 0;
        }
        fairygui::GProgressBar* ret = fairygui::GProgressBar::create();
        object_to_luaval<fairygui::GProgressBar>(tolua_S, "fgui.GProgressBar",(fairygui::GProgressBar*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GProgressBar:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GProgressBar_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GProgressBar_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GProgressBar();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GProgressBar");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GProgressBar:GProgressBar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GProgressBar_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GProgressBar_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GProgressBar)");
    return 0;
}

int lua_register_libfairygui_GProgressBar(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GProgressBar");
    tolua_cclass(tolua_S,"GProgressBar","fgui.GProgressBar","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GProgressBar");
        tolua_function(tolua_S,"new",lua_libfairygui_GProgressBar_constructor);
        tolua_function(tolua_S,"setMin",lua_libfairygui_GProgressBar_setMin);
        tolua_function(tolua_S,"setValue",lua_libfairygui_GProgressBar_setValue);
        tolua_function(tolua_S,"tweenValue",lua_libfairygui_GProgressBar_tweenValue);
        tolua_function(tolua_S,"setMax",lua_libfairygui_GProgressBar_setMax);
        tolua_function(tolua_S,"update",lua_libfairygui_GProgressBar_update);
        tolua_function(tolua_S,"getValue",lua_libfairygui_GProgressBar_getValue);
        tolua_function(tolua_S,"getTitleType",lua_libfairygui_GProgressBar_getTitleType);
        tolua_function(tolua_S,"getMin",lua_libfairygui_GProgressBar_getMin);
        tolua_function(tolua_S,"getMax",lua_libfairygui_GProgressBar_getMax);
        tolua_function(tolua_S,"setTitleType",lua_libfairygui_GProgressBar_setTitleType);
        tolua_function(tolua_S,"create", lua_libfairygui_GProgressBar_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GProgressBar).name();
    g_luaType[typeName] = "fgui.GProgressBar";
    g_typeCast["GProgressBar"] = "fgui.GProgressBar";
    return 1;
}

int lua_libfairygui_GSlider_setMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_setMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GSlider:setMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_setMin'", nullptr);
            return 0;
        }
        cobj->setMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:setMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_setMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GSlider:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_setWholeNumbers(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_setWholeNumbers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GSlider:setWholeNumbers");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_setWholeNumbers'", nullptr);
            return 0;
        }
        cobj->setWholeNumbers(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:setWholeNumbers",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_setWholeNumbers'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_setMax(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_setMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GSlider:setMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_setMax'", nullptr);
            return 0;
        }
        cobj->setMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:setMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_setMax'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_getWholeNumbers(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_getWholeNumbers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_getWholeNumbers'", nullptr);
            return 0;
        }
        bool ret = cobj->getWholeNumbers();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:getWholeNumbers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_getWholeNumbers'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_getValue(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_getValue'", nullptr);
            return 0;
        }
        double ret = cobj->getValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:getValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_getTitleType(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_getTitleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_getTitleType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getTitleType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:getTitleType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_getTitleType'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_getMin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_getMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_getMin'", nullptr);
            return 0;
        }
        double ret = cobj->getMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:getMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_getMin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_getMax(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_getMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_getMax'", nullptr);
            return 0;
        }
        double ret = cobj->getMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:getMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_getMax'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_setTitleType(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GSlider_setTitleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::ProgressTitleType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GSlider:setTitleType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_setTitleType'", nullptr);
            return 0;
        }
        cobj->setTitleType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:setTitleType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_setTitleType'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GSlider_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_create'", nullptr);
            return 0;
        }
        fairygui::GSlider* ret = fairygui::GSlider::create();
        object_to_luaval<fairygui::GSlider>(tolua_S, "fgui.GSlider",(fairygui::GSlider*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GSlider:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GSlider_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GSlider_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GSlider();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GSlider");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GSlider:GSlider",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GSlider_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GSlider_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GSlider)");
    return 0;
}

int lua_register_libfairygui_GSlider(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GSlider");
    tolua_cclass(tolua_S,"GSlider","fgui.GSlider","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GSlider");
        tolua_function(tolua_S,"new",lua_libfairygui_GSlider_constructor);
        tolua_function(tolua_S,"setMin",lua_libfairygui_GSlider_setMin);
        tolua_function(tolua_S,"setValue",lua_libfairygui_GSlider_setValue);
        tolua_function(tolua_S,"setWholeNumbers",lua_libfairygui_GSlider_setWholeNumbers);
        tolua_function(tolua_S,"setMax",lua_libfairygui_GSlider_setMax);
        tolua_function(tolua_S,"getWholeNumbers",lua_libfairygui_GSlider_getWholeNumbers);
        tolua_function(tolua_S,"getValue",lua_libfairygui_GSlider_getValue);
        tolua_function(tolua_S,"getTitleType",lua_libfairygui_GSlider_getTitleType);
        tolua_function(tolua_S,"getMin",lua_libfairygui_GSlider_getMin);
        tolua_function(tolua_S,"getMax",lua_libfairygui_GSlider_getMax);
        tolua_function(tolua_S,"setTitleType",lua_libfairygui_GSlider_setTitleType);
        tolua_function(tolua_S,"create", lua_libfairygui_GSlider_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GSlider).name();
    g_luaType[typeName] = "fgui.GSlider";
    g_typeCast["GSlider"] = "fgui.GSlider";
    return 1;
}

int lua_libfairygui_GScrollBar_setScrollPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GScrollBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GScrollBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GScrollBar_setScrollPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        fairygui::ScrollPane* arg0;
        bool arg1;

        ok &= luaval_to_object<fairygui::ScrollPane>(tolua_S, 2, "fgui.ScrollPane",&arg0, "fgui.GScrollBar:setScrollPane");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GScrollBar:setScrollPane");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_setScrollPane'", nullptr);
            return 0;
        }
        cobj->setScrollPane(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GScrollBar:setScrollPane",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_setScrollPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GScrollBar_setDisplayPerc(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GScrollBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GScrollBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GScrollBar_setDisplayPerc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GScrollBar:setDisplayPerc");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_setDisplayPerc'", nullptr);
            return 0;
        }
        cobj->setDisplayPerc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GScrollBar:setDisplayPerc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_setDisplayPerc'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GScrollBar_getMinSize(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GScrollBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GScrollBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GScrollBar_getMinSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_getMinSize'", nullptr);
            return 0;
        }
        double ret = cobj->getMinSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GScrollBar:getMinSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_getMinSize'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GScrollBar_setScrollPerc(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GScrollBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GScrollBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GScrollBar_setScrollPerc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GScrollBar:setScrollPerc");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_setScrollPerc'", nullptr);
            return 0;
        }
        cobj->setScrollPerc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GScrollBar:setScrollPerc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_setScrollPerc'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GScrollBar_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GScrollBar",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_create'", nullptr);
            return 0;
        }
        fairygui::GScrollBar* ret = fairygui::GScrollBar::create();
        object_to_luaval<fairygui::GScrollBar>(tolua_S, "fgui.GScrollBar",(fairygui::GScrollBar*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GScrollBar:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GScrollBar_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GScrollBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GScrollBar_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GScrollBar();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GScrollBar");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GScrollBar:GScrollBar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GScrollBar_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GScrollBar_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GScrollBar)");
    return 0;
}

int lua_register_libfairygui_GScrollBar(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GScrollBar");
    tolua_cclass(tolua_S,"GScrollBar","fgui.GScrollBar","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GScrollBar");
        tolua_function(tolua_S,"new",lua_libfairygui_GScrollBar_constructor);
        tolua_function(tolua_S,"setScrollPane",lua_libfairygui_GScrollBar_setScrollPane);
        tolua_function(tolua_S,"setDisplayPerc",lua_libfairygui_GScrollBar_setDisplayPerc);
        tolua_function(tolua_S,"getMinSize",lua_libfairygui_GScrollBar_getMinSize);
        tolua_function(tolua_S,"setScrollPerc",lua_libfairygui_GScrollBar_setScrollPerc);
        tolua_function(tolua_S,"create", lua_libfairygui_GScrollBar_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GScrollBar).name();
    g_luaType[typeName] = "fgui.GScrollBar";
    g_typeCast["GScrollBar"] = "fgui.GScrollBar";
    return 1;
}

int lua_libfairygui_GTree_getSelectedNode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_getSelectedNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_getSelectedNode'", nullptr);
            return 0;
        }
        fairygui::GTreeNode* ret = cobj->getSelectedNode();
        object_to_luaval<fairygui::GTreeNode>(tolua_S, "fgui.GTreeNode",(fairygui::GTreeNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:getSelectedNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_getSelectedNode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_expandAll(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_expandAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GTreeNode* arg0;

        ok &= luaval_to_object<fairygui::GTreeNode>(tolua_S, 2, "fgui.GTreeNode",&arg0, "fgui.GTree:expandAll");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_expandAll'", nullptr);
            return 0;
        }
        cobj->expandAll(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:expandAll",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_expandAll'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_getClickToExpand(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_getClickToExpand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_getClickToExpand'", nullptr);
            return 0;
        }
        int ret = cobj->getClickToExpand();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:getClickToExpand",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_getClickToExpand'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_setClickToExpand(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_setClickToExpand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GTree:setClickToExpand");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_setClickToExpand'", nullptr);
            return 0;
        }
        cobj->setClickToExpand(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:setClickToExpand",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_setClickToExpand'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_setIndent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_setIndent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GTree:setIndent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_setIndent'", nullptr);
            return 0;
        }
        cobj->setIndent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:setIndent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_setIndent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_getIndent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_getIndent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_getIndent'", nullptr);
            return 0;
        }
        int ret = cobj->getIndent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:getIndent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_getIndent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_collapseAll(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_collapseAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GTreeNode* arg0;

        ok &= luaval_to_object<fairygui::GTreeNode>(tolua_S, 2, "fgui.GTreeNode",&arg0, "fgui.GTree:collapseAll");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_collapseAll'", nullptr);
            return 0;
        }
        cobj->collapseAll(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:collapseAll",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_collapseAll'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_getRootNode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_getRootNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_getRootNode'", nullptr);
            return 0;
        }
        fairygui::GTreeNode* ret = cobj->getRootNode();
        object_to_luaval<fairygui::GTreeNode>(tolua_S, "fgui.GTreeNode",(fairygui::GTreeNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:getRootNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_getRootNode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_selectNode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_selectNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GTreeNode* arg0;

        ok &= luaval_to_object<fairygui::GTreeNode>(tolua_S, 2, "fgui.GTreeNode",&arg0, "fgui.GTree:selectNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_selectNode'", nullptr);
            return 0;
        }
        cobj->selectNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        fairygui::GTreeNode* arg0;
        bool arg1;

        ok &= luaval_to_object<fairygui::GTreeNode>(tolua_S, 2, "fgui.GTreeNode",&arg0, "fgui.GTree:selectNode");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GTree:selectNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_selectNode'", nullptr);
            return 0;
        }
        cobj->selectNode(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:selectNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_selectNode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_unselectNode(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GTree*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GTree_unselectNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GTreeNode* arg0;

        ok &= luaval_to_object<fairygui::GTreeNode>(tolua_S, 2, "fgui.GTreeNode",&arg0, "fgui.GTree:unselectNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_unselectNode'", nullptr);
            return 0;
        }
        cobj->unselectNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:unselectNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_unselectNode'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GTree_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTree",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_create'", nullptr);
            return 0;
        }
        fairygui::GTree* ret = fairygui::GTree::create();
        object_to_luaval<fairygui::GTree>(tolua_S, "fgui.GTree",(fairygui::GTree*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTree:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTree_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GTree* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTree_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GTree();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GTree");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GTree:GTree",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTree_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GTree_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTree)");
    return 0;
}

int lua_register_libfairygui_GTree(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GTree");
    tolua_cclass(tolua_S,"GTree","fgui.GTree","fgui.GList",nullptr);

    tolua_beginmodule(tolua_S,"GTree");
        tolua_function(tolua_S,"new",lua_libfairygui_GTree_constructor);
        tolua_function(tolua_S,"getSelectedNode",lua_libfairygui_GTree_getSelectedNode);
        tolua_function(tolua_S,"expandAll",lua_libfairygui_GTree_expandAll);
        tolua_function(tolua_S,"getClickToExpand",lua_libfairygui_GTree_getClickToExpand);
        tolua_function(tolua_S,"setClickToExpand",lua_libfairygui_GTree_setClickToExpand);
        tolua_function(tolua_S,"setIndent",lua_libfairygui_GTree_setIndent);
        tolua_function(tolua_S,"getIndent",lua_libfairygui_GTree_getIndent);
        tolua_function(tolua_S,"collapseAll",lua_libfairygui_GTree_collapseAll);
        tolua_function(tolua_S,"getRootNode",lua_libfairygui_GTree_getRootNode);
        tolua_function(tolua_S,"selectNode",lua_libfairygui_GTree_selectNode);
        tolua_function(tolua_S,"unselectNode",lua_libfairygui_GTree_unselectNode);
        tolua_function(tolua_S,"create", lua_libfairygui_GTree_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GTree).name();
    g_luaType[typeName] = "fgui.GTree";
    g_typeCast["GTree"] = "fgui.GTree";
    return 1;
}

int lua_libfairygui_Window_getCloseButton(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getCloseButton'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getCloseButton'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getCloseButton();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getCloseButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getCloseButton'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_getContentPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getContentPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getContentPane'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = cobj->getContentPane();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getContentPane",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getContentPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_show(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_show'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_show'", nullptr);
            return 0;
        }
        cobj->show();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:show",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_show'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_isTop(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_isTop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_isTop'", nullptr);
            return 0;
        }
        bool ret = cobj->isTop();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:isTop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_isTop'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_hideImmediately(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_hideImmediately'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_hideImmediately'", nullptr);
            return 0;
        }
        cobj->hideImmediately();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:hideImmediately",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_hideImmediately'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_toggleStatus(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_toggleStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_toggleStatus'", nullptr);
            return 0;
        }
        cobj->toggleStatus();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:toggleStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_toggleStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_hide(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_hide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_hide'", nullptr);
            return 0;
        }
        cobj->hide();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:hide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_hide'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_getFrame(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getFrame'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = cobj->getFrame();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_isShowing(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_isShowing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_isShowing'", nullptr);
            return 0;
        }
        bool ret = cobj->isShowing();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:isShowing",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_isShowing'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_closeModalWait(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_closeModalWait'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.Window:closeModalWait");

            if (!ok) { break; }
            bool ret = cobj->closeModalWait(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->closeModalWait();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.Window:closeModalWait",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_closeModalWait'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_initWindow(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_initWindow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_initWindow'", nullptr);
            return 0;
        }
        cobj->initWindow();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:initWindow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_initWindow'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setContentArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setContentArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.Window:setContentArea");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setContentArea'", nullptr);
            return 0;
        }
        cobj->setContentArea(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setContentArea",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setContentArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setDragArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setDragArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.Window:setDragArea");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setDragArea'", nullptr);
            return 0;
        }
        cobj->setDragArea(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setDragArea",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setDragArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setContentPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setContentPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GComponent* arg0;

        ok &= luaval_to_object<fairygui::GComponent>(tolua_S, 2, "fgui.GComponent",&arg0, "fgui.Window:setContentPane");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setContentPane'", nullptr);
            return 0;
        }
        cobj->setContentPane(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setContentPane",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setContentPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_isModal(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_isModal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_isModal'", nullptr);
            return 0;
        }
        bool ret = cobj->isModal();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:isModal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_isModal'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_isBringToFrontOnClick(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_isBringToFrontOnClick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_isBringToFrontOnClick'", nullptr);
            return 0;
        }
        bool ret = cobj->isBringToFrontOnClick();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:isBringToFrontOnClick",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_isBringToFrontOnClick'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_getContentArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getContentArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getContentArea'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getContentArea();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getContentArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getContentArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setBringToFrontOnClick(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setBringToFrontOnClick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.Window:setBringToFrontOnClick");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setBringToFrontOnClick'", nullptr);
            return 0;
        }
        cobj->setBringToFrontOnClick(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setBringToFrontOnClick",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setBringToFrontOnClick'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setModal(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setModal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.Window:setModal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setModal'", nullptr);
            return 0;
        }
        cobj->setModal(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setModal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setModal'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_getModalWaitingPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getModalWaitingPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getModalWaitingPane'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getModalWaitingPane();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getModalWaitingPane",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getModalWaitingPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_getDragArea(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_getDragArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_getDragArea'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getDragArea();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:getDragArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_getDragArea'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_bringToFront(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_bringToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_bringToFront'", nullptr);
            return 0;
        }
        cobj->bringToFront();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:bringToFront",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_bringToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_showModalWait(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_showModalWait'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.Window:showModalWait");

            if (!ok) { break; }
            cobj->showModalWait(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->showModalWait();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.Window:showModalWait",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_showModalWait'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_setCloseButton(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_setCloseButton'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.Window:setCloseButton");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_setCloseButton'", nullptr);
            return 0;
        }
        cobj->setCloseButton(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:setCloseButton",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_setCloseButton'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_addUISource(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::Window*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_Window_addUISource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::IUISource* arg0;

        ok &= luaval_to_object<fairygui::IUISource>(tolua_S, 2, "fgui.IUISource",&arg0, "fgui.Window:addUISource");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_addUISource'", nullptr);
            return 0;
        }
        cobj->addUISource(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:addUISource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_addUISource'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_Window_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.Window",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_create'", nullptr);
            return 0;
        }
        fairygui::Window* ret = fairygui::Window::create();
        object_to_luaval<fairygui::Window>(tolua_S, "fgui.Window",(fairygui::Window*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.Window:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_Window_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::Window* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_Window_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::Window();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.Window");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.Window:Window",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_Window_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_Window_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Window)");
    return 0;
}

int lua_register_libfairygui_Window(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.Window");
    tolua_cclass(tolua_S,"Window","fgui.Window","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"Window");
        tolua_function(tolua_S,"new",lua_libfairygui_Window_constructor);
        tolua_function(tolua_S,"getCloseButton",lua_libfairygui_Window_getCloseButton);
        tolua_function(tolua_S,"getContentPane",lua_libfairygui_Window_getContentPane);
        tolua_function(tolua_S,"show",lua_libfairygui_Window_show);
        tolua_function(tolua_S,"isTop",lua_libfairygui_Window_isTop);
        tolua_function(tolua_S,"hideImmediately",lua_libfairygui_Window_hideImmediately);
        tolua_function(tolua_S,"toggleStatus",lua_libfairygui_Window_toggleStatus);
        tolua_function(tolua_S,"hide",lua_libfairygui_Window_hide);
        tolua_function(tolua_S,"getFrame",lua_libfairygui_Window_getFrame);
        tolua_function(tolua_S,"isShowing",lua_libfairygui_Window_isShowing);
        tolua_function(tolua_S,"closeModalWait",lua_libfairygui_Window_closeModalWait);
        tolua_function(tolua_S,"initWindow",lua_libfairygui_Window_initWindow);
        tolua_function(tolua_S,"setContentArea",lua_libfairygui_Window_setContentArea);
        tolua_function(tolua_S,"setDragArea",lua_libfairygui_Window_setDragArea);
        tolua_function(tolua_S,"setContentPane",lua_libfairygui_Window_setContentPane);
        tolua_function(tolua_S,"isModal",lua_libfairygui_Window_isModal);
        tolua_function(tolua_S,"isBringToFrontOnClick",lua_libfairygui_Window_isBringToFrontOnClick);
        tolua_function(tolua_S,"getContentArea",lua_libfairygui_Window_getContentArea);
        tolua_function(tolua_S,"setBringToFrontOnClick",lua_libfairygui_Window_setBringToFrontOnClick);
        tolua_function(tolua_S,"setModal",lua_libfairygui_Window_setModal);
        tolua_function(tolua_S,"getModalWaitingPane",lua_libfairygui_Window_getModalWaitingPane);
        tolua_function(tolua_S,"getDragArea",lua_libfairygui_Window_getDragArea);
        tolua_function(tolua_S,"bringToFront",lua_libfairygui_Window_bringToFront);
        tolua_function(tolua_S,"showModalWait",lua_libfairygui_Window_showModalWait);
        tolua_function(tolua_S,"setCloseButton",lua_libfairygui_Window_setCloseButton);
        tolua_function(tolua_S,"addUISource",lua_libfairygui_Window_addUISource);
        tolua_function(tolua_S,"create", lua_libfairygui_Window_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::Window).name();
    g_luaType[typeName] = "fgui.Window";
    g_typeCast["Window"] = "fgui.Window";
    return 1;
}

int lua_libfairygui_GRoot_closeAllWindows(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_closeAllWindows'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_closeAllWindows'", nullptr);
            return 0;
        }
        cobj->closeAllWindows();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:closeAllWindows",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_closeAllWindows'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hideTooltips(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hideTooltips'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_hideTooltips'", nullptr);
            return 0;
        }
        cobj->hideTooltips();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:hideTooltips",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hideTooltips'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hasAnyPopup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hasAnyPopup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_hasAnyPopup'", nullptr);
            return 0;
        }
        bool ret = cobj->hasAnyPopup();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:hasAnyPopup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hasAnyPopup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getTopWindow(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getTopWindow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getTopWindow'", nullptr);
            return 0;
        }
        fairygui::Window* ret = cobj->getTopWindow();
        object_to_luaval<fairygui::Window>(tolua_S, "fgui.Window",(fairygui::Window*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getTopWindow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getTopWindow'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hidePopup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hidePopup'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:hidePopup");

            if (!ok) { break; }
            cobj->hidePopup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->hidePopup();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GRoot:hidePopup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hidePopup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_closeAllExceptModals(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_closeAllExceptModals'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_closeAllExceptModals'", nullptr);
            return 0;
        }
        cobj->closeAllExceptModals();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:closeAllExceptModals",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_closeAllExceptModals'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_showPopup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_showPopup'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:showPopup");

            if (!ok) { break; }
            fairygui::GObject* arg1;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 3, "fgui.GObject",&arg1, "fgui.GRoot:showPopup");

            if (!ok) { break; }
            fairygui::PopupDirection arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GRoot:showPopup");

            if (!ok) { break; }
            cobj->showPopup(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:showPopup");

            if (!ok) { break; }
            cobj->showPopup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GRoot:showPopup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_showPopup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_showTooltipsWin(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_showTooltipsWin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::GObject* arg0;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:showTooltipsWin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_showTooltipsWin'", nullptr);
            return 0;
        }
        cobj->showTooltipsWin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:showTooltipsWin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_showTooltipsWin'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_closeModalWait(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_closeModalWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_closeModalWait'", nullptr);
            return 0;
        }
        cobj->closeModalWait();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:closeModalWait",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_closeModalWait'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getInputProcessor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getInputProcessor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getInputProcessor'", nullptr);
            return 0;
        }
        fairygui::InputProcessor* ret = cobj->getInputProcessor();
        object_to_luaval<fairygui::InputProcessor>(tolua_S, "fgui.InputProcessor",(fairygui::InputProcessor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getInputProcessor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getInputProcessor'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getSoundVolumeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getSoundVolumeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getSoundVolumeScale'", nullptr);
            return 0;
        }
        double ret = cobj->getSoundVolumeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getSoundVolumeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getSoundVolumeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_togglePopup(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_togglePopup'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:togglePopup");

            if (!ok) { break; }
            fairygui::GObject* arg1;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 3, "fgui.GObject",&arg1, "fgui.GRoot:togglePopup");

            if (!ok) { break; }
            fairygui::PopupDirection arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GRoot:togglePopup");

            if (!ok) { break; }
            cobj->togglePopup(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:togglePopup");

            if (!ok) { break; }
            cobj->togglePopup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.GRoot:togglePopup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_togglePopup'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_isSoundEnabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_isSoundEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_isSoundEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isSoundEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:isSoundEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_isSoundEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_setSoundVolumeScale(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_setSoundVolumeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GRoot:setSoundVolumeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_setSoundVolumeScale'", nullptr);
            return 0;
        }
        cobj->setSoundVolumeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:setSoundVolumeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_setSoundVolumeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getTouchTarget(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getTouchTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getTouchTarget'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getTouchTarget();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getTouchTarget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getTouchTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hideWindowImmediately(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hideWindowImmediately'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::Window* arg0;

        ok &= luaval_to_object<fairygui::Window>(tolua_S, 2, "fgui.Window",&arg0, "fgui.GRoot:hideWindowImmediately");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_hideWindowImmediately'", nullptr);
            return 0;
        }
        cobj->hideWindowImmediately(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:hideWindowImmediately",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hideWindowImmediately'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getModalLayer(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getModalLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getModalLayer'", nullptr);
            return 0;
        }
        fairygui::GGraph* ret = cobj->getModalLayer();
        object_to_luaval<fairygui::GGraph>(tolua_S, "fgui.GGraph",(fairygui::GGraph*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getModalLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getModalLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_playSound(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_playSound'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GRoot:playSound");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_playSound'", nullptr);
            return 0;
        }
        cobj->playSound(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GRoot:playSound");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GRoot:playSound");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_playSound'", nullptr);
            return 0;
        }
        cobj->playSound(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:playSound",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_playSound'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getModalWaitingPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getModalWaitingPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getModalWaitingPane'", nullptr);
            return 0;
        }
        fairygui::GObject* ret = cobj->getModalWaitingPane();
        object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getModalWaitingPane",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getModalWaitingPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_setSoundEnabled(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_setSoundEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui.GRoot:setSoundEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_setSoundEnabled'", nullptr);
            return 0;
        }
        cobj->setSoundEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:setSoundEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_setSoundEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_bringToFront(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_bringToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::Window* arg0;

        ok &= luaval_to_object<fairygui::Window>(tolua_S, 2, "fgui.Window",&arg0, "fgui.GRoot:bringToFront");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_bringToFront'", nullptr);
            return 0;
        }
        cobj->bringToFront(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:bringToFront",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_bringToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hasModalWindow(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hasModalWindow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_hasModalWindow'", nullptr);
            return 0;
        }
        bool ret = cobj->hasModalWindow();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:hasModalWindow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hasModalWindow'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_showModalWait(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_showModalWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_showModalWait'", nullptr);
            return 0;
        }
        cobj->showModalWait();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:showModalWait",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_showModalWait'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_isModalWaiting(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_isModalWaiting'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_isModalWaiting'", nullptr);
            return 0;
        }
        bool ret = cobj->isModalWaiting();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:isModalWaiting",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_isModalWaiting'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getTouchPosition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getTouchPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GRoot:getTouchPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getTouchPosition'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getTouchPosition(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getTouchPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getTouchPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_getPoupPosition(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_getPoupPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        fairygui::GObject* arg0;
        fairygui::GObject* arg1;
        fairygui::PopupDirection arg2;

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.GRoot:getPoupPosition");

        ok &= luaval_to_object<fairygui::GObject>(tolua_S, 3, "fgui.GObject",&arg1, "fgui.GRoot:getPoupPosition");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.GRoot:getPoupPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getPoupPosition'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getPoupPosition(arg0, arg1, arg2);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:getPoupPosition",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getPoupPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_showWindow(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_showWindow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::Window* arg0;

        ok &= luaval_to_object<fairygui::Window>(tolua_S, 2, "fgui.Window",&arg0, "fgui.GRoot:showWindow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_showWindow'", nullptr);
            return 0;
        }
        cobj->showWindow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:showWindow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_showWindow'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_showTooltips(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_showTooltips'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.GRoot:showTooltips");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_showTooltips'", nullptr);
            return 0;
        }
        cobj->showTooltips(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:showTooltips",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_showTooltips'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_hideWindow(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_GRoot_hideWindow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fairygui::Window* arg0;

        ok &= luaval_to_object<fairygui::Window>(tolua_S, 2, "fgui.Window",&arg0, "fgui.GRoot:hideWindow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_hideWindow'", nullptr);
            return 0;
        }
        cobj->hideWindow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:hideWindow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_hideWindow'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_GRoot_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Scene* arg0;
        ok &= luaval_to_object<cocos2d::Scene>(tolua_S, 2, "cc.Scene",&arg0, "fgui.GRoot:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_create'", nullptr);
            return 0;
        }
        fairygui::GRoot* ret = fairygui::GRoot::create(arg0);
        object_to_luaval<fairygui::GRoot>(tolua_S, "fgui.GRoot",(fairygui::GRoot*)ret);
        return 1;
    }
    if (argc == 2)
    {
        cocos2d::Scene* arg0;
        int arg1;
        ok &= luaval_to_object<cocos2d::Scene>(tolua_S, 2, "cc.Scene",&arg0, "fgui.GRoot:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GRoot:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_create'", nullptr);
            return 0;
        }
        fairygui::GRoot* ret = fairygui::GRoot::create(arg0, arg1);
        object_to_luaval<fairygui::GRoot>(tolua_S, "fgui.GRoot",(fairygui::GRoot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GRoot:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GRoot_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GRoot",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_getInstance'", nullptr);
            return 0;
        }
        fairygui::GRoot* ret = fairygui::GRoot::getInstance();
        object_to_luaval<fairygui::GRoot>(tolua_S, "fgui.GRoot",(fairygui::GRoot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GRoot:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GRoot_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::GRoot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GRoot_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::GRoot();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.GRoot");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.GRoot:GRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GRoot_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_GRoot_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GRoot)");
    return 0;
}

int lua_register_libfairygui_GRoot(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GRoot");
    tolua_cclass(tolua_S,"GRoot","fgui.GRoot","fgui.GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GRoot");
        tolua_function(tolua_S,"new",lua_libfairygui_GRoot_constructor);
        tolua_function(tolua_S,"closeAllWindows",lua_libfairygui_GRoot_closeAllWindows);
        tolua_function(tolua_S,"hideTooltips",lua_libfairygui_GRoot_hideTooltips);
        tolua_function(tolua_S,"hasAnyPopup",lua_libfairygui_GRoot_hasAnyPopup);
        tolua_function(tolua_S,"getTopWindow",lua_libfairygui_GRoot_getTopWindow);
        tolua_function(tolua_S,"hidePopup",lua_libfairygui_GRoot_hidePopup);
        tolua_function(tolua_S,"closeAllExceptModals",lua_libfairygui_GRoot_closeAllExceptModals);
        tolua_function(tolua_S,"showPopup",lua_libfairygui_GRoot_showPopup);
        tolua_function(tolua_S,"showTooltipsWin",lua_libfairygui_GRoot_showTooltipsWin);
        tolua_function(tolua_S,"closeModalWait",lua_libfairygui_GRoot_closeModalWait);
        tolua_function(tolua_S,"getInputProcessor",lua_libfairygui_GRoot_getInputProcessor);
        tolua_function(tolua_S,"getSoundVolumeScale",lua_libfairygui_GRoot_getSoundVolumeScale);
        tolua_function(tolua_S,"togglePopup",lua_libfairygui_GRoot_togglePopup);
        tolua_function(tolua_S,"isSoundEnabled",lua_libfairygui_GRoot_isSoundEnabled);
        tolua_function(tolua_S,"setSoundVolumeScale",lua_libfairygui_GRoot_setSoundVolumeScale);
        tolua_function(tolua_S,"getTouchTarget",lua_libfairygui_GRoot_getTouchTarget);
        tolua_function(tolua_S,"hideWindowImmediately",lua_libfairygui_GRoot_hideWindowImmediately);
        tolua_function(tolua_S,"getModalLayer",lua_libfairygui_GRoot_getModalLayer);
        tolua_function(tolua_S,"playSound",lua_libfairygui_GRoot_playSound);
        tolua_function(tolua_S,"getModalWaitingPane",lua_libfairygui_GRoot_getModalWaitingPane);
        tolua_function(tolua_S,"setSoundEnabled",lua_libfairygui_GRoot_setSoundEnabled);
        tolua_function(tolua_S,"bringToFront",lua_libfairygui_GRoot_bringToFront);
        tolua_function(tolua_S,"hasModalWindow",lua_libfairygui_GRoot_hasModalWindow);
        tolua_function(tolua_S,"showModalWait",lua_libfairygui_GRoot_showModalWait);
        tolua_function(tolua_S,"isModalWaiting",lua_libfairygui_GRoot_isModalWaiting);
        tolua_function(tolua_S,"getTouchPosition",lua_libfairygui_GRoot_getTouchPosition);
        tolua_function(tolua_S,"getPoupPosition",lua_libfairygui_GRoot_getPoupPosition);
        tolua_function(tolua_S,"showWindow",lua_libfairygui_GRoot_showWindow);
        tolua_function(tolua_S,"showTooltips",lua_libfairygui_GRoot_showTooltips);
        tolua_function(tolua_S,"hideWindow",lua_libfairygui_GRoot_hideWindow);
        tolua_function(tolua_S,"create", lua_libfairygui_GRoot_create);
        tolua_function(tolua_S,"getInstance", lua_libfairygui_GRoot_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GRoot).name();
    g_luaType[typeName] = "fgui.GRoot";
    g_typeCast["GRoot"] = "fgui.GRoot";
    return 1;
}

int lua_libfairygui_PopupMenu_setItemGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_setItemGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:setItemGrayed");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.PopupMenu:setItemGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_setItemGrayed'", nullptr);
            return 0;
        }
        cobj->setItemGrayed(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:setItemGrayed",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_setItemGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_getItemName(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_getItemName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.PopupMenu:getItemName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_getItemName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getItemName(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:getItemName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_getItemName'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_clearItems(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_clearItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_clearItems'", nullptr);
            return 0;
        }
        cobj->clearItems();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:clearItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_clearItems'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_getList(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_getList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_getList'", nullptr);
            return 0;
        }
        fairygui::GList* ret = cobj->getList();
        object_to_luaval<fairygui::GList>(tolua_S, "fgui.GList",(fairygui::GList*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:getList",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_getList'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_removeItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_removeItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:removeItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_removeItem'", nullptr);
            return 0;
        }
        bool ret = cobj->removeItem(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:removeItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_removeItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_addItem(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_addItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::function<void (fairygui::EventContext *)> arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:addItem");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_addItem'", nullptr);
            return 0;
        }
        fairygui::GButton* ret = cobj->addItem(arg0, arg1);
        object_to_luaval<fairygui::GButton>(tolua_S, "fgui.GButton",(fairygui::GButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:addItem",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_addItem'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_addSeperator(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_addSeperator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_addSeperator'", nullptr);
            return 0;
        }
        cobj->addSeperator();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:addSeperator",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_addSeperator'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_addItemAt(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_addItemAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        std::function<void (fairygui::EventContext *)> arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:addItemAt");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.PopupMenu:addItemAt");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_addItemAt'", nullptr);
            return 0;
        }
        fairygui::GButton* ret = cobj->addItemAt(arg0, arg1, arg2);
        object_to_luaval<fairygui::GButton>(tolua_S, "fgui.GButton",(fairygui::GButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:addItemAt",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_addItemAt'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_setItemText(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_setItemText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:setItemText");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui.PopupMenu:setItemText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_setItemText'", nullptr);
            return 0;
        }
        cobj->setItemText(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:setItemText",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_setItemText'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_setItemChecked(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_setItemChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:setItemChecked");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.PopupMenu:setItemChecked");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_setItemChecked'", nullptr);
            return 0;
        }
        cobj->setItemChecked(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:setItemChecked",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_setItemChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_show(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_show'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            fairygui::GObject* arg0;
            ok &= luaval_to_object<fairygui::GObject>(tolua_S, 2, "fgui.GObject",&arg0, "fgui.PopupMenu:show");

            if (!ok) { break; }
            fairygui::PopupDirection arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.PopupMenu:show");

            if (!ok) { break; }
            cobj->show(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->show();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui.PopupMenu:show",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_show'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_getContentPane(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_getContentPane'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_getContentPane'", nullptr);
            return 0;
        }
        fairygui::GComponent* ret = cobj->getContentPane();
        object_to_luaval<fairygui::GComponent>(tolua_S, "fgui.GComponent",(fairygui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:getContentPane",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_getContentPane'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_getItemCount(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_getItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_getItemCount'", nullptr);
            return 0;
        }
        int ret = cobj->getItemCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:getItemCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_getItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_setItemCheckable(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_setItemCheckable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:setItemCheckable");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.PopupMenu:setItemCheckable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_setItemCheckable'", nullptr);
            return 0;
        }
        cobj->setItemCheckable(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:setItemCheckable",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_setItemCheckable'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_isItemChecked(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_isItemChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:isItemChecked");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_isItemChecked'", nullptr);
            return 0;
        }
        bool ret = cobj->isItemChecked(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:isItemChecked",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_isItemChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_setItemVisible(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_PopupMenu_setItemVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:setItemVisible");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.PopupMenu:setItemVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_setItemVisible'", nullptr);
            return 0;
        }
        cobj->setItemVisible(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:setItemVisible",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_setItemVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_PopupMenu_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.PopupMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 0)
        {
            fairygui::PopupMenu* ret = fairygui::PopupMenu::create();
            object_to_luaval<fairygui::PopupMenu>(tolua_S, "fgui.PopupMenu",(fairygui::PopupMenu*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.PopupMenu:create");
            if (!ok) { break; }
            fairygui::PopupMenu* ret = fairygui::PopupMenu::create(arg0);
            object_to_luaval<fairygui::PopupMenu>(tolua_S, "fgui.PopupMenu",(fairygui::PopupMenu*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.PopupMenu:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_create'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_PopupMenu_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::PopupMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_PopupMenu_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::PopupMenu();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui.PopupMenu");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.PopupMenu:PopupMenu",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_PopupMenu_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_PopupMenu_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PopupMenu)");
    return 0;
}

int lua_register_libfairygui_PopupMenu(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.PopupMenu");
    tolua_cclass(tolua_S,"PopupMenu","fgui.PopupMenu","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PopupMenu");
        tolua_function(tolua_S,"new",lua_libfairygui_PopupMenu_constructor);
        tolua_function(tolua_S,"setItemGrayed",lua_libfairygui_PopupMenu_setItemGrayed);
        tolua_function(tolua_S,"getItemName",lua_libfairygui_PopupMenu_getItemName);
        tolua_function(tolua_S,"clearItems",lua_libfairygui_PopupMenu_clearItems);
        tolua_function(tolua_S,"getList",lua_libfairygui_PopupMenu_getList);
        tolua_function(tolua_S,"removeItem",lua_libfairygui_PopupMenu_removeItem);
        tolua_function(tolua_S,"addItem",lua_libfairygui_PopupMenu_addItem);
        tolua_function(tolua_S,"addSeperator",lua_libfairygui_PopupMenu_addSeperator);
        tolua_function(tolua_S,"addItemAt",lua_libfairygui_PopupMenu_addItemAt);
        tolua_function(tolua_S,"setItemText",lua_libfairygui_PopupMenu_setItemText);
        tolua_function(tolua_S,"setItemChecked",lua_libfairygui_PopupMenu_setItemChecked);
        tolua_function(tolua_S,"show",lua_libfairygui_PopupMenu_show);
        tolua_function(tolua_S,"getContentPane",lua_libfairygui_PopupMenu_getContentPane);
        tolua_function(tolua_S,"getItemCount",lua_libfairygui_PopupMenu_getItemCount);
        tolua_function(tolua_S,"setItemCheckable",lua_libfairygui_PopupMenu_setItemCheckable);
        tolua_function(tolua_S,"isItemChecked",lua_libfairygui_PopupMenu_isItemChecked);
        tolua_function(tolua_S,"setItemVisible",lua_libfairygui_PopupMenu_setItemVisible);
        tolua_function(tolua_S,"create", lua_libfairygui_PopupMenu_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::PopupMenu).name();
    g_luaType[typeName] = "fgui.PopupMenu";
    g_typeCast["PopupMenu"] = "fgui.PopupMenu";
    return 1;
}

int lua_libfairygui_UIObjectFactory_setLoaderExtension(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIObjectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::function<fairygui::GLoader * ()> arg0;
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIObjectFactory_setLoaderExtension'", nullptr);
            return 0;
        }
        fairygui::UIObjectFactory::setLoaderExtension(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIObjectFactory:setLoaderExtension",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIObjectFactory_setLoaderExtension'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIObjectFactory_newObject(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIObjectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            fairygui::ObjectType arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.UIObjectFactory:newObject");
            if (!ok) { break; }
            fairygui::GObject* ret = fairygui::UIObjectFactory::newObject(arg0);
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            fairygui::PackageItem* arg0;
            ok &= luaval_to_object<fairygui::PackageItem>(tolua_S, 2, "fgui.PackageItem",&arg0, "fgui.UIObjectFactory:newObject");
            if (!ok) { break; }
            fairygui::GObject* ret = fairygui::UIObjectFactory::newObject(arg0);
            object_to_luaval<fairygui::GObject>(tolua_S, "fgui.GObject",(fairygui::GObject*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.UIObjectFactory:newObject",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIObjectFactory_newObject'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_UIObjectFactory_setPackageItemExtension(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.UIObjectFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::function<fairygui::GComponent * ()> arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.UIObjectFactory:setPackageItemExtension");
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_UIObjectFactory_setPackageItemExtension'", nullptr);
            return 0;
        }
        fairygui::UIObjectFactory::setPackageItemExtension(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.UIObjectFactory:setPackageItemExtension",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_UIObjectFactory_setPackageItemExtension'.",&tolua_err);
#endif
    return 0;
}
static int lua_libfairygui_UIObjectFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIObjectFactory)");
    return 0;
}

int lua_register_libfairygui_UIObjectFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.UIObjectFactory");
    tolua_cclass(tolua_S,"UIObjectFactory","fgui.UIObjectFactory","",nullptr);

    tolua_beginmodule(tolua_S,"UIObjectFactory");
        tolua_function(tolua_S,"setLoaderExtension", lua_libfairygui_UIObjectFactory_setLoaderExtension);
        tolua_function(tolua_S,"newObject", lua_libfairygui_UIObjectFactory_newObject);
        tolua_function(tolua_S,"setPackageItemExtension", lua_libfairygui_UIObjectFactory_setPackageItemExtension);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::UIObjectFactory).name();
    g_luaType[typeName] = "fgui.UIObjectFactory";
    g_typeCast["UIObjectFactory"] = "fgui.UIObjectFactory";
    return 1;
}

int lua_libfairygui_DragDropManager_cancel(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::DragDropManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.DragDropManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_DragDropManager_cancel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_cancel'", nullptr);
            return 0;
        }
        cobj->cancel();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.DragDropManager:cancel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_cancel'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_DragDropManager_isDragging(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::DragDropManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.DragDropManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_DragDropManager_isDragging'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_isDragging'", nullptr);
            return 0;
        }
        bool ret = cobj->isDragging();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.DragDropManager:isDragging",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_isDragging'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_DragDropManager_getAgent(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::DragDropManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.DragDropManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_DragDropManager_getAgent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_getAgent'", nullptr);
            return 0;
        }
        fairygui::GLoader* ret = cobj->getAgent();
        object_to_luaval<fairygui::GLoader>(tolua_S, "fgui.GLoader",(fairygui::GLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.DragDropManager:getAgent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_getAgent'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_DragDropManager_startDrag(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::DragDropManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui.DragDropManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_libfairygui_DragDropManager_startDrag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.DragDropManager:startDrag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_startDrag'", nullptr);
            return 0;
        }
        cobj->startDrag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.DragDropManager:startDrag");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "fgui.DragDropManager:startDrag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_startDrag'", nullptr);
            return 0;
        }
        cobj->startDrag(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        cocos2d::Value arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui.DragDropManager:startDrag");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "fgui.DragDropManager:startDrag");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui.DragDropManager:startDrag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_startDrag'", nullptr);
            return 0;
        }
        cobj->startDrag(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.DragDropManager:startDrag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_startDrag'.",&tolua_err);
#endif

    return 0;
}
int lua_libfairygui_DragDropManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.DragDropManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_getInstance'", nullptr);
            return 0;
        }
        fairygui::DragDropManager* ret = fairygui::DragDropManager::getInstance();
        object_to_luaval<fairygui::DragDropManager>(tolua_S, "fgui.DragDropManager",(fairygui::DragDropManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.DragDropManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_DragDropManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fairygui::DragDropManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_DragDropManager_constructor'", nullptr);
            return 0;
        }
        cobj = new fairygui::DragDropManager();
        tolua_pushusertype(tolua_S,(void*)cobj,"fgui.DragDropManager");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui.DragDropManager:DragDropManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_DragDropManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_libfairygui_DragDropManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DragDropManager)");
    return 0;
}

int lua_register_libfairygui_DragDropManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.DragDropManager");
    tolua_cclass(tolua_S,"DragDropManager","fgui.DragDropManager","",nullptr);

    tolua_beginmodule(tolua_S,"DragDropManager");
        tolua_function(tolua_S,"new",lua_libfairygui_DragDropManager_constructor);
        tolua_function(tolua_S,"cancel",lua_libfairygui_DragDropManager_cancel);
        tolua_function(tolua_S,"isDragging",lua_libfairygui_DragDropManager_isDragging);
        tolua_function(tolua_S,"getAgent",lua_libfairygui_DragDropManager_getAgent);
        tolua_function(tolua_S,"startDrag",lua_libfairygui_DragDropManager_startDrag);
        tolua_function(tolua_S,"getInstance", lua_libfairygui_DragDropManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::DragDropManager).name();
    g_luaType[typeName] = "fgui.DragDropManager";
    g_typeCast["DragDropManager"] = "fgui.DragDropManager";
    return 1;
}

int lua_libfairygui_GTween_getTween(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:getTween");
            if (!ok) { break; }
            fairygui::TweenPropType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GTween:getTween");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::getTween(arg0, arg1);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:getTween");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::getTween(arg0);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.GTween:getTween",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_getTween'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_isTweening(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:isTweening");
            if (!ok) { break; }
            fairygui::TweenPropType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GTween:isTweening");
            if (!ok) { break; }
            bool ret = fairygui::GTween::isTweening(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:isTweening");
            if (!ok) { break; }
            bool ret = fairygui::GTween::isTweening(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.GTween:isTweening",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_isTweening'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_delayedCall(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GTween:delayedCall");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTween_delayedCall'", nullptr);
            return 0;
        }
        fairygui::GTweener* ret = fairygui::GTween::delayedCall(arg0);
        object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTween:delayedCall",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_delayedCall'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_to(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            cocos2d::Vec2 arg0;
            ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GTween:to");
            if (!ok) { break; }
            cocos2d::Vec2 arg1;
            ok &= luaval_to_vec2(tolua_S, 3, &arg1, "fgui.GTween:to");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:to");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::to(arg0, arg1, arg2);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GTween:to");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GTween:to");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:to");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::to(arg0, arg1, arg2);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Vec3 arg0;
            ok &= luaval_to_vec3(tolua_S, 2, &arg0, "fgui.GTween:to");
            if (!ok) { break; }
            cocos2d::Vec3 arg1;
            ok &= luaval_to_vec3(tolua_S, 3, &arg1, "fgui.GTween:to");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:to");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::to(arg0, arg1, arg2);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Vec4 arg0;
            ok &= luaval_to_vec4(tolua_S, 2, &arg0, "fgui.GTween:to");
            if (!ok) { break; }
            cocos2d::Vec4 arg1;
            ok &= luaval_to_vec4(tolua_S, 3, &arg1, "fgui.GTween:to");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:to");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::to(arg0, arg1, arg2);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui.GTween:to");
            if (!ok) { break; }
            cocos2d::Color4B arg1;
            ok &=luaval_to_color4b(tolua_S, 3, &arg1, "fgui.GTween:to");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:to");
            if (!ok) { break; }
            fairygui::GTweener* ret = fairygui::GTween::to(arg0, arg1, arg2);
            object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.GTween:to",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_to'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_toDouble(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        double arg1;
        double arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui.GTween:toDouble");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GTween:toDouble");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:toDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTween_toDouble'", nullptr);
            return 0;
        }
        fairygui::GTweener* ret = fairygui::GTween::toDouble(arg0, arg1, arg2);
        object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTween:toDouble",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_toDouble'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_clean(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTween_clean'", nullptr);
            return 0;
        }
        fairygui::GTween::clean();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTween:clean",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_clean'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_shake(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui.GTween:shake");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui.GTween:shake");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui.GTween:shake");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_libfairygui_GTween_shake'", nullptr);
            return 0;
        }
        fairygui::GTweener* ret = fairygui::GTween::shake(arg0, arg1, arg2);
        object_to_luaval<fairygui::GTweener>(tolua_S, "fgui.GTweener",(fairygui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui.GTween:shake",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_shake'.",&tolua_err);
#endif
    return 0;
}
int lua_libfairygui_GTween_kill(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui.GTween",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:kill");
            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui.GTween:kill");
            if (!ok) { break; }
            fairygui::GTween::kill(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:kill");
            if (!ok) { break; }
            fairygui::GTween::kill(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui.GTween:kill");
            if (!ok) { break; }
            fairygui::TweenPropType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui.GTween:kill");
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui.GTween:kill");
            if (!ok) { break; }
            fairygui::GTween::kill(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui.GTween:kill",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_libfairygui_GTween_kill'.",&tolua_err);
#endif
    return 0;
}
static int lua_libfairygui_GTween_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTween)");
    return 0;
}

int lua_register_libfairygui_GTween(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui.GTween");
    tolua_cclass(tolua_S,"GTween","fgui.GTween","",nullptr);

    tolua_beginmodule(tolua_S,"GTween");
        tolua_function(tolua_S,"getTween", lua_libfairygui_GTween_getTween);
        tolua_function(tolua_S,"isTweening", lua_libfairygui_GTween_isTweening);
        tolua_function(tolua_S,"delayedCall", lua_libfairygui_GTween_delayedCall);
        tolua_function(tolua_S,"to", lua_libfairygui_GTween_to);
        tolua_function(tolua_S,"toDouble", lua_libfairygui_GTween_toDouble);
        tolua_function(tolua_S,"clean", lua_libfairygui_GTween_clean);
        tolua_function(tolua_S,"shake", lua_libfairygui_GTween_shake);
        tolua_function(tolua_S,"kill", lua_libfairygui_GTween_kill);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fairygui::GTween).name();
    g_luaType[typeName] = "fgui.GTween";
    g_typeCast["GTween"] = "fgui.GTween";
    return 1;
}
TOLUA_API int register_all_libfairygui(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"fgui",0);
	tolua_beginmodule(tolua_S,"fgui");

	lua_register_libfairygui_UIEventDispatcher(tolua_S);
	lua_register_libfairygui_GObject(tolua_S);
	lua_register_libfairygui_GComponent(tolua_S);
	lua_register_libfairygui_GList(tolua_S);
	lua_register_libfairygui_GTree(tolua_S);
	lua_register_libfairygui_GImage(tolua_S);
	lua_register_libfairygui_GScrollBar(tolua_S);
	lua_register_libfairygui_GComboBox(tolua_S);
	lua_register_libfairygui_GButton(tolua_S);
	lua_register_libfairygui_GGroup(tolua_S);
	lua_register_libfairygui_GMovieClip(tolua_S);
	lua_register_libfairygui_GTextField(tolua_S);
	lua_register_libfairygui_GRichTextField(tolua_S);
	lua_register_libfairygui_UIConfig(tolua_S);
	lua_register_libfairygui_GRoot(tolua_S);
	lua_register_libfairygui_ActionMovieClip(tolua_S);
	lua_register_libfairygui_GLabel(tolua_S);
	lua_register_libfairygui_GTween(tolua_S);
	lua_register_libfairygui_UIPackage(tolua_S);
	lua_register_libfairygui_GGraph(tolua_S);
	lua_register_libfairygui_GProgressBar(tolua_S);
	lua_register_libfairygui_UIObjectFactory(tolua_S);
	lua_register_libfairygui_PopupMenu(tolua_S);
	lua_register_libfairygui_GBasicTextField(tolua_S);
	lua_register_libfairygui_GSlider(tolua_S);
	lua_register_libfairygui_GTextInput(tolua_S);
	lua_register_libfairygui_Window(tolua_S);
	lua_register_libfairygui_GLoader(tolua_S);
	lua_register_libfairygui_GObjectPool(tolua_S);
	lua_register_libfairygui_DragDropManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

