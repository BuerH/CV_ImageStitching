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

include_directories(. ${OpenCV_INCLUDE_DIRS})

add_executable(CV main.cpp
        Projection/head/Spherical.h
        Projection/source/Spherical.cpp
        Projection/source/Cylindrical.cpp
        CornerDetect/Harris/harris.h
        CornerDetect/Harris/harris.cpp
        CornerDetect/Shi_Tomas/shiTomas.h
        CornerDetect/Shi_Tomas/shiTomas.cpp
        Projection/projection.h
        CornerDetect/corner.h)

target_link_libraries(CV ${OpenCV_LIBRARIES} opencv_xfeatures2d)