cmake_minimum_required(VERSION 3.2.1)
project(Astar)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 14)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
add_executable(Astar src/astar.cpp src/Map.cpp src/Nodes.cpp)
target_link_libraries (Astar ${OpenCV_LIBS})
