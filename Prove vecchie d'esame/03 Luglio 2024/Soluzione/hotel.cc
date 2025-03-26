#include <iostream>
#include <cstring>

using namespace std ;

#include "hotel.h"

int compare(tipo_inf a,tipo_inf b){
	return a.stelle-b.stelle;
}

void copy(tipo_inf& dest, tipo_inf source){
	strcpy(dest.nome,source.nome);
	strcpy(dest.luogo,source.luogo);
	dest.stelle = source.stelle;
}

void print(tipo_inf a ){
    cout<<a.stelle<<" stelle "<<a.nome<<" "<<a.luogo<<endl;
}
