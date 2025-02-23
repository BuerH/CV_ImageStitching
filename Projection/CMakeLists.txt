
add_library(Projection
        head/Spherical.h
        source/Spherical.cpp
        source/Cylindrical.cpp
        projection.h)

target_include_directories(Projection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # 可选：如果 Projection 有头文件需要暴露
# 如果 Projection 依赖于 OpenCV，则需要添加以下行：
target_link_libraries(Projection ${OpenCV_LIBRARIES})