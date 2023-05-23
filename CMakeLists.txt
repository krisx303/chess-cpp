cmake_minimum_required(VERSION 3.23)
project(chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(chess main.cpp Vector2.hpp Vector2.cpp movement/generators/Generator.hpp
        movement/generators/SingleVectorGenerator.hpp movement/generators/RotationGenerator.hpp
        movement/generators/CompositeGenerator.hpp board/Pawn.hpp
        board/NormalPawn.hpp board/Knight.hpp)
