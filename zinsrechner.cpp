#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iomanip>
//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
int menue(void);
float eingabeBetrag(void);
float berechneEndbetrag(float, float , int);
void berechneEndbetrag_jaehrlich(float,float,int);

//main
int main()
{
  float f_Kapital, f_Endkapital, f_Zinssatz = 0.0;
  int i_Laufzeit, i_Auswahl = 0;
  char cNochmal = ' ';
  do
  {   
    if(system("CLS"))system("clear");
    i_Auswahl = menue();
    switch(i_Auswahl)
    {
      case 1: cout << "Startkapital in Euro: ";
              f_Kapital = eingabeBetrag();
              cout << "Zinssatz in Prozent: ";
              f_Zinssatz = eingabeBetrag();
              cout << "Laufzeit in Jahren: ";
              i_Laufzeit = eingabeBetrag();
              f_Endkapital = berechneEndbetrag(f_Kapital, f_Zinssatz, i_Laufzeit);
              cout << "\nNach " << i_Laufzeit << " Jahren:\t\t" << setprecision(2) << fixed << f_Endkapital;
              break;
      case 2: cout << "Startkapital in Euro: ";
              f_Kapital = eingabeBetrag();
              cout << "Zinssatz in Prozent: ";
              f_Zinssatz = eingabeBetrag();
              cout << "Laufzeit in Jahren: ";
              i_Laufzeit = eingabeBetrag();
              berechneEndbetrag_jaehrlich(f_Kapital, f_Zinssatz, i_Laufzeit);
              break;
      default:cout << "\nDieser Menüpunkt ist nicht vorhanden!";
              break;
    }
    cout << "\n\nNoch eine Berechnung? <J/j> ";
    cin >> cNochmal;
  } while ( cNochmal == 'j' || cNochmal == 'J');

}

//Methoden
int menue()
{
  int i_eingabe = 0;
  cout << "--------------------------------------------\n";
  cout << "Bitte Menüpunkt auswählen\n\n";
  cout << "\t<1> Sparplan berechnen\n";
  cout << "\t<2> Sparplan mit jährlicher Ausgabe\n\n";
  cout << "--------------------------------------------";
  cout << "\nIhre Wahl: ";
  cin >> i_eingabe;
  return i_eingabe;
}
float eingabeBetrag()
{
  int i_eingabe = 0;
  cin >> i_eingabe;
  if( i_eingabe >= 0)
  {
    return i_eingabe;
  }
  else
  {
    return i_eingabe * (-1);
  }
}
float berechneEndbetrag(float f_AnfKap, float f_Zins, int i_Zeit)
{
  return f_AnfKap*pow(1+(f_Zins/100),i_Zeit);
}
void berechneEndbetrag_jaehrlich(float f_AnfKap, float f_Zins, int i_Zeit)
{
 for( int i=0; i<i_Zeit; i++)
 {
   f_AnfKap = f_AnfKap * (1+(f_Zins/100));
   cout << "\nNach dem " << i+1 << ".Jahr:\t\t" << setprecision(2) << fixed << f_AnfKap;
   //cout << "\nNach dem " << i+1 << ".Jahr:\t\t" << setprecision(2) << fixed << f_AnfKap*pow(1+(f_Zins/100),i+1);
 }
}
