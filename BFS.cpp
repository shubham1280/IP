#include<stdio.h>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
using namespace cv;
Mat img = imread("./dfs_path.jpg",0);
Mat che(img.rows,img.cols,CV_8UC1,Scalar(0));
int blob=0;
typedef struct point{
	int i;
	int j;
}point;
point first;
queue <point> myqu;
void check(int r,int c)
{
	if(r+1<img.rows)
	{
		if(img.at<uchar>(r+1,c)==0 && che.at<uchar>(r+1,c)==0)
		{
			first.i = r+1;
			first.j = c;
			che.at<uchar>(r+1,c) = 255;
			myqu.push(first);
		}
	}
	if(r-1>0)
	{
		if(img.at<uchar>(r-1,c)==0 && che.at<uchar>(r-1,c)==0)
		{	
			first.i = r-1;
			first.j = c;
			che.at<uchar>(r-1,c) = 255;
			myqu.push(first);
		}
	}
	if(c+1<img.cols)
	{
		if(img.at<uchar>(r,c+1)==0 && che.at<uchar>(r,c+1)==0)
		{
			first.i = r;
			first.j = c+1;
			che.at<uchar>(r,c+1) = 255;
			myqu.push(first);
		}
	}
	if(c-1>0)
	{
		if(img.at<uchar>(r,c-1)==0 && che.at<uchar>(r,c-1)==0)
		{	
			first.i = r;
			first.j = c-1;
			che.at<uchar>(r,c-1) = 255;
			myqu.push(first);
		}
	}
	if(r+1<img.rows && c+1<img.cols)
	{
		if(img.at<uchar>(r+1,c+1)==0 && che.at<uchar>(r+1,c+1)==0)
		{
			first.i = r+1;
			first.j = c+1;
			che.at<uchar>(r+1,c+1) = 255;
			myqu.push(first);
		}
	}
	if(r+1<img.rows && c-1>0)
	{
		if(img.at<uchar>(r+1,c-1)==0 && che.at<uchar>(r+1,c-1)==0)
		{
			first.i = r+1;
			first.j = c-1;
			che.at<uchar>(r+1,c-1) = 255;
			myqu.push(first);
		}
	}
	if(r-1>0 && c+1<img.cols)
	{
		if(img.at<uchar>(r-1,c+1)==0 && che.at<uchar>(r-1,c+1)==0)
		{
			first.i = r-1;
			first.j = c+1;
			che.at<uchar>(r-1,c+1) = 255;
			myqu.push(first);
		}
	}
	if(r-1>0 && c-1>0)
	{
		if(img.at<uchar>(r-1,c-1)==0 && che.at<uchar>(r-1,c-1)==0)
		{
			first.i = r-1;
			first.j = c-1;
			che.at<uchar>(r-1,c-1) = 255;
			myqu.push(first);
		}
	}
	myqu.pop();
	if(myqu.empty() == 1)
	{
		blob+=1;
	}
	else
	{
		check(myqu.front().i,myqu.front().j);
	}
}
int main()
{
	int k,l;
	for(k=0;k<img.rows;k++)
	{	
		for(l=0;l<img.cols;l++)
		{
			if(img.at<uchar>(k,l)==0 && che.at<uchar>(k,l) == 0)
			{
				che.at<uchar>(k,l) = 255;
				first.i = k;
				first.j = l;
				myqu.push(first);
				check(k,l);
			}
			else{continue;}
		}

	}
	cout<<"Number of blobs = "<<blob<<endl;
	namedWindow("bfs",WINDOW_NORMAL);
	imshow("bfs",che);
	waitKey(0);
	return 0;
}