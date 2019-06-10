#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main()
{
	// 读入一张图片（demo）  
	Mat img = imread("1.jpg");
	// 创建一个名为 "demo"窗口  
	cvNamedWindow("demo");
	// 在窗口中显示demo  
	imshow("demo", img);
	// 等待6000 ms后窗口自动关闭  
	waitKey(6000);
}