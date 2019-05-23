
void merge(int *vetor, int inicio, int meio, int fim)
{
	int aux[fim-inicio+1];
	int i=inicio,j=(meio+1),k=0;
	while((i<=(meio))&&(j<=fim))
	{
		if(vetor[i]<vetor[j])
		{
			aux[k]=vetor[i];
			i++;
		}
		else
		{
			aux[k]=vetor[j];
			j++;
		}
		k++;
	}
	while(i<=(meio))
	{
		aux[k]=vetor[i];
		k++;
		i++;
	}
	while(j<=fim)
	{
		aux[k]=vetor[j];
		k++;
		j++;
	}
	for(i=0;i<=(fim-inicio);i++)
	{
		vetor[i+inicio]=aux[i];
	}
}



void algMergeSort(int *vetor, int inicio, int fim)
{
	if(inicio<fim)
	{
		int meio=(inicio+fim)/2;
		algMergeSort(vetor,inicio,meio);
		algMergeSort(vetor,meio+1,fim);
		merge(vetor,inicio,meio,fim);
	}

}

int* mergeSort(int *vetor, int tamanhoVetor)
{
	algMergeSort(vetor,0, tamanhoVetor-1);
	return vetor;
}
