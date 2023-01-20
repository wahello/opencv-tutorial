#include <iostream>

#include <opencv2/opencv.hpp>
#include <filesystem>


extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
}

using namespace std;
using namespace cv;
namespace fs = std::filesystem;


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

    Mat srcimg3 = imread("../lena.png");
    imshow("srcimg3", srcimg3);
    Mat black = Mat::zeros(srcimg3.size(), srcimg3.type());
    black = Scalar(40, 40, 40); // 亮度 brightness

    Mat dst5;
    add(srcimg3, black, dst5); //
    imshow("dst5", dst5);

    Mat dst6;
    subtract(srcimg3, black, dst6);
    imshow("dst6", dst6);

    Mat dst7;
    addWeighted(srcimg3, 1.5, black, 0.2, 0.0, dst7);
    imshow("dst7", dst7);

    vector <int> compression_params;
    compression_params.push_back(IMWRITE_JPEG_QUALITY);
    compression_params.push_back(80);

    std::string dire("../result/07/");
    std::error_code ec;
    fs::create_directories(dire);

    imwrite("../result/07/dst7.jpg", dst7, compression_params);
    imwrite("../result/07/dst6.jpg", dst6, compression_params);

    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
