#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "inventar.h"
using namespace std;
fstream inFile; 
int main(){
	inventar produs[100];int n; 
	char action; 
	float maxim, minim; 
	citire(produs, n);
	
	while(true){ 
		cout << "Introduceti optiunea dorita: "; 
		cin >> action;
		switch (action){
			// afisarea datelor originale
			case 'a':
				afisare(produs, n);
				break;

			// afisarea datelor sortate
			case 'b':
				cout << "Introduceti sub-optiunea dorita: "; 
				cin >> action;
				switch (action)
				{
					case 'a':
						// lista sortata dupa nume
						sort(produs, n);
						afisare(produs, n);
						break;
			
					default:
						cout << "Optiunea introdusa nu este valida. Reincearca.";
						break;
				}
				break;
			case 'f': 
				cout << "Introduceti sub-optiunea dorita: ";
				cin >> action;
				switch (action)
				{
					case 'a':
						// filtru dupa pret
						filtru(produs, n, minim, maxim);
						break;
					default:
						cout << "Optiunea introdusa nu este valida. Reincearca.";
						break;
				}
				break;


			case '0': 
				// iesire
				return 0; 
			default: 
				cout << "Optiunea introdusa nu este valida. Reincearca.";
				break;
		}
	} 

	return 0;
}
