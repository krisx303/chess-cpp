#include "Rook.hpp"

Generator* Rook::movement = new RotationGenerator(Vector2(0, 1), -1);
Generator* Rook::attack = Rook::movement;