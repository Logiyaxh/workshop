#include"light.h"

void lightReco(cv::Mat img, Color c = RED)
{
    //转化灰度
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    //进行二值化
    cv::Mat bi_image;
    cv::threshold(gray, bi_image, 200, 255, cv::THRESH_BINARY);
    //轮廓检测
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(bi_image, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

    //绘制轮廓
    for (const auto& contour : contours)
    {
        //计算外接矩形
        cv::Rect bd_rect = cv::boundingRect(contour);
        double r = static_cast<double>(bd_rect.width)/bd_rect.height;
        //计算平均颜色
        double red_avg = cv::mean(img(bd_rect))[2];
        double blue_avg = cv::mean(img(bd_rect))[0];

        //test
        // cv::imshow("test1", bi_image(bd_rect));
        // cv::imshow("test2", img(bd_rect));
        // cv::waitKey(0);
        // std::cout << red_avg << "\t" << blue_avg << std::endl;

        switch (c)
        {
        case RED:
            if (red_avg > blue_avg && r>0.1 && r<0.4)
            {
                cv::rectangle(img, bd_rect, cv::Scalar(0, 255, 0), 2);
            }
            break;
        case BLUE:
            if (blue_avg > red_avg && r>0.1 && r<0.4)
            {
                cv::rectangle(img, bd_rect, cv::Scalar(0, 255, 0), 2);
            }
            break;
        default:
            break;
        }
    }
    
    cv::imshow("binary image", bi_image);
    cv::imshow("recognition image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}