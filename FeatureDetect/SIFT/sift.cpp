//
// Created by star on 2/24/25.
//
#include "sift.h"
void getFeatureAndDescriptorsBySIFT(const cv::Mat& img, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions, int features_nums, int octave_layers_nums, double contrast_threshold, double edge_threshold, double sigma) {
    if (!img.data) {
        return;
    }
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create(features_nums, octave_layers_nums, contrast_threshold, edge_threshold,
                                              sigma);
    //计算特征点
    sift->detect(img, keyPoints);

    sift->compute(img, keyPoints, descriptions);
    /**
     * 二合一，同时计算特征点和描述子，第五个参数若为true，则和compute没有区别
     * 第二个参数是掩码mask，这里可能要注意，没有测试
     */
//    sift->detectAndCompute(img, cv::Mat(), keyPoints, descriptions, false);
}