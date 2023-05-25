#pragma once

#include "Generator.hpp"
#include "RotationGenerator.hpp"
#include <vector>
#include <memory>

using std::vector;

class CompositeGenerator : public Generator {
private:
    vector<Generator *> generators;
    int index = 0;


public:

    ~CompositeGenerator() override {
        while (!generators.empty()) {
            generators.pop_back();
        }
    }

    bool hasEnded() override {
        return Generator::hasEnded() || (generators.size() >= index-1 && generators[generators.size() - 1]->hasEnded());
    }

    Vector2 getNextMovePosition() override {
        if (generators[index]->hasEnded()) {
            index++;
        }
        return generators[index]->getNextMovePosition();
    }

    bool skipToNextGenerator() override {
        if (generators[index]->skipToNextGenerator()) {
            index++;
            if(index == generators.size()) {
                Generator::setEnded();
                setEnded();
            }
            return true;
        }
        return false;
    }

    CompositeGenerator * addGenerator(Generator *generator) {
        generators.push_back(generator);
        return this;
    }

    void reset() override {
        index = 0;
        for (const auto &item: generators) {
            item->reset();
        }
        Generator::reset();
    }

};