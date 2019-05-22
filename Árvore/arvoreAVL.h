#include <stdio.h>
#include <stdlib.h>

typedef enum {OK, ERROR} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef enum {PREORDEM,EMORDEM, POSORDEM} ORDEM;

typedef struct no no, *arvore;
typedef int dado;

struct no
{
	dado conteudo;
	arvore esquerda;
	arvore direita;
};	

#define CONTEUDO(T) ((T)->conteudo)
#define ESQUERDA(T) ((T)->esquerda)
#define DIREITA(T)  ((T)->direita)
#define VISITA(T)   (printf("\n |%d| ", CONTEUDO(T)))


/*****PROTOTIPO DAS FUNCOES*******/
status inicia_arvore(arvore *p_T);
status aloca_arvore_no(arvore *p_T, dado conteudo);
void libera_arvore_no(arvore *p_T);
bool arvore_vazia(arvore T);
status insercao(arvore *t, dado conteudo);
int altura(arvore t);
int balanceamento(arvore a);
void imprime(arvore p, int nivel);
void balancearArvore(arvore *a);
void rotacaoEsquerda(arvore *a);
void rotacaoDireita(arvore *a);
int predecessor(arvore a, int remover);
int sucessor(arvore a, int remover);
int minimo(arvore t);
int maximo(arvore t);
arvore encotrarNo(arvore a, int num);
arvore pai(arvore a , arvore filho);


//inicializa arvore apontada por p_T em NULL
status inicia_arvore(arvore *p_T)
{
	*p_T = NULL;
	return OK;
}

//aloca espaco de memoria para no da arvore apontada por T e armazena conteudo
status aloca_arvore_no(arvore *p_T, dado conteudo)
{
	arvore T = (arvore) malloc(sizeof(no));
	if (T == NULL) return ERROR;
	
	*p_T = T;
	CONTEUDO(T) = conteudo;
	ESQUERDA(T) = NULL;
	DIREITA(T)  = NULL;
	return OK;
}

//libera espaco de memoria ocupado pelo da arvore apontada por T
void libera_arvore_no(arvore *p_T)
{
	free(*p_T);
	*p_T = NULL;
}

//retona TRUE se lista L esta' vazia
bool arvore_vazia(arvore T)
{
	return(T == NULL) ? TRUE : FALSE;
}


status insercao(arvore *t, dado conteudo)
{

	arvore y=NULL, x, z;
	if(aloca_arvore_no(&z,conteudo)==ERROR)
		return ERROR;
	x = *t;
	
	while(x!=NULL)
	{
		y=x;     //y é o pai de x
		if(CONTEUDO(z)<CONTEUDO(x))
			x=ESQUERDA(x);
		else 
			x=DIREITA(x);
	}
	if(y==NULL)
		*t=z;
	else
	{
		if(CONTEUDO(z)<CONTEUDO(y))
			ESQUERDA(y)=z;
		else 
			DIREITA(y)=z;
	}
}

int altura(arvore t)
{
	if(t!=NULL)
	{		
		int he = altura(ESQUERDA(t));
		int hd = altura(DIREITA(t));
		if(hd>he)
			return hd+1;
		else
			return he+1;
	}
}

int balanceamento(arvore a)
{
	return (altura(ESQUERDA(a)) - altura(DIREITA(a)));	
}

void rotacaoEsquerda(arvore *a)
{
	arvore y, x, aux;
	x=*a;
	y=DIREITA(x);
	aux= ESQUERDA(y);
	ESQUERDA(y)=x;
	DIREITA(x)=aux;
	*a=y;	
}

void rotacaoDireita(arvore *a)
{
	arvore y, x, aux;
	y=*a;
	x=ESQUERDA(y);
	aux=DIREITA(x);
	DIREITA(x)=y;
	ESQUERDA(y)=aux;
	*a=x;
}

void inserirAVL(arvore *a, int conteudo)
{
	insercao(a,conteudo);
	balancearArvore(a);
	
}


void imprime(arvore p, int nivel)
{
     int i;
     if(p == NULL)
        return;
     imprime(DIREITA(p), nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%d {%d}\n\n",CONTEUDO(p), nivel);
     imprime(ESQUERDA(p),nivel+1);
     
}

void balancearArvore(arvore *a)
{
	if(balanceamento(*a)<=-2 || balanceamento(*a)>=2)
	{
		if(balanceamento(*a)>=0)
		{
			if(balanceamento(ESQUERDA(*a))>=0)
				rotacaoDireita(a);
			else
			{
				rotacaoEsquerda(&ESQUERDA(*a));
				rotacaoDireita(a);
			}
		}
		else
		{
			if(balanceamento(DIREITA(*a))<=0)
				rotacaoEsquerda(a);
			else
			{
				rotacaoDireita(&DIREITA(*a));
				rotacaoEsquerda(a);
			}
		}
	}
}


status remover(arvore a, int k)
{
	arvore aux=a, del,suc;
	while(aux!=NULL && aux!=k)
	{
		if(aux>k)
			aux=ESQUERDA(aux);
		else
			aux=DIREITA(aux);
	}
	if(aux==NULL)
		return ERROR;
	del=aux;
	aux=a;
	suc=sucessor(del);
	if()
	
}


void remocaoAVL(arvore *a, int num)
{
	arvore del,suc,sub,p;
	del=encotrarNo(*a,num);
	if(DIREITA(del)==NULL || ESQUERDA(del)==NULL)
		suc=del;
	else
	{
		int s=sucessor(*a, CONTEUDO(suc));
		suc=encotrarNo(*a,s);
	}
	if(ESQUERDA(suc)!=NULL)
		sub=ESQUERDA(suc);
	else
		sub=DIREITA(suc);
	if(sub!=NULL)
	{
		p=pai(*a,sub);
		p=pai(*a,suc);
	}
	if(pai(*a,suc)==NULL)
		*a=sub;
	else
	{
		p=pai(*a,suc);
		if(suc==ESQUERDA(p))
			ESQUERDA(p)=sub;
		else
			DIREITA(p)=sub;
	}
	if(suc!=NULL)
		CONTEUDO(del)=CONTEUDO(suc);
	
}


arvore pai(arvore a , arvore filho)
{
	arvore aux, pai;
	aux=a;
	pai=NULL;
	while(aux!=NULL)
	{
		if(aux==filho)
			return pai;
		pai=aux;
		if(CONTEUDO(aux)>CONTEUDO(filho))
			aux=ESQUERDA(aux);
		else
			aux=DIREITA(aux);		
			
	}
	return NULL;
}

arvore encotrarNo(arvore a, int num)
{
	arvore aux=a;
	while(aux!=NULL)
	{
		if(CONTEUDO(aux)==num)
			return aux;
		if(CONTEUDO(aux)>num)
			aux=ESQUERDA(aux);
		else
			aux=DIREITA(aux);		
			
	}
	return NULL;
	
}

int minimo(arvore t)
{
	arvore aux;
	for(aux=t;ESQUERDA(aux)!= NULL;aux=ESQUERDA(aux));
	return CONTEUDO(aux);
}

int maximo(arvore t)
{
	arvore aux=t;
	while(DIREITA(aux)!=NULL)
	{
		aux=DIREITA(aux);
	}
	return CONTEUDO(aux);
}

int sucessor(arvore a, int remover)
{
	arvore y,x;
	x=encotrarNo(a,remover);
	if(DIREITA(x)!=NULL)
		return (minimo(DIREITA(x)));
	y=pai(a,x);
	while(y!=NULL && x==DIREITA(y))
	{
		x=y;
		y=pai(a,y);
	}

	return CONTEUDO(y);
}

int predecessor(arvore a, int remover)
{
	arvore y,x;
	x=encotrarNo(a,remover);
	if(ESQUERDA(x)!=NULL)
		return(maximo(ESQUERDA(x)));
	y=pai(a,x);
	while(y!=NULL && x==ESQUERDA(y))
	{
		x=y;
		y=pai(a,y);
	}
	return CONTEUDO(y);
}



