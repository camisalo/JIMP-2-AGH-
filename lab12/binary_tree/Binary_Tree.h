//
// Created by konrad on 25.05.17.
//

#ifndef JIMP_EXERCISES_BINARY_TREE_H
#define JIMP_EXERCISES_BINARY_TREE_H


namespace binary_tree {

    template<class T>


    class Tree {
    public:
        Tree(int key) : key_{key} {}

        void AddNode(T key) {

        }

    private:

        T key_;
        Tree *childL_;
        Tree *childR_;
    };
};


#endif //JIMP_EXERCISES_BINARY_TREE_H
