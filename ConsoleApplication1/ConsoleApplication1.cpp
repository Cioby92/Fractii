#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>
#include "TemplateFractie.h"
#include "NumarComplex.h"
#include "Meniu.h"


using namespace std;

int main() {

    Meniu meniu =  Meniu();
    meniu.Show_Menu();


  

    Complex cCin;
    cout << "Supraincarcare operator '>>':" << endl;
    cout << "Introduceti pe rand partea reala si partea imaginara (+<ENTER>):" << endl;
    cin >> cCin;
    cout << "Supraincarcare operator '<<': cCin: " << cCin << endl;

    Complex cCout = cCin;
    cout << "Supraincarcare operator '=': cCout = cCin => " << cCout << endl;
    cout << endl << "================================" << endl << "Sfarsit!";

    return 0;
}