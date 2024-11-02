#include"light.h"


void lightReco(cv::Mat img, Color c = RED)
{
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_RGB2GRAY);
    //进行二值化
    cv::Mat bi_image;
    cv::threshold(gray, bi_image, 127, 255, cv::THRESH_BINARY);
    //轮廓检测
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(bi_image, contours, cv::RETR_LIST,  cv::CHAIN_APPROX_NONE);
    //绘制轮廓
    for (const auto& contour : contours)
    {
        cv::Rect bd_rect = cv::boundingRect(contour);
        double r = static_cast<double>(bd_rect.width)/bd_rect.height;
        //double area = bd_rect.area();

        if(r>0.1 && r<0.4)
        {
            cv::rectangle(img, bd_rect, cv::Scalar(0, 255, 0), 2);
        }
    }
    
    cv::imshow("binary image", bi_image);
    cv::imshow("recognition image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}