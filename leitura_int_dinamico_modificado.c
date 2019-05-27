#include <stdio.h>
#include <stdlib.h>

//Teste Git

// Prototipo das funcoes
int Leitura_Dinamica_Arquivo_Inteiros(char *nome_arquivo1, char *nome_arquivo2, int *numeros[], int *tamanho);
void SelectionSort(int a[], int array_size);
int TiraRepetido(int *a[], int array_size);

// argc  : quantidade de strings passadas na chamada do programa
// argv[]: contem as strings passadas na chamada do programa

// Exemplo de uma chamada desse programa
// > leitura_int_dinamico entrada.txt
// argc = 2 (duas strings)
// argv[0] = "leitura_int_dinamico"
// argv[1] = "entrada.txt"


int main(int argc, char *argv[])
  {
	FILE *arquivo; 
    int *numero;
    int j, k, lidos = 10;//k=tamanho final do vetor dinamico, sem as repetições

	arquivo=fopen("arquivo_final","w"); //Abrindo o arquivo onde será escrito o vetor final do exercicio 3	

    if(argc < 3) //nome do arquivo de entrada deve ser passado na chamada do programa
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);  //Sem arquivo de entrada, nao tem o que fazer, aborta programa
	}


	if (Leitura_Dinamica_Arquivo_Inteiros(argv[1], argv[2], &numero, &lidos)) //se memoria alocada?
	{

		printf("\n\nQuantidade de numeros lidos: %d\n", lidos);
		printf("Os numeros sao:\n");
		for(j=0 ; j<lidos ; j++) 
		{ 
			printf("numero[%d] = %d\n", j, numero[j]);
		}

		printf("\nOs numeros ordenados e sem repeticao:\n");
		SelectionSort(numero, lidos);
		k=TiraRepetido(&numero,lidos);
		fprintf(arquivo,"%d\n",k); //Vai colocar na primeira linha do novo vetor a quantidade de inteiros que ele contem 
		for(j=0 ; j<k ; j++) 
		{ 
			printf("numero[%d] = %d\n", j, numero[j]);
			fprintf(arquivo,"%d\n",numero[j]);  //Vai copiar o novo vetor para o arquivo
		}
	}
		free(numero);
	
	return(0);
	
  }


// Dado um arquivo de entrada,
// retorna, via passagem por referência um array de inteiros e o seu tamanho
int Leitura_Dinamica_Arquivo_Inteiros(char *nome_arquivo1, char *nome_arquivo2, int *numeros[], int *tamanho)
{
    FILE *arquivo1, *arquivo2;
    int lidos = 0, i, j;
	if(((arquivo1 = fopen(nome_arquivo1,"r")) == NULL) || ((arquivo2 = fopen(nome_arquivo2,"r")) == NULL)) //problemas na abertura do arquivo?
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
	fscanf(arquivo1, "%d", &i); //primeira informacao do arquivo eh a quantidade de inteiros que ele contem
	fscanf(arquivo2, "%d", &j); //primeira informacao do arquivo eh a quantidade de inteiros que ele contem
	*tamanho = i+j; //Soma o tamanho dos dois arquivos
	int *ptr = (int *) malloc((*tamanho) * sizeof(int));
	if(ptr == NULL) return 0; //memoria não alocada
	while (fscanf(arquivo1, "%d", &ptr[lidos]) == 1) //Leitura dos inteiros do arquivo 1
	{ 
		lidos++;
	}
	while (fscanf(arquivo2, "%d", &ptr[lidos]) == 1) //Leitura dos inteiros do arquivo 2
	{ 
		lidos++;
	}

	fclose(arquivo1);
	fclose(arquivo2);
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

//Funcao para retirar os numeros repetidos
int TiraRepetido(int *a[], int array_size)
{
	int i,j,k,v[array_size];
	for(i=0,j=1,k=0;j<array_size;i++,j++){  //Vai passar para um novo vetor o ultimo numero de uma sequencia de repeticao

		if((*a)[i]!=(*a)[j])
		{
			v[k]=(*a)[i];
			k++;
		}
	}

	if((*a)[i]!=v[k-1]) //soluciona o caso do ultimo numero do vetor
		v[k++]=(*a)[i];

	int *vet=(int*)malloc((k)*(sizeof(int))); // aloca memoria adequada para o novo vetor
	for(i=0;i<k;i++) //copia os numeros para o novo espaço de memoria
	{
		vet[i]=v[i];
	}
	*a=vet; //retorna o vetor
	return k; //o novo tamanho do vetor
}
