/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano gli alberi
 */

#include<iostream>
#include<string.h>
using namespace std;

//********************************* FUNZIONI UTILI *********************************/

//Dichiarazione di un nuovo tipo di dato
typedef char* tipo_inf;
//Confrontare due stringhe
int compare(tipo_inf s1,tipo_inf s2){
	return strcmp(s1,s2);
}
//Fare la copia da una stringa ad un altra
void copy(tipo_inf& dest, tipo_inf source){
	dest=new char[strlen(source)];
	strcpy(dest,source);
}
//Stampare la stringa passata
void print(tipo_inf inf){
	cout<<inf;
}

/************************************ ALBERI*****************************************/

//Creazione della nostro albeero tramite una struct
struct node {
    char* inf;
    node* parent;       // puntatore al nodo padre (opzione)
	node* firstChild;   // puntatore al primo figlio
	node* nextSibling;  // puntatore al prossimo fratello
};
struct node {
    tipo_inf inf;
    node* parent;       // puntatore al nodo padre (opzione)
	node* firstChild;   // puntatore al primo figlio
	node* nextSibling;  // puntatore al prossimo fratello
};

//Dichiarazione del nuovo tipo lista
typedef node* tree;             //utilizza la parola chiave typedef per definire un nuovo tipo chiamato tree. 
                                //il tipo tree è sinonimo di node*, cioè un puntatore a un oggetto di tipo node.
//Definizione del tipo di dato
tree root;

//Crea un nuovo nodo con valore informativo i (oppure con una funzione)
node* new_node(char* i) {
    node* n = new node;                                     // creazione del nuovo nodo
    n->inf = new char[strlen(i) + 1];                       // alloca spazio per la stringa, includendo il terminatore null
    strcpy(n->inf, i);                                      // copia il contenuto della stringa i nel campo informativo del nuovo nodo
    n->nextSibling = n->firstChild = n->parent = NULL;      // inizializza i puntatori a NULL
    return n;                                               // restituisce il nuovo nodo creato
}
node* new_node(tipo_inf i){
	node* n=new node;                                       // creazione del nuovo nodo
	copy(n->inf,i);                                         // copia della stringa
	n->nextSibling=n->firstChild=n->parent=NULL;            // inizializza i puntatori a NULL
	return n;                                               // restituisce il nuovo nodo creato
}

//Aggiorna p inserendo il sottoalbero radicato in c come primo figlio di p
void insert_child(tree p, tree c) {
    c->nextSibling = p->firstChild;     // il prossimo fratello di c è l'attuale primo figlio di p
    c->parent = p;                      // imposta p come padre di c
    p->firstChild = c;                  // imposta c come nuovo primo figlio di p
}
//Aggiorna n inserendo il sottoalbero radicato in t come fratello successivo di n
void insert_sibling(node* n, tree t) {
    t->nextSibling = n->nextSibling;    // il prossimo fratello di t è l'attuale prossimo fratello di n
    t->parent = n->parent;              // imposta il padre di t come lo stesso padre di n
    n->nextSibling = t;                 // imposta t come nuovo prossimo fratello di n
}

//Restituisce il contenuto informative del nodo n
char* get_info(node* n){
	return n->inf;                      // ritorno dell'informazione del nodo
}
//Restituisce il padre del nodo n
node* get_parent(node* n){
	return n->parent;                   // ritorno del padre del nodo
}
//Restituisce il primo figlio del nodo n, se esiste
node* get_firstChild(node* n){
	return n->firstChild;               // ritorno del primo figlio del nodo
}
//Restituisce il fratello successive del nodo n, se esiste
node* get_nextSibling(node* n){
	return n->nextSibling;              // ritorno del fratello successivo del nodo
}

/********************************* VISITA DFS *********************************/

// Funzione per stampare la rappresentazione serializzata di un albero e con la funzione print per stampare il contenuto informativo di un nodo (oppure senza funzione)
void serialize(tree t){
    cout << "(";                   // inizia la serializzazione con un'apertura di parentesi
    cout << get_info(t);           // stampa direttamente l'informazione del nodo corrente
    tree t1 = get_firstChild(t);   // ottiene il primo figlio del nodo corrente
    while(t1 != NULL){             // si controlla su tutti i figli del nodo corrente
        serialize(t1);             // richiama ricorsivamente la funzione serialize sul figlio
        t1 = get_nextSibling(t1);  // passa al prossimo fratello del figlio corrente
    }
    cout << ")";                   // Chiude la serializzazione con una chiusura di parentesi
}
void serialize(tree t) {
    cout << "(";                   // inizia la serializzazione con un'apertura di parentesi
    print(get_info(t));            // stampa l'informazione del nodo corrente utilizzando la funzione print
    tree t1 = get_firstChild(t);   // ottiene il primo figlio del nodo corrente
    while(t1 != NULL){             // si controlla su tutti i figli del nodo corrente
        serialize(t1);             // richiama ricorsivamente la funzione serialize sul figlio
        t1 = get_nextSibling(t1);  // passa al prossimo fratello del figlio corrente
    }
    cout << ")";                   // Chiude la serializzazione con una chiusura di parentesi
}