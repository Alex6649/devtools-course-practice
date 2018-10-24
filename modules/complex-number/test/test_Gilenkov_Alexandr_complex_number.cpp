// Copyright 2018 Gilenkov Alexandr

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Gilenkov_Alexandr_ComplexNumberTest, Addition_Is_Associative) {
    // ARRANGE
    ComplexNumber z1(1.4, 2.2);
    ComplexNumber z2(2.6, 5.4);
    ComplexNumber z3(6.9, 8.3);
    // ACT
    ComplexNumber sum1 = z1 + (z2 + z3);
    ComplexNumber sum2 = (z1 + z2) + z3;
    // ASSERT
    EXPECT_EQ(sum1, sum2);
}

TEST(Gilenkov_Alexandr_ComplexNumberTest, Addition_Is_Commutative) {
    // ARRANGE
    ComplexNumber z1(1.0, 2.0);
	ComplexNumber z2(3.4, 5.6);
    // ACT
    ComplexNumber sum1 = z1 + z2;
    ComplexNumber sum2 = z2 + z1;
    // ASSERT
    EXPECT_EQ(sum1, sum2);
}

TEST(Gilenkov_Alexandr_ComplexNumberTest, Multiple_Is_Commutative) {
    // ARRANGE
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.4, 5.6);
    // ACT
    ComplexNumber mult1 = z1 * z2;
    ComplexNumber mult2 = z2 * z1;
    // ASSERT
    EXPECT_EQ(mult1, mult2);
}

TEST(Gilenkov_Alexandr_ComplexNumberTest,
         Multiple_Not_Equal_Number_Equal_Null) {
    // ARRANGE
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(-1.0, -2.0);
    ComplexNumber z3(0.0, 0.0);
    // ACT
    ComplexNumber sum1 = z1 + z2;
    // ASSERT
    EXPECT_EQ(sum1, z3);
}

TEST(Gilenkov_Alexandr_ComplexNumberTest, Devide_To_Null) {
    // ARRANGE
    ComplexNumber z1(1.2, 2.3);
    ComplexNumber null(0, 0);
    // ASSERT
    ASSERT_ANY_THROW(z1 / null);
}
