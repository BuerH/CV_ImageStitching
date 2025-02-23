//
// Created by star on 2/18/25.
//

#ifndef SPHERICAL_SPHERICAL_H
#define SPHERICAL_SPHERICAL_H

#include <opencv2/opencv.hpp>
#include <cmath>
class Spherical {

};
//经纬坐标转化
cv::Mat getSphericalProjection (cv::Mat, int);
//极坐标转化
cv::Mat getSphericalProjectionCommon (cv::Mat, int);

#endif //SPHERICAL_SPHERICAL_H
