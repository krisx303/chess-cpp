#pragma once

#include "../Vector2.hpp"
#include "Pawn.hpp"
#include <vector>

using std::vector;
using namespace std;

#define BOARD_SIZE 8

class Board {

private:
    Pawn* board[BOARD_SIZE][BOARD_SIZE]{};
    vector<Pawn*> reserve;

    vector<Vector2> getMovementsFromGenerator(Generator* generator, const Vector2& position){
        vector<Vector2> positions;
        while (!generator->hasEnded()) {
            Vector2 vector = position + generator->getNextMovePosition();
            if (isOutsideArea(vector) || isOccupied(vector, PlayerColor::WHITE)) {
                generator->skipToNextGenerator();
                continue;
            }
            positions.push_back(vector);
        }
        generator->reset();
        return positions;
    }

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

    bool isOutsideArea(Vector2 &position) {
        return position.getX() < 0 || position.getX() >= BOARD_SIZE || position.getY() < 0 || position.getY() >= BOARD_SIZE;
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

    vector<Vector2> getMovementsFromPosition(const Vector2& position) {
        Pawn* pawn = getPawnAtPosition(position);
        Generator* generator = pawn->getMovementGenerator();
        return getMovementsFromGenerator(generator, position);
    }

    vector<Vector2> getAttacksFromPositions(const Vector2& position){
        Pawn* pawn = getPawnAtPosition(position);
        Generator* generator = pawn->getAttackGenerator();
        return getMovementsFromGenerator(generator, position);
    }
};