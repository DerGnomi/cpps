//Include
#include <iostream> //for stdinout
#include <stdio.h>  //for stdinout
#include <string>   //for stringIn
#include <stdlib.h> //for srand/rand

using namespace std;

int main()
{
  int a_wurf[8][10]={0};
  int a_haeufig[6]={0};
  
  srand((unsigned int)time(NULL));
  if(system("CLS"))system("clear"); //clear screen
  for (int j=0;j<8;j++){
    for (int i=0;i<10;i++){
      a_wurf[j][i]=rand()%6+1;
      switch(a_wurf[j][i]){
        case 1: 
          a_haeufig[0]++;
          break;
        case 2:
          a_haeufig[1]++;
          break;
        case 3: 
          a_haeufig[2]++;
          break;
        case 4:
          a_haeufig[3]++;
          break;
        case 5:
          a_haeufig[4]++;
          break;
        case 6:
          a_haeufig[5]++;
          break;
        default:
          cout << "Falsche Zahl wird ausgegeben";
      }
  }
  
  cout << "--------------------------------------------";
  cout << "\n                 Würfelspiel";
  cout << "\n--------------------------------------------";
  cout << "\n\nDie gewürfelten Zahlen des Spielers";
  cout << "\n\nSpieler 1: ";
  for (int i=0;i<10;i++){
    cout << "   " << a_wurf[i];
  }
  cout << "\n\nZiehhäufigkeitg der Zahlen 1-6:";
  for (int i=0;i<6;i++){
    cout << "\nDie Zahl "<< i+1 <<":\t" << a_haeufig[i] << " mal";
  }
  cout << "\n";
}
