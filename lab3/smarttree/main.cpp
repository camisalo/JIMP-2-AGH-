//
// Created by konrad on 15.03.17.
//
#include <iostream>

#include "SmartTree.h"
using datastructures::SmartTree;

int main() {
    std::unique_ptr<SmartTree> root;
    root = datastructures::CreateLeaf(99);
    root = InsertLeftChild(move(root), datastructures::CreateLeaf(100));
    root = InsertRightChild(move(root), datastructures::CreateLeaf(88));
    root->left = InsertLeftChild(move(root->left), datastructures::CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), datastructures::CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), datastructures::CreateLeaf(897));
    root->right = InsertRightChild(move(root->right), datastructures::CreateLeaf(761));


    std::string s = datastructures::DumpTree(root);
    std::cout << s << std::endl;
    return 0;
}