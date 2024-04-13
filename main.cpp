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
		cout << "\na - afisare\nb - adaugare\nc - sortare\nf - filtrare\n0 - iesire\n"; 
		cin >> action;
		switch (action){
			// afisarea datelor originale
			case 'a':
				afisare(produs, n);
				break;

			case 'b':
				adaugare(produs, n);
				break;

			// afisarea datelor sortate
			case 'c':
				cout << "Introduceti sub-optiunea dorita: "; 
				cout << "\na - sortare dupa nume\n";
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
				cout << "\na - filtru dupa pret\n";
				cin >> action;
				switch (action)
				{
					case 'a':
						// filtru dupa pret
						sort(produs, n, minim, maxim);
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
