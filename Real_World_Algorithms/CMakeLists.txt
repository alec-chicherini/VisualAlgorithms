message("### RealWorldAlgorithms BEGIN")
cmake_minimum_required(VERSION 3.20)

#Real World Algorithms Book tasks. And test in console and google test.
project(RealWorldAlgorithms CXX C)

add_executable(RealWorldAlgorithmsTestConsole Real_World_Algorithms.cpp)
set_target_properties(RealWorldAlgorithmsTestConsole PROPERTIES
		CXX_STANDART 20
		CXX_STANDARD_REQUIRED ON)

#add timedelay lib from github
include(${VisualAlgorithms_SOURCE_DIR}/cmake/TimedelayFetch.cmake)
TimedelayFetch(RealWorldAlgorithmsTestConsole)

include(${VisualAlgorithms_SOURCE_DIR}/cmake/MessageProperty.cmake)
message_property(RealWorldAlgorithmsTestConsole CXX_STANDART)

message_property(CMAKE CXX_STANDART)
message_property(CMAKE CXX_COMPILER_ID)
message_property(CMAKE CXX_COMPILER_VERSION)

message("### RealWorldAlgorithms END")