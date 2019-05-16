#include"tad_texto.h"

int main()
{
	texto myt;
	iniciarTexto(&myt);
	preencherTexto("texto.txt", &myt);
	printf("\n\n");
	imprimiTexto(myt);
	printf("\n");
	salvaArquivo("textoFinal.txt", &myt);
}
