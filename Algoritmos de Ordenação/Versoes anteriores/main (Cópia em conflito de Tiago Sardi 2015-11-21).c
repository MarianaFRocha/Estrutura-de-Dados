#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "geraArquivo.h"
#include "trocaPosicao.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "countingSort.h"

int maiorNumero(int* vetor, int tamanhoVetor);

int main(){
	
	int tamanhoVetor;
	int i = 0, aux, j;
	

	criaArquivo();
	FILE* arquivo = fopen("entrada.txt", "r");

	if(arquivo == NULL){
		printf("\nProblema ao ler o arquivo!");
		return 0;
	}

	fscanf(arquivo, "%d", &tamanhoVetor);	//a ideia é separar o primeiro valor do arquivo e só os demais entrarem no vetor
	
	int* vetor=(int*)malloc(sizeof(int)*(tamanhoVetor));
	
	while( !feof(arquivo) ){
		fscanf(arquivo, "%d", &vetor[i]);
		i++;
	}

	printf("\n****\tDESORDENADO\t****\n");
	for(i =0 ; i<tamanhoVetor ; i++){
		printf("\nvetor[%d]: %d", i, vetor[i]);
	}
	printf("\n\n");

	//vetor = insertionSort(vetor, tamanhoVetor);
	//vetor = bubbleSort(vetor, tamanhoVetor);	
	//heapSort (tamanhoVetor, vetor);
	//vetor = selectionSort(vetor, tamanhoVetor);
	//quickSort(vetor, 0, tamanhoVetor-1);
	//vetor=shellSort(vetor, tamanhoVetor);
	//vetor=mergeSort(vetor, tamanhoVetor);

	//COUNTING SORT
	int k = maiorNumero(vetor, tamanhoVetor);
	//vetor = countingSort(vetor, ,tamanhoVetor);
	printf("tam de k: %d", k);
	
	countingSort(vetor, k, tamanhoVetor);
	printf("\n****\tORDENADO\t****\n");
	for(i =0 ; i<tamanhoVetor ; i++){
		printf("\nvetor2[%d]: %d", i, vetor[i]);
	}
	fclose(arquivo);
}

int maiorNumero(int* vetor, int tamanhoVetor){

	int i;
	int maiorNumero= vetor[0];
	for(i=1 ; i<tamanhoVetor ; i++){
		if(vetor[i]>maiorNumero){
			maiorNumero=vetor[i];
		}
	}
	return maiorNumero;
}