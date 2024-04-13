using namespace std;
struct inventar{
	char cat[21], produs[16];
	double pret;
	int cantitate;
	bool disponibilitate;
};

void citire(inventar p[],int &n){
	ifstream inFile("date.in");
	inFile>>n;
	for(int i=0;i<n;i++){
		inFile>>p[i].cat>>p[i].produs>>p[i].pret>>p[i].cantitate>>p[i].disponibilitate;
	}
	inFile.close();
	
}
void afisare(inventar p[],int n){
     int nr = 1; 
	cout << setfill('-') << setw(84) << '\n';
     cout << setfill(' ');
     cout << "| " << setw(5) << "Nr." << " | "
     << setw(20) << "Categorie" << " | "
     << setw(11) << "Produs" << " | "
     << setw(10) << "Pret" << " | "
     << setw(5) << "Cant" << " | "
     << setw(8) << "Dispon" << " |" << endl;
     cout << setfill('-') << setw(84) << '\n';
     cout << setfill(' ');

     for (int i = 0; i < n; i++) {
         cout << "| "<< setw(5) << nr <<" | " 
          << setw(20) << p[i].cat << " | "
         << setw(11) << p[i].produs << " | "
         << setw(10) << p[i].pret << " | "
         << setw(5) << p[i].cantitate << " | "
         << setw(8) << p[i].disponibilitate << " |" << endl;
         nr++; 
     }
     cout << setfill('-') << setw(84) << '\n';
}
void adaugare(inventar p[],int &n){
	cout<<"Introduceti categoria: ";cin>>p[n].cat;
	cout<<"Itroduceti produs: ";cin>>p[n].produs;
	cout<<"Introduceti pretul: ";cin>>p[n].pret;
	cout<<"Introduceti cantitatea:  ";cin>>p[n].cantitate;
	cout<<"Introduceti disponibilitatea (1/0): ";cin>>p[n].disponibilitate;
	n++;
}

void sort(inventar p[],int n){
     cout << "Produsele sortate crescator dupa nume: " << endl;
     for(int i = 0; i < n - 1 ; i++){
          for(int j = 0; j < n - i - 1; j++){
               if(strcmp(p[j].produs, p[j+1].produs) > 0){
                    char temp[50];
                    strcpy(temp, p[j].produs);
                    strcpy(p[j].produs, p[j+1].produs);
                    strcpy(p[j+1].produs, temp);
               }
          }
     }
     cout << endl; 
}

void sort(inventar p[], int n, double minim, double maxim) {
     int nr = 1;
     cout << "Introduceti intervalul de preturi: "; 
     cout << endl << "Pretul minim: "; cin >> minim;
     cout << "Pretul maxim: "; cin >> maxim;
    cout << "Produsele sortate crescator dupa pret pentru intervalul de pret intre "
         << minim << " si " << maxim << ": " << endl;
         cout << setfill('-') << setw(84) << '\n';
             cout << setfill(' ') << "| " << setw(5) << "Nr." << " | " 
                 << setw(20) << "Categorie" << " | "
                 << setw(11) << "Produs" << " | "
                 << setw(10) << "Pret" << " | "
                 << setw(5) << "Cant" << " | "
                 << setw(8) << "Dispon" << " |" << endl;
          cout << setfill('-') << setw(84) << '\n';
     for (int i = 0; i < n; i++) {
         if(minim < p[i].pret && p[i].pret < maxim){
             cout << setfill(' ') << "| " << setw(5) << nr <<" | " 
              << setw(20) << p[i].cat << " | "
                 << setw(11) << p[i].produs << " | "
                 << setw(10) << p[i].pret << " | "
                 << setw(5) << p[i].cantitate << " | "
                 << setw(8) << p[i].disponibilitate << " |" << endl;
                 nr++; 
         }
     }
     cout << setfill('-') << setw(84) << '\n';
     cout << endl;
}

void filtruNume(inventar p[], int n) {
     int nr = 1;
     char produs_cautat[50];
	cout << "Introduceti produsul cautat: ";
	cin >> produs_cautat;
	cout << produs_cautat << " sunt:" << endl;
     cout << setfill('-') << setw(84) << '\n';
             cout << setfill(' ') << "| " << setw(5) << "Nr." << " | " 
             << setw(20) << "Categorie" << " | "
                 << setw(11) << "Produs" << " | "
                 << setw(10) << "Pret" << " | "
                 << setw(5) << "Cant" << " | "
                 << setw(8) << "Dispon" << " |" << endl;
          cout << setfill('-') << setw(84) << '\n';
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].produs, produs_cautat) == 0) {
             cout << setfill(' ') << "| " << setw(5) << nr <<" | " << setw(20) << p[i].cat << " | "
                 << setw(11) << p[i].produs << " | "
                 << setw(10) << p[i].pret << " | "
                 << setw(5) << p[i].cantitate << " | "
                 << setw(8) << p[i].disponibilitate << " |" << endl;
                 nr++; 
		}    
	}
     cout << setfill('-') << setw(84) << '\n';
	cout << endl;
}

void filtruCat(inventar p[], int n) {
     int nr = 1;
     char cat_cautata[50];
	cout << "Introduceti categoria cautata: ";
	cin >> cat_cautata;
	cout << "Telefoanele produs " << cat_cautata << " sunt:" << endl;
     cout << setfill('-') << setw(84) << '\n';
             cout << setfill(' ') << "| " << setw(5) << "Nr." << " | " 
             << setw(20) << "Categorie" << " | "
                 << setw(11) << "Produs" << " | "
                 << setw(10) << "Pret" << " | "
                 << setw(5) << "Cant" << " | "
                 << setw(8) << "Dispon" << " |" << endl;
          cout << setfill('-') << setw(84) << '\n';
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].cat, cat_cautata) == 0) {
             cout << setfill(' ') << "| " << setw(5) << nr <<" | "  
             << setw(20) << p[i].cat << " | "
                 << setw(11) << p[i].produs << " | "
                 << setw(10) << p[i].pret << " | "
                 << setw(5) << p[i].cantitate << " | "
                 << setw(8) << p[i].disponibilitate << " |" << endl;
                 nr++; 
		}
	}
     cout << setfill('-') << setw(84) << '\n';
	cout << endl;
}