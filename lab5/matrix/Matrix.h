//
// Created by konrad on 30.03.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <complex>

namespace algebra {

    class Matrix {
    public:

        Matrix();

        Matrix(const char *text);

        Matrix(const Matrix &tex);       //1. konstruktor kopiujący
        ~Matrix();


        std::string Print() const;


        Add(const Matrix &p) const;

        Sub(const Matrix &p) const;

        Mul(const Matrix &p) const;


        size_t Size() const;


    private:
        int rows, columns;
        std::complex<double> **mat;

    };

}
#endif //JIMP_EXERCISES_MATRIX_H
