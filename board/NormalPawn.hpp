#pragma once

#include "Pawn.hpp"
#include "../movement/generators/SingleVectorGenerator.hpp"
#include "../movement/generators/CompositeGenerator.hpp"

class NormalPawn : public Pawn {
private:
    static Generator *movement;
    static Generator *attack;

public:
    NormalPawn(const Vector2 &position, PlayerColor color) : Pawn(position, color) {}

    Generator *getMovementGenerator() override {
        return movement;
    }

    Generator *getAttackGenerator() override {
        return attack;
    }
};

Generator* NormalPawn::movement = new SingleVectorGenerator(Vector2(0, 1), 1);
Generator* NormalPawn::attack = (new CompositeGenerator())
        ->addGenerator(new SingleVectorGenerator(Vector2(-1, 1), 1))
        ->addGenerator(new SingleVectorGenerator(Vector2(1, 1), 1));