/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano gli alberi binari (BST)
 */

#include<iostream>
using namespace std;

/********************************ALBERI BINARI********************************/

//Definizione della struttura nodo
struct bnode {
    int inf;
    bnode* left;        // nodo sinistro
    bnode* right;       // nodo destro
    bnode* parent;      // collegamento al padre
};
//Dichiarazione del t324683ipo di dato binary tree
typedef bnode* btree;

/****************************ALBERI BINARI DA RICERCA***************************/
