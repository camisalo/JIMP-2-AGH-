//
// Created by konrad on 30.03.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <complex>
#include <initializer_list>
#include <vector>


namespace algebra {

    class Matrix {
    public:

        Matrix();

        Matrix(int row, int col);

        Matrix(const char *text);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> value);


        Matrix(const Matrix &tex);       //1. konstruktor kopiujący
        ~Matrix();


        Matrix Add(const Matrix &p) const;

        Matrix Sub(const Matrix &p) const;

        Matrix Mul(const Matrix &p) const;

        Matrix Pow(int power) const;

        std::string Print() const;

        std::pair<size_t, size_t> Size() const;


    private:
        int rows, columns;
        std::complex<double> **mat;

    };

}
#endif //JIMP_EXERCISES_MATRIX_H
