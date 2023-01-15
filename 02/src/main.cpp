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


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=3

int main(int argc, char const *argv[])
{
    /* code */
    cout << " --- 00 hello world !" << endl;
    // Mat srcimg = imread("../lena.png", IMREAD_COLOR);
    Mat srcimg = imread("../lena.png", IMREAD_UNCHANGED);
    if (srcimg.empty()) {
        cout << "image is null" << endl;
        return -1;
    }

    // namedWindow("003-demo", WINDOW_AUTOSIZE);
    namedWindow("003-demo", WINDOW_NORMAL);
    imshow("003-demo", srcimg);
    
    // waitKey(0);  
    // destroyAllWindows();
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
