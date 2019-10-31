#include <stdio.h>
#include <stdlib.h>
int *fila;

int primeiro, ultimo, MAXTAM;


int criar_fila(){
    primeiro=0;
    ultimo=0;
    MAXTAM=5;
    fila=malloc(MAXTAM*sizeof(int));
    if(fila==NULL){
        return 0;
    }
    return 1;
}
int redimensiona(){
    int i,j;
    fila=realloc(fila,2*MAXTAM*sizeof(int));
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
int inserir_elemento(int elemento){
    if((ultimo+1)%MAXTAM==primeiro)
        if(!redimensiona())
            return 0;
    
    fila[ultimo]=elemento;
    ultimo=(ultimo+1)%MAXTAM;
    return 1;
}
int remover_elemento(int *elemento){
    if(primeiro==ultimo){
        return 0;
    }
    *elemento=fila[primeiro];
    primeiro=(primeiro+1)%MAXTAM;
    return 1;
}


void imprime(){
	//celula *p = l->prox;
	for(int i=0;i<MAXTAM;i++)
		printf("%d|",fila[i]);
    printf("p %d u %d \n",primeiro,ultimo);
}

