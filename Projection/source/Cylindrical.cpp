//
// Created by star on 2/18/25.
//

#include "Projection/head/Cylindrical.h"

cv::Mat getCylindricalProjection (cv::Mat image, int focal) {
    if (image.empty()) {
        return image;
    }
    int height = image.rows;
    int width = image.cols;
    int result_width = width + 200;
    int result_height = height + 200;
    cv::Mat result_image(result_height, result_width,CV_8UC3);

    double theta = 0;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            theta = atan2(i, focal);

            int proj_i = (int)(focal * theta);
            int proj_j = (int)(focal * j / sqrt(pow(i, 2) + pow (focal, 2)));

            if (proj_i >= 0 && proj_i <result_width && proj_j > 0 && proj_j < result_height) {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = image.at<cv::Vec3b>(j,i);
            } else {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = 0;
            }
        }
    }
    return result_image;
}

cv::Mat getCylindricalProjectionCommon (cv::Mat image, int focal) {
    if (image.empty()) {
        return image;
    }
    int height = image.rows;
    int width = image.cols;
    int result_width = width + 200;
    int result_height = height + 200;
    int center_x = width/2;
    int center_y = height/2;
    cv::Mat result_image(result_height, result_width,CV_8UC3);

    double theta = 0;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {

            theta = atan2(i-center_x, focal);

            int proj_i = (int)(focal * theta) + result_width/2;
            int proj_j = (int)(focal * (j-center_y) / sqrt(pow(i-center_x, 2) + pow (focal, 2))) + result_height/2;

            if (proj_i >= 0 && proj_i <result_width && proj_j > 0 && proj_j < result_height) {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = image.at<cv::Vec3b>(j,i);
            } else {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = 0;
            }
        }
    }
    return result_image;

}

cv::Mat getCylindricalProjWithPara (cv::Mat image, int focal) {
    if (image.empty()) {
        return image;
    }
    int height = image.rows;
    int width = image.cols;
    int result_width = width + 200;
    int result_height = height + 200;
    int center_x = width/2;
    int center_y = height/2;

    cv::Mat result_image(result_height, result_width,CV_8UC3);

    double u = 0;
    double v = 0;
    double w = 0;
    double theta = 0;

    double mid = 0;

    double theta2 = atan2(result_width, 2*focal);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            mid = sqrt (pow(i-center_x, 2) + pow (focal, 2));
            u = focal * (i - center_x) / mid;
            v = focal * (j - center_y) / mid;
            w = focal * focal / mid;

            theta = atan2(u, w);

            int proj_i = (int)(focal * theta) + focal * theta2;
            int proj_j = (int)v + result_height/2;

            if (proj_i >= 0 && proj_i <result_width && proj_j > 0 && proj_j < result_height) {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = image.at<cv::Vec3b>(j,i);
            } else {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = 0;
            }
        }
    }
    return result_image;

}