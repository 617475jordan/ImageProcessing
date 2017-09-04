#include <opencv_all.h>
#include "drawing.h"
Mat m_matImg;
Mat m_matGrayImg;
Mat m_matForegroundImg;
Mat m_matBackgroundImg;
int m_iThresholdValue = 30;
int m_iMaxThresholdValue = 255;
float PI = acos(-1.0);
int main()
{
	//drawing drawing;
	//m_srcImg = imread("..\\data\\2.jpg");    //注意路径得换成自己的 
	//resize(m_srcImg, m_srcImg, Size(320, 240));
	//cvtColor(m_srcImg, foreground, CV_RGB2GRAY);
	//while (1)
	//{
	//	threshold(foreground, foreground, 150, 255, THRESH_BINARY);
	//	foreground.setTo(0);
	//	m_grayImg=drawing.drawingContourMomentAndPointCentroid(foreground, m_srcImg);
	//	imshow("m_grayImg", m_grayImg);
	//	waitKey(1);
	//}
	
	VideoCapture capture;
	BackgroundSubtractorMOG2 mog;
	/*capture.open("..\\data\\indoor.mp4");
	
	if (!capture.isOpened())
	{
		return -1;
	}*/
	int m_icount = 0;
	while (1)
	{
		int t = clock();
		m_icount++;
		m_matImg = imread("..\\data\\1\\key.jpg");
		//capture >> m_matImg;
		if (m_matImg.empty())
		{
			return -1;
		}
		resize(m_matImg, m_matImg, Size(320, 240));
		cvtColor(m_matImg, m_matImg, CV_RGB2GRAY);
		cvtColor(m_matImg, m_matImg, CV_GRAY2RGB);

		mog(m_matImg, m_matForegroundImg, 0.001);
		// 腐蚀  
		erode(m_matForegroundImg, m_matForegroundImg, cv::Mat());
		// 膨胀  
		dilate(m_matForegroundImg, m_matForegroundImg, cv::Mat());
		mog.getBackgroundImage(m_matBackgroundImg);   // 返回当前背景图像  
		//imshow("video", foreground);
		//imshow("background", background);
		if (m_icount >= 0)
		{
			drawing drawing;
			Mat m_MatImg, m_MatThresholdImg;
			static const int nY20_thresh = 50;
	
			threshold(m_matForegroundImg, m_matForegroundImg, nY20_thresh, 255, THRESH_BINARY);
			m_MatImg = drawing.drawingContourMomentAndPointCentroid(m_matForegroundImg, m_matImg);
			namedWindow("Contours", CV_WINDOW_AUTOSIZE);
			imshow("Contours", m_MatImg);
			//moveWindow("Contours", 1100, 20);
			waitKey(1);
		}
		else
		{
			namedWindow("Contours", CV_WINDOW_AUTOSIZE);
			imshow("Contours", m_matImg);
			waitKey(1);
		}
		if (waitKey(10)=='c')
		{
			waitKey();
		}
		cout << "time:" << clock() - t << endl;
	}
	waitKey(0);
	m_matImg.release();
	m_matGrayImg.release();
	return 0;
}