#pragma once

#include "../Vector2.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "NormalPawn.hpp"
#include <vector>

using std::vector;
using namespace std;

#define BOARD_SIZE 8

class Board {
private:
    Pawn *board[BOARD_SIZE][BOARD_SIZE]{};
    PlayerColor colorCheck = NONE;
    King *whiteKing, *blackKing;
    Pawn *killedPawn, *movedPawn;
    Vector2 movedPosition;

    PlayerColor oppositeColor(PlayerColor color) {
        if (color == WHITE)
            return BLACK;
        return WHITE;
    }

    bool kingCheckGenerator(Pawn *pawn) {
        vector<Vector2> attacks;
        addPositionsFromAttack(&attacks, pawn);
        return any_of(attacks.begin(), attacks.end(), [&](const Vector2 &attack) {
            return getPawnAtPosition(attack)->getType() == pawn->getType();
        });
    }

    void addPositionsFromMovement(vector<Vector2> *positions, Pawn *pawn) {
        Generator *movement = pawn->getMovementGenerator();
        while (!movement->hasEnded()) {
            Vector2 move = movement->getNextMovePosition();
            if (pawn->getColor() == WHITE)
                move = move.opposite();
            move = pawn->getPosition() + move;
            if (isOutsideArea(move) || isOccupied(move)) {
                movement->skipToNextGenerator();
                continue;
            }
            positions->push_back(move);
        }
        movement->reset();
    }

    void addPositionsFromAttack(vector<Vector2> *positions, Pawn *pawn) {
        Generator *attack = pawn->getAttackGenerator();
        while (!attack->hasEnded()) {
            Vector2 move = attack->getNextMovePosition();
            if (pawn->getColor() == WHITE)
                move = move.opposite();
            move = pawn->getPosition() + move;
            if (isOutsideArea(move) || isOccupied(move, pawn->getColor())) {
                attack->skipToNextGenerator();
                continue;
            }
            if (isOccupied(move, oppositeColor(pawn->getColor()))) {
                positions->push_back(move);
                attack->skipToNextGenerator();
            }
        }
        attack->reset();
    }

    vector<Vector2> getMovementsFromGenerator(Pawn *pawn) {
        vector<Vector2> positions;
        addPositionsFromMovement(&positions, pawn);
        addPositionsFromAttack(&positions, pawn);
        return positions;
    }

    class Iterator {
    private:
        Pawn **current;

    public:
        explicit Iterator(Pawn **start) : current(start) {}

        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }

        Pawn *operator*() const {
            return *current;
        }

        Iterator &operator++() {
            //TODO repair iterator to avoid checking if nullptr
            ++current;
            return *this;
        }
    };

public:
    ~Board() {
        for (auto &i: board) {
            for (auto &j: i) {
                delete j;
            }
        }
    }

    bool kingCheck(King *king) {
        Queen queen(king->getPosition(), king->getColor());
        Knight knight(king->getPosition(), king->getColor());
        Rook rook(king->getPosition(), king->getColor());
        Bishop bishop(king->getPosition(), king->getColor());
        NormalPawn pawn(king->getPosition(), king->getColor());
        if(kingCheckGenerator(&queen))
            return true;
        if(kingCheckGenerator(&knight))
            return true;
        if(kingCheckGenerator(&rook))
            return true;
        if(kingCheckGenerator(&bishop))
            return true;
        if(kingCheckGenerator(&pawn))
            return true;
        return false;
    }

    PlayerColor kingCheck() {
        if (kingCheck(whiteKing))
            return WHITE;
        if (kingCheck(blackKing))
            return BLACK;
        return NONE;
    }

    bool isOccupied(const Vector2 &position) {
        return board[position.getX()][position.getY()] != nullptr;
    }

    bool isOccupied(const Vector2 &position, PlayerColor color) {
        Pawn *pawn = board[position.getX()][position.getY()];
        return pawn != nullptr && pawn->getColor() == color;
    }

    static bool isOutsideArea(Vector2 &position) {
        return position.getX() < 0 || position.getX() >= BOARD_SIZE || position.getY() < 0 ||
               position.getY() >= BOARD_SIZE;
    }

    void addPawn(const Vector2 &position, Pawn *pawn) {
        board[position.getX()][position.getY()] = pawn;
    }

    void addKingPawn(King *king) {
        if (king->getColor() == WHITE)
            whiteKing = king;
        else
            blackKing = king;
        addPawn(king);
    }

    void addPawn(Pawn *pawn) {
        const Vector2 &position = pawn->getPosition();
        addPawn(position, pawn);
    }

    Pawn *getPawnAtPosition(const Vector2 &position) {
        return board[position.getX()][position.getY()];
    }


    Iterator begin() {
        return Iterator(&board[0][0]);
    }

    Iterator end() {
        return Iterator(&board[BOARD_SIZE][0]);
    }

    vector<Vector2> getMovementsFromPawn(Pawn *pawn) {
        return getMovementsFromGenerator(pawn);
    }

    void movePawn(Pawn *pawn, Vector2 &toPos) {
        int x = pawn->getPosition().getX();
        int y = pawn->getPosition().getY();
        killedPawn = board[toPos.getX()][toPos.getY()];
        board[x][y] = nullptr;
        movedPawn = pawn;
        movedPosition = pawn->getPosition();
        pawn->setPosition(toPos);
        addPawn(toPos, pawn);
    }

    PlayerColor getCheckColor() {
        return colorCheck;
    }

    void setCheckColor(PlayerColor color) {
        this->colorCheck = color;
    }

    void backMove() {
        int x = movedPosition.getX();
        int y = movedPosition.getY();
        board[movedPawn->getPosition().getX()][movedPawn->getPosition().getY()] = nullptr;
        board[x][y] = movedPawn;
        movedPawn->setPosition(movedPosition);
        if(killedPawn != nullptr) {
            addPawn(killedPawn->getPosition(), killedPawn);
        }
        killedPawn = nullptr;
    }
};