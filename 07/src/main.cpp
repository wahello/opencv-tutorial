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


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=7

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

    
    // 
    Mat dst1;
    Mat mask = Mat::zeros(srcimg1.size(), CV_8UC1);
    bitwise_not(srcimg1, dst1, mask);
    imshow("bitwise_not", dst1);
    

    vector <int> compression_params;
    compression_params.push_back(IMWRITE_JPEG_QUALITY);
    compression_params.push_back(80);

    std::string dire("../result/08/");
    std::error_code ec;
    fs::create_directories(dire);

    imwrite("../result/07/dst1.jpg", dst1, compression_params);
    // imwrite("../result/07/dst6.jpg", dst6, compression_params);

    waitKey(0);
    destroyAllWindows();
    
    cout << " " << endl;

    return 0;
}
