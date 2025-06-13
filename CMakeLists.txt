cmake_minimum_required(VERSION 3.10)
project(MyTestProject)

# Find GTest and GMock
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES test.c test.cpp)

# Create the executable
add_executable(MyTests ${SOURCE_FILES})

# Link GTest and GMock
target_link_libraries(MyTests ${GTEST_LIBRARIES} ${GMOCK_INCLUDE_DIRS} pthread)