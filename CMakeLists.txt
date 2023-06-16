cmake_minimum_required(VERSION 3.23)
project(chess)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)

add_executable(chess main.cpp src/Vector2.hpp src/Vector2.cpp src/movement/generators/Generator.hpp
        src/movement/generators/SingleVectorGenerator.hpp src/movement/generators/RotationGenerator.hpp
        src/movement/generators/CompositeGenerator.hpp src/board/Pawn.hpp
        src/board/NormalPawn.hpp src/board/Knight.hpp
        src/helpers/RenderHelper.hpp src/helpers/RenderHelper.cpp
        src/GlobalResources.hpp src/GlobalResources.cpp src/panels/GamePanel.hpp src/panels/GamePanel.cpp
        src/panels/Panel.cpp src/panels/Panel.hpp src/board/Board.hpp src/board/Rook.hpp src/board/PlayerColor.hpp
        src/board/Bishop.hpp src/board/Queen.hpp src/board/King.hpp src/board/Knight.cpp src/board/King.cpp
        src/board/Rook.cpp src/board/King.cpp src/board/NormalPawn.cpp src/board/Queen.cpp src/board/Bishop.cpp
        src/board/PlayerColor.cpp)

target_link_libraries(chess sfml-system sfml-window sfml-graphics sfml-audio)