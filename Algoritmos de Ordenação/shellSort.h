

int* shellSort(int* vetor, int tamanhoVetor)
{
	int h=1, aux, p, a,i;
	do h=(h*3)+1; while(h<=tamanhoVetor); // sequencia de incremento de knuth
	do
	{

		h=(h-1)/3;
		for(p=h; p<=tamanhoVetor; p++)
		{
			aux=vetor[p];
			a=p-h; // Calcula o indice do valor anterior
			while((a>=0) && (aux<vetor[a]))  //O indice tem que ser maior que 0 e o proximo numero menor que o anterior
			{
				vetor[a+h]=vetor[a];
				a=a-h;
			}
			vetor[a+h]=aux;
		}
	}while(h!=1);
	
	return vetor;
}
