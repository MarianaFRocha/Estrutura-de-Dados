
#include"tad_ocorrencias.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef struct celulaI celulaI, *indice;

struct celulaI
{
	ocorrencia conteudo;	
	indice posterior;
};

//funcoes
status iniciarIndice(indice *i);
status armazenarIndice(indice *i, palavra p);
status repetidos(palavra *p1, palavra *p2);
int icont(palavra p1);



status iniciarIndice(indice *i)
{
	*i=NULL;
}

status armazenarIndice(indice *i, palavra p)
{
	ocorrencia o;


	indice celula = (indice) malloc(sizeof(celulaI));
	if (celula == NULL)
		return ERROR;


	CHAVE(celula)=o;
	POST(celula)=NULL;

	if(*i==NULL)
	{
		iniciarOcorrencia(&o);
		armazenarOcorrencia(&o,p);
		*i=celula;
		return OK;
	}

	indice aux;
	palavra pag;
	for(aux=*i;POST(aux)!=NULL;aux=POST(aux))
	{
		pag=CHAVE(CHAVE(aux));
		if(repetidos(&pag,&p)==OK)
		{
			armazenarOcorrencia(&CHAVE(aux),p);
					
			return OK;
		}	
	}
	armazenarOcorrencia(&(CHAVE(celula)),p);
	POST(aux)=celula;
	printf("\nPASSOU\n");
	return OK;
}

int icont(palavra p1)
{
	palavra auxp1;

	int cont; 

	if(p1==NULL)
		return 0;
	for(auxp1=p1, cont=1; POST(auxp1)!=NULL && CHAVE(POST(auxp1))!= ' ' ; auxp1=POST(auxp1), cont++);
	return cont;

}

status repetidos(palavra *p1, palavra *p2)
{
	palavra auxp1, auxp2;

	int tam1, tam2, cont = 0;
	tam1 = icont(*p1);
	tam2 = icont(*p2);
	
	if(tam2 != tam1)
		return ERROR;

	for(auxp1=*p1, auxp2=*p2; auxp1!=NULL && auxp2!=NULL; auxp1=POST(auxp1),auxp2=POST(auxp2))
	{
		if(CHAVE(auxp1)==CHAVE(auxp2))
			cont++;
	}
	if(cont==tam1)
		return OK;
	else
		return ERROR;

}

status imprimirIndice(indice i)
{
	if(i==NULL)
		return ERROR;
	indice aux;
	ocorrencia o;
	for(aux=i;aux!=NULL;aux=POST(aux))
	{
		for(o=CHAVE(aux);o!=NULL;o=POST(o))
			imprimiPalavra(CHAVE(o));
	}
	return OK;

}
