#include <stdio.h>
#include <stdlib.h>

#define CHAVE(L) ((L)->conteudo)
#define POST(L) ((L)->posterior)
#define ANT(L) ((L)->anterior)

typedef enum {OK, ERROR} status;
typedef enum {FALSE=0, TRUE=1} bool;
typedef struct celulaD celulaD, *listaD;

struct celulaD {
	int conteudo;
	listaD posterior;
	listaD anterior;
};

//FUNCOES
int Leitura_Arquivo_Inteiros(char *nome_arquivo, listaD *p_L, int *tamanho);
status insere_ordenado_listaD_circular(listaD *p_L, int chave);
status print_listaD(listaD L);
status aloca_celula_dupla(listaD *p_L, int chave);
status insereOrdenado(listaD *p, int elemento);



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
		insereOrdenado(p_L, aux_int);
	}
	fclose(arquivo);
	*tamanho = lidos;
	return 1;
 }

status print_listaD(listaD L){
	listaD p;
	int i;
	if(L==NULL	){
		printf("\n Lista vazia\n");
		return ERROR;
	}
	else if ((POST(L) == ANT(L)) &&  (ANT(L) == L)) //um unico elemento
	{
		printf("elemento 1: %d\n ",CHAVE(L));
		printf("\n");
	}
	else{
		for(i=1 ,p = POST(L); p != L; p= POST(p), i++){
			printf("elemento %d: %i \n",i,CHAVE(p));
		}
		printf("elemento %d: %i\n ",i,CHAVE(p));
		printf("\n");
		return OK;
	}
}

status aloca_celula_dupla(listaD *p_L, int chave)
{
	listaD L = (listaD) malloc(sizeof(celulaD));
	if (L == NULL) 
		return ERROR;
	CHAVE(L) = chave;
	POST(L) = L;
	ANT(L) = L;
	*p_L = L;
	return OK;
}



// PROVA QUESTAO 1

status inicia_listaD_circular(listaD *p_L)
{
	*p_L=NULL;
	return OK;
}


status remove_menor_elemento_listaD_circulaR(listaD *p_l, int *chave)
{
	if(*p_l==NULL)
		return ERROR;
	listaD aux;
	

}

/*status insere_ordenado_listaD_circular(listaD *p_L, int chave)
{
	listaD celula, aux;
	printf("ok!!!!!!!!!");
	if(aloca_celula_dupla(&celula, chave)==ERROR)
		return ERROR;
	printf("ok!!!!!!!!!");
	if(*p_L==NULL)
	{
		printf("ok!!!!!!!!!");
		POST(celula)=celula;
		ANT(celula)=celula;
		*p_L=celula;
		return OK;
	}
	if(POST(*p_L)==*p_L)
	{
		if(CHAVE(aux)>chave)
		{
			POST(celula)=aux;
			ANT(celula)=ANT(aux);
			POST(ANT(aux))=celula;
			ANT(aux)=celula;	
		}	
		else
		{	
			POST(celula)=POST(aux);
			ANT(celula)=aux;
			ANT(POST(aux))=celula;
			ANT(aux)=celula;
			if(ANT(celula)==*p_L)
			*p_L=celula;
		}
	}
	for(aux = POST(*p_L); ((aux != *p_L) && (CHAVE(celula)>CHAVE(aux))); aux = POST(aux));
	if(CHAVE(aux)>chave)
	{
		POST(celula)=aux;
		ANT(celula)=ANT(aux);
		POST(ANT(aux))=celula;
		ANT(aux)=celula;	
	}
	else
	{
		POST(celula)=POST(aux);
		ANT(celula)=aux;
		ANT(POST(aux))=celula;
		ANT(aux)=celula;
		if(ANT(celula)==*p_L)
			*p_L=celula;
	}
	return OK;
}*/


status insereOrdenado(listaD *p, int elemento)
{
	listaD celula,aux;
	if(aloca_celula_dupla(&celula, elemento)==ERROR)
		return ERROR;
	if(*p==NULL)
	{
		*p=celula;
		ANT(*p)=celula;
		POST(*p)=celula;
	}
	for(aux=POST(*p);POST(aux)!=*p && CHAVE(aux)<=elemento;aux=POST(aux));
	if(CHAVE(aux)<=elemento)
	{
		ANT(celula)=aux;
		POST(celula)=POST(aux);
		POST(aux)=celula;
		ANT(POST(celula))=celula;
	}
	if(CHAVE(aux)>elemento)
	{
		ANT(celula)=*p;
		POST(celula)=POST(*p);
		POST(*p)=celula;
		ANT(POST(celula))=celula;	
	}
	return OK;
}







