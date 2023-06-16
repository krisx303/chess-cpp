#pragma once

#include "PlayerColor.hpp"
#include "../movement/generators/Generator.hpp"
#include <iostream>

class Pawn {
private:
    Vector2 position_;
    PlayerColor color_;
    int typeID_;

public:
    explicit Pawn(const Vector2 &position, PlayerColor color, int typeID) : position_(position), color_(color), typeID_(typeID) {}

    virtual ~Pawn() = default;

    Vector2 getPosition() const { return position_; }

    PlayerColor getColor() const { return color_; }

    int getType() const {return typeID_;}

    virtual Generator *getMovementGenerator() = 0;

    virtual Generator *getAttackGenerator() = 0;

    void setPosition(Vector2 &pos) {
        position_ = pos;
    }
};
