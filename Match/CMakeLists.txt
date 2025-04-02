
add_library(Match
        match.h
        BFMatcher/bfMatch.cpp
        BFMatcher/bfMatch.h)

target_include_directories(Match PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# 如果 Projection 依赖于 OpenCV，则需要添加以下行：
target_link_libraries(Match ${OpenCV_LIBRARIES})