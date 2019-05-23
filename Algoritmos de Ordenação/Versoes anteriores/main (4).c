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
         fclose(arquivo);

	//printf("\n****\tDESORDENADO\t****\n");
	//for(i =0 ; i<tamanhoVetor ; i++){
		//printf("\nvetor[%d]: %d", i, vetor[i]);
	//}
	//printf("\n\n");

            //Tempo Bubble
            clock_t tbubble0,tbubble1;
             tbubble0 = clock();
            //vetor = bubbleSort(vetor, tamanhoVetor);
             tbubble1 = clock();
             double tempobubble = ((tbubble1-tbubble0)*1000/CLOCKS_PER_SEC);


            //Tempo Insertion
            clock_t tinsertion0,tinsertion1;
             tinsertion0 = clock();
           //vetor = insertionSort(vetor, tamanhoVetor);
             tinsertion1 = clock();
             double tempoinsertion= ((tinsertion1-tinsertion0)*1000/CLOCKS_PER_SEC);

           //Tempo Heap
            clock_t theap0,theap1;
             theap0 = clock();
             //heapSort (tamanhoVetor, vetor);
             theap1 = clock();
             double tempoheap= ((theap1-theap0)*1000/CLOCKS_PER_SEC);

           //Tempo Selection
            clock_t tselection0,tselection1;
             tselectionp0 = clock();
           //vetor = selectionSort(vetor, tamanhoVetor);
             tselection1 = clock();
             double temposelection= ((tselection1-tselection0)*1000/CLOCKS_PER_SEC);

           //Tempo Quick
            clock_t tquick0,tquick1;
             tquick0 = clock();
           //quickSort(vetor, 0, tamanhoVetor-1);
             tquick1 = clock();
             double tempoquick= ((tquick1-tquick0)*1000/CLOCKS_PER_SEC);

             //Tempo Shell
            clock_t tshell0,tshell1;
             tshell0 = clock();
             //vetor=shellSort(vetor, tamanhoVetor);
             tshell1 = clock();
             double temposhell= ((tshell1-tshell0)*1000/CLOCKS_PER_SEC);

            //Tempo Merge
            clock_t tmerge0,tmerge1;
             tmerge0 = clock();
             //vetor=mergeSort(vetor, tamanhoVetor);
             tmerge1 = clock();
             double tempomerge= ((tmerge1-tmerge0)*1000/CLOCKS_PER_SEC);

             //Tempo Counting





    FILE *saida = fopen("Saida.txt","w+");
    int ii;
    for(ii=0;ii<tamanhoVetor-1;ii++){
        fprintf(saida, "%d\n", vetor[ii]);

    }

    FILE *resultado = fopen("Resultado.txt","w+");
    int jj;
    fprintf(resultado, "Quantidade de chaves: %d\n", tamanhoVetor);
    fprintf(resultado, "Maior chave: %d\n", 11);
    fprintf(resultado, "Limite de tempo: %d segundos\n", 1200);
    fprintf(resultado, "Tempo absoluto dos algoritmos:\n");

       //Buble
        //Insertion
        //Heap
        //Selection
        //Quick
        //Shell
    //Merge
        //Counting





     return 0;
}
