
void insertionSort(int* vetor, int tamanhoVetor){

	int i, aux, j;

	for(i=0 ; i<tamanhoVetor ; i++){
		j=i;

		// se um valor estiver maior que seu proximo então vá voltando até encontrar a posição certa desse proximo
		for( j=i ; j>0 ; j--){	
			if((vetor[j] < vetor[j-1]))
				trocaPosicao(&vetor[j], &vetor[j-1]);
		}
	}
	//return vetor;
}