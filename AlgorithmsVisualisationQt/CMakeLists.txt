message("### algorithms_visualisation BEGIN")
cmake_minimum_required(VERSION 3.20)

#building evironment for Algorithms Visualisation
project(algorithms_visualisation)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CURRENT_PROJECT_COMPONENTS Widgets Gui Core 3DCore 3DExtras 3DRender)

include(${VisualAlgorithms_SOURCE_DIR}/cmake/QtModulePrepare.cmake)
QtModulePrepare(CURRENT_PROJECT_COMPONENTS)

add_executable(${PROJECT_NAME} 
	AlgorithmsVisualisationQt.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

include(${VisualAlgorithms_SOURCE_DIR}/cmake/MessageProperty.cmake)

message_property(${PROJECT_NAME} CXX_STANDART)
message_property(CMAKE CXX_STANDART)
message_property(CMAKE CXX_COMPILER_ID)
message_property(CMAKE CXX_COMPILER_VERSION)

set(DIRECTORIES_WITH_LIBS 
    /3d/
    /main/
    /properties/
    /scenes/)

foreach(DIR_LIBS_ IN LISTS DIRECTORIES_WITH_LIBS)
  message(" ### Searching directory: " ${DIR_LIBS_})
    file(
        GLOB IN_FOLDER_CPP_FILES
        ${algorithms_visualisation_SOURCE_DIR}${DIR_LIBS_}*.cpp
     )

    foreach(CPP_FILE_PATH IN LISTS IN_FOLDER_CPP_FILES)

       cmake_path(
         GET CPP_FILE_PATH
         STEM CPP_FILE
         )

       add_library(
         ${CPP_FILE}
         ${CPP_FILE_PATH}
         )

       target_compile_features(${CPP_FILE} PUBLIC cxx_std_17)

       message(" ### ${CPP_FILE} added as library from ${CPP_FILE_PATH}")

       target_include_directories(
          ${PROJECT_NAME} PUBLIC 
          .${DIR_LIBS_}
          )

    endforeach()

endforeach()

#linkage dependencies order important
SET(LIBRARIES_LIST 
             main_window   
             graph_menu 
             sorting_menu
             viewport_window
             scene_entities_common_graph
             scene_properties_common_graph
             qlinemesh                        
             property_camera                    
             property_camera_controller         
             property_light                     
             property_material                  
             property_mesh                      
             property_transform      
             color_picker                       
             component_states           
             xyz_picker                         
             )
#
 
foreach(LIBS IN LISTS LIBRARIES_LIST)
    message(" ### Library from list: " ${LIBS})

    #All libs linkled with all libs. May be need to set dependencies individually.
    #Not work because wrong order.
    foreach(LIBS_ IN LISTS LIBRARIES_LIST)
        if(NOT ${LIBS} STREQUAL ${LIBS_})
            target_link_libraries(${LIBS} ${LIBS_})
            message(" ### ${LIBS} linked with ${LIBS_} ")
       endif()
    endforeach()

    foreach(COMP IN LISTS CURRENT_PROJECT_COMPONENTS)
    	set(CURRENT_COMPONENT_NAME ${QT_PERFIX}${COMP} )
        target_link_libraries(${LIBS} ${CURRENT_COMPONENT_NAME})
        message(" ### ${LIBS} linked with  ${CURRENT_COMPONENT_NAME} ")
    endforeach()

    

    target_include_directories(
       ${LIBS} PUBLIC 
       utilities
       properties
       3d
       scenes
       main
       )

    
endforeach()


target_link_libraries(${PROJECT_NAME} main_window)

 foreach(COMP IN LISTS CURRENT_PROJECT_COMPONENTS)
    	set(CURRENT_COMPONENT_NAME ${QT_PERFIX}${COMP} )
        target_link_libraries(${PROJECT_NAME} ${CURRENT_COMPONENT_NAME})
        message(" ### ${PROJECT_NAME} linked with  ${CURRENT_COMPONENT_NAME} ")
 endforeach()


 target_include_directories(
    ${PROJECT_NAME} PUBLIC 
       utilities
    )
    #Project deployment BEGIN
if(WIN32)
set(FULL_PATH_TO_EXECUTABLE $<TARGET_FILE:${PROJECT_NAME}>)
message(" ### FULL_PATH_TO_EXECUTABLE is ${FULL_PATH_TO_EXECUTABLE} ")



message(" ### Deployment for Windows. Looking for windeployqt.exe")
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_PREFIX_PATH}/bin/windeployqt.exe 
					${FULL_PATH_TO_EXECUTABLE}
					--no-quick-import 
					--no-translations 
)
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/settings)

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
   ${algorithms_visualisation_SOURCE_DIR}/settings  $<TARGET_FILE_DIR:${PROJECT_NAME}>/settings)

   elseif(LINUX)

      message(" ### Deployment for Linux. In develop.")

   endif(WIN32)
#Project deployment END
message("### algorithms_visualisation END")