#include <iostream> 
#include <stdio.h> //Brauch nur ich!!

using namespace std;

int main()
{	
	//Variablen
	float f_zahl1 = 0.0;
	float f_zahl2 = 0.0;
	
	//Eingabe
	cout << "---------------Taschenrechner---------------";
	cout << "\nGib eine Zahl ein: ";
	cin >> f_zahl1;
	cout << "\nGib eine zweite Zahl ein: ";
	cin >> f_zahl2;
	
	//Verarbeitung und Ausgabe
	cout << "\nDie Summe der beiden Zahlen ist: " << f_zahl1+f_zahl2; //Summe
	cout << "\nDie Differenz der beiden Zahlen ist (Zahl1-Zahl2): " << f_zahl1-f_zahl2; //Differenz
	cout << "\nDas Produkt der beiden Zahlen ist: " << f_zahl1*f_zahl2; //Produkt
	cout << "\nDer Quotient der beiden Zahlen ist (Zahl1/Zahl2): " << f_zahl1/f_zahl2; //Quotient
	
	//
	getchar();
	getchar();
	
	return 0;
}
