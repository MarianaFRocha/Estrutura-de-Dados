#include"tad_pagina.h"

int main()
{
	pagina myp;
	iniciarPagina(&myp);
	preencherPagina("texto.txt", &myp);
	printf("\n\n");
	imprimiPagina(myp);
	printf("\n");
}
