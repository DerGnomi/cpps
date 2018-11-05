#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Variablen
bool b_tester = true;
char c_nochmal = 'y';
int i_zaehler = 1;

//Methoden
int main()
{
	while(b_tester == true)
	{
		cout << "Bitte 30 Personen einsteigen!\n";
		for(int i = 0; i < 30; i++)
		{
			cout << "\nNoch " << 30-i << " Personen einsteigen";
			cout << "\nBitte einsteigen!";
			cout << "\n\nSignal Drehkreuz!";
		}
		cout << "Bitte nicht mehr einsteigen!\n";
		cout << "\nDies war der " << i_zaehler << " Durchlauf!\n\n";
		i_zaehler++;
		cout << "Nächste Runde? (y/n): ";
		cin >> c_nochmal;
		if(c_nochmal == 'y' || c_nochmal == 'Y')
		{
			b_tester = true;
		}
		else
		{
			b_tester = false;
		}
	}

	getchar();
	getchar();
	return 0;
}
