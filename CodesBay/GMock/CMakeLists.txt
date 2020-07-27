cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#include_directories(${GMOCK_INCLUDE_DIRS}) 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(Gmock1 test.cpp)
target_link_libraries(Gmock1 ${GTEST_LIBRARIES} pthread)
