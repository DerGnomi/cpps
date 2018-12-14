//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
void Sort(int *p_ziehung, int laenge);
void Ausgabe(int *p_ziehung, int laenge, int gesamt);
int* Ziehung(int AnzahlGesamt, int AnzahlzuZiehend);


//MainMethode
int main()
{
	srand((unsigned int)time(NULL));
	int AnzahlZuZiehendeZahlen=0;
	int AnzahlGesamtZahlen=0;
	int *pZiehung = NULL;
	char c_taste = 'y';

	do {
		if(system("CLS"))system("clear");
		do{
			cout << "Bitte geben Sie als erstes die Anzahl der zu ziehenden Zahlen ein: ";
			cin >> AnzahlZuZiehendeZahlen;
			cout << "Bitte geben Sie jetzt die Anzahl der zugrunde liegenden Zahlen ein: ";
			cin >> AnzahlGesamtZahlen;
		} while ( AnzahlZuZiehendeZahlen > AnzahlGesamtZahlen );

		//Array anlegen und mit passenden Zufallszahlen füllen
		pZiehung = Ziehung(AnzahlGesamtZahlen,AnzahlZuZiehendeZahlen);
		//Array sortieren
		Sort(pZiehung, AnzahlZuZiehendeZahlen);
		//Array ausgeben
		Ausgabe(pZiehung, AnzahlZuZiehendeZahlen, AnzahlGesamtZahlen);

		//Speicher freigeben
		delete[] pZiehung;
		pZiehung = NULL;
		cout << "\n\nNoch einmal? (y oder mit andere Taste beenden)> ";
		cin >> c_taste;
	} while(c_taste == 'y' );
	return 0;
}

//Methodendefinition
void Sort(int *p_ziehung, int laenge){
	int min = 0;
	int pos = 0;
	for( int i = 0; i < laenge-1 ; i++)
	{
		min = *(p_ziehung+i);
		pos = i;
		for (int k = i+1 ; k < laenge; k++)
		{
			if(*(p_ziehung+k) < min )
			{
				min = *(p_ziehung+k);
				pos = k;
			}
		}
		if( pos != i )
		{
			*(p_ziehung+pos) = *(p_ziehung+i);
			*(p_ziehung+i) = min;
		}
	}
}

void Ausgabe( int *p_ziehung, int laenge, int gesamt){
	cout << "Die " << laenge << " Zahlen aus " << gesamt << " sind :\n";
	for( int i = 0; i < laenge; i++)
	{
		cout << *(p_ziehung+i) << " ";
	}
}

int* Ziehung(int AnzahlGesamt, int AnzahlZuZiehend){
	int *p_anfang = new int[AnzahlZuZiehend];
	for(int i=0; i < AnzahlZuZiehend; i++)
	{
		p_anfang[i] = rand() % AnzahlGesamt+1;
		for(int k=0; k<i; k++)
		{
			if( *(p_anfang+i) == *(p_anfang+k) )
			{
				i--;
			}
		}
	}
	return p_anfang;
}
