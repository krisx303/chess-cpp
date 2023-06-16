#pragma once

#include "Pawn.hpp"
#include "../movement/generators/SingleVectorGenerator.hpp"
#include "../movement/generators/CompositeGenerator.hpp"

class NormalPawn : public Pawn {
private:
    static Generator *movement;
    static Generator *movementFirstMove;
    static Generator *attack;
    bool firstMove = false;

public:
    NormalPawn(const Vector2 &position, PlayerColor color) : Pawn(position, color, 5) {}

    Generator *getMovementGenerator() override {
        if(!firstMove)
            return movementFirstMove;
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }

    void changeState() {
        firstMove = true;
    }
};