//
// Created by star on 3/23/25.
//

#include "bfMatch.h"
void getMatchesByBF(const cv::Mat& description1, const cv::Mat& description2, std::vector<cv::DMatch>& matches, cv::NormTypes matcherType, float maxDistance) {
    cv::BFMatcher bfMatcher(matcherType); //设置距离
    std::vector<cv::DMatch> allMatches;
    bfMatcher.match(description1, description2, allMatches);
    for(auto & allMatch : allMatches) {
        if(allMatch.distance <= maxDistance) {
            matches.push_back(allMatch);
        }
    }
}