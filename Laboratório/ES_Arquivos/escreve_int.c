#include <stdio.h>
#include <stdlib.h>

// Prototipo das funcoes
void Escreve_Arquivo_Inteiros(char *nome_arquivo);

// argc  : quantidade de strings passadas na chamada do programa
// argv[]: contem as strings passadas na chamada do programa

// Exemplo de uma chamada desse programa
// > escreve_int entrada.txt
// argc = 2 (duas strings)
// argv[0] = "escreve_int"
// argv[1] = "entrada.txt"

int main(int argc, char *argv[])
  {
    if(argc < 2)
      {
        printf("\nErro: Digite o nome do arquivo !!!\n\n");
        system("PAUSE");
        exit(1);
      }
    //Cria e salva no disco um arquivo de inteiros
    Escreve_Arquivo_Inteiros(argv[1]);
    return(0); 
  }




// Cria e salva no disco um arquivo de inteiros
// Recebe como entrada o nome do arquivo a ser criado no disco
void Escreve_Arquivo_Inteiros(char *nome_arquivo)
{
    FILE *arquivo;
    int a;
    // Se o Sistema Operacional conseguiu criar/abrir o arquivo?
    if((arquivo = fopen(nome_arquivo,"w")) == NULL) 
    {
        printf("Erro ao criar/abrir arquivo!!!\n\n");
        exit(1);
    }
    printf("\n entre com um numero:");
    scanf("%d", &a);
    while (a != -999) //preenche o arquivo ate o usuario digitar "-999"
    {
    	fprintf(arquivo, "%d\n", a);
     	// le o próximo número
     	printf("\nentre com um numero:");
     	scanf("%d", &a);
    }
    fclose(arquivo);
    printf("\nGravado com sucesso em %s\n\n",nome_arquivo);
 }
