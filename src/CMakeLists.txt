add_executable(CV main.cpp)
target_include_directories(CV PUBLIC .) #  PUBLIC 表示依赖于 CV 的其他目标也可以访问这些头文件
target_include_directories(CV PRIVATE ${OpenCV_INCLUDE_DIRS}) # PRIVATE 表示只有 CV 可以访问这些头文件