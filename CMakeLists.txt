cmake_minimum_required(VERSION 2.8)
#include(FRCDeploy)

project(CommandBasedRobot)

set(WPILib_INCLUDE_DIRS "/usr/arm-frc-linux-gnueabi/include")
set(WPILib_LIBRARY "/usr/arm-frc-linux-gnueabi/lib/libwpi_2015.so")

include_directories(${WPILib_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(cmd-based ${SOURCE_CODE})
target_link_libraries(cmd-based ${WPILib_LIBRARY})

#add_make_deploy(cmd-based 10.25.39.2)
