//
// Created by konrad on 30.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <string>
#include <list>
#include <initializer_list>
#include <experimental/string_view>
#include <set>
#include <iostream>

using ::std::experimental::string_view;
using ::std::string;

namespace pool {

    class TextPool {
    public:

        TextPool();

        TextPool(std::initializer_list<string> p);

        //1. konstruktor kopiujący
        TextPool(const TextPool &tex) = delete;

        //2. konstruktor przenoszący
        TextPool(TextPool &&tex);

        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &tex) = delete;

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&tex);


        ~TextPool();

        string_view Intern(const string &p);

        size_t StoredStringCount() const;


    private:
        std::set<std::string> chunks;


    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
