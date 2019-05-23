#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "trocaPosicao.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "countingSort.h"

int maior(int *vetor, int tamanhoVetor);

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

	while(!feof(arquivo) ){
		fscanf(arquivo, "%d", &vetor[i]);
		i++;
	}


	//printf("\n****\tDESORDENADO\t****\n");
	//for(i =0 ; i<tamanhoVetor ; i++){
		//printf("\nvetor[%d]: %d", i, vetor[i]);
	//}
	//printf("\n\n");

             //Tempo Counting
             clock_t tcounting0,tcounting1;
             int m = maior(vetor,tamanhoVetor);
             tcounting0 = clock();
             vetor=countingSort(vetor, m,tamanhoVetor);
             tcounting1 = clock();
             double tempocounting= ((tcounting1-tcounting0)*1000/CLOCKS_PER_SEC);
        //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

            //Tempo Bubble
            clock_t tbubble0,tbubble1;
             tbubble0 = clock();
             vetor = bubbleSort(vetor, tamanhoVetor);
             tbubble1 = clock();
             double tempobubble = ((tbubble1-tbubble0)*1000/CLOCKS_PER_SEC);

             //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

            //Tempo Insertion
             clock_t tinsertion0,tinsertion1;
             tinsertion0 = clock();
             insertionSort(vetor, tamanhoVetor);
             tinsertion1 = clock();
             double tempoinsertion= ((tinsertion1-tinsertion0)/CLOCKS_PER_SEC);

               //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

           //Tempo Heap
            clock_t theap0,theap1;
             theap0 = clock();
              heapSort (tamanhoVetor, vetor);
             theap1 = clock();
             double tempoheap= ((theap1-theap0)*1000/CLOCKS_PER_SEC);

              //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

          //Tempo Selection
            clock_t tselection0,tselection1;
             tselection0 = clock();
             vetor = selectionSort(vetor, tamanhoVetor);
             tselection1 = clock();
             double temposelection= ((tselection1-tselection0)*1000/CLOCKS_PER_SEC);

               //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

           //Tempo Quick
            clock_t tquick0,tquick1;
             tquick0 = clock();
             quickSort(vetor, 0, (tamanhoVetor-1));
             tquick1 = clock();
             double tempoquick= ((tquick1-tquick0)*1000/CLOCKS_PER_SEC);

               //Recupera Vetor desordenado
            i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

             //Tempo Shell
            clock_t tshell0,tshell1;
             tshell0 = clock();
              vetor=shellSort(vetor, tamanhoVetor);
             tshell1 = clock();
             double temposhell= ((tshell1-tshell0)*1000/CLOCKS_PER_SEC);

               //Recupera Vetor desordenado
             i = 0;
             while( !feof(arquivo) ){
                fscanf(arquivo, "%d", &vetor[i]);
                  i++;
             }

            //Tempo Merge
            clock_t tmerge0,tmerge1;
             tmerge0 = clock();
             vetor=mergeSort(vetor, tamanhoVetor);
             tmerge1 = clock();
             double tempomerge= ((tmerge1-tmerge0)*1000/CLOCKS_PER_SEC);

       




fclose(arquivo);
    FILE *saida = fopen("Saida.txt","w+");
    int ii;
    for(ii=0;ii<tamanhoVetor;ii++){
        fprintf(saida, "%d\n", vetor[ii]);

    }

    FILE *resultado = fopen("Resultado.txt","w+");
    int jj;
    fprintf(resultado, "Quantidade de chaves: %d\n", tamanhoVetor);
    //fprintf(resultado, "Maior chave: %d\n", m); //m recebeu maior no counting
    fprintf(resultado, "Limite de tempo: %d segundos\n", 3600);
    fprintf(resultado, "Tempo absoluto dos algoritmos(milisegundos):\n");

       //Buble
      fprintf(resultado, "BubbleSort: %f  \n", tempobubble);
        //Insertion
      fprintf(resultado, "InsertionSort: %f  \n", tempoinsertion);
       //Heap
      fprintf(resultado, "HeapSort: %f  \n", tempoheap);
        //Selection
      fprintf(resultado, "SelectionSort: %f  \n", temposelection);
      
        //Quick
      fprintf(resultado, "QuickSort: %f  \n", tempoquick);
        ///Shell
    fprintf(resultado, "ShellSort: %f  \n", temposhell);
    //Merge
   fprintf(resultado, "MergeSort: %f  \n", tempomerge);
        //Counting
       fprintf(resultado, "CountingSort: %f  \n", tempocounting);
     return 0;
}

int maior(int *vetor,int tamanhoVetor){
    int i, maior = vetor[0];
    for(i=0;i<tamanhoVetor;i++)
    {
        if(maior< vetor[i])
          {
              maior= vetor[i];
          }
    }
    return maior;

}
