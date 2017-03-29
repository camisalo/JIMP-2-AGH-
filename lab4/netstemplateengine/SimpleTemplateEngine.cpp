//
// Created by konrad on 28.03.17.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


namespace nets {


    View::View(string p) {
        this->szablon = p;
    }

    View::~View() {}

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        string zwracane, hash;
        bool ok;
        int j;
        std::cout << this->szablon << std::endl;
        for (int i = 0; i < this->szablon.length(); ++i) {
            if (this->szablon[i] == '{' && this->szablon[i + 1] == '{') {
                j = i + 2;
                ok = true;
                hash = "";
                while (this->szablon[j] != '}' || this->szablon[j + 1] != '}') {
                    if (this->szablon[j] == '{') {
                        hash = "";
                        ok = false;
                        break;
                    }
                    hash += this->szablon[j];
                    j++;
                }
                cout << hash << endl;
                if (model.find(hash) != model.end() && ok) {
                    zwracane += model.find(hash)->second;
                }
                if (ok)
                    i = j + 2;
            }
            if (this->szablon[i] != '\0')
                zwracane += this->szablon[i];
        }
        return zwracane;
    }
}