# file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/**/*.hpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
add_library(thre INTERFACE)

target_include_directories(thre INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
