//
// Created by star on 3/10/25.
//

#include "orb.h"
void getFeatureAndDescriptorsByORB(const cv::Mat& img, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions,
                                   int features_nums, float scaleFactor,
                                   int n_levels, int edge_threshold, int first_level, int WTA_K,
                                   cv::ORB::ScoreType score_type, int patch_size, int fast_threshold) {
    if (!img.data) {
        return;
    }
    cv::Ptr<cv::ORB> orb = cv::ORB::create(features_nums, scaleFactor, n_levels, edge_threshold,
                                           first_level, WTA_K, score_type, patch_size, fast_threshold);
    //计算特征点
    orb->detect(img, keyPoints);

    orb->compute(img, keyPoints, descriptions);
}