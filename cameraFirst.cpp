#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;
  
int main(){
    VideoCapture cap(0);
    Mat Frame;
    namedWindow("Camera", WINDOW_NORMAL);
    while(1){
	cap>>Frame;
        Mat output(Frame.rows,Frame.cols,CV_8UC3,Scalar(0,0,0));
        Canny(Frame,output,50,100,3,1);
        imshow("Camera", output);
        waitKey(100);
    }
    return 0;
}

   /* Mat img = imread("rubik.jpg",0);
    Mat img2(img.rows,img.cols, CV_8UC1, Scalar(0));
    Canny(img,img2,50,100,3,0);
    namedWindow("UseCanny", WINDOW_NORMAL);
    imshow("UseCanny", img2);
    waitKey(0);
    return 0;*/
