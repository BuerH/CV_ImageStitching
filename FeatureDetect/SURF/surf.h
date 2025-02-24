//
// Created by star on 2/24/25.
//

#ifndef CV_SURF_H
#define CV_SURF_H

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

 /**
  * 通过surf方法计算特征点
  * @param keyPoints 特征点存放处
  * @param descriptions 描述子存放处
  * @param hessian_threshold surf关键点检测的阈值， 默认为300
  * @param octaves_nums 构建关键点金字塔的组数， 默认为4
  * @param octave_layers_nums 金字塔每组的层数， 默认为3
  * @param extended 是否使用拓展描述子， 默认为true
  * @param upright 是否计算关键点方向，默认为false
  */
void getFeatureAndDescriptorsBySURF(const cv::Mat&, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions, double hessian_threshold = 300, int octaves_nums = 50, int octave_layers_nums = 3, bool extended = true, bool upright = false);


#endif //CV_SURF_H
