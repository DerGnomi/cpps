#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
        //Variablen
        int i_Zeit = 0;
        float f_Betrag = 0.0; //Zahlbetrag
        char c_Taste = ' ';   //Taste
        const int i_Takt = 15;//Zeittakt
        const float f_Einheit = 0.5;

	while(true)
        {
		if(system("CLS"))system("clear"); //Bildschirm löschen
		//Variablen zurücksetzen
		i_Zeit = 0; f_Betrag = 0.0;
		//Anleitung
		cout << "\n\t\t\t-----------------Parkautomat-----------------";
        	cout << "\n\t\t\tUm einen Parkschein ueber 15 Minuten zu loesen, ";
        	cout << "\n\t\t\t\tmusst du die Taste p druecken \n\t\t\t";	
		//Verarbeitung
		do
		{
			cout << "\n\n\t\t\tTaste druecken: " ; cin >> c_Taste; //Taste einlesen
			if(c_Taste == 'p' || c_Taste == 'P')
			{
		        	i_Zeit = i_Zeit + i_Takt;
                		f_Betrag = f_Einheit*i_Zeit/i_Takt;
				cout << "\n\t\t\tParkzeit: " << i_Zeit << "\n\t\t\tZahlbetrag: " << f_Betrag;
			}
		
		}
		while((c_Taste == 'p' || c_Taste == 'P') && i_Zeit < 45);
		if(i_Zeit > 0)
		{	
			//Parkzettel
			cout << "\n\n\t\t\tParkzettel:" << "\n\t\t\tParkzeit: " << i_Zeit << "\n\t\t\tZahlbetrag: " << f_Betrag;
		}
		else
		{	
			//Fehlermeldung
			cout << "\n\t\t\tDu musst erst einmal P/p druecken";
		}
		//Damit das Programm den Parkzettelzeigt:
		getchar();
		getchar();
	}
	
	getchar();
	getchar();
	return 0;
}
