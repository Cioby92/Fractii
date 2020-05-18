#pragma once
#include <stdexcept>
#include <ostream>
#include <istream>

class Complex {

private: 
    double parteIntreaga, parteImaginara;

public:
 
    //constructor implicit
    Complex();

    // constructor cu un singur parametru double care initializeaza partea imaginara cu 0
    // explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Complex(double real);

    // constructor cu 2 parametri double
    Complex(double real, double imag);

    // copy constructor
    Complex(const Complex& c);

    // destructor trivial
    ~Complex();

    // copy assignment operator
    Complex& operator = (const Complex& c);

    // supraincarcare operator ==
    bool operator == (const Complex& c);

    // supraincarcare operator +: (a, b) + (c, d) = (a + c, b + d)
    Complex operator + (const Complex& c);

    // supraincarcare operator - (binar): (a, b) - (c, d) = (a - c, b - d)
    Complex operator - (const Complex& c);

    // supraincarcare operator - (unar):  -(a, b) = (-a, -b)
    Complex operator - ();

    // supraincarcare operator *: (a, b) * (c, d) = (ac - bd, bc + ad)
    Complex operator * (const Complex& f);

    // supraincarcare operator / cu intreg: (a, b) / x = (a/x, b/x)
    Complex operator / (const float x);

    // supraincarcare operator / cu alt nr complex => a/b = (a * conj(b)) / modul(b)^2; b = (b1, b2); conj(b) = (b1, - b2)
    Complex operator / (const Complex& f);

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
