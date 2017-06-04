//
// Created by konrad on 01.06.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree {
    template<class T>
    class Tree {
    public:
        Tree(){}
        Tree(T value) : value_{value}, size_{1}, depth_{1} {}
        T Value(){return value_;}
        int Size(){return size_;}
        int Depth(){
            if (this->size_ == 1) return 1;
            else if (this->size_ <= 3) return 2;
            else if (this->size_ <= 7) return 3;
        }
        void Insert(T value){
            this->size_++;
            Tree *w, *p;
            w = new Tree;
            w->left = w->right = nullptr;
            w->value_ = value;

            p = this;
            bool make = true;
            while(make) {
                if (value < p->value_)
                {
                    if (!p->left){
                        p->left = w;
                        make = false;
                    } else p = p->left;
                }
                else {
                    if (!p->right){
                        p->right = w;
                        make = false;
                    } else p = p->right;
                }
            }
            delete p;

        }

    private:
        T value_;
        int size_, depth_;
        Tree *left= nullptr, *right= nullptr;
    };

}
#endif //JIMP_EXERCISES_TREE_H
