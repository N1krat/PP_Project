#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "inventar.h"
using namespace std;
fstream inFile; 
int main(){
	stoc produs[100];int n; 
	char action; 
	float maxim, minim; 
	citire(produs, n);
	
	while(true){ 
		cout << "Introduceti optiunea dorita: ";
		cout << "\na - afisare\nb - adaugare\nd - sortare\ne - cautare\nf - filtrare\n9 - salvarea datelor in fisier\n0 - iesire\n"; 
		cin >> action;
		switch (action){
			// afisarea datelor originale
			case 'a':
				afisare(produs, n);
				break;

			case 'b':
				adaugare(produs, n);
				break;

			case 'c': 
			break; 
			
			// afisarea datelor sortate
			case 'd':
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

			// Cautarea produselor
			case 'e': 
				cout << "Introduceti sub-optiunea dorita: "; 
				cout << "\na - cautare dupa produs\nb - cautare dupa disponibilitate\nc - dupa categorie\n";
				cin >> action;
				switch (action)
				{
					case 'a':
						cautare(produs, n);
						break;

					case 'b': 
						cautareDisp(produs, n);
						break;
					case 'c': 
						cautareCat(produs, n);
						break;
					
					default:
						cout << "Optiunea introdusa nu este valida. Reincearca.";
						break;
				}
				break;

			case 'f': 
				cout << "Introduceti sub-optiunea dorita: ";
				cout << "\na - filtru dupa pret\nb - filtru dupa nume\nc - filtru dupa categorie\n";
				cin >> action;
				switch (action)
				{
					case 'a':
						// filtru dupa interval de preturi
						sort(produs, n, minim, maxim);
						break;

					case 'b': 
						// filtru dupa produs
						filtruNume(produs, n);
						break;

					case 'c': 
						// filtru dupa categorie
						filtruCat(produs, n);
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
