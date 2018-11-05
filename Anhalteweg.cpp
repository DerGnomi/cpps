#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Variablen Definition
float f_geschwindigkeit = 0;
float f_anhalteweg = 0;
int i_weg = 0;
int i_reaktion = 0;
int i_verzoegerung = 0;
char c_nochmal = 'y';

int i_speicher = 0;

int main()
{
	while(c_nochmal == 'y' || c_nochmal == 'Y')
	{	
		if(system("CLS"))system("clear");
		cout << "Bitte geben Sie die gefahrene Geschwindigkeit ein (km/h): ";
		cin >> f_geschwindigkeit;
		cout << "Bitte geben Sie die restliche Strecke zum Hindernis ein (m): ";
		cin >> i_weg;
		cout << "Bitte geben Sie die Reaktionzeit (Schrecksekunde ca. 1s) ein (s): ";
		cin >> i_reaktion;
		cout << "Bitte geben Sie den Verzögerungswert an\n";
		cout << "\n\t\t\t1 - Beton trocken ------ 9 m/s";
		cout << "\n\t\t\t2 - Asphalt trocken ---- 7 m/s";
		cout << "\n\t\t\t3 - Beton nass --------- 5 m/s";
		cout << "\n\t\t\t4 - Asphalt nass ------- 3 m/s\n";
		cout << "\nBitte wählen Sie einen Wert (1-4): ";
		do
		{
			cin >> i_verzoegerung;
			i_speicher = i_verzoegerung;
			switch(i_verzoegerung)
			{
				case 1: i_verzoegerung = 9;
					break;
				case 2: i_verzoegerung = 7;
					break;
				case 3: i_verzoegerung = 5;
					break;
				case 4: i_verzoegerung = 3;
					break;
				default: cout << "Falsche Eingabe! Nochmal: ";
					break;
			}
		}
		while(i_speicher > 4 || i_speicher < 1);
		f_geschwindigkeit = f_geschwindigkeit/3.6;
		f_anhalteweg = (f_geschwindigkeit *  i_reaktion) + ((f_geschwindigkeit * f_geschwindigkeit) / (2 *  i_verzoegerung));
		cout << "\nWeg bis zum Hindernis: " << i_weg;
		cout << "\nBenoetigte Anhaltestrecke: " << f_anhalteweg << "\n\n";
		if(f_anhalteweg < i_weg)
		{
			cout << "Glueck gehabt!";
		}
		else
		{
			cout << "Crash!";
		}
		cout << "\n\nWollen Sie noch eine Simulation durchführen? (y/Y): ";
		cin >> c_nochmal;
	}
	getchar();
	getchar();
	return 0;
}
