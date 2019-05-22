#include "listaArvore.h"


status listaAlfabeto(listaArv *alfab)
{
	FILE *arq;
	char aux;
	if((arq = fopen("alfabeto.txt","r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
	while (fscanf(arq, "%c", &aux) == 1 && aux!='\n')
	{ 
		inserir_final_lista(alfab, aux);
	}
	
}

//Constroi listaArv de frequencia de letras do alfabeto no texto
status construirLista(listaArv *a, char *nomeArquivo) 
{	
	FILE *arquivo;
	char letra;
	arvore arv;
	listaArv alf, aux;
	iniciar_lista(&alf);
	listaAlfabeto(&alf);
	aux=alf;
	
    // Contar frequencia no texto.
	while(aux != NULL)
	{
		 if((arquivo = fopen(nomeArquivo,"r")) == NULL)
		{
			printf("Erro ao abrir arquivo!!!\n\n");
			exit(1);
		}
		while (fscanf(arquivo, "%c", &letra) == 1)
		{
			arv=CHAVE(aux);	
			if(CONTEUDO(arv)==letra)
				FREQUENCIA(arv)=FREQUENCIA(arv)+1;
		}
	aux=POST(aux);
	}

	imprimeFrequencia(alf);
	*a=alf;
   	return OK;
}

//insere raiz no inicio da arvore apontada por p_T 
//e armazena conteudo no novo no' da arvore
status insere_raiz(arvore *p_T, char conteudo, arvore esquerda, arvore direita)
{
	if (arvore_vazia(*p_T) == FALSE) return ERROR;
	if (aloca_arvore_no(p_T, conteudo) == ERROR) return ERROR;
	ESQUERDA(*p_T) = esquerda;
		DIREITA(*p_T) = direita;
	return OK;	
}

void imprimiABB(arvore t)
{
	if(t==NULL)
		return;
	imprimiABB(ESQUERDA(t));
	printf("\n %d ", CONTEUDO(t));
	imprimiABB(DIREITA(t));
}

//cria a arvore de HUffman                
status criaHuffman(arvore t, listaArv l)
{
	arvore folha1, folha2,aux,z,arv;
	listaArv menor, usados;
	int i, soma, tamlista;
	tamlista=tamanhoLista(l);

	//inicialização
	inicializar(&aux);
	iniciar_lista(&usados);

	//enquanto a listaArv de frequencia for >1 
	while(tamlista>1)
	{
		
		//PRIMEIRO MENOR		
		//pega o menor da listaArv e cria uma folha com as informações 
		menor=menorElemento(l);
		arv=CHAVE(menor);
		aloca_arvore_no(&folha1, CONTEUDO(arv));
		FREQUENCIA(folha1)=FREQUENCIA(arv);
		printf("\n\n-->MENOR 1 : %C %d\n\n", CONTEUDO(folha1), FREQUENCIA(folha1));  //TESTE ARMAZENOU NA FOLHA UHULL
	
		//copia a celula ja usada para uma nova listaArv
		removeCaracter(&l, CONTEUDO(arv));	
		adicionarCelulaFinal(&usados, menor);
		

		//SEGUNDO MENOR	
		//pega o menor da listaArv e cria uma folha com as informações 
		menor=menorElemento(l);
		arv=CHAVE(menor);
		aloca_arvore_no(&folha2, CONTEUDO(arv));
		FREQUENCIA(folha2)=FREQUENCIA(arv);
		printf("\n\n-->MENOR 2: %C %d\n\n", CONTEUDO(folha2), FREQUENCIA(folha2));  //TESTE ARMAZENOU NA FOLHA UHULL
	
		//copia a celula ja usada para uma nova listaArv
		removeCaracter(&l, CONTEUDO(arv));	
		adicionarCelulaFinal(&usados, menor);

		printf("\n\n");
		imprimeFrequencia(l);		

		tamlista=tamanhoLista(l);
		printf("\nTAM:%d\n\n", tamlista);

	}

	
		return ERROR;
	
		
}
