#include "vetorint.h"

int main(){

	FILE *arquivo;
	arquivo = fopen("Teste15.txt","r");
	tipo_VetorInt meuvetor;
	tipo_VetorInt meuvetor2;
	tipo_VetorInt meuvetor3;

	int tamanho,x;
	fscanf(arquivo,"%d",&tamanho);
	meuvetor=vetorint_InicializaVazio();
	meuvetor=vetorint_InicializaTamanho(tamanho);
	
	printf("\n\n--->Vetor 1:\n\n");
	meuvetor=vetorint_InicializaArquivo("Teste15.txt");

	meuvetor=vetorint_InsereElemento(meuvetor, 10000);
	
	meuvetor=vetorint_ExcluiElemento(meuvetor, 10000);	
	
	vetorint_ImprimeNaTela(meuvetor);
	
	meuvetor2=vetorint_InicializaArquivo("Teste25.txt");
	printf("\n\n--->Vetor 2:\n\n");
	vetorint_ImprimeNaTela(meuvetor2);
	
	meuvetor=vetorint_InsereElemento(meuvetor, 10000);
	
	meuvetor=vetorint_ExcluiElemento(meuvetor, 10000);

	meuvetor3=vetorint_SomaVetores(meuvetor,meuvetor2);
	printf("\n\n--->Vetor 3 (Soma Vetores):\n\n");
	vetorint_ImprimeNaTela(meuvetor3);
	
	x=vetorint_CalculaProdutoEscalar(meuvetor,meuvetor2);
	printf("\nProduto Escalar: %d\n\n", x);

	meuvetor3=vetorint_DestroiArquivo(meuvetor3,"arquivofinal.txt");
}
	
