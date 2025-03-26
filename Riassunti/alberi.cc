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

//Funzione per stampare la rappresentazione serializzata di un albero e con la funzione print per stampare il contenuto informativo di un nodo (oppure senza funzione)
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

//Funzione per il calcolo dell'altezza di un albero
int altezza(tree t){
	if(get_firstChild(t)==NULL){        // se il nodo non ha figli
		return 0;                       // la sua altezza è 0
    }
    int max=0,max_loc;                  // si inizializzano le variabili per tenere traccia dell'altezza massima
	tree t1 = get_firstChild(t);        // si ottiene il primo figlio del nodo corrente
	while(t1!=NULL){                    // si controlla su tutti i figli del nodo corrente
		max_loc=altezza(t1);            // richiama ricorsivamente la funzione altezza sul figlio e ne memorizza il risultato
		if(max_loc>max){
			max=max_loc;                // aggiorna il massimo se l'altezza del figlio corrente è maggiore dell'altezza massima finora trovata
        }
        t1 = get_nextSibling(t1);       // si passa al prossimo fratello del figlio corrente
	}
	return max + 1;                       // restituisce l'altezza massima trovata tra i figli più 1 (per includere il nodo corrente)
}

//Funzione per il calcolo della dimensione dell'albero (DFS)
int dimensione(tree t) {
    int dim = 0, dim1;            // inizializza il contatore della dimensione a 0 e una variabile temporanea dim1
    tree t1 = get_firstChild(t);  // ottiene il primo figlio del nodo corrente
    while (t1 != NULL) {          // itera su tutti i figli del nodo corrente
        dim1 = dimensione(t1);    // calcola la dimensione del sottoalbero radicato nel figlio corrente
        dim += dim1;              // aggiunge la dimensione del sottoalbero alla dimensione totale
        t1 = get_nextSibling(t1); // passa al fratello successivo del nodo corrente
    }
    return dim + 1;               // ritorna la dimensione totale dell'albero, includendo il nodo corrente
}


/********************************* VISITA BFS *********************************/
//Per l'utilizzo delle visite BFS c'è bisogno di utilizzare una Coda

//Definizione della struttura elemBFS
struct elemBFS {
    node* inf;       // informazione contenuta nel nodo della coda, un puntatore a un nodo dell'albero
    elemBFS* pun;    // puntatore al prossimo elemento della coda
};
//Definizione del nuovo tipo lista come puntatore a elemBFS
typedef elemBFS* lista;
//Definizione della struttura codaBFS
typedef struct {
    lista head;      // puntatore alla testa della coda
    elemBFS* tail;   // puntatore alla coda della coda
} codaBFS;

//Funzione per aggiungere un elemento alla coda
codaBFS enqueue(codaBFS c, node* i) {
    elemBFS *e = new_elem(i);  // crea un nuovo elemento per la coda
    if (c.tail != NULL) {      // se la coda non è vuota
        c.tail->pun = e;       // collega l'ultimo elemento al nuovo elemento
    }
    c.tail = e;                // imposta il nuovo elemento come l'ultimo della coda
    if (c.head == NULL) {      // se la coda era vuota
        c.head = c.tail;       // imposta anche il primo elemento della coda
    }
    return c;                  // ritorna la coda aggiornata
}

//Funzione per rimuovere e restituire il primo elemento della coda
node* dequeue(codaBFS& c) {
    node* ris = (c.head)->inf; // salva il puntatore al nodo da restituire
    c.head = (c.head)->pun;    // sposta la testa al prossimo elemento
    return ris;                // ritorna il nodo rimosso
}

//Funzione per ottenere il primo elemento della coda senza rimuoverlo
node* first(codaBFS c) {
    return (c.head)->inf;      // ritorna il nodo in testa alla coda
}

//Funzione per verificare se la coda è vuota
bool isEmpty(codaBFS c) {
    if (c.head == NULL) {      // se la testa è NULL, la coda è vuota
        return true;
    }
    return false;              // altrimenti, la coda non è vuota
}

//Funzione per creare una nuova coda vuota
codaBFS newQueue() {
    codaBFS c = {NULL, NULL};  // inizializza head e tail a NULL
    return c;                  // ritorna la nuova coda vuota
}

//Funzione per creare un nuovo elemento della coda
static elemBFS* new_elem(node* n) {
    elemBFS* p = new elemBFS;  // alloca un nuovo elemBFS
    p->inf = n;                // imposta il nodo come informazione
    p->pun = NULL;             // imposta il puntatore al prossimo elemento come NULL
    return p;                  // ritorna il nuovo elemento
}

//Funzione per il calcolo della dimensione dell'albero (BFS)
int dimensione(tree t) {
    int count = 0;                      // inizializza il contatore dei nodi a 0
    codaBFS c = newQueue();             // crea una nuova coda vuota
    c = enqueue(c, t);                  // inserisce la radice dell'albero nella coda
    while (!isEmpty(c)) {               // continua finché la coda non è vuota
        node* n = dequeue(c);           // estrae il primo nodo dalla coda
        count++;                        // incrementa il contatore dei nodi
        tree t1 = get_firstChild(n);    // ottiene il primo figlio del nodo corrente
        while (t1 != NULL) {            // itera su tutti i figli del nodo corrente
            c = enqueue(c, t1);         // aggiunge ogni figlio alla coda
            t1 = get_nextSibling(t1);   // passa al fratello successivo
        }
    }
    return count;                       // ritorna il numero totale di nodi
}
