#pragma  once
#include <opencv_all.h>
#if _DEBUG
#pragma comment(lib, "..\\lib\\FaceAlignmentd.lib")
#pragma comment(lib, "..\\lib\\FaceDetectiond.lib")
#pragma comment(lib, "..\\lib\\Identificationd.lib")

#else
#pragma comment(lib, "..\\lib\\FaceAlignment.lib")
#pragma comment(lib, "..\\lib\\FaceDetection.lib")
#pragma comment(lib, "..\\lib\\Identification.lib")



#endif