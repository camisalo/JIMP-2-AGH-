//
// Created by konrad on 27.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>
#include <string>

namespace academia {

    class Pesel {
    public:
        Pesel(const std::string init);
    };

    class AcademiaDataValidationError : public std::runtime_error {
    public:
        AcademiaDataValidationError(std::string i);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(std::string i, int k);
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(std::string i, int k);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(std::string i);
    };


}

#endif //JIMP_EXERCISES_PESEL_H
