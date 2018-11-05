//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h> 

//std:: - globalgenutzt
using namespace std;

void fuellen(char *p_char, int *p_int, int laenge);

//MainMethode
int main()
{
  int zaehler = 0;
  char a_Zeichen[21];
  char *p_Zeichen = &a_Zeichen[0];
  int a_int[20];
  int *p_int = NULL;
  p_int = a_int;
  //p_Zeichen = a_Zeichen || p_Zeichen = &a_Zeichen[0]; // geht auch
  cout << "Gib einen Zeichenstring mit bis zu 20 Zeichen ein: ";
  cin >> a_Zeichen;
  for(int i=0;i<21;i++)
  {
    cout << *(p_Zeichen+i); 
    //cout << p_Zeichen[i];
  }
  cout << '\n';
  for(int i=0;i<20;i++)
  {
    cout << *(p_int+i) << '\t';
    //cout << p_int[i];
  }
  fuellen(a_Zeichen,a_int,20);
  //for(int i=0;i<20;i++)
  //{
    ////a_int[k]=a_Zeichen[k];
    ////p_int[k] = p_Zeichen[k];
    //*(p_int+i) = *(p_Zeichen+i);
  //}
  cout << '\n';
  while(*(p_Zeichen+zaehler) != '\0')
  {
    cout << *(p_Zeichen+zaehler);
    zaehler++;
  }
  zaehler = 0;
  cout << '\n';
  for(int i=0;i<20;i++)
  {
    cout << *(p_int+i) << '\t';
  }
  cout << '\n';
  return 0;
}

void fuellen(char *p_char, int *p_int, int laenge){
  for(int i=0; i<laenge;i++)
  {
    *(p_int+i) = *(p_char+i);
  }
}
