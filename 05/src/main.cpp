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


// https://www.bilibili.com/video/BV1jz4y1Z7pf?p=6

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

    namedWindow("004-demo", WINDOW_AUTOSIZE);
    imshow("004-demo", srcimg);
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


    Mat  m1 = Mat(256, 256, CV_8UC3);
    // m1  = Scalar(0, 0, 255);
    m1  = Scalar(0, 255, 0);
    imshow("m1", m1);

    Mat  m2 = Mat(Size(512, 512), CV_8UC3);
    m2  = Scalar(255, 0, 255);
    imshow("m2", m2);

    Mat  m3 = Mat::zeros(Size(512, 512), CV_8UC3);
    imshow("m3", m3);

    Mat m5 = srcimg.clone();
    imshow("m5", m5);

    Mat m6;
    srcimg.copyTo(m6);
    imshow("m6", m6);

    Mat m7 = Mat::zeros(srcimg.size(), srcimg.type());
    imshow("m7", m7);

    Mat m8 = Mat::zeros(srcimg.size(), srcimg.type());

    for (int row = 0; row < height; row++) {
        uchar* curr_row = srcimg.ptr<uchar>(row);
        uchar* m8_row = m8.ptr<uchar>(row);

        for (int col = 0; col < width; col ++) {
            switch (chnel)
            {
            case 3:
                {
                /* code */ 
                int blue = *curr_row++;
                int green = *curr_row++;
                int red = *curr_row++;

                // 图片拷贝
                *m8_row++ =  blue;
                *m8_row++ = green;
                *m8_row++ = red;
                
                /*
                *m8_row++ = (255 - blue);
                *m8_row++ = (255 - green);
                *m8_row++ = (255 - red);
                */

                /*
                Vec3b pixel = srcimg.at<Vec3b>(row, col);
                int blue = pixel[0];
                int green = pixel[1];
                int red = pixel[2];
                srcimg.at<Vec3b>(row, col)[0] = (255 - blue);
                srcimg.at<Vec3b>(row, col)[1] = (255 - green);
                srcimg.at<Vec3b>(row, col)[2] = (255 - red);
                */

                break;
                }
            case 1:
                {
                int pv = *curr_row++;

                // 
                *m8_row++ = pv;

                // *m8_row++ = (255 - pv);

                /*
                int pv = srcimg.at<uchar>(row, col);
                srcimg.at<uchar>(row, col) = (255 -pv);
                */
                break;
                }
            default:
                break;
            }
        }
    }

    imshow("m8", m8);

    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
