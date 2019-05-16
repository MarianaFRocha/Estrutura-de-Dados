#include"tad_palavras.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef struct celulaL celulaL, *linha;

struct celulaL
{
	palavra conteudo;
	linha posterior;
};

// Prototipos das funcoes.
void iniciarLinha(linha *l);
status adicionarPalavra(linha *l, palavra p);
status imprimilinha(linha l,int posicao);
status preencherLinha(char *nomeArquivo, linha *l);
status salvaLinha(char *nomeArquivo,linha *l);



//Inicializa a celula
void iniciarLinha(linha *l)
{
	*l=NULL;
}


//Funcao para copiar um arquivo para a lista
status preencherLinha(char *nomeArquivo, linha *l)
{
	FILE *arquivo;
	if((arquivo=fopen(nomeArquivo, "r")) == NULL)
	{
		printf("\nError ao abrir o arquivo!\n");
		return ERROR;
	}
	int cont=0, letras=0;
	palavra p;
	char aux;
	while (cont<60)
	{
		iniciarPalavra(&p);
		while (fscanf(arquivo, "%c", &aux) == 1 && aux!=' ')  //Vai copiando ate o fim do arquivo ou encontrar um espaço
		{
			if(aux != '\n')
				criarPalavra(&p, aux);
			else
				criarPalavra(&p, ' ');
		}
		adicionarPalavra(l,p);
		ibf(aux!=' ')
			return OK;
		criarPalavra(&p, ' ');
		letras=contadorLetras(p);
		cont=cont+letras;
	}
	if(cont==61) //problema do espaco, se a palavra couber certinho não precisa do espaço deve-se pular direto a linha
	{
		palavra auxp;
		for(auxp=p;POST(auxp)!=NULL;auxp=POST(auxp));
		POST(auxp)=NULL;
		cont--;
	}
	if(cont>60) //Caso tem extrapolado o limite de 60 caracteres
	{
		linha aux,proximaL;
		for(aux=*l;POST(POST(aux))!=NULL;aux=POST(aux));
		proximaL=POST(aux);
		POST(aux)=NULL;
		cont=cont-letras;
		int i;
		for(i=cont;i<60;i++);
			criarPalavra(&p, '1');
		adicionarPalavra(l,p);
		printf("\nl:%d\n", letras);
	}

	fclose(arquivo);
}

//Função para alocar memoria e armazenar informação na celula criada
status adicionarPalavra(linha *l, palavra p)
{
	linha celula = (linha) malloc(sizeof(celulaL));
	if (celula == NULL)
		return ERROR;


	CHAVE(celula)=p;
	POST(celula)=NULL;

	if(*l==NULL)
	{
		*l=celula;
		return OK;
	}

	linha aux;
	for(aux=*l;POST(aux)!=NULL;aux=POST(aux));
	POST(aux)=celula;
	return OK;
}

//Imprimi o conteudo da celula
status imprimilinha(linha l,int posicao)
{
	if(l==NULL)
		return ERROR;
	linha aux;
	printf("%d-",posicao);
	for(aux=l;aux!=NULL;aux=POST(aux))
		imprimiPalavra(CHAVE(aux));
	return OK;
}

//Funcao para achar a posicao da palavra na linha
int posicaoPalavra(palavra p, linha l)
{
	linha aux;
	int i;
	for(i=0, aux=l;aux!=NULL && CHAVE(l)!=p;i++,aux=POST(aux));
	return i;
}

status salvaLinha(char *nomeArquivo,linha *l)
{
	int cont=0;

	if(*l==NULL)
		return ERROR;
	linha aux;
	palavra chave;
	for(aux=*l;aux!=NULL;aux=POST(aux))
	{
		chave=CHAVE(aux);
		salvaPalavra(nomeArquivo, &chave);
		cont++;
	}
	return OK;
}

