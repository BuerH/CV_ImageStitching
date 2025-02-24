#include <iostream>
#include "../Projection/projection.h"
#include "../CornerDetect/corner.h"
#include "../FeatureDetect/feature.h"

#ifndef FOCAL
#define FOCAL 1000
#endif

//记得修改路径
#ifndef TEST_IMAGE_PATH
#define TEST_IMAGE_PATH "/home/star/CLionProjects/SIFT/1.png"
#endif
using namespace std;
void testFeatureDetect(const cv::Mat& image);

int main() {
    // 读取图像
    cv::Mat image = imread(TEST_IMAGE_PATH, cv::IMREAD_COLOR);

    // 检查图像是否成功读取
    if (image.empty()) {
        cout << "无法读取图像" << endl;
        return -1;
    }
    vector<cv::KeyPoint> keyPoints;
    cv::Mat descriptions;

    keyPoints = getKeyPointsByShi(image);
    cv::Mat keyPointImage;
    drawKeypoints(image, keyPoints, keyPointImage);
//    imshow("Harris角点", keyPointImage);
//    cv::Mat result_image = getSphericalProjection(image, FOCAL);
//    cv::Mat result_image = getSphericalProjectionCommon(image, FOCAL);
//    cv::Mat result_image = getCylindricalProjection(image, FOCAL);
    cv::Mat result_image = getCylindricalProjectionCommon(image, FOCAL);
//    cv::Mat result_image = getCylindricalProjWithPara(image, FOCAL);

//    imshow("关键点", result_image);
    testFeatureDetect(image);

    cv::waitKey(0);

    return 0;
}

void testFeatureDetect(const cv::Mat& image) {
    vector<cv::KeyPoint> keyPoints;
    cv::Mat descriptions;
    cv::Mat keyPointImage;
    getFeatureAndDescriptorsBySIFT(image,keyPoints,descriptions);
    drawKeypoints(image, keyPoints, keyPointImage);
    imshow("SIFT关键点", keyPointImage);
}
