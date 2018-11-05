#include <iostream>
#include <math.h>
using namespace std; 

int main()
{
	//Variablen
	int i_Feld = 0;
	long double ld_Reiskorn = 0.0;
	const float f_gewicht = 0.00003;

	//Eingabe
	cout << "Bitte gib das Feld ein: ";
	cin >> i_Feld;
	while(i_Feld < 1 || i_Feld > 64)
	{
		cout << "Bitte ein Feld zwischen 1 und 64 nehmen! ";
		cin >> i_Feld;
	}
	
	//Berechnung
	ld_Reiskorn = pow(2, i_Feld-1) * f_gewicht;

	//Ausgabe
	cout <<  "Auf dem " << i_Feld << " liegen " << pow(2, i_Feld-1) << " Reiskoerner.\nSie haben ein Gewicht von: " << ld_Reiskorn << "kg.";
	
}
