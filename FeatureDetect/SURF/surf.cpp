//
// Created by star on 2/24/25.
//
#include "surf.h"
void getFeatureAndDescriptorsBySURF(const cv::Mat& img, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions, double hessian_threshold, int octaves_nums, int octave_layers_nums, bool extended, bool upright) {
    if (!img.data) {
        return;
    }
    cv::Ptr<cv::xfeatures2d::SURF> surf = cv::xfeatures2d::SURF::create(hessian_threshold, octaves_nums, octave_layers_nums, extended,
                                              upright);
    //计算特征点
    surf->detect(img, keyPoints);

    surf->compute(img, keyPoints, descriptions);
    /**
     * 二合一，同时计算特征点和描述子，第五个参数若为true，则和compute没有区别
     * 第二个参数是掩码mask，这里可能要注意，没有测试
     */
//    surf->detectAndCompute(img, cv::Mat(), keyPoints, descriptions, false);
}
