#pragma once

#include <iostream>
#include <ostream>

class Vector2 {
private:
    int x_, y_;

public:
    // Constructor: Creates a Vector2 object with given x and y coordinates.
    Vector2(int x, int y) : x_{x}, y_{y} {}

    // Copy constructor: Creates a Vector2 object by copying another Vector2 object.
    Vector2(const Vector2 &src) : Vector2(src.x_, src.y_) {}

    // Getter function: Returns the x coordinate of the Vector2 object.
    int getX() const { return x_; }

    // Getter function: Returns the y coordinate of the Vector2 object.
    int getY() const { return y_; }

    // Overloaded stream insertion operator: Outputs the Vector2 object in the format "Vector2[x, y]".
    friend std::ostream &operator<<(std::ostream &os, const Vector2 &dt);

    // Adds two Vector2 objects and returns the result as a new Vector2 object.
    Vector2 operator+(const Vector2 &other) const;

    // Subtracts two Vector2 objects and returns the result as a new Vector2 object.
    Vector2 operator-(const Vector2 &other) const;

    // Multiplies the Vector2 object by a scalar value and returns the result as a new Vector2 object.
    Vector2 operator*(int scalar) const;

    // Checks if two Vector2 objects are equal.
    bool operator==(const Vector2 &other) const;

    // Checks if two Vector2 objects are not equal.
    bool operator!=(const Vector2 &other) const;

    // Function: Returns the vector with opposite direction (negated x and y coordinates).
    Vector2 opposite() const;

    // Function: Returns the vector rotated 90 degrees counter-clockwise.
    Vector2 rotate() const;
};