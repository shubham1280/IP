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
	namedWindow("lenna", WINDOW_NORMAL);
	Mat img = imread("./lenna.jpg",1);
	Mat imr(img.rows,2*img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<2*img.cols;j++)
		{
			if(j<img.cols)
			{imr.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);}
			else
			{
				imr.at<Vec3b>(i,j) = img.at<Vec3b>(i,1023-j);
			}
			
		}
	}
	namedWindow("classy",WINDOW_NORMAL);
	imshow("classy",imr);
	waitKey(5000);
	return 0;
}