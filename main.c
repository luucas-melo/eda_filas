#include <stdio.h>
#include <stdlib.h>
#include "fila_fixa.h"

int vet[5],i,elemento;
criar_fila();
for(i = 0;i<5;i++){
    if(fila_cheia()){
        return 0;
    }
    inserir_fila(vet[i]);
}
for(j=0;j<5;j++){
    retirar_fila(&elemento);
}
