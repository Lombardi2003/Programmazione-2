#include <iostream>
#include <fstream>

using namespace std ;

#include "bst.h"

/**
 * Funzione stampa
 * Funzione per la stampa dei valori
 * @param tree Parametro di ingresso alla funzione
 */
void stampa(bst tree){
    if(tree==NULL){ return;}
    if(get_left(tree)!=NULL){
        stampa(tree->left);
    }
    print(tree->inf);
    if(get_right(tree)!=NULL){
        stampa(tree->right);
    }
}

void stampa_maggiore(bst t, int stelle){
    if(t==NULL){ return;}
     if(get_left(t)!=NULL){
        stampa_maggiore(t->left,stelle);
    }
    if(t->inf.stelle>stelle){
         print(t->inf);
    }
    if(get_right(t)!=NULL){
        stampa_maggiore(t->right,stelle);
    }
}

void stampa_minore(bst tree, int stelle){
    if(tree==NULL){ return;}
    if(get_left(tree)!=NULL){
        stampa_minore(tree->left,stelle);
    }
    if(tree->inf.stelle<=stelle){
        print(tree->inf);
    }
    if(get_right(tree)!=NULL){
        stampa_minore(tree->left,stelle);
    }
}

void ricerca(bst tree, int stelle, bool v){
    if(v==true){
        stampa_maggiore(tree,stelle);
    }
    else{
        stampa_minore(tree,stelle);
    }
}

int main(){
    ifstream f("hotel.txt");
    int n;
    f>>n;
    bst tree = NULL;
    for(int i=0 ; i<n ; i++){
        tipo_inf n;
        f>>n.stelle;
        f.ignore();
        f.getline(n.nome,20);
        f>>n.luogo;
        tipo_key k = n.stelle;
        bnode* b = bst_newNode(k,n);
        bst_insert(tree,b);
    }
    f.close();
    cout<<"Punto 1"<<endl;
    stampa(tree);
    cout<<"Punto 2 A"<<endl;
    ricerca(tree,3,true);
}