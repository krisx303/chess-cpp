#pragma once

#include "Pawn.hpp"
#include "../movement/generators/CompositeGenerator.hpp"
#include "../movement/generators/RotationGenerator.hpp"

class Queen : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    Queen(const Vector2 &position, PlayerColor color) : Pawn(position, color, 1) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};