#include <jni.h>

#include <stdlib.h>
#include <android/asset_manager.h>
#include <assert.h>
#include <android/asset_manager_jni.h>
#include <sys/types.h>
#include "ImgRecon.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ANDROID__
#include <android/log.h>
#define TAG "HURecognition"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , TAG,__VA_ARGS__)
#else
#define LOGV(...) printf(__VA_ARGS__)
#define LOGD(...) printf(__VA_ARGS__)
#define LOGI(...) printf(__VA_ARGS__)
#define LOGW(...) printf(__VA_ARGS__)
#define LOGE(...) printf(__VA_ARGS__)
#endif // __ANDROID__


JNIEXPORT jint JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_CreateIntance
		(JNIEnv *env, jobject obj,jobject assetManager){
	AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
	return (jint)(new ImgRecon(mgr));
}

JNIEXPORT jint JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_DestroyIntance
		(JNIEnv *env, jobject obj, jint instance){
	if (instance) {
		ImgRecon* tmp = (ImgRecon*)instance;
		delete tmp;
		return 0;
	}
	return -1;
}



JNIEXPORT void JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_ShowPreview
		(JNIEnv *env, jobject obj, jint instance, jlong addrGray, jlong addrRgba){

	Mat& mGr  = *(Mat*)addrGray;
	Mat& mRgb = *(Mat*)addrRgba;

	ImgRecon* irf = (ImgRecon*)instance;
	//LOGE("ShowPreview 1\n");
	LOGE("ShowPreview");
	irf->ShowPreview(mRgb,0);
	LOGE("end ShowPreview");


}


#ifdef __cplusplus
}
#endif
