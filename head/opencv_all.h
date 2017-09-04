#ifndef   OPENCV_ALL
#define   OPENCV_ALL

#include "opencv2/opencv.hpp"
#include "opencv2/core/internal.hpp"
#include "opencv2/legacy/legacy.hpp"
#include "opencv2/legacy/compat.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv/highgui.h"
#include <ctime>
#include <time.h>
#include <math.h>
#include <iostream>
#include <ostream>
#if _DEBUG 
#pragma comment(lib, "..\\lib\\opencv_calib3d249d.lib")
#pragma comment(lib, "..\\lib\\opencv_core249d.lib")
#pragma comment(lib, "..\\lib\\opencv_contrib249d.lib")
#pragma comment(lib, "..\\lib\\opencv_features2d249d.lib")
#pragma comment(lib, "..\\lib\\opencv_flann249d.lib")
#pragma comment(lib, "..\\lib\\opencv_gpu249d.lib")
#pragma comment(lib, "..\\lib\\opencv_highgui249d.lib")
#pragma comment(lib, "..\\lib\\opencv_imgproc249d.lib")
#pragma comment(lib, "..\\lib\\opencv_legacy249d.lib")
#pragma comment(lib, "..\\lib\\opencv_ml249d.lib")
#pragma comment(lib, "..\\lib\\opencv_nonfree249d.lib")
#pragma comment(lib, "..\\lib\\opencv_objdetect249d.lib")
#pragma comment(lib, "..\\lib\\opencv_ocl249d.lib")
#pragma comment(lib, "..\\lib\\opencv_photo249d.lib")
#pragma comment(lib, "..\\lib\\opencv_stitching249d.lib")
#pragma comment(lib, "..\\lib\\opencv_superres249d.lib")
#pragma comment(lib, "..\\lib\\opencv_ts249d.lib")
#pragma comment(lib, "..\\lib\\opencv_video249d.lib")
#pragma comment(lib, "..\\lib\\opencv_videostab249d.lib")

#else
#pragma comment(lib, "..\\lib\\opencv_calib3d249.lib")
#pragma comment(lib, "..\\lib\\opencv_core249.lib")
#pragma comment(lib, "..\\lib\\opencv_contrib249.lib")
#pragma comment(lib, "..\\lib\\opencv_features2d249.lib")
#pragma comment(lib, "..\\lib\\opencv_flann249.lib")
#pragma comment(lib, "..\\lib\\opencv_gpu249.lib")
#pragma comment(lib, "..\\lib\\opencv_highgui249.lib")
#pragma comment(lib, "..\\lib\\opencv_imgproc249.lib")
#pragma comment(lib, "..\\lib\\opencv_legacy249.lib")
#pragma comment(lib, "..\\lib\\opencv_ml249.lib")
#pragma comment(lib, "..\\lib\\opencv_nonfree249.lib")
#pragma comment(lib, "..\\lib\\opencv_objdetect249.lib")
#pragma comment(lib, "..\\lib\\opencv_ocl249.lib")
#pragma comment(lib, "..\\lib\\opencv_photo249.lib")
#pragma comment(lib, "..\\lib\\opencv_stitching249.lib")
#pragma comment(lib, "..\\lib\\opencv_superres249.lib")
#pragma comment(lib, "..\\lib\\opencv_ts249.lib")
#pragma comment(lib, "..\\lib\\opencv_video249.lib")
#pragma comment(lib, "..\\lib\\opencv_videostab249.lib")

#endif
using namespace cv;
using namespace std;


#endif