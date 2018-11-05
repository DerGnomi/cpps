#include <iostream>
#include <string>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    char c_buchstabe = ' ';
    cout << "Gib bitte einen Kleinbuchstaben ein: ";
    cin >> c_buchstabe;
    while(c_buchstabe < 96 || c_buchstabe >123)
    {
        cout << "\nDas ist kein Kleibuchstabe! Gib bitte einen Kleinbuchstaben ein: ";
        cin >> c_buchstabe;
    }
    cout << "Der zugehörige Großbuchstabe lautet: " << (char)(c_buchstabe - 32) << '\n';
   
    getchar();
    getchar();
}
