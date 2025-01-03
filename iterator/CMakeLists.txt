# file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/**/*.hpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
add_library(ite INTERFACE)

target_include_directories(ite INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(ite INTERFACE thre)