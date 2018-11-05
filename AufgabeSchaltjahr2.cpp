#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	//Varivablen
	int i_Jahr = 0;
	//Eingabe
	cout << "Gib das Jahr ein: ";
	cin >> i_Jahr;
	//Verarbeitung
	if( i_Jahr%4 == 0)
	{
		if(i_Jahr%100 == 0)
		{
			if(i_Jahr%400 == 0)
			{
				cout << "Das Jahr " << i_Jahr << " ist ein Schaltjahr!";
			}
			else
			{
				cout << "Das Jahr " << i_Jahr << " ist kein Schaltjahr!";
			}
		}
		else
		{
			cout << "Das Jahr " << i_Jahr <<" ist ein Schaltjahr!";
		}	
	}	
	else
	{
            	cout << "Das Jahr " << i_Jahr <<" ist kein Schaltjahr!";
	}
	
	getchar();
	getchar();

	return 0;
}