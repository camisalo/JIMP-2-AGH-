//
// Created by konrad on 30.03.17.
//

#include "Matrix.h"

namespace algebra {

    Matrix::Matrix() {
        rows = 0;
        columns = 0;
    }

    Matrix::Matrix(const char *text) {
        for (int i = 0; text[i] != '\0'; ++i) {

        }
    }

    Matrix::Matrix(const Matrix &tex) {

    }

    Matrix::~Matrix() {

    }


    Matrix::Add(const Matrix &p) const {

    }

    Matrix::Sub(const Matrix &p) const {

    }

    Matrix::Mul(const Matrix &p) const {

    }


    std::string Matrix::Print() const {


    }

    size_t Matrix::Size() const {

    }


}