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

    TextPool::TextPool(std::initializer_list<string> p) {
        for (auto v:p) {
            this->pool.emplace_back(v);
        }

    }

    string_view TextPool::Intern(const string_view p) {
        std::cout << p << std::endl;
        string_view out;
        for (auto v:this->pool) {
            if (p == v) {
                out = p;
            }
        }

    }

    size_t TextPool::StoredStringCount() const {
        size_t out;
        out = this->pool.size();
        return out;
    }


}