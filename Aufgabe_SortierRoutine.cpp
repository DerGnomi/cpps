//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h> 

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
void InitArray(int *p_int, int laenge);
void ZeigeArray(int *p_int, int laenge);
void BubbleSort(int *p_int, int laenge);

const int MAX_ELEMENTE = 20;

//MainMethode
int main()
{
  if(system("CLS"))system("clear"); //clear screen$
  int ai_Zahlen[MAX_ELEMENTE];
  InitArray(ai_Zahlen, MAX_ELEMENTE);

  cout << "Array-Inhalt vor dem Sortieren:\n";
  cout << "------------------------------\n";
  
  ZeigeArray(ai_Zahlen, MAX_ELEMENTE);
  BubbleSort(ai_Zahlen, MAX_ELEMENTE);

  cout << "Array-Inhalt nach dem Sortieren:\n";
  cout << "-------------------------------\n";

  ZeigeArray(ai_Zahlen, MAX_ELEMENTE);

  return 0;
}

//Methoden
void InitArray(int *p_int, int laenge)
{
  srand((unsigned int)time(NULL));
  for(int i=0;i < laenge; i++)
  {
     *(p_int+i) = rand()%101;
  }
}

void ZeigeArray(int *p_int, int laenge)
{
  for(int i=0;i<laenge;i++)
  {
    cout << *(p_int+i) << "  ";
  }
  cout << '\n';
}

void BubbleSort(int *p_int, int laenge)
{
  int i_temp = 0;
  for(int i=0;i<laenge-1;i++)
  {
    for(int k=0;k<laenge-1-i;k++)
    {
      if(*(p_int+k) > *(p_int+k+1))
      {
        i_temp = *(p_int+k);
        *(p_int+k) = *(p_int+k+1);
        *(p_int+k+1) = i_temp;
      }
    }
  }
}
