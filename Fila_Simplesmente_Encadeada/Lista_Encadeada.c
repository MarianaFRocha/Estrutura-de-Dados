
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)



int main(int argc, char *argv[])
{
	lista mylista, newlista;
	
	status resp;

    	int lidos,i;
	
	if(argc < 2)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);
	}
	iniciar_lista(&mylista);
	if (Leitura_Arquivo_Inteiros(argv[1], &mylista, &lidos)) //se memoria alocada?
	{
		printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros sao:\n");
		resp=print_lista(mylista);
	}

	resp=inserir_inicio_lista(&mylista,10000);
	printf("Nova Lista:\n");
	resp=print_lista(mylista);
	i=quantidade_elementos_lista(mylista);
	printf("------>Total:%d \n", i);
	
	SelectionSort(mylista);
	resp=print_lista(mylista);
	newlista=removeDuplicates(mylista);		
	printf("Nova Nova Lista:\n");
	resp=print_lista(newlista);
	deleteList(&mylista);
	resp=print_lista(mylista);

	return 0;
}
	
