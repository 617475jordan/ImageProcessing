#include <opencv_all.h>
#include "drawing.h"
Mat m_srcImg;
Mat m_grayImg;
int thresh = 30;
int max_thresh = 255;
float PI = acos(-1);
int main()
{
	VideoCapture capture;
	capture.open("..\\data\\car.mpg");
	if (!capture.isOpened())
	{
		return -1;
	}
	while (1)
	{
		//m_srcImg = imread("..\\data\\0817.jpg");
		capture >> m_srcImg;
		if (m_srcImg.empty())
		{
			return -1;
		}
		resize(m_srcImg, m_srcImg, Size(320, 240));
		cvtColor(m_srcImg, m_grayImg, CV_BGR2GRAY);//ª“∂»ªØ      
		GaussianBlur(m_srcImg, m_srcImg, Size(3, 3), 0.1, 0, BORDER_DEFAULT);
		blur(m_grayImg, m_grayImg, Size(3, 3)); //¬À≤®       
		namedWindow("image", CV_WINDOW_AUTOSIZE);
		imshow("image", m_srcImg);
		//moveWindow("image", 20, 20);
		//∂®“ÂCanny±ﬂ‘µºÏ≤‚ÕºœÒ       
		Mat m_cannyImg;
		//¿˚”√cannyÀ„∑®ºÏ≤‚±ﬂ‘µ       
		Canny(m_grayImg, m_cannyImg, thresh, thresh * 3, 3);
	   

		drawing drawing;
		Mat m_MatImg;
		m_MatImg=drawing.drawingContourMomentAndPointCentroid(m_cannyImg);
		namedWindow("Contours", CV_WINDOW_AUTOSIZE);
		imshow("Contours", m_MatImg);
		//moveWindow("Contours", 1100, 20);
		waitKey(1);
		if (waitKey(10))
		{
			waitKey();
		}
	}
	waitKey(0);
	m_srcImg.release();
	m_grayImg.release();
	return 0;
}