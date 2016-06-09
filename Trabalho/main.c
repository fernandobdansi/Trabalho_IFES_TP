/*
------------------------------------------
-  Instituto Federal do Espirito Santo   -
Rafael S. Guimaraes <rafaelg@ifes.edu.br>
------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "lista_mesas.h"
#include "lista_clientes.h"

int main(){

	int opc;
	ListaMesas *lm;
	ListaClientes *lc;
	Fila *fp;

	lm = ListaMesas_inicializa();
	lc = ListaClientes_inicializa();
	fp = Fila_inicializa();





	/* Exemplo de utilizacao */

do{
	printf("########## IFES - TECNICAS DE PROGRAMACAO ##########\n");
  printf("## SISTEMA DE REGISTRO DE PEDIDOS MESAS DE GRANITO #\n");
	printf("####################################################\n");
	printf("Clientes: Lista\n");
	printf("Mesas: Lista\n");
	printf("Pedidos: Fila\n");
	printf("1 - Cadastrar Cliente\n");
	printf("2 - Cadastrar Mesa\n");
	printf("3 - Abrir pedido de Mesa\n");
	printf("4 - Fechar pedido de Mesa\n");
	printf("5 - Imprimir Clientes\n");
	printf("6 - Imprimir Mesas\n");
	printf("7 - Imprimir Pedidos\n");
	printf("0 - Sair do Programa\n\n");
	printf("Digite a opcao desejada: \n");
	scanf("%i",&opc);
	Cliente cli;
	Mesa mes;
	Pedido ped;
	switch (opc) {
		case 1:

				printf("Informe o nome: ");
				scanf("%s",cli.nome);
				printf("Informe o cpf: ");
				scanf("%s",cli.cpf);
				printf("Informe a data de nascimento: ");
				scanf("%s",cli.nascimento);
				ListaClientes_insere(&lc, cli);
		break;
		case 2:

				printf("Digite o ID: ");
				scanf("%i",&mes.id);
				printf("Digite a cor: ");
				scanf("%s",mes.cor);
				printf("Digite a altura: ");
				scanf("%f",&mes.altura);
				printf("Digite a largura: ");
				scanf("%f",&mes.largura);
				ListaMesas_insere(&lm, mes);
		break;
		case 3:

				printf("Digite o numero: ");
				scanf("%i",&ped.numero);
				printf("Digite o CPF: ");
				scanf("%s",ped.cpf);
				printf("Digite a cor: ");
				scanf("%s",ped.cor);
				printf("Digite e altura: ");
				scanf("%f",&ped.altura);
				printf("Digite a largura: ");
				scanf("%f",&ped.largura);

		break;
		case 4:



		break;
		case 5:

		break;
		case 6:

		break;
		case 7:

		break;
		case 0:

		break;
		default:
		printf("Opção Invalidada!!!\n");
		break;
	}


}while(opc != 0);
return 0;
}
