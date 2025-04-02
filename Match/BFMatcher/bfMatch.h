//
// Created by star on 3/23/25.
//

#ifndef CV_BFMATCH_H
#define CV_BFMATCH_H

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

/**
 * 使用暴力匹配的方法获取匹配的点。默认使用汉明距离，最大距离为30.
 * @param matcherType 使用的距离计算方法
 * @param maxDistance 匹配的描述子的最大距离
 */
void getMatchesByBF(const cv::Mat&, const cv::Mat&, std::vector<cv::DMatch> &, cv::NormTypes matcherType = cv::NORM_HAMMING, float maxDistance = 30.0);

#endif //CV_BFMATCH_H
