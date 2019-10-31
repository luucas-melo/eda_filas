#include <stdio.h>
#include <stdlib.h>
#include "fila_listaEncadeada.h"


typedef struct celula{
	int dado;
	struct celula *prox;

}celula;
int num_elementos=0;

celula *fila;
int cria_fila(){
	fila = malloc(sizeof(celula));
	fila->prox = fila;
	if(fila==NULL)
		return 0;
	return 1;
}
int fila_cheia(){
	return 0;
}
int fila_vazia(){
	if(fila->prox==fila)
		return 1;
	else
		return 0;
}
int remove_elemento(int *elemento){
	if(fila_vazia()){
		//printf("vazia");
		return 0;
	}
	celula *lixo = fila->prox;
	*elemento = lixo->dado;
	fila->prox = lixo->prox;
	num_elementos--;
	free(lixo);
	return 1;
}
int insere_elemento(int elemento){
	celula *novo = malloc(sizeof(celula));	
	if(novo==NULL){
		return 0;
	}
	//printf("%ld",sizeof(fila->prox)/sizeof(fila->dado));
	novo->prox = fila->prox;
	fila->prox=novo;
	fila->dado=elemento;
	fila=novo;
	num_elementos++;
	return 1;	
}
void imprime(){
	//celula *p = l->prox;]
	for(int i=0;i<num_elementos;i++){
		printf("------");
	}
	printf("-");
	printf("\n");
	printf("| ");
	for(celula*p=fila->prox;p!=fila;p=p->prox){	
		printf("%.3d | ",p->dado);
	}
	printf("\n");
	for(int i=0;i<num_elementos;i++){
		printf("------");
		
	}
	printf("-");
	printf("\n");
	
	for(int i=0;i<num_elementos;i++){
		if(i==0){
			printf("  p");
		}
		if(i==num_elementos-1){
			printf(" u");
		}
		printf("      ");
	}
	

}
int tamanho_fila(){
	return num_elementos;
}

int reinicia_fila(){
	int elem;
	while(remove_elemento(&elem));
		free(fila);
	cria_fila();	
	return 1;
}




