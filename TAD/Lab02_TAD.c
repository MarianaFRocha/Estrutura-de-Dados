// Inclusao de bibliotecas padroes.
#include <stdio.h>


// Inclusao de bibliotecas criadas pelo programador.
#include "vetorint.h"


// Definicao de constantes.
#define TAM 2

// -----------------------
// Prototipos de funcoes.
// -----------------------


// --------
// Funcao main:
// --------

int main()
{
	tipo_VetorInt meuvetor;
	//int i;
	
	meuvetor = vetorint_InicializaVazio(); //Inicializa vetor vazio
	vetorint_ImprimeNaTela(meuvetor);
	meuvetor = vetorint_InicializaTamanho(TAM); //Inicializa vetor vazio com tamanho TAM
	vetorint_ImprimeNaTela(meuvetor);
	meuvetor = vetorint_LeituraTeclado(meuvetor, TAM); //preenche TAM valores via teclado
	vetorint_ImprimeNaTela(meuvetor);
	meuvetor = vetorint_Destroi(meuvetor); //destroi vetor
	vetorint_ImprimeNaTela(meuvetor);
   	meuvetor = vetorint_InicializaTamanho(2*TAM); //Inicializa vetor vazio com tamanho 3*TAM
	vetorint_ImprimeNaTela(meuvetor);
	meuvetor = vetorint_LeituraTeclado(meuvetor, 2*TAM); //preenche 2*TAM valores via teclado
	vetorint_ImprimeNaTela(meuvetor);
	meuvetor = vetorint_Destroi(meuvetor); //destroi vetor
	vetorint_ImprimeNaTela(meuvetor);
	return 0;
}
