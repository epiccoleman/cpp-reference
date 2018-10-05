add_library(Character Character.cpp)
add_executable(CharacterUnitTests CharacterUnitTests.cpp)
add_test(CharacterUnitTests)

TARGET_LINK_LIBRARIES(CharacterUnitTests Character gtest pthread)
