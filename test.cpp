#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    namedWindow("lenna", WINDOW_NORMAL);

    Mat img = imread("./lenna.jpg", 1);
	imshow("lenna", img);
    waitKey(0);
    return 0;
}
