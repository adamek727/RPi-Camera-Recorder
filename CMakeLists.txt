cmake_minimum_required(VERSION 3.10)
project(SingleCamera)

find_package( OpenCV REQUIRED )
find_package( Yaml-cpp REQUIRED )

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(libs)

set(SOURCES
        src/main.cpp
        src/Application.cpp
        src/StorageHandler.cpp
        src/Camera.cpp)

add_executable(SingleCamera ${SOURCES})
target_link_libraries(SingleCamera ${OpenCV_LIBS} stdc++fs yaml-cpp)
