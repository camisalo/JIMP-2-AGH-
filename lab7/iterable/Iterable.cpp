//
// Created by konrad on 22.04.17.
//

#include "Iterable.h"

namespace utility {


    ZipperIterator::ZipperIterator() {

    }

    bool ZipperIterator::NotEquals(const ZipperIterator &zip) {
        bool ok = true;

    }

    void IterableIterator::Begin() {

    }

    void IterableIterator::End() {

    }


    Enumerate::Enumerate() {}

    Enumerate::Enumerate(std::vector<std::string> init) {
        int i = 1;
        for (auto v:init) {
            iterator.emplace_back(i, v);
        }
    }


}