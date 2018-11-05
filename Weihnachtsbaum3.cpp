
//Include
	#include <iostream> //for stdinout
	#include <stdio.h>  //for stdinout
	#include <string>   //for stringIn
	#include <stdlib.h> //for srand/rand

using namespace std;

int main()
{
	//Var
	int i_height = 0;
	int i_storage = 0;
	int i_storage2 = 0;
	int i_strand = 0; //Storage randomized numb
	bool b_tester = true;
	string s_yn = " ";
	//Randomizer
	srand((unsigned int)time(NULL));
	
	
	//Tree:
	while(b_tester == true)	//Endlosschleife
	{
		cout << "\033[1;32m";
		do //Input
		{	
			if(system("CLS"))system("clear"); //clear screen
			cout << "Colored xmas tree.  Height (5-80): ";		
			cin >> i_height;
		} while (i_height < 5 || i_height > 80);
		i_storage2 = 0;	
		i_storage = ((i_height / 5) * 3) + 1;
		for(int i = 0; i < i_height; i++) //tree
		{
			cout << '\n';
			for(int k = 0; k < i_storage -  i_storage2 ; k++)
			{
				cout << " ";		//Output space
			}
			cout << 'X';
			
			for(int k = 0; k < i_storage2*2 ; k++)
			{			
				if(rand()%5 == 3 )		//Randomlocation for candles and balls
				{
					if(rand()%2 == 1)	//candle and ball
					{
						cout << "\033[33m" << "I" << "\033[1;32m"; //Output candle - yellow
					}
					else
					{
						cout << "\033[31m" << "O" << "\033[1;32m"; //Output ball - red 
					}
				}
				else
				{
					cout << "X"; //leefs
				}
			}
			i_storage2++;
			if(i != 0)	//leefs getting smaller
			{
				if((i+1)%5 == 0)
				{
					i_storage2 = i_storage2 - 3;	
				}
			}
		}
		for(int i = 0; i < 3;i++) //Output root
		{
			cout << '\n' << "\033[0;33m";
            for(int j = 0; j < i_storage; j++)
            {
           		cout << " ";
            }
            cout << 'H';
		}
		cout << "\n\n" << "\033[1;32m" << "One more tree? <y/n>"; //Output
		cin >>  s_yn;
		if( s_yn == "y")
		{
			b_tester = true; //One more loop
		}
		else
		{
			b_tester = false; //Exit
		}
	}
if(system("CLS"))system("clear");			
	
}
