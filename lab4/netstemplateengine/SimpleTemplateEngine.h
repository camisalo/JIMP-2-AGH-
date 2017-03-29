//
// Created by konrad on 28.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

namespace nets {
    class View {
        View();

        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
