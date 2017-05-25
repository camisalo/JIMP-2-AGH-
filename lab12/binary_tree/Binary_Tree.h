//
// Created by konrad on 25.05.17.
//

#ifndef JIMP_EXERCISES_BINARY_TREE_H
#define JIMP_EXERCISES_BINARY_TREE_H

#include <iostream>

using namespace std;

namespace binary_tree {

    template<class T>
    class Tree {
    public:
        Tree(T key) : key_{key} {}

        void AddNode(T key) {
            bool ok = true;
            if (childL_ == nullptr) {
                childL_->SetKey(key);
                ok = false;
            } else if (childR_ == nullptr) {
                childR_ = Tree{key};
                ok = false;
            }

            if (ok) {
                childL_->AddNode(key);
            }

        }

        void SetKey(T key) {
            key_ = key;
        }

        void BFS() {
            Tree root = this;
            while (root.childL_ == nullptr || root.childR_ == nullptr) {
                std::cout << childL_
            }
        }

    private:

        T key_;
        Tree *childL_ = nullptr;
        Tree *childR_ = nullptr;
    };
};


#endif //JIMP_EXERCISES_BINARY_TREE_H
