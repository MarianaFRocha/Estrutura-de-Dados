#include <stdio.h>
#include <stdlib.h>
#include "TAD_Prova.h"

int main(int argc, char *argv[])
{
	
	listaD mylista;

    	int lidos;
    	int chave;
	
	if(argc < 2)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        exit(1);
	}
	
	inicia_listaD_circular(&mylista);
	if (Leitura_Arquivo_Inteiros(argv[1], &mylista, &lidos)) //se memoria alocada?
	{
		printf("\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros sao:\n");
		//print_listaD(mylista);
	}
	print_listaD(mylista);

}
