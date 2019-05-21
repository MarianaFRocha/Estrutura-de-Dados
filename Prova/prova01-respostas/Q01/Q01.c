#include <stdio.h>
#include "listaD.h"



int main(int argc, char *argv[])
{
	
	listaD mylista;

    int lidos;
    dado chave;
	
	if(argc < 2)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        exit(1);
	}
	
	iniciar_listaD_circular(&mylista);
	print_listaD(mylista); 
	if (Leitura_Arquivo_Inteiros(argv[1], &mylista, &lidos)) //se memoria alocada?
	{
		printf("\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros sao:\n");
	}
	print_listaD(mylista);
	
	
	remove_menor_elemento_listaD_circular(&mylista, &chave);
	printf("Menor = %d\n", chave);
	print_listaD(mylista);
	remove_menor_elemento_listaD_circular(&mylista, &chave);
	printf("Menor = %d\n", chave);
	print_listaD(mylista);
	remove_menor_elemento_listaD_circular(&mylista, &chave);	
	printf("Menor = %d\n", chave);
	print_listaD(mylista);
	remove_menor_elemento_listaD_circular(&mylista, &chave);
	printf("Menor = %d\n", chave);
	print_listaD(mylista);			
	remove_maior_elemento_listaD_circular(&mylista, &chave);
	printf("Maior = %d\n", chave);
	print_listaD(mylista);
	remove_maior_elemento_listaD_circular(&mylista, &chave);
	printf("Maior = %d\n", chave);
	print_listaD(mylista);
	remove_maior_elemento_listaD_circular(&mylista, &chave);
	printf("Maior = %d\n", chave);
	print_listaD(mylista);
	remove_maior_elemento_listaD_circular(&mylista, &chave);
	printf("Maior = %d\n", chave);
	print_listaD(mylista);	

	return 0;
}

