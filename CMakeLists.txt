cmake_minimum_required(VERSION 3.20)

#top level sollution to all included projects
project(VisualAlgorithms)


set(REAL_WORLD_ALGORITHMS "Real_World_Algorithms")
set(Q_OBJECT_PICKER_TEST "QObjectPicker_test")

set(PROJECTS 
    ${REAL_WORLD_ALGORITHMS}
	${Q_OBJECT_PICKER_TEST}
	)

foreach(P IN LISTS PROJECTS)
	# Here and later all messages generated in this project build system starts with ###
	message("### " ${P} " folder added to project")
	add_subdirectory(${P} cmake/build/${P})
endforeach()
