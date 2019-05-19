/* Exercicios */
/* (1) As definicoes de lista e o main() estao em um mesmo arquivo.
O primeiro exercicio consiste em separar esses dois codigos criando
o arquivo lista.h com a definicao de um TAD lista. */
 
/* (2) Acrescentar ao TAD e implementar as funções abaixo na sequência determinada: */
//status print_lista(lista L);
//int quantidade_elementos_lista(lista L);
//status inserir_inicio_lista(lista *p_L, dado chave);



#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)



int main(int argc, char *argv[])
{
	lista mylista;
	
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

	return 0;
}
	
