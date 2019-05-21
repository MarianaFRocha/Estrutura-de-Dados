// Inclusao de bibliotecas padroes.
#include <stdio.h>


// Inclusao de bibliotecas criadas pelo programador.
#include "filaint.h"



// --------
// Funcao main:
// --------

int main()
{
	tipo_FilaInt p;
	int num;
	
	p = filaint_Inicializa(); //Inicializa vetor vazio
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 10);
	p = filaint_ENTRAR(p,10);
	filaint_ImprimeNaTela(p);
	p = filaint_SAIR(p,&num);
	printf("\nSAIR = %d", num);
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 20);
	p = filaint_ENTRAR(p,20);
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 30);
	p = filaint_ENTRAR(p,30);
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 40);
	p = filaint_ENTRAR(p,40);
	filaint_ImprimeNaTela(p);
	p = filaint_SAIR(p,&num);
	printf("\nSAIR = %d", num);
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 50);
	p = filaint_ENTRAR(p,50);
	filaint_ImprimeNaTela(p);
	printf("\nENTRAR = %d", 60);
	p = filaint_ENTRAR(p,60);
	filaint_ImprimeNaTela(p);
	p = filaint_SAIR(p,&num);
	printf("\nSAIR = %d", num);
	filaint_ImprimeNaTela(p);
	p = filaint_Destroi(p); //destroi vetor
	filaint_ImprimeNaTela(p);
	return 0;
}
