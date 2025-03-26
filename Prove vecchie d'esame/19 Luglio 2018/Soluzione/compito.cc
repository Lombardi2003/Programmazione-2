#include <iostream>
#include <fstream>
using namespace std;

#include "grafi.h"
#include "node.h"

// Funzione per stampare il grafo
void stampa(const graph& g) {
    for (int i = 0; i < g.dim; ++i) {               // Itera attraverso tutti i nodi del grafo
        adj_node* temp = g.nodes[i];                // Ottiene la lista di adiacenza per il nodo corrente
        while (temp != nullptr) {                   // Itera attraverso la lista di adiacenza
            cout << i + 1 << " -> " << temp->node << endl;   // Stampa l'arco dal nodo corrente al nodo destinazione
            temp = temp->next;                               // Passa al prossimo nodo nella lista di adiacenza
        }
    }
}

// Funzione per stampare il grafo
void stampa(const graph& g, node* n) {
    for (int i = 0; i < g.dim; ++i) {               // Itera attraverso tutti i nodi del grafo
        adj_node* temp = g.nodes[i];                // Ottiene la lista di adiacenza per il nodo corrente
        while (temp != nullptr) {                   // Itera attraverso la lista di adiacenza
            cout << n[i+1].cont;
            if(n[i+1].tipo=='U' &&n[temp->node].tipo=='U'){
                cout<< " follow ";
            }
            else{
                if(n[i+1].tipo=='U' &&n[temp->node].tipo=='T'){
                    cout<< " like ";
                }
                else{
                    cout<< " owner ";
                }
            }
            cout<< n[temp->node].cont << endl;   // Stampa l'arco dal nodo corrente al nodo destinazione
            temp = temp->next;                               // Passa al prossimo nodo nella lista di adiacenza
        }
    }
}
int* totalLike(graph g, node* n) {
    int* k = new int[g.dim + 1](); // Allocazione e inizializzazione dell'array k
    

    return k; // Restituisce l'array k
}


int main() {
    cout<<"PUNTO 1"<<endl;
    // Apertura del file di input
    ifstream file("graph");
    if (!file.is_open()) {
        cerr << "Errore nell'apertura del file." << endl;           // Messaggio di errore se il file non può essere aperto
        return 0;                                                   // Termina il programma con un codice di errore
    }

    graph g;
    file >> g.dim;                  // Legge il numero di nodi dal file
    g.nodes = new adj_list[g.dim];  // Alloca memoria per le liste di adiacenza dei nodi

    // Inizializza tutte le liste di adiacenza a nullptr
    for (int i = 0; i < g.dim; ++i) {
        g.nodes[i] = nullptr;
    }
    int src, dest;
    // Legge gli archi dal file e li aggiunge al grafo
    while (file >> src >> dest) {
        adj_node* new_node = new adj_node;  // Crea un nuovo nodo di adiacenza
        new_node->node = dest;              // Imposta il nodo di destinazione
        new_node->weight = 0;               // Imposta il peso a 0 poiché non è utilizzato (nel tuo esempio il grafo è non pesato)
        new_node->next = g.nodes[src - 1];  // Inserisce il nuovo nodo nella lista di adiacenza del nodo sorgente
        g.nodes[src - 1] = new_node;
    }

    file.close();   // Chiude il file di input
    stampa(g);      // Chiama la funzione per stampare il grafo
    
    cout<<endl<<"PUNTO 2"<<endl;
    node* nodi = new node[g.dim+1];
    ifstream f("node");
    if (!f.is_open()) {
        cerr << "Errore nell'apertura del file." << endl;           // Messaggio di errore se il file non può essere aperto
        return 0;                                                   // Termina il programma con un codice di errore
    }
    // Inizializza tutte le liste di adiacenza a nullptr
    for (int i = 1; i <= g.dim; i++) {
        f.getline(nodi[i].cont,81);
        f>>nodi[i].tipo;
        f.ignore();
    }
    f.close();   // Chiude il file di input
    stampa(g,nodi);
    
    cout<<endl<<"PUNTO 3.a"<<endl;
    int* n = totalLike(g,nodi);

    int max=0;
    for (int i = 1; i <= g.dim; i++) {
        if(n[i]>max){
            max=n[i];
        }
    }
    for (int i = 1; i <= g.dim; i++) {
        if(n[i]==max){
            cout<<nodi[i].cont<<endl;
        }
    }
}