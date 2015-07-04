cmake_minimum_required(VERSION 2.8)

project(CommandBasedRobot)

set(WPILib_INCLUDE_DIRS "/usr/arm-frc-linux-gnueabi/include")
set(WPILib_LIBRARY "/usr/arm-frc-linux-gnueabi/lib/libwpi_2015.so")

include_directories(${WPILib_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(cmd-based ${SOURCE_CODE})
target_link_libraries(cmd-based ${WPILib_LIBRARY})

set(TEAM 2539)
add_custom_command(OUTPUT deploy_stamp
	COMMAND ssh -q lvuser@roborio-${TEAM}.local "rm /home/lvuser/FRCUserProgram || true"
	COMMAND scp cmd-based lvuser@roborio-${TEAM}.local:FRCUserProgram
	COMMAND ssh -q lvuser@roborio-${TEAM}.local ". /etc/profile.d/natinst-path.sh; chmod a+x /home/lvuser/FRCUserProgram; /usr/local/frc/bin/frcKillRobot.sh -t -r"
	DEPENDS cmd-based
VERBATIM)
set_source_files_properties(deploy_stamp PROPERTIES SYMBOLIC true)
add_custom_target(deploy DEPENDS deploy_stamp)
