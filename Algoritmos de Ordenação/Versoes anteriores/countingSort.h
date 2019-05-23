

void countingSort(int* a, int k, int tamanhoVetorA){
	

	

	//int* b=(int*)malloc(sizeof(int*tamanhoVetorA));
	int b[tamanhoVetorA];
	int i,j;
	int c[k];

	for(i=0 ; i<k ; i++){
		c[i]=0;
	}

	//calcula tamanho de a

	for(i=0 ; i<tamanhoVetorA ; i++){
		c[a[i]]++;
	}

	

	for(i=2; i<k ; i++){
		c[i] = c[i] + c[i-1];
	}

	
	/*for(j = tamanhoVetorA-1 ; j>=0 ; j--){
		b[j] = 0;
		printf("\nb[%d]: %d", j, b[j]);
	}*/

/*
	*/

	for(i=0 ; i<tamanhoVetorA; i++){
		printf("\na[%d]: %d", i, a[i]);
	}

	//FOR DANDO PAU
	for(j = tamanhoVetorA-1 ; j>0 ; j--){
		printf("\n.................a[%d]: %d", j, a[j]);
		printf("\n.................b[c[a[%d]]]: %d", j, b[c[a[j]]]);
		b[c[a[j]]] = a[j];

		c[a[j]]--;
	}


	printf("\n");
	
}