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
        bool exist;
        for (auto v:p) {
            exist = false;
            for (auto k:this->pool) {
                if (v == k) {
                    exist = true;
                }
            }
            if (!exist) {
                this->pool.emplace_back(v);
            }
            std::cout << v << std::endl;
        }
    }

    //konstruktor kopiujacy
    TextPool::TextPool(const TextPool &tex) {
        for (auto v:tex.pool) {
            pool.emplace_back(v);
        }
    }

    //konstruktor przenoszący:
    TextPool::TextPool(TextPool &&tex) : pool{nullptr} {
        swap(pool, tex.pool);
    }

    //3. operator przypisania kopiujący
    TextPool &TextPool::operator=(const TextPool &tex) {
        if (this == &tex) {
            return *this;
        }

        std::vector<string>().swap(pool);


        for (auto v:tex.pool) {
            pool.emplace_back(v);
        }
    }

    //4. operator przypisania przenoszący
    TextPool &TextPool::operator=(TextPool &&tex) {
        if (this == &tex) {
            return *this;
        }

        std::vector<string>().swap(pool);

        for (auto v:tex.pool) {
            pool.emplace_back(v);
        }
    }

    TextPool::~TextPool() {

    }

    string_view TextPool::Intern(const string_view p) {
        std::cout << p << std::endl;
        string_view out;
        bool ok = false;
        for (auto v:this->pool) {
            if (p == v) {
                out = p;
                ok = true;
            }
        }
        if (!ok) {
            this->pool.emplace_back(p);
            out = this->pool.back();
        }
        return out;

    }

    size_t TextPool::StoredStringCount() const {
        size_t out;
        out = this->pool.size();
        for (auto v:this->pool) {
            std::cout << v << "  ";
        }
        std::cout << out << std::endl;
        return out;
    }


}