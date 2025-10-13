add_library(dsa    STATIC  "include/VectorOne.hpp" )
target_include_directories(dsa   INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(dsa   PUBLIC  libOne)

