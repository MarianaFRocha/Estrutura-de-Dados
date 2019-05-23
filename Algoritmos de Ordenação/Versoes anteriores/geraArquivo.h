#define MAX 10

void criaArquivo(){

  int i, valor;
  FILE *arq;
  arq = fopen("entrada.txt", "w+");
  if(arq == NULL){
    printf("\nErro ao criar o arquivo!");
    return ;
  }
  fprintf(arq, "%d\n", MAX);
  srand( (unsigned)time(NULL) );
  for(i=0; i<MAX ; i++){
    valor= 0 + ( rand() % (2*MAX));
    fprintf(arq, "%d\n", valor);
  }
  
  fclose(arq);

}
