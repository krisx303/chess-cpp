#pragma once

#include "SingleVectorGenerator.hpp"

class RotationGenerator : public Generator {
private:
    Vector2 direction_;
    int radius_;
    SingleVectorGenerator *generator;
    int counter = 0;

public:

    explicit RotationGenerator(const Vector2 &direction, int radius) : direction_(direction), radius_(radius) {
        generator = new SingleVectorGenerator(direction, radius);
    }

    ~RotationGenerator() override {
        delete generator;
    }

    bool hasEnded() override {
        if (counter == 3 && generator->hasEnded()) {
            setEnded();
        }
        return Generator::hasEnded();
    }

    Vector2 getNextMovePosition() override {
        if (generator->hasEnded()) {
            skipGenerator();
        }
        return generator->getNextMovePosition();;
    }

    void skipGenerator() {
        counter++;
        if (counter == 4) {
            setEnded();
        }
        direction_ = direction_.rotate();
        delete generator;
        generator = new SingleVectorGenerator(direction_, radius_);
    }

    bool skipToNextGenerator() override {
        if (radius_ == -1) {
            skipGenerator();
            return true;
        }
        return false;
    }

    void reset() override {
        counter = 0;
        delete generator;
        direction_ = direction_.rotate();
        generator = new SingleVectorGenerator(direction_, radius_);
        Generator::reset();
    }

    void print(std::ostream &os) const override {
        os << "RotationGenerator[" << direction_ << ", " << counter << ", " << radius_ << "]";
    }
};