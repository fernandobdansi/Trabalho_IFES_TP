/*
Arquivo: fila.c (Implementacao das Funcoes)
Instituto Federal do Espirito Santo - Cachoeiro de Itapemirim
*/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// funcao que inicializa a fila
Fila* Fila_inicializa (){
	Fila *nova = (Fila *) malloc(sizeof(Fila));
	if (!nova){
		printf("Fila_nova: nao foi possivel alocar espaco para uma nova fila. ");
		exit(1);
	}

	/* Inicializa os dados */
	nova->ini = NULL;
	nova->fim = NULL;
	return nova;
}

// imprime os elementos da fila
void Fila_imprime (Fila *fp){
	NoFila *aux; /* variavel auxiliar para percorrer a fila */

	if(fp->ini != NULL){
		printf("############## Elementos da Fila: ###############\n");
		for (aux = fp->ini; aux != NULL; aux = aux->prox){
			printf("|NUMERO DO PED: %d| \n", aux->info.numero);
			printf("|CPF DO PED: %s| \n", aux->info.cpf);
			printf("|COR DO PED: %s| \n", aux->info.cor);
			printf("|ALTURA DO PED: %.2f| \n", aux->info.altura);
			printf("|LARGURA DO PED: %.2f| \n", aux->info.largura);
			printf("<- fim \n");
		}
	}else{
		printf("\n\t\tFila Vazia!");
	}
	printf("\n");
}

// retorna 1 se vazia ou 0 se nao vazia
int Fila_vazia (Fila *fp){
	return (fp->ini == NULL);
}


// insere elemento novo na fila (sempre no final)
void Fila_insere (Fila *fp, Pedido pedido){
	NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
	novo->info.numero = pedido.numero;
	strcpy(novo->info.cpf , pedido.cpf);
	strcpy(novo->info.cor, pedido.cor);
	novo->info.altura = pedido.altura;
	novo->info.largura = pedido.largura;

	novo->prox = NULL;
	if (fp->fim != NULL)
		fp->fim->prox = novo;

	fp->fim = novo;
	if (fp->ini==NULL) /* fila antes vazia? */
		fp->ini = fp->fim;
}

// retira um elemento da fila (sempre do inicio, ou seja o primeiro)
int Fila_retira (Fila* fp){
	NoFila* novo_ini;
	NoFila* removido;
	int valor;

	removido = fp->ini;
	novo_ini = fp->ini->prox;

	valor = fp->ini->info.numero;
	fp->ini = novo_ini;
	if (fp->ini == NULL) /* fila ficou vazia? */
		fp->fim = NULL;
	free(removido);
	return valor;
}
