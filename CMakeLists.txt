project(pb_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(pb_test pb_main.cpp)

install(TARGETS pb_test RUNTIME DESTINATION bin)


