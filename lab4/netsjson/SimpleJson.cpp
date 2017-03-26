//
// Created by konrad on 25.03.17.
//

#include <string>
#include <vector>
#include <map>
#include <experimental/optional>


#include "SimpleJson.h"

using ::nets::JsonValue;
using ::std::string;
using ::std::vector;
using ::std::map;

namespace nets {

    JsonValue::JsonValue(int p) {
        this->value.emplace_back(std::to_string(p));
    }

    JsonValue::JsonValue(double p) {
        this->value.emplace_back(std::to_string(p));
    }

    JsonValue::JsonValue(bool p) {
        this->value.emplace_back(std::to_string(p));
    }

    JsonValue::JsonValue(string p) {
        this->value.emplace_back(p);
    }

    JsonValue::JsonValue(vector<JsonValue> &p) {


    }

    JsonValue::JsonValue(map<string, JsonValue> p) {
        for (auto n:p) {
            this->mapa.emplace(n.first, n.second);
        }
    }

    JsonValue::~JsonValue() {}

    string JsonValue::ToString() const {
        string out;
        for (int i = 0; i < this->value.size(); ++i) {
            if (value.size() == 1)
                out += this->value[i];
            else
                out += " ," + this->value[i];
        }
        return out;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(string name) const {
        string a;
        int i = 0;
        JsonValue k = this->mapa.find(name)->second;
        return k;
    }

}
