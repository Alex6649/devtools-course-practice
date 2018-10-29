// Copyright 2018 Gilenkov Alexandr

#include <gtest/gtest.h>
#include "include/mass-converter.h"

TEST(Mass_Converter, test_correct_value_with_true) {
    // Arrange
    double val = 43.564;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_TRUE(conv.isCorrect(val));
}
TEST(Mass_Converter, test_correct_value_with_false) {
    // Arrange
    double val = -43.564;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_FALSE(conv.isCorrect(val));
}
TEST(Mass_Converter, Can_Create_Mass_Converter) {
    // Act & Assert
    ASSERT_NO_THROW(MassConverter conv);
}
TEST(Mass_Converter, Transform_Tonn_to_Kilogramm) {
    // Arrange
    double tonn = 13.440;
    double res = 13440;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.tonnToKilogramm(tonn), res);
}
TEST(Mass_Converter, Throw_with_Transform_Tonn_to_Kilogramm) {
    // Arrange
    double tonn = -13.440;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToKilogramm(tonn));
}
TEST(Mass_Converter, Transform_Kilogramm_To_Tonn) {
    // Arrange
    double kilo = 17650;
    double res = 17.65;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.kilogrammToTonn(kilo), res);
}
TEST(Mass_Converter, Throw_with_Transform_Kilogramm_To_Tonn) {
    // Arrange
    double kilo = -5980;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.kilogrammToTonn(kilo));
}
TEST(Mass_Converter, Transform_Tonn_To_Gramm) {
    // Arrange
    double tonn = 9;
    double res = 9000000;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.tonnToGramm(tonn), res);
}
TEST(Mass_Converter, Throw_with_Transform_Tonn_To_Gramm) {
    // Arrange
    double tonn = -5;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToGramm(tonn));
}
TEST(Mass_Converter, Transform_Gramm_To_Tonn) {
    // Arrange
    double gramm = 1765000;
    double res = 1.765;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.grammToTonn(gramm), res);
}
TEST(Mass_Converter, Throw_with_Transform_Gramm_To_Tonn) {
    // Arrange
    double gramm = -5980000;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.grammToTonn(gramm));
}
TEST(Mass_Converter, Transform_Tonn_To_Stoun) {
    // Arrange
    double tonn = 5;
    double res = 787.365;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.tonnToStoun(tonn), res);
}
TEST(Mass_Converter, Throw_with_Transform_Tonn_To_Stoun) {
    // Arrange
    double tonn = -9;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToStoun(tonn));
}
TEST(Mass_Converter, Transform_Stoun_To_Tonn) {
    // Arrange
    double stoun = 1259.78;
    double res = 7.9999745988201143;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.stounToTonn(stoun), res);
}
TEST(Mass_Converter, Throw_with_Transform_Stoun_To_Tonn) {
    // Arrange
    double stoun = -5980;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.stounToTonn(stoun));
}
TEST(Mass_Converter, Transform_Tonn_To_Funt) {
    // Arrange
    double tonn = 1;
    double res = 2204.62;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.tonnToFunt(tonn), res);
}
TEST(Mass_Converter, Throw_with_Transform_Tonn_To_Funt) {
    // Arrange
    double tonn = -2;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToFunt(tonn));
}
TEST(Mass_Converter, Transform_Funt_To_Tonn) {
    // Arrange
    double funt = 13227.7;
    double res = 5.9999909281418118;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.funtToTonn(funt), res);
}
TEST(Mass_Converter, Throw_with_Transform_Funt_To_Tonn) {
    // Arrange
    double funt = -5980;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.funtToTonn(funt));
}
TEST(Mass_Converter, Transform_Tonn_To_Uncia) {
    // Arrange
    double tonn = 0.134;
    double res = 4726.7160000000003;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.tonnToUncia(tonn), res);
}
TEST(Mass_Converter, Throw_with_Transform_Tonn_To_Uncia) {
    // Arrange
    double tonn = -5;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToUncia(tonn));
}
TEST(Mass_Converter, Throw_with_Transform_Uncia_To_Tonn) {
    // Arrange
    double uncia = -598830;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.unciaToTonn(uncia));
}
TEST(Mass_Converter, Transform_Kilogramm_To_Gramm) {
    // Arrange
    double kilo = 153;
    double res = 153000;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.kilogrammToGramm(kilo), res);
}
TEST(Mass_Converter, Throw_with_Transform_Kilogramm_To_Gramm) {
    // Arrange
    double kilo = -50;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.kilogrammToGramm(kilo));
}
TEST(Mass_Converter, Transform_Gramm_To_Kilogramm) {
    // Arrange
    double gramm = 141096;
    double res = 141.096;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.grammToKilogramm(gramm), res);
} 
TEST(Mass_Converter, Throw_with_Transform_Gramm_To_Kilogramm) {
    // Arrange
    double gramm = -598830;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.grammToKilogramm(gramm));
}
TEST(Mass_Converter, Transform_Kilogramm_To_Stoun) {
    // Arrange
    double kilo = 500;
    double res = 78.740157480314963;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.kilogrammToStoun(kilo), res);
}
TEST(Mass_Converter, Throw_with_Transform_Kilogramm_To_Stoun) {
    // Arrange
    double kilo = -598830;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.kilogrammToStoun(kilo));
}
TEST(Mass_Converter, Transform_Stoun_To_Kilogramm) {
    // Arrange
    double stoun = 141;
    double res = 895.34999999999991;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.stounToKilogramm(stoun), res);
}
TEST(Mass_Converter, Throw_with_Transform_Stoun_to_Kilogramm) {
    // Arrange
    double stoun = -59;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.stounToKilogramm(stoun));
}
TEST(Mass_Converter, Transform_Kilogramm_To_Funt) {
    // Arrange
    double kilo = 87;
    double res = 191.83500000000001;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.kilogrammToFunt(kilo), res);
} 
TEST(Mass_Converter, Throw_with_Transform_Kilogramm_To_Funt) {
    // Arrange
    double kilo = -65;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.kilogrammToFunt(kilo));
}
TEST(Mass_Converter, Transform_Funt_To_Kilogramm) {
    // Arrange
    double funt = 191.802;
    double res = 86.985034013605443;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.funtToKilogramm(funt), res);
}
TEST(Mass_Converter, Throw_with_Transform_Funt_To_Kilogramm) {
    // Arrange
    double funt = -190;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.funtToKilogramm(funt));
}
TEST(Mass_Converter, Transform_Uncia_To_Tonn) {
    // Arrange
    double uncia = 141096;
    double res = 4;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.unciaToTonn(uncia), res);
}
TEST(Mass_Converter, Transform_Kilogramm_To_Uncia) {
    // Arrange
    double kilo = 87;
    double res = 3068.8380000000002;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.kilogrammToUncia(kilo), res);
}
TEST(Mass_Converter, Throw_with_Transform_Kilogramm_To_Uncia) {
    // Arrange
    double kilo = -90;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.kilogrammToUncia(kilo));
}
TEST(Mass_Converter, Transform_Gramm_To_Stoun) {
    // Arrange
    double gramm = 70000;
    double res = 11.02311342169566;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.grammToStoun(gramm), res);
}
TEST(Mass_Converter, Throw_with_Transform_Gramm_To_Stoun) {
    // Arrange
    double gramm = -8975;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.grammToStoun(gramm));
}
TEST(Mass_Converter, Transform_Stoun_To_Gramm) {
    // Arrange
    double stoun = 11.023113;
    double res = 69999.997322109004;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.stounToGramm(stoun), res);
}
TEST(Mass_Converter, Throw_with_Transform_Stoun_To_Gramm) {
    // Arrange
    double stoun = -5;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.stounToGramm(stoun));
}
TEST(Mass_Converter, Transform_Gramm_To_Funt) {
    // Arrange
    double gramm = 70000;
    double res = 154.32370941286442;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.grammToFunt(gramm), res);
}
TEST(Mass_Converter, Throw_with_Transform_Gramm_To_Funt) {
    // Arrange
    double gramm = -783434;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.grammToFunt(gramm));
}
TEST(Mass_Converter, Transform_Funt_To_Gramm) {
    // Arrange
    double funt = 154.32358;
    double res = 69999.941299359998;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.funtToGramm(funt), res);
}
TEST(Mass_Converter, Throw_with_Transform_Funt_To_Gramm) {
    // Arrange
    double funt = -37;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.funtToGramm(funt));
}
TEST(Mass_Converter, Transform_Gramm_To_Uncia) {
    // Arrange
    double gramm = 70000;
    double res = 2469.1358024691358;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.grammToUncia(gramm), res);
}
TEST(Mass_Converter, Throw_with_Transform_Gramm_To_Uncia) {
    // Arrange
    double gramm = -9876;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.grammToUncia(gramm));
}
TEST(Mass_Converter, Transform_Uncia_To_Gramm) {
    // Arrange
    double uncia = 2469.1773;
    double res = 70001.176454999993;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.unciaToGramm(uncia), res);
}
TEST(Mass_Converter, Throw_with_Transform_Uncia_To_Gramm) {
    // Arrange
    double uncia = -598;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.unciaToGramm(uncia));
}
TEST(Mass_Converter, Transform_Stoun_To_Funt) {
    // Arrange
    double stoun = 89;
    double res = 1246;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.stounToFunt(stoun), res);
}
TEST(Mass_Converter, Throw_with_Transform_Stoun_To_Funt) {
    // Arrange
    double stoun = -59;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.stounToFunt(stoun));
}
TEST(Mass_Converter, Transform_Funt_To_Stoun) {
    // Arrange
    double funt=1246;
    double res = 89;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.funtToStoun(funt), res);
}
TEST(Mass_Converter, Throw_with_Transform_Funt_To_Stoun) {
    // Arrange
    double funt = -1234;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.funtToStoun(funt));
}
TEST(Mass_Converter, Transform_Stoun_To_Uncia) {
    // Arrange
    double stoun = 5;
    double res = 1120;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.stounToUncia(stoun), res);
}
TEST(Mass_Converter, Throw_with_Transform_Stoun_To_Uncia) {
    // Arrange
    double stoun = -59;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.stounToUncia(stoun));
}
TEST(Mass_Converter, Transform_Uncia_To_Stoun) {
    // Arrange
    double uncia = 1120;
    double res = 5;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.unciaToStoun(uncia), res);
}
TEST(Mass_Converter, Throw_with_Transform_Uncia_To_Stoun) {
    // Arrange
    double uncia = -598;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.tonnToStoun(uncia));
}
TEST(Mass_Converter, Transform_Funt_To_Uncia) {
    // Arrange
    double funt = 67;
    double res = 1072;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.funtToUncia(funt), res);
}
TEST(Mass_Converter, Throw_with_Transform_Funt_To_Uncia) {
    // Arrange
    double funt = -89;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.funtToUncia(funt));
}
TEST(Mass_Converter, Transform_Uncia_To_Funt) {
    // Arrange
    double uncia = 1072;
    double res = 67;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_DOUBLE_EQ(conv.unciaToFunt(uncia), res);
}
TEST(Mass_Converter, Throw_with_Transform_Uncia_To_Funt) {
    // Arrange
    double uncia = -598;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.unciaToFunt(uncia));
}
