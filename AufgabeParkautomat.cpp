#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int i_Zeit = 0;
	float f_Betrag = 0.0; //Zahlbetrag
	char c_Taste = ' ';   //Taste
	const int i_Takt = 15;//Zeittakt
	const float f_Einheit = 0.5;

	//Ausgabe
	cout << "\t\t\t-----------------Parkautomat-----------------";
	cout << "\n\t\t\tUm einen Parkschein ueber 15 Minuten zu loesen, ";
	cout << "\n\t\t\t\tmusst du die Taste p druecken \n\t\t\t";

	//Eingabe
	cin >> c_Taste;
	
	//Verarbeitung
	if(c_Taste == 'p' || c_Taste == 'P')
	{
		//Abfrage auf OK
		cout << "\n\t\t\tJetzt mit OK (o) bestaetigen";
		cout << "\n\t\t\toder weitere 15 Minuten mit p buchen\n\t\t\t";
                cin >> c_Taste;
		i_Zeit = i_Zeit + i_Takt;
                f_Betrag = f_Einheit*i_Zeit/i_Takt;
		if ( c_Taste == 'p' || c_Taste == 'P')
		{
			cout << "\n\t\t\tUnd jetzt mit OK (o) bestaetigen\n\t\t\t";
	                cin >> c_Taste;
        	        i_Zeit = i_Zeit + i_Takt;
                	f_Betrag = f_Einheit*i_Zeit/i_Takt;
                	if( c_Taste == 'o' || c_Taste == 'O')
                	{
                        	cout << "\n\t\t\tParkzeit: " << i_Zeit;
                        	cout << "\n\t\t\tBetrag: " << f_Betrag;
                	}
                	else
                	{
                        	cout << "\t\t\tmax. 30 Minuten";
           		}

		}
		else // o wird gedrückt
		{
			cout << "\n\t\t\tParkzeit: " << i_Zeit;
                	cout << "\n\t\t\tBetrag: " << f_Betrag;
		}
	}
	else
	{
		cout << "Sie muessen mindestens einmal die P-Taste druecken!";
	}

	getchar();
	getchar();
}
