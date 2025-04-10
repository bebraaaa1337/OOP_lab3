#include "library.hpp"
#include <stdexcept>

namespace template_library {
    Complex::Complex()
    : m_real(0),m_imag(0)
    {}
    Complex::Complex(double real, double imag)
    : m_real(real),
    m_imag(imag){}
    double Complex::real() const{
        return m_real;
    }
    double Complex::imag() const{
        return m_imag;
    }
    Complex Complex::operator+(const Complex& other) const{
        return Complex(m_real+other.real(), m_imag+other.imag());
    }
    Complex Complex:: operator-(const Complex& other) const{
        return Complex(m_real-other.real(),m_imag-other.imag());
    }
    Complex Complex::operator*(const Complex& other) const{
        return Complex(m_real*other.real()-m_imag*other.imag(),
                      m_real*other.imag()+m_imag*other.real());
    }
    Complex Complex::operator/(const Complex& other) const{
        return Complex((m_real*other.real()-m_imag*other.imag())/(other.real()*other.real()+other.imag()*other.imag()),(m_imag*other.real()-m_real*other.imag())/(other.real()*other.real()+other.imag()*other.imag()));
    }
    Complex operator*(double m, const Complex& other){
        return Complex(m*other.real(),m*other.imag());
    }
    Complex operator*(const Complex& other, double m){
         return Complex(m*other.real(),m*other.imag());
    }
    std::ostream& operator<<(std::ostream& os, const Complex& c){
        if (c.imag()<0){
        os<<c.real()<<" - "<<std::abs(c.imag())<<"i";
        }
        else if (c.imag()>0){
            os<<c.real()<<" + "<< c.imag()<<"i";
        }
        else{
            os<<c.real();
        }
        return os;
    }
    std::istream& operator>>(std::istream& is, Complex& c){
        is>>c.m_real;
        is>>c.m_imag;
        return is;
    }
} 