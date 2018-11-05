#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

void v_secabfrage();
void v_booabfrage();
void v_ausgabe();

int i_hoehe = 0;
int i_variante = 0;
int i_speicher = 0;
bool b_tester = true;
string s_yn = " ";

int main()
{


	while(b_tester == true)
	{
		if(system("CLS"))system("clear"); //clear screen
		cout << "Gib die Variante des Weihnachtsbaumes ein(1-4): ";
		cin >> i_variante;
		while( i_variante <= 0 || i_variante >= 5 )
       	{
     		cout << "Du darfst nur 1-4 eingeben: ";
            cin >> i_variante;
        }
		if( i_variante == 1)
		{
			v_secabfrage();
			for(int i = 0; i < i_hoehe; i++)
			{
				cout << "X\n";
			}
			v_booabfrage();
		}
		else if(i_variante == 2)
		{
			v_secabfrage();
            for(int i = 0; i < i_hoehe; i++)
            {
              	cout << "\nX";
				for(int j = 1; j < i+1 ; j++)
				{
					cout << "X";
				}
            }
            v_booabfrage();
		}
		else if(i_variante == 3)
		{
			v_secabfrage(); 
			v_ausgabe();
            v_booabfrage();
		}
		else
		{
			v_secabfrage();
            v_ausgabe();
			for(int i = 0; i < 2;i++)
			{
				cout << '\n';
                for(int j = 0; j < i_hoehe -1; j++)
                {
                	cout << " ";
                }
                cout << 'H';
			}
            v_booabfrage();
		}
	}
	getchar();
	getchar();
	return 0;
}


void v_secabfrage()
{
	cout << "Weihnachtsbaum; Hoehe eingeben (5-40): ";
	cin >> i_hoehe;
	while( i_hoehe <= 4 || i_hoehe >= 41)
   	{
 	   	cout << "Hoehe nicht zwischen 5-40, neu eingeben: ";
      	cin >> i_hoehe;
    }
	cout << '\n';
}

void v_ausgabe()
{
		for(int i = 0; i < i_hoehe ; i++)
		{
			cout << '\n';
			for(int j = 0; j < (i_hoehe -1) - i ; j++)
			{
				cout << " ";
			}
			cout << 'X';
			for(int k = 1; k < (i*2)+1; k++)
			{
				cout << "X";
			}
		}	
}

void v_booabfrage()
{
	cout << "\n\nNoch ein Baum? <y/n>";
    cin >>  s_yn;         
	if( s_yn == "y")
    {
     	b_tester = true;
    }
    else
    {
      	b_tester = false;
   	}
}