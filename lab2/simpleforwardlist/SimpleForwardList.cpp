//
// Created by konrad on 14.03.17.
//

#include "SimpleForwardList.h"
#include <iostream>


ForwardList * CreateNode(int value) {
    ForwardList *lista = new ForwardList;
    lista->liczba = value;
    std::cout << value << std::endl;
    return lista;
}


void DestroyList(struct ForwardList *list) {
    delete list;
    std::cout << "Zniszczone" << std::endl;
}