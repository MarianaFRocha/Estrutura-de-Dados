/* 
 Tipo Abstrato de Dados: tipo_FilaInt

*/

// Inclusao de bibliotecas padroes.
#include <stdio.h>
#include <stdlib.h>

// Definicao de constanttes.


// Definicao da estrutura com seus atributos.
struct str_FilaInt {
	int *vet;
	int fim;
	int tamanho;
};
typedef struct str_FilaInt tipo_FilaInt;

// -----------------------
// Prototipos das funcoes.
// -----------------------

//   Operacoes construtoras.
tipo_FilaInt filaint_Inicializa();


//   Operacoes analisadoras.
void filaint_ImprimeNaTela(tipo_FilaInt v);



//   Operacoes modificadoras.
tipo_FilaInt filaint_ENTRAR(tipo_FilaInt v, int num);
tipo_FilaInt filaint_SAIR(tipo_FilaInt v, int *num);

// Operacoes destrutoras
tipo_FilaInt filaint_Destroi(tipo_FilaInt v);


// --------
// Funções:
// --------



// Inicializa um vetor de inteiros vazio.
tipo_FilaInt filaint_Inicializa() {
	tipo_FilaInt v;
	v.tamanho = 1; //inicializada com um elemento
	v.vet = (int *) malloc(v.tamanho*sizeof(int)); 
	v.fim = 0; //fim aponta para a primeira posicao vazia
	return v;
}



// Imprime o vetor de inteiros na tela.
void filaint_ImprimeNaTela(tipo_FilaInt v) {
	int i;
	if (v.fim == 0) printf("\nFila vazia\n");
	else{
		printf("\n\nFila fim = %d \n", v.fim);
		printf("Fila tamanho = %d \n", v.tamanho);
		for (i=0; i<v.fim; i++) 
		{
			printf("Vetor[%d] = %d\n", i+1, v.vet[i]);
		}
	}
}


tipo_FilaInt filaint_ENTRAR(tipo_FilaInt v, int num)
{
	tipo_FilaInt u;
	int i;
	
	if (v.tamanho > v.fim) //se igual então fila cheia
	{
		v.vet[v.fim] = num;
		v.fim++;
		return v;
	}
	// se fila cheia dobra o tamanho da fila
	u.tamanho = 2*v.tamanho;
	u.fim = v.fim;
	u.vet = (int *) malloc(u.tamanho*sizeof(int)); 
	for (i=0; i<v.fim; i++) 
	{
		u.vet[i] = v.vet[i];
	}
	u.vet[u.fim] = num;
	u.fim++;
	v = filaint_Destroi(v);
	return u;
}


tipo_FilaInt filaint_SAIR(tipo_FilaInt v, int *num)
{
	int i;
	if (v.fim == 0) printf("\nFila vazia\n");
	else
	{
		*num = v.vet[0];
		for(i = 0; i < v.fim; i++)
			v.vet[i] = v.vet[i+1];
		v.fim--;
	}
	return v;
}


// Libera memoria e deixa filaint na condicao de vazio
tipo_FilaInt filaint_Destroi(tipo_FilaInt v)
{
	free(v.vet);
	v.vet = NULL;
	v.fim = 0;
	v.tamanho = 0;
	return v;
}
