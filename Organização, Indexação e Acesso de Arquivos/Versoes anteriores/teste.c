#include <stdio.h>
#include <string.h>

int main(){

	// Declaracao das variaveis
	unsigned long int b[10], i;
	char a[10];
	
	printf("VALORES INICIAIS: A preenchido de 1 a 10 | B zerado\n\n");

	// Preenchemos o array a com numeros de 1 a 10 e o array b com zeros
	for (i = 0; i < 10; i++)
	{

		// Atrbuicao dos valores
		a[i] = i + 1;
		b[i] = 0;

		// Exibicao dos valores atuais
		printf("A %d -> %d\n", i, a[i]);
		printf("B %d -> %d\n", i, b[i]);

	}

	// Atraves da funcao memcpy, copiamos todos os dados contidos em a, para b
	memcpy(b, a, sizeof(b));
	
	printf("\n\nVALORES APOS A COPIA DE MEMORIA\n\n");

	// Exibicao dos valores apos a copia de memoria
	for (i = 0; i < 10; i++)
	{
		printf("A %d -> %d\n", i, a[i]);
		printf("B %d -> %d\n", i, b[i]);
	}

}