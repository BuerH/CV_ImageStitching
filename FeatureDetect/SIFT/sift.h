//
// Created by star on 2/24/25.
//

#ifndef CV_SIFT_H
#define CV_SIFT_H

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
/**
 * 通过sift方法计算特征点
 * @param keyPoints 特征点存放处
 * @param descriptions 描述子存放处
 * @param features_nums 特征点数量，默认为50
 * @param octave_layers_nums 每组的层数，默认为3
 * @param contrast_threshold 过滤较差特征点的阈值，参数越大，返回特征点越少，默认为0.04
 * @param edge_threshold 过滤边缘效应的阈值，参数越大，返回特征点越多，默认为10
 * @param sigma 金字塔第0层高斯滤波的系数，默认为1.6
 */
void getFeatureAndDescriptorsBySIFT(const cv::Mat&, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions, int features_nums = 50, int octave_layers_nums = 3, double contrast_threshold = 0.04, double edge_threshold = 10, double sigma = 1.6);
#endif //CV_SIFT_H
