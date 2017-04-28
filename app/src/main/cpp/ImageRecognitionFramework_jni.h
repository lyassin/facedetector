/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework */

#ifndef _Included_eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework
#define _Included_eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework
 * Method:    CreateIntance
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_CreateIntance
        (JNIEnv *env, jobject obj);

/*
 * Class:     eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework
 * Method:    DestroyIntance
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_DestroyIntance
        (JNIEnv *, jobject, jint);


/*
 * Class:     eu_tsp_ImageRecognitionFramework_ImageRecognitionFramework
 * Method:    ShowPreview
 * Signature: (I[BIII)[B
 */
JNIEXPORT void JNICALL Java_status_face_ensi_tn_facestatus_ImageRecognitionFramework_ShowPreview
        (JNIEnv *env, jobject obj, jint instance, jlong addrGray, jlong addrRgba);



#ifdef __cplusplus
}
#endif
#endif
