message("### GraphVisualisationOLCGE BEGIN")
cmake_minimum_required(VERSION 3.20)


#Real World Algorithms Book tasks. And test in console and google test.
project(GraphsVisualisationOLCGE)

add_executable(${PROJECT_NAME} GraphsVisualisationOLCGE.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


#add olc pixel game engine header from github
include(${VisualAlgorithms_SOURCE_DIR}/cmake/OLCGEFetch.cmake)
OLCGEFetch(${PROJECT_NAME})

#add timedelay lib from github
include(${VisualAlgorithms_SOURCE_DIR}/cmake/TimedelayFetch.cmake)
TimedelayFetch(${PROJECT_NAME})

include(${VisualAlgorithms_SOURCE_DIR}/cmake/MessageProperty.cmake)
message_property(${PROJECT_NAME} CXX_STANDART)

message_property(CMAKE CXX_STANDART)
message_property(CMAKE CXX_COMPILER_ID)
message_property(CMAKE CXX_COMPILER_VERSION)

message("### GraphVisualisationOLCGE END")