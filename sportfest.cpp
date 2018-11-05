//Includes
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Structs zum verwalten der Sportler und der Ergebnisse
struct t_person{
  string nachname;
  string vorname;
  int i_alter;
};
struct t_sportler{
  float fa_weitsprung[3]={0};
  float fa_kugelstossen[6]={0};
  float fa_speerwerfen[6]={0};
  float f_lauf100=0;
  t_person Person;
};

int main()
{
  int i_AnzahlSportler = 0;
  char c_wiederholen = ' ';
  int i_gewinn_sportler = 0;
  int i_gewinn_versuch = 0;
  float f_gewinn_weite = 0;
  if(system("CLS"))system("clear");
  
  //Eingabe
  cout << "--------------------------------------------------------------\n";
  cout << "-------------------------- Sportfest -------------------------\n";
  cout << "--------------------------------------------------------------\n\n";

  do{
    //Daten der Sportler erfasseni
    cout << "Geben Sie die Anzahl der Athleten ein! >";
    cin >> i_AnzahlSportler;
    t_sportler Athlet[i_AnzahlSportler];
    cout << "Geben Sie die Daten der Sporter ein!\n";
    for (int i=0;i<i_AnzahlSportler;i++)
    {
      cout << i+1 << ". Sportler Vorname > ";
      cin >> Athlet[i].Person.vorname;
      cout << i+1 << ". Sportler Nachname > ";
      cin >> Athlet[i].Person.nachname;
      cout << i+1 << ". Sportler Alter > ";
      cin >> Athlet[i].Person.i_alter;
      cout << '\n';
    }
    //Disziplinen erfassen
    for(int i_versuche = 0; i_versuche < 3; i_versuche++)
    {
      for(int i_sportler= 0; i_sportler < i_AnzahlSportler; i_sportler++)
      {
        cout << Athlet[i_sportler].Person.vorname << ' ' << Athlet[i_sportler].Person.nachname << "\t Weitsprung " << i_versuche+1 << ". Versuch > ";
        cin >> Athlet[i_sportler].fa_weitsprung[i_versuche];
        if(Athlet[i_sportler].fa_weitsprung[i_versuche] > f_gewinn_weite)
        {
          f_gewinn_weite = Athlet[i_sportler].fa_weitsprung[i_versuche];
          i_gewinn_sportler = i_sportler;
          i_gewinn_versuch = i_versuche;
        }
      }
    }
    //Ergebnis Ausgabe
    cout << "\n---------- Ergebnisse -------------\n";
    for(int i_sportler=0;i_sportler < i_AnzahlSportler; i_sportler++)
    {
      float besteWeite = 0;
      int versuchnr = 0;
      for(int i_versuche = 0; i_versuche < 3; i_versuche++)
      {
        if(Athlet[i_sportler].fa_weitsprung[i_versuche] > besteWeite)
        {
          besteWeite = Athlet[i_sportler].fa_weitsprung[i_versuche];
          versuchnr = i_versuche+1;
        }
      }
      cout << "Der weiteste Sprung des Sportlers " << Athlet[i_sportler].Person.vorname << ' ' << Athlet[i_sportler].Person.nachname << " \twar Sprung " << versuchnr << " mit einer Weite von \t" << besteWeite << "m\n\n";
    }
    cout << "------------ Sieger ---------------\n\n";
    cout << "Der Sportler " << Athlet[i_gewinn_sportler].Person.vorname << ' ' << Athlet[i_gewinn_sportler].Person.nachname << " hat mit dem \t " << i_gewinn_versuch+1 << " Versuch die beste Weite von \t" << f_gewinn_weite << "m erreicht!\n\n";
    cout << "Willst du noch ein Sportfest machen? (y/n)> " ;
    cin >> c_wiederholen;
  }while (c_wiederholen == 'y');
  return 0;
}

