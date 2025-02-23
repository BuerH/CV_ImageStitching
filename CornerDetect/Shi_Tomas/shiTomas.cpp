//
// Created by star on 2/23/25.
//

#include "shiTomas.h"
std::vector<cv::KeyPoint> getKeyPointsByShi(const cv::Mat& src, int maxCorners, double quality_level, double minDistance, cv::Mat mask, int blockSize, bool useHarris, double k) {
    if (!src.data) {
        return {};
    }
    std::vector<cv::KeyPoint> keyPoints;
    std::vector<cv::Point2f> corners;

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    if (useHarris) {
        cv::goodFeaturesToTrack(gray, corners, maxCorners, quality_level, minDistance, mask, blockSize, useHarris, k);
    } else {
        cv::goodFeaturesToTrack(gray, corners, maxCorners, quality_level, minDistance, mask);
    }
    for (auto corner : corners) {
        cv::KeyPoint keyPoint;
        keyPoint.pt = corner;
        keyPoints.emplace_back(keyPoint);
    }
    return keyPoints;
}
