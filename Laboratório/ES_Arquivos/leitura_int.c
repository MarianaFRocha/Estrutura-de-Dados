#include <stdio.h>
#include <stdlib.h>

// Prototipo das funcoes
void SelectionSort(int a[], int array_size);


// argc  : quantidade de strings passadas na chamada do programa
// argv[]: contem as strings passadas na chamada do programa

// Exemplo de uma chamada desse programa
// > leitura_int entrada.txt
// argc = 2 (duas strings)
// argv[0] = "leitura_int"
// argv[1] = "entrada.txt"

int main(int argc, char *argv[])
  {
    FILE *arquivo;
    const int tam = 30;
    int numeros[tam];
    int j, lidos = 0;

    if(argc < 2)
  	{
            printf("\nErro: Digite o nome do arquivo !!!\n\n");
            exit(1);
	}
       // Se o Sistema Operacional conseguiu abrir o arquivo?
	if((arquivo = fopen(argv[1],"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}

	lidos = 0 ;
        // Le os inteiros do arquivo enquanto nao for final de arquivo.
        // Salva cada inteiro lido no vetor numeros[].
        
	while((lidos < tam-1) && (fscanf(arquivo, "%d", &numeros[lidos]) == 1))
	{ 
		lidos++; // Qual a quantidade maxima de inteiros que podem ser lidos?
	}
	fclose(arquivo);

	printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
	printf("Os numeros sao:\n");

	for(j=0 ; j<lidos ; j++) 
	{ 
		printf("%d\n", numeros[j]);
	}
	
	printf("\nOs numeros ordenados:\n");
	SelectionSort(numeros, lidos);  //ordena vetor numeros[].
	for(j=0 ; j<lidos ; j++) 
	{ 
		printf("%d\n", numeros[j]);
	}

	return(0); 
	
  }


void SelectionSort(int a[], int array_size)
{
     int i;
     for (i = 0; i < array_size - 1; ++i)
     {
          int j, min, temp;
          min = i;
          for (j = i+1; j < array_size; ++j)
          {
               if (a[j] < a[min])
                    min = j;
          }

          temp = a[i];
          a[i] = a[min];
          a[min] = temp;
     }
}
















