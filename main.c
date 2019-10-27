#include <stdio.h>
#include <stdlib.h>
#include "filaListaEncadeada.h"
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
    
int opcao,elemento,vetor[MAXTAM];
int n;
criar_fila();
int cont = -1,j;
while ((opcao = menu()) != 0){
switch (opcao)
{
case 1:
    printf("Quantos elementos deseja adicionar?\n");
    scanf("%d",&n);
    for(j=0;j<n;j++){
    scanf("%d",&vetor[j]);
    if(&vetor[j]>=0 && vetor[j]<=900)
        inserir_elemento(vetor[j]);
    else
        printf(" Elemento %d não foi inserido -> Digite um numero positivo maior que 1000\n",vetor[j]);
    if(fila_cheia()){
        cont++;
    }  
    }
    if(fila_cheia() && j==n){
        printf(" %d elemento(s) foram inserido(s) na fila, mas %d não coube(ram)\n",n,cont);
    }  
    break;
case 2:
    printf("Quantos elementos deseja remover?\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(!fila_vazia()){
            remover_elemento(vetor);
            printf("Elemento removido: %d\n",vetor[i]);
        }  
        else{   
             printf("não é possivel remover mais elementos, pois a fila está vazia\n");
        }
    }
    break;
case 3:
    exibir();
    break;
default:
    break;
}
putchar('\n');
}


    return 0;
}
