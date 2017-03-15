//
// Created by konrad on 11.03.17.
//
#include "Polybius.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){

    ifstream myfile;
    myfile.open("plik-tekst.txt");

    char word[64];
    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl << endl;

    while(myfile >> word)
        cout << word;
    myfile.close();
    
    
    //////////////////////////////////
    string wiadomosc = "wiadomosc do zaszyfrowania";
    string zaszyfrowana = PolybiusCrypt(wiadomosc);
    cout << zaszyfrowana << endl;

    cout << endl <<endl;
    string odszyfrowana = PolybiusDecrypt(zaszyfrowana);
    cout << odszyfrowana << endl;
    /////////////////////////////////
    

    ofstream dopliku ("plik-szyfr.txt", ios_base::in | ios_base::app);

    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl;

    dopliku << "Tekst zapisany w pliku" << endl;

    dopliku.close();

    return 0;
}