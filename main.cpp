#include <iostream>
#include <list>
#include "Vector2.hpp"
#include "board/Board.hpp"
#include "board/NormalPawn.hpp"
#include "board/Rook.hpp"
#include "board/Knight.hpp"

using std::cout;
using std::endl;

class Parent {
public:
    virtual std::list<int> &getList() {
        static std::list<int> myList;
        return myList;
    }

    void addToList(int x) {
        getList().push_back(x);
    }
};

class Child : public Parent {
public:
    std::list<int> &getList() override {
        static std::list<int> myList;
        return myList;
    }
};

void fulfillBoard(Board& board) {
    for(int i = 0;i<BOARD_SIZE;++i) {
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
    auto *generator = board.getPawnAtPosition(Vector2(1, 0))->getMovementGenerator();

    while (!generator->hasEnded()) {
        Vector2 vector = Vector2(1, 0) + generator->getNextMovePosition();
        if (board.isOutsideArea(vector) || board.isOccupied(vector, PlayerColor::WHITE)) {
            generator->skipToNextGenerator();
            continue;
        }
        cout << vector << endl;
    }

    generator->reset();

    return 0;
}
