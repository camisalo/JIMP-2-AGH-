//
// Created by konrad on 14.03.17.
//

#include "XorCypherBreaker.h"
#include <algorithm>
#include <iostream>

using std::find;
using std::vector;
using std::string;
using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary) {


    int j, k, number, znalezione, naj = 0;
    string decrypted_s;
    string key = "";
    int decrypted[cryptogram.size()];
    int keyloger[] = {'a', 'a', 'a'};

    for (int a = 0; a < 26; ++a) {
        keyloger[0] = 'a' + a;
        for (int b = 0; b < 26; ++b) {
            keyloger[1] = 'a' + b;
            for (int c = 0; c < 26; ++c) {
                keyloger[2] = 'a' + c;
                j = 0;
                k = 0;

                for (auto i:cryptogram) {
                    decrypted[j] = keyloger[k] xor (int) i;
                    decrypted_s += (char) decrypted[j];
                    j++;
                    if ((k + 1) % 3 == 0)
                        k = 0;
                    else
                        k++;
                }
                number = 0;
                for (auto dic:dictionary) {
                    znalezione = decrypted_s.find(dic);
                    if (znalezione >= 0) {
                        number++;
                        if (number > 20 && number > naj) {
                            key = (char) keyloger[0];
                            key += (char) keyloger[1];
                            key += (char) keyloger[2];
                            naj = number;
                        }
                    }
                }
                decrypted_s = "";
            }
        }
    }
    return key;
}