#add timedelay lib from github

function(TimedelayFetch TARGET_TO_INCLUDE)
    include(FetchContent)

    FetchContent_Declare(
    timedelay_git_master
    GIT_REPOSITORY https://github.com/ikvasir/timedelay.git
    GIT_TAG master
    )

    FetchContent_MakeAvailable(timedelay_git_master)

    set(TIMEDELAY_INCLUDE ${VisualAlgorithms_SOURCE_DIR}/include/timedelay/)

    file(
    GLOB TIMEDELAY_INCLUDE_FILES
    ${timedelay_git_master_SOURCE_DIR}/*.h
    ${timedelay_git_master_SOURCE_DIR}/*.cpp
    )
    
    file(
         COPY ${TIMEDELAY_INCLUDE_FILES}
         DESTINATION ${TIMEDELAY_INCLUDE}
         )
    
    target_include_directories(${TARGET_TO_INCLUDE} PUBLIC ${TIMEDELAY_INCLUDE})
endfunction()