#include "ImgRecon.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <android/asset_manager.h>
#ifdef __ANDROID__
#include <android/log.h>
#define TAG "ImageRecognitionFramework"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , TAG,__VA_ARGS__)
#else
#define LOGV(...) fprintf(fp,__VA_ARGS__)
#define LOGD(...) fprintf(fp,__VA_ARGS__)
#define LOGI(...) fprintf(fp,__VA_ARGS__)
#define LOGW(...) fprintf(fp,__VA_ARGS__)
#define LOGE(...) fprintf(fp,__VA_ARGS__)
#endif // __ANDROID__


ImgRecon::ImgRecon(AAssetManager* mgr)
{

	AAssetDir* assetDir = AAssetManager_openDir(mgr, "");
	const char* filename = (const char*)NULL;

         //-- 1. Load the cascades
           if( !face_cascade.load( "/sdcard/data/haarcascade_frontalface_alt.xml" ) ){ LOGE("--(!)Error loading\n"); };
           if( !eyes_cascade.load( "/sdcard/data/haarcascade_eye.xml" ) ){ LOGE("--(!)Error loading\n");  };
}
ImgRecon::~ImgRecon()
{

}
void ImgRecon::detectAndDisplay( Mat frame )
{
  std::vector<Rect> faces;
  Mat frame_gray;

  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );

  //-- Detect faces
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

  for( size_t i = 0; i < faces.size(); i++ )
  {
    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    Mat faceROI = frame_gray( faces[i] );
    std::vector<Rect> eyes;

    //-- In each face, detect eyes
    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    for( size_t j = 0; j < eyes.size(); j++ )
     {
       Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
       int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
       circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
     }
  }
  //-- Show what you got

 }
int ImgRecon::ShowPreview(Mat mbgra, int Algo)
{

	LOGE("show Preview");

	detectAndDisplay( mbgra );

return 0;

}
