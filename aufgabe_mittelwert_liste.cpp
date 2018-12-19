//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

//std:: - globalgenutzt
using namespace std;

//Strukturen
struct T_Zahlen{
  int Zahl;
  T_Zahlen *pnext;
};

//Methodenfestlegung
T_Zahlen* AddZahl(int i_Zahl, T_Zahlen* p_Anfang);
void Liste_Fuellen(T_Zahlen* p_Anfang, int laenge);
void Liste_letzen_finden(T_Zahlen* p_Anfang);
#double Mittelwert()

//MainMethode
int main()
{
  int laenge=0;
  char c_taste = 'y';
  #char gk_taste = ' ';

  if(system("CLS"))system("clear");
  cout << " Mittelwertberechnung";
  cout << "\n----------------------\n";

  cout << "Werteanzahl: ";
  cin >> laenge;
	T_Zahlen *p_Anfang=NULL;
  p_Anfang = new T_Zahlen;

  //Liste auffüllen
  Liste_Fuellen(p_Anfang, laenge);
}

//Methodendefinition

void Liste_Fuellen(T_Zahlen* p_Anfang, int laenge){
  for (int i=0; i< laenge; i++)
  {
      T_Zahlen *p_Zusatz=NULL;
      p
  }
}

void Liste_letzen_finden(T_Zahlen* p_Anfang){
  while()
}
