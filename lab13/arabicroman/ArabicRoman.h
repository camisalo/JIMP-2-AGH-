//
// Created by konrad on 01.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H


#include <string>

class ArabicRoman {

public:
    ArabicRoman(int number) : numberA_{number} {
        FromArabicToRoman();
    }

    ArabicRoman(std::string number) : numberR_{number} {
        FromRomanToArabic();
    }

    void FromArabicToRoman() {
        int decimalValue[] = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ];
        var
        romanNumeral = [ 'M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I' ];

        var romanized = '';

        for (var index = 0; index < decimalValue.length; index++) {
            while (decimalValue[index] <= num) {
                romanized += romanNumeral[index];
                num -= decimalValue[index];
            }
        }

        return romanized;
    }

    void FromRomanToArabic() {

    }

    int GetArabic() { return numberA_; }

    std::string GetRoman() { return numberR_; }

private:
    int numberA_;
    std::string numberR_;

};


#endif //JIMP_EXERCISES_ARABICROMAN_H
