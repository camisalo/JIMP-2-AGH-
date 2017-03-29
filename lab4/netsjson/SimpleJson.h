//
// Created by konrad on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <vector>
#include <map>
#include <experimental/optional>

using ::std::string;
using ::std::vector;
using ::std::map;

namespace nets {
    class JsonValue {
    public:
        JsonValue(int p);

        JsonValue(double p);

        JsonValue(bool p);

        JsonValue(const char p[]);

        JsonValue(string &p);

        JsonValue(vector<JsonValue> &p);

        JsonValue(map<string, JsonValue> &p);

        ~JsonValue();

        string ToString() const;

        std::experimental::optional<JsonValue> ValueByName(string name) const;

    private:
        std::string value;
        std::map<string, JsonValue> mapa;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
