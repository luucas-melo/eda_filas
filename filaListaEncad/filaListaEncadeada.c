
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int dado;
	struct celula *prox;

}celula;

celula *fila;
int inicializa_fila(){
	fila = malloc(sizeof(celula));
	fila->prox = fila;
	if(fila==NULL)
		return 0;
	return 1;
}
int desenfileira(int *y){
	if(fila->prox==fila)
		return 0;
	celula *lixo = fila->prox;
	*y = lixo->dado;
	fila->prox = lixo->prox;
	free(lixo);
	return 1;
}
int enfileira(int y){
	celula *novo = malloc(sizeof(celula));	
	if(novo==NULL){
		return 0;
	}
	novo->prox = fila->prox;
	fila->prox=novo;
	fila->dado=y;
	fila=novo;
	return 1;	
}
void imprime(celula *l){
	//celula *p = l->prox;
	for(celula*p=l->prox;p!=l;p=p->prox)
		printf("%d |",p->dado);
}

int destruir_fila(){
	int elem;
	while(desenfileira(&elem));
	free(fila);
	return 1;
}

int main(){
	inicializa_fila();
	enfileira(1);
	enfileira(2);
	enfileira(3);
	imprime(fila);
	//printf("%d",p->dado);
	return 0;
}
