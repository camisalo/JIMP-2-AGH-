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
        this->value = std::to_string(p);
    }

    JsonValue::JsonValue(double p) {
        this->value = std::to_string(p);
    }

    JsonValue::JsonValue(bool p) {
        this->value = std::to_string(p);
    }

    JsonValue::JsonValue(string
    p) {
    this->
    value = p;
}

JsonValue::JsonValue(vector<JsonValue> p) {

}

JsonValue::JsonValue(JsonValue *p) {

}

JsonValue::JsonValue(map<string, JsonValue> p) {

}

JsonValue::~JsonValue() {}

JsonValue::ValueByName(string
name){

}


string JsonValue::ToString() {

}


}
