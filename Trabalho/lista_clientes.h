/*
Arquivo: lista_clientes.h (Prototipo das Funcoes e Declaracoes dos Structs)
*/
#ifndef __LISTA_CLIENTES_H__
#define __LISTA_CLIENTES_H__

typedef struct cliente {
	char cpd[15];
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
void ListaClientes_insere (ListaClientes *l, char cpf);
int ListaClientes_retira (ListaClientes *l, char cpf);
void ListaClientes_imprime (ListaClientes *l);
int ListaClientes_vazia (ListaClientes *l);

#endif
