//
// Created by konrad on 30.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <string>
#include <vector>
#include <initializer_list>
#include <experimental/string_view>
#include <set>

using ::std::experimental::string_view;
using ::std::string;

namespace pool {

    class TextPool {
    public:

        TextPool(std::initializer_list<string> p);

        string_view Intern(const string_view p);

        size_t StoredStringCount() const;


    private:
        std::vector<string> pool;


    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
