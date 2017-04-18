//
// Created by konrad on 30.03.17.
//

#include <vector>
#include <memory>
#include <iostream>

#include "Matrix.h"

using ::std::string;
using std::cout;
using std::endl;

namespace algebra {

    Matrix::Matrix() : rows{0}, columns{0} {
        mat = nullptr;
    }

    Matrix::Matrix(int row, int col) : rows{row}, columns{col} {

        mat = new std::complex<double> *[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new std::complex<double>[columns];
        }
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
        cout << "rowki = " << rows << "kolumny = " << columns << endl;
        int i = 0, j = 0;

        mat = new std::complex<double> *[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new std::complex<double>[columns];
        }

        for (auto v:value) {

            for (auto p:v) {
                mat[i][j] = p.;
                cout << ">>>>>" << mat[i][j] << endl;
                j++;
            }
            i++;
        }

    }


    Matrix::Matrix(const Matrix &Old) {
        rows = Old.rows;
        columns = Old.columns;
        mat = Old.mat;
    }

    Matrix::~Matrix() {

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

    Matrix Matrix::Div(const Matrix &p) const {

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