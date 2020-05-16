#pragma once
#include <stdexcept>
#include <ostream>
#include <istream>

class Complex {

private: 
    double parteIntreaga, parteImaginara;

public:
 
    //constructor implicit
    Complex() {
        this->parteIntreaga = 0;
        this->parteImaginara = 0;
    };

    // constructor cu un singur parametru double care initializeaza partea imaginara cu 0
    // explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Complex(double real) {
        this->parteIntreaga = real;
        this->parteImaginara = 0;
    };

    // constructor cu 2 parametri double
    Complex(double real, double imag) {
        this->parteIntreaga = real;
        this->parteImaginara = imag;
    };

    // copy constructor
    Complex(const Complex& c) {
        this->parteIntreaga = c.parteIntreaga;
        this->parteImaginara = c.parteImaginara;
    };

    // destructor trivial
    ~Complex() = default;

    // copy assignment operator
    Complex& operator = (const Complex& c) {
        parteIntreaga = c.parteIntreaga;
        parteImaginara = c.parteImaginara;
    };

    // supraincarcare operator ==
    bool operator == (const Complex& c) {
        return this->parteIntreaga == c.parteIntreaga && this->parteImaginara == c.parteImaginara;
    };

    // supraincarcare operator +: (a, b) + (c, d) = (a + c, b + d)
    Complex operator + (const Complex& c) {
        return Complex(this->parteIntreaga + c.parteImaginara, this->parteImaginara + c.parteImaginara);
    };

    // supraincarcare operator - (binar): (a, b) - (c, d) = (a - c, b - d)
    Complex operator - (const Complex& c) {
        return Complex(this->parteIntreaga - c.parteImaginara, this->parteImaginara - c.parteImaginara);
    };

    // supraincarcare operator - (unar):  -(a, b) = (-a, -b)
    Complex operator - () {
        return Complex(-this->parteIntreaga, -this->parteImaginara);
    };

    // supraincarcare operator *: (a, b) * (c, d) = (ac - bd, bc + ad)
    Complex operator * (const Complex& f) {
        return Complex(this->parteIntreaga * f.parteIntreaga - this->parteImaginara * f.parteImaginara, this->parteIntreaga * f.parteImaginara + this->parteImaginara * f.parteIntreaga);
    };

    // supraincarcare operator / cu intreg: (a, b) / x = (a/x, b/x)
    Complex operator / (const float x) {
        if (x == 0.0) {
            throw std::invalid_argument{ "Numitor invalid (0) !" };
        }
        return Complex(this->parteIntreaga / x, this->parteImaginara / x);
    };

    // supraincarcare operator / cu alt nr complex => a/b = (a * conj(b)) / modul(b)^2; b = (b1, b2); conj(b) = (b1, - b2)
    Complex operator / (const Complex& f) {
        double modul2 = f.parteIntreaga * f.parteIntreaga + f.parteImaginara * f.parteImaginara;
        if (modul2 == 0) {
            throw std::invalid_argument{ "Modul invalid (0)!" };
        }
        return Complex((this->parteIntreaga * f.parteIntreaga + this->parteImaginara * f.parteImaginara) / modul2, (this->parteImaginara * f.parteIntreaga - this->parteIntreaga * f.parteImaginara) / modul2);
    };

    // supraincarcare operator << (cout) - caz special pt partea imaginara pozitiva
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.parteIntreaga << " " << (c.parteImaginara >= 0 ? "+" : "-") << " " << abs(c.parteImaginara) << "i";
        return os;
    };

    // supraincarcare operator >> (cin)
    friend std::istream& operator >> (std::istream& is, Complex& c) {
        is >> c.parteIntreaga >> c.parteImaginara;
        return is;
    };
};
