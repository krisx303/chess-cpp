#pragma once

#include <iosfwd>
#include <iostream>
#include <string>

class Vector2 {
private:
    int x_, y_;
public:
    Vector2(int x, int y) : x_{x}, y_{y} {};

    Vector2(const Vector2 &src) : Vector2(src.x_, src.y_) {};

    int getX() const { return x_; }

    int getY() const { return y_; }

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &dt);

    Vector2 operator+(const Vector2 &other) const;

    Vector2 operator-(const Vector2 &other) const;

    Vector2 operator*(int scalar) const;

    bool operator==(const Vector2 &other) const;

    bool operator!=(const Vector2 &other) const;

    Vector2 oposite() const{
        return {-x_, -y_};
    }


    Vector2 rotate() const;
};
