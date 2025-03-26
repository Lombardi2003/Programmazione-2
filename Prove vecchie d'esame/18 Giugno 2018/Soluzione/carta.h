/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

typedef struct{
    char persona[20];
    int tot_punti;
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
