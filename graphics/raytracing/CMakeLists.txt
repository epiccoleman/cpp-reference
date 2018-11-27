cmake_minimum_required(VERSION 2.6)
project(Raytracer)

add_library(Vec3 Vec3.cpp)
add_library(Ray Ray.cpp)
add_library(Hitable INTERFACE)
add_library(Sphere INTERFACE)
add_executable(Raytracer main.cpp)
TARGET_LINK_LIBRARIES(Raytracer Sphere Ray Vec3)

add_executable(RaytracerTest SphereTest.cpp Vec3Test.cpp RayTest.cpp testMain.cpp)
TARGET_LINK_LIBRARIES(RaytracerTest Sphere Ray Vec3 gtest pthread)
