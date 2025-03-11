//
// Created by star on 3/10/25.
//

#ifndef CV_ORB_H
#define CV_ORB_H

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

/**
 * ORB方法获取特征点
 * @param keyPoints             特征点位置
 * @param descriptions          特征点描述子
 * @param features_nums         特征点数目
 * @param scaleFactor           金字塔尺寸缩小的比例
 * @param n_levels              金字塔的层数
 * @param edge_threshold        检测的边缘阈值，和patch_size大小相同
 * @param first_level           初始图象放在金子塔第几层
 * @param WTA_K                 使用那种形式的描述子，默认2使用BRIEF描述子，使用汉明距离进行比较
 * @param score_type            关键点的评价方法
 * @param patch_size            生成描述子时关键点周围邻域的尺寸
 * @param fast_threshold        计算FAST角点时像素值插值的阈值
 */
void getFeatureAndDescriptorsByORB(const cv::Mat&, std::vector<cv::KeyPoint>& keyPoints, cv::Mat& descriptions,
                                   int features_nums = 150, float scaleFactor = 1.2f,
                                   int n_levels = 8, int edge_threshold = 31, int first_level = 0, int WTA_K = 2,
                                   cv::ORB::ScoreType score_type = cv::ORB::HARRIS_SCORE, int patch_size = 31, int fast_threshold = 20);

#endif //CV_ORB_H
