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

std::unique_ptr<SmartTree> CreateLeaf(int value) {

}

std::unique_ptr<SmartTree>
datastructures::InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {

}

std::unique_ptr<SmartTree>
datastructures::InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {

}

void datastructures::PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {

}

std::string datastructures::DumpTree(const std::unique_ptr<SmartTree> &tree) {

}

std::unique_ptr<SmartTree> datastructures::RestoreTree(const std::string &tree) {

}