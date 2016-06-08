/*
Arquivo: fila.h (Prototipo das Funcoes e Declaracoes dos Structs)
*/

#ifndef __FILA_H__
#define __FILA_H__

typedef struct pedido {
	int numero;
	char cpf[15];
	char cor[15];
	float altura;
	float largura;
}Pedido;


typedef struct no_fila {
	Pedido info; // Valor Padrao
	struct no_fila *prox;
} NoFila;

typedef struct fila {
	NoFila *ini;
	NoFila *fim;
} Fila;

//Prototipo das funcoes
Fila* Fila_inicializa ();
void Fila_insere (Fila *p, Pedido ped);
int Fila_retira (Fila *p);
void Fila_imprime (Fila *p);
int Fila_vazia (Fila *p);

#endif
