#include <stdio.h>
#include <stdlib.h>


// Prototipo das funcoes
int Leitura_Dinamica_Arquivo_Inteiros(char *nome_arquivo, int *numeros[], int *tamanho);
void SelectionSort(int a[], int array_size);

// argc  : quantidade de strings passadas na chamada do programa
// argv[]: contem as strings passadas na chamada do programa

// Exemplo de uma chamada desse programa
// > leitura_int_dinamico entrada.txt
// argc = 2 (duas strings)
// argv[0] = "leitura_int_dinamico"
// argv[1] = "entrada.txt"


int main(int argc, char *argv[])
  {
    int *numero;
    int j, lidos = 10;

    if(argc < 2) //nome do arquivo de entrada deve ser passado na chamada do programa
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        exit(1);  //Sem arquivo de entrada, nao tem o que fazer, aborta programa
	}


	if (Leitura_Dinamica_Arquivo_Inteiros(argv[1], &numero, &lidos)) //se memoria alocada?
	{
		printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros sao:\n");
		for(j=0 ; j<lidos ; j++) 
		{ 
			printf("numero[%d] = %d\n", j, numero[j]);
		}
		
		printf("\nOs numeros ordenados:\n");
		SelectionSort(numero, lidos);
		for(j=0 ; j<lidos ; j++) 
		{ 
			printf("numero[%d] = %d\n", j, numero[j]);
		}
	}
		free(numero);
	
	return(0);
	
  }


// Dado um arquivo de entrada,
// retorna, via passagem por referência um array de inteiros e o seu tamanho
int Leitura_Dinamica_Arquivo_Inteiros(char *nome_arquivo, int *numeros[], int *tamanho)
{
    FILE *arquivo;
    int lidos = 0;
    
	if((arquivo = fopen(nome_arquivo,"r")) == NULL) //problemas na abertura do arquivo?
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
	fscanf(arquivo, "%d", tamanho); //primeira informacao do arquivo eh a quantidade de inteiros que ele contem
	int *ptr = (int *) malloc((*tamanho) * sizeof(int));
	if(ptr == NULL) return 0; //memoria não alocada
	lidos = 0;
	while (fscanf(arquivo, "%d", &ptr[lidos]) == 1) //Leitura dos inteiros
	{ 
		lidos++;
	}
	fclose(arquivo);
	*numeros = ptr; //retorna array

	return 1;
 }

//Dado um array de inteiros e o seu tamanho
//retorna o array com seu conteudo ordenado
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

/* Atividade 01
Execute o programa acima e compreenda, linha por linha,  as funcoes
"main" e "Leitura_Dinamica_Arquivo_Inteiros".
*/


/* Atividade 02
Esquematize o comportamento da memoria, principalmente na chamada
da funcao "Leitura_Dinamica_Arquivo_Inteiros" 
 */


/* Atividade 03
Altere o programa acima para que dois vetores dinâmicos sejam lidos 
de arquivos diferentes e crie um terceiro vetor com o resultado da 
união dos dois primeiros. Escreva o resultado em um arquivo. 
OBS: A união não deve conter números repetidos.
*/




