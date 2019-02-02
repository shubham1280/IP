#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cmath>
using namespace std;
using namespace cv;
Mat img = imread("./rubik1.jpg",0);
Mat blr(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat edh(img.rows,img.cols,CV_8UC1,Scalar(0));
int gx(int row,int col)
	{
		int p,j=0,i=0,q;
		for(p=row-1;p<row+1;p++)
		{
			for(q=col-1;q<col+1;q++)
			{
				i += 1;
				if(p>0 && q>0 && p<blr.rows && q<blr.cols)
				{
					if(i==1||i==7)
					{
						j += blr.at<uchar>(p,q)*(-1);
					}
					if(i==2||i==5||i==8)
					{
						j +=blr.at<uchar>(p,q)*0;
					}
					if(i==4)
					{
						j +=blr.at<uchar>(p,q)*(-2);
					}
					if(i==3||i==9)
					{
						j+= blr.at<uchar>(p,q)*(1);
					}
					if(i==6)
					{
						j+= blr.at<uchar>(p,q)*(2);
					}
				}
			}
		}
		j = j*j;
		return j;
	}
int gy(int row,int col)
	{
		int p,j=0,i=0,q;
		for(p=row-1;p<row+1;p++)
		{
			for(q=col-1;q<col+1;q++)
			{
				i += 1;
				if(p>0 && q>0 && p<blr.rows && q<blr.cols)
				{
					if(i==1||i==3)
					{
						j += blr.at<uchar>(p,q)*(-1);
					}
					if(i==4||i==5||i==6)
					{
						j +=blr.at<uchar>(p,q)*0;
					}
					if(i==2)
					{
						j +=blr.at<uchar>(p,q)*(-2);
					}
					if(i==7||i==9)
					{
						j+= blr.at<uchar>(p,q)*(1);
					}
					if(i==8)
					{
						j+= blr.at<uchar>(p,q)*(2);
					}
				}
			}
		}
		j = j*j;
		return j;
	}
void updatefunc(int t,void*)
{
	int i,j,thr=0;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			thr = sqrt(gx(i,j) + gy(i,j));
			if(thr>t)
			{
				edh.at<uchar>(i,j) = 0;
			}
			else{edh.at<uchar>(i,j) = 255;}
		}
	}
	imshow("blur",edh);
	//imwrite("imag.png",edh);
}
int main()
{
	int i,j,th;
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
	createTrackbar("thresh","blur",&th,255,updatefunc);
	waitKey(0);
	return 0;
}	