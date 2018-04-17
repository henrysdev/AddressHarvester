cmake_minimum_required(VERSION 2.8.9)
project(entry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")

add_executable(entry src/Harvester.cpp src/UrlFrontier.cpp src/UrlFrontier.h src/PageGrabber.cpp src/PageGrabber.h src/Parser.cpp src/Parser.h)

target_link_libraries(entry curl)