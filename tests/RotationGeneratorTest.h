#pragma once

#include "Test.h"
#include "TestComposite.h"
#include "UnitTest.h"
#include "../src/movement/generators/RotationGenerator.hpp"

using std::cout;
using std::endl;

TestResult zeroRadiusRG() {

}

class RotationGeneratorTest : public TestComposite {
private:
public:
    explicit RotationGeneratorTest() : TestComposite("Rotation Generator Test") {}

    void beforeTest() override {
        addTest(new UnitTest(zeroRadiusRG, "Zero radius is ended on start"));
    }
};