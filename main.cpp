#include <iostream>


using namespace std;

const int dimensioneMax=100;

//prototipi
int caricaVettore(int numeri[]);
float media(int n, int num[]);
void stampaMedia(float m);
void visualizza(int n, int num[]);
void MaggioreEMinore(int n, int num[]);
void ordinamento(int n, int v[]);
void ricercaParziale(int n, int v[]);
void ricercaTotale(int n, int v[]);
int Menu();


int main() {
    
    int n;
    float m=0.00;
    int scelta;
    int numeri[dimensioneMax];
    
    n=caricaVettore(numeri);
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                m=media(n, numeri);
                stampaMedia(m);
            break;
            case 2:
                visualizza(n, numeri);
            break;
            case 3:
                MaggioreEMinore(n, numeri);
            break;
            case 4:
                ordinamento(n, numeri);
            break;
            case 5:
                ricercaParziale(n, numeri);
            break;
            case 6:
                ricercaTotale(n, numeri);
            break;
            case 0:
                cout<<"Esci"<<endl;
            break;
            default:
                cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);
    
    return 0;
}

int Menu() {
  int scegli;
  cout<<"-----------------MENU-----------------"<<endl;
  cout<<"1-Stampa media"<<endl;
  cout<<"2-Stampa vettore"<<endl;
  cout<<"3-Visualizza maggiore e minore"<<endl;
  cout<<"4-Ordina vettore"<<endl;
  cout<<"5-Ricerca parziale"<<endl;
  cout<<"6-Ricerca totale"<<endl;
  cout<<"0-Fine"<<endl;
  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

int caricaVettore(int numeri[]) {
    
    int i=0;
    char risp;
    
    do {
        cout<<"Inserisci un elemento: ";
        cin>>numeri[i];
        cout<<"Vuoi inserire un altro elemento ? (S/N): ";
        cin>>risp;
        i++;
    }while(risp=='s'||risp=='S');
    
    return i;
    
}

float media(int n, int num[]) {
    
    float m=0.00;
    float s=0.00;
    
    for(int i=0; i<n; i++) {
        s=s+num[i];
    }
    
    m=s/n;
    
    return m;
    
}

void stampaMedia(float m) {
    cout<<"La media degli elementi del vettore e' : "<<m<<endl;
}


void visualizza(int n, int num[]) {
    
    cout<<"Gli elementi del vettore sono: "<<endl;
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<num[i]<<endl;
    }
    
    cout<<endl;
    
}


void MaggioreEMinore(int n, int num[]) {
    
    int max=num[0];
    int min=num[0];
    
    for(int i=0; i<n; i++) {
        if(num[i]>max) {
            max=num[i];
        }
        
        if(num[i]<min) {
            min=num[i];
        }
        
    }
    
    cout<<"Il valore maggiore nel vettore e' : "<<max<<endl;
    cout<<"Il valore minore nel vettore e' : "<<min<<endl;
    
    
}


void ordinamento(int n, int v[]) {
    
    int temp;
    
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(v[i]>v[j]) {
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
    cout<<"Il vettore ordinato e' : "<<endl;
    visualizza(n, v);
    
    
}


void ricercaParziale(int n, int v[]) {
    int numero;
    int i=0;
    
    
    cout<<endl;
    
    cout<<"Inserisci il numero da cercare: ";
    cin>>numero;
    while(i<n&&v[i]!=numero) {
        i=i+1;
    }
    
    if(i>=n) {
        cout<<numero<<" non e' presente nel vettore"<<endl;
    } else {
        cout<<numero<<" e' presente nel vettore e si trova in "<<i+1<<"° posizione"<<endl;

    }
    
    cout<<endl;
}



void ricercaTotale(int n, int v[]) {
    
    int numero;

    
    cout<<endl;
    
    cout<<"Inserisci il numero da ricercare: ";
    cin>>numero;
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        if(v[i]==numero) {
            cout<<"Dato trovato: "<<v[i]<<endl;
        }
    }
    
    cout<<endl;
    
}
