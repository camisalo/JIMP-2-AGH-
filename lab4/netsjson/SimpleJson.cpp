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
using ::std::literals::operator ""s;


namespace nets {

    JsonValue::JsonValue(int p) {
        this->value = std::to_string(p);
    }

    JsonValue::JsonValue(double p) {
        string a, b = "";
        int k = 0;
        if (p == 0)
            this->value = "0";
        else {
            a = std::to_string(p);
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != '0')
                    k = i;
            }
            for (int i = 0; i <= k; ++i) {
                b += a[i];
            }
        }
        this->value = b;
    }

    JsonValue::JsonValue(bool p) {
        if (p)
            this->value = "true";
        else
            this->value = "false";
    }

    JsonValue::JsonValue(const char p[]) {
        string a = p;
        this->value = p;
    }


    JsonValue::JsonValue(string &p) {
        string a;
        a += "\"" + p + "\"";
        this->value = a;
    }

    JsonValue::JsonValue(vector<JsonValue> &p) {
        string a;
        a += "[";
        for (int i = 0; i < p.size(); ++i) {
            if (i == 0)
                a += p[i].value;
            else
                a += ", " + p[i].value;
        }
        a += "]";
        this->value = a;
    }

    JsonValue::JsonValue(map<string, JsonValue> &p) {
        for (auto n:p) {
            this->mapa.emplace("\"" + n.first + "\"", n.second);
        }
    }

    JsonValue::~JsonValue() {}

    string JsonValue::ToString() const {

        return this->value;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(string &name) const {
        std::map<string, JsonValue>::iterator k = this->mapa.find(name);
        if (k != this->mapa.end())
            return std::experimental::make_optional(mapa.find(name)->second);
        else
            return {};
    }

}
