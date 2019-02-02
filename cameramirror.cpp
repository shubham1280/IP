#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;
  
int main(){
    int i,j;
    VideoCapture cap(0);
    Mat Frame;
    namedWindow("Camera", WINDOW_NORMAL);
    while(1){
	cap>>Frame;
        //Mat output(Frame.rows,Frame.cols,CV_8UC3,Scalar(0,0,0));
        //Canny(Frame,output,50,100,3,1);
    Mat imr(Frame.rows,2*Frame.cols,CV_8UC3,Scalar(0,0,0));
    for(i=0;i<Frame.rows;i++)
    {
        for(j=0;j<2*Frame.cols;j++)
        {
            if(j<Frame.cols)
            {imr.at<Vec3b>(i,j) = Frame.at<Vec3b>(i,j);}
            else
            {
                imr.at<Vec3b>(i,j) = Frame.at<Vec3b>(i,1023-j);
            }
            
        }
    }
    imshow("classy",imr);
    waitKey(5);
    }
    return 0;
}

   /* Mat Frame = imread("rubik.jpg",0);
    Mat Frame2(Frame.rows,Frame.cols, CV_8UC1, Scalar(0));
    Canny(Frame,Frame2,50,100,3,0);
    namedWindow("UseCanny", WINDOW_NORMAL);
    imshow("UseCanny", Frame2);
    waitKey(0);
    return 0;*/