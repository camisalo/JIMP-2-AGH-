//
// Created by konrad on 30.03.17.
//

#include "Matrix.h"

using ::std::string;

namespace algebra {

    Matrix::Matrix() {
        rows = 0;
        columns = 0;
        mat = nullptr;
    }

    Matrix::Matrix(int row, int col) {
        rows = row;
        columns = col;
        mat = nullptr;
    }


    Matrix::Matrix(const char *text) {
        string p;
        for (int i = 0; text[i] != '\0'; ++i) {

            p += text[i];
        }
    }


    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> value) {
        rows = (int) value.size();
        columns = (int) value.begin()->size();
        int i = 0;
        for (auto v:value) {

        }

    }


    Matrix::Matrix(const Matrix &Old) {
        this->rows = Old.rows;
        this->columns = Old.columns;
        this->mat = Old.mat;
    }

    Matrix::~Matrix() {
        delete[] mat;
    }


    Matrix Matrix::Add(const Matrix &p) const {
        for (int i = 0; i < columns; ++i) {
            for (int j = 0; j < rows; ++j) {

            }
        }
    }

    Matrix Matrix::Sub(const Matrix &p) const {

    }

    Matrix Matrix::Mul(const Matrix &p) const {

    }

    Matrix Matrix::Pow(int power) const {

    }

    std::string Matrix::Print() const {


    }

    std::pair<size_t, size_t> Matrix::Size() const {
        size_t p[2];
        p[0] = (size_t) rows;
        p[1] = (size_t) columns;
    }


}