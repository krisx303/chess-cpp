#pragma once

#include "../../Vector2.hpp"

class Generator {
private:
    bool end = false;
public:

    virtual ~Generator() = default;
    virtual bool hasEnded() { return end; };

    virtual Vector2 getNextMovePosition() = 0;

    virtual bool skipToNextGenerator() = 0;

    void setEnded() { end = true; }

    void setNotEnded() {end = false;}

    virtual void reset() {
        end = false;
    }
};