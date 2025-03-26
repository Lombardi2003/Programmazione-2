#include <iostream>
#include <cstring>

using namespace std ;

#include"tipo.h"

int compare(tipo_inf a,tipo_inf b){
    if(a.valore==b.valore){
        return a.seme-b.seme;
    }
    return a.valore-b.valore;
}
void copy(tipo_inf & dest, tipo_inf source){
    dest.seme=source.seme;
	dest.valore = source.valore;
}
void print(tipo_inf a){
    cout<<a.valore<<" "<<a.seme<<endl;
}


