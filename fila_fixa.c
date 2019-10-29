#include "fila_fixa.h"
#include<stdlib.h>
#include<stdio.h>
#define MAXTAM 5
int primeiro;
int ultimo;
int num_elementos;
int vetor[MAXTAM];
int total;
void criar_fila(){
    primeiro = 0;
    ultimo = -1;
    num_elementos = 0;
}

int inserir_elemento(int elemento){
    if(fila_cheia()){
        printf("fila cheia porra\n");
        return 0;    
    }  
    ultimo = ultimo+1;
    vetor[ultimo] = elemento;
    num_elementos++;
    total++;
    printf("primeiro: %d  ultimo %d\n",primeiro,ultimo);
    return 1;
}

int remover_elemento(int *elemento){
    if(fila_vazia()){
        printf("fila vazia\n");
        return 0;
    }
    *elemento = vetor[primeiro];
    primeiro = primeiro+1;
    num_elementos--;
    //printf("%d\n",vetor[ultimo]);
    //printf("primeiro: %d  ultimo %d\n",primeiro,ultimo);
    printf("elemento removido %d\n",*elemento);
    return 1;
     

}

int fila_cheia(){
    if(ultimo>=MAXTAM-1){
        return 1;
    }
    else
        return 0;

}

int fila_vazia(){
    if(num_elementos==0)
        return 1;
    else 
        return 0;
}
void exibir(void){
        int i;
        
        for(i=primeiro;i<=ultimo;i++){  
            //printf("primeiro %d ultimo %d\n",primeiro,ultimo);    
            printf("%d | ",vetor[i]);
        }
        //printf("%d | ", vetor[ultimo]);
        
        //printf("ele %d |",vetor[ultimo]);
        printf("\n");
        
            
}
int destruir_fila(){
    primeiro = -1;
    ultimo = -1;
    return 0;
}

int tamanho_fila(){

    return total;
}