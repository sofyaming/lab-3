#include "library.hpp"
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <iomanip>

//namespace template_library {
    // Реализация методов класса Complex ...
    Complex::Complex() : m_real(0.0), m_imag(0.0) {}

    Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

    double Complex::real() const {
        return m_real;
    }

    double Complex::imag() const {
        return m_imag;
    }

    Complex Complex::operator+(const Complex& other) const {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }

    Complex Complex::operator-(const Complex& other) const {
        return Complex(m_real - other.m_real, m_imag - other.m_imag);
    }

    Complex Complex::operator*(const Complex& other) const {
        double realPart = (m_real * other.m_real) - (m_imag * other.m_imag);
        double imagPart = (m_real * other.m_imag) + (m_imag * other.m_real);
        return Complex(realPart, imagPart);
    }

    Complex Complex::operator/(const Complex& other) const {
        double denominator = other.m_real * other.m_real + other.m_imag * other.m_imag;
        if (denominator == 0.0) {
            throw std::runtime_error("Division by zero complex number.");
        }
        double realPart = (m_real * other.m_real + m_imag * other.m_imag) / denominator;
        double imagPart = (m_imag * other.m_real - m_real * other.m_imag) / denominator;
        return Complex(realPart, imagPart);
    }

    Complex operator*(double m, const Complex& other) {
        return Complex(m * other.m_real, m * other.m_imag);
    }

    Complex operator*(const Complex& other, double m) {
        return Complex(m * other.m_real, m * other.m_imag);
    }

    std::ostream& operator<<(std::ostream& os, const Complex& c) {
        if (c.m_imag == 0.0) {
            os << std::fixed << std::setprecision(1) << c.m_real;
        }
        else {
            os << c.m_real;
            if (c.m_imag >= 0.0) {
                os << " + " << c.m_imag << "i";
            }
            else {
                os << " - " << abs(c.m_imag) << "i";
            }
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.m_real >> c.m_imag;
        return is;
    }

    int main() {
        //TEST(ComplexDefaultConstructorTest, InitializesToZero)
        std::cout << "InitializesToZero" << "\n";
        Complex a1;
        if (a1.real() != 0.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (a1.imag() != 0.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexParameterizedConstructorTest, InitializesWithGivenValues)
        std::cout << "InitializesWithGivenValues" << "\n";
        Complex a2(3.0, 4.0);
        if (a2.real() != 3.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (a2.imag() != 4.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexAdditionTest, AddsTwoComplexNumbers)
        std::cout << "AddsTwoComplexNumbers" << "\n";
        Complex a3(1.0, 2.0);
        Complex b3(3.0, 4.0);
        Complex result3 = a3 + b3;
        if (result3.real() != 4.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result3.imag() != 6.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexSubtractionTest, SubtractsTwoComplexNumbers)
        std::cout << "SubtractsTwoComplexNumbers" << "\n";
        Complex a4(5.0, 6.0);
        Complex b4(2.0, 3.0);
        Complex result4 = a4 - b4;
        if (result4.real() != 3.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result4.imag() != 3.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexMultiplicationTest, MultipliesWithNegativeComplexNumber)
        std::cout << "MultipliesWithNegativeComplexNumber" << "\n";
        Complex a5(2.0, 3.0);
        Complex b5(-1.0, 1.0);
        Complex result5 = a5 * b5;
        if (result5.real() != -5.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result5.imag() != -1.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexMultiplicationTest, MultipliesTwoComplexNumbers)
        std::cout << "MultipliesTwoComplexNumbers" << "\n";
        Complex a6(2.0, 3.0);
        Complex b6(3.0, 4.0);
        Complex result6 = a6 * b6;
        if (result6.real() != -6.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result6.imag() != 17.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexScalarMultiplicationTest, MultipliesComplexByScalar)
        std::cout << "MultipliesComplexByScalar" << "\n";
        Complex a7(1.0, 2.0);
        double m7 = 2;
        Complex result7 = m7 * a7;
        if (result7.real() != 2.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result7.imag() != 4.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexScalarMultiplicationTest, MultipliesScalarByComplex)
        std::cout << "MultipliesScalarByComplex" << "\n";
        Complex a8(1.0, 2.0);
        double m8 = 2;
        Complex result8 = a8 * m8;
        if (result8.real() != 2.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (result8.imag() != 4.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexInputTest, ReadsFromInputStream)
        std::cout << "ReadsFromInputStream" << "\n";
        Complex c;
        std::istringstream input("3.0 4.0");
        input >> c;
        if (c.real() != 3.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        if (c.imag() != 4.0) {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }

        //TEST(ComplexOutputTest, WritesToOutputStream)
        std::cout << "WritesToOutputStream" << "\n";
        Complex c1(3.0, 4.0);
        Complex c2(3.0, -4.0);
        Complex c3(0.0, 0.0);
        std::ostringstream output1;
        output1 << c1;
        if (output1.str() != "3 + 4i") {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        std::ostringstream output2;
        output2 << c2;
        if (output2.str() != "3 - 4i") {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        std::ostringstream output3;
        output3 << c3;
        if (output3.str() != "0.0") {
            std::cout << "False" << "\n";
        }
        else {
            std::cout << "True" << "\n";
        }
        
    }
