
add_library(CornerDetect
        Harris/harris.h
        Harris/harris.cpp
        Shi_Tomas/shiTomas.h
        Shi_Tomas/shiTomas.cpp
        corner.h
        Fast/fast.cpp)

target_include_directories(CornerDetect PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # 可选：如果 CornerDetect 有头文件需要暴露
# 如果 CornerDetect 依赖于 OpenCV，则需要添加以下行：
target_link_libraries(CornerDetect ${OpenCV_LIBRARIES})