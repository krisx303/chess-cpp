#pragma once

#include "Generator.hpp"

class SingleVectorGenerator : public Generator {
private:
    Vector2 direction_;
    int distance_;
    int curr_distance_;

public:
    explicit SingleVectorGenerator(const Vector2 &direction, int distance) : direction_(direction), distance_(distance),
                                                                             curr_distance_(0) {}

    ~SingleVectorGenerator() override = default;

    bool hasEnded() override {
        if (curr_distance_ == distance_) {
            setEnded();
        }
        return Generator::hasEnded();
    }

    Vector2 getNextMovePosition() override {
        this->curr_distance_++;
        return direction_ * curr_distance_;
    }

    bool skipToNextGenerator() override {
        setEnded();
        return distance_ == -1;
    }

    void reset() override {
        curr_distance_ = 0;
        Generator::setNotEnded();
        setNotEnded();
    }

    void print(std::ostream &os) const override {
        os << "SingleVectorGenerator[" << direction_ << ", " << distance_ << ", " << curr_distance_ << "]";
    }
};