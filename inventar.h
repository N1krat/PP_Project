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

void tab_sus(){
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
}

void afis(inventar p,int &nr){
     cout << "| "<< setw(5) << nr <<" | " 
          << setw(20) << p.cat << " | "
         << setw(11) << p.produs << " | "
         << setw(10) << p.pret << " | "
         << setw(5) << p.cantitate << " | "
         << setw(8) << p.disponibilitate << " |" << endl;
         nr++; 
}

void afisare(inventar p[],int n){
     int nr = 1; 
	tab_sus();

     for (int i = 0; i < n; i++) {
         afis(p[i], nr); 
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
    cout << "Produsele sortate crescator dupa pret pentru intervalul de pret intre "; 
    cout << minim << " si " << maxim << " sunt: " << endl;
     tab_sus();
     for (int i = 0; i < n; i++) {
         if(minim < p[i].pret && p[i].pret < maxim){
             afis(p[i], nr); 
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
          tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].produs, produs_cautat) == 0) {
             afis(p[i], nr); 
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
             tab_sus();
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].cat, cat_cautata) == 0) {
             afis(p[i], nr); 
		}
	}
     cout << setfill('-') << setw(84) << '\n';
	cout << endl;
}