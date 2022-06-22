LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2d_lua_android_static

LOCAL_MODULE_FILENAME := libluacocos2dandroid

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := ../manual/platform/android/CCLuaJavaBridge.cpp \
                   ../manual/platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../.. \
                    $(LOCAL_PATH)/../manual \
                    $(LOCAL_PATH)/../../../../external/lua/tolua \
                    $(LOCAL_PATH)/../manual/platform/android \
                    $(LOCAL_PATH)/../manual/platform/android/jni

LOCAL_EXPORT_LDLIBS := -lGLESv2 \
                       -llog \
                       -landroid

# luajit
#LUA_STATIC_LIB := luajit_static
#LUA_IMPORT_PATH := lua/luajit/prebuilt/android
#LUA_INCLUDE_PATH := $(LOCAL_PATH)/../../../../external/lua/luajit/include
#
#LOCAL_STATIC_LIBRARIES := $(LUA_STATIC_LIB)
# luajit end

# lua 5.1.x
LUA_STATIC_LIB := lua_static
LUA_IMPORT_PATH := lua/lua/
LUA_INCLUDE_PATH := $(LOCAL_PATH)/../../../../external/lua/lua/

LOCAL_STATIC_LIBRARIES := $(LUA_STATIC_LIB)
# lua 5.1.x

include $(BUILD_STATIC_LIBRARY)

#==============================================================

include $(CLEAR_VARS)

LOCAL_MODULE    := cocos2d_lua_static

LOCAL_MODULE_FILENAME := libluacocos2d

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := ../manual/CCLuaBridge.cpp \
          ../manual/CCLuaEngine.cpp \
          ../manual/CCLuaStack.cpp \
          ../manual/CCLuaValue.cpp \
          ../manual/Cocos2dxLuaLoader.cpp \
          ../manual/LuaBasicConversions.cpp \
          ../manual/lua_module_register.cpp \
          ../auto/lua_cocos2dx_auto.cpp \
          ../manual/cocos2d/lua_cocos2dx_deprecated.cpp \
          ../manual/cocos2d/lua_cocos2dx_manual.cpp \
          ../manual/cocos2d/LuaOpengl.cpp \
          ../manual/cocos2d/LuaScriptHandlerMgr.cpp \
          ../manual/tolua_fix.cpp \
          ../../../../external/lua/tolua/tolua_event.c \
          ../../../../external/lua/tolua/tolua_is.c \
          ../../../../external/lua/tolua/tolua_map.c \
          ../../../../external/lua/tolua/tolua_push.c \
          ../../../../external/lua/tolua/tolua_to.c \
          ../../../../external/xxtea/xxtea.cpp \
          ../auto/lua_cocos2dx_audioengine_auto.cpp \
          ../manual/audioengine/lua_cocos2dx_audioengine_manual.cpp

# cjson
LOCAL_CJSON_SRC_FILES := ../../../../external/lua/cjson/fpconv.c \
                         ../../../../external/lua/cjson/lua_cjson.c \
                         ../../../../external/lua/cjson/strbuf.c

# lpack
LOCAL_SRC_FILES += ../../../../external/lua/lpack/lpack.c

# lfs
LOCAL_SRC_FILES += ../../../../external/lua/lfs/lfs.c

# lsocket
LOCAL_SRC_FILES += ../../../../external/lua/lsocket/lsocket.c
# LOCAL_SRC_FILES += ../../../../external/lua/lsocket/async_resolver.c \
#                   ../../../../external/lua/lsocket/gai_async.c

# sproto
LOCAL_SRC_FILES += ../../../../external/lua/sproto/sproto.c \
                   ../../../../external/lua/sproto/lsproto.c


LOCAL_SRC_FILES += ../../../../external/lua/crypto/CCCrypto.cpp

LOCAL_SRC_FILES += ../../../../external/lua/lpeg/lpcap.c \
                    ../../../../external/lua/lpeg/lpcode.c \
                    ../../../../external/lua/lpeg/lpprint.c \
                    ../../../../external/lua/lpeg/lptree.c \
                    ../../../../external/lua/lpeg/lpvm.c

LOCAL_SRC_FILES += ../../../../external/lua/pbc/src/alloc.c \
                   ../../../../external/lua/pbc/src/array.c \
                   ../../../../external/lua/pbc/src/bootstrap.c \
                   ../../../../external/lua/pbc/src/context.c \
                   ../../../../external/lua/pbc/src/decode.c \
                   ../../../../external/lua/pbc/src/map.c \
                   ../../../../external/lua/pbc/src/pattern.c \
                   ../../../../external/lua/pbc/src/proto.c \
                   ../../../../external/lua/pbc/src/register.c \
                   ../../../../external/lua/pbc/src/rmessage.c \
                   ../../../../external/lua/pbc/src/stringpool.c \
                   ../../../../external/lua/pbc/src/varint.c \
                   ../../../../external/lua/pbc/src/wmessage.c \
                   ../../../../external/lua/pbc/src/pbc-lua.c

LOCAL_SRC_FILES += ../../../../external/lua/LuaBitOp/bit.c

LOCAL_SRC_FILES += ../../../../external/lua/lua_extensions.c

LOCAL_SRC_FILES += $(LOCAL_CJSON_SRC_FILES)

#Component
# LOCAL_SRC_FILES += ../manual/CCComponentLua.cpp

#3d
# LOCAL_SRC_FILES += ../manual/3d/lua_cocos2dx_3d_manual.cpp \
#                    ../auto/lua_cocos2dx_3d_auto.cpp

#cocosdenshion
LOCAL_SRC_FILES += ../manual/cocosdenshion/lua_cocos2dx_cocosdenshion_manual.cpp \
                   ../auto/lua_cocos2dx_cocosdenshion_auto.cpp

#network
LOCAL_SRC_FILES += ../manual/network/lua_cocos2dx_network_manual.cpp \
                   ../manual/network/Lua_web_socket.cpp \
                   ../manual/network/lua_xml_http_request.cpp \
                   ../../../../external/lua/luasocket/auxiliar.c \
                   ../../../../external/lua/luasocket/buffer.c \
                   ../../../../external/lua/luasocket/except.c \
                   ../../../../external/lua/luasocket/inet.c \
                   ../../../../external/lua/luasocket/io.c \
                   ../../../../external/lua/luasocket/luasocket.c \
                   ../../../../external/lua/luasocket/luasocket_scripts.c \
                   ../../../../external/lua/luasocket/mime.c \
                   ../../../../external/lua/luasocket/options.c \
                   ../../../../external/lua/luasocket/select.c \
                   ../../../../external/lua/luasocket/serial.c \
                   ../../../../external/lua/luasocket/tcp.c \
                   ../../../../external/lua/luasocket/timeout.c \
                   ../../../../external/lua/luasocket/udp.c \
                   ../../../../external/lua/luasocket/unix.c \
                   ../../../../external/lua/luasocket/usocket.c

# #cocosbuilder
# LOCAL_SRC_FILES += ../manual/cocosbuilder/lua_cocos2dx_cocosbuilder_manual.cpp \
#                    ../manual/cocosbuilder/CCBProxy.cpp \
#                    ../auto/lua_cocos2dx_cocosbuilder_auto.cpp

#cocostudio
LOCAL_SRC_FILES += ../manual/cocostudio/lua_cocos2dx_coco_studio_manual.cpp \
                   ../manual/cocostudio/CustomGUIReader.cpp \
                   ../manual/cocostudio/lua_cocos2dx_csloader_manual.cpp \
                   ../auto/lua_cocos2dx_csloader_auto.cpp \
                   ../auto/lua_cocos2dx_studio_auto.cpp \
                   ../manual/cocostudio/lua-cocos-studio-conversions.cpp

#spine
LOCAL_SRC_FILES += ../manual/spine/lua_cocos2dx_spine_manual.cpp \
                   ../manual/spine/LuaSkeletonAnimation.cpp \
                   ../auto/lua_cocos2dx_spine_auto.cpp

#ui
LOCAL_SRC_FILES +=  ../manual/ui/lua_cocos2dx_ui_manual.cpp \
                    ../auto/lua_cocos2dx_ui_auto.cpp \
                    ../manual/ui/lua_cocos2dx_experimental_webview_manual.cpp \
                    ../manual/ui/lua_cocos2dx_experimental_video_manual.cpp \
                    ../auto/lua_cocos2dx_experimental_video_auto.cpp \
                    ../auto/lua_cocos2dx_experimental_webview_auto.cpp

#extension
LOCAL_SRC_FILES += ../manual/extension/lua_cocos2dx_extension_manual.cpp \
                   ../auto/lua_cocos2dx_extension_auto.cpp

# #physics3d
# LOCAL_SRC_FILES += ../manual/physics3d/lua_cocos2dx_physics3d_manual.cpp \
#                    ../auto/lua_cocos2dx_physics3d_auto.cpp \

# #navmesh
# LOCAL_SRC_FILES += ../manual/navmesh/lua_cocos2dx_navmesh_conversions.cpp \
#                    ../manual/navmesh/lua_cocos2dx_navmesh_manual.cpp \
#                    ../auto/lua_cocos2dx_navmesh_auto.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../external/lua/tolua \
                    $(LUA_INCLUDE_PATH) \
                    $(LOCAL_PATH)/../../../2d \
                    $(LOCAL_PATH)/../../../base \
                    $(LOCAL_PATH)/../../../3d \
                    $(LOCAL_PATH)/../../../network \
                    $(LOCAL_PATH)/../../../editor-support/cocosbuilder \
                    $(LOCAL_PATH)/../../../editor-support/cocostudio \
                    $(LOCAL_PATH)/../../../editor-support/cocostudio/ActionTimeline \
                    $(LOCAL_PATH)/../../../editor-support/spine \
                    $(LOCAL_PATH)/../../../ui \
                    $(LOCAL_PATH)/../../../physics3d \
                    $(LOCAL_PATH)/../../../navmesh \
                    $(LOCAL_PATH)/../../../../extensions \
                    $(LOCAL_PATH)/../auto \
                    $(LOCAL_PATH)/../manual \
                    $(LOCAL_PATH)/../manual/cocos2d \
                    $(LOCAL_PATH)/../manual/3d \
                    $(LOCAL_PATH)/../manual/cocosdenshion \
                    $(LOCAL_PATH)/../manual/audioengine \
                    $(LOCAL_PATH)/../manual/network \
                    $(LOCAL_PATH)/../manual/extension \
                    $(LOCAL_PATH)/../manual/cocostudio \
                    $(LOCAL_PATH)/../manual/cocosbuilder \
                    $(LOCAL_PATH)/../manual/spine \
                    $(LOCAL_PATH)/../manual/ui \
                    $(LOCAL_PATH)/../manual/navmesh \
                    $(LOCAL_PATH)/../../../../external/xxtea \
                    $(LOCAL_PATH)/../../../.. \
                    $(LOCAL_PATH)/../../../../external/lua

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../../external/lua/tolua \
						               $(LUA_INCLUDE_PATH) \
                           $(LOCAL_PATH)/../auto \
                           $(LOCAL_PATH)/../manual \
                           $(LOCAL_PATH)/../manual/cocos2d \
                           $(LOCAL_PATH)/../manual/3d \
                           $(LOCAL_PATH)/../manual/cocosdenshion \
                           $(LOCAL_PATH)/../manual/audioengine \
                           $(LOCAL_PATH)/../manual/network \
                           $(LOCAL_PATH)/../manual/cocosbuilder \
                           $(LOCAL_PATH)/../manual/cocostudio \
                           $(LOCAL_PATH)/../manual/spine \
                           $(LOCAL_PATH)/../manual/extension \
                           $(LOCAL_PATH)/../manual/ui \
                           $(LOCAL_PATH)/../manual/navmesh \
                           $(LOCAL_PATH)/../../../..

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2d_lua_android_static

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_STATIC_LIBRARY)

$(call import-add-path,$(LOCAL_PATH)/../../../..)
$(call import-add-path,$(LOCAL_PATH)/../../../../external)
$(call import-module,$(LUA_IMPORT_PATH))
$(call import-module,cocos)
