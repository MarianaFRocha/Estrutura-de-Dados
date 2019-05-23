


int* bubbleSort(int* vetor, int tamanhoVetor){
	int i, j;

	for(i = 0 ; i<tamanhoVetor-1 ; i++){
		for(j = 0 ; j<tamanhoVetor-1 ; j++){
			if(vetor[j]>vetor[j+1]){
				trocaPosicao(&vetor[j], &vetor[j+1]);
			}
		}
	}
	return vetor;
}

