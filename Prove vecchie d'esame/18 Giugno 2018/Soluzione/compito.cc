#include<iostream>
#include<cstring>
#include"bst.h"


using namespace std;

int totalePunti(bst tree, int inf, int sup){
    int somma=0;
    if(tree==NULL){
        
	}
    else{
        if(get_left(tree)!=NULL){
           somma += totalePunti(tree->left,inf,sup);
        }
        if(tree->key>=inf && tree->key<=sup){
            somma += tree->inf.tot_punti;
        }
        if(get_right(tree)!=NULL){
            somma += totalePunti(tree->right,inf,sup);
        }
    }
    return somma;
}

int main(){
    int num_carte;
    cout<<"Inserisci numero di carte: ";
    cin>>num_carte;
    bst tree;
    for(int i=0 ; i<num_carte ; i++){
        tipo_key num;
        tipo_inf carta;
        char app[20];
        cout<<"Inserisci il numero della carta: ";
        cin>>num;
        cout<<"Inserisci il nome del proprietario della carta: ";
        cin>>carta.persona;
        strcat(carta.persona," ");
        cout<<"Inserisci il congome del proprietario della carta: ";
        cin>>app;
        strcat(carta.persona,app);
        cout<<"Inserisci il saldo punti della carta: ";
        cin>>carta.tot_punti;
        bnode* b = bst_newNode(num,carta);
        bst_insert(tree,b);
    }
    cout<<"PUNTO 2: "<<endl;
    bst_stampa(tree);
    cout<<endl;
    cout<<"PUNTO 2.b: "<<endl;
    int inf,sup;
    cout<<"Inserisci il numero inferiore: ";
    cin>>inf;
    cout<<"Inserisci il numero superiore: ";
    cin>>sup;
    cout<<"Il totale dei punti nel range delle carte inserito e': "<<totalePunti(tree,inf,sup)<<endl;
}