//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

//std:: - globalgenutzt
using namespace std;

string eingabe(string);
int menue();

//Struct
struct t_verleih{
  string name;
  string datum;
};
struct t_buecher {
  string titel;
  string author;
  int i_seiten;
  t_verleih Ausleihe;
};

//MainMethode
int main()
{
  //Attribute
  int i_buecher = 0;
  int i_menue = 0;
  char c_abbruch = ' ';
  char c_leihe = ' ';
  string s_abfrage = "";
  //Setup
  system("clear");
  cout << "Wie viele Bücher sollen verwaltet werden?> ";
  cin >> i_buecher;
  getchar();
  t_buecher Buch[i_buecher];
  for(int i=0;i<i_buecher;i++)
  {
    cout << "\n--- Buch " << i+1 << " ---\n";
    Buch[i].titel = eingabe("Wie ist der Titel des Buchs: ");
    Buch[i].author = eingabe("Wie heißt der Author des Buchs: ");
    cout << "Gib die Seitenanzahl des Buchs an: ";
    cin >> Buch[i].i_seiten;
    getchar();
  }
  system("clear");
  //Verwaltung
  do{
    i_menue = menue();
    system("clear");
    switch(i_menue){
      case 1: 
        cout << "--- Diese Bücher sind in der Bibilothek vorhanden ---\n";
        for(int i=0; i<i_buecher;i++)
        {
          cout << '\n'<< Buch[i].titel << " von " << Buch[i].author << " mit " << Buch[i].i_seiten << " Seiten";
        }
        break;
      case 2:
        cout << "--- Buch ausleihen ---\n\n";
        for(int i=0;i<i_buecher;i++)
        {
          if(Buch[i].Ausleihe.name == "")
            cout << Buch[i].titel << "\n";
        }
        cout << "\nMöchten Sie ein Buch ausleihen? (y/n)> ";
        do{
          cin >> c_leihe;
          getchar();
          if(c_leihe < 65 || c_leihe > 90 && c_leihe < 97 || c_leihe > 122)
            cout << "Falsche Eingabe! Versuch es nochmal> ";
        } while ( c_leihe < 65 || c_leihe > 90 && c_leihe < 97 || c_leihe > 122);
        if(c_leihe == 'y')
        {
          s_abfrage = eingabe("\nGeben Sie den Buchtitel an: ");
          for(int i=0;i<i_buecher;i++)
          {
            if(Buch[i].titel == s_abfrage )
            {
              if(Buch[i].Ausleihe.name == "")
              {
                c_leihe = 'g';
                Buch[i].Ausleihe.name = eingabe("Geben Sie Ihren Namen ein: ");
                Buch[i].Ausleihe.datum = eingabe("Geben Sie das heutige Datum an: ");
                cout << "Buch ausgeliehen!\n";
              }
            }
          }
          if( c_leihe != 'g'){
            cout << "\nDas Buch konnte nicht ausgeliehen werden: "<< s_abfrage;
          }
        } 
        else{
          cout << "\nAbbruch!";
        }
        c_leihe = ' ';
        s_abfrage = "";
        break;
      case 3:
        cout << "--- Rückgabe ---\n\n";
        cout << "Folgend Bücher sind ausgeliehen! (Drücke Enter für weiter)\n";
        getchar();
        for(int i=0;i<i_buecher;i++)
        {
          if(Buch[i].Ausleihe.name != "")
          {
            cout << Buch[i].titel << "\n";
          }
        }
        s_abfrage = eingabe("Geben Sie den Buchtitel an: ");
        for(int i=0;i<i_buecher;i++)
        {
          if(Buch[i].titel == s_abfrage)
          {
            Buch[i].Ausleihe.name = "";
            cout << "Buch zurückgegeben!";
            c_leihe = 'g';
          }
        }
        if(c_leihe != 'g')
        {
          cout << "Dieses Buch gibt es nicht!";
        }
        c_leihe = ' ';
        s_abfrage = "";
        break;
      case 4:
        cout << "Programm wird beendet. ..... ";
        c_abbruch = 'a';
        break;
      default:
        cout << "Gib einen vorhandenen Menüpunkt ein!";
    }
    cout << "\n\n";
  } while ( c_abbruch != 'a');
}

string eingabe(string ausgabe)
{
  string input;
  //getchar();
  cout << ausgabe;
  getline(cin, input);
  return input;
}
int menue()
{
  int i_menue = 0;
  cout << "---- Menü ----\n";
  cout << "Welche Aktion möchten Sie ausführen?\n";
  cout << "1: Alle Bücher auflisten\n";
  cout << "2: Ein Buch ausleihen\n";
  cout << "3: Ein Buch zurückgeben\n";
  cout << "4: Verwaltung beenden\n";
  cout << "\nAktion> ";
  cin >> i_menue;
  return i_menue;
}
