//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

//std:: - globalgenutzt
using namespace std;

//Methodenfestlegung
int SucheZahl(int *p_array, int laenge, int eingabe);
void Ausgabe(int eingabe, int vorhanden);
void ArrayVergleich(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_speicher);
void ArrayReihenfolge(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_array3, int laenge3);
void ArrayReihenfolgeDirekt(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_array3, int laenge3, bool reihe, int zaehler);
//GlobaleVaribalen
//int i_Beispiel = 0;


//MainMethode
int main()
{
  //ai_speicher muss mindestens so groß sein, wie das kleinste Array
  int ai_Zahlen[10]={ 5,2,6,12,56,31,78,94,21,51 };
  int ai_Vergleich[5]={ 9,21,12,78,94 };
  int ai_speicher[5]={0};
  int i_eingabe;
  int i_stelle;
  //EINGABE
  cout << "Geben Sie eine ganze Zahl zwischen 0 und 100 ein: ";
  cin >> i_eingabe;
  i_stelle = SucheZahl(ai_Zahlen,10,i_eingabe);
  Ausgabe(i_eingabe,i_stelle);
  cout << " ----- Arrayvergleich Zahlen -----  \n\n";
  ArrayVergleich(ai_Zahlen,10,ai_Vergleich,5,ai_speicher);
  for(int i=0;i<5;i++)
  {
    if(ai_speicher[i] != 0)
    {
      cout << ai_speicher[i] << " ";
    }
  }
  cout << "\n\n";
  cout << " ----- Arrayvergleich Reihenfolge -----  \n\n";
  ArrayReihenfolge(ai_speicher,5,ai_Vergleich,5,ai_Zahlen,10);
  cout << "\n\n";
  cout << " ----- Arrayvergleich direkt folgend -----  \n\n";
  ArrayReihenfolgeDirekt(ai_speicher,5,ai_Vergleich,5,ai_Zahlen,10,false,0);
  cout << "\n";
  return 0;
}

//Methodendefinition

void ArrayReihenfolgeDirekt(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_array3, int laenge3, bool reihe, int zaehler){
  if(reihe == false && zaehler < laenge1)
  {
    for(int i=0;i<laenge2;i++)
    {
      if(*(p_array1) == *(p_array2+i))
      {
        ArrayReihenfolgeDirekt(p_array1+1,laenge1,p_array2,laenge2,p_array3,laenge3,true,zaehler++);

      }
    }
  }
}

void ArrayReihenfolge(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_array3, int laenge3){
  int ai_Reihe[laenge1] ={0};
  int zaehler = 0;
  int pos = 0;
  for(int i=0;i<laenge1;i++)
  {
    if(*(p_array1+i) != 0)
    {
      for(int k=pos;k<laenge2;k++)
      {
        if(*(p_array1+i) == *(p_array2+k))
        {
          pos = k;
          ai_Reihe[zaehler] = *(p_array1+i);
          zaehler++;
        }
      }
    }
    else{
      break;
    }
  }
  cout << "Die Zahlen \n{";
  for(int i=0;i<laenge1;i++)
  {
    if(ai_Reihe[i+1] != 0)
    {
      cout << ai_Reihe[i] << ",";
    }
    else{
      cout << ai_Reihe[i];
      break;
    }
  }
  cout << "}\n sind in der gleichen Reihenfolge in \n{";
  for(int i=0;i<laenge3;i++)
  {
    if(i+1 != laenge3)
      cout << *(p_array3+i) << ',';
    else{
      cout << *(p_array3+i);
    }
  }
  cout << "}\n und in \n{";
  for(int i=0;i<laenge2;i++)
  {
    if(i+1 != laenge2)
      cout << *(p_array2+i) << ',';
    else{
      cout << *(p_array2+i);
    }
  }
  cout << "}\n enthalten!";
}

void ArrayVergleich(int *p_array1, int laenge1, int *p_array2, int laenge2, int *p_speicher){
  int zaehler=0;
  for(int i = 0; i< laenge1; i++)
  {
    for(int k=0; k<laenge2;k++)
    {
      if(*(p_array1+i) == *(p_array2+k))
      {
        *(p_speicher+zaehler) = *(p_array1+i);
        zaehler++;
      }
    }
  }
  cout << zaehler << " Zahlen sind in den beiden Arrays gleich\n";
}

int SucheZahl(int *p_array, int laenge, int eingabe){
  int i_ausgabe=0;
  for(int i=0; i < laenge; i++)
  {
    if(*(p_array+i) == eingabe)
    {
      i_ausgabe = i+1;
    }
  }
  return i_ausgabe;
}

void Ausgabe(int eingabe, int vorhanden){
  cout << "Die Zahl " << eingabe << " ist im Array ";
  if(vorhanden > 0)
  {
    cout << "an der Stelle " << vorhanden << " vorhanden";
  }
  else{
    cout << "nicht vorhanden";
  }
  cout << "\n\n";
}
