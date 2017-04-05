//
// Created by konrad on 30.03.17.
//

#include <string>
#include <vector>
#include <initializer_list>
#include <experimental/string_view>
#include <set>
#include <iostream>

#include "TextPool.h"

using std::experimental::string_view;
using std::string;

namespace pool {
    TextPool::TextPool() {}

    TextPool::TextPool(std::initializer_list<string> p) {
        chunks.insert(p);
    }

    //konstruktor przenoszący:
    TextPool::TextPool(TextPool &&tex) {
        swap(chunks, tex.chunks);
    }

    //4. operator przypisania przenoszący
    TextPool &TextPool::operator=(TextPool &&tex) {
        if (this == &tex) {
            return *this;
        }
        chunks.clear();
        for (auto v:tex.chunks) {
            chunks.insert(v);
        }
    }

    TextPool::~TextPool() {
    }

    string_view TextPool::Intern(const string &p) {
        if (chunks.find(p) != chunks.end()) {
            return *chunks.find(p);
        } else {
            chunks.insert(p);
            return *chunks.find(p);
        }
    }

    size_t TextPool::StoredStringCount() const {
        size_t out;
        out = chunks.size();
        return out;
    }
}