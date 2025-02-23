//
// Created by star on 2/23/25.
//

#ifndef CV_SHITOMAS_H
#define CV_SHITOMAS_H
#include <opencv2/opencv.hpp>

/**
 * 使用harris的改进方法进行检测
 * @param maxCorners 最大角点数量 默认为100
 * @param quality_level 角点阈值与最佳角点的关系，默认为0.01倍
 * @param minDistance 两角点最佳欧式距离，默认为 0.05
 * @param mask 掩码，默认为空，代表检测整幅图像
 * @param blockSize 计算梯度协方差矩阵的尺寸， 默认为3
 * @param useHarris 是否使用 Harris 角点检测
 * @param k Harris 角点检测的常值权重系数 默认为0.05
 * @return 所有的关键点
 */
std::vector<cv::KeyPoint> getKeyPointsByShi(const cv::Mat&, int maxCorners = 100, double quality_level = 0.01, double minDistance = 0.05, cv::Mat mask = cv::Mat(), int blockSize = 3, bool useHarris = false, double k = 0.05);

#endif //CV_SHITOMAS_H
