/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano gli alberi binari (BST)
 */

#include<iostream>
#include<string.h>
using namespace std;

/********************************ALBERI BINARI********************************/

//Definizione della struttura nodo
struct bnode {
    int inf;
    bnode* left;        // nodo sinistro
    bnode* right;       // nodo destro
    bnode* parent;      // collegamento al padre
};
//Dichiarazione del tipo di dato binary tree
typedef bnode* btree;

/****************************ALBERI BINARI DA RICERCA***************************/

//Definizione dei principali tipi dell'albero
typedef int tipo_key;       // chiave
typedef char* tipo_inf;     // informazione
//Definizione della struttura dati 
struct bnode {
    tipo_key key;           
    tipo_inf inf;
    bnode* left;            // nodo sinistro
    bnode* right;           // nodo destro
    bnode* parent;          // collegamento al padre
};
//Dichiarazione del tipo di dato binary search tree
typedef bnode* bst;

/**************************FUNZIONI UTILI ***********************/

//Funzione che copia il valore passato in quello nuovo
void copy(tipo_inf& dest, tipo_inf source){
	dest=new char[strlen(source)];      // allocazione del nuovo spazio di memoria di destinazione
	strcpy(dest,source);                // copia il contenuto di source in dest
}
//Stampare la stringa passata
void print(tipo_inf inf){
	cout<<inf;
}

/****************************PRIMITIVE***************************/

//Funzione che crea un nuovo nodo con chiave e contenuto informativo dato
bnode* bst_newNode(tipo_key k, tipo_inf i){
	bnode* n=new bnode;                 // crea un nuovo nodo
	copy(n->inf,i);                     // copia l'informazione i nel campo inf del nuovo nodo
	copy_key(n->key,k);                 // copia la chiave k nel campo key del nuovo nodo
	n->right=n->left=n->parent=NULL;    // si inizializzano tutti i puntatori a NULL
	return n;                           // ritorno del nodo creato
}

//Funzione che restituisce la chiave del nodo in ingresso
tipo_key get_key(bnode* n){
	return (n->key);                    // ritorno della chiave del nodo di partenza
}

//Funzione che restituisce il valore del nodo in ingresso
tipo_inf get_value(bnode* n){
	return (n->inf);                    // ritorno del valore del nodo di partenza
}

//Funzione che restituisce il sottoalbero sinistro dell’albero in ingresso
bst get_left(bst t){
	return (t->left);                   // ritorno del nodo di sinistra
}

//Funzione che restituisce il sottoalbero destro dell’albero in ingresso
bst get_right(bst t){
	return (t->right);                  // ritorno del nodo di destra
}

//Funzione restituisce il padre dell’albero in ingresso
bnode* get_parent(bnode* n){
	return (n->parent);                 // ritorno del nodo padre
}

//Funzione che ti copia la chiave
static tipo_key copy_key(tipo_key& s,tipo_key s1){
	s=s1;                               // assegnamento il valore di s1 a s
	return s;                           // ritorno della chiave coppiata
}

//Funzione che confronta due chiavi e restituisce la differenza tra di esse
static tipo_key compare_key(tipo_key s,tipo_key s1){
		return s1-s;                    // ritorno della differenza tra le chiavi
}

//Funzione che stampa la chiave
void print_key(tipo_key k){
	cout<<k;                            // stampa della chiave
}

//Funzione che aggiunge un nodo all’albero di ricerca (con la versione ricorsiva)
void bst_insert(bst& b, bnode* n){
	bnode* x;
	bnode* y=NULL;
	if(b==NULL){
		b=n;                                                // se l'albero è ancora vuoto allora il nodo diventa nodo radice
    }
	else{
	    x=b;
	    while (x != NULL){                                  // si fa un ciclo per capire le posizione corretta da inserire il nodo
	        y=x;
	        if(compare_key(get_key(n),get_key(x))<0){       // se la chiave del nuovo nodo è minore della chiave del nodo corrente, ci si sposta a sinistra nell'albero
		        x = get_left(x);
	        }
            else{                                           // altrimenti ci si sposta sul nodo destro
		        x = get_right(x);   
	        }
	    }
	    n->parent = y;                                      // una volta trovata la posizione corretta, si assegna il nodo genitore al nuovo nodo
	    if (compare_key(get_key(n), get_key(y))<0){         // se la chiave del nuovo nodo è minore della chiave del nodo genitore, il nuovo nodo diventa il figlio sinistro
	      y->left = n;
	    }   
        else{                                               // altrimenti il nuovo nodo diventa il figlio destro
	      y->right = n;
	    }
    }
}
void bst_insert(bst& b, bnode* n){
    if(b==NULL){                                        // se l'albero è vuoto, il nuovo nodo diventa la radice
        b=n;
        return;                                         // uscita dalla funzione
    }
    if (compare_key(get_key(n),get_key(b))<0){          // confronto della chiave del nuovo nodo con la chiave del nodo corrente
        if(get_left(b)!=NULL){                          // se la chiave del nuovo nodo è minore, si inserisce nel sottoalbero sinistro
            bst_insert(b->left,n);                      // se il figlio sinistro non è NULL, si ricorre la funzione sul sottoalbero sinistro
        }
        else {                                          // se il figlio sinistro è NULL, si inserisce il nuovo nodo come figlio sinistro
            b->left=n;
            n->parent=b;
        }
    }
    else{
        if(get_right(b)!=NULL){                         // se la chiave del nuovo nodo è maggiore o uguale, si inserisce nel sottoalbero destro
            bst_insert(b->right,n);                     // se il figlio destro non è NULL, si ricorre la funzione sul sottoalbero destro
        }   
        else{
            b->right=n;                                 // se il figlio destro è NULL, si inserisce il nuovo nodo come figlio destro
            n->parent=b;
        }
    }
}

// Stampa l'albero in ordine crescente delle chiavi
void print_BST(bst b){
	if(get_left(b)!=NULL){          // stampa il sottoalbero sinistro (se esiste)
		print_BST(get_left(b));
    }
	print_key(get_key(b));          // stampa la chiave del nodo corrente
	cout<<"  ";
	print(get_value(b));            // stampa il valore informativo del nodo corrente
	cout<<endl;
	if(get_right(b)!=NULL){         // stampa il sottoalbero destro (se esiste)
	    print_BST(get_right(b));
    }
}

// Restituisce il nodo associato alla chiave in ingresso, se esiste
bnode* bst_search(bst b,tipo_key k){            // ciclo finché non trova il nodo o raggiunge una foglia
    while (b != NULL) {
	    if(compare_key(k,get_key(b))==0){       // confronta la chiave k con la chiave del nodo corrente b
	    	return b;                           // se le chiavi corrispondono, restituisce il nodo corrente
        }
	    if(compare_key(k,get_key(b))<0){        // se k è minore della chiave del nodo corrente, va al sottoalbero sinistro
		    b = get_left(b);                    // spostamento all'albero a sinistra
	    } 
        else{                                   // altrimenti
		    b = get_right(b);                   // sopstamento all'albero a destra
	    }
	}
	return NULL;
}

// Aggiorna il puntatore al figlio (sinistro o destro) del padre di p al nuovo elemento q
void update_father(bnode* p, bnode* q) {
    // Verifica se p è il figlio sinistro del suo genitore
    if (p == get_left(get_parent(p))) {         // Se p è il figlio sinistro, aggiorna il puntatore sinistro del padre di p con q
        (p->parent)->left = q;
    } 
    else {
        (p->parent)->right = q;                 // Se p è il figlio destro, aggiorna il puntatore destro del padre di p con q
    }
}

// Funzione che cancella un nodo dall’albero di ricerca
void bst_delete(bst& b, bnode* n) {
    bnode* new_child;                   // variabile d'appoggio che individua il nodo da sostituire a n come figlio

    // Caso 1: Nodo senza figli
    if (get_left(n) == NULL) {
        if (get_right(n) == NULL) {
            new_child = NULL;           // nodo foglia
        } 
        else {
            new_child = get_right(n);   // solo figlio destro
        }
    }
    // Caso 2: Nodo con solo figlio sinistro
    else{
        if (get_right(n) == NULL) {
            new_child = get_left(n);
        }
    // Caso 3: Nodo con entrambi i figli
        else {
        // Cerca l'elemento più grande nel sottoalbero sinistro di n
            bnode* app = get_left(n);
            while (get_right(app) != NULL) {
                app = get_right(app);
            }
            // Se app è una foglia
            if (get_left(app) == NULL) {
                update_father(app, NULL);
            } 
            else {  
                // Se app ha il figlio sinistro, aggiorna il padre del figlio sinistro di app
                (app->parent)->right = get_left(app);
                (app->left)->parent = get_parent(app);
            }
            // Sostituisce app con n
            app->left = get_left(n);
            app->right = get_right(n);
            // Aggiorna i puntatori dei genitori dei figli di app
            if (get_left(app) != NULL) {
                (app->right)->parent = app;
            }
            if (get_left(app) != NULL) {
                (app->left)->parent = app;
            }
            new_child = app;
        }
    }
    // Aggiorna il padre di new_child
    if (new_child != NULL) {
        new_child->parent = get_parent(n);
    }
    // Se n è la radice, aggiorna b con new_child
    if (n == b) {
        b = new_child;
    } 
    else {
    // Altrimenti, aggiorna il padre di n con new_child
        update_father(n, new_child);
    }
    // Dealloca il nodo n
    delete n;
}