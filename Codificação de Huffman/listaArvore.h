#include "arvore.h"

typedef struct listaArvore listaArvore, *listaArv;

struct listaArvore{
	arvore conteudo;
	listaArv posterior;		
};


#define CHAVE(T) ((T)->conteudo)
#define POST(T) ((T)->posterior)


status iniciar_lista(listaArv *p_L)
{
	*p_L = NULL;
	return OK;
}

status alocar_celula(listaArv *p_L, char elemento)
{
	listaArv L = (listaArv) malloc(sizeof(listaArvore));
	if (L == NULL) return ERROR;

	arvore arv;
	inicializar(&arv);
	aloca_arvore_no(&arv, elemento);
	
	CHAVE(L) = arv;
	POST(L) = NULL;

	*p_L = L;
	return OK;
}


status inserir_final_lista(listaArv *p_L, char chave)
{
	listaArv L, tmplista;
	if (alocar_celula(&L, chave) == ERROR) return ERROR;
	
	if (*p_L == NULL)
	{
		*p_L = L;
	}
	else
	{
		for(tmplista = *p_L; POST(tmplista)!=NULL; tmplista= POST(tmplista));
		POST(tmplista) = L;
	}
	return OK;
}

void adicionarCelulaFinal(listaArv *l, listaArv celula)
{
	POST(celula)=NULL;
	if(*l==NULL)
		*l=celula;
	else
	{
		listaArv aux;
		for(aux=*l;POST(aux)=NULL;aux=POST(aux));
		POST(aux)=celula;		
	}

}

status print_lista(listaArv L)
{
	listaArv x;
	arvore arv;
	if (L == NULL)
	{
		printf("\nlista Vazia\n\n");
		return ERROR;
	}
	for(x=L;POST(x)!=NULL;x=POST(x))
	{
		arv=CHAVE(x);
		printf("--->%c\n", CONTEUDO(arv));
	}
	return OK;
}

status imprimeFrequencia(listaArv l)
{
	listaArv x;
	arvore arv;
	if (l == NULL)
	{
		printf("\nlista Vazia\n\n");
		return ERROR;
	}
	for(x=l;x!=NULL;x=POST(x))
	{
		arv=CHAVE(x);
		printf("%c = %d\n", CONTEUDO(arv), FREQUENCIA(arv));
	}
}

void libera_folha(listaArv *p_l)
{
	free(*p_l);
	*p_l=NULL;
}

status deleteFolha(listaArv *p_l, listaArv folha)
{
	if(*p_l==NULL)
		return ERROR;
	if(*p_l==folha)
	{
		*p_l=POST(*p_l);
	}
	else
	{
		listaArv l;
		for(l=*p_l;(l!=NULL)&&(POST(l)!=folha);l=POST(l));
		if(l==NULL)
			return ERROR;
		else
			POST(l)=POST(folha);	
	}
	libera_folha(&folha);
	return OK;
}

//retira os elementos que não existem no texto, ou seja, as letras que tem zero de frequencia
void removeElementos(listaArv *l)
{
	listaArv aux, prox;
	arvore arv=CHAVE(*l);
	if(FREQUENCIA(arv)==0)
	{
		prox=POST(*l);
		libera_folha(l);
		*l=prox;
	}
	for(aux=*l;POST(aux)!=NULL;aux=POST(aux))
	{
		arv=CHAVE(POST(aux));
		if(FREQUENCIA(arv)==0)
		{
			prox=POST(POST(aux));
			libera_folha(&POST(aux));
			POST(aux)=prox;
		}
	}
}

void removeCaracter(listaArv *l, char elemento)
{
	listaArv aux, prox;
	arvore arv=CHAVE(*l);
	if(CONTEUDO(arv)==elemento)
	{
		prox=POST(*l);
		libera_folha(l);
		*l=prox;
		return;
	}
	for(aux=*l;POST(aux)!=NULL;aux=POST(aux))
	{
		arv=CHAVE(POST(aux));
		if(CONTEUDO(arv)==elemento)
		{
			prox=POST(POST(aux));
			libera_folha(&POST(aux));
			POST(aux)=prox;
		}
	}
}


listaArv menorElemento(listaArv l)
{
	listaArv aux, menor;
	arvore arv=CHAVE(l);
	int m=FREQUENCIA(arv);
	menor=l;
	for(aux=l;aux!=NULL;aux=POST(aux))
	{
		arv=CHAVE(aux);
		if(FREQUENCIA(arv)<m)
		{
			menor=aux;
			m=FREQUENCIA(arv);
		}
	}
	return menor;
}

int tamanhoLista(listaArv l)
{
	if(l==NULL)
		return 0;
	int cont=1;
	listaArv x;
	for(x=l;POST(x)!=NULL;x=POST(x))
	{cont++;}
	return cont;
}

