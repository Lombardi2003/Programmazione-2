typedef struct{
    int stelle;
    char nome[20];
    char luogo[20];
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
