cmake_minimum_required(VERSION 3.3)
project(Test)

# enable C++11 standard,set the other flags used during the project compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lboost_system")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#Bring the headers, such as Student.h into the project
#include_directories(include)

#Can manually add the sources using the set command as follows:
# set(SOURCE_FILES src/main.cpp)
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCE_FILES "src/*.cpp")

#add_executable(myexec src/module1/module1.cpp src/module2/module2.cpp src/main.cpp)
#add_executable(mytest test1.cpp)
add_executable(redis-cli ${SOURCE_FILES})