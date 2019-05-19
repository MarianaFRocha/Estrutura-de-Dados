 
#include <stdio.h>
#include <stdlib.h>

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

// Prototipos das funcoes.

int Leitura_Arquivo_Inteiros(char *nome_arquivo, lista *p_L, int *tamanho);

status alocar_celula(lista *p_L, dado chave);
status iniciar_lista(lista *p_L);
bool lista_vazia(lista L);
status inserir_inicio_lista(lista *p_L, dado chave);
status inserir_final_lista(lista *p_L, dado chave);
status delete_celula(lista *p_l, lista celula);
void libera_celula(lista *p_l);
status delete_inicio_lista(lista *p_l, dado *p_chave);
void deleteList(lista *p_l);
void SelectionSort(lista l);
lista removeDuplicates(lista l);
status print_lista(lista L);

	
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
	lidos = 0;
	while (fscanf(arquivo, "%d", &aux_int) == 1)
	{ 
		lidos++;
		inserir_final_lista(p_L, aux_int); /* ou inserir_final_lista (p_L, aux_int)*/
	}
	fclose(arquivo);
	return 1;
 }



//aloca espaco de memoria para no apontado por L e armazena chave
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





//retona TRUE se lista L esta vazia
bool lista_vazia(lista L)
{
	return(L == NULL) ? TRUE : FALSE;
}





//insere no no final da lista apontada por p_L e armazena chave no novo no
status inserir_final_lista(lista *p_L, dado chave)
{
	lista L, tmplista=*p_L;
	if (alocar_celula(&L, chave) == ERROR) return ERROR;
	
	if (lista_vazia(*p_L) == TRUE)
	{
		*p_L = L;
		tmplista=*p_L;
	}
	else
	{
		for(tmplista = *p_L; POST(tmplista)!=NULL; tmplista= POST(tmplista));
		POST(tmplista) = L;
	}
	return OK;
}


status print_lista(lista L)
{
	lista x;
	if (L == NULL)
	{
		printf("\nlista Vazia\n\n");
		return ERROR;
	}
	for(x=L;x!=NULL;x=POST(x))
	{
		printf("--->%d\n", CHAVE(x));
	}
	return OK;
}

int quantidade_elementos_lista(lista L)
{
	int cont=1;
	lista x;
	for(x=L;POST(x)!=NULL;x=POST(x))
	{cont++;}
	return cont;
}

//insere no no inicio da lista apontada por p_L e armazena chave no novo no
status inserir_inicio_lista(lista *p_L, dado chave)
{	
	lista L;
	if (alocar_celula(&L, chave) == ERROR) return ERROR;
	
	if (lista_vazia(*p_L) == TRUE)
	{
		*p_L = L;
	}
	else
	{
		POST(L)=*p_L;
		*p_L=L;
	}
	return OK;
}


status delete_celula(lista *p_l, lista celula)
{
	if(lista_vazia(*p_l)==TRUE)
		return ERROR;
	if(*p_l==celula)
	{
		*p_l=POST(*p_l);
	}
	else
	{
		lista l;
		for(l=*p_l;(l!=NULL)&&(POST(l)!=celula);l=POST(l));
		if(l==NULL)
			return ERROR;
		else
			POST(l)=POST(celula);	
	}
	libera_celula(&celula);
	return OK;
}

void libera_celula(lista *p_l)
{
	free(*p_l);
	*p_l=NULL;
}

//remove a 1 celula e retorna o seu conteudo por referencia

status delete_inicio_lista(lista *p_l, dado *p_chave)
{
	if(lista_vazia(*p_l)==TRUE) return ERROR;
	*p_chave=CHAVE(*p_l);
	return(delete_celula(p_l,*p_l));
}

void deleteList(lista *p_l)
{
	if(lista_vazia(*p_l)==FALSE)
	{
		deleteList(&POST(*p_l));
		libera_celula(p_l);
		
	}
}

void SelectionSort(lista l)
 {
     lista tmp, aux;
     for (tmp = l; POST(tmp)!=NULL; tmp=POST(tmp))
     {
		  lista min;	
          int temp;
          min = POST(tmp);
          for (aux = POST(tmp); POST(aux)!=NULL; aux=POST(aux))
          {
               if (CHAVE(aux) < CHAVE(min))
                    min=aux;
          }

          temp = CHAVE(tmp);
          CHAVE(tmp) = CHAVE(min);
          CHAVE(min) = temp;
     }
 }

lista removeDuplicates(lista l)
{
	int i,j,k;
	lista tmp,aux,mylista;
	iniciar_lista(&mylista);
	for(tmp=l, aux=POST(tmp);POST(aux)!=NULL;tmp=POST(tmp), aux=POST(aux))
	{
		
		i=CHAVE(tmp);
		j=CHAVE(aux);
		if(i!=j)
			inserir_final_lista(&mylista, i);
	}
	for(tmp=mylista;POST(tmp)!=NULL;tmp=POST(tmp));
	if(CHAVE(tmp)!=CHAVE(aux))
	{
		inserir_final_lista(&mylista, CHAVE(aux));
	}
	return mylista;
}


 

