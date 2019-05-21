/* 
Tipo Abstrato de Dados: Lista Encadeada
-------------------------------------

*/

// Inclusao de bibliotecas padroes.
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef enum {ERROR, OK} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef int dado;

typedef struct celula celula, *lista;

struct celula
{
	dado conteudo;
	lista posterior;
};	

int Leitura_Arquivo_Inteiros(char *nome_arquivo, lista *p_L, int *tamanho);

status alocar_celula(lista *p_L, dado chave);
status iniciar_lista(lista *p_L);
bool lista_vazia(lista L);
void free_celula(lista *p_L);
status inserir_inicio_lista(lista *p_L, dado chave);
status inserir_final_lista(lista *p_L, dado chave);
status delete(lista *p_L, dado *p_chave);
status delete_celula(lista *p_L, lista celula);
status print_lista(lista L);
status remove_duplicatas(lista *p_L,lista *p_R);
status Append(lista *p_L,lista *p_R);
status DestroiR_Lista(lista *p_L);
status DestroiI_Lista(lista *p_L);


// Le um arquivo de inteiros e carrega na lista *p_L
// O arquivo deve estar no seguinte formato: 
// O primeiro inteiro indica a quantidade de inteiros a serem lidos
// em seguida, os inteiros a serem lidos e carregados em *p_L
int Leitura_Arquivo_Inteiros(char *nome_arquivo, lista *p_L, int *tamanho)
{
    FILE *arquivo;
    int lidos = 0;
    int aux_int;
    
	if((arquivo = fopen(nome_arquivo,"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
	fscanf(arquivo, "%d", tamanho);
	lidos = 1;
	while (fscanf(arquivo, "%d", &aux_int) == 1)
	{ 
		lidos++;
		/* Exercicio: substituir a funcao inserir_inicio_lista abaixo pela inserir_final_lista */
		inserir_inicio_lista(p_L, aux_int);
	}
	fclose(arquivo);
	*tamanho = lidos;
	return 1;
 }



//aloca espaco de memoria para no' apontado por L e armazena chave
status alocar_celula(lista *p_L, dado chave)
{
	lista L = (lista) malloc(sizeof(celula));
	if (L == NULL) return ERROR;
	
	*p_L = L;
	CHAVE(L) = chave;
	POST(L) = NULL;
	return OK;
}



//inicializa lista apontada por p_L em NULL
status iniciar_lista(lista *p_L)
{
	*p_L = NULL;
	return OK;
}





//retona TRUE se lista L esta' vazia
bool lista_vazia(lista L)
{
	return(L == NULL) ? TRUE : FALSE;
}


//libera espaco de memoria ocupado pelo no' apontado por L
void free_celula(lista *p_L)
{
	free(*p_L);
	*p_L = NULL;
}


//insere no' no inicio da lista apontada por p_L e armazena chave no novo no'
status inserir_inicio_lista(lista *p_L, dado chave)
{
	lista L;
	if (alocar_celula(&L, chave) == ERROR) return ERROR;
	POST(L) = *p_L;
	*p_L = L;
	return OK;	
}



//insere no' no final da lista apontada por p_L e armazena chave no novo no'
status inserir_final_lista(lista *p_L, dado chave)
{
	lista L, tmplista;
	if (alocar_celula(&L, chave) == ERROR) return ERROR;
	
	if (lista_vazia(*p_L) == TRUE)
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


//deleta o primeiro no' da lista apontada por p_L e retorna dados do n\'o excluido
status delete(lista *p_L, dado *p_chave)
{
	if(lista_vazia(*p_L) == TRUE) return ERROR;
	
	*p_chave = CHAVE(*p_L);
	return delete_celula(p_L, *p_L);
}


//exclui um determinado no' da memoria
status delete_celula(lista *p_L, lista celula)
{
	if(lista_vazia(*p_L) == TRUE) return ERROR;
	
	if(*p_L == celula)
	{
		*p_L = POST(*p_L);
	}
	else
	{
		lista L;
		for(L = *p_L; ((L!= NULL) && (POST(L) != celula)); L = POST(L));
		if (L == NULL) return ERROR;
		else POST(L) = POST(celula);
	}
	free_celula(&celula);
	return OK;
}


status print_lista(lista L){
	lista p;
	if(lista_vazia(L)){
		printf("Lista vazia\n");
		return ERROR;
	}
	else{
		for(p = L; p != NULL; p= POST(p)){
			printf(" %i ",CHAVE(p));
		}
		printf("\n");
		return OK;
	}
}


status remove_duplicatas(lista *p_L,lista *p_R)
{
	lista auxi,auxj, ant_auxj, tmpj;
	lista ultimo_p_R, auxR;
	*p_R = NULL;
	ultimo_p_R = *p_R;
	if (lista_vazia(*p_L) == TRUE)
	{
		return OK;
	}
	for(auxi = *p_L; auxi != NULL;auxi = POST(auxi))
	{
		ant_auxj = auxi;
		for(auxj = POST(auxi); auxj != NULL; auxj = POST(auxj))
		{
			if (CHAVE(auxj) == CHAVE(auxi)) 
			{
				tmpj = auxj;
				POST(ant_auxj) = POST(tmpj);
				if (lista_vazia(*p_R)) 
				{
					*p_R = auxj;
					ultimo_p_R = *p_R;
				}
				else
				{
					for(auxR = *p_R; auxR != ultimo_p_R; auxR = POST(auxR));
					POST(auxR) = auxj;
					ultimo_p_R = auxj;
				}
				
			}
			else
			{
				ant_auxj = POST(ant_auxj);
			}
			//printf("p_R = ");print_lista(*p_R);
			//printf("auxj= ");print_lista(auxj);
		}		
	}
	return OK;
}

status Append(lista *p_L,lista *p_R)
{
	lista aux_L,aux_R;
	if (lista_vazia(*p_L) == TRUE)
	{
		*p_L = *p_R;
	}
	else
	{
		for(aux_L = *p_L; POST(aux_L) != NULL; aux_L = POST(aux_L));
		POST(aux_L) = *p_R;
	}
	*p_R = NULL;
	return OK;
}

status DestroiR_Lista(lista *p_L)
{
	if (lista_vazia(*p_L) == TRUE)
	{
		return OK;
	}
	DestroiR_Lista(&POST(*p_L));
	free_celula(p_L);
	
}

status DestroiI_Lista(lista *p_L)
{
	lista aux_L;
	while (POST(*p_L) != NULL)
	{
		for(aux_L = *p_L; POST(POST(aux_L)) != NULL; aux_L = POST(aux_L));
		free_celula(&POST(aux_L));
		aux_L = NULL;
	}
	free_celula(p_L);
	*p_L = NULL;
	return OK;
}



/*
status remove_duplicatas(lista *p_L,lista *p_R)
{
	lista auxi,auxj, ant_auxj, tmpj;
	if (lista_vazia(*p_L) == TRUE)
	{
		*p_R = NULL;
		return OK;
	}
	for(auxi = *p_L; auxi != NULL;auxi = POST(auxi))
	{
		ant_auxj = auxi;
		for(auxj = POST(auxi); auxj != NULL; auxj = POST(auxj))
		{
			if (CHAVE(auxj) == CHAVE(auxi)) 
			{
				tmpj = auxj;
				POST(ant_auxj) = POST(tmpj);
				free(tmpj);
			}
			else
			{
				ant_auxj = POST(ant_auxj);
			}
		}		
	}
	return OK;
}
*/

