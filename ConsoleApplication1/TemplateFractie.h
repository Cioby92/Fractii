#pragma once
#include <stdexcept>
#include <ostream>
#include <istream>

using namespace std;

template <typename T>
class Fractie {

private:
    T numarator, numitor;
public:
    // constructor
    Fractie() {
        this->numarator = T();
        this->numitor = T();
    }

    // constructor cu un parametru care initializeaza numitorul cu o valoare
    // explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Fractie(T numarator) {
        this->numarator = numarator;
        this->numitor = T(1);
    };

    // constructor cu 2 parametri; validam numitorul fractiei
    Fractie(T numarator, T numitor) {
        this->numarator = numarator;
        if (numitor == T(0)) {
            throw std::invalid_argument{ "Numitor invalid (0) !" };
        }
        this->numitor = numitor;
    };

    // copy constructor
    Fractie(const Fractie& f) {
        this->numarator = f.numarator;
        this->numitor = f.numitor;
    };

    // destructor trivial
    ~Fractie() = default;

    // copy assignment operator
    Fractie& operator = (const Fractie& f) {
        this->numarator = f.numarator;
        this->numitor = f.numitor;
        return *this;
    };

    // supraincarcare operator ==
    bool operator == (const Fractie& f) {
        return this->numarator * f.numitor == this->numitor * f.numarator;
    };

    // supraincarcare operator +: (ad/bd + cb/bd)
    Fractie operator + (const Fractie& f) {
        return Fractie(this->numarator * f.numitor + f.numarator * this->numitor, this->numitor * f.numitor);
    };

    // supraincarcare operator - (binar): (ad/bd - cb/bd)
    Fractie operator - (const Fractie& f) {
        return Fractie(this->numarator * f.numitor - f.numarator * this->numitor, this->numitor * f.numitor);
    };

    // supraincarcare operator - (unar)
    Fractie operator - () {
        return Fractie(-this->numarator, this->numitor);
    };

    // supraincarcare operator *
    Fractie operator * (const Fractie& f) {
        return Fractie(this->numarator * f.numarator, this->numitor * f.numitor);
    };

    // supraincarcare operator /
    Fractie operator / (const Fractie& f) {
        return Fractie(this->numarator * f.numitor, this->numitor * f.numarator);
    };

    // supraincarcare operator << (cout)
    friend ostream& operator << (ostream& os, const Fractie& f) {
        os << f.numarator << "/" << f.numitor;
        return os;
    };

    // supraincarcare operator >> (cin)
    friend istream& operator >> (istream& is, const Fractie& f) {
        is >> f.numarator >> f.numitor;
        return is;
    };
};
