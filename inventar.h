using namespace std;
struct inventar{
	char tip[21], marca[16], culoare[11];
	double pret;
	int cantitate;
	bool disponibilitate;
};

void citire(inventar p[],int &n){
	ifstream inFile("date.in");
	inFile>>n;
	for(int i=0;i<n;i++){
		inFile>>p[i].tip>>p[i].marca>>p[i].culoare>>p[i].pret>>p[i].cantitate>>p[i].disponibilitate;
	}
	inFile.close();
	
}
void afisare(inventar p[],int n){
	cout << setfill('-') << setw(84) << '\n';
     cout << setfill(' ');
     cout << "| " << setw(20) << "Tip" << " | "
     << setw(11) << "Marca" << " | "
     << setw(10) << "Culoare" << " | "
     << setw(10) << "Pret" << " | "
     << setw(5) << "Cant" << " | "
     << setw(8) << "Dispon" << " |" << endl;
     cout << setfill('-') << setw(84) << '\n';
     cout << setfill(' ');

     for (int i = 0; i < n; i++) {
         cout << "| " << setw(20) << p[i].tip << " | "
         << setw(11) << p[i].marca << " | "
         << setw(10) << p[i].culoare << " | "
         << setw(10) << p[i].pret << " | "
         << setw(5) << p[i].cantitate << " | "
         << setw(8) << p[i].disponibilitate << " |" << endl;
     }

     cout << setfill('-') << setw(84) << '\n';
}
void adaugare(inventar p[],int &n){
	cout<<"Introduceti tipul: ";cin>>p[n].tip;
	cout<<"Itroduceti marca: ";cin>>p[n].marca;
	cout<<"Introduceti culoarea: ";cin>>p[n].culoare;
	cout<<"Introduceti pretul: ";cin>>p[n].pret;
	cout<<"Introduceti cantitatea:  ";cin>>p[n].cantitate;
	cout<<"Introduceti disponibilitatea (1/0): ";cin>>p[n].disponibilitate;
	n++;
}
void sort(inventar p[],int n){
     cout << "Telefoanele sortate crescator dupa nume: " << endl;
     for(int i = 0; i < n - 1 ; i++){
          for(int j = 0; j < n - i - 1; j++){
               if(strcmp(p[j].marca, p[j+1].marca) > 0){
                    char temp[50];
                    strcpy(temp, p[j].marca);
                    strcpy(p[j].marca, p[j+1].marca);
                    strcpy(p[j+1].marca, temp);
               }
          }
     }

     cout << endl; 
}



void filtru(inventar p[], int n, double minim, double maxim) {
     cout << "Introduceti intervalul de preturi: "; 
     cout << endl << "Pretul minim: "; cin >> minim;
     cout << "Pretul maxim: "; cin >> maxim;
    cout << "Telefoanele sortate crescator dupa pret pentru intervalul de pret intre "
         << minim << " si " << maxim << ": " << endl;
         cout << setfill('-') << setw(84) << '\n';
             cout << setfill(' ') << "| " << setw(20) << "Tip" << " | "
                 << setw(11) << "Marca" << " | "
                 << setw(10) << "Culoare" << " | "
                 << setw(10) << "Pret" << " | "
                 << setw(5) << "Cant" << " | "
                 << setw(8) << "Dispon" << " |" << endl;
          cout << setfill('-') << setw(84) << '\n';
     for (int i = 0; i < n; i++) {
         if(minim < p[i].pret && p[i].pret < maxim){
             cout << setfill(' ') << "| " << setw(20) << p[i].tip << " | "
                 << setw(11) << p[i].marca << " | "
                 << setw(10) << p[i].culoare << " | "
                 << setw(10) << p[i].pret << " | "
                 << setw(5) << p[i].cantitate << " | "
                 << setw(8) << p[i].disponibilitate << " |" << endl;
         }
     }
     cout << setfill('-') << setw(84) << '\n';
     cout << endl;
}