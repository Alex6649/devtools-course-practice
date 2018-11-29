// Copyright 2018 Gilenkov Alexandr

#include <gtest/gtest.h>
#include "../include/mass-converter.h"


TEST(Mass_Converter, Can_Create_Mass_Converter) {
    // Act & Assert
    ASSERT_NO_THROW(MassConverter conv);
}
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
TEST(Mass_Converter, Throw_When_Uncorrect_Argument) {
    // Arrange
    double val = -22.345;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.convert(val, "Tonn", "Stone"));
}
TEST(Mass_Converter, test_convert_tonn_to_kilogramm) {
    // Arrange
    double input = 6;
    double output = 6000;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.convert(input, "Tonn", "Kilogramm"), output);
}
TEST(Mass_Converter, test_convert_gramm_to_kilogramm) {
    // Arrange
    double input = 1000;
    double output = 1;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.convert(input, "Gramm", "Kilogramm"), output);
}
TEST(Mass_Converter, test_convert_stone_to_kilogramm) {
    // Arrange
    double input = 0.157473;
    double output = 1;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.convert(input, "Stone", "Kilogramm"), output);
}
TEST(Mass_Converter, test_convert_pound_to_kilogramm) {
    // Arrange
    double input = 2.205;
    double output = 1;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.convert(input, "Pound", "Kilogramm"), output);
}
TEST(Mass_Converter, test_convert_ounce_to_kilogramm) {
    // Arrange
    double input = 35.274;
    double output = 1;
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.convert(input, "Ounce", "Kilogramm"), output);
}
TEST(Mass_Converter, Throw_with_convert_Tonn_to_Kilogramm) {
    // Arrange
    double tonn = -13.440;
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.convert(tonn, "Tonn", "Kilogramm"));
}
TEST(Mass_Converter, Throw_with_convert_Tonn_to_Kilogramm_2) {
    // Arrange
    double tonn = 13.440;
    const char* from = "Tonns";
    const char* to = "Kilogramm";
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.convert(tonn, from, to));
}
TEST(Mass_Converter, Throw_with_convert_Tonn_to_Kilogramm_3) {
    // Arrange
    double tonn = 13.440;
    const char* from = "Tonn";
    const char* to = "Kilogram";
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.convert(tonn, from, to));
}
TEST(Mass_Converter, Test_ParseMassUnit_1) {
    // Arrange
    const char* val = "Tonn";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Tonn);
}
TEST(Mass_Converter, Test_ParseMassUnit_2) {
    // Arrange
    const char* val = "Kilogramm";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Kilogramm);
}
TEST(Mass_Converter, Test_ParseMassUnit_3) {
    // Arrange
    const char* val = "Gramm";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Gramm);
}
TEST(Mass_Converter, Test_ParseMassUnit_4) {
    // Arrange
    const char* val = "Stone";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Stone);
}
TEST(Mass_Converter, Test_ParseMassUnit_5) {
    // Arrange
    const char* val = "Pound";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Pound);
}
TEST(Mass_Converter, Test_ParseMassUnit_6) {
    // Arrange
    const char* val = "Ounce";
    // Act
    MassConverter conv;
    // Assert
    EXPECT_EQ(conv.ParseMassUnit(val), Ounce);
}
TEST(Mass_Converter, Throw_Test_ParseMassUnit) {
    // Arrange
    const char* val = "Bla";
    // Act
    MassConverter conv;
    // Assert
    ASSERT_ANY_THROW(conv.ParseMassUnit(val));
}
