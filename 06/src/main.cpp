#include <iostream>

#include <opencv2/opencv.hpp>


extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
}

using namespace std;
using namespace cv;


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=7

int main(int argc, char const *argv[])
{
    /* code */

    cout << " --- 00 hello world !" << endl;
    Mat srcimg1 = imread("../lena.png");
    Mat srcimg2 = imread("../lena.png");

    if (srcimg1.empty() || srcimg2.empty()) {
        cout << "image is null" << endl;
        return -1;
    }

    // namedWindow("input1", WINDOW_AUTOSIZE);
    imshow("input1", srcimg1);
    imshow("input2", srcimg2);
    
    // 
    Mat dst1;
    add(srcimg1, srcimg2, dst1);
    imshow("add-img", dst1);

    Mat dst2;
    subtract(srcimg1, srcimg2, dst2);
    imshow("substract-img", dst2);

    Mat dst3;
    multiply(srcimg1, srcimg2, dst3);
    imshow("mulptlpy-img", dst3);

    Mat dst4;
    divide(srcimg1, srcimg2, dst4);
    imshow("divide-img", dst4);


    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
