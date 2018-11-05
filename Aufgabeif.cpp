#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int i_Zeit = 0;
	float f_Betrag = 0.0;
	char c_Taste = ' ';
	const int i_Takt = 15;
	const float f_Einheit = 0.5;

	//Ausgabe
	cout << "\t\t\t-----------------Parkautomat-----------------";
	cout << "\n\t\t\tUm einen Parkschein über 15 Minuten zu lösen, ";
	cout << "\n\t\t\t\tmusst du die Taste p drücken \n\t\t\t";

	//Eingabe
	cin >> c_Taste;
	
	//Verarbeitung
	if(c_Taste == 'p')
	{
		i_Zeit = i_Zeit + i_Takt;
		f_Betrag = f_Einheit*i_Zeit/i_Takt;
		cout << "\n\t\t\tParkzeit: " << i_Zeit;
		cout << "\n\t\t\tBetrag: " << f_Betrag;
	}
	else
	{
		
	}

	getchar();
	getchar();
}
