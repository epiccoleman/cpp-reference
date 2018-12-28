cmake_minimum_required(VERSION 2.8)
set(BOOST_ROOT /usr/local/src/boost_1_69_0)
#set(Boost_INCLUDE_DIR ${BOOST_ROOT})
set(BOOST_LIBRARYDIR /usr/local/src/boost_1_69_0/stage/lib)

FIND_PACKAGE( Boost 1.69 COMPONENTS program_options REQUIRED )
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(main hello.cpp)
target_link_libraries(main LINK_PUBLIC ${Boost_LIBRARIES} )
target_include_directories(main PUBLIC ${Boost_INCLUDE_DIR} )
