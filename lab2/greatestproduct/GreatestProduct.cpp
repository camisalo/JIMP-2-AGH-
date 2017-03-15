//
// Created by konrad on 14.03.17.
//


#include <vector>


#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k) {
    int iloczyn, naj = 0;
    for (int v:numbers) {
        for (int w:numbers) {
            iloczyn = v * w;
            if (iloczyn > naj) {
                naj = iloczyn;
            }
        }
    }
    return naj;
}
