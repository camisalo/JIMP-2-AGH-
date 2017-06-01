//
// Created by konrad on 01.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <map>
#include <chrono>

namespace profiling {
    template<class T>
    auto TimeRecorder(T t) {
        static std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
        auto result = t();
        std::chrono::duration<double, std::milli> elapsed = std::chrono::high_resolution_clock::now() - begin;
        return std::pair<decltype(result), double>(result, elapsed.count());
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
