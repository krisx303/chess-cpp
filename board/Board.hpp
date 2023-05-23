#pragma once

#include "../Vector2.hpp"
#include "Pawn.hpp"
#include <vector>

using std::vector;

#define BOARD_SIZE 8

class Board {

private:
    Pawn* board[BOARD_SIZE][BOARD_SIZE]{};
    vector<Pawn*> reserve;

public:
    ~Board(){
        for (auto & i : board){
            for (auto & j : i){
                delete j;
            }
        }
    }

    bool isOccupied(const Vector2 &position, PlayerColor color) {
        Pawn* pawn = board[position.getX()][position.getY()];
        return pawn != nullptr && pawn->getColor() == color;
    }

    bool isOutsideArea(Vector2 &position) const {
        return position.getX() < 0 || position.getX() >= 8 || position.getY() < 0 || position.getY() >= 8;
    }

    void addPawn(const Vector2& position, Pawn* pawn) {
        board[position.getX()][position.getY()] = pawn;
    }

    void addPawn(Pawn* pawn){
        const Vector2& position = pawn->getPosition();
        addPawn(position, pawn);
    }

    Pawn *getPawnAtPosition(const Vector2& position) {
        return board[position.getX()][position.getY()];
    }
};