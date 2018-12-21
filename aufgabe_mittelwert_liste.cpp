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
T_Zahlen* AddZahl(T_Zahlen* p_Anfang, int i_Zahl);
T_Zahlen* DeleteZahl(T_Zahlen* p_Anfang, int i_Zahl);
T_Zahlen* Liste_Fuellen(
  int laenge);
void Liste_Ausgeben(T_Zahlen* p_Anfang);
void Mittelwert_berechnen(T_Zahlen* p_Anfang);
void Mittelwert_helfer(T_Zahlen* p_Anfang, int i_laenge, double d_mittelwert);

//MainMethode
int main()
{
  int laenge=0;
  int eingabe = 0;
  char c_taste = 'y';
  char gk_taste = ' ';

  if(system("CLS"))system("clear");
  cout << " Mittelwertberechnung";
  cout << "\n----------------------\n";

  cout << "Werteanzahl: ";
  cin >> laenge;
	T_Zahlen *p_Anfang=NULL;
  p_Anfang = new T_Zahlen;

  //Liste auffüllen
  p_Anfang = Liste_Fuellen(laenge);

  //Liste Ausgeben
  cout << "\n" << "\tListe:";
  cout << "\n----------------------\n";
  Liste_Ausgeben(p_Anfang);
  cout << "\n";
  Mittelwert_berechnen(p_Anfang);
  //Zahl hinzufügen oder löschen
  do{
    cout << "Zahlen bearbeiten? (y/n)> ";
    cin >> c_taste;
    if(c_taste == 'y')
    {
      cout << "Willst du eine Zahl hinzufügen oder löschen? (g/k)> ";
      cin >> gk_taste;
      cout << "Gib eine Zahl ein: ";
      cin >> eingabe;
      if(gk_taste == 'g'){
        p_Anfang = AddZahl(p_Anfang, eingabe);
      }
      else{
        p_Anfang = DeleteZahl(p_Anfang, eingabe);
      }
      cout << "\n" << "\tListe:";
      cout << "\n----------------------\n";
      Liste_Ausgeben(p_Anfang);
      cout << "\n";
      Mittelwert_berechnen(p_Anfang);
    }
  }while(c_taste == 'y');
  delete[] p_Anfang;
  p_Anfang = NULL;
  return 0;
}

//Methodendefinition

T_Zahlen* Liste_Fuellen(int laenge){
  T_Zahlen* Zusatz = NULL;
  if(laenge != 0){
    Zusatz = new T_Zahlen[laenge];
    for (int i=0; i< laenge; i++)
    {
      cout << i+1 << ". Wert: ";
      cin >> Zusatz[i].Zahl;
    }
    for (int i = 0; i < laenge-1; i++)
    {
      Zusatz[i].pnext = &Zusatz[i+1];
    }
  }
  return Zusatz;
}

T_Zahlen* AddZahl(T_Zahlen* p_Anfang, int i_Zahl){
  if(p_Anfang != NULL){
    if((*p_Anfang).pnext != NULL)
      (*p_Anfang).pnext = AddZahl((*p_Anfang).pnext, i_Zahl);
    else{
      T_Zahlen *n_Knoten=NULL;
      n_Knoten = new T_Zahlen;
      (*n_Knoten).Zahl = i_Zahl;
      (*p_Anfang).pnext = &(*n_Knoten);
    }
  }
  else{
    T_Zahlen *n_Knoten=NULL;
    n_Knoten = new T_Zahlen;
    (*n_Knoten).Zahl = i_Zahl;
    p_Anfang = &(*n_Knoten);
  }
  return p_Anfang;
}

T_Zahlen* DeleteZahl(T_Zahlen* p_Anfang, int i_Zahl){
  if(p_Anfang != NULL){
    if((*p_Anfang).Zahl == i_Zahl){
      p_Anfang = (*p_Anfang).pnext;
    }
    else{
      (*p_Anfang).pnext = DeleteZahl((*p_Anfang).pnext, i_Zahl);
    }
  }
  return p_Anfang;
}

void Liste_Ausgeben(T_Zahlen* p_Anfang){
  if(p_Anfang != NULL){
    cout << (*p_Anfang).Zahl << " ";
    if((*p_Anfang).pnext != NULL )
      Liste_Ausgeben((*p_Anfang).pnext);
  }
}

void Mittelwert_berechnen(T_Zahlen* p_Anfang){
  if(p_Anfang != NULL){
    Mittelwert_helfer((*p_Anfang).pnext,1,(*p_Anfang).Zahl);
  }
}

void Mittelwert_helfer(T_Zahlen* p_Anfang, int i_laenge, double d_mittelwert){
  if(p_Anfang != NULL){
    if((*p_Anfang).pnext != NULL)
      Mittelwert_helfer((*p_Anfang).pnext, ++i_laenge, d_mittelwert+(*p_Anfang).Zahl);
    else{
      d_mittelwert += (*p_Anfang).Zahl;
      cout << "Der Mittelwert beträgt: " << d_mittelwert/(i_laenge+1) << "\n";
    }
  }
  else{
    cout << "Der Mittelwert beträgt: " << d_mittelwert << "\n";
  }
}
