//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
int* EingabeArray(int anzahl);
double Mittelwert(int* pDaten, int laenge);
void Ausgabe(int* pDaten, int laenge);
int* Arrayresize(int* pDaten, int laenge, char c);

//MainMethode
int main()
{
  //Attribute
  int laenge=0;
	int *pZahlen = NULL;
  char c_taste = 'y';
  char gk_taste = ' ';

	//Header
	if(system("CLS"))system("clear");
  cout << " Mittelwertberechnung";
  cout << "\n----------------------\n";

  //Arraylaenge eingeben
  cout << "Werteanzahl: ";
  cin >> laenge;

  //Werteeingabe
  pZahlen = EingabeArray(laenge);

  //Werteausgeben und Mittelwert berechnen
  Ausgabe(pZahlen, laenge);
  cout << "Mittelwert " << Mittelwert(pZahlen, laenge) << "\n\n";

  //Array bearbeiten
  do{
    cout << "Zahlen bearbeiten? (y/n)> ";
    cin >> c_taste;
    if(c_taste == 'y')
    {
      //Vergrößern oder Verkleinern abfragen
      do{
        cout << "Vergrößern oder verkleinern? (g/k)> ";
        cin >> gk_taste;
      } while (gk_taste != 'g' && gk_taste != 'k');
      //Methodenaufruf zum vergrößern oder verkleinern
      pZahlen = Arrayresize(pZahlen, laenge, gk_taste);
      //Länge anpassen
      if (gk_taste == 'g')
        laenge++;
      else
        laenge--;
      //Ausgabe und Mittelwert berechnen
      Ausgabe(pZahlen, laenge);
      cout << "Mittelwert " << Mittelwert(pZahlen, laenge) << "\n\n";
    }
  }while(c_taste == 'y');

  //beenden und speicher freigeben
  delete[] pZahlen;
  pZahlen = NULL;
  return 0;
}

//Methodendefinition
int* EingabeArray(int anzahl){
  int *pNeu = new int [anzahl];
  for ( int i=0; i < anzahl; i++)
  {
     cout << i+1 << ". Wert: ";
     cin >> pNeu[i];
  }
  cout << "\n";
  return pNeu;
}

double Mittelwert(int* pDaten, int laenge){
  double mittel=0;
  for (int k=0;k<laenge;k++)
  {
    mittel = mittel + *(pDaten+k);
  }
  mittel = mittel/laenge;
  return mittel;
}

void Ausgabe(int* pDaten, int laenge){
  cout << "Die Werte: ";
  for (int k=0;k < laenge; k++)
  {
    cout << *(pDaten+k) << " ";
  }
  cout << "\n";
}

int* Arrayresize(int* pDaten, int laenge, char c){
  int iNeu = 0;
  int *pNeu = NULL;
  switch(c)
  {
    //Größer machen
    case 'g':
      pNeu = new int [laenge+1];
      cout << "Neue Zahl: ";
      cin >> iNeu;
      for (int k=0;k<laenge;k++)
      {
        pNeu[k] = pDaten[k];
      }
      pNeu[laenge] = iNeu;
      break;
    //Kleiner machen
    case 'k':
      int i_stelle;
      pNeu = new int [laenge-1];
      cout << "Welche Zahl soll gelöscht werden?\n";
      for (int k=0;k<laenge;k++)
      {
        cout << k+1 << ". " << pDaten[k] << "\n";
      }
      cout << "\n";
      do {
        cin >> i_stelle;
      } while(i_stelle > laenge || i_stelle < laenge);
      for (int k=0; k<i_stelle;k++)
      {
        pNeu[k] = pDaten[k];
      }
      for (int k=i_stelle;k<laenge;k++)
      {
        pNeu[k-1]=pDaten[k];
      }
      break;
  }
  return pNeu;
}
