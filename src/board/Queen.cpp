#include "Queen.hpp"

Generator* Queen::movement = (new CompositeGenerator())
        ->addGenerator(new SingleVectorGenerator(Vector2(0, 1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(1, 1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(0, 1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(1, -1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(0, -1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(1, 0), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(-1, -1), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(-1, 0), -1))
        ->addGenerator(new SingleVectorGenerator(Vector2(-1, 1), -1));
Generator* Queen::attack = Queen::movement;