#include"tad_palavras.h"

int main (int argc, char *argv[])
{
	if(argc < 2)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);
	}
	int l;
	palavra mypalavra;
	iniciarPalavra(&mypalavra);
	lerPalavra(argv[1], &mypalavra, &l);

	imprimiPalavra(mypalavra);
	printf("\n");

	lerPalavra(argv[1], &mypalavra, &l);

	imprimiPalavra(mypalavra);
	printf("\n");

	int t =contadorLetras(mypalavra);
	printf("\nTamanho palavra: %d\n", t);
}
