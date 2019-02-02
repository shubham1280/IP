#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
Mat img=imread("lenna.jpg",1);
Mat a(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));  
int main()
{
    int avg_r=0,count=0,avg_g=0,avg_b=0;
    for(int i = 0; i < img.rows; i++){
        for(int j=0;j<img.cols;j++){
            avg_r=0;avg_g=0;avg_b=0;
            count=0;
            for(int k=i-5;k<i+6;k++){
                for(int l=j-5;l<j+6;l++){
                    if(0<k && k<img.rows && 0<l && l<img.cols){
                        avg_r+=img.at<Vec3b>(k,l)[2];
                        avg_g+=img.at<Vec3b>(k,l)[1];
                        avg_b+=img.at<Vec3b>(k,l)[0];
                        count++;
                    }
                }
            }
            a.at<Vec3b>(i,j)[2]=avg_r/count;
            a.at<Vec3b>(i,j)[1]=avg_g/count;
            a.at<Vec3b>(i,j)[0]=avg_b/count;

        }
    }
    namedWindow("lea", WINDOW_NORMAL); 
    imshow("lea",a);
    waitKey(0);
    return 0;
}

