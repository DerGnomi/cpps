#include <iostream> 
#include <stdio.h> //Brauch nur ich!!

using namespace std;

float nettoberechnen(float f_netto);

int main()
{ 
  float f_brutto = 0;
  cout << "Nettowert berechen";
  cout << "\nGib den Brutowert ein: ";
  cin >> f_brutto;
  cout << "Der Nettowert beträgt: " << nettoberechnen(f_brutto) << "€\n";
}

float nettoberechnen(float f_br)
{
  return f_br/1.14;
}
