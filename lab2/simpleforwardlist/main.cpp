//
// Created by konrad on 14.03.17.
//

#include "SimpleForwardList.h"

int main(void){

    ForwardList * head = CreateNode(10);
    head->next = CreateNode(15);
    head->next->next = CreateNode(20);

    DestroyList(head->next->next);

    return 0;
}