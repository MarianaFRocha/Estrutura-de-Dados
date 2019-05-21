#include <stdio.h>
#include "lista.h"



int main(int argc, char *argv[])
{
	lista Lista1, Lista2;

    int lidos;
	
	if(argc < 3)
  	{
		printf("\nErro: Digite o nome dos arquivos !!!\n\n");
        exit(1);
	}
	iniciar_lista(&Lista1);
	iniciar_lista(&Lista2);
	print_lista(Lista1); 
	print_lista(Lista2);
	if (Leitura_Arquivo_Inteiros(argv[1], &Lista1, &lidos)) //se memoria alocada?
	{
		printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros da Lista1 sao:\n");
		print_lista(Lista1);
	}
	if (Leitura_Arquivo_Inteiros(argv[2], &Lista2, &lidos)) //se memoria alocada?
	{
		printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros da Lista 2 sao:\n");
		print_lista(Lista2);
	}
	printf("\n\nAppend antes:\n");
	printf("Os numeros da Lista1 sao:\n");
	print_lista(Lista1);
	printf("Os numeros da Lista 2 sao:\n");
	print_lista(Lista2);
	Append(&Lista1, &Lista2);
	printf("\n\nAppend depois:\n");
	printf("Os numeros da Lista1 sao:\n");
	print_lista(Lista1);
	printf("Os numeros da Lista 2 sao:\n");
	print_lista(Lista2);
	return 0;
}

