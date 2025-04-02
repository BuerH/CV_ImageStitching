cmake_minimum_required(VERSION 3.26)
project(CV)

set(CMAKE_CXX_STANDARD 14)

if(POLICY CMP0146)
    cmake_policy(SET CMP0146 OLD)
endif()

find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found")
endif()

add_subdirectory(src)
add_subdirectory(CornerDetect)
add_subdirectory(Projection)
add_subdirectory(FeatureDetect)
add_subdirectory(Match)

target_link_libraries(CV ${OpenCV_LIBRARIES} opencv_xfeatures2d CornerDetect Projection FeatureDetect Match)