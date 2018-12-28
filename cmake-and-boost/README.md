# CMake and Boost

This is an example of using CMake's built in FindBoost to find boost and use it.

This is a pain in the ass to figure out so hopefully we never have to do that again!

```
# set BOOST_ROOT (so that CMake can find boos) 
set(BOOST_ROOT /usr/local/src/boost_1_69_0) 

# set BOOST_LIBRARYDIR - not sure this is necessary
set(BOOST_LIBRARYDIR /usr/local/src/boost_1_69_0/stage/lib)

# find boost and get a handle on the program_options lib
FIND_PACKAGE( Boost 1.69 COMPONENTS program_options REQUIRED )

# Boost_INCLUDE_DIR is populated by FIND_PACKAGE and gets you Boost's single header libs. No need to do anything more than this to use any of those, I think.
include_directories(${Boost_INCLUDE_DIR})

# may not be necessary?
link_directories(${Boost_LIBRARY_DIR})

add_executable(main hello.cpp)

# use link libraries for the compiled ones
target_link_libraries(main LINK_PUBLIC ${Boost_LIBRARIES} )

# use include_directories for the single header ones
target_include_directories(main PUBLIC ${Boost_INCLUDE_DIR} )
```

