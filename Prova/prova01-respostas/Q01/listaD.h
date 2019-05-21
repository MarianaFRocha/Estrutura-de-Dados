/* 
Tipo Abstrato de Dados: Lista Circular Duplamente Encadeada
-------------------------------------

*/

// Inclusao de bibliotecas padroes.
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)
#define ANT(L)   ((L)->anterior)

typedef enum {ERROR, OK} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef int dado;

typedef struct celulaD celulaD, *listaD;

struct celulaD
{
	dado conteudo;
	listaD posterior;
	listaD anterior;
};	

int Leitura_Arquivo_Inteiros(char *nome_arquivo, listaD *p_L, int *tamanho);

status alocar_celulaD(listaD *p_L, dado chave);
status iniciar_listaD_circular(listaD *p_L);
bool listaD_vazia(listaD L);
void free_celulaD(listaD *p_L);
status inserir_inicio_listaD_circular(listaD *p_L, dado chave);
status inserir_ordenado_listaD_circular(listaD *p_L, dado chave);
status remove_menor_elemento_listaD_circular(listaD *p_L, dado *chave);
status remove_maior_elemento_listaD_circular(listaD *p_L, dado *chave);

status print_listaD(listaD L); 

// Le um arquivo de inteiros e carrega na lista *p_L
// O arquivo deve estar no seguinte formato: 
// O primeiro inteiro indica a quantidade de inteiros a serem lidos
// em seguida, os inteiros a serem lidos e carregados em *p_L
int Leitura_Arquivo_Inteiros(char *nome_arquivo, listaD *p_L, int *tamanho)
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
		//printf("\n %d |  ",  aux_int);
		inserir_ordenado_listaD_circular(p_L, aux_int);
		//print_listaD(*p_L); 

	}
	fclose(arquivo);
	*tamanho = lidos;
	return 1;
 }



//aloca espaco de memoria para no' apontado por L e armazena chave
status alocar_celulaD(listaD *p_L, dado chave)
{
	listaD L = (listaD) malloc(sizeof(celulaD));
	if (L == NULL) return ERROR;
	CHAVE(L) = chave;
	POST(L) = NULL;
	ANT(L) = NULL;
	*p_L = L;
	return OK;
}



//inicializa lista apontada por p_L em NULL
status iniciar_listaD_circular(listaD *p_L)
{
	*p_L = NULL;
	return OK;
}





//retona TRUE se lista L esta' vazia
bool listaD_vazia(listaD L)
{
	return(L == NULL) ? TRUE : FALSE;
}


//libera espaco de memoria ocupado pelo no' apontado por L
void free_celulaD(listaD *p_L)
{
	free(*p_L);
	*p_L = NULL;
}

status print_listaD(listaD L){
	listaD p;
	if(listaD_vazia(L)){
		printf("\n Lista vazia\n");
		return ERROR;
	}
	else if ((POST(L) == ANT(L)) &&  (ANT(L) == L)) //um unico elemento
	{
		printf(" %i ",CHAVE(L));
		printf("\n");
	}
	else{
		for(p = POST(L); p != L; p= POST(p)){
			printf(" %i ",CHAVE(p));
		}
		printf(" %i ",CHAVE(p));
		printf("\n");
		return OK;
	}
}

status inserir_inicio_listaD_circular(listaD *p_L, dado chave)
{
	listaD L;
	if (alocar_celulaD(&L, chave) == ERROR) return ERROR;
	if(listaD_vazia(*p_L)){
		POST(L) = L;
		ANT(L) = L;
		*p_L = L;
	}
	else
	{
		ANT(POST(*p_L)) = L;
		POST(L) = POST(*p_L);
		POST(*p_L) = L;
		ANT(L) = *p_L;				
	}
	//print_listaD(*p_L); 
	return OK;	
}

status inserir_ordenado_listaD_circular(listaD *p_L, dado chave)
{
	listaD L, p;
	if (alocar_celulaD(&L, chave) == ERROR) return ERROR;
	if(listaD_vazia(*p_L)){
		POST(L) = L;
		ANT(L) = L;
		*p_L = L;
	}
	if (CHAVE(L) > CHAVE(*p_L)) //se é a maior chave da lista, basta inserir e atualizar entrada
	{
		ANT(POST(*p_L)) = L;
		POST(L) = POST(*p_L);
		POST(*p_L) = L;
		ANT(L) = *p_L;
		*p_L =L;			
	}
	else if (CHAVE(L) < CHAVE(POST(*p_L))) //se é a menor chave da lista, basta inserir no inicio
	{
		ANT(POST(*p_L)) = L;
		POST(L) = POST(*p_L);
		POST(*p_L) = L;
		ANT(L) = *p_L;			
	}
	else  // procura posicao e posiciona "p" no no' anterior a posicao de insercao
	{
		for(p = POST(*p_L); ((p != *p_L) && (CHAVE(L)>CHAVE(p))); p = POST(p));
		p = ANT(p);
		ANT(POST(p)) = L;
		POST(L) = POST(p);
		POST(p) = L;
		ANT(L) = p;				
	}
	//print_listaD(*p_L); 
	return OK;	
}

status remove_menor_elemento_listaD_circular(listaD *p_L, dado *chave)
{
	listaD p;
	if(listaD_vazia(*p_L)) return ERROR;
	if ((POST(*p_L) == ANT(*p_L)) &&  (ANT(*p_L) == *p_L)) //um unico elemento
	{
		*chave = CHAVE(*p_L);
		free_celulaD(p_L);
		*p_L = NULL;
	}
	else
	{
		*chave = CHAVE(POST(*p_L));
		p = POST(*p_L);
		POST(*p_L) = POST(p);
		ANT(POST(p)) = *p_L;
		free_celulaD(&p);		
	}
	return OK;
}

status remove_maior_elemento_listaD_circular(listaD *p_L, dado *chave)
{
	listaD p;
	if(listaD_vazia(*p_L)) return ERROR;
	if ((POST(*p_L) == ANT(*p_L)) &&  (ANT(*p_L) == *p_L)) //um unico elemento
	{
		*chave = CHAVE(*p_L);
		free_celulaD(p_L);
		*p_L = NULL;
	}
	else
	{
		*chave = CHAVE(*p_L);
		p = *p_L;
		*p_L = ANT(*p_L);
		POST(*p_L) = POST(p);
		ANT(POST(p)) = *p_L;
		free_celulaD(&p);			
	}
	return OK;
}

/*
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

