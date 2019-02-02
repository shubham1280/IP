#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;
  
int main(){
    Mat img = imread("./frb.jpg",0);
    Mat img2(img.rows,img.cols, CV_8UC1, Scalar(0));
    Canny(img,img2,50,100,3,1);
    namedWindow("UseCanny", WINDOW_NORMAL);
    imshow("UseCanny", img2);
    imwrite("canny.png",img2);
    waitKey(0);
    return 0;
}
