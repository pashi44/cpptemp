cmake_minimum_required(VERSION 3.20)
project(templates)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-O0  -g  -gdwarf-4 ")
set(CMAKE_CXX_DEBUG_FLAG "-lthread")
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CXX_FLAGS "-W")
set(CMAKE_C_FLAGS "-w")

file(GLOB SOURCES '*.cpp' '*.hpp')

add_subdirectory(thre)
add_subdirectory(library)
add_subdirectory(referenceLibrary)
add_subdirectory(iterator)

add_executable(TempOne "./TempOne.cpp")
target_link_libraries(TempOne PUBLIC libOne reflib thre ite)
target_link_libraries(TempOne INTERFACE Threads::Threads)