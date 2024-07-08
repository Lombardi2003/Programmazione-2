/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano le liste doppie 
 * Con le liste doppie è possibile scorrere la lista degli elementi nelle due direzioni
 * 
 * Alcune primitive sono le stesse delle liste semplici
 */

#include<iostream>
using namespace std;

//Creazione della nostra lista tramite una struct
struct elem {
    int inf;                // elemento della lista
    elem * pun;             // puntatore che punta al prossimo elemento della lista
    elem* prec;             // puntatore che punta all'elemento precedente della lista
};

//Dichiarazione del nuovo tipo lista
typedef elem* lista;                //utilizza la parola chiave typedef per definire un nuovo tipo chiamato lista. 
                                    //il tipo lista è sinonimo di elem*, cioè un puntatore a un oggetto di tipo elem.
//Definizione del tipo di dato
lista testa;                

/********************************* PRIMITIVE *********************************/

//Accesso alla testa della lista
int head(lista l){
    return l->inf;                  // ritorno del valore in testa
}
//Accesso alla coda della lista
lista tail(lista l){
    return l->pun;                  // passaggio alla coda, quindi passaggio al prossimo nodo disponibile
}
//Accesso al elemento precedente della lista
lista prev(lista p){
    return p->prec;                 // passaggio all'elemento precedente
}

//Inserimento di un elemento in testa alla lista
lista insert_elem(lista l, elem* e){
    e->pun=l;           // il nuovo elemento punta al vecchio primo elemento della lista
    if(l!=NULL){
        l->prec=e;      // se la lista non è vuota, il vecchio primo elemento punta indietro al nuovo elemento
    }
    e->prec=NULL;       // il nuovo elemento non ha un nodo precedente
    return e;           // il nuovo elemento diventa la nuova testa della lista (lista aggiornata)
}

//Eliminazione di un elemento della lista
lista delete_elem(lista l, elem* e){
    if(l==e){                       // controllo se l'elemento da eliminare è in testa
        l=tail(l);                  // eliminazione dell'elemento in testa spostando la lista    
    }
    else{
        (e->prec)->pun = e->pun;    // collegamento del nodo precedente al nodo successivo
    }
    if(e->pun!=NULL){
        (e->pun)->prec = e->prec;   // collegamento del nodo successivo al nodo precedente
    }
    delete e;                       // eliminazione dell'elemento
    return l;                       // ritorno lista aggiornata
}

//Ricerca di un elemento nella lista
elem* search(lista l, int v){
	while(l!=NULL){             // ricerca di un elemento nella lista
		if(head(l)==v){         // controllo se si trovo l'elemento si trova in testa alla lista
			return l;           // ritorno dell'elemento trovato
        }
		else{
			l=tail(l);          // se non si trova in testa, passo avanti e rifaccio il controllo
        }
    }
	return NULL;                // se l'elemento non si trova nella lista ritorna NULL
}

//Copia della lista originale in uno nuova lista
lista copy(lista l1){
    lista l=NULL;               // si inizializza la nuova lista a NULL
    elem* curr;                 // puntatore al nodo corrente
    elem* prev=NULL;            // puntatore al nodo precedente
    while(l1!=NULL){            // controllo fino a quando non finisco la lista principale
        curr = new elem ;       // creazione del nuovo nodo
        curr->inf = head(l1);   // il nuovo nodo prende l'informazione
        curr->pun=NULL;         // impostazione che il prossimo nodo è NULL
        if(prev==NULL){         // se è NULL sto creando la testa della lista
            l=curr;             // passaggio della nuova testa alla nuova lista
        }
        else{
            prev->pun=curr;     // collegamento al nodo precedente al nuovo nodo creato
        }
        prev=curr;              // aggiornamento del nodo precedente al nuovo nodo
        l1=tail(l1);            // passaggio al nodo successivo della lista originale
    }
    return l;                   // ritorno della nuova lista             
}

/********************************* FUNZIONI *********************************/

//Stampa di tutti gli elementi della lista
void stampa_lista(lista p){
    while (p != NULL) {
        cout << head(p) << " " ; // stampa valore in testa
        p = tail(p);             // spostamento sulla coda di p
    }
    cout << endl ;
}

//Funzione per la creazione della lista
lista crea_lista(int num){
    lista testa = NULL ;            // inizializza la lista come vuota
    for (int i = 1 ; i <= num ; i++) {
        elem* p = new elem ;        //creazione di un nuovo elemento della lista
        int n;
        cout<<"Inserisci un numero: ";
        cin>>n;
        p->pun = p->prec = NULL;
        testa=insert_elem(testa,p); // chiamata per l'inserimento nella lista
      }
      return testa ;
}

//Funzione per eliminare l'intera lista
void elimina_lista(lista& testa){
     while (testa != NULL){                 //controllo fino a quando la lista non è finita
           testa=delete_elem(testa,testa);  // chiamata per l'eliminazione del elemento trovato
     }
}

//Funzione di un esercizio per la creazione di una lista di due numeri a tempo di scrittura
void due_elementi() { 
    lista testa = new elem;     // creazione della lista
    testa->inf = 3;             // primo numero
    lista p = new elem;         // creazione di un elemento di appoggio            
    p->inf = 7;                 // secondo numero
    p->pun = NULL;              // inserimento del terminatore di lista
    testa->pun = p;             // collegamento tra i due numeri
    stampa_lista(testa);
}

// Funzione che conta le occorrenze di un valore nella lista
int conta(lista l, int v){
    int occ = 0;                        // numero di occorrenze inizializzate a zero
    while((l=search(l,v))!=NULL){       // controllo se ho trovato il valore
        l=tail(l);                      // sostituisco la lista primaria con la lista partendo da subito dopo che ho trovato il valore
        occ++;                          // incremento
    }
    return occ;                         // ritorno delle occorrenze
}

// Funzione che cancella dalla lista tutte le occorrenze che si trovanno al suo interno di un determinato valore
lista cancella(lista l, int v){
    elem* e;                            // definizione di un elemento
    while((e=search(l,v))!=NULL){       // trovo il valore prestabilito dove si trova e lo assegno al nuovo elemento
        l=delete_elem(l,e);             // cancello l'elemento dalla lista
    }
    return l;                           // ritorno della nuova lista
}