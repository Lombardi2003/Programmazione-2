/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano gli alberi
 */

#include<iostream>
#include<string.h>
using namespace std;

//Creazione della nostro albeero tramite una struct
struct node {
    char* inf;
    node* parent;       // puntatore al nodo padre (opzione)
	node* firstChild;   // puntatore al primo figlio
	node* nextSibling;  // puntatore al prossimo fratello
};

//Dichiarazione del nuovo tipo lista
typedef node* tree;             //utilizza la parola chiave typedef per definire un nuovo tipo chiamato tree. 
                                //il tipo tree è sinonimo di node*, cioè un puntatore a un oggetto di tipo node.
//Definizione del tipo di dato
tree root;

//Crea un nuovo nodo con valore informativo i
node* new_node(char* i) {
    node* n = new node;  // Alloca dinamicamente un nuovo nodo
    n->inf = new char[strlen(i) + 1];                 // Alloca spazio per la stringa, includendo il terminatore null
    strcpy(n->inf, i);                                // Copia il contenuto della stringa i nel campo informativo
    n->nextSibling=n->firstChild=n->parent=NULL;      // Inizializza i puntatori a nullptr
    return n;                                         // Restituisce il nuovo nodo creato
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
