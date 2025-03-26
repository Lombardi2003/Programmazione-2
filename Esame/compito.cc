#include<iostream>
#include<fstream>
using namespace std;

#include"liste.h"

/**
 * @mainpage DOCUMENTAZIONE ESAME 17/07/2024 .
 * il progetto fa uso di liste doppie dove sono salvati una serie di carte da gioco,
 * le quali sono salvate in due liste [mani da gioco], una per il giocatore 1 e l'altra per il giocatore 2;
 * le informazioni delle carte del giocatore 1 sono custodite nel file g1.txt;
 * le informazioni delle carte del giocatore 2 sono custodite nel file g2.txt;
*/


/**
 * Funzione pesca. 
 * Ha lo scopo di aggiongere alla lista in mano ad un giocatore una nuova carta
 * con valore v e seme s;
 * @param l lista di un giocatore che sta pescando una carta
 * @param v il valore della carta pescata dal giocatore
 * @param s il seme della carta pescata dal giocatore
*/
void pesca(lista& l, int v, char s){
    elem* nuovo = new elem ;        //creazione di un nuovo elemento della lista
    nuovo->inf.valore = v;
    nuovo->inf.seme = s;
    nuovo->pun = nuovo->prev = NULL;
    l = insert_elem(l,nuovo);
}

/**
 * Funzione stampa. 
 * Ha lo scopo di stampare e confrontare le due liste di mani di entrambi i giocatori,
 * stampando che le carte nella stessa posizione, la n carta del giocatore 1 è minore/maggiore/uguale
 * alla n carta del giocatore 2
 * @param g1 lista della mano del giocatore 1
 * @param g2 lista della mano del giocatore 2
*/
void stampa(lista g1,lista g2){
    while (g1 != NULL) {
        cout<<head(g1).valore<<" "<<head(g1).seme<<" ";
        if(compare(g1->inf,g2->inf)<0){
            cout<<"minore di ";
        }
        else{
            if(compare(g1->inf,g2->inf)==0){
                cout<<"uguale di ";
            }
            else{
                cout<<"maggiore di ";
            }
        }
        cout<<head(g2).valore<<" "<<head(g2).seme<<endl;
        g1 = tail(g1);
        g2 = tail(g2);
    }
    cout << endl ;
}


/**
 * Funzione conta. 
 * Ha lo scopo contare il numero di occorrenze dentro un lista
 * @param l lista dove avviene il conteggio
 * @param v elemento da ricercare
*/
int conta(lista l, tipo_inf v){
    int occ = 0;                        // numero di occorrenze inizializzate a zero
    while((l=search(l,v))!=NULL){       // controllo se ho trovato il valore
        l=tail(l);                      // sostituisco la lista primaria con la lista partendo da subito dopo che ho trovato il valore
        occ++;                          // incremento
    }
    return occ;                         // ritorno delle occorrenze
}

/**
 * Funzione tris. 
 * Ha lo scopo di restiturire su quale valore, un giocatore ha un tris
 * @param carte lista della mano del giocatore da verificare dove si trovano i tris
*/
int* tris(lista carte){
    int* num = new int[13];
    char c[4] = {'C','F','P','Q'};
    for(int i=0; i<13 ;i++){
        int count=0;
        tipo_inf inf;
        inf.valore=i+1;
        for(int j=0; j<4;j++){
            inf.seme = c[j];
            count += conta(carte,inf);
        }
        if(count<3){
            num[i]=0;
        }
        else{
            num[i]=1;
        }
    }
    return num;
}
/**
 * Funzione cala. 
 * Ha lo scopo di restiturire il tris per calare con il proprio punteggio calato
 * @param carte lista della mano del giocatore da verificare i tris
*/
int cala(lista & carte){
    int* n = tris(carte);
    for(int i=0;i<13;i++){
        //controllo
    }
    return 0;
}

int main(){
    lista g1 = NULL;
    lista g2 = NULL;
    int dim;
    cout<<"Inserire il numero di carte da far pescare ad entrambi i giocatori: ";
    cin>>dim;
    ifstream f1("g1.txt");
    for(int i=0; i<dim ;i++){
        int v;
        char s;
        f1>>v;
        f1.ignore();
        f1>>s;
        pesca(g1,v,s);
    }
    f1.close();
    ifstream f2("g2.txt");
    for(int i=0; i<dim ;i++){
        int v;
        char s;
        f2>>v;
        f2.ignore();
        f2>>s;
        pesca(g2,v,s);
    }
    f2.close();

    cout<<endl<<"PUNTO 1"<<endl;
    stampa(g1,g2);

    cout<<endl<<"PUNTO 2.a"<<endl;
    int* t1 = tris(g1);
    int* t2 = tris(g2);
    cout<<"Giocatore 1: ";
    for(int i=0; i<dim ; i++){
        cout<<t1[i]<<" ";
    }
    cout<<endl;
    cout<<"Giocatore 2: ";
    for(int i=0; i<dim ; i++){
        cout<<t2[i]<<" ";
    }
    cout<<endl;

    cout<<endl<<"PUNTO 2.b"<<endl;
    while(true){
        elem* nuovo;
        cout<<"Pesca del Giocatore 1\nValore: ";
        cin>>nuovo->inf.valore;
        cout<<"Seme: ";
        cin>>nuovo->inf.seme;
        insert_elem(g1,nuovo);
        if(cala(g2)==0){
            cout<<"Fine gioco";
            return 0;
        }
        cout<<"Pesca del Giocatore 2\nValore: ";
        cin>>nuovo->inf.valore;
        cout<<"Seme: ";
        cin>>nuovo->inf.seme;
        if(cala(g2)==0){
            cout<<"Fine gioco";
            return 0;
        }
    }
    
}