
#include "arvore_Percurso.h"


int main()
{
   	arvore T, arvore_esq, arvore_dir, TT,  TTT;
   	int conteudo_esq, conteudo_dir, conteudo_raiz ;
  
 
 	//controi arvore T: raiz(1) 
 	//         esquerda(2)  direita(3)
   	printf("\n\n---------------------- T ----------------------");
   	inicia_arvore(&T);
 	conteudo_esq = 2;
   	aloca_arvore_no(&arvore_esq, conteudo_esq);
   	conteudo_dir = 3;
   	aloca_arvore_no(&arvore_dir,conteudo_dir);
   	conteudo_raiz = 1;
   	insere_raiz(&T, conteudo_raiz, arvore_esq, arvore_dir);
   	percorre_arvore(T,PREORDEM);
   	percorre_arvore(T,EMORDEM);
   	percorre_arvore(T,POSORDEM);

 	//controi arvore TT: raiz(-1) 
 	//         esquerda(-2)  direita(-3)
 	printf("\n\n---------------------- TT ----------------------");
	inicia_arvore(&TT);
	conteudo_esq = -2;
   	aloca_arvore_no(&arvore_esq, conteudo_esq);
   	conteudo_dir = 3;
   	aloca_arvore_no(&arvore_dir,conteudo_dir);
   	conteudo_raiz = -1;
   	insere_raiz(&TT, conteudo_raiz, arvore_esq, arvore_dir);
	
	percorre_arvore(TT,PREORDEM);
   	percorre_arvore(TT,EMORDEM);
   	percorre_arvore(TT,POSORDEM);
	
 	//controi arvore TTT:           raiz(0)
 	//                    esquerda(1)     direta(-1)
 	//                 esq(2)  dir(3)   esqu(-2)  dir(3)
   	printf("\n\n---------------------- T ----------------------"); 	
	inicia_arvore(&TTT);
	conteudo_raiz = 0;
   	insere_raiz(&TTT, conteudo_raiz, T, TT);
	
	percorre_arvore(TTT,PREORDEM);
   	percorre_arvore(TTT,EMORDEM);
   	percorre_arvore(TTT,POSORDEM);	

	int i = contNo(TTT, 0);
	
	printf("\nQuestão 2: \nQuantidade de folhas: %d \n", i);

	i=contDado(TTT, 3, 0);
	printf("\nQuestão 2: \nQuantidade de elemento 3: %d \n", i);	

	destroi_arvore(&TTT);
	percorre_arvore(TTT,PREORDEM);
   	percorre_arvore(TTT,EMORDEM);
   	percorre_arvore(TTT,POSORDEM);	

	i = contNo(TTT, 0);
	
	printf("\nQuantidade de nos: %d \n", i);

   return 0;
}




