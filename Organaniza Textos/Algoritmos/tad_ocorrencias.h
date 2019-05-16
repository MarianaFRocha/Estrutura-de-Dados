
#include"tad_pagina.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)


typedef struct celulaO celulaO, *ocorrencia;

struct celulaO
{
	palavra conteudo;	
	ocorrencia posterior;
};

status iniciarOcorrencia(ocorrencia *o)
{
	*o=NULL;
}



status armazenarOcorrencia(ocorrencia *o, palavra p)
{
	ocorrencia celula = (ocorrencia) malloc(sizeof(celulaO));
	if (celula == NULL)
		return ERROR;


	CHAVE(celula)=p;
	POST(celula)=NULL;

	if(*o==NULL)
	{
		*o=celula;
		return OK;
	}
		printf("\nPASSOU\n");	
	ocorrencia aux;
	for(aux=*o;POST(aux)!=NULL;aux=POST(aux));
	POST(aux)=celula;
	return OK
}

int posicaoW(ocorrencia *o,linha l)
{
	
}



