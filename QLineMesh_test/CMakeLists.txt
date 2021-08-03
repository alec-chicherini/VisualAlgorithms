message("### line_mesh_test BEGIN")
cmake_minimum_required(VERSION 3.20)

#building evironment for QObjectPicker_test
project(line_mesh_test)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CURRENT_PROJECT_COMPONENTS Widgets Gui Core 3DCore 3DExtras 3DRender)

include(${VisualAlgorithms_SOURCE_DIR}/cmake/QtModulePrepare.cmake)
QtModulePrepare(CURRENT_PROJECT_COMPONENTS)

add_executable(${PROJECT_NAME} 
	main.cpp)

add_library(line_mesh_window
	qlinemesh_test.cpp
	)

#now library reates in algorithms visualisation project
#add_library(qlinemesh
#	${VisualAlgorithms_SOURCE_DIR}/AlgorithmsVisualisationQt/3d/qlinemesh.cpp
#	)

target_include_directories(line_mesh_window PUBLIC
${VisualAlgorithms_SOURCE_DIR}/AlgorithmsVisualisationQt/3d/
)

target_link_libraries(
	line_mesh_window
	qlinemesh
)


foreach(COMP IN LISTS CURRENT_PROJECT_COMPONENTS)
	set(CURRENT_COMPONENT_NAME ${QT_PERFIX}${COMP} )
	message(" ### line_mesh_window linked with  ${CURRENT_COMPONENT_NAME} ")
	message(" ### qlinemesh linked with  ${CURRENT_COMPONENT_NAME} ")
	target_link_libraries(line_mesh_window  ${CURRENT_COMPONENT_NAME})
	target_link_libraries(qlinemesh  ${CURRENT_COMPONENT_NAME})
endforeach()

target_link_libraries(${PROJECT_NAME}
	line_mesh_window 
	Qt::Widgets
	)

#Project deployment BEGIN
if(WIN32)

set(FULL_PATH_TO_EXEC $<TARGET_FILE:${PROJECT_NAME}>)
message(" ### FULL_PATH_TO_EXEC is ${FULL_PATH_TO_EXEC} ")

message(" ### Deployment for Windows. Looking for windeployqt.exe")

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_PREFIX_PATH}/bin/windeployqt.exe 
					${FULL_PATH_TO_EXEC}
					--no-quick-import 
					--no-translations 
)
 elseif(LINUX)

      message(" ### Deployment for Linux. In develop.")

   endif(WIN32)
#Project deployment END
message("### line_mesh_test END")