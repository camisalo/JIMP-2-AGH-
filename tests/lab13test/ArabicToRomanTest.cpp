//
// Created by mwypych on 01.06.17.
//

#include <stdexcept>
#include <string>
#include <gtest/gtest.h>
#include "ArabicRoman.h"
#include <string>

using namespace std::string_literals;

TEST(TestArabicToRmoan, IsAbleToSaveArabicNumber) {
    ArabicRoman AR(1);
    EXPECT_EQ(1, AR.GetArabic());
}

TEST(TestArabicToRmoan, IsAbleToSaveRomanNumber) {
    ArabicRoman AR("V");
    EXPECT_EQ("V"s, AR.GetRoman());
}

