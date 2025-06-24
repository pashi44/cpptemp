add_library(stlcont INTERFACE
    include/StlOne.hpp)
    # PersonOne.cpp)

target_include_directories(stlcont  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)