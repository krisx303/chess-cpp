#pragma once

#include "Pawn.hpp"
#include "../movement/generators/CompositeGenerator.hpp"
#include "../movement/generators/RotationGenerator.hpp"

class Knight : public Pawn {
private:
    static Generator* createMovementGenerator();
    static Generator* createAttackGenerator();

public:
    Knight(const Vector2& position, PlayerColor color) : Pawn(position, color, 3) {}

    Generator* getMovementGenerator() override;
    Generator* getAttackGenerator() override;
};