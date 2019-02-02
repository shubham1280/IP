#include<iostream>
#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
Mat img = imread("./lenna.jpg",1);
int rup,rlow,gup,glow,bup,blow;
void updatefunc(int t,void*)
{
	int i,j;
	Mat rgb(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			//rgb.at<Vec3b>(i,j) = img.at<Vec3b>(i,j);
			if(img.at<Vec3b>(i,j)[2]<rup && img.at<Vec3b>(i,j)[2]>rlow)
				{rgb.at<Vec3b>(i,j)[2] = 255;}
			else{rgb.at<Vec3b>(i,j)[2] = 0;}
			if(img.at<Vec3b>(i,j)[1]<gup && img.at<Vec3b>(i,j)[1]>glow)
				{rgb.at<Vec3b>(i,j)[1]=255;}
			else{rgb.at<Vec3b>(i,j)[1]=0;}
			if(img.at<Vec3b>(i,j)[0]<bup && img.at<Vec3b>(i,j)[0]>blow)
				{rgb.at<Vec3b>(i,j)[0]=255;}
			else{rgb.at<Vec3b>(i,j)[0]=0;}
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