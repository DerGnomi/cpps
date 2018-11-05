#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{

	//Variablen
	float f_Anfangskapital = 0.0;
	float f_Zinssatz = 0.0;
	int i_Laufzeit = 0;
	float f_Endkapital = 0.0;

	//Eingabe
	cout << "Bitte gib dein Anfangskapital ein: ";
	cin >> f_Anfangskapital;
	cout << "Bitte gib den Zinssatz ein: ";
	cin >> f_Zinssatz;
	cout << "Bitte gib die Laufzeit ein: ";
	cin >> i_Laufzeit;
	
	//Berechnung
	f_Endkapital = f_Anfangskapital * pow((1+f_Zinssatz / 100), i_Laufzeit);
	
	//Ausgabe
	cout << setprecision(2) << fixed;
	cout << "Dein Endkapital betraegt: " << f_Endkapital;
	
	getchar();
	getchar();
}

