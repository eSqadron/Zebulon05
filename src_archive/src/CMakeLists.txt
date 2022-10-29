cmake_minimum_required(VERSION 3.10)

project(Zebulon05)

set(INCLUDE include)
set(SRC src)

add_executable(Zebulon05 src/main.cpp)

target_include_directories(Zebulon05 PRIVATE ${INCLUDE})

set(SOURCES ${SRC}/main.cpp ${SRC}/RobotLeg.cpp ${INCLUDE}/RobotLeg.hpp src/RobotLegROS.cpp include/RobotLegROS.hpp)
add_executable(test ${SOURCES})