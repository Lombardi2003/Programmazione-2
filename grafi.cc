/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano i grafi
 */

#include<iostream>
#include<string.h>
using namespace std;

/********************************GRAFI********************************/

// Struttura Lista di adiacenza
struct adj_node {
      int node;           // Nodo destinazione dell'arco
      float weight;       // Peso dell'arco
      adj_node* next;     // Puntatore al prossimo elemento della lista di adiacenza
};
// Definizione del tipo di dato della lista di adiacenza
typedef adj_node* adj_list;
// Definizione del tipo di dato per i grafi
typedef struct {
      adj_list* nodes;    // Array di liste di adiacenza, ogni elemento rappresenta la lista di adiacenza di un nodo del grafo
      int dim;            // Numero di nodi nel grafo
} graph;
