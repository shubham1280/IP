#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
	int i,j,k=0,A[256]={0};
	Mat img = imread("./len.jpg",1);
	Mat hist(img.rows*img.cols,256,CV_8UC1,Scalar(255));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			k = img.at<uchar>(i,j);
			A[k] = A[k] + 1;
			hist.at<uchar>((img.rows*img.cols-A[k]),k) = 0;
		}
	} 
	namedWindow("Histogram",WINDOW_NORMAL);
	imshow("Histogram",hist);
	waitKey(0);
	return 0;

}