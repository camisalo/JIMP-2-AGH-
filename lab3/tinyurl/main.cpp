//
// Created by konrad on 15.03.17.
//

#include "TinyUrl.h"

using std::cout;
using std::endl;
using tinyurl::TinyUrlCodec;

int main(void) {

    TinyUrlCodec a;
    a.url = "dasdas";
    std::unique_ptr<TinyUrlCodec> struktura = std::make_unique<TinyUrlCodec>();

    struktura->url;
    std::string url = "https://github.com.";
    struktura->hash = "000000";
    struktura->url = url;

    tinyurl::Encode(url, &struktura);

    return 0;
}