/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano i grafi
 */

#include<iostream>
#include<string.h>
using namespace std;

/********************************GRAFI********************************/

//Struttura Lista di adiacenza
struct adj_node {
      int node;           // Nodo destinazione dell'arco
      float weight;       // Peso dell'arco
      adj_node* next;     // Puntatore al prossimo elemento della lista di adiacenza
};
//Definizione del tipo di dato della lista di adiacenza
typedef adj_node* adj_list;
//Definizione del tipo di dato per i grafi
typedef struct {
      adj_list* nodes;    // Array di liste di adiacenza, ogni elemento rappresenta la lista di adiacenza di un nodo del grafo
      int dim;            // Numero di nodi nel grafo
} graph;

/********************************PRIMITIVE*****************************/

//Restituisce la rappresentazione di un grafo di n vertici identificati univocamente da 1 a n attraverso n liste di adiacenza
graph new_graph(int n){}

//Aggiunge l’arco orientato (s,d) con peso w alla lista di adiacenza del nodo s
void add_arc(graph& g,int s,int d,float w){}

// Aggiunge l’arco non orientato (s,d) con peso w alla lista di adiacenza del nodo s e del nodo d
void add_edge(graph& g,int s,int d,float w){}

/****************************PRIMITIVE DI ACCESSO***********************/

//Restituisce il numero n dei nodi del grafo
int get_dim(graph){}

//Restituisce la testa della lista di adiacenza del nodo con identificativo in ingresso
adjlist get_adjlist(graph,int){}

//Restituisce l’identificativo del nodo contenuto nell’elemento della lista di adiacenza
int get_adjnode(adj_node*){}

//Restituisce il prossimo elemento della lista di adiacenza
adj_list get_nextadj(adj_list){}
