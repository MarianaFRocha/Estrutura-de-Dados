
#include "ABB.h"
#include <time.h>


int main()
{
   char a[20];
    printf("Digite o nome do arquivo\n");
    scanf("%s",a);
    
    //INSERIR
    //clock_t t;
    //t = clock();
    int m = Leitura_Arquivo_Inteiros(a);
    //t = clock() - t;
    //printf ("TEMPO: %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    
  
    //BUSCAR
    clock_t t2;
    char nome[20];
    
    printf("Buscar");
    scanf("%s",nome);
    //t2 = clock();
    busca_arq(nome);
    //t2 = clock() - t2;
    //printf ("TEMPO: %d clicks (%f seconds).\n",t2,((float)t2)/CLOCKS_PER_SEC);
    
    //exclui_arq(nome);
    return 0;

}
