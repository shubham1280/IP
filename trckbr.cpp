#include<iostream>
#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
void updatefunc(int t,void*)
{
	int i,j;
	Mat img = imread("./lenna.jpg",1);
	Mat grey(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			grey.at<uchar>(i,j) = (img.at<Vec3b>(i,j)[0]*0.07 + img.at<Vec3b>(i,j)[1]*0.72 + img.at<Vec3b>(i,j)[2]*0.21);
			if(grey.at<uchar>(i,j)<t)
				{grey.at<uchar>(i,j) = 0;}
			else{grey.at<uchar>(i,j)=255;}
		}
	}
	imshow("class",grey);
}
int main()
{	
	int th;
	namedWindow("class",WINDOW_NORMAL);
	createTrackbar("track","class",&th,255,updatefunc);
	waitKey(0);
	return 0;
}