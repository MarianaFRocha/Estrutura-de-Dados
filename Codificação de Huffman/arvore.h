#include<stdio.h>
#include<stdlib.h>


typedef enum {OK, ERROR} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef struct no no, *arvore;


struct no {
   	char caracter;
	int frequencia;
	int codigo;
	arvore esquerda;
	arvore direita;
};

#define FREQUENCIA(T) ((T)->frequencia)
#define CONTEUDO(T) ((T)->caracter)
#define CODIGO(T) ((T)->codigo)
#define ESQUERDA(T) ((T)->esquerda)
#define DIREITA(T)  ((T)->direita)


void inicializar(arvore *t)
{
	*t=NULL;
}

status aloca_arvore_no(arvore *p_T, char caracter)
{
	arvore T = (arvore) malloc(sizeof(no));
	if (T == NULL) return ERROR;
	
	*p_T = T;
	CODIGO(T)=0;
	CONTEUDO(T) = caracter;
	ESQUERDA(T) = NULL;
	DIREITA(T)  = NULL;
	return OK;
}

bool arvore_vazia(arvore T)
{
	return(T == NULL) ? TRUE : FALSE;
}
