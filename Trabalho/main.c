/*
------------------------------------------
-  Instituto Federal do Espirito Santo   -
Fernando Bueno Dansi, Artur Zampirolli
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

	printf("########## IFES - TECNICAS DE PROGRAMACAO ###########\n");
  printf("## SISTEMA DE REGISTRO DE PEDIDOS MESAS DE GRANITO ##\n");
	printf("#####################################################\n");
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
	printf("8 - Imprimir Clientes por Idade\n");
	printf("0 - Sair do Programa\n\n");
	printf("Digite a opcao desejada: \n");
	scanf("%i",&opc);
	Cliente cli;
	Mesa mes;
	Pedido ped;
	char cor[15];
	float larg, alt;
	int mesaRetirada;
	int idade;
	Pedido pedidoRetirado;
	switch (opc) {
		case 1:
				getchar();
				printf("Informe o nome: ");
				gets(cli.nome);
				printf("Informe o cpf: ");
				gets(cli.cpf);
				printf("Informe a data de nascimento: ");
				gets(cli.nascimento);
				printf("Digite a Idade:\n");
				scanf("%i",&cli.idade);
				ListaClientes_insere(lc, cli);
		break;
		case 2:

				printf("Digite o ID: ");
				scanf("%i",&mes.id);
				printf("Digite a cor: ");
				getchar();
				gets(mes.cor);
				printf("Digite a altura: ");
				scanf("%f",&mes.altura);
				printf("Digite a largura: ");
				scanf("%f",&mes.largura);
				ListaMesas_insere(lm, mes);
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
				Fila_insere(fp, ped);

		break;
		case 4:

			if(Fila_vazia(fp)==0){
						printf("Fechando Pedido!!!\n");
						pedidoRetirado = Fila_retira(fp);
						strcpy(cor, pedidoRetirado.cor);
						alt = pedidoRetirado.altura;
						larg = pedidoRetirado.largura;
						//printf("%s\n",pedidoRetirado.cor);
						//printf("%.2f\n",pedidoRetirado.altura);
						//printf("%.2f\n",pedidoRetirado.largura);
						mesaRetirada = ListaMesas_retira(lm, pedidoRetirado.cor, pedidoRetirado.altura, pedidoRetirado.largura);
						//printf("O Pedido %.2f foi fechado!\n",pedidoRetirado.altura);
						printf("Mesa Retirada = %i\n",mesaRetirada);
			}else{
				printf("Lista Vazia\n");
			}
				system("sleep 5");

		break;
		case 5:
				printf("############# Imprimindo Cliente: ###############\n");
				ListaClientes_imprime (lc);
				printf("#################################################\n");
				system("sleep 5");
		break;
		case 6:
				printf("############## Imprimindo Mesas: ################\n");
				ListaMesas_imprime (lm);
				printf("#################################################\n");
				system("sleep 5");
		break;
		case 7:
				printf("############## Imprimindo Pedidos: ##############\n");
				Fila_imprime (fp);
				printf("#################################################\n");
				system("sleep 5");
		break;
		case 8:
				printf("Digite a Idade que deseja imprimir: \n");
				scanf("%i",&idade);
				ImprimiIdade(lc, idade);
				system("sleep 5");
				break;

		case 0:
				printf("\n Saindo do Programa!!!\n");
				system("sleep 2");
		break;
		default:
				system("sleep 2");
				printf("Opção Invalidada!!!\n");
		break;
	}
	system("clear");
}while(opc != 0);
return 0;
}
