//
// Created by star on 2/18/25.
//

#include "Projection/head/Spherical.h"
cv::Mat getSphericalProjection (cv::Mat image, int focal) {
    // 检查图像是否成功读取
    if (image.empty()) {
        std::cout << "无法读取图像" << std::endl;
        return image;
    }

    int height = image.rows;
    int width = image.cols;
    int center_x = width / 2;
    int center_y = height / 2;
    int result_width = width + 100;
    int result_height = height +  100;
    cv::Mat result_image(result_height, result_width, CV_8UC3);
    double phi = 0;
    double theta = 0;
    for (int i = 0; i < width; ++i) {
        int x_off_set = i - center_x;
        for (int j = 0; j < height; ++j) {
            int y_off_set = j - center_y;
            phi = atan2(y_off_set, sqrt(pow(x_off_set, 2) + pow(focal, 2)));
            theta = atan2(x_off_set, focal);

            // 将极坐标转换回笛卡尔坐标 (投影到平面)
            int proj_i = (int)(focal * theta * cos(phi) + result_width / 2);
            int proj_j = (int)(focal * phi + result_height / 2);
            // 检查是否越界
            if (proj_i >= 0 && proj_i < result_width && proj_j >= 0 && proj_j < result_height) {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = image.at<cv::Vec3b>(j, i);
            } else {
                result_image.at<uchar>(j, i) = 0; // 越界时设置为黑色或其他默认值
            }
        }
    }
    return result_image;
}


cv::Mat getSphericalProjectionCommon (cv::Mat image, int focal) {
    //检查图像是否成功读取
    if (image.empty()) {
        std::cout << "无法读取图像" << std::endl;
        return image;
    }
    int f = 700;

    int height = image.rows;
    int width = image.cols;
    int center_x = width / 2;
    int center_y = height / 2;

    // 确定结果图像的大小 (根据 f 的值调整)
    int result_width = width + 200;
    int result_height = height +  200;
    cv::Mat result_image(result_height, result_width, CV_8UC3);
    result_image = cv::Scalar(0, 0, 0); // 初始化为黑色

    for (int i = 0; i < width; ++i) {
        int x_off_set = i - center_x;
        for (int j = 0; j < height; ++j) {
            int y_off_set = j - center_y;

            // 使用球坐标系转换公式 (更接近真实的球面投影)
            double x = (double)x_off_set / f;
            double y = (double)y_off_set / f;
            double r = sqrt(x * x + y * y);

            double theta = atan(r); // 极角
            double phi = atan2(y, x);  // 方位角

            // 将极坐标转换回笛卡尔坐标 (投影到平面)
            int proj_i = (int)(f * theta * cos(phi) + result_width / 2);
            int proj_j = (int)(f * theta * sin(phi) + result_height / 2);

            // 检查是否越界 (针对结果图像)
            if (proj_i >= 0 && proj_i < result_width && proj_j >= 0 && proj_j < result_height) {
                result_image.at<cv::Vec3b>(proj_j, proj_i) = image.at<cv::Vec3b>(j, i);
            }
        }
    }
    return result_image;
}
