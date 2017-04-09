cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

project(kbcontrol)
add_executable(kbcontrol main.cpp)

find_package(X11 REQUIRED)

if (X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(kbcontrol ${X11_LIBRARIES})
endif(X11_FOUND)

enable_testing()
add_executable(test_kbcontrol test.cpp)
add_test(test_kbcontrol test_kbcontrol)

