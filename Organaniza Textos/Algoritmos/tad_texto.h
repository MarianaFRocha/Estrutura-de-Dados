
#include"tad_indice.h"

#define CHAVE(L) ((L)->conteudo)
#define POST(L)  ((L)->posterior)

typedef struct celulaT celulaT, *texto;

struct celulaT
{
	pagina conteudo;
	texto posterior;
};

// Prototipos das funcoes.
void iniciarTexto(texto *t);
status adicionarPaginas(texto *t, pagina pag);
int posicaoPagina(pagina p, texto t);
status imprimiTexto(texto t);
status preencherTexto(char *nomeArquivo, texto *t);
status salvaArquivo(char *nomeArquivo, texto *t);


//Inicializa a celula
void iniciarTexto(texto *t)
{
	*t=NULL;
}

//Função para alocar memoria e armazenar informação na celula criada
status adicionarPaginas(texto *t, pagina pag)
{
	texto celula = (texto) malloc(sizeof(celulaT));
	if(celula == NULL)
		return ERROR;
	CHAVE(celula)=pag;
	POST(celula)=NULL;

	if(*t==NULL)
	{
		*t=celula;
		return OK;
	}

	texto aux;
	for(aux=*t;POST(aux)!=NULL;aux=POST(aux));
	POST(aux)=celula;
	return OK;
}

//Funcao para achar a posicao da pagina no texto
int posicaoPagina(pagina p, texto t)
{
	pagina aux;
	int i;
	for(i=0, aux=t;aux!=NULL && CHAVE(t)!=p;i++,aux=POST(aux));
	return i;
}

//Imprimi o conteudo da celula
status imprimiTexto(texto t)
{
    int i=1;
	if(t==NULL)
		return ERROR;
	texto aux;
	for(aux=t;aux!=NULL;aux=POST(aux))
		imprimiPagina(CHAVE(aux), i++);
	return OK;
}


//Funcao para copiar um arquivo para a lista
status preencherTexto(char *nomeArquivo, texto *t)
{
	FILE *arquivo;
	if((arquivo=fopen(nomeArquivo, "r")) == NULL)
	{
		printf("\nError ao abrir o arquivo!\n");
		return ERROR;
	}

	int contLinha=0, contPagina=0, contPalavras=0,letras=0, i=0;
	linha l, proximaL;
	iniciarLinha(&proximaL);
	char aux;
	palavra p;
	pagina pag;
	indice ind;
	iniciarIndice(&ind);
	while (contLinha<21)
	{
		iniciarLinha(&l);
		l=proximaL;

		while(contPalavras<60)
		{
			iniciarPalavra(&p);

			while (fscanf(arquivo, "%c", &aux) == 1 && aux!=' ')
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
			if(letras>4)		//tem que ser maior porque todas as palavras contem espacos no final
			{
				armazenarIndice(&ind, p);  //armazena no indice remissivo
			}
			contPalavras=contPalavras+letras;
			iniciarLinha(&proximaL);
			i=0;
		}
		if(contPalavras==61) //problema do espaco, se a palavra couber certinho não precisa do espaço deve-se pular direto a linha
		{
			palavra auxp;
			for(auxp=p;POST(POST(auxp))!=NULL;auxp=POST(auxp));
			POST(auxp)=NULL;
			contPalavras--;
		}
		if(contPalavras>60)  //Caso tem extrapolado o limite de 60 caracteres
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
				criarPalavra(&p, '1');
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
			adicionarLinhas(&pag, l);
			if(aux!=' ')
				break;
		}
		if(contLinha==21) //Quando tiver 21 linhas ocorrer a quebra de pagina
		{
			contPagina++;
			iniciarPalavra(&p);
			criarPalavra(&p, '\f');
			adicionarPalavra(&l,p);
			adicionarPaginas(t,pag);
			iniciarPagina(&pag);
			contLinha=0;
		}
	}
	iniciarPalavra(&p);
	criarPalavra(&p, '\t');
	adicionarPalavra(&l,p);
	adicionarPaginas(t,pag);
	imprimirIndice(ind);
	fclose(arquivo);

}



//Função que salva a saida do programa em arquivo txt
status salvaArquivo(char *nomeArquivo, texto *t)
{
	if(*t==NULL)
		return ERROR;
	texto aux;
	pagina chave;
	for(aux=*t;aux!=NULL;aux=POST(aux))
	{
		chave=CHAVE(aux);
		salvaPagina(nomeArquivo, &chave);
	}
	return OK;
}









