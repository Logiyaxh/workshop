#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>

enum Color
{
    RED,
    GREEN,
    BLUE
};
void lightReco(cv::Mat img, Color c);