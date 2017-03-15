//
// Created by konrad on 11.03.17.
//

#include "Polybius.h"

#include <iostream>
#include <fstream>
#include <algorithm>

std::string PolybiusCrypt(std::string message) {
    char szachownica[][5] = {{'a','b','c','d','e'},
                             {'f','g','h','i','k'},
                             {'l','m','n','o','p'},
                             {'q','r','s','t','u'},
                             {'v','w','x','y','z'}};

    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    std::string szyfr;
    for (int wyr=0; message.size() > wyr; ++wyr){
        for (int i=0; i<5; ++i){
            for (int j=0; j<5; ++j){
                if (message[wyr] == szachownica[i][j]){
                    szyfr += std::to_string(i+1);
                    szyfr += std::to_string(j+1);
                } else if (message[wyr] == 'j' && i==1 && j==3){
                    szyfr += std::to_string(i+1);
                    szyfr += std::to_string(j+1);
                }
            }
        }
    }
    return szyfr;
}

std::string PolybiusDecrypt(std::string crypted){
    char szachownica[][5] = {{'a','b','c','d','e'},
                             {'f','g','h','i','k'},
                             {'l','m','n','o','p'},
                             {'q','r','s','t','u'},
                             {'v','w','x','y','z'}};
    int a,b;
    std::string decrypted,k1,k2;
    std::string::size_type sz;
    for (int i=0; i < crypted.size(); ++++i){
        k1 = crypted[i];
        k2 = crypted[i+1];
        a = std::stoi(k1);
        b = std::stoi(k2);
        decrypted += szachownica[a-1][b-1];

    }
    return decrypted;
}