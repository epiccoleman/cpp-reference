cmake_minimum_required(VERSION 2.6)
project(Raytracer)

add_library(Vec3 Vec3.cpp)
add_executable(RaytracerTest Vec3Test.cpp)
TARGET_LINK_LIBRARIES(RaytracerTest Vec3 gtest pthread)
