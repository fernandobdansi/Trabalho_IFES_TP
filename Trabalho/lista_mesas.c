/*
Arquivo: lista_mesas.c (Implementacao das funcoes da Mesa)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_mesas.h"

// funcao que inicializa a lista
ListaMesas* ListaMesas_inicializa (){
	ListaMesas *nova = (ListaMesas *) malloc(sizeof(ListaMesas));
	if (!nova){
		printf("Funcao inicializa: nao foi possivel alocar espaco para uma nova Lista. ");
		exit(1);
	}

	/* Inicializa os dados */
	nova->prim = NULL;
	return nova;
}

// imprime os elementos da lista
void ListaMesas_imprime (ListaMesas *lm){
	NoListaMesas *aux; /* variavel auxiliar para percorrer a fila */

	printf("########## Elementos da ListaMesas: #############\n");
	for (aux = lm->prim; aux != NULL; aux = aux->prox){
		printf("\t\tID = %i\n", aux->info.id);
		printf("\t\tCOR = %s\n", aux->info.cor);
		printf("\t\tALTURA = %.2f\n", aux->info.altura);
		printf("\t\tLARGURA = %.2f\n", aux->info.largura);
		printf("\n");
	}
}


// retorna 1 se vazia ou 0 se nao vazia
int ListaMesas_vazia (ListaMesas *lm){
	return (lm->prim == NULL);
}


// busca um elemento na lista
int ListaMesas_busca (ListaMesas *lm, int id){
	NoListaMesas *aux; /* variavel auxiliar para percorrer a lista */
	for (aux = lm->prim; aux != NULL; aux = aux->prox)
		if (aux->info.id == id)
			return 1;

	// nao achou o elemento
	return 0;
}


// insere elemento novo na lista
void ListaMesas_insere (ListaMesas *lm, Mesa mesa){
	NoListaMesas *novo = (NoListaMesas *) malloc(sizeof(NoListaMesas));

	novo->info.id = mesa.id;
	strcpy(novo->info.cor, mesa.cor);
	novo->info.altura = mesa.altura;
	novo->info.largura = mesa.largura;

	novo->prox = lm->prim;
	novo->ant = NULL;
	/* nao esta vazia, ou seja, este nao eh o primeiro elemento da lista */
	if (lm->prim != NULL)
		lm->prim->ant = novo;
	lm->prim = novo;
}

//remove um elemento da lista
int ListaMesas_retira (ListaMesas* lm, int id){
	NoListaMesas *aux = lm->prim; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while ( (aux != NULL) && (aux->info.id == id) ) {
		aux = aux->prox;
	}
	if(aux != NULL){
		if(aux->prox != NULL)
			aux->prox->ant = aux->ant;
		if(aux->ant != NULL)
			aux->ant->prox = aux->prox;
		else
			lm->prim = aux->prox;
		free(aux);
		return 1;
	}else{
		return 0;
	}
}
