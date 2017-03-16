//
// Created by konrad on 15.03.17.
//

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>

#include "TinyUrl.h"

using std::cout;
using std::endl;

std::unique_ptr<TinyUrlCodec> Init() {


    return 0;
}

void tinyurl::NextHash(std::array<char, 6> *state) {

    std::array<char, 6> *git;
    *git = {'a', 'b', 'v', 'c', 'c', 'f'};


    for (int i = 0; i < state->size(); ++i) {
        cout << state + i << endl;

    }
    cout << endl << state << endl;
}

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {


}


std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

}
