#include <gtest/gtest.h>
#include "library.hpp"

TEST(ComplexDefaultConstructorTest, InitializesToZero) {
    template_library::Complex a;

    EXPECT_EQ(a.real(), 0.0);
    EXPECT_EQ(a.imag(), 0.0);
}

TEST(ComplexParameterizedConstructorTest, InitializesWithGivenValues) {
    template_library::Complex a(3.0, 4.0);

    EXPECT_EQ(a.real(), 3.0);
    EXPECT_EQ(a.imag(), 4.0);
}

TEST(ComplexAdditionTest, AddsTwoComplexNumbers) {
    template_library::Complex a(1.0, 2.0);
    template_library::Complex b(3.0, 4.0);
    template_library::Complex result = a + b;

    EXPECT_EQ(result.real(), 4.0);
    EXPECT_EQ(result.imag(), 6.0);
}

TEST(ComplexSubtractionTest, SubtractsTwoComplexNumbers) {
    template_library::Complex a(5.0, 6.0);
    template_library::Complex b(2.0, 3.0);
    template_library::Complex result = a - b;

    EXPECT_EQ(result.real(), 3.0);
    EXPECT_EQ(result.imag(), 3.0);
}

TEST(ComplexMultiplicationTest, MultipliesWithNegativeComplexNumber) {
    template_library::Complex a(2.0, 3.0);
    template_library::Complex b(-1.0, 1.0);
    template_library::Complex result = a * b;

    EXPECT_EQ(result.real(), -5.0);
    EXPECT_EQ(result.imag(), -1.0);
}

TEST(ComplexMultiplicationTest, MultipliesTwoComplexNumbers) {
    template_library::Complex a(2.0, 3.0);
    template_library::Complex b(3.0, 4.0);
    template_library::Complex result = a * b;

    EXPECT_EQ(result.real(), -6.0);
    EXPECT_EQ(result.imag(), 17.0);
}

TEST(ComplexScalarMultiplicationTest, MultipliesComplexByScalar) {
    template_library::Complex a(1.0, 2.0);
    double m = 2;
    template_library::Complex result = m * a;

    EXPECT_EQ(result.real(), 2.0);
    EXPECT_EQ(result.imag(), 4.0);
}

TEST(ComplexScalarMultiplicationTest, MultipliesScalarByComplex) {
    template_library::Complex a(1.0, 2.0);
    double m = 2;
    template_library::Complex result = a * m;

    EXPECT_EQ(result.real(), 2.0);
    EXPECT_EQ(result.imag(), 4.0);
}

TEST(ComplexInputTest, ReadsFromInputStream) {
    template_library::Complex c;

    std::istringstream input("3.0 4.0"); 
    input >> c;

    EXPECT_EQ(c.real(), 3.0);
    EXPECT_EQ(c.imag(), 4.0);
}

TEST(ComplexOutputTest, WritesToOutputStream) {
    template_library::Complex c1(3.0, 4.0); 
    template_library::Complex c2(3.0, -4.0); 
    template_library::Complex c3(0.0, 0.0); 

    std::ostringstream output1;
    output1 << c1;
    EXPECT_EQ(output1.str(), "3 + 4i");

    std::ostringstream output2;
    output2 << c2;
    EXPECT_EQ(output2.str(), "3 - 4i");

    std::ostringstream output3;
    output3 << c3;
    EXPECT_EQ(output3.str(), "0.0");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
