/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano i grafi
 */

#include<iostream>
#include<string.h>
using namespace std;

/********************************ALBERI BINARI********************************/

//Struttura Lista di adiacenza
struct adj_node {
      int node;
      float weight;
      adj_node* next;
};
typedef adj_node* adj_list;
Grafo
typedef struct{
adj_list* nodes;
int dim;
} graph;
