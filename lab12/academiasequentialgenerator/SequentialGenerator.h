//
// Created by konrad on 01.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

namespace academia {
    template<class IdType, class CounterType>
    class SequentialIdGenerator {
    public:
        SequentialIdGenerator():counter_(0){};

        SequentialIdGenerator(const CounterType &counter) : counter_(counter) {};

        IdType NextValue(void);

    private:
        CounterType counter_;
    };

    template<class IdType, class CounterType>
    IdType SequentialIdGenerator<IdType, CounterType>::NextValue(void){
        CounterType tmp = counter_;
        ++counter_;
        return IdType(tmp);
    }
}

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
