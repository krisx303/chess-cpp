#pragma once

#include "Test.h"

typedef TestResult (*TestFunction)();

class UnitTest : public Test {
    TestFunction testFunction;
public:
    UnitTest(TestFunction function, string testName): Test(testName), testFunction{function}{}

    TestResult test() override{
        return testFunction();
    }
};