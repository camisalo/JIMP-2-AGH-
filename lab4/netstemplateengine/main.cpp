//
// Created by konrad on 28.03.17.
//

#include "SimpleTemplateEngine.h"

#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main(void) {

    const auto p = std::make_unique<nets::View>("siema jestem sobie {{ktos}} i nazywkam sie Lalalaa.");


    std::unordered_map<string, string> por = {{"ktos", "Konrad"}};

    cout << p->Render(por) << endl;

    return 1;
}