

int *countingSort(int* a, int k, int tamanhoVetorA){
	
	int *b=(int*)malloc(sizeof(int)*(tamanhoVetorA));
	int i,j;
	int c[k+1];

	for(i=0 ; i<k+1 ; i++){
		c[i]=0;
	}

	for(i=0 ; i<tamanhoVetorA ; i++){
		c[a[i]]++;
	}

	

	for(i=1; i<k+1 ; i++){
		c[i] = c[i] + c[i-1];
	}
	

	
	for(j = tamanhoVetorA-1 ; j>=0 ; j--){
		b[c[a[j]]-1] = a[j]; 

		(c[a[j]])--;
	}


	//IMPRIME VETORES
	/*for(i=0 ; i<tamanhoVetorA; i++){
		printf("\na[%d]: %d", i, a[i]);
	}*/
	
	/*for(i=0 ; i<tamanhoVetorA; i++){
		printf("\nb[%d]: %d", i, b[i]);
	}/*
        for(i=0 ; i<k+1; i++){
		printf("\nc[%d]: %d", i, c[i]);
	}*/
	
	
	return b;
	
	
}
