#pragma once

#include "Pawn.hpp"
#include "../movement/generators/CompositeGenerator.hpp"

class Knight : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    Knight(const Vector2 &position, PlayerColor color) : Pawn(position, color) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};

Generator* Knight::movement = (new CompositeGenerator())
        ->addGenerator(new RotationGenerator(Vector2(2, 1), 1))
        ->addGenerator(new RotationGenerator(Vector2(2, -1), 1));
Generator* Knight::attack = Knight::movement;