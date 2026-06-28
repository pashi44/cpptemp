cmake_minimum_required(VERSION 3.20)
project(templates)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-O0  -g  -gdwarf-4 ")
set(CMAKE_CXX_DEBUG_FLAG "-lthread")
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CXX_FLAGS "-W")
set(CMAKE_C_FLAGS "-w")

# set(CMAKE_CXX_COMPILER  /usr/lib/ccache/arm-none-eabi-g++)

file(GLOB SOURCES '*.cpp' '*.hpp')

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
find_package(Threads REQUIRED)      
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


endif()
add_subdirectory(thre)
add_subdirectory(library)
add_subdirectory(referenceLibrary)
add_subdirectory(iterator)

add_executable(TempOne   ${CMAKE_CURRENT_SOURCE_DIR}/src/TempOne.cpp)
target_link_libraries(TempOne PUBLIC libOne reflib thre ite)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(TempOne PUBLIC Threads::Threads)
endif()
