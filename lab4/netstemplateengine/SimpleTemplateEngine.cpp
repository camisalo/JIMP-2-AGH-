//
// Created by konrad on 28.03.17.
//

#include "SimpleTemplateEngine.h"


namespace nets {

    class View {
        View();

        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    };


}