#include<stdio.h>
#include<stdlib.h>


#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef struct celula celula, *palavra;

typedef enum {ERROR, OK} status;
typedef enum {FALSE=0, TRUE=1 } bool;

struct celula
{
	char conteudo;
	palavra posterior;
};

// Prototipos das funcoes.
void iniciarPalavra(palavra *p);
status lerPalavra(char *nomeArquivo, palavra *p, int *letras);
status criarPalavra(palavra *p, char l);
status imprimiPalavra(palavra p);
status salvaPalavra(char *nomeArquivo, palavra *p);

int cont=0, lin=1, contPag=1;


//Inicializa a celula
void iniciarPalavra(palavra *p)
{
	*p=NULL;
}

o
//Funcao para copiar um arquivo para a lista palavra 
status lerPalavra(char *nomeArquivo, palavra *p, int *letras)
{
	FILE *arquivo;
	if((arquivo=fopen(nomeArquivo, "r")) == NULL)
	{
		printf("\nError ao abrir o arquivo!\n");
		return ERROR;
	}
	char aux;
	int i=0;
	while (fscanf(arquivo, "%c", &aux) == 1 && aux!=' ')  //Vai copiando ate o fim do arquivo ou encontrar um espaço 
	{ 
		criarPalavra(p, aux); 
		i++;
	}

	*letras=i; 
	if(aux!=' ')
		return OK;
	fclose(arquivo);
}


//Função para alocar memoria e armazenar informação na celula criada  
status criarPalavra(palavra *p, char l)
{
	palavra celula = (palavra) malloc(sizeof(celula));
	if (celula == NULL) 
		return ERROR;


	CHAVE(celula)=l;
	POST(celula)=NULL;	
	
	if(*p==NULL)
	{
		*p=celula;
		return OK;
	}

	palavra aux;
	for(aux=*p;POST(aux)!=NULL;aux=POST(aux));
	POST(aux)=celula;
	return OK;	
}


//Imprimi o conteudo da celula
status imprimiPalavra(palavra p)
{
	if(p==NULL)
		return ERROR;
	palavra aux;
	for(aux=p;aux!=NULL;aux=POST(aux))
		printf("%c",CHAVE(aux));
	return OK;
}


//Conta quantas celulas existe na lista
int contadorLetras(palavra p)
{
	if(p==NULL)
		return 0;
	palavra aux;
	int cont;
	for(aux=p,cont=1;POST(aux)!=NULL;aux=POST(aux),cont++);
	return cont;
}


//retorna o primeiro conteudo da lista palavra e depois o apaga
//sera utilizado na saida do programa quando for salvar no txt
status salvaPalavra(char *nomeArquivo, palavra *p)
{
	FILE *arquivo;
	arquivo=fopen(nomeArquivo,"a");
	if(*p==NULL)
		return ERROR;
	palavra aux;
	if(cont == 0)
	{
		fprintf(arquivo,"%d ", lin);
		lin++;	
	}
	for(aux=*p;aux!=NULL;aux=POST(aux), cont++)
	{
		if(cont==61 && lin!=22)
		{	
			fprintf(arquivo,"%d ", lin);
			lin++;
			cont=0;
		}
		if(CHAVE(aux)=='\f' || CHAVE(aux)=='\t')
		{	
			fprintf(arquivo,"\n\nPagina %d\n\n", contPag);
			contPag++;
			lin=1;
			cont=-1;
		}
		else
			fprintf(arquivo,"%c",CHAVE(aux));	
		
				
	}
	
	fclose(arquivo);
	return OK;
}







