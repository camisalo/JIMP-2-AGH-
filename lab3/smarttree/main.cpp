//
// Created by konrad on 15.03.17.
//
#include <iostream>

#include "SmartTree.h"

int main() {

    auto tree = datastructures::RestoreTree("[99 [100 [1234 [none] [none]] [4321 [none] [none]]] "
                                    "[88 [897 [none] [none]] [761 [none] [none]]]]");
    std::cout << datastructures::DumpTree(tree);
    return 0;
}