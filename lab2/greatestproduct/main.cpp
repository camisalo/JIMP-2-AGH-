//
// Created by konrad on 14.03.17.
//
#include "GreatestProduct.h"

#include <vector>
#include <iostream>

using namespace std;

int main(void) {


    vector<int> wektor;
    for (int i = 0; i < 10; ++i) {
        wektor.push_back(i * 3);
    }
    cout << wektor[3] << endl;
    cout << GreatestProduct(wektor, 10) << endl;
    return 0;

}