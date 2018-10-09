cmake_minimum_required(VERSION 2.6)
project(Raytracer)

add_library(Vec3 Vec3.cpp)
add_executable(Raytracer main.cpp)
TARGET_LINK_LIBRARIES(Raytracer Vec3)

add_executable(RaytracerTest Vec3Test.cpp RayTest.cpp testMain.cpp)
TARGET_LINK_LIBRARIES(RaytracerTest Vec3 gtest pthread)
