/* 
 Tipo Abstrato de Dados: tipo_VetorInt
 -------------------------------------
 Um TAD contem dois elementos principais:
	- Estrutura de dados (com seus atributos);
	- Conjunto de operacoes sobre estas estruturas.
*/

// Inclusao de bibliotecas padroes.
#include <stdio.h>
#include <stdlib.h>

// Definicao de constanttes.


// Definicao da estrutura com seus atributos.
struct str_VetorInt {
	int *vet;
	int n;
};
typedef struct str_VetorInt tipo_VetorInt;

// -----------------------
// Prototipos das funcoes.
// -----------------------

//   Operacoes construtoras.
tipo_VetorInt vetorint_InicializaVazio();
tipo_VetorInt vetorint_InicializaTamanho(int tamanho);
tipo_VetorInt vetorint_InicializaArquivo(char *nome_arquivo);

//   Operacoes analisadoras.
void vetorint_ImprimeNaTela(tipo_VetorInt v);
int vetorint_PesquisaSequencial(tipo_VetorInt v, int elem);

//   Operacoes produtoras.
tipo_VetorInt vetorint_SomaVetores(tipo_VetorInt v1, tipo_VetorInt v2);
int vetorint_CalculaProdutoEscalar(tipo_VetorInt v1, tipo_VetorInt v2);

//   Operacoes modificadoras.
tipo_VetorInt vetorint_LeituraTeclado(tipo_VetorInt v, int num);
tipo_VetorInt vetorint_InsereElemento(tipo_VetorInt v, int elem);
tipo_VetorInt vetorint_SubstituiElemento(tipo_VetorInt v, int elem, int pos);
tipo_VetorInt vetorint_ExcluiElemento(tipo_VetorInt v, int elem);

// Operacoes destrutoras
tipo_VetorInt vetorint_Destroi(tipo_VetorInt v);
tipo_VetorInt vetorint_DestroiArquivo(tipo_VetorInt v, char *nome_arquivo);


// --------
// Funções:
// --------



// Inicializa um vetor de inteiros vazio.
tipo_VetorInt vetorint_InicializaVazio() {
	tipo_VetorInt v;
	v.vet = NULL;
	v.n = 0;
	return v;
}


//Inicializa o tamanho de um vetor de inteiros mas continua vazio.
tipo_VetorInt vetorint_InicializaTamanho(int tamanho) {
	tipo_VetorInt v;
	v.vet = (int *) malloc(tamanho*sizeof(int));
	v.n = 0;
	return v;
}


// Realiza a leitura do vetor de inteiros pelo teclado.
tipo_VetorInt vetorint_LeituraTeclado(tipo_VetorInt v, int num) { //passa uma struct do tipo tipo_VetorInt e o tamanho
	int i;
	for (i=0; i<num; i++) {
		printf("Digite o elemento %d: ", i+1);
		scanf("%d", &v.vet[i]);
	}
	v.n=num; // n recebe o tamanho
	
	return v; 
}

// Imprime o vetor de inteiros na tela.
void vetorint_ImprimeNaTela(tipo_VetorInt v) {
	int i;
	if (v.n == 0) printf("\nVetor vazio\n");
	else{
		for (i=0; i<v.n; i++) 
		{
		printf("Vetor[%d] = %d\n", i+1, v.vet[i]);
		}
	}
}

// Procura elemento no vetor, retornando sua posicao.
int vetorint_PesquisaSequencial(tipo_VetorInt v, int elem) {
	int i;
	for (i=0; i<v.n; i++) {
		if (elem == v.vet[i]) return i;
	}
	return -1;
}

// Substitui elemento em uma dada posicao do vetor.
tipo_VetorInt vetorint_SubstituiElemento(tipo_VetorInt v, int elem, int pos) {
	if (pos < 0) return v;
	if (pos >= v.n) return v;
	
	v.vet[pos] = elem;
	return v;
}


// Libera memoria e deixa vetorint na condicao de vazio
tipo_VetorInt vetorint_Destroi(tipo_VetorInt v)
{
	free(v.vet);
	v.vet = NULL;
	v.n = 0;
	return v;
}


//Exercicio

//Inicializa o tamanho de um vetor de inteiros e o preenche com
// o conteudo de um arquivo
tipo_VetorInt vetorint_InicializaArquivo(char *nome_arquivo)
{
	FILE *arquivo;
	arquivo = fopen(nome_arquivo,"r");//abrindo o arquivo
	int i,tam;
	tipo_VetorInt v;
	fscanf(arquivo,"%d",&tam); // Primeira informacao do arquivo eh seu o tamanho
	v=vetorint_InicializaTamanho(tam);
	for(i=0;i<tam;i++)
	{
		fscanf(arquivo,"%d",&(v.vet[i]));
	}
	v.n=i;
	return v;
}



// Funcao que insere um elemento novo no vetor.
tipo_VetorInt vetorint_InsereElemento(tipo_VetorInt v, int elem) {
	
	int i,tam;
	tam=(v.n)+1;
	tipo_VetorInt v2;
	v2=vetorint_InicializaTamanho(tam);
	for(i=0;i<tam;i++){
		v2.vet[i]=v.vet[i];
	}
	i--;
	v2.vet[i]=elem;
	v2.n=tam;
	v=vetorint_Destroi(v); //Libera a memoria de v
	return v2;
}


// Funcao que exclui um elemento do especifico do vetor.
tipo_VetorInt vetorint_ExcluiElemento(tipo_VetorInt v, int elem) {
	
	int i, j,v2[v.n],cont=0;
	for(i=0;i<v.n;i++)
	{
		if(v.vet[i]!=elem)
		{
			v2[cont]=v.vet[i];
			cont++;
		}	
	}
	cont--;
	v=vetorint_Destroi(v);
	v=vetorint_InicializaTamanho(cont);
	v.n=cont;
	for(i=0;i<v.n;i++)
	{
		v.vet[i]=v2[i];
	}
	return v;
}

// Cria um vetor soma dos elementos de dois vetores.
tipo_VetorInt vetorint_SomaVetores(tipo_VetorInt v1, tipo_VetorInt v2) 
{
	tipo_VetorInt vSoma;
	int i,tamanho;
	if(v1.n>v2.n) //Caso os vetores não tenham o mesmo tamanho
		tamanho=v1.n;
	else
		tamanho=v2.n;
	vSoma=vetorint_InicializaTamanho(tamanho);
	vSoma.n=tamanho;
	for(i=0;i<tamanho;i++)
	{
		if(i>v1.n)
			vSoma.vet[i]=v2.vet[i];
		else
		{
			if(i>v2.n)
				vSoma.vet[i]=v2.vet[i];
			else
				vSoma.vet[i]=(v1.vet[i]+v2.vet[i]);
		}

	}
	return vSoma;
}

// Funcao que calcula o produto escalar (somatorio dos produtos) de dois vetores
int vetorint_CalculaProdutoEscalar(tipo_VetorInt v1, tipo_VetorInt v2) {
	
	int total=0,i,tamanho;
	if(v1.n<v2.n) //Caso os vetores tenham tamanho diferente, tamanho recebe o valor do menor, pois depois ultrapassar os limites ele passara a ser multiplicado 											por 0 não alterando o resultado final
		tamanho=v1.n;
	else
		tamanho=v2.n;	
	for(i=0;i<tamanho;i++)
	{
		total=((v1.vet[i])*(v2.vet[i]))+total;
	}
	return total;
}

// Libera memoria apos salvar o conteudo do vetor em um arquivo
// que possa ser lido novamente e carregado em memoria
tipo_VetorInt vetorint_DestroiArquivo(tipo_VetorInt v, char *nome_arquivo)
{
	int i;
	FILE *arquivo;
	arquivo=fopen(nome_arquivo,"w");
	fprintf(arquivo,"%d\n",v.n);
	for(i=0;i<v.n;i++)
	{
		fprintf(arquivo,"%d\n",v.vet[i]);
	}
	free(v.vet);
	v.vet = NULL;
	v.n = 0;
	return v;
}
