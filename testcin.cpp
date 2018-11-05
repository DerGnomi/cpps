//Include (Delete not used ones)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h> 

//std:: - globalgenutzt
using namespace std;

//MainMethode
int main()
{
  string input;
  string second;
  getline(cin, input);
  second = input;
  cout << input << '|' << second;
  return 0;
}
