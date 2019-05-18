#include <stdio.h>
#include <stdlib.h>

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)


typedef enum {ERROR, OK} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef int dado;

typedef struct celula celula, *pilha;

struct celula
{
	dado conteudo;
	pilha posterior;
};


// Prototipos das funcoes.

void iniciarPilha(pilha *p);
status criarCelula(pilha *p, int chave);
status leituraArquivos(pilha *p, char *nome_arquivo);
status salvaPilha(pilha p, char *nome_arquivo);
status pushInserir(pilha *p, int elemento);
status popRemove(pilha *p);
int topo(pilha *p);
void imprimiPilha(pilha p);
int tamanhoPilha(pilha p);


void iniciarPilha(pilha *p)
{
	*p = NULL;
}

status criarCelula(pilha *p, int chave)
{
	pilha auxP = (pilha) malloc(sizeof(celula));
	if (auxP == NULL) 
		return ERROR;
	*p = auxP;
	CHAVE(*p) = chave;
	POST(*p) = NULL;
	return OK;
}

status leituraArquivos(pilha *p, char *nome_arquivo)
{
	FILE *arquivo;
	int elemento, tamanho;
	status s;
	if((arquivo = fopen(nome_arquivo,"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		return ERROR;
	}
	while(fscanf(arquivo,"%d",&elemento)==1)
	{
		s=pushInserir(p, elemento);
		if(s==ERROR)
		{
			printf("Erro ao ler arquivo!!!\n\n");
			return ERROR;
		}
	}
	fclose(arquivo);
	return OK;
}

status salvaPilha(pilha p, char *nome_arquivo ) //IMCOMPLETO
{
	FILE *arquivo;
	arquivo=fopen(nome_arquivo,"w");
	pilha aux;
	int tamanho = tamanhoPilha(p);
	fprintf(arquivo,"%d\n",tamanho);
	for(aux=p;POST(aux)!=NULL;aux=POST(aux))
		fprintf(arquivo,"%d\n",CHAVE(aux));
	fclose(arquivo);
	return OK;
}

status pushInserir(pilha *p, int elemento)
{
	pilha auxP;
	if (criarCelula(&auxP,elemento) == ERROR) 
		return ERROR;	
	if (p == NULL) //Lista Vazia
 		*p = auxP;
	else
	{
		POST(auxP)=*p;
		*p=auxP;
	}
	return OK;
}	

status popRemove(pilha *p)
{
	if(*p == NULL)
		return ERROR;
	*p=POST(*p);
	return OK;	
}

void imprimiPilha(pilha p)
{
	if(p==NULL)
		printf("Lista Vazia"); 
	pilha auxP;
	int i;
	printf("\n\nQuantidade de numeros lidos: %d\n", tamanhoPilha(p));
		printf("Os numeros sao:\n");
	for(i=0,auxP=p;POST(auxP)!=NULL;auxP=POST(auxP),i++)
		printf("Elemento %d: %d\n", i,CHAVE(auxP));
}

int topo(pilha *p)
{
	printf("\nTOPO:%d\n\n", CHAVE(*p));
	return CHAVE(*p);	
}

int tamanhoPilha(pilha p)
{
	int i;
	pilha aux;
	for(i=0, aux=p;POST(aux)!=NULL;aux=POST(aux),i++);
	return i;

}









