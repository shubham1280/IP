#include<iostream>
#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
void updatefunc1(int r,void*)
{
	int i,j;
	Mat img = imread("./lenna.jpg",1);
	Mat rgb(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			rgb.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);
			if(rgb.at<Vec3b>(i,j)[2]<r)
				{rgb.at<Vec3b>(i,j)[2] = 0;}
			else{rgb.at<Vec3b>(i,j)[2] = 255;}
		}
	}
	imshow("class",rgb);
}
void updatefunc2(int b,void*)
{
	int i,j;
	Mat img = imread("./lenna.jpg",1);
	Mat rgb(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			rgb.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);
			if(rgb.at<Vec3b>(i,j)[0]<b)
				{rgb.at<Vec3b>(i,j)[0] = 0;}
			else{rgb.at<Vec3b>(i,j)[0] = 255;}

		}
	}
	imshow("class",rgb);
}
void updatefunc3(int g,void*)
{
	int i,j;
	Mat img = imread("./lenna.jpg",1);
	Mat rgb(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			rgb.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);
			if(rgb.at<Vec3b>(i,j)[1]<g)
				{rgb.at<Vec3b>(i,j)[1] = 0;}
			else{rgb.at<Vec3b>(i,j)[1] = 255;}

		}
	}
	imshow("class",rgb);
}

int main()
{	
	int r,g,b;
	namedWindow("class",WINDOW_NORMAL);
	createTrackbar("trackr","class",&r,255,updatefunc1);
	createTrackbar("trackb","class",&b,255,updatefunc2);
	createTrackbar("trackg","class",&g,255,updatefunc3);
	waitKey(0);
	return 0;
}