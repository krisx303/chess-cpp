#include "King.hpp"

Generator* King::movement = (new CompositeGenerator())
        ->addGenerator(new RotationGenerator(Vector2(1, 1), 1))
        ->addGenerator(new RotationGenerator(Vector2(1, 0), 1));
Generator* King::attack = King::movement;