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


// Prototipos das funcoes.
status inicia_arvore(arvore *p_T);
status aloca_arvore_no(arvore *p_T, dado conteudo);
void libera_arvore_no(arvore *p_T);
bool arvore_vazia(arvore T);
status insercao_ABB(arvore *t, dado conteudo);
int minimo_ABB(arvore t);
int maximo_ABB(arvore t);
int sucessor_ABB(arvore t, int numero);
//


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

status insercao_ABB(arvore *t, dado conteudo)
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


void removerElemento(arvore *a, int num)
{
	
}


int minimo_ABB(arvore t)
{
	arvore aux;
	for(aux=t;ESQUERDA(aux)!= NULL;aux=ESQUERDA(aux));
	return CONTEUDO(aux);
}


int maximo_ABB(arvore t)
{
	arvore aux;
	for(aux=t;DIREITA(aux)!= NULL;aux=DIREITA(aux));
	return CONTEUDO(aux);
}

int sucessor_ABB(arvore t, int numero) 
{
			 
}

void imprimeABB(arvore t)
{
	if(t==NULL)
		return;
	imprimeABB(ESQUERDA(t));
	printf("\n %d ", CONTEUDO(t));
	imprimeABB(DIREITA(t));
}

void imprime(arvore p, int nivel){
     int i;
     if(p == NULL)
        return;
     imprime(DIREITA(p), nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%d {%d}\n\n",CONTEUDO(p), nivel);
     imprime(ESQUERDA(p),nivel+1);
     
}

int alturaABB(arvore t)
{
	if(t!=NULL)
	{		
		int he = alturaABB(ESQUERDA(t));
		int hd = alturaABB(DIREITA(t));
		if(hd>he)
			return hd+1;
		else
			return he+1;
	}
}

void contNo(arvore a, int *cont)
{
	if(a!=NULL)
	{
		contNo(ESQUERDA(a), cont);
		*cont=*cont+1;
		contNo(DIREITA(a), cont);
	}
}


bool verificaBalanciamento(arvore a)  
{
	if (arvore_vazia(a)==TRUE) return TRUE;
	int cont=0;
	arvore aux1, aux2;
	if(((alturaABB(ESQUERDA(a))-alturaABB(DIREITA(a)))>=2) || ((alturaABB(ESQUERDA(a))-alturaABB(DIREITA(a)))<=-2))
		return FALSE;
	verificaBalanciamento(ESQUERDA(a));
	verificaBalanciamento(DIREITA(a));
}

void balanceada(arvore a)
{
	if (verificaBalanciamento(a)==TRUE)
		printf("\nA ARVORE ESTA BALANCEADA\n");	
	else
		printf("\nA ARVORE NAO ESTA BALANCEADA\n");
}

void contChave(arvore a, int chave,int *cont)
{
	if(a!=NULL)
	{
		if(chave==CONTEUDO(a))
			*cont=*cont+1;
		contChave(ESQUERDA(a),chave,cont);
		contChave(DIREITA(a),chave,cont);
	}
}


//Questao 8

int ancestrais(arvore a, int num)
{
	int cont=0;
	arvore aux=a;
	while(a!=NULL && CONTEUDO(aux)!=num)
	{
		cont++;
		if(num>CONTEUDO(aux))
			aux=DIREITA(aux);
		else
			aux=ESQUERDA(aux);
	}
	if(CONTEUDO(aux)!=num)
	{
		printf("\nNumero não encotrado!\n");
		return 0;
	}
	else
		return cont;

}


//verifica se duas arvores são iguais
bool iguais(arvore a, arvore b)
{
	if(a==NULL && b ==NULL)
		return TRUE;
	if(a==NULL || b ==NULL)
		return FALSE;
	if(CONTEUDO(a)==CONTEUDO(b))
	{
		return (iguais(ESQUERDA(a),ESQUERDA(b)) && iguais(DIREITA(a),DIREITA(b)));
	}
	return FALSE;
}


void comparaArvores(arvore a, arvore b)
{
	if (iguais(a,b)==TRUE)
		printf("\nARVORES IGUAIS!!\n");	
	else
		printf("\nARVORES DIFERENTES!!\n");
}
