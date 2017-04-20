//
// Created by konrad on 20.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>

namespace arrays {


    class ArrayFill {
    public:
        virtual int Value(int index) const = 0;
    };


    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value);

        virtual int Value(int index) const override;

    private:
        int value_;
    };


    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int n);

        IncrementalFill(int a, int b);

        virtual int Value(int index) const override;

    private:
        int value_, a, b;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int n);

        SquaredFill(int a, int b);

        virtual int Value(int index) const override;

    private:
        int value_, a, b;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(int n);

        RandomFill(int a, int b);

        virtual int Value(int index) const override;

    private:
        int value_;
        int a, b;


    };

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v);


}


#endif //JIMP_EXERCISES_ARRAYFILL_H
