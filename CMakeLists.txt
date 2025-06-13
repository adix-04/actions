# cmake_minimum_required(VERSION 3.10)
# project(MyTestProject)

# # Find GTest and GMock
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# set(SOURCE_FILES test.c test.cpp)

# # Create the executable
# add_executable(MyTests ${SOURCE_FILES})

# # Link GTest and GMock
# target_link_libraries(MyTests ${GTEST_LIBRARIES} ${GMOCK_INCLUDE_DIRS} pthread)

cmake_minimum_required(VERSION 3.10)
project(MyTests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()
set(SOURCE_FILES test.c test.cpp)
add_executable(MyTests ${SOURCE_FILES})
target_link_libraries(MyTests gtest_main)

include(GoogleTest)
gtest_discover_tests(MyTests)
