#include "NumarComplex.h"
Complex::Complex()
{
	this->parteIntreaga = 0;
	this->parteImaginara = 0;
}

Complex::Complex(double real)
{
	this->parteIntreaga = real;
	this->parteImaginara = 0;
}

Complex::Complex(double real, double imag)
{
	this->parteIntreaga = real;
	this->parteImaginara = imag;
}
Complex::Complex(const Complex& c)
{
	this->parteIntreaga = c.parteIntreaga;
	this->parteImaginara = c.parteImaginara;
}

Complex::~Complex() = default;

Complex& Complex::operator=(const Complex& c)
{
	this->parteIntreaga = c.parteIntreaga;
	this->parteImaginara = c.parteImaginara;
    return *this;
}

bool Complex::operator == (const Complex& c) {
    return this->parteIntreaga == c.parteIntreaga && this->parteImaginara == c.parteImaginara;
};

Complex  Complex::operator + (const Complex& c) {
    return Complex(this->parteIntreaga + c.parteImaginara, this->parteImaginara + c.parteImaginara);
};

Complex  Complex::operator - (const Complex& c) {
    return Complex(this->parteIntreaga - c.parteImaginara, this->parteImaginara - c.parteImaginara);
};

Complex  Complex::operator - () {
    return Complex(-this->parteIntreaga, -this->parteImaginara);
};

Complex  Complex::operator * (const Complex& f) {
    return Complex(this->parteIntreaga * f.parteIntreaga - this->parteImaginara * f.parteImaginara, this->parteIntreaga * f.parteImaginara + this->parteImaginara * f.parteIntreaga);
};

Complex  Complex::operator / (const float x) {
    if (x == 0.0) {
        throw std::invalid_argument{ "Numitor invalid (0) !" };
    }
    return Complex(this->parteIntreaga / x, this->parteImaginara / x);
};

Complex  Complex::operator / (const Complex& f) {
    double modul2 = f.parteIntreaga * f.parteIntreaga + f.parteImaginara * f.parteImaginara;
    if (modul2 == 0) {
        throw std::invalid_argument{ "Modul invalid (0)!" };
    }
    return Complex((this->parteIntreaga * f.parteIntreaga + this->parteImaginara * f.parteImaginara) / modul2, (this->parteImaginara * f.parteIntreaga - this->parteIntreaga * f.parteImaginara) / modul2);
};