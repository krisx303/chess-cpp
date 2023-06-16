#pragma once

#include "Pawn.hpp"
#include "../movement/generators/CompositeGenerator.hpp"
#include "../movement/generators/RotationGenerator.hpp"

class Bishop : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    Bishop(const Vector2 &position, PlayerColor color) : Pawn(position, color, 2) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};