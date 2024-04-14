using namespace std;
struct stoc{
	char cat[21], prod[16], tara[21];
	double pret;
	int cantitate;
	bool disponibilitate;
};

void citire(stoc p[],int &n){
	ifstream inFile("date.in");
	inFile>>n;
	for(int i=0;i<n;i++){
		inFile>>p[i].cat>>p[i].prod>>p[i].tara>>p[i].pret>>p[i].cantitate>>p[i].disponibilitate;
	}
	inFile.close();
}

void tab_sus(){
	cout << setfill('-') << setw(92) << '\n';
     cout << setfill(' ');
     cout << "| " << setw(5) << "Nr." << " | "
     << setw(15) << "Categorie" << " | "
     << setw(11) << "Produsul" << " | "
     << setw(15) << "Tara de Orig" << " | "
     << setw(10) << "Pret" << " | "
     << setw(5) << "Cant" << " | "
     << setw(8) << "Dispon" << " |" << endl;
     cout << setfill('-') << setw(92) << '\n';
     cout << setfill(' ');
}

void afis(stoc p,int &nr){
     cout << "| "<< setw(5) << nr <<" | " 
     << setw(15) << p.cat << " | "
     << setw(11) << p.prod << " | "
     << setw(15) << p.tara << " | "
     << setw(10) << p.pret << " | "
     << setw(5) << p.cantitate << " | "
     << setw(8) << p.disponibilitate << " |" << endl;
     nr++; 
}

void afisare(stoc p[],int n){
     int nr = 1; 
	tab_sus();

     for (int i = 0; i < n; i++) {
         afis(p[i], nr); 
     }
     cout << setfill('-') << setw(92) << '\n';
}

// Functiile de adaugare
void adaugare(stoc p[],int &n){
	cout<<"Introduceti categoria: ";cin>>p[n].cat;
	cout<<"Itroduceti prod: ";cin>>p[n].prod;
     cout<<"Introduceti tara de origine: "; cin>>p[n].tara;
	cout<<"Introduceti pretul: ";cin>>p[n].pret;
	cout<<"Introduceti cantitatea:  ";cin>>p[n].cantitate;
	cout<<"Introduceti disponibilitatea (1/0): ";cin>>p[n].disponibilitate;
	n++;
}

// Functiile de stergere


// Functiile de sortare
void sort(stoc p[],int &n){
     int nr = 1; 
     cout << "Produsele sortate dupa alfabet: " << endl;
     for(int i = 0; i < n - 1 ; i++){
          for(int j = 0; j < n - i - 1; j++){
               if(strcmp(p[j].prod, p[j+1].prod) > 0){
                    char temp[50];
                    strcpy(temp, p[j].prod);
                    strcpy(p[j].prod, p[j+1].prod);
                    strcpy(p[j+1].prod, temp);
               }
          }
     }
     cout << endl; 
}


// Functiile de filtrare
void sort(stoc p[], int n, double minim, double maxim) {
     int nr = 1;
     cout << "Introduceti intervalul de preturi: "; 
     cout << endl << "Pretul minim: "; cin >> minim;
     cout << "Pretul maxim: "; cin >> maxim;
    cout << "Prodele filtrate in intervalul de pret: "; 
    cout << minim << " si " << maxim << " sunt: " << endl;
     tab_sus();
     for (int i = 0; i < n; i++) {
         if(minim < p[i].pret && p[i].pret < maxim){
             afis(p[i], nr); 
         }
     }
     cout << setfill('-') << setw(92) << '\n';
     cout << endl;
}

void filtruNume(stoc p[], int n) {
     int nr = 1;
     char prod_cautat[50];
	cout << "Introduceti produsul cautat: ";
	cin >> prod_cautat;
	cout << prod_cautat << " sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].prod, prod_cautat) == 0) {
             afis(p[i], nr); 
		}    
	}
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

void filtruCat(stoc p[], int n) {
     int nr = 1;
     char cat_cautata[50];
	cout << "Introduceti categoria cautata: ";
	cin >> cat_cautata;
	cout << "Produsele filtrate dupa categoria " << cat_cautata << " sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].cat, cat_cautata) == 0) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

// Functii de cautare
void cautare(stoc p[], int n) {
     int nr = 1;
     char prod_cautata[50];
	cout << "Introduceti produsul dorit: ";
	cin >> prod_cautata;
	cout << "Cautarea dorita de " << prod_cautata << " sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].prod, prod_cautata) == 0) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

void cautareDisp(stoc p[], int n) {
     int nr = 1;
     cout << "Produsele disponibile sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (p[i].disponibilitate > 0) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

void cautareCat(stoc p[], int n) {
     int nr = 1;
     char cat_cautata[50];
	cout << "Introduceti categoria cautata: ";
	cin >> cat_cautata;
	cout << "Produsele din categoria " << cat_cautata << " sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].cat, cat_cautata) == 0) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

