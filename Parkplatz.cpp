//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <array>

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
void FeldAusgabe();
void ParkplatzBelegen();
void Menue();
void sortierteAusgabe();
void ParkplatzFreigeben();

//GlobaleVaribalen
int a_index_pp[50] = {0};
int a_lkw_pp[50] = {0};
int a_stunden[50] = {2101,183,9123,4102,124,1234,5345,64232,1239,56332,1234,5512,5127,9123,712,512,61,1251,635,9381,3532,9183,5122,59,1225,3521,6693,124,632,6865,9304,5812,512,6221,52344,12,5991,352,1245,1858,5886,4203,6234,6609,623,2395,152,5898,5819,51235};

//MainMethode
int main()
{
  bool b_wd = false;
  int i_epn = 0;
  char c_wd = ' ';
  for ( int i = 0; i < 50; i++)
  {
    a_index_pp[i] = i+1;
  }
  do{
    if(system("CLS"))system("clear");
    //Ausgabe
    cout << "\033[0m";
    FeldAusgabe();
		//Parkplatz belegen
		Menue();
    cout << "\nWiederholen? <y/n>";
    cin >> c_wd;
    if ( c_wd == 'y')
    {
      b_wd = true;
    }
    else 
    {
      b_wd = false;
    }
  } while ( b_wd == true);
}

//Methodendefinition
void FeldAusgabe(){ 
  bool b_gr1000 = false;
  for( int i = 0; i < 50 ; i++)
  {
    if(a_stunden[i] >= 1000 )
    {
      b_gr1000 = true;
    }
  }
   cout << "Belegung:\n\n";
    for( int i = 0; i < 50 ; i++)
    {
      if ( i%3 == 0 && i != 0)
      {
        cout << "\n";
      }
      cout << "\033[0;m" << "P-NR: ";
      if ( i < 9)
      {
        cout << " ";
      }
      cout << i+1 << " = ";
      if ( a_lkw_pp[i] == 0)
      {
        cout << "\033[1;32m" << "frei\t\t" <<"\033[0;m";
      }
      else if( a_lkw_pp[i] == 1)
      {
        cout << "\033[0;31m" << "belegt\t" << "\033[0;m";
      }
      else
      {
        cout << "\033[1;33m" << "reserviert\t" << "\033[0;m";
      }
      cout << "{ " << a_stunden[i] << " }\t";
      if ( b_gr1000 == true && a_stunden[i] < 1000)
      {
        cout << "\t";
      }
    }  
}

void ParkplatzBelegen(){
  int i_epn = 0;
  int i_stunden = 0;
  char c_br = ' ';
	cout << "\nBitte gib den Aufenthalt in Stunden ein: ";
  cin >> i_stunden;
  if( i_stunden >= 1 && i_stunden <= 24)
  {
    cout << "\nBitte gib eine Platznummer an: ";
    cin >> i_epn;
    if ( i_epn > 50 || i_epn < 1 )
    {
      cout << "Platz nicht vorhanden";
    }
    else
    {
  	  if ( a_lkw_pp[i_epn-1] == 0)
  	  {
        cout << "Belegen oder Reservieren? <b/r> ";
        cin >> c_br;
        if ( c_br == 'b')
        {
          a_lkw_pp[i_epn-1] = 1;
          a_stunden[i_epn-1] = a_stunden[i_epn-1] + i_stunden;
          cout << "Der Parkplatz " << i_epn << " gehört Ihnen";
        }
        else if( c_br == 'r')
        {
          a_lkw_pp[i_epn-1] = 2;
          a_stunden[i_epn-1] = a_stunden[i_epn-1] + i_stunden;
          cout << "Der Parkplatz " << i_epn << " ist reserviert";
        }
        else 
        {
          cout << "Falsche Eingabe! Vorgang abgebrochen!";
        }
      }
      else
      {
        cout << "Parkplatz bereits belegt!";
      }
    }
  }
  else {
    cout << "\nDie Parkzeit muss zwischen 1h und 24h liegen!";
  }
  
}

void ParkplatzFreigeben()
{
  int i_epn = 0;
 	cout << "Parkplatz Nr angeben: ";
  cin >> i_epn;
  if ( i_epn >= 1 && i_epn <= 50)
  {
    if ( a_lkw_pp[i_epn-1] > 0 ) 
    {   
  	  a_lkw_pp[i_epn-1] = 0;
      cout << "Der Parkplatz " << i_epn << " ist wieder frei";
    }   
    else{
  	  cout << "Der Parkplatz ist bereits frei";
    }
  }
  else{
    cout << "Der Parkplatz muss zwischen 1 und 50 liegen!";
  }
}

void sortierteAusgabe()
{
  int temp = 0;
  int i_verg = 0;
  int i_tausch = 0;
  for ( int i = 0; i < 50; i++)
  {
    for ( int k = 0; k < i-1; i++)
    {
       if( a_stunden[k] > a_stunden[k+1])
       {
          temp = a_lkw_pp[k];
          a_lkw_pp[k] = a_lkw_pp[k+1];
          a_lkw_pp[k+1] = temp;
          temp = a_stunden[k];
          a_stunden[k] = a_stunden[k+1];
          a_stunden[k+1] = temp;
          temp = a_index_pp[k];
          a_index_pp[k] = a_index_pp[k+1];
          a_index_pp[k+1] = temp;
          i_tausch++;
       }
       i_verg++;
    }
  }
  cout << "\nSortierte Ausgabe: ";
  for (int i=0; i < 50; i++)
  {
    cout << "\nParkplatz Nr. " << a_index_pp[i] << "\t= " << a_stunden[i];
  }
  cout << "\nAnzahl Vergleich gesamt: " << i_verg;
  cout << "\nAnzahl Tausch gesamt: " << i_tausch;
  for (int i=0; i<50;i++)
  {
    for(int k=0;k<i-1;k++)
    {
      if( a_index_pp[k] > a_index_pp[k+1])
      {
        temp = a_lkw_pp[k];
        a_lkw_pp[k]=a_lkw_pp[k+1];
        a_lkw_pp[k+1]=temp;
        temp = a_stunden [k];
        a_stunden[k] = a_stunden[k+1];
        a_stunden[k+1] = temp;
        temp = a_index_pp[k];
        a_index_pp[k] = a_index_pp[k+1];
        a_index_pp[k+1] = temp;
      }
    }
  }
}

void Menue()
{
  char c_eingabe = ' ';
  cout << "\n==== Menue ====";
  cout << "\n(b) Belegen und Reservieren";
  cout << "\n(f) Freigeben";
  cout << "\n(s) Statistik ausgeben";
  cout << "\n\nAuswahl treffen: ";
  cin >> c_eingabe;
  if ( c_eingabe == 'b')
  {
    ParkplatzBelegen();
  }
  else if( c_eingabe == 'f')
  {
    ParkplatzFreigeben();
  }
  else if (c_eingabe == 's')
  {
    sortierteAusgabe();
  }
  else
  {
    cout << "Falsche eingabe!";
  }
}
