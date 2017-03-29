//
// Created by konrad on 21.03.17.
//

#include "SimpleUrl.h"


class SimpleUrl {


    std::string Login() const;
    std::string Host() const;
    std::string Path() const;
    uint16_t Port() const;
    std::string Scheme() const;
    std::string Query() const;
    std::string Fragment() const;
};

