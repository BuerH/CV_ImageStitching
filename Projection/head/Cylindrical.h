//
// Created by star on 2/18/25.
//

#ifndef SPHERICAL_CYLINDRICAL_H
#define SPHERICAL_CYLINDRICAL_H

#include <opencv2/opencv.hpp>
#include <cmath>
class Cylindrical {

};

cv::Mat getCylindricalProjection (cv::Mat, int);

cv::Mat getCylindricalProjectionCommon (cv::Mat, int);

cv::Mat getCylindricalProjWithPara (cv::Mat, int);


#endif //SPHERICAL_CYLINDRICAL_H
