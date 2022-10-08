set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(01 p1.cpp)
add_executable(02 p2.cpp)
configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)
configure_file(input_test ${CMAKE_CURRENT_BINARY_DIR}/input_test)