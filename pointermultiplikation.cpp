//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h> 

//std:: - globalgenutzt
using namespace std;

//MainMethode
int main()
{
  int Faktor1 = 0;
  int Faktor2 = 0;

  int *p_Faktor1 = &Faktor1;
  int *p_Faktor2 = &Faktor2;

  cout << "Multiplikation mit Zeigern\n\n";
  cout << "Faktoreingabe: ";
  cout << "\nFaktor 1: ";
  cin >> Faktor1;
  cout << "Faktor 2: ";
  cin >> Faktor2;
  cout << "Das Produkt von " << Faktor1 << " und " << Faktor2 << " ist " << *p_Faktor1 * *p_Faktor2 << '\n';
  return 0;
}
