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
        string a, b;
        if (p == 0)
            this->value.emplace_back("");
        else {
            a = std::to_string(p);
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != '0')
                    b += a[i];
            }
        }
        this->value.emplace_back(b);
    }

    JsonValue::JsonValue(bool p) {
        if (p)
            this->value.emplace_back("true");
        else
            this->value.emplace_back("false");
    }

    JsonValue::JsonValue(string p) {
        string a;
        a += "\"" + p + "\"";
        this->value.emplace_back(a);
    }

    JsonValue::JsonValue(vector<JsonValue> p) {
        for (auto v:p) {
            this->value.emplace_back(v);
        }
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
