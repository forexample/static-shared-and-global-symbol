cmake_minimum_required(VERSION 3.9)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.22.0.tar.gz"
    SHA1 "f91a01c6e0eb53b1dc55a6442cd93580db91da07"
)

project(foo)

include_directories("${CMAKE_CURRENT_LIST_DIR}")

add_library(A STATIC A.hpp A.cpp)
set_target_properties(A PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

add_library(B SHARED B.hpp B.cpp)
target_link_libraries(B PUBLIC A)

add_executable(C C.cpp)
target_link_libraries(C PUBLIC B)

hunter_add_package(gauze)
find_package(gauze CONFIG REQUIRED)

enable_testing()
gauze_add_test(NAME C COMMAND C)
