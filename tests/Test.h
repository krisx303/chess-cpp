#pragma once

#include <string>
#include <ostream>

using std::string;

enum TestResult {
    INCOMPLETE,
    SUCCESS,
    FAILED
};


std::ostream &operator<<(std::ostream &os, TestResult result) {
    switch (result) {
        case INCOMPLETE:
            os << "INCOMPL";
            break;
        case SUCCESS:
            os << "SUCCESS";
            break;
        case FAILED:
            os << "FAILED!";
            break;
    }
    return os;
}

class Test {
    private:
        string testName_;
        TestResult result_ = INCOMPLETE;
        virtual void beforeTest(){};
        virtual void afterTest(){};
        virtual TestResult test() = 0;

public:
    explicit Test(const char *testName): testName_(testName){}
    explicit Test(string& testName): testName_(testName){}
    virtual ~Test() = default;

    TestResult runTest() {
        beforeTest();
        this->result_ = test();
        afterTest();
        return this->result_;
    }

    virtual void print(std::ostream& os) const {
        os << result_ << ": ";
        os << testName_;
    }

    friend std::ostream &operator<<(std::ostream &os, const Test &test) {
        test.print(os);
        return os;
    }
};