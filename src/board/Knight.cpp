#include "Knight.hpp"

Generator* Knight::createMovementGenerator() {
    return (new CompositeGenerator())
            ->addGenerator(new RotationGenerator(Vector2(2, 1), 1))
            ->addGenerator(new RotationGenerator(Vector2(2, -1), 1));
}

Generator* Knight::createAttackGenerator() {
    return createMovementGenerator();
}

Generator* Knight::getMovementGenerator() {
    static Generator* movement = createMovementGenerator();
    return movement;
}

Generator* Knight::getAttackGenerator() {
    static Generator* attack = createAttackGenerator();
    return attack;
}