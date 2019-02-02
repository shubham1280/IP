#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cmath>
using namespace std;
using namespace cv;
Mat img = imread("./imag.png",0);
Mat dil(img.rows,img.cols,CV_8UC1,Scalar(0));
int check(int row,int col)
	{
		int p,q,j=0;
		for(p=row-1;p<row+1;p++)
		{
			for(q=col-1;q<col+1;q++)
			{
				if(p>0 && q>0 && p<img.rows && q<img.cols)
				{
					if(img.at<uchar>(p,q) == 255)
					{
						j=1;
					}
				}
			}
		}
		return j;
	}
int main()
{
	int i,j,k;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			k = check(i,j);
			if(k==1)
			{
				dil.at<uchar>(i,j) = 255;
			}
		}
	}
	namedWindow("dil",WINDOW_NORMAL);
	imshow("dil",dil);
	//imwrite("dil.png",dil);
	waitKey(0);
	return 0;
}