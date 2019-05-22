#include <stdio.h>
#include <stdlib.h>

#define ESQUERDA(T) ((T)->esquerda)
#define DIREITA(T) ((T)->direita)
#define CONTEUDO(T) ((T)->conteudo)


typedef enum {OK, ERROR} status;
typedef enum {FALSE=0, TRUE=1 } bool;
typedef enum {PREORDEM,EMORDEM, POSORDEM} ORDEM;

typedef struct arvore_no arvore_no, *arvore;
typedef int dado;


struct arvore_no
{
	int conteudo;
	arvore esquerda;
	arvore direita;
};

arvore myarvore;
status percurso_preordem(arvore T);
arvore_no* insere(arvore *p_T, arvore_no *novo);
status exclui(arvore *p_T, int novo);
status percurso_emordem(arvore T);

status aloca_arvore_no(arvore *p_T, int conteudo, arvore_no **T) //aqui tem q ser um p de p
{
	*T =  (arvore)malloc(sizeof(arvore_no));
	if (*T == NULL) return ERROR;


	CONTEUDO(*T) = conteudo;
	ESQUERDA(*T) = NULL;
	DIREITA(*T)  = NULL;

	return OK;
}


void libera_arvore_no(arvore *p_T)
{
	free(*p_T);
	*p_T = NULL;
}


status inicia_arvore(arvore *p_T)
{
	*p_T = NULL;
	return OK;
}

bool arvore_vazia(arvore T)
{
	return(T == NULL) ? TRUE : FALSE;
}

int Leitura_Arquivo_Inteiros(char *nome_arquivo)
{

    FILE *arquivo;
    int num;
    char nome[20];
    inicia_arvore(&myarvore);

	if((arquivo = fopen(nome_arquivo,"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
	int cont=0;
    while(fscanf(arquivo, "%d", &num) == 1)
    {
        arvore_no *no;
        aloca_arvore_no(&myarvore, num, &no);
        
        arvore_no *pp;
        pp = insere(&myarvore,no);

        if (pp==NULL)
        {
            myarvore = no;
        }

        else if (CONTEUDO(pp) > CONTEUDO(no))
        {
            ESQUERDA(pp) = no;
            if (pp!= NULL); 

        }
        else
        {
            DIREITA(pp)= no;
            if (pp!= NULL) ;
        }



    }


    //percurso_preordem(myarvore);
    return 1;

}

arvore_no* insere(arvore *p_T, arvore_no *novo)   
{
 

    arvore_no *p, *r;
    

    if (arvore_vazia(*p_T) == TRUE)
    {
        *p_T = novo;
        
        return NULL;
    }
    else
    {


          

        r = *p_T;
        p = NULL;

        while (r != NULL)
            {
                 

                p = r;
                if (CONTEUDO(r) > CONTEUDO(novo))
                {
                    r = (ESQUERDA(r));
                    
                }
                else
                {
                    r = (DIREITA(r));  
                    //printf("\nComparado: %d %d , MENOR %d\n",CONTEUDO(r),CONTEUDO(novo),CONTEUDO(r));
                }
                

            }

        //printf("PAI: %d ESQUERDA: %d  DIREITA: %d" ,CONTEUDO(p),ESQUERDA(p),DIREITA(p));  //NAO TA SENDO MODIFICADA A ARVORE!!!!!!

    }
    //printf("\nnot null>%p\n",p);
   // r = novo;
    return p;


}


void busca(arvore *p_T, int novo)
{
    arvore_no *r;
    r = *p_T;
    int achou=0;

    while ((r != NULL) &&!(achou))
    {
       if (CONTEUDO(r)>novo)
       r=ESQUERDA(r);
       else if(CONTEUDO(r)==novo)
            achou = 1;
       else
            r = DIREITA(r);
    }
    if (r==NULL) printf("Nao encontrado!");

   // else //printf("\nAchei o %d\n",CONTEUDO(r));

}

void busca_arq(char nome[30])
{
    FILE *arquivo;
    if((arquivo = fopen(nome,"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}
    int num;
    while(fscanf(arquivo, "%d", &num) == 1)
    {
        busca(&myarvore, num);

    }

}

void exclui_arq(char nome[30])
{
    FILE *arquivo;
    if((arquivo = fopen(nome,"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}

    int num;
    while(fscanf(arquivo, "%d", &num) == 1)
    {
        exclui(&myarvore, num);

    }
    //printf("agora:\n");
    percurso_emordem(myarvore);



}




status exclui(arvore *p_T, int novo)
{




    arvore_no *p, *r,*q;


    if (arvore_vazia(*p_T) == TRUE)
    {
       // printf("dkadasdsad5a4sd5a4s");

        return OK;
    }
    else
    {
        arvore_no *r,*p;
        r = *p_T;
        int achou=0;

        while ((r != NULL) &&!(achou))
       {


          if (CONTEUDO(r)>novo)
          {

                  p=r;
                  r=ESQUERDA(r);
          }

          else if(CONTEUDO(r)==novo)
               achou = 1;
          else
          {
              p=r;
              r = DIREITA(r);
          }



       }
       // printf("tentei %d %d\n",novo,r);

        if (r==NULL) printf("Nao encontrado!");


        if (r!=NULL)
            {
                printf("--");



                if ((ESQUERDA(r) ==NULL) && (DIREITA(r)==NULL))
                {
                    printf("oi");

                    if (CONTEUDO(p)> CONTEUDO(r))
                        ESQUERDA(p)=NULL;
                    else
                        DIREITA(p)=NULL;
                     printf("\nAdeus: %d",CONTEUDO(r));
                    free(r);


                }
                else if (ESQUERDA(r) == NULL)
                {
                    printf("tcha");

                    if (CONTEUDO(p)> CONTEUDO(r))
                        ESQUERDA(p)=DIREITA(r);
                    else
                        DIREITA(p)=DIREITA(r);
                    printf("\nAdeus: %d",CONTEUDO(r));

                    free(r);
                    printf("OK");


               //copiei e pá
                }
                else if (DIREITA(r) == NULL)
                {
                    printf("aa");

                    if (CONTEUDO(p)> CONTEUDO(r))
                        ESQUERDA(p)=ESQUERDA(r);
                    else
                        DIREITA(p)=ESQUERDA(r);
                    printf("\nAdeus: %d",CONTEUDO(r));

                     free(r);
                }


                else if (((ESQUERDA(r) !=NULL) && (DIREITA(r)!=NULL)))
                    {

                        arvore pai_p,aux;
                        aux=DIREITA(r);
                        pai_p=DIREITA(r);


                        while(ESQUERDA(aux)!=NULL) //vendo o sucessor
                        {
                            //printf("bb"); //LOLLLLp
                            pai_p=aux;
                            aux = ESQUERDA(aux);
                            //printf("%p %p ",aux,ESQUERDA(aux));

                        }


                        printf("\nsucessor: -> %p %d ",p,CONTEUDO(r));

                        CONTEUDO(r)=CONTEUDO(aux);
                        printf("cont %p %p",(ESQUERDA(pai_p)),DIREITA(aux));
                        if (ESQUERDA(pai_p)!=NULL)ESQUERDA(pai_p)=DIREITA(p);
                        if (p==NULL) printf("explica essa") ;
                        printf("\nAdeus: %d",CONTEUDO(aux));
                        free(aux);
                        printf("ok");


                    }
            }
    }


    printf("*************excluido");

    return OK;
}


/*


no *seguinte( no *x) {
    if (x->dir != NULL) {
       no *y = x->dir;
       while (y->esq != NULL) y = y->esq;
       return y;                                 // *
    }
    while (x->pai != NULL && x->pai->dir == x)   // **
       x = x->pai;                               // **
    return x->pai;*
}*/








status percurso_preordem(arvore T)
{



	if (arvore_vazia(T) == TRUE) return OK;
	printf ("\n%d\n",CONTEUDO(T));

	percurso_preordem(ESQUERDA(T));
	percurso_preordem(DIREITA(T));
	return OK;
}


//percurso em-ordem
status percurso_emordem(arvore T)
{
	status rc;
	if (arvore_vazia(T) == TRUE) return OK;
	rc = percurso_emordem(ESQUERDA(T));
	printf ("\n%d\n",CONTEUDO(T));
	rc = percurso_emordem(DIREITA(T));
	return rc;
}
/*
//percurso pos-ordem
status percurso_posordem(arvore T)
{
	status rc;
	if (arvore_vazia(T) == TRUE) return OK;
	rc = percurso_posordem(ESQUERDA(T));
	rc = percurso_posordem(DIREITA(T));
	VISITA(T);
	return rc;
}
*/


