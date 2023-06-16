#pragma once

#include "Test.h"
#include "TestComposite.h"
#include "UnitTest.h"
#include "../src/movement/generators/SingleVectorGenerator.hpp"

using std::cout;
using std::endl;

TestResult zeroRadiusSGIsAlreadyEnded() {
    SingleVectorGenerator generator(Vector2(1, 0), 0);
    if(generator.hasEnded())
        return SUCCESS;
    return FAILED;
}

TestResult zeroRadiusSGIsEndedAfterReset() {
    SingleVectorGenerator generator(Vector2(1, 0), 0);
    generator.reset();
    if(generator.hasEnded())
        return SUCCESS;
    return FAILED;
}

TestResult zeroRadiusSGIsEndedAfterSkipping() {
    SingleVectorGenerator generator(Vector2(1, 0), 0);
    if(generator.skipToNextGenerator()){
        return FAILED;
    }
    return SUCCESS;
}

TestResult infRadiusSGIsNotEndedOnStart() {
    SingleVectorGenerator generator(Vector2(1, 0), -1);
    if(generator.hasEnded())
        return FAILED;
    return SUCCESS;
}

TestResult infRadiusSGIsEndedAfterSkipping() {
    SingleVectorGenerator generator(Vector2(1, 0), -1);
    if(!generator.skipToNextGenerator())
        return FAILED;
    if(generator.hasEnded())
        return SUCCESS;
    return FAILED;
}

TestResult infRadiusSGGeneratesPositionsUntilSkip() {
    SingleVectorGenerator generator(Vector2(1, 0), -1);
    for(int i = 1; i < 5;i++){
        if(generator.hasEnded())
            return FAILED;
        Vector2 position = generator.getNextMovePosition();
        Vector2 vector2(i, 0);
        if(position != vector2)
            return FAILED;
    }
    generator.skipToNextGenerator();
    if(generator.hasEnded())
        return SUCCESS;
    return FAILED;
}

TestResult infRadiusSGIsNotEndedAfterReset() {
    SingleVectorGenerator generator(Vector2(1, 0), -1);
    generator.skipToNextGenerator();
    generator.reset();
    if(generator.hasEnded())
        return FAILED;
    return SUCCESS;
}

class SingleVectorGeneratorTest : public TestComposite {
private:
public:
    explicit SingleVectorGeneratorTest() : TestComposite("Single Vector Generator Test") {}

    void beforeTest() override {
        addTest(new UnitTest(zeroRadiusSGIsAlreadyEnded, "Zero radius is ended on start"));
        addTest(new UnitTest(zeroRadiusSGIsEndedAfterReset, "Zero radius is ended after reset"));
        addTest(new UnitTest(zeroRadiusSGIsEndedAfterSkipping, "Zero radius is ended after skipping"));
        addTest(new UnitTest(infRadiusSGIsNotEndedOnStart, "Infinity radius is not ended on start"));
        addTest(new UnitTest(infRadiusSGIsEndedAfterSkipping, "Infinity radius is ended after skipping"));
        addTest(new UnitTest(infRadiusSGGeneratesPositionsUntilSkip, "Infinity radius generates positions until skip"));
        addTest(new UnitTest(infRadiusSGIsNotEndedAfterReset, "Infinity radius is ended after reset"));
    }
};