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
void sterge(stoc p[], int &n, int v[], int sizev){
	for(int i=0;i<sizev;i++){
		if(v[i]!=n-1){
			for(int j=v[i]-1;j<n-1;j++){
				p[j]=p[j+1];	
			}
			for(int k=0;k<sizev;k++){
				--v[k];
			}
		}
		--n;
	}
	afisare(p, n);
}

// Functiile de sortare
void schimb(stoc* p1, stoc* p2, int size){
    for(int i = 0; i < size; i++){
        stoc temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}

void sort(stoc p[],int &n){
     int f;
     cout << "Produsele sortate dupa alfabet: " << endl;
	do{
		f=0;
		for(int i=0;i<n-1;i++){
               for(int j = 0; j < n - i - 1; j++){
                    if(strcmp(p[j].prod, p[j+1].prod) > 0){
                         schimb(&p[j], &p[j+1], 1);
                    }
               } 
		}
	}while(f!=0);
}

void schimb(stoc *p1, stoc *p2){
	stoc aux; 
	aux = *p1; 
	*p1=*p2;
	*p2=aux;
}
void sortPret(stoc p[],int &n){
    int f;
	do{
		f=0;
		for(int i=0;i<n-1;i++){
			if(p[i].pret<p[i+1].pret){
				schimb(&p[i],&p[i+1]);
				f=1;
			}
		}
	}while(f!=0);
 
}

void sortDis(stoc p[],int &n){
     int dis;
     cout << "Introduceti disponibilitatea dorita: ";
     cin >> dis; 
     int nr = 1;
     cout << "Produsele disponibile sunt:" << endl;
     tab_sus();
	for (int i = 0; i < n; i++) {
		if (p[i].disponibilitate == dis) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(92) << '\n';
     cout << "Produsele indisponibile sunt: " << endl; 
     tab_sus();
     for (int i = 0; i < n; i++){ 
          if (p[i].disponibilitate != dis){
               afis(p[i], nr);
          } 
     }
     cout << setfill('-') << setw(92) << '\n';
	cout << endl;
}

// Functiile de filtrare
void filtru(stoc p[], int n, double minim, double maxim) {
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

void filtru(stoc p[], int n) {
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

void salvare(stoc p[],int &n){
     int nr = 1; 
     string fileout; 
     cout << "Introduceti numele fisierului de iesire: "; cin >> fileout;
	fstream outFile(fileout, ios::out);
     
     outFile << setfill('-') << setw(92) << '\n';
     outFile << setfill(' ');
     outFile << "| " << setw(5) << "Nr." << " | "
     << setw(15) << "Categorie" << " | "
     << setw(11) << "Produsul" << " | "
     << setw(15) << "Tara de Orig" << " | "
     << setw(10) << "Pret" << " | "
     << setw(5) << "Cant" << " | "
     << setw(8) << "Dispon" << " |" << endl;
     outFile << setfill('-') << setw(92) << '\n';
     outFile << setfill(' ');

	for(int i=0;i<n;i++){
          outFile << "| "<< setw(5) << nr <<" | " 
          << setw(15) << p[i].cat << " | "
          << setw(11) << p[i].prod << " | "
          << setw(15) << p[i].tara << " | "
          << setw(10) << p[i].pret << " | "
          << setw(5) << p[i].cantitate << " | "
          << setw(8) << p[i].disponibilitate << " |" << endl;
          nr++; 
	}

     outFile << setfill('-') << setw(92) << '\n';
	outFile.close();
     cout << "Datele au fost salvate cu succes!" << endl;
}
