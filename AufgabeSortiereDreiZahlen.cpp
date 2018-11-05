#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void SortiereDreiZahlen(int&, int&, int&);
void TauscheInhalt(int&, int&);

int main()
{
  if(system("CLS"))system("clear");
  int i_Z1 = 0;
  int i_Z2 = 0;
  int i_Z3 = 0;

  cout << "Gib drei Werte ein:";
  cout << "\nWert 1: ";
  cin >> i_Z1;
  cout << "Wert 2: ";
  cin >> i_Z2;
  cout << "Wert 3 ";
  cin >> i_Z3;

  SortiereDreiZahlen(i_Z1, i_Z2, i_Z3);
  cout << "Sortierte Ausgabe: " << i_Z1 <<" "<< i_Z2 <<" "<< i_Z3 << "\n";
}

void TauscheInhalt(int &i_A1, int &i_A2)
{
  int i_help = i_A1;
  i_A1 = i_A2;
  i_A2 = i_help;
}

void SortiereDreiZahlen(int &i_B1, int &i_B2, int &i_B3)
{
  if( i_B2 > i_B3)
  {
    TauscheInhalt(i_B2, i_B3);
  }
  if( i_B1 > i_B2)
  { 
    TauscheInhalt(i_B1, i_B2);
    if( i_B2 > i_B3)
    {
      TauscheInhalt(i_B2, i_B3);
    }
  }
}
