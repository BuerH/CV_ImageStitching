//
// Created by star on 2/23/25.
//

#ifndef CV_HARRIS_H
#define CV_HARRIS_H
#include <opencv2/opencv.hpp>

class harris {

};

std::vector<cv::KeyPoint> getKeyPointsByHarris(const cv::Mat&, int step_size = 2, int sobel_r = 5, double k = 0.05);

#endif //CV_HARRIS_H
