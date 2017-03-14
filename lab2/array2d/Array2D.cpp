//
// Created by konrad on 11.03.17.
//

#include "Array2D.h"

#include <iostream>

using namespace std;

int **Array2D(int n_rows, int n_columns){
    if (n_rows==0 || n_columns==0){
        std::cout << "bad_array_new_length" << std::endl;
        return nullptr;
    }
    std::cout << endl;
    int ** tab = new int * [n_rows];
    for (int i=0; i<n_rows; ++i){
        tab[i] = new int [n_columns];
        for (int j=0; j < n_columns; ++j){
            tab[i][j] = j + i * n_columns + 1;
        }
    }
    return tab;
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0; n_rows > i; ++i){
        delete [] array[i];
    }
    delete [] array;
}