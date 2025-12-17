file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(ite INTERFACE)
target_sources(ite INTERFACE ${HEADER_FILES})

target_include_directories(ite INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(ite INTERFACE thre)
