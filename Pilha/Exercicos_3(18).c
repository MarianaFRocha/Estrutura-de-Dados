#include "pilha.h"

int main(int argc, char *argv[])
{
	pilha mypilha;
	iniciarPilha(&mypilha);
	if(argc < 3)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);
	}
	if (leituraArquivos(&mypilha, argv[1]))
		imprimiPilha(mypilha);
	popRemove(&mypilha);
	imprimiPilha(mypilha);
	int t=topo(&mypilha);
	salvaPilha(mypilha, argv[2]);

	return 0;
}
