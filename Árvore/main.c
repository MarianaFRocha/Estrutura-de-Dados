#include "arvoreBinariaBusca.h"

int main()
{
	arvore myt, mya;
	int alt,no=0;

	//QUESTÃO 1
	printf("\n\nQUESTAO 1 e 3:\n\n");

	inicia_arvore(&myt);
	insercao_ABB(&myt, 16);
	insercao_ABB(&myt, 7);
	insercao_ABB(&myt, 4);
	insercao_ABB(&myt, 23);
	insercao_ABB(&myt, 1);
	insercao_ABB(&myt, 9);
	insercao_ABB(&myt, 25);
	imprime(myt, 0);
	alt = alturaABB(myt);
	printf("\nAltura: %d \n", alt);

	inicia_arvore(&myt);
	insercao_ABB(&myt, 7);
	insercao_ABB(&myt, 9);
	insercao_ABB(&myt, 4);
	insercao_ABB(&myt, 16);
	insercao_ABB(&myt, 1);
	insercao_ABB(&myt, 23);
	insercao_ABB(&myt, 25);
	imprime(myt, 0);
	alt = alturaABB(myt);
	printf("\nAltura: %d \n", alt);

	inicia_arvore(&myt);
	insercao_ABB(&myt, 4);
	insercao_ABB(&myt, 7);
	insercao_ABB(&myt, 9);
	insercao_ABB(&myt, 16);
	insercao_ABB(&myt, 1);
	insercao_ABB(&myt, 23);
	insercao_ABB(&myt, 25);
	imprime(myt, 0);
	alt = alturaABB(myt);
	printf("\nAltura: %d \n", alt);

	
	inicia_arvore(&myt);
	insercao_ABB(&myt, 9);
	insercao_ABB(&myt, 4);
	insercao_ABB(&myt, 23);
	insercao_ABB(&myt, 1);
	insercao_ABB(&myt, 7);
	insercao_ABB(&myt, 16);
	insercao_ABB(&myt, 25);
	imprime(myt, 0);
	alt = alturaABB(myt);
	printf("\nAltura: %d \n", alt);

	printf("\nQUESTAO 2:\n");

	contNo(myt, &no);
	printf("Quantidade de nos: %d\n", no);
		
	printf("\nQUESTAO 4:\n");

	inicia_arvore(&mya);
	insercao_ABB(&mya, 9);
	insercao_ABB(&mya, 4);
	insercao_ABB(&mya, 9);
	insercao_ABB(&mya, 23);
	insercao_ABB(&mya, 7);
	insercao_ABB(&mya, 16);
	insercao_ABB(&mya, 25);
	imprime(mya, 0);

	balanceada(mya);

	inicia_arvore(&myt);
	insercao_ABB(&myt, 9);
	insercao_ABB(&myt, 4);
	insercao_ABB(&myt, 23);
	insercao_ABB(&myt, 1);
	insercao_ABB(&myt, 7);
	insercao_ABB(&myt, 16);
	insercao_ABB(&myt, 25);
	imprime(myt, 0);

	balanceada(myt);

	printf("\nQUESTAO 5:");
	int cont, x=16; 
	contChave(myt,x,&cont);
	printf("\nO numero %d aparece %d vezes na arvore.\n", x, cont);

	printf("\nQUESTAO 8:");
	cont=ancestrais(myt,x);
	printf("\nO numero %d tem %d de nós ancestrais.\n", x, cont);

	x=25;
	cont=ancestrais(mya,x);
	printf("\nA arvore 2 tem %d de %d nós ancestrais.\n", x, cont);

	comparaArvores(myt,myt);
}

