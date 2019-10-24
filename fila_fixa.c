#include "fila_fixa.h"
#include<stdlib.h>
#include<stdio.h>
#define MAXTAM 5
int primeiro;
int ultimo;
int num_elementos;
int vetor[MAXTAM];
void criar_fila(){
    primeiro = 0;
    ultimo = -1;
    num_elementos = 0;
}

int inserir_elemento(int elemento){
    if(fila_cheia()){
        printf("fila cheia\n");
        return 0;    
    }  
    else{
    ultimo = (ultimo+1)%MAXTAM;
    vetor[ultimo] = elemento;
    num_elementos++;
    //printf("primeiro: %d  ultimo %d\n",primeiro,ultimo);
    return 1;
    }

}

int remover_elemento(int *elemento){
    if(fila_vazia())
        return 0;
    *elemento = vetor[primeiro];
    primeiro = (primeiro+1)%MAXTAM;
    //num_elementos--;
    
    //printf("%d\n",vetor[ultimo]);
    //printf("primeiro: %d  ultimo %d\n",primeiro,ultimo);
    //printf("elemento removido %d\n",*elemento);
    return 1;
     

}

int fila_cheia(){
    if(num_elementos>=MAXTAM){
        return 1;
    }
    else
        return 0;

}

int fila_vazia(){
    if(primeiro==ultimo)
        return 1;
    else 
        return 0;
}
void exibir_fila(void){
        int i;
        if(primeiro>=ultimo)
            printf("fila vazia\n");
        else{
        for(i=0;i!=ultimo;i++){    
            printf("%d | ",vetor[i]);
        }
        printf("%d |",vetor[ultimo]);  
        printf("\n");
          
       }
}

