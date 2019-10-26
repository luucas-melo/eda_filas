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
    
int opcao,elemento,cont = 0,j;
int n;
criar_fila();
while ((opcao = menu()) != 0){
switch (opcao)
{
case 1:
    printf("Quantos elementos deseja adicionar?\n");
    scanf("%d",&n);
    for(j=0;j<n;j++){
    scanf("%d",&elemento);
    if(fila_cheia()){
        cont++;
    }  
    inserir_elemento(elemento);
    }
    if(fila_cheia() && j==n){
        printf(" %d elemento(s) foram inserido(s) na fila, mas %d não coube(ram)\n",n,cont);
    }  
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
putchar('\n');
}




    return 0;
}
