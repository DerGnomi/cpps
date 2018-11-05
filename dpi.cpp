//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
//void v_Beispiel();

//GlobaleVaribalen
//int i_Beispiel = 0;
int i_max = 0;
double d_PI = 1.0;


//MainMethode
int main()
{
	//Eingabe 
	cout << "Bis zu welchem Wert soll gerechnet werden?: ";
	cin >> i_max;
	//Verarbeitung
	for(int i=3; i <= i_max; i += 4)
	{
		d_PI = d_PI - 1.0/i + 1.0/(i+2);
		cout << "d_PI = " << 4*d_PI << '\n';
	}
	//Ausgabe
	cout << "d_PI = " << 4*d_PI << '\n';
}

//Methodendefinition

//void v_Beispiel(){ }
