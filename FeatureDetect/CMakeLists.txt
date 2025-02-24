add_library(FeatureDetect
        SIFT/sift.cpp
        SIFT/sift.h
        feature.h
        SURF/surf.cpp
)

target_include_directories(FeatureDetect PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # 可选：如果 CornerDetect 有头文件需要暴露
# 如果 CornerDetect 依赖于 OpenCV，则需要添加以下行：
target_link_libraries(FeatureDetect ${OpenCV_LIBRARIES} opencv_xfeatures2d)