#include <stdio.h>
#include <stdlib.h>

typedef enum {OK, ERROR} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef enum {PREORDEM,EMORDEM, POSORDEM} ORDEM;

typedef struct arvore_no arvore_no, *arvore;
typedef int dado;

struct arvore_no
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

status aloca_arvore_no(arvore *p_T, dado conteudo);  //aloca espaco de memoria para no' da arvore apontada por T e armazena conteudo
void libera_arvore_no(arvore *p_T); //libera espaco de memoria ocupado pelo da arvore apontada por T
status inicia_arvore(arvore *p_T); //inicializa arvore apontada por p_T em NULL
bool arvore_vazia(arvore T);
status insere_raiz(arvore *p_T, dado conteudo, arvore esquerda, arvore direita);
status percorre_arvore(arvore T, ORDEM ordem);
status percurso_preordem(arvore T);
status percurso_emordem(arvore T);
status percurso_posordem(arvore T);
void destroi_arvore(arvore *p_T);
int contNo(arvore T, int cont);
int contDado(arvore T, int elemento, int cont);

 //aloca espaco de memoria para no da arvore apontada por T e armazena conteudo
status aloca_arvore_no(arvore *p_T, dado conteudo)
{
	arvore T = (arvore) malloc(sizeof(arvore_no));
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


//inicializa arvore apontada por p_T em NULL
status inicia_arvore(arvore *p_T)
{
	*p_T = NULL;
	return OK;
}


//retona TRUE se lista L esta' vazia
bool arvore_vazia(arvore T)
{
	return(T == NULL) ? TRUE : FALSE;
}



//insere raiz no inicio da arvore apontada por p_T 
//e armazena conteudo no novo no' da arvore
status insere_raiz(arvore *p_T, dado conteudo, arvore esquerda, arvore direita)
{
	if (arvore_vazia(*p_T) == FALSE) return ERROR;
	if (aloca_arvore_no(p_T, conteudo) == ERROR) return ERROR;
	ESQUERDA(*p_T) = esquerda;
	DIREITA(*p_T) = direita;
	return OK;	
}




//escolhe percurso
status percorre_arvore(arvore T, ORDEM ordem) 
{
	switch (ordem)
	{
		case PREORDEM: 	printf("\n pre-ordem");
		               	return (percurso_preordem(T));

		case EMORDEM: 	printf("\n em-ordem");
						return (percurso_emordem(T));
						
		case POSORDEM:	printf("\n pos-ordem"); 
						return (percurso_posordem(T));
	}
	return ERROR;
}


//percurso pre-ordem
status percurso_preordem(arvore T)
{
	status rc;
	if (arvore_vazia(T) == TRUE) return OK;
	VISITA(T);
	rc = percurso_preordem(ESQUERDA(T));
	rc = percurso_preordem(DIREITA(T));
	return rc;
}


//percurso em-ordem
status percurso_emordem(arvore T)
{
	status rc;
	if (arvore_vazia(T) == TRUE) return OK;
	rc = percurso_emordem(ESQUERDA(T));
	VISITA(T);
	rc = percurso_emordem(DIREITA(T));
	return rc;
}

//percurso pos-ordem
status percurso_posordem(arvore T)
{
	status rc;
	if (arvore_vazia(T) == TRUE) return OK;
	rc = percurso_posordem(ESQUERDA(T));
	rc = percurso_posordem(DIREITA(T));
	VISITA(T);
	return rc;
}


//Destroi toda a arvore, garantido toda memoria liberada 
void destroi_arvore(arvore *p_T)
{
	if (arvore_vazia(*p_T) == FALSE)
	{
		destroi_arvore(&ESQUERDA(*p_T));
		destroi_arvore(&DIREITA(*p_T));	
		libera_arvore_no(p_T);
	}
}


//funcao que conta o numero de nos da arvore.
int contNo(arvore T, int cont)
{
	if (arvore_vazia(T) == TRUE) return cont;
	cont++;
	cont=contNo(ESQUERDA(T), cont);
	cont=contNo(DIREITA(T), cont);
	
}

//Quantidade de vezes que um dado aparece em uma arvore 
int contDado(arvore T, int elemento, int cont)
{
	if (arvore_vazia(T) == TRUE) return cont;
	if(elemento == CONTEUDO(T))
		cont++;
	cont=contDado(ESQUERDA(T), elemento,cont);
	cont=contDado(DIREITA(T), elemento,cont);		
}
