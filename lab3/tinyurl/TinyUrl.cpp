//
// Created by konrad on 15.03.17.
//

#include <utility>
#include <string>
#include <array>
#include <memory>

#include "TinyUrl.h"

std::unique_ptr<TinyUrlCodec> Init();

void NextHash(std::arrray<char, 6> *state);

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);