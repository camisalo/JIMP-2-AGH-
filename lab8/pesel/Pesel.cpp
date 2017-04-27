//
// Created by konrad on 27.04.17.
//

#include "Pesel.h"

namespace academia {


    Pesel::Pesel(const std::string init) {
        if (init.size() != 11) {
            throw InvalidPeselLength(init, (int) init.size());
        }
        int A[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
        int suma = 0;
        for (int i = 0; i < 11; ++i) {
            suma += ((int) init[i] - 48) * A[i];
        }
        if (suma != 169) {
            throw InvalidPeselChecksum(init, suma);
        }


    }


    AcademiaDataValidationError::AcademiaDataValidationError(std::string i) : std::runtime_error(i) {

    }


    InvalidPeselChecksum::InvalidPeselChecksum(std::string i, int k) : AcademiaDataValidationError(i) {

    }


    InvalidPeselLength::InvalidPeselLength(std::string i, int k) : AcademiaDataValidationError(i) {

    }

    InvalidPeselCharacter::InvalidPeselCharacter(std::string i) : AcademiaDataValidationError(i) {

    }


}