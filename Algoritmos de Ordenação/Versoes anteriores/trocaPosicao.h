void trocaPosicao(int* valorA, int* valorB){
	int aux;

	aux=*valorB;
	*valorB = *valorA;
	*valorA = aux;
}
