LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := ccets

LOCAL_MODULE_FILENAME := libets

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := \
assets-manager/Manifest.cpp \
assets-manager/AssetsManagerEx.cpp \
assets-manager/CCEventAssetsManagerEx.cpp \
assets-manager/CCEventListenerAssetsManagerEx.cpp

LOCAL_STATIC_LIBRARIES := cocos2dx_internal_static
LOCAL_STATIC_LIBRARIES += cocos_network_static
# LOCAL_STATIC_LIBRARIES += ext_box2d
# LOCAL_STATIC_LIBRARIES += ext_bullet

LOCAL_CXXFLAGS += -fexceptions

LOCAL_C_INCLUDES := $(LOCAL_PATH)

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/. \
                           $(LOCAL_PATH)/..
#                            $(LOCAL_PATH)/GUI/CCControlExtension \
#                            $(LOCAL_PATH)/GUI/CCScrollView

include $(BUILD_STATIC_LIBRARY)
