#pragma once

#include <vector>
#include <ostream>
#include "Test.h"

class TestComposite : public Test {
private:
    std::vector<Test*> tests;
    int success = 0;
public:
    explicit TestComposite(const char* string) : Test(string) {}

    void addTest(Test* test){
        tests.push_back(test);
    }

    TestResult test() override {
        TestResult result;
        for (const auto &item: tests){
            result = item->runTest();
            if(result == SUCCESS) success++;
        }
        if(success == tests.size()) return SUCCESS;
        return FAILED;
    }

    void print(std::ostream &os) const override {
        Test::print(os);
        os << std::endl;
        os << "Success: "<< success << " Failed: " << tests.size() - success << std::endl;
        for (const auto &item: tests) {
            os << '\t';
            item->print(os);
            os << '\n';
        }
    }
};