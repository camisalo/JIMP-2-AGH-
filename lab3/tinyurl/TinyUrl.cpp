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
using tinyurl::TinyUrlCodec;

std::unique_ptr<TinyUrlCodec> tinyurl::Init() {
    std::unique_ptr<TinyUrlCodec> url = std::make_unique<TinyUrlCodec>();

    cout << endl << "Zalokowano pamiec dla TinyUrlCodec" << endl;
    url->hash = "000000";
    return url;
}

void tinyurl::NextHash(std::array<char, 6> *state) {
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::array<char, 6> hash = *state;
    int j, i = 5;
    bool ok = false;

    while (!ok) {
        if (hash[i] == 'z') {
            state->_M_elems[i] = alphabet[0];
        } else {
            j = 0;
            while (state->_M_elems[i] != alphabet[j] && j < alphabet.size()) {
                j++;
            }
            state->_M_elems[i] = alphabet[j + 1];
            ok = true;
        }
        i--;
    }
}

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {



    cout << endl << endl << endl << url << endl;


}


std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

    codec->hash;



}
