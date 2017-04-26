//
// Created by konrad on 20.04.17.
//

#include "ArrayFill.h"


namespace arrays {

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    UniformFill::UniformFill(int value) : value_{value} {}

    int UniformFill::Value(int index) const {
        return value_;
    }

    IncrementalFill::IncrementalFill(int n) {
        value_ = n;
        a = 0;
        b = 1;
    }

    IncrementalFill::IncrementalFill(int a, int b) : a{a}, b{b} {
        value_ = 0;
    }

    int IncrementalFill::Value(int index) const {
        return a + (value_ + index) * b;
    }


    SquaredFill::SquaredFill(int n) {
        value_ = n;
    }

    SquaredFill::SquaredFill(int a, int b) : a{a}, b{b} {
        value_ = 0;
    }

    int SquaredFill::Value(int index) const {
        return a * ((index) * (index)) + b;
    }


    RandomFill::RandomFill(int n) {
        value_ = n;
    }

    RandomFill::RandomFill(int a, int b) : a{a}, b{b} {
        value_ = 0;
    }

    int RandomFill::Value(int index) const {

    }

}