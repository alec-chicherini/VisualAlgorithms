#cmake -Bbuild -D_QT_5_PATH="S:\Code\Qt\5.15.2\msvc2019_64"^C

cmake_minimum_required(VERSION 3.20)

#top level sollution to all included projects
project(VisualAlgorithms)


#System initialisation BEGIN

set(LINUX ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" CACHE BOOL "If system linux - true, not - false")

# Here and later all messages generated in this project build system starts with ###
if(WIN32)
        message("### System is WIN32")
		set(WRONG_PATH_MESSAGE "'C:\\Qt\\5.15.2\\msvc2019_64\\'")
elseif(LINUX)
        message("### System is Linux")
		set(WRONG_PATH_MESSAGE "'\\Qt\\5.15.2\\gcc_64'")
else()
        message(FATAL_ERROR " ### System NOT supported now. System must be: Windows, Linux")
        return()
endif(WIN32)
#System initialisation END


#Qt initialisation BEGIN
option(_QT_5_PATH "Set _QT_5_PATH like: ${WRONG_PATH_MESSAGE}" OFF)

string(COMPARE EQUAL "${_QT_5_PATH}" "OFF" zero_check)
	if(zero_check)

                message(FATAL_ERROR "### -D_QT_5_PATH is empty! Set _QT_5_PATH on cmake.exe call like: 'cmake . -D_QT_5_PATH=${WRONG_PATH_MESSAGE}'")
                return()
	else()
		message("### -D_QT_5_PATH is ${_QT_5_PATH}")
	endif()

#not work with latest version of Qt6. So all build system made for Qt5. Qt6 future feature.
set(QT_DEFAULT_MAJOR_VERSION 5)

message("### QT_DEFAULT_MAJOR_VERSION is ${QT_DEFAULT_MAJOR_VERSION}")

#Qt initialisation END

#CMAKE build system tree initialisation BEGIN
set(REAL_WORLD_ALGORITHMS "Real_World_Algorithms")
set(Q_OBJECT_PICKER_TEST "QObjectPicker_test")
set(Q_LINE_MESH_TEST "QLineMesh_test")
set(ALGORITHMS_VISUALISATION_QT "AlgorithmsVisualisationQt")
set(GRAPHS_VISUALISATION_OLCGE "GraphsVisualisationOLCGE")

set(PROJECTS 
    ${REAL_WORLD_ALGORITHMS}
	${ALGORITHMS_VISUALISATION_QT}
	${Q_OBJECT_PICKER_TEST}
	${Q_LINE_MESH_TEST}
	${GRAPHS_VISUALISATION_OLCGE}
	)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message("### CMAKE build dir is ${CMAKE_SOURCE_DIR}")
	set(SUBPROJECTS_BUILD_DIR build/)
else()
	message("### CMAKE build dir is ${CMAKE_BINARY_DIR}")
	set(SUBPROJECTS_BUILD_DIR ./)
endif()

foreach(P IN LISTS PROJECTS)
	
	message("### " ${P} " folder added to project")
	add_subdirectory(${P} ${SUBPROJECTS_BUILD_DIR}${P})
endforeach()

#CMAKE build system tree initialisation END
