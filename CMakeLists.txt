cmake_minimum_required(VERSION 3.16)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
project(BICS_ABM)
add_subdirectory(igraph)

add_library(BICS_ABM_lib SHARED 
    BICS_ABM.h 
    BICS_ABM.cpp 
    )

add_executable(BICS_ABM 
    main.cpp 
    )


target_link_libraries(BICS_ABM_lib PUBLIC igraph)
target_link_libraries(BICS_ABM PUBLIC BICS_ABM_lib igraph)
