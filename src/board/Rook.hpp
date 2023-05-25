#pragma once

#include "Pawn.hpp"
#include "../movement/generators/SingleVectorGenerator.hpp"
#include "../movement/generators/CompositeGenerator.hpp"

class Rook : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    Rook(const Vector2 &position, PlayerColor color) : Pawn(position, color) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};

Generator* Rook::movement = new RotationGenerator(Vector2(0, 1), -1);
Generator* Rook::attack = Rook::movement;