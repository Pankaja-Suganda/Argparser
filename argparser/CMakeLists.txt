set(CMAKE_CXX_STANDARD 17)

# folder including
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create a static library for the "argparser" module
add_library(argparser STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argparser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argument.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argflag.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argint.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argdouble.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argstring.cpp
)
