#include "NormalPawn.hpp"

Generator* NormalPawn::movement = new SingleVectorGenerator(Vector2(0, 1), 1);
Generator* NormalPawn::movementFirstMove = new SingleVectorGenerator(Vector2(0, 1), 2);
Generator* NormalPawn::attack = (new CompositeGenerator())
        ->addGenerator(new SingleVectorGenerator(Vector2(-1, 1), 1))
        ->addGenerator(new SingleVectorGenerator(Vector2(1, 1), 1));