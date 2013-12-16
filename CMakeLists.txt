cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(CommandBasedRobot)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(cmd-based ${SOURCE_CODE})
target_link_libraries(cmd-based ${WPILib_LIBRARY})

add_make_deploy(cmd-based 10.25.39.2)
