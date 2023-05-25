#include "Vector2.hpp"

std::ostream &operator<<(std::ostream &os, const Vector2 &dt) {
    os << "Vector2[" << dt.getX() << ", " << dt.getY() << ']';
    return os;
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {x_ + other.x_, y_ + other.y_};
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {x_ - other.x_, y_ - other.y_};
}

Vector2 Vector2::operator*(int scalar) const {
    return {x_ * scalar, y_ * scalar};
}

bool Vector2::operator==(const Vector2 &other) const {
    return x_ == other.x_ && y_ == other.y_;
}

bool Vector2::operator!=(const Vector2& other) const {
    return !(*this == other);
}

Vector2 Vector2::opposite() const {
    return {-x_, -y_};
}

Vector2 Vector2::rotate() const {
    return {-y_, x_};
}
