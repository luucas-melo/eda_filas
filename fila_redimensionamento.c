#include <stdio.h>
#include <stdlib.h>
#include "fila_redimensionamento.h"
int *fila;

int primeiro, ultimo, MAXTAM;
int num_elementos;

int cria_fila(){
    primeiro=0;
    ultimo=0;
    MAXTAM=5;
    num_elementos=0;
    fila=malloc(MAXTAM*sizeof(int));
    if(fila==NULL){
        return 0;
    }
    return 1;
}
int redimensiona(){
    int i,j;
    fila=realloc(fila,2*MAXTAM*sizeof(int));
    if(fila==NULL)
        return 0;
    if(primeiro>ultimo){
        if(MAXTAM-primeiro>ultimo){
            for(i=0,j=MAXTAM;i<ultimo;i++,j++){
                fila[j]=fila[i];
            }   
            ultimo=MAXTAM+ultimo;  
        }
        else {
            for(i=MAXTAM-1,j=2*MAXTAM-1;i>=primeiro;i--,j--){
                fila[j]=fila[i];
                //primeiro=j+1;
           
            }
         primeiro=MAXTAM+primeiro;
        }           
    }
   
    MAXTAM=MAXTAM*2;
    return 1;
}
int insere_elemento(int elemento){
    if((ultimo+1)%MAXTAM==primeiro)
        if(!redimensiona())
            return 0;
    num_elementos++;
    fila[ultimo]=elemento;
    ultimo=(ultimo+1)%MAXTAM;
    return 1;
}
int remove_elemento(int *elemento){
    if(fila_vazia()){
        //printf("fila vazia\n");
        return 0;
    }
    *elemento = fila[primeiro];
    primeiro = (primeiro+1)%MAXTAM;
    num_elementos--;
    
    return 1;
}

int fila_cheia(){
    return 0;
}

int fila_vazia(){
    if((primeiro==0 && ultimo==0)|| num_elementos==0){
        return 1;
    }
    return 0;
}
int reinicia_fila(){
	free(fila);
    cria_fila();
}

int tamanho_fila(){

    return MAXTAM;
}

void imprime(){
	for(int i=0;i<tamanho_fila();i++){
		printf("------");
	}
	printf("-");
	printf("\n");
	printf("| ");
	for(int i=0;i<tamanho_fila();i++){
		printf("%.3d | ",fila[i]);
    }
    printf("\n");
	for(int i=0;i<tamanho_fila();i++){
		printf("------");
		
	}
	printf("-");
	printf("\n");
	if(!fila_vazia()){
        for(int i=0;i<tamanho_fila();i++){
            if(i==primeiro){
                printf("  p");
            }
            if(i==ultimo-1){
                printf(" u");
            }
            if (i==tamanho_fila()-1 && ultimo==0){
                printf(" u");
            }

            printf("      ");
        }
    }
    
}

