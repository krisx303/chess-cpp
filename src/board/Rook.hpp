#pragma once

#include "Pawn.hpp"
#include "../movement/generators/RotationGenerator.hpp"

class Rook : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    Rook(const Vector2 &position, PlayerColor color) : Pawn(position, color, 4) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};