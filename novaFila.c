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
        printf("fila cheia\n");
        return 0;    
    }  
    if(fila_vazia()){
        primeiro = 0;
    }
    ultimo = ultimo+1;
    vetor[ultimo] = elemento;
    num_elementos++;
    total++;
    //printf("primeiro: %d  ultimo %d\n",primeiro,ultimo);
    return 1;
}

int remover_elemento(int *elemento){
    if(fila_vazia())
        return 0;
    *elemento = vetor[primeiro];
    primeiro = primeiro+1;
    num_elementos--;
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
    if(num_elementos==0)
        return 1;
    else 
        return 0;
}
void exibir_fila(void){
        int i;
        /*
        for(i=0;i<total;i++){  
            //printf("primeiro %d ultimo %d\n",primeiro,ultimo);    
            printf("elemento %d | primeiro %d | ultimo %d \n ",vetor[i],primeiro,ultimo);
        }
        */
        //printf("ele %d |",vetor[ultimo]);
        while( remover_elemento(vetor) ){
        printf("primeiro %d\n",primeiro);
        printf("\nValor:%d\n",vetor[primeiro]);
       
        }
        printf("\n");
            
}


