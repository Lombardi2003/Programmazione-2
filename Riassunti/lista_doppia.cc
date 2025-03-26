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

//Funzione per la navigazione tra gli elementi presenti all'interno di una lista
void naviga(elem* e) {                              // prende un puntatore a un elemento della lista (elem* e) come argomento
	char scelta;                                    // dichiara una variabile scelta di tipo char per memorizzare l'input dell'utente.
	cout<< "Trovato!!";
	do {
		cout<< "Cosa vuoi fare (B per backward (muoversi indietro), F per forward (muoversi avanti), S per stop)"<<endl;
		cin>>scelta;
	    if(scelta=='F' && tail(e)!=NULL) {          // se l'utente sceglie 'F' e l'elemento corrente ha un successivo (tail(e) != NULL), stampa il valore del successivo elemento e aggiorna e per puntare al successivo.
	    	cout<<head(tail(e))<<endl;
	    	e=tail(e);
        }
	    else
	    	if(scelta=='B' && prev(e) !=NULL) {     // se l'utente sceglie 'B' e l'elemento corrente ha un precedente (prev(e) != NULL), stampa il valore del precedente elemento e aggiorna e per puntare al precedente.
	    		cout<<head(prev(e))<<endl;
	    		e=prev(e);
            }
	    else cout<<"Elemento non esistente!!"<<endl;    // se l'utente sceglie 'F' ma non c'è un successivo o sceglie 'B' ma non c'è un precedente, stampa un messaggio di errore.
    }		
    while(scelta!='S');                                 // il ciclo continua finché l'utente non inserisce 'S' per fermarsi.
}

/***************************************************ESEMPIO MAIN **********************************************/

int main()
{
    int n, v;               // numero di elementi (n), valore da inserire o cercare (v)
    int scelta;             // la scelta dell'utente (scelta) e il 
    lista testa=NULL;       // il puntatore alla testa della lista (testa)
    elem* ris;              // puntatore all'elemento trovato (ris).
    do {
    	cout<<"Cosa vuoi fare?"<<endl;
    	cout<<"1: Creare una lista"<<endl;
    	cout<<"2: Cancellare valori dalla lista"<<endl;
    	cout<<"3: Stampare la lista"<<endl;
    	cout<<"4: Cercare valori nella lista"<<endl;
    	cout<<"5: Esci"<<endl;
    	cin>>scelta;
    	switch(scelta) {
    	    case 1:         // l'utente specifica il numero di elementi, e la lista viene creata chiamando crealista(n).
                cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    		    cin >> n;
    		    testa = crea_lista(n);
    		break;
    		case 2:         // l'utente specifica il valore da cancellare, e la funzione cancella(testa, v) viene chiamata per rimuovere tutti gli elementi con quel valore.
                cout<<"Inserire il valore da cancellare:"<<endl;
    		    cin>>v;
    		    testa=cancella(testa,v);
    		break;
    		case 3:         // viene chiamata la funzione stampalista(testa) per stampare il contenuto della lista. 
                stampa_lista(testa);
    		break;
    		case 4:         // l'utente specifica il valore da cercare, e se l'elemento viene trovato, viene chiamata la funzione naviga(ris) per permettere la navigazione tra gli elementi.
                cout << "Valore da cercare"<<endl;
    		    cin>>v;
   			    ris=search(testa,v);
    		    if(ris!=NULL)
    			    naviga(ris);
    		    else
    			    cout<<"Valore non presente"<<endl;
    		break;
    		case 5:         // messaggio di uscita
                cout<<"Ciao ciao!!"<<endl;}
    	}
		while(scelta!=5);
		// non dimenticare di deallocare la memoria della lista quando non serve più (deallocare la memoria della lista prima di terminare il programma è importante per evitare perdite di memoria)
        while (testa != NULL) {     // il ciclo continua fino a quando testa non è NULL
            elem* temp = testa;     // viene creato un puntatore temporaneo temp che punta all'elemento attuale della testa.
            testa = tail(testa);    // la testa viene aggiornata per puntare al prossimo elemento della lista (tail(testa)).
            delete temp;            // il nodo puntato da temp viene deallocato usando delete.
        }
    return 0;
}