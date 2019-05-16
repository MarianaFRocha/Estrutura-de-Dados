

#include"tad_indice.h"


int main()
{
	palavra p,q,r;
	printf("\nTESTE DE COMPARACAO:");
	iniciarPalavra(&p);
	criarPalavra(&p, 'o');
	criarPalavra(&p, 'i');
//	imprimiPalavra(p);
	printf("\n\n");
	iniciarPalavra(&q);
	criarPalavra(&q, 'o');
	criarPalavra(&q, 'i');
//	imprimiPalavra(q);


	if(repetidos(&p,&q)==OK)
		printf("OK\n\n");

	iniciarPalavra(&p);
	criarPalavra(&p, 'o');
	criarPalavra(&p, 'i');
	criarPalavra(&p, ' ');
//	imprimiPalavra(p);
	printf("\n\n");
	iniciarPalavra(&q);
	criarPalavra(&q, 'o');
	criarPalavra(&q, 'i');
//	imprimiPalavra(q);

	if(repetidos(&p,&q)==OK)
		printf("OK\n\n");


	iniciarPalavra(&p);
	criarPalavra(&p, 'o');
	criarPalavra(&p, 'i');
	criarPalavra(&p, 'r');
//	imprimiPalavra(p);
	printf("\n\n");
	iniciarPalavra(&q);
	criarPalavra(&q, 'o');
	criarPalavra(&q, 'i');
//	imprimiPalavra(q);

	if(repetidos(&p,&q)==OK)
		printf("\n\nOK\n\n");

	iniciarPalavra(&r);
	criarPalavra(&r, 'a');
	criarPalavra(&r, 'i');
	//imprimiPalavra(r);
	printf("\n\n");
	indice i;
	iniciarIndice(&i);
	armazenarIndice(&i, p);
	armazenarIndice(&i, q);
	armazenarIndice(&i, r);

	imprimirIndice(i);		

}
