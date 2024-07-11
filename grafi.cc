/*
 * Riassunto sulle principali primitive e funzione per quento rigurdano i grafi
 */

#include<iostream>
#include<fstream>
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
graph new_graph(int n){
    graph G;                        // dichiarazione di una variabile di tipo graph
    G.dim = n;                      // assegna il numero di vertici (n) al campo dim della struttura graph
    G.nodes = new adj_list[n];      // alloca un array di liste di adiacenza (adj_list) di dimensione n
    for (int i = 0; i < n; i++) {
        G.nodes[i] = NULL;          // inizializza ogni lista di adiacenza come vuota (NULL)
    }
    return G;                       // restituisce il grafo creato
}

//Aggiunge l’arco orientato (u, v) con peso w alla lista di adiacenza del nodo u
void add_arc(graph& G, int u, int v, float w) {
      adj_node* t = new adj_node;  // crea un nuovo nodo di adiacenza
      t->node = v - 1;             // imposta il nodo di destinazione (corretto per indice base 0)
      t->weight = w;               // imposta il peso dell'arco
      t->next = G.nodes[u - 1];    // collega il nuovo nodo all'inizio della lista di adiacenza di u
      G.nodes[u - 1] = t;          // aggiorna l'inizio della lista di adiacenza di u al nuovo nodo
}

//Aggiunge un arco non orientato tra i nodi u e v con peso w
void add_edge(graph& g, int u, int v, float w) {
      add_arc(g, u, v, w);          // Aggiunge l'arco orientato (u, v) con peso w
      add_arc(g, v, u, w);          // Aggiunge l'arco orientato (v, u) con peso w
}

/****************************PRIMITIVE DI ACCESSO***********************/

//Restituisce la dimensione del grafo, ovvero il numero di nodi
int get_dim(graph g) {
      return g.dim;
}

//Restituisce la testa della lista di adiacenza del nodo con identificativo in ingresso
adj_list get_adjlist(graph g, int u) {
      return g.nodes[u-1];
}


//Restituisce l’identificativo del nodo contenuto nell’elemento della lista di adiacenza
int get_adjnode(adj_node* l){
	return (l->node+1);
}

//Restituisce il prossimo elemento della lista di adiacenza
adj_list get_nextadj(adj_list l){
	return l->next;
}

//Restituisce il peso del nodo contenuto nell’elemento della lista di adiacenza
float get_adjweight(adj_node* l){
	return (l->weight);
}

//Funzione che aggiunge un arco diretto o un edge non orientato a un grafo g a seconda del valore di d.
void add(graph& g, int u, int v, float w, bool d) {
      if (d){
            add_arc(g,u,v,w);   // Aggiunge un arco diretto tra u e v con peso w
      }
      else{
            add_edge(g,u,v,w);  // Aggiunge un edge tra u e v con peso w
      }
}

//Funzione che legge dallo stream f il numero dei nodi (prima riga), genera il corrispondente grafo e lo popola aggiungendo gli archi specificati nelle righe successive del file
graph g_build(ifstream &g, bool d, bool w) {
      int n;
      g >> n;                             // legge il numero di nodi dal file
      graph G = new_graph(n);             // crea un nuovo grafo con n nodi
      int v1, v2;
      if (w) {
            float w;
            while (g >> v1 >> v2 >> w) {
                  add(G, v1, v2, w, d);   // aggiunge un arco o un edge con peso w al grafo G
            }
      }
      else {
            while (g >> v1 >> v2) {
                  add(G, v1, v2, 1.0, d); // aggiunge un arco o un edge con peso 1.0 al grafo G
            }
      }
      return G;                           // restituisce il grafo G costruito
}
//Main che prende i dati dal file e crea un grafo a se per se, poi stampa tutti i dati
int main(int argc,char *argv[]) {
      /* Se il numero di parametri con cui e' stato chiamato il client e'
         inferiore a tre - si ricordi che il primo parametro c'e' sempre, ed e' il
         nome del file eseguibile - si ricorda all'utente che deve inserire
         anche il nome del file che descrive il grafo e il flag  weighted*/
      if (argc<3) {
            cout << "Usage: " << argv[0] << " filename directed weighted\n";
            exit(0);
      };
      
      ifstream g;
      g.open(argv[1]);
      cout <<   argv[1] << " " << argv[2] << " " << argv[2]<<endl;
      int directed = atoi(argv[2]);
      int weighted = atoi(argv[3]);
      
      /*Chiamata a g_build che costruisce un grafo*/
      graph G=g_build(g, directed, weighted);
      cout<<get_dim(G)<<endl;

      //Stampa dell'array di liste
      adj_list tmp;
      for (int i=1; i<=get_dim(G); i++) {
            tmp=get_adjlist(G,i);
            cout << i;
            while (tmp) {
	            cout << " --> " << get_adjnode(tmp);
	            tmp=get_nextadj(tmp);
            }
            cout << endl;
      } 
}

