LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/../../../../../OpenCV-android-sdk/sdk/native/jni/OpenCV.mk

LOCAL_MODULE := ImageRecognitionFramework
LOCAL_SRC_FILES += ImageRecognitionFramework_jni.cpp
LOCAL_SRC_FILES +=ImgRecon.cpp


LOCAL_LDLIBS +=  -llog -ldl
LOCAL_LDLIBS    += -landroid

include $(BUILD_SHARED_LIBRARY)