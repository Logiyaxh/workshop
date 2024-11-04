#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include"light.h"

int main()
{
    cv::Mat img = cv::imread("../image/image2.png");
    if(img.empty())
    {
        std::cerr << "Could not load..." << std::endl;
    }

    lightReco(img, BLUE);    
    return 0;
}