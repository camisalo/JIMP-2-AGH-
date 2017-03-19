//
// Created by konrad on 15.03.17.
//
#include <ostream>
#include <string>
#include <memory>
#include <iostream>

#include "SmartTree.h"

using std::cout;
using std::endl;
using datastructures::SmartTree;

std::unique_ptr<SmartTree> datastructures::CreateLeaf(int value) {
    std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
    leaf->value = value;
    return leaf;
}

std::unique_ptr<SmartTree>
datastructures::InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
    tree->left = std::move(left_subtree);
    return tree;
}

std::unique_ptr<SmartTree>
datastructures::InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
    tree->right = std::move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
    if (unique_ptr) {
        PrintTreeInOrder(unique_ptr->left, out);
        *out << unique_ptr->value << ", ";
        PrintTreeInOrder(unique_ptr->right, out);
    }
}

std::string datastructures::DumpTree(const std::unique_ptr<SmartTree> &tree) {
    std::string dump;
    dump += "[";
    dump += std::to_string(tree->value);
    dump += Print(tree->left);
    dump += Print(tree->right);

    dump += "]";
    return dump;
}

std::string datastructures::Print(const std::unique_ptr<SmartTree> &tree) {
    std::string dump;
    dump += " [";
    if (tree) {
        dump += std::to_string(tree->value);
        dump += Print(tree->left);
        dump += Print(tree->right);
    } else {
        dump += "none";
    }
    dump += "]";
    return dump;
}

std::unique_ptr<SmartTree> datastructures::RestoreTree(const std::string &tree) {

}

