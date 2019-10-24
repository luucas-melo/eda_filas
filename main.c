#include <stdio.h>
#include <stdlib.h>
#include "fila_fixa.h"
#define MAXTAM 5
int menu(void){
    int opcao;
    printf("1-inserir elemento\n");
    printf("2-remover elemento\n");
    printf("3-exibir fila\n");
    scanf("%d",&opcao);
    return opcao;
}
int main(){
    
int vetor[MAXTAM],opcao;
int i,elemento,j;
criar_fila();
/*
inserir_elemento(10);
inserir_elemento(20);
inserir_elemento(30);
inserir_elemento(40);
inserir_elemento(50);
inserir_elemento(60);
inserir_elemento(70);

exibir_fila();
*/
 while ((opcao = menu()) != 0){
switch (opcao)
{
case 1:
    scanf("%d",&elemento);
    inserir_elemento(elemento);
    break;
case 2:
    remover_elemento(&elemento);
    break;
case 3:
    exibir_fila();
    break;
default:
    break;
}
}



    return 0;
}
