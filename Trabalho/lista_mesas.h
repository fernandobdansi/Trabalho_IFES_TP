/*
Arquivo: lista_mesas.h (Funcoes e Declaracoes dos Structs das Mesas)
*/

#ifndef __LISTA_MESAS_H__
#define __LISTA_MESAS_H__

typedef struct mesa{
	int id;
	char cor[15];
	float altura;
	float largura;
}Mesa;

typedef struct no_listamesas {
	Mesa info;
	struct no_listamesas *prox;
	struct no_listamesas *ant;
} NoListaMesas;

typedef struct lista {
	NoListaMesas *prim;
} ListaMesas;

ListaMesas* ListaMesas_inicializa ();
void ListaMesas_insere (ListaMesas *lm, Mesa mes);
int ListaMesas_retira (ListaMesas *lm,int id);
void ListaMesas_imprime (ListaMesas *lm);
int ListaMesas_vazia (ListaMesas *lm);

#endif
