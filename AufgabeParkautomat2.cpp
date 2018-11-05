#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	//Variablen
	int i_Zeit = 0;
	float f_Betrag = 0.0; //Zahlbetrag
	char c_Taste = ' ';   //Taste
	const int i_Takt = 15;//Zeittakt
	const float f_Einheit = 0.5;
  float f_Guthaben = 0.0;

  double nettowert(double d_brutto);

	//Eingabe
	cout << "\t\t\t-----------------Parkautomat-----------------";
	cout << "\n\t\t\tUm einen Parkschein ueber 15 Minuten zu loesen, ";
	cout << "\n\t\t\t\tmusst du die Taste p druecken \n\t\t\t";
	cout << "\tGuthaben eingeben:\n\t\t\t\t";
  cin >> f_Guthaben;
  //Verarbeitung
	while(true)
	{
    cout << "Eingabe: \n\t\t\t";
    cin >> c_Taste;
	  if ( (c_Taste == 'p' || c_Taste == 'P') && i_Zeit < 120 )
	  {
		  i_Zeit = i_Zeit + i_Takt;
      f_Betrag = f_Einheit*i_Zeit/i_Takt;
      cout << "\n\t\t\tParkzeit: " << i_Zeit;
      cout << "\n\t\t\tBetrag: " << f_Betrag;
		}
	  if( (c_Taste == 'o' || c_Taste == 'O') && i_Zeit > 0)
    {
      if(f_Guthaben >= f_Betrag)
      {
        f_Guthaben = f_Guthaben - f_Betrag;
        cout << "\n\t\t\tNettowert: " << nettowert(f_Betrag);
        cout << "\n\t\t\tBrutto: " << f_Betrag;
        cout << "\n\t\t\tGuthaben: " << f_Guthaben;
        cout << "\n\t\t\tParkzeit: " << i_Zeit;
      }
      else 
      {
        cout << "\n\t\t\tGuthaben reicht nicht aus!";
      }
    }
    else
    {
      cout << "\n\t\t\tZeitüberschreitung oder falsche Taste";
    }
  }
  getchar();
	getchar();
	return 0;	
}

double nettowert(double d_br)
{
  return d_br / 1.19;
}
