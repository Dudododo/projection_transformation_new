#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("1.jpg", 1);
	cv::Mat dstMat;

	//变换前的四点坐标
	cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(250,100)
	};

	//变换后的四点坐标
	cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180)
	};

	//计算仿射矩阵
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);

	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
	waitKey(0);
}
