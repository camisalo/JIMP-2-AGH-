//
// Created by konrad on 18.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
#include <string>

namespace factoryMethod {

    template<class T>
    T Create();


    class MyType {
    public:
        MyType() {}

        std::string SayHello() {
            return "hello";
        }

    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
