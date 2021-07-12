#add olc pixel game engine header from github

function(OLCGEFetch TARGET_TO_INCLUDE)
    include(FetchContent)

    FetchContent_Declare(
    olcge_git_header
    GIT_REPOSITORY https://github.com/OneLoneCoder/olcPixelGameEngine.git
    GIT_TAG master
    )

    FetchContent_MakeAvailable(olcge_git_header)

    set(OLC_INCLUDE ${VisualAlgorithms_SOURCE_DIR}/include/olcPixelGameEngine/)

    file(
    GLOB OLC_INCLUDE_FILES
    ${olcge_git_header_SOURCE_DIR}/olcPixelGameEngine.h
    )
    
    file(
         COPY ${OLC_INCLUDE_FILES}
         DESTINATION ${OLC_INCLUDE}
         )

    target_include_directories(${TARGET_TO_INCLUDE} PUBLIC ${OLC_INCLUDE})
endfunction()