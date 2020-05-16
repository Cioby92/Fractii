#pragma once
#include <iostream>
#include "TestareAutomata.h"

using namespace std;
class Meniu
{
private:
	int choice;
	TestareAutomata TA = TestareAutomata();
public:
	//constructor implicit

	Meniu()
	{
		choice = 0;
	}
	int Show_Menu()
	{
		do
		{
			cout << endl
				<< "1 - Testare Automata  \n"
				<< "2 - Testare Automata pentru numere complexe \n"
				<< "3 - Testare Manuala \n"
				<< "4 - Exit \n"
				<< "Introdu optiunea";
			cin >> choice;
			switch (choice)
			{
			case 1:
				TA.TestareAutomataFractie();
				break;
			case 2: 
				TA.TestareAutomataFractiiComplexe();
				break;
			case 3: break;
			default:
			{
				cout << "Introdu o optiune valabila";
				break;
			}
			}

		} while (choice != 4);
		return 0;
	}
	
};

