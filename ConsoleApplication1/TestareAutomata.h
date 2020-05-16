#pragma once
#include <iostream>
#include "TemplateFractie.h"
#include <cassert>
#include "NumarComplex.h"

class TestareAutomata
{

public:
    TestareAutomata()
    {

    }
	void TestareAutomataFractie()
	{
        cout << "Fractie cu tipul standard intreg:" << endl << "================================" << endl;
        Fractie<int> int0(21);
        cout << "Constructor fractie cu o valoare intreaga (21): " << int0 << endl;

        cout << "Constructori fractii cu cate 2 valori intregi: ";
        Fractie<int> int1 = Fractie<int>(1, 2);
        Fractie<int> int2 = Fractie<int>(3, 4);
        cout << "int1 (1, 2): " << int1 << "; int2 (3, 4): " << int2 << endl;
        cout << "Supraincarcare operator '+': " << "int1 + int2 => " << (int1 + int2) << endl;
        cout << "Supraincarcare operator '*': " << "int1 * int2 => " << (int1 * int2) << endl;

        cout << "Supraincarcare operatori '=', '==': ";
        int1 = int2;
        assert(int1 == int2);
        cout << "int1 = int2; => int1: " << int1 << "; int2: " << int2 << endl;
        cout << "Supraincarcare operator '+' dupa '=': " << "int1 + int2 => " << (int1 + int2) << endl;

        assert(Fractie<int>(6, 4) == (int1 + int2));
        assert(Fractie<int>(0, 1) == (int2 - int1));

        Fractie<int> int3 = Fractie<int>(1, 2);
        Fractie<int> int4 = Fractie<int>(2, 4);
        Fractie<int> int3_4 = (int3 - int4);
        Fractie<int> int_4 = -int4;

        cout << "Constructori fractii cu cate 2 valori intregi: " << "int3 (1, 2): " << int3 << "; int4 (2, 4): " << int4 << endl;
        assert(Fractie<int>(1, 4) == (int3 * int4));
        assert(Fractie<int>(2, 8) == (int3 * int4));
        assert(Fractie<int>(1, 1) == (int3 + int4));
        assert(Fractie<int>(1) == (int3 + int4));
        assert(Fractie<int>(1) == (int3 / int4));
        cout << "Supraincarcare operator '-' binar: " << "int3 - int4 => " << int3_4 << endl;
        assert(Fractie<int>(0) == int3_4);
        assert(Fractie<int>(0, 8) == int3_4);
        cout << "Supraincarcare operator '-' unar: " << "-int4 => " << int_4 << endl;
        assert(Fractie<int>(-1, 2) == int_4);

        cout << "Constructori fractii cu cate 2 valori intregi: " << "int5 (4, 1); int6 (2, 1); int7 (1, 0); " << endl;
        cout << "Supraincarcare operator '/' cu si fara numitor invalid: " << endl;
        try {
            Fractie<int> int5 = Fractie<int>(4, 1);
            Fractie<int> int6 = Fractie<int>(2, 1);
            cout << "int5 / int6: Numitor valid => " << (int5 / int6) << endl;

            Fractie<int> int7 = Fractie<int>(1, 0);
            cout << "int6 / int7: Numitor invalid => arunca eroare in constructor, nu ajunge aici!" << (int6 / int7) << endl;
        }
        catch (std::invalid_argument& e) {
            cout << "Eroare prinsa (invalid_argument): " << e.what() << endl;
        }
        catch (...) {
            cout << "Eroare!" << endl;
        }
	}

    void TestareAutomataFractiiComplexe()
    {
        cout << endl << "Fractie cu tipul custom 'complex':" << endl << "================================" << endl;
        Complex c1(1);
        Complex c2(0);
        cout << "Constructor fractie cu un singur parametru c1(1): " << c1 << endl;
        cout << "Constructor fractie cu un singur parametru c2(0): " << c2 << endl;

        assert(Complex(1, 0) == c1);
        assert(Complex(0, 0) == c2);

        Complex c3 = Complex(3, 5);
        Complex c4 = Complex(6, -4);
        Complex c5 = Complex(1, 2);
        cout << "Constructor fractie cu 2 parametri c3(3, 5): " << c3 << endl;
        cout << "Constructor fractie cu 2 parametri c4(6, -4): " << c4 << endl;
        cout << "Constructor fractie cu 2 parametri c5(1, 2): " << c5 << endl;
        cout << "Supraincarcare operator '*': cc43 * c4 => " << c3 * c4 << endl;
        assert(Complex(38, 18) == (c3 * c4));
        cout << "Supraincarcare operatori '/' si '==': (1, 0) == c5 / c5 => " << c5 / c5 << endl;
        assert(Complex(1, 0) == (c5 / c5));
    }

};

