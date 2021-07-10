cmake_minimum_required(VERSION 3.20)

#top level sollution to all included projects
project(VisualAlgorithms)

#System initialisation BEGIN
if(WIN32)
	message("### System in WIN32")
else()
	message(FATAL_ERROR " ### System NOT WIN32. Not acceptable now. Linux will be addeded here.")
	return()
endif(WIN32)
#System initialisation END

#Qt initialisation BEGIN

option(_QT_5_PATH "Path to Qt5 current compiler folder like 'C:\\Qt\\5.15.2\\msvc2019_64\\'" OFF)

string(COMPARE EQUAL "${_QT_5_PATH}" "OFF" zero_check)
	if(zero_check)
		message(FATAL_ERROR "### -D_QT_5_PATH is empty! Set _QT_5_PATH on cmake.exe call like: \"cmake . -D_QT_5_PATH=C:\\\\Qt\\\\5.15.2\\\\msvc2019_64\\\\\"")
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

set(PROJECTS 
    ${REAL_WORLD_ALGORITHMS}
	${Q_OBJECT_PICKER_TEST}
	${Q_LINE_MESH_TEST}
	)

foreach(P IN LISTS PROJECTS)
	# Here and later all messages generated in this project build system starts with ###
	message("### " ${P} " folder added to project")
	add_subdirectory(${P} cmake/build/${P})
endforeach()

#CMAKE build system tree initialisation END
