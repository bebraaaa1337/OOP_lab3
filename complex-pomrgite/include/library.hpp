#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace template_library {

class Complex {
public:
    // Конструктор
    Complex();
    Complex(double real, double imag);
    
    // Геттеры
    double real() const;
    double imag() const;

    // Арифметические операции
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Умножение комплексного числа на вещественное число
    friend Complex operator*(double m, const Complex& other);
    friend Complex operator*(const Complex& other, double m);

    // Операторы вывода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

private:
    double m_real;
    double m_imag;
};

} 

#endif 