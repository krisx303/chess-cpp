#include <iostream>
#include <list>
#include "Vector2.hpp"
#include "board/Board.hpp"
#include "board/NormalPawn.hpp"
#include "board/Rook.hpp"
#include "board/Knight.hpp"

using std::cout;
using std::endl;


void fulfillBoard(Board &board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board.addPawn(new NormalPawn(Vector2(i, 1), PlayerColor::WHITE));
    }
    board.addPawn(new Rook(Vector2(0, 0), PlayerColor::WHITE));
    board.addPawn(new Rook(Vector2(7, 0), PlayerColor::WHITE));
    board.addPawn(new Knight(Vector2(1, 0), PlayerColor::WHITE));
    board.addPawn(new Knight(Vector2(6, 0), PlayerColor::WHITE));
}

int main() {
    Board board;
    fulfillBoard(board);
    auto positions = board.getAttacksFromPositions(Vector2(1, 1));

    for (const auto &item: positions)
        cout << item << endl;

    positions = board.getAttacksFromPositions(Vector2(0, 0));

    for (const auto &item: positions)
        cout << item << endl;

    return 0;
}
