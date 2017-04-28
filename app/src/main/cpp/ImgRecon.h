#ifndef ImgRecon_h__
#define ImgRecon_h__
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/highgui.h>
#include <android/asset_manager.h>
#include <assert.h>
#include <android/asset_manager_jni.h>
#include <sys/types.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

class ImgRecon
{
public:
	ImgRecon(AAssetManager* mgr);
	~ImgRecon();

    void detectAndDisplay( Mat frame );
	int ShowPreview(Mat mbgra, int Algo);

private:
 CascadeClassifier face_cascade;
 CascadeClassifier eyes_cascade;


};


#endif // ImgRecon_h__
