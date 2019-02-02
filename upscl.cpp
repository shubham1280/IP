#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("./lenna.jpg",1);
	Mat upscl(2*img.rows,2*img.cols,CV_8UC3,Scalar(0,0,0));
	int i,j,k;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			upscl.at<Vec3b>(2*i,2*j)[0] = img.at<Vec3b>(i,j)[0];  
			upscl.at<Vec3b>(2*i+1,2*j+1)[0] = img.at<Vec3b>(i,j)[0]; 
			upscl.at<Vec3b>(2*i,2*j+1)[0] = img.at<Vec3b>(i,j)[0]; 
			upscl.at<Vec3b>(2*i+1,2*j)[0] = img.at<Vec3b>(i,j)[0]; 
			upscl.at<Vec3b>(2*i,2*j)[1] = img.at<Vec3b>(i,j)[1];  
			upscl.at<Vec3b>(2*i+1,2*j+1)[1] = img.at<Vec3b>(i,j)[1]; 
			upscl.at<Vec3b>(2*i,2*j+1)[1] = img.at<Vec3b>(i,j)[1]; 
			upscl.at<Vec3b>(2*i+1,2*j)[1] = img.at<Vec3b>(i,j)[1]; 
			upscl.at<Vec3b>(2*i,2*j)[2] = img.at<Vec3b>(i,j)[2];  
			upscl.at<Vec3b>(2*i+1,2*j+1)[2] = img.at<Vec3b>(i,j)[2]; 
			upscl.at<Vec3b>(2*i,2*j+1)[2] = img.at<Vec3b>(i,j)[2]; 
			upscl.at<Vec3b>(2*i+1,2*j)[2] = img.at<Vec3b>(i,j)[2]; 

		}
	}
	namedWindow("enlarge",WINDOW_AUTOSIZE);
	imshow("enlarge",upscl);
	waitKey(0);
	return 0;
}