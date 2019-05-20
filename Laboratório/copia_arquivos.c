#include <stdio.h>
#include <stdlib.h>

//Programa que lê de um arquivo e copia para outro

int main(int argc, char *argv[]){

	FILE *arquivo1;
	FILE *arquivo2;
	FILE *arquivo3; 
	int *numero, *tamanho, *tamanho2 , lidos=0, l2, a,i;
	tamanho=&lidos;
	tamanho2=&l2;

//confere se a entrada no terminal esta correta 

	if(argc < 3)
  	{
            printf("\nErro: Digite o nome do arquivo !!!\n\n");
            exit(1);
	}

//Abrindo os arquivos

	arquivo1 = fopen(argv[1],"r");
	arquivo3 = fopen(argv[2],"r");
	arquivo2 = fopen("arquivo_final","w");

// Se o Sistema Operacional conseguiu criar/abrir o arquivo?

    	if((arquivo1 == NULL) || (arquivo2 == NULL)) 
    	{
       	printf("Erro ao criar/abrir arquivo!!!\n\n");
       	exit(1);
    	}
//Descobrir a quantidade de numeros do bloco de notas
//O primeiro numero do arquivo é quantidade de numeros 

	fscanf(arquivo1,"%d",tamanho);
	fscanf(arquivo3,"%d",tamanho2);

//Copiar de um arquivo para outro

	for((a=*tamanho + *tamanho2);a>0;a--)
	{
		
		fscanf(arquivo1,"%d",numero);
		fprintf(arquivo2,"%d\n",*numero);
	}

//Fecha e Salva os arquivos

    	fclose(arquivo1);
	fclose(arquivo2);
    	printf("\nGravado com sucesso!\n\n");
 }
	
