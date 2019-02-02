#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
Mat img = imread("./rubik.jpg",0);
int main()
{
	int i,j;
	Mat blr(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(i-1>0 && i+1<img.rows && j-1>0 && j+1<img.cols )
			{
				blr.at<uchar>(i,j) = img.at<uchar>(i,j)*0.25 + ((img.at<uchar>(i+1,j+1)+img.at<uchar>(i-1,j-1)+img.at<uchar>(i+1,j-1)+img.at<uchar>(i-1,j+1))/16) + (img.at<uchar>(i,j+1)+img.at<uchar>(i,j-1)+img.at<uchar>(i+1,j)+img.at<uchar>(i-1,j))*0.125;
			}
			else
			{
				blr.at<uchar>(i,j) = img.at<uchar>(i,j)*0.25;
				if(i-1>0)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i-1,j)*0.125; 
				}
				if(i+1<img.rows)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i+1,j)*0.125;
				}
				if(j-1>0)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i,j-1)*0.125;
				}
				if(j+1<img.cols)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i,j+1)*0.125;
				}
				if(i+1<img.rows && j-1>0)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i+1,j-1)/16;
				}
				if(i-1>0 && j-1>0)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i-1,j+1)/16;
				}
				if(i-1>0 && j+1<img.cols)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i-1,j+1)/16;
				}
				if(i+1<img.rows && j+1<img.cols)
				{
					blr.at<uchar>(i,j)=+ img.at<uchar>(i+1,j+1)/16;
				}
			}
		}
	}
	namedWindow("blur",WINDOW_NORMAL);
	imshow("blur",blr);
	waitKey(0);
	return 0;

}