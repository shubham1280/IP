#include<iostream>
#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat cool(100,100,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<98;i++)
	{
		for(j=0;j<98-i;j++)
		{
			cool.at<Vec3b>(i,j)[2]=255;
		}
		for(j=98-i+1;j<99;j++)
		{
			cool.at<Vec3b>(i,j)[2]=255;
			cool.at<Vec3b>(i,j)[1]=255;
		}
	}
 	namedWindow("win",CV_WINDOW_NORMAL);
  	imshow("win",cool);
  	waitKey(0);

	return 0;
}