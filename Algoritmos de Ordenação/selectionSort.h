int* selectionSort(int* vetor, int tamanho){
	int pivoA;
	int i,j;

	for(i=0 ; i<tamanho-1 ; i++){
		pivoA=i;
		for(j=i+1 ; j<tamanho ; j++){
			if(vetor[j] < vetor[pivoA])
				pivoA=j;
		}
		if( i!= pivoA)
			trocaPosicao(&vetor[i], &vetor[pivoA]);
	}

	return vetor;

}