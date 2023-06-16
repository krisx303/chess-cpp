#pragma once

#include "Pawn.hpp"
#include "../movement/generators/CompositeGenerator.hpp"
#include "../movement/generators/RotationGenerator.hpp"

class King : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    King(const Vector2 &position, PlayerColor color) : Pawn(position, color, 0) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};