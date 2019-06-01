#include <stdio.h>
#include <string.h>
#include <time.h>


#define TAM_MAX 698299	// numero de RAs final - maximo-> 698299

int main(){

	time_t inicio,fim;

	FILE *arq;
	arq = fopen("dados.txt", "w");
	
	inicio=time(NULL);

	int vetor1[2*TAM_MAX];	//vai pegar de uma fonte com mais valores
	int vetor2[TAM_MAX]; //mudar pra lista depois
	int i,j=0;

	int posicao;

	for(i=0; i<(2*TAM_MAX) ; i++){
		vetor1[i] = i+1;
	}
	
	srand( (unsigned)time(NULL) );
	while(j<TAM_MAX){
		

		//printf("\nposicao: ");		
		//scanf("%d",&posicao);
		
		
		posicao= 0 + ( rand() % TAM_MAX); // coloquei % 2*TAM_MAX-1 , mas nao gerava aleatorio direito

//		printf("\nposicao: %d", posicao);
		
		if(vetor1[posicao]!=-1){
			vetor2[j]=vetor1[posicao];
			vetor1[posicao]=-1;
			j++;
			
		}

	}
/*
	printf("\nvetor 1 (descartavel): \n");
	for(i=0 ; i<(2*TAM_MAX) ; i++){
		printf("%d\t", vetor1[i]);
	}
*/
	//printf("\nvetor 2 (RAs aleatorios sem repetir): \n");
	for(i=0 ; i<TAM_MAX ; i++){
		fprintf(arq, "%d nome sobrenome\n",vetor2[i]);
		//printf("%d\t", vetor2[i]);
	}

	fim = time(NULL);
	printf("\nTempo de execucao: %.0f segundos\n", difftime(fim, inicio));
	printf("\n\n");
	fclose(arq);
}