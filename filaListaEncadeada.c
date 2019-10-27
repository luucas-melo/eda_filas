#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 5
typedef struct celula{
	int dado;
	struct celula *prox;

}celula;
int num_elementos=0;

celula *fila;
int criar_fila(){
	fila = malloc(sizeof(celula));
	fila->prox = fila;
	if(fila==NULL)
		return 0;
	return 1;
}
int fila_cheia(){
	if(num_elementos==MAXTAM)
		return 1;
	else
		return 0;
}
int fila_vazia(){
	if(fila->prox==fila)
		return 1;
	else
		return 0;
}
int remover_elemento(int *y){
	if(fila_vazia()){
		//printf("vazia");
		return 0;
	}
	celula *lixo = fila->prox;
	*y = lixo->dado;
	fila->prox = lixo->prox;
	num_elementos--;
	free(lixo);
	return 1;
}
int inserir_elemento(int y){
	celula *novo = malloc(sizeof(celula));	
	if(fila_cheia()){
		return 0;
	}
	//printf("%ld",sizeof(fila->prox)/sizeof(fila->dado));
	novo->prox = fila->prox;
	fila->prox=novo;
	fila->dado=y;
	fila=novo;
	num_elementos++;
	return 1;	
}
void exibir(){
	//celula *p = l->prox;]
	printf("------------------------------\n");
	printf("|");
	for(celula*p=fila->prox;p!=fila;p=p->prox){	
		printf("%d |",p->dado);
	}
	printf("\n");
	printf("------------------------------\n");
	
}

int destruir_fila(){
	int elem;
	while(remover_elemento(&elem));
	free(fila);
	return 1;
}




