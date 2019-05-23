#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "trocaPosicao.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
//#include "quickSort.h"
#include "shellSort.h"
#include "mergeSort.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);
	}
	
	int tamanhoVetor;
	int i = 0, aux, j;
	

	
	FILE* arquivo = fopen(argv[1], "r");

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
		//printf("\nvetor[%d]: %d", i, vetor[i]);
	}
	printf("\n\n");

	//vetor = insertionSort(vetor, tamanhoVetor);
	//vetor = bubbleSort(vetor, tamanhoVetor);	
	//heapSort (tamanhoVetor, vetor);
	//vetor = selectionSort(vetor, tamanhoVetor);
	//quickSort(vetor, 0, tamanhoVetor-1);
	//vetor=shellSort(vetor, tamanhoVetor);
	clock_t t0,t1;
        double tempoGasto;
        t0 = clock();
	vetor=mergeSort(vetor, tamanhoVetor);
	
	//for()
        t1 = clock();
        tempoGasto = ((t1-t0));
        printf("TEMPO GASTO: %f",tempoGasto);

	printf("\n****\tORDENADO MERGE\t****\n");
	for(i =0 ; i<tamanhoVetor ; i++){
		//printf("\nvetor2[%d]: %d", i, vetor[i]);
	}
	fclose(arquivo);
        return 0;
}
