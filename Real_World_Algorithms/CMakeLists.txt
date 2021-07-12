message("### RealWorldAlgorithms BEGIN")
cmake_minimum_required(VERSION 3.20)

#Real World Algorithms Book tasks. And test in console and google test.
project(RealWorldAlgorithms)

add_executable(RealWorldAlgorithmsTestConsole Real_World_Algorithms.cpp)

target_compile_features(RealWorldAlgorithmsTestConsole PUBLIC cxx_std_20)

#add timedelay lib from github
include(${VisualAlgorithms_SOURCE_DIR}/cmake/TimedelayFetch.cmake)
TimedelayFetch(RealWorldAlgorithmsTestConsole)

include(${VisualAlgorithms_SOURCE_DIR}/cmake/MessageProperty.cmake)
message_property(RealWorldAlgorithmsTestConsole CXX_STANDART)

message_property(CMAKE CXX_STANDART)
message_property(CMAKE CXX_COMPILER_ID)
message_property(CMAKE CXX_COMPILER_VERSION)

message("### RealWorldAlgorithms END")