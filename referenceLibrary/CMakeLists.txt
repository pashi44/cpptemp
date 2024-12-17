add_library(reflib SHARED Reference.cpp)
target_include_directories(reflib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)