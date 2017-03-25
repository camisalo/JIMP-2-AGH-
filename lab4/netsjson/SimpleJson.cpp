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

namespace nets {

    JsonValue::JsonValue(int p) {
        this->name[0] = "value";
        this->value[0] = std::to_string(p);
    }

    JsonValue::JsonValue(double p) {
        this->name[0] = "value";
        this->value[0] = std::to_string(p);
    }

    JsonValue::JsonValue(bool p) {
        this->name[0] = "value";
        this->value[0] = std::to_string(p);
    }

    JsonValue::JsonValue(string p) {
        this->name[0] = "name";
        this->value[0] = p;
    }

    JsonValue::JsonValue(vector<JsonValue> &p) {

    }

    JsonValue::JsonValue(JsonValue *p) {
        this->Json = p;
    }

    JsonValue::JsonValue(map<string, JsonValue> p) {

    }

    JsonValue::~JsonValue() {}

    std::experimental::optional<std::string> JsonValue::ValueByName(string name) {

    }


    string JsonValue::ToString() {

    }
}
