#include <iostream>
#include "Test.h"
#include "SingleVectorGeneratorTest.h"
#include "RotationGeneratorTest.h"

int main() {

    Test* test = new SingleVectorGeneratorTest();
    test->runTest();
    std::cout << *test;

    delete test;
    test = new RotationGeneratorTest();
    test->runTest();
    std::cout << *test;

    return 0;
}