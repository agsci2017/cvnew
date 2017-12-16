cmake_minimum_required(VERSION 2.8)
project(opencv_example_project)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenMP)

if(OPENMP_FOUND)
message("OPENMP FOUND")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "-O2 -fomit-frame-pointer -msse2 -msse3 -msse -mmmx ")

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

if(CMAKE_VERSION VERSION_LESS "2.8.11")
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

add_executable(x x.cpp)
target_link_libraries(x ${OpenCV_LIBS})


