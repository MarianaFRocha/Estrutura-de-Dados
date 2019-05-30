#include <stdio.h>
#include <stdlib.h>


int main()
{
	char url[]="dados.txt",
	     linha[100];
	char *nome, *ult_nome, *nota1, *nota2, *nota3;
	FILE *arq;
        char copia[100];

	long long int num=0;

	arq = fopen("dados.txt", "w");
	for(num=0;num<100000;num++){
		fprintf(arq, "Leandro&Nogueira&10&10&10.4\n");	
	}

	return 0;
}
