#pragma once

#include "PlayerColor.hpp"
#include "../movement/generators/Generator.hpp"
#include <iostream>

class Pawn {
private:
    Vector2 position_;
    PlayerColor color_;

public:
    explicit Pawn(const Vector2 &position, PlayerColor color) : position_(position), color_(color) {}

    Vector2 getPosition() const { return position_; }

    PlayerColor getColor() const { return color_; }

    virtual Generator *getMovementGenerator() = 0;

    virtual Generator *getAttackGenerator() = 0;
};
