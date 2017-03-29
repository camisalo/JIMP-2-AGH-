//
// Created by konrad on 28.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <map>

using std::string;

namespace nets {
    class View {
    public:
        View(string p);

        ~View();

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        string szablon;
    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
