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


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=1

int main(int argc, char const *argv[])
{
    /* code */

    cout << " --- 00 hello world !" << endl;
    Mat srcimg = imread("../lena.png");
    if (srcimg.empty()) {
        cout << "image is null" << endl;
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", srcimg);
    
    // waitKey(0);  
    // destroyAllWindows();
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
