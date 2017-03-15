//
// Created by konrad on 14.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

struct ForwardList //
{
    int liczba;
    struct ForwardList* next;
};


ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
