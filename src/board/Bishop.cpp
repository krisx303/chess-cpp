#include "Bishop.hpp"

Generator* Bishop::movement = new RotationGenerator(Vector2(1, 1), -1);
Generator* Bishop::attack = Bishop::movement;