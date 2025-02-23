//
// Created by star on 2/23/25.
//

#include "harris.h"

std::vector<cv::KeyPoint> getKeyPointsByHarris(const cv::Mat& src, int step_size, int sobel_r, double k){
    if (!src.data) {
        return {};
    }
    //转为灰度图像
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    //计算harris评价系数，R  https://lsxiang.github.io/Journey2SLAM/computer_vision/Harris/
    cv::Mat harris;
    cv::cornerHarris(gray, harris, step_size, sobel_r, k);

    //归一化数值便于比较和结果展示，0-255
    cv::Mat harrisn;
    cv::normalize(harris, harrisn, 0, 255, cv::NORM_MINMAX);

    //将图像数据类型变为CV_8U
    cv::convertScaleAbs(harrisn, harrisn);

    //寻找Harris角点
    std::vector<cv::KeyPoint> keyPoints;
    for (int row = 0; row < harrisn.rows; row++) {
        for (int col = 0; col < harrisn.cols; col++) {
            int R = harrisn.at<uchar>(row, col);
            if (R > 125) {
                cv::KeyPoint keyPoint;
                keyPoint.pt.x = (float)col;
                keyPoint.pt.y = (float)row;
                keyPoints.emplace_back(keyPoint);
            }
        }
    }
    return keyPoints;
}
