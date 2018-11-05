#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int i_ToreHeim = 0;
	int i_ToreGast = 0;
	
	//Eingabe
	cout << "Bitte geben Sie die Anzahl der Tore der Heimmannschaft ein: ";
	cin >> i_ToreHeim;
	cout << "Bitte geben Sie die Anzahl der Tore der Gastmannschaft ein: ";
	cin >> i_ToreGast;
		
	//Ausgabe
	cout << "\nEs fielen insgesamt: " << i_ToreHeim + i_ToreGast << " Tore.";
	cout << "\nJede Mannschaft erzielte im Schnitt: " << (float)i_ToreHeim + (float)i_ToreGast / 2 << " Tore.";
	
	getchar();
	getchar();
	return 0;
}