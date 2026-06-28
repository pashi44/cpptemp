add_library(libOne STATIC libOne.cpp PersonOne.cpp)

target_include_directories(libOne PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
