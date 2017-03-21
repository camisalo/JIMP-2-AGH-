//
// Created by konrad on 16.03.17.
//


#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>

#include "MinimalTimeDifference.h"

using namespace std;

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    regex pattern{R"((\d{1,2}):(\d{2}))"};
    std::smatch matches;
    unsigned int suma = 0;
    if (regex_match(time_HH_MM, matches, pattern)) {
        cout << endl << "godziny: " << stoi(matches[1]) << endl;
        cout << "minuty: " << stoi(matches[2]) << endl;

        suma = stoi(matches[1]) * 60 + stoi(matches[2]);
    }
    cout << suma << endl;
    return suma;

}

unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    unsigned int czas[times.size()], i = 0, largest = 0, wynik = 0;
    for (auto v:times) {
        czas[i] = ToMinutes(v);
        i++;
    }


    for (int i = 0; i < times.size(); ++i) {
        for (int j = 0; j < times.size(); ++j) {
            wynik = 0;
            if (i != j) {
                wynik = abs(czas[i] - czas[j]);
            }

            if (wynik > 720) {
                wynik = 1440 - wynik;
            }
            if (largest < wynik) {
                largest = wynik;
            }

        }
    }
    cout << "wynik= " << largest << endl;
    return largest;

}