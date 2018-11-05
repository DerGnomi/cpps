#include <iostream> 
#include <stdio.h> //Brauch nur ich!!

using namespace std;

int add2(int z1, int z2);

int main()
{ 
  int i_Zahl1 = 0;
  int i_Zahl2 = 0;
  cout << "Gibt zwei Zahlen ein die Addiert werden sollen";
  cout << "\nZahl 1: ";
  cin >> i_Zahl1;
  cout << "Zahl 2: ";
  cin >> i_Zahl2;
  cout << "Das Ergebnis ist: " << add2(i_Zahl1, i_Zahl2) << '\n';
}

int add2(int i_z1,int i_z2)
{
  return i_z1+i_z2;
}
