//Include
#include <iostream> //for stdinout
#include <stdio.h>  //for stdinout
#include <string>   //for stringIn
#include <stdlib.h> //for srand/rand
#include <time.h>

using namespace std;

struct T_spieler{
  string name;
  int ergebnisse[10]={0};
};

int main()
{
  char c;
  int i_spielrunden = 0;
  int i_spieleranzahl = 0;
  int i_wuerfe = 10;
  int a_haeufig[6]={0};
  
  srand((unsigned int)time(NULL));
  if(system("CLS"))system("clear"); //clear screen
  i_spielrunden++;
  
  cout << "----------------------------------------------------\n";
  cout << "                Würfelspiel\n";
  cout << "----------------------------------------------------\n\n";

  cout << "Wie viele Spieler spielen mit? ";
  cin >> i_spieleranzahl;
  cout << "Wie viele Spielrunden sollen gespielt werden? ";
  cin >> i_spielrunden;

  T_spieler spieler[i_spieleranzahl];
  for (int i=0; i<i_spieleranzahl; i++)
  {
    cout << "Name Spieler " << i+1 << " eingeben: ";
    cin >> spieler[i].name;
  }
  
  do{
    cout << "--------------------Würfeln beginnt-------------------";
    for(int i_runde = 0; i_runde < i_spielrunden; i_runde++){
      cout << "\n\n----------- Runde " << i_runde+1 << "---------------------------------";
      for (int j=0;j<i_spieleranzahl;j++){
        for (int i=0;i<i_wuerfe;i++){
          spieler[j].ergebnisse[i]=rand()%6+1;
          a_haeufig[spieler[j].ergebnisse[i]-1]++;
        }
      }
      cout << "\n\nDie gewürfelten Zahlen des Spielers\n";
      for (int i=0;i<i_spieleranzahl;i++)
      {
        cout << "Spieler " << spieler[i].name << '\t';
        for (int j=0;j<i_wuerfe;j++){
          cout << "  " << spieler[i].ergebnisse[j];
        }
        cout << '\n';
      }
    }
    cout << "\n\nZiehhäufigkeitg der Zahlen 1-6:";
    for (int i=0;i<6;i++){
      cout << "\nDie Zahl "<< i+1 <<":\t" << a_haeufig[i] << " mal";
    }
    cout << "\n\n";
    cout << "Willst du das Spiel wiederholen? (y/n)> ";
    cin >> c;
  }while ( c == 'y');
  return 0;
}
