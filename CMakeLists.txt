cmake_minimum_required(VERSION 3.14)

project(executor C CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

# Enable Testing
include(CTest)
enable_testing()

add_subdirectory(deps)

# Target: executor
file(GLOB all_srcs CMAKE_CONFIGURE_DEPENDS
    src/*.cc
    src/*.c
)

add_library(executor ${all_srcs})

target_include_directories(executor 
  PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(executor
  INTERFACE
    alert_intf
    clean_intf
)

# Target: executor_test

file(GLOB all_tests CMAKE_CONFIGURE_DEPENDS
    test/*.cc
    test/*.c
)

add_executable(executor_test ${all_tests})

target_include_directories(executor_test 
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/test
)

target_link_libraries(executor_test 
  PRIVATE
    executor
    gtest
    gtest_main
)

add_test(NAME executor_test COMMAND executor_test)
