cmake_minimum_required(VERSION 2.6)
project(Evercraft)

add_library(Character Character.cpp)
add_executable(CharacterTest CharacterTest.cpp)
TARGET_LINK_LIBRARIES(CharacterTest Character gtest pthread)
add_test(CharacterTest CharacterTest)
