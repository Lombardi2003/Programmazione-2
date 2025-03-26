#include<iostream>
#include<cstring>

using namespace std;
#include"carta.h"

int compare(tipo_inf a,tipo_inf b){
    return a.tot_punti-b.tot_punti;
}

void copy(tipo_inf& dest,tipo_inf source){
    strcpy(dest.persona,source.persona);
    dest.tot_punti = source.tot_punti;
}

void print(tipo_inf a){
    cout<<a.persona<<" Punti: "<<a.tot_punti<<endl;
}
