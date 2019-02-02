#include<iostream>
#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
Mat img = imread("./frb.jpg",1);
int rup,rlow,gup,glow,bup,blow;
void updatefunc(int t,void*)
{
	int i,j;
	Mat rgb(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<Vec3b>(i,j)[2]<rup && img.at<Vec3b>(i,j)[2]>rlow && img.at<Vec3b>(i,j)[1]<gup && img.at<Vec3b>(i,j)[1]>glow && img.at<Vec3b>(i,j)[0]<bup && img.at<Vec3b>(i,j)[0]>blow)
				{
					rgb.at<uchar>(i,j) = 0;
				}
			else
				{
				
					rgb.at<uchar>(i,j) = 255;
				}
		}
	}
	imshow("class",rgb);
}

int main()
{	
	namedWindow("class",WINDOW_NORMAL);
	createTrackbar("trackrup","class",&rup,255,updatefunc);
	createTrackbar("trackrlow","class",&rlow,255,updatefunc);
	createTrackbar("trackbup","class",&bup,255,updatefunc);
	createTrackbar("trackblow","class",&blow,255,updatefunc);
	createTrackbar("trackgup","class",&gup,255,updatefunc);
	createTrackbar("trackglow","class",&glow,255,updatefunc);
	waitKey(0);
	return 0;
}