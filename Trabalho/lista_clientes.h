/*
Arquivo: lista_clientes.h (Prototipo das Funcoes e Declaracoes dos Structs do Cliente)
*/
#ifndef __LISTA_CLIENTES_H__
#define __LISTA_CLIENTES_H__

typedef struct cliente {
	char cpf[15];
	char nome[30];
	char nascimento[17];
}Cliente;

typedef struct no_lista_clientes {
	Cliente info;
	struct no_lista_clientes *prox;
	struct no_lista_clientes *ant;
} NoListaClientes;

typedef struct lista_clientes {
	NoListaClientes *prim;
} ListaClientes;

ListaClientes* ListaClientes_inicializa ();
void ListaClientes_insere (ListaClientes *lc, Cliente cli);
int ListaClientes_retira (ListaClientes *lc, char cpf[15]);
void ListaClientes_imprime (ListaClientes *lc);
int ListaClientes_vazia (ListaClientes *lc);

#endif
