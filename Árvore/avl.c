#include "arvoreAVL.h"

int main()
{
	arvore myt, mya;
	int alt,no=0;

	inicia_arvore(&myt);
	inserirAVL(&myt, 16);
	inserirAVL(&myt, 7);
	inserirAVL(&myt, 4);
	inserirAVL(&myt, 23);
	inserirAVL(&myt, 1);
	inserirAVL(&myt, 9);
	inserirAVL(&myt, 25);
	imprime(myt, 0);
	alt = altura(myt);
	printf("\nAltura: %d \n", alt);

	printf("\n\nROTACAO PARA DIREITA:\n");
	rotacaoDireita(&myt);
	imprime(myt, 0);
	

	printf("\n--------------------------------------------------------------------------------------------\n\n");

	inicia_arvore(&mya);
	inserirAVL(&mya, 9);
	inserirAVL(&mya, 4);
	inserirAVL(&mya, 9);
	inserirAVL(&mya, 23);
	inserirAVL(&mya, 7);
	inserirAVL(&mya, 16);
	inserirAVL(&mya, 25);
	imprime(mya, 0);

	printf("\n\nROTACAO PARA ESQUERDA:\n");
	rotacaoEsquerda(&mya);
	imprime(mya, 0);

	inicia_arvore(&myt);
	inserirAVL(&myt, 1);
	inserirAVL(&myt, 2);
	inserirAVL(&myt, 3);
	inserirAVL(&myt, 4);
	inserirAVL(&myt, 5);
	inserirAVL(&myt, 6);
	inserirAVL(&myt, 7);
	imprime(myt, 0);
	alt = altura(myt);
	
	int bal=balanceamento(myt);
	printf("\nFB:%d\n", bal);


	int s=sucessor(myt,5);
	printf("\nsucessor: %d\n", s);

	remocaoAVL(&myt, 4);
	imprime(myt, 0);

	remocaoAVL(&mya, 4);
	imprime(mya, 0);

}
