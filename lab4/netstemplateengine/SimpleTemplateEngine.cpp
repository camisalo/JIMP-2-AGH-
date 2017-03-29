//
// Created by konrad on 28.03.17.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>

using std::string;


namespace nets {


    View::View(string p) {

    }

    View::~View() {}

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::cout << this->szablon << std::endl;
        for (int i = 0; i < this->szablon.length(); ++i) {
            if (this->szablon[i] == '{' && this->szablon[i] == '{') {

            }
        }
    }
}