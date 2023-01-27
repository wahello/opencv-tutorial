#include <iostream>
#include <filesystem>

#include <opencv2/opencv.hpp>


extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
}

using namespace std;
using namespace cv;

namespace fs = std::filesystem;

// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=8

int main(int argc, char const *argv[])
{
    /* code */

    cout << " --- 00 hello world !" << endl;
    Mat srcimg1 = imread("../lena.png");

    if (srcimg1.empty()) {
        cout << "image is null" << endl;
        return -1;
    }

    // namedWindow("input1", WINDOW_AUTOSIZE);
    imshow("input1", srcimg1);

    
    // 按为非
    Mat dst1;
    Mat mask1 = Mat::zeros(srcimg1.size(), CV_8UC1);
    Mat mask2 = Mat::zeros(srcimg1.size(), CV_8UC1);

    int w = srcimg1.cols / 2;
    int h = srcimg1.rows / 2;
    for (int row = 0; row < h; row ++ ) {
        for (int col = 0; col < w; col ++ ) {
            mask1.at<uchar>(h + row, w + col) = 255;
            mask2.at<uchar>(h + row, w + col) = 50;
        }
    }

    bitwise_not(srcimg1, dst1, mask1);
    imshow("mask1", mask1);
    imshow("bitwise_not", dst1);
    
    // 按位与
    Mat dst2;
    bitwise_and(srcimg1, srcimg1, dst2, mask1);    
    imshow("bitwise_and", dst2);

    // 按位或
    Mat dst3;
    bitwise_or(srcimg1, srcimg1, dst3, mask2);
    imshow("mask2", mask2);
    imshow("bitwise_or", dst3);
    

    vector <int> compression_params;
    compression_params.push_back(IMWRITE_JPEG_QUALITY);
    compression_params.push_back(80);

    std::string dire("../result/08/");
    std::error_code ec;
    fs::create_directories(dire);

    imwrite("../result/08/dst1.jpg", dst1, compression_params);

    waitKey(0);
    destroyAllWindows();
    
    cout << " end of " << endl;

    return 0;
}
