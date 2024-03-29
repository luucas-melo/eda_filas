#include "fila_fixa.h"
#include<stdlib.h>
#include<stdio.h>
#define MAXTAM 5
int primeiro;
int ultimo;
int num_elementos;
int vetor[MAXTAM];

void cria_fila(){
    primeiro = 0;
    ultimo = -1;
}

int insere_elemento(int elemento){
    if(fila_cheia()){
        return 0;    
    }  
    ultimo = ultimo+1;
    vetor[ultimo] = elemento;
    return 1;
}

int remove_elemento(int *elemento){
    if(fila_vazia()){
        //printf("fila vazia\n");
        return 0;
    }
    *elemento = vetor[primeiro];
    primeiro = primeiro+1;
    
    if(primeiro>MAXTAM-1){
        primeiro=0; 
    }
    if(fila_cheia()){
        return 0;
    }
    
    
    

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
    if(ultimo+1==primeiro){

        return 1;
}
    else 
        return 0;
}
int tamanho_fila(){

    return MAXTAM;
}
void imprime(){
        int i;
        for(i=0;i<tamanho_fila();i++){
            printf("------");
        }
        printf("-");
        printf("\n| ");
        for(i=0;i<tamanho_fila();i++){     
            printf("%.3d | ",vetor[i]);
        }
        printf("\n");
        for(i=0;i<tamanho_fila();i++){
            printf("------");
        }
        printf("-");
        printf("\n");
        printf("  ");
        if(!fila_vazia()){
            for(i=0;i<tamanho_fila();i++){     
                if (i==primeiro){
                    printf("p");
                }
                if (i==ultimo){
                    printf(" u");
                }
                
                printf("      ");
            }
        }
} 
int reinicia_fila(){
    for(int i=0;i<tamanho_fila();i++){
        vetor[i]=0;
    }
    cria_fila();
    return 1    ;
}

