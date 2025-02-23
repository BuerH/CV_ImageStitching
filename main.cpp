#include <iostream>
#include "Projection/projection.h"
#include "CornerDetect/corner.h"

#ifndef FOCAL
#define FOCAL 1000
#endif
using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat image = imread("/home/star/CLionProjects/SIFT/1.png", IMREAD_COLOR);

    // 检查图像是否成功读取
    if (image.empty()) {
        cout << "无法读取图像" << endl;
        return -1;
    }

    vector<KeyPoint> keyPoints;
    keyPoints = getKeyPointsByShi(image);
    Mat keyPointImage;
    drawKeypoints(image, keyPoints, keyPointImage);
    imshow("Harris角点", keyPointImage);
//    cv::Mat result_image = getSphericalProjection(image, FOCAL);
//    cv::Mat result_image = getSphericalProjectionCommon(image, FOCAL);
//    cv::Mat result_image = getCylindricalProjection(image, FOCAL);
    cv::Mat result_image = getCylindricalProjectionCommon(image, FOCAL);
//    cv::Mat result_image = getCylindricalProjWithPara(image, FOCAL);



    imshow("关键点", result_image);
    waitKey(0);

    return 0;
}
