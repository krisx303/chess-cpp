cmake_minimum_required(VERSION 3.23)
project(chess-tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(chess-tests tests.cpp Test.h SingleVectorGeneratorTest.h TestComposite.h UnitTest.h
        ../src/movement/generators/Generator.hpp ../src/movement/generators/SingleVectorGenerator.hpp
        ../src/Vector2.hpp ../src/Vector2.cpp RotationGeneratorTest.h
        ../src/movement/generators/RotationGenerator.hpp)

target_link_libraries(chess-tests)