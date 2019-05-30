#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TAM_MAX 14 // EDITE AQUI ***************************

int* criaVetor1(){
  int i;

  int *vetor1=(int*)malloc((2*TAM_MAX)*sizeof(int));
  //int vetor1[2*TAM_MAX];  //vai pegar de uma fonte com mais valores

  for(i=0; i<(2*TAM_MAX) ; i++){
    vetor1[i] = i+1;
  }

  return vetor1;

}

int criaRA(){
  //cria somente 1 RA aleatorio

  //int* vetor2=(int*)malloc(TAM_MAX*(sizeof(int)));

  //essa eh a funcao extraiRA que vai daqui...

  FILE *arq;
  arq = fopen("dados.txt", "r");

  char linha[200], *ra_aux;
  int ra, i=0;
  int* vetor2=(int*)malloc(TAM_MAX * sizeof(int*));
  
  while((i<TAM_MAX)&&(fgets(linha, sizeof(linha), arq))!=NULL ){
    ra_aux = (char*)strtok(linha, "&");
    vetor2[i] = atoi(ra_aux);
    i++;
            
  }
  //...ateh aqui. Se conseguirem chamar a funcao extraiRA seria ótimo.
  //int* vetor2 = extraiRA();
  

  srand( (unsigned)time(NULL) );
  int novoRA = 1 + ( rand() % TAM_MAX);
  printf("\ncomecando com: %d", novoRA);
  for(i=0 ; i<TAM_MAX ; i++){
    if(novoRA == vetor2[i]){
      novoRA= 1 + ( rand() % 2*TAM_MAX);
      i=-1;
      printf("\nRA atual: %d", novoRA);
     
    }
    
  }

  return novoRA;
  
}

int* extraiRA(){

  FILE *arq;
  arq = fopen("dados.txt", "r");

  char linha[200], *ra_aux;
  int ra, i=0;
  int* vetor2=(int*)malloc(TAM_MAX * sizeof(int*));
  

  while((i<TAM_MAX)&&(fgets(linha, sizeof(linha), arq))!=NULL ){
    ra_aux = (char*)strtok(linha, "&");
    vetor2[i] = atoi(ra_aux);
    i++;
            
  }

  /*for(i=0; i<TAM_MAX ; i++){
    printf("\nmeus RAs lindos caramba: %lu", sizeof(vetor2[i]));
  }*/

  return vetor2;
}

int* geraRA(int *vetor1){
  printf("\n\ndeu certo\n\n");

  int* vetor2=(int*)malloc(TAM_MAX * sizeof(int));
  
  int j=0;
  int posicao;

  int i;
  for(i=0 ; i<2*TAM_MAX; i++){
    printf("\n%d",vetor1[i]);
  }

  srand( (unsigned)time(NULL) );
  while(j<TAM_MAX){

    posicao= 0 + ( rand() % TAM_MAX);

  


    if(vetor1[posicao]!=-1){
      vetor2[j]=vetor1[posicao];
      vetor1[posicao]=-1;
      j++;
    }
  }
  return vetor2;
}

void geraArquivo(){

  time_t inicio,fim;
  inicio=time(NULL);

  FILE *arq;
  arq = fopen("dados.txt", "w");

   //mudar pra lista depois
  int i;

  int* vetor1=criaVetor1();

  int* vetor2=geraRA(vetor1);


  for(i=0 ; i<TAM_MAX ; i++){
    fprintf(arq, "%d&nome&sobrenome&10&08&5\n",vetor2[i]);
  }

  fim = time(NULL);
  printf("\nTempo de execucao: %.0f segundos\n", difftime(fim, inicio));
  printf("\nArquivo gerado com sucesso!\n");


  fclose(arq);
}