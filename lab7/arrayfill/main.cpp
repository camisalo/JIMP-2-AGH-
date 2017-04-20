//
// Created by konrad on 20.04.17.
//

#include "ArrayFill.h"


int main(void) {
    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);
}