#include"tad_linha.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef struct celulaP celulaP, *pagina;

struct celulaP
{
	linha conteudo;
	pagina posterior;
};

// Prototipos das funcoes.
void iniciarPagina(pagina *pag);
status adicionarLinhas(pagina *pag, linha l);
status imprimiPagina(pagina pag, int pos);
status preencherPagina(char *nomeArquivo, pagina *pag);
int posicaoLinha(linha l, pagina p);

//Inicializa a celula
void iniciarPagina(pagina *pag)
{
	*pag=NULL;
}

//Função para alocar memoria e armazenar informação na celula criada
status adicionarLinhas(pagina *pag, linha l)
{
	pagina celula = (pagina) malloc(sizeof(celulaP));
	if(celula == NULL)
		return ERROR;

	CHAVE(celula)=l;
	POST(celula)=NULL;

	if(*pag==NULL)
	{
		*pag=celula;
		return OK;
	}

	pagina aux;
	for(aux=*pag;POST(aux)!=NULL;aux=POST(aux));
	POST(aux)=celula;
	return OK;
}

//Funcao para achar a posicao da linha na pagina
int posicaoLinha(linha l, pagina p)
{
	pagina aux;
	int i;
	for(i=0, aux=p;aux!=NULL && CHAVE(p)!=l;i++,aux=POST(aux));
	return i;
}

//Imprimi o conteudo da celula
status imprimiPagina(pagina pag, int pos)
{
	int i=1;
	if(pag==NULL)
		return ERROR;
	pagina aux;
	for(aux=pag;aux!=NULL;aux=POST(aux))
		imprimilinha(CHAVE(aux),i++);
	return OK;
}

//Funcao para copiar um arquivo para a lista
status preencherPagina(char *nomeArquivo, pagina *pag)
{
	FILE *arquivo;
	if((arquivo=fopen(nomeArquivo, "r")) == NULL)
	{
		printf("\nError ao abrir o arquivo!\n");
		return ERROR;
	}

	int contLinha=0, contPalavras=0,letras=0, i=0;
	linha l, proximaL;
	iniciarLinha(&proximaL);
	char aux;
	palavra p;

	while (contLinha<21)
	{
		iniciarLinha(&l);
		l=proximaL;

		while(contPalavras<60)
		{
			iniciarPalavra(&p);

			while (fscanf(arquivo, "%c", &aux) == 1 && aux!=' ') //Vai copiando ate o fim do arquivo ou encontrar um espaço
			{
				if(aux != '\n')
					criarPalavra(&p, aux);
				else
					criarPalavra(&p, ' ');
			}

			adicionarPalavra(&l,p);

			if(aux!=' ' )
			{
				letras=contadorLetras(p);
				contPalavras=contPalavras+letras;
				break;
			}
			criarPalavra(&p, ' ');
			letras=contadorLetras(p);
			contPalavras=contPalavras+letras;
			iniciarLinha(&proximaL);
			i=0;
		}
		if(contPalavras==61) //problema do espaco, se a palavra couber certinho não precisa do espaço deve-se pular direto a linha
		{
			palavra auxp;
			for(auxp=p;POST(auxp)!=NULL;auxp=POST(auxp));
			POST(auxp)=NULL;
			contPalavras--;
		}
		if(contPalavras>60)
		{

			linha aux;
			iniciarLinha(&proximaL);
			for(aux=l;POST(POST(aux))!=NULL;aux=POST(aux));
			proximaL=POST(aux);
			POST(aux)=NULL;
			contPalavras=contPalavras-letras;
			iniciarPalavra(&p);

			for(i=contPalavras;i<60;i++)
			{
				criarPalavra(&p, ' ');
				contPalavras++;
			}

			adicionarPalavra(&aux,p);
			i=letras;
		}

		if(contPalavras==60 || aux!=' ') //Quando a linha estiver completa ou chegar ao fim do testo
		{
			iniciarPalavra(&p);
			criarPalavra(&p, '\n');
			adicionarPalavra(&l,p);
			contLinha++;
			contPalavras=i;
			adicionarLinhas(pag, l);
			if(aux!=' ')
				return OK;
		}
	}

	fclose(arquivo);
}


status salvaPagina(char *nomeArquivo,pagina *pag)
{
	if(*pag==NULL)
		return ERROR;
	pagina aux;
	linha chave;
	for(aux=*pag;aux!=NULL;aux=POST(aux))
	{
		chave=CHAVE(aux);
		salvaLinha(nomeArquivo, &chave);
	}
	return OK;
}
