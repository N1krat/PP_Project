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
	cout << "Datele din date.in a fost citita cu succes!" << endl; 

	while(true){ 
		cout << "Introduceti optiunea dorita: ";
		cout << "\na - afisare\nb - adaugare\nc - stergere\nd - sortare\ne - cautare\nf - filtrare\n9 - salvarea datelor in fisier\n0 - iesire\n"; 
		cin >> action;

		switch (action){
			// afisarea datelor originale
			case 'a':
				afisare(produs, n);
				break;

			// Adaugarea datelor noi
			case 'b':
				adaugare(produs, n);
				break;

			// Stergerea datelor
			case 'c': { 
				afisare(produs ,n);
				cout<<"Cite elemente doriti sa stergeti?"<<endl;
				int ids;
				cin>>ids;
				int elemt[ids];
				cout<<"Ce elemene doriti sa stergeti (nr lor din tabel): " << endl;
				for (int i=0;i<ids;i++){
					cin>>elemt[i];
				}	
				sterge(produs, n, elemt, ids);
			} 
			break; 
			
			// afisarea datelor sortate
			case 'd':
				cout << "Introduceti sub-optiunea dorita: "; 
				cout << "\na - sortare dupa pret\nb - sortare dupa nume\nc - sortare dupa disponibilitate\n";
				cin >> action;
				switch (action)
				{
					case 'a':
						// lista sortata dupa pret
						sortPret(produs, n); 
						afisare(produs, n);
						break;
					case 'b':
						// lista sortata dupa nume
						sort(produs, n);
						afisare(produs, n);
						break; 
					case 'c': 
						// lista sortata dupa disponibilitate
						sortDis(produs, n);
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
						// Cautare dupa produs
						cautare(produs, n);
						break;

					case 'b': 
						// Cautare dupa disponibilitate
						cautareDisp(produs, n);
						break;
					case 'c': 
						// Cautare dupa categorie
						cautareCat(produs, n);
						break;
					
					default:
						cout << "Optiunea introdusa nu este valida. Reincearca.";
						break;
				}
				break;

			// filtrarea
			case 'f': 
				cout << "Introduceti sub-optiunea dorita: ";
				cout << "\na - filtru dupa pret\nb - filtru dupa nume\nc - filtru dupa categorie\n";
				cin >> action;
				switch (action)
				{
					case 'a':
						// filtru dupa interval de preturi
						filtru(produs, n, minim, maxim);
						break;

					case 'b': 
						// filtru dupa produs
						filtru(produs, n);
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

			case '9':
				// salvarea datelor in fisier
				salvare(produs, n);
				break;

			case '0': 
				// iesire
				cout << "Multumim ca utilizati programul de inventar!";
				return 0; 
			default: 
				cout << "Optiunea introdusa nu este valida. Reincearca.";
				break;
		}
	} 

	return 0;
}
