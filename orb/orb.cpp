#include <opencv_all.h>

void KeyPointsToPoints(vector<KeyPoint> kpts, vector<Point2f> &pts);

bool refineMatchesWithHomography(
	const std::vector<cv::KeyPoint>& queryKeypoints,
	const std::vector<cv::KeyPoint>& trainKeypoints,
	float reprojectionThreshold, std::vector<cv::DMatch>& matches,
	cv::Mat& homography);

/** @function main */
int main(int argc, char* argv[]) {

	/************************************************************************/
	/* �������⣬������ȡ������ƥ�䣬����ͶӰ�任                            */
	/************************************************************************/

	// ��ȡͼƬ  
	Mat img1, img2;
	int m_iThrshold = 2;
	int m_iWidth = 320 * m_iThrshold;
	int m_iHeight = 240 * m_iThrshold;

	Mat img1Ori ;
	Mat img2Ori = imread("..\\data\\2\\book1.jpg");
	if (img2Ori.empty())
	{
		return -1;
	}
	cvtColor(img2Ori, img2Ori, CV_RGB2GRAY);
	resize(img2Ori, img2, Size(m_iWidth, m_iHeight));


	cv::Ptr<cv::FeatureDetector> detector = new cv::ORB(1000);                        // ����orb�������� 
	cv::Ptr<cv::DescriptorExtractor> extractor = new cv::FREAK(true, true);           // ��Freak���������������� 
	vector<KeyPoint> keypoints2;
	Mat descriptors2;
	detector->detect(img2, keypoints2);
	extractor->compute(img2, keypoints2, descriptors2);
	cv::Ptr<cv::DescriptorMatcher> matcher = new cv::BFMatcher(cv::NORM_HAMMING, true);// ����ƥ�䣬����Hamming����
	VideoCapture capture("..\\data\\1\\book.mp4");
	while (1)
	{
		int t = clock();
		capture >> img1Ori;
		//img1Ori = imread("..\\data\\2\\key1.jpg");
		if (img1Ori.empty() )
		{
			return -1;
		}
		cvtColor(img1Ori, img1Ori, CV_RGB2GRAY);
		resize(img1Ori, img1, Size(m_iWidth, m_iHeight));


		vector<KeyPoint> keypoints1;  // ���ڱ���ͼ�е�������     
		
		Mat descriptors1;               // ���ڱ���ͼ�е����������������  
		

		detector->detect(img1, keypoints1);      // ����һ��ͼ�е�������  
		
		if (keypoints2.empty() | keypoints1.empty())
		{
			continue;
		}
		extractor->compute(img1, keypoints1, descriptors1);      // ����ͼ��������λ�õ���������  



		vector<DMatch> matches;

		matcher->match(descriptors1, descriptors2, matches);

		/*Mat imResultOri;
		drawMatches(img1, keypoints1, img2, keypoints2, matches, imResultOri,
		CV_RGB(0, 255, 0), CV_RGB(0, 255, 0));*/
		//cout << "[Info] # of matches : " << matches.size() << endl;
		
		Mat matHomo;
		refineMatchesWithHomography(keypoints1, keypoints2, 3, matches, matHomo);
		cout << "[Info] Homography T : " << matHomo << endl;
		cout << "[Info] # of matches : " << matches.size() << endl;
		cout << "time:" << clock() - t << "ms" << endl;
		Mat imResult;
		drawMatches(img1, keypoints1, img2, keypoints2, matches, imResult,
			CV_RGB(255,0,0),CV_RGB( 0,255,0));

		//// �������  
		//vector<uchar> vstatus;
		//vector<float> verrs;
		//vector<Point2f> points1;
		//vector<Point2f> points2;
		//KeyPointsToPoints(keypoints1, points1);

		//calcOpticalFlowPyrLK(img1, img2, points1, points2, vstatus, verrs);

		//Mat imOFKL = img1.clone();
		//for (int i = 0; i < vstatus.size(); i++) {
		//	if (vstatus[i] && verrs[i] < 15) {
		//		line(imOFKL, points1[i], points2[i], CV_RGB(255, 255, 255), 1, 8, 0);
		//		circle(imOFKL, points2[i], 3, CV_RGB(255, 255, 255), 1, 8, 0);
		//	}
		//}


		//imwrite("opt.jpg", imOFKL);
		//imwrite("re1.jpg", imResultOri);
		//imwrite("re2.jpg", imResult);

		//imshow("Optical Flow", imOFKL);
		//imshow("origin matches", imResultOri);
		imshow("refined matches", imResult);
		waitKey(1);
	}
	return -1;
}

bool refineMatchesWithHomography(
	const std::vector<cv::KeyPoint>& queryKeypoints,
	const std::vector<cv::KeyPoint>& trainKeypoints,
	float reprojectionThreshold, std::vector<cv::DMatch>& matches,
	cv::Mat& homography) 
{
	const int minNumberMatchesAllowed = 8;

	if (matches.size() < minNumberMatchesAllowed)
		return false;

	// Prepare data for cv::findHomography  
	std::vector<cv::Point2f> srcPoints(matches.size());
	std::vector<cv::Point2f> dstPoints(matches.size());

	for (size_t i = 0; i < matches.size(); i++) {
		srcPoints[i] = trainKeypoints[matches[i].trainIdx].pt;
		dstPoints[i] = queryKeypoints[matches[i].queryIdx].pt;
	}

	// Find homography matrix and get inliers mask  
	std::vector<unsigned char> inliersMask(srcPoints.size());
	homography = cv::findHomography(srcPoints, dstPoints, CV_FM_RANSAC,
		reprojectionThreshold, inliersMask);

	std::vector<cv::DMatch> inliers;
	for (size_t i = 0; i < inliersMask.size(); i++) {
		if (inliersMask[i])
			inliers.push_back(matches[i]);
	}

	matches.swap(inliers);
	return matches.size() > minNumberMatchesAllowed;
}

void KeyPointsToPoints(vector<KeyPoint> kpts, vector<Point2f> &pts)
{
	for (unsigned int i = 0; i < kpts.size(); i++) {
		pts.push_back(kpts[i].pt);
	}

	return;
}