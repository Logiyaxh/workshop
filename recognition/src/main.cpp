#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include"light.h"

int main()
{
    cv::Mat img = cv::imread("../image/image1.png");
    if(img.empty())
    {
        std::cerr << "Could not load..." << std::endl;
    }
    //转化灰度图像
    lightReco(img, RED);
    return 0;
}