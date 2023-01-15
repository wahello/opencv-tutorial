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


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=4

int main(int argc, char const *argv[])
{
    /* code */

    cout << " --- 00 hello world !" << endl;
    // Mat srcimg = imread("../lena.png");
    // Mat srcimg = imread("../lena.png", IMREAD_GRAYSCALE);
    Mat srcimg = imread("../lena.png", IMREAD_UNCHANGED);
    if (srcimg.empty()) {
        cout << "image is null" << endl;
        return -1;
    }

    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", srcimg);
    int chnel = srcimg.channels();
    int width = srcimg.cols;
    int height = srcimg.rows;
    int  depth = srcimg.depth();
    int t = srcimg.type();

    if (t == CV_8UC3) {
        cout << " t : " << t << endl;
    }

    cout << "channels: " << chnel << endl;
    cout << "width: " << width << endl;
    cout << "height: " << height << endl;
    // imwrite("./lena.jpg", srcimg);

    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
