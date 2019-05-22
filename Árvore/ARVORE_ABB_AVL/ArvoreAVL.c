# include <stdlib.h>
# include <stdio.h>

typedef struct node
{
  int id;
  struct node *esq;
  struct node *dir;
}node;

/*****PROTOTIPO DAS FUNCOES*******/
void exibe(node*R, int nivel);
node** sucessor(node*R);
node** predecessor(node*R);
void busca(node*R, int chave);
void inserechave(node**R, int chave);
void removerchave(node**R, int chave);
int hEsq(node*R);
int hDir(node*R);
int balanceamento(node*R);
node* rotEsq(node*R);
node* rotDir(node*R);
node* rotDuplaEsq(node*R);
node* rotDuplaDir(node*R);
void balanceaDir(node**R,int chave);
void balanceaEsq(node**R,int chave);
int carregaArquivo(node**R);
void criarArquivo(FILE* arquivo);
void salvaNoArquivo(node*R, FILE* arquivo);
void EscreverArquivo(FILE* arquivo, int chave);


void inserechave(node**R, int chave){
     if(*R == NULL){
            *R = (node*)malloc(sizeof(node));
            (*R)->id = chave;
            (*R)->esq = NULL;
            (*R)->dir = NULL;
     }
     else{
       if((*R)->id > chave){
         inserechave(&(*R)->esq,chave);

         if(balanceamento(*R) < -1 || balanceamento(*R) > 1){

           if(chave < (*R)->esq->id){
             printf("Rotacao Simples a direita\t");
             *R = rotDir(*R);
             return;
           }
           else{
             printf("Rotacao Dupla a esquerda\t");
             *R = rotDuplaEsq(*R);
             return;
           }
         }
       }

       if((*R)->id < chave){

         inserechave(&(*R)->dir,chave);

         if(balanceamento(*R) < -1 || balanceamento(*R) > 1){

           if(chave > (*R)->dir->id){
             printf("Rotacao Simples a esquerda\t");

             *R = rotEsq(*R); return;
           }
           else{
             printf("Rotacao Dupla a direita\t");
             *R = rotDuplaDir(*R); return;
           }
         }
       }
       if((*R)->id == chave){
         printf("chave repetida\t");
       }
     }
}

void exibe(node *R,int nivel){
    int i;
    if(R==NULL)
        return;
    if(R->esq!=NULL){

        exibe(R->esq,nivel+1);
    }
    for(i=0;i<nivel;i++)
        printf("\t");
    printf("%d\n",R->id);
    if(R->dir!=NULL){
        exibe(R->dir,nivel+1);
    }

}

void busca(node *R, int chave){
    if(R!=NULL){
        if((R)->id > chave){
            busca(R->esq, chave);
        }
        else{
            if(R->id < chave){
                busca(R->dir, chave);
            }
            else{
                if(R->id == chave){
                    printf("Chave encontrada: %d",R->id);
                }
            }
        }
    }
    else
        printf("Chave nao encontrada...\t");

}
node** sucessor(node*R){
    node** aux = &R;
    if((*aux)->dir != NULL){
        aux = &(*aux)->dir;
        while((*aux)->esq != NULL){
            aux = &(*aux)->esq;
        }
    }
    return aux;
}

node** predecessor(node*R){
    node** aux = &R;
    if((*aux)->esq != NULL){
        aux = &(*aux)->esq;
        while((*aux)->dir != NULL){
            aux = &(*aux)->dir;
        }
    }
    return aux;
}

void removerchave(node**R, int chave){
    node* aux = *R;
    node **aux1;
    node *aux2;
    if(*R != NULL){
        if((*R)->id == chave){
            if((*R)->esq == (*R)->dir){
                printf("\nr = %d\n",chave);
                free(*R);
                *R = NULL;
            }
            else{
                if((*R)->esq != NULL){
                    aux1 = predecessor(*R);
                    aux2 = *aux1;
                    (*aux1) = (*aux1)->esq;
                }
                else{
                    aux1 = sucessor(*R);
                    aux2 = *aux1;
                    (*aux1) = (*aux1)->dir;
                }
                (*R)->id = aux2->id;
                free(aux2);
                aux2 = NULL;
            }
        }
        else{
            if((*R)->id < chave){
                    removerchave(&(*R)->dir,chave);
                    balanceaEsq(&(*R),chave);
            }
            if((*R)->id > chave){
                    removerchave(&(*R)->esq,chave);
                    balanceaDir(&(*R),chave);
            }
        }
  }
  else
    printf("Chave nao enhrada...\t");
}

int hEsq(node*R){
    node* aux = R;
    int h = 0;

    if(aux->esq == NULL)
        return 0;

    else{
        while(aux->esq != NULL){
            aux = aux->esq;
            h = h + 1;

            if(aux->esq == NULL && aux->dir != NULL){
                while(aux->dir != NULL){
                    h = h + 1;
                    aux = aux->dir;
                }
            }
        }
        return h;
    }
}

int hDir(node*R){
    node* aux = R;
    int h = 0;

    if(aux->dir == NULL)
        return 0;
    else{
        while(aux->dir != NULL){
            aux = aux->dir;
            h = h + 1;

            if(aux->dir == NULL && aux->esq != NULL){
                while(aux->esq != NULL){
                    h = h + 1;
                    aux = aux->esq;
                }
            }
        }
        return h;
    }
}


int balanceamento(node*R){
    node* aux = R;
    int bl = 0;
    bl = hDir(aux) - hEsq(aux);
    return bl;
}


node* rotDuplaEsq(node*R){
     node* aux = R;
     aux->esq = rotEsq(aux->esq);
     aux = rotDir(aux);
     return aux;
}


node* rotDuplaDir(node*R){
    node* aux = R;
    aux->dir = rotDir(aux->dir);
    aux = rotEsq(aux);
    return aux;
}


node* rotDir(node*R){
    node* aux = R;
    node* x = aux;
    node* y = aux->esq;
    x->esq = y->dir;
    y->dir = x;
    return y;
}


node* rotEsq(node*R){
    node* aux = R;
    node* x = aux;
    node* y = aux->dir;

    x->dir = y->esq;
    y->esq = x;
    return y;
}

void balanceaDir(node**R, int chave){
    node* aux1 = (*R)->dir;
    node* aux = *R;

    while(aux!= NULL){
        if(balanceamento(aux) < -1 || balanceamento(aux) > 1){
            if(aux1->dir != NULL){
                *R = rotEsq(*R);
                break;
            }
            else{
                *R = rotDuplaDir(*R);
                break;
            }
        }
        aux= aux->dir;
    }
}

void balanceaEsq(node**R, int chave){
    node* aux1 = (*R)->esq;
    node* aux = *R;

    while(aux != NULL){
        if(balanceamento(aux) < -1 || balanceamento(aux) > 1){
            if(aux1->esq == NULL){
                *R = rotDuplaEsq(*R);
                break;
            }
            else{
                *R = rotDir(*R);
                break;
            }
        }
     aux = aux->esq;
    }
}


int carregaArquivo(node**R){
    int chave;
    FILE* arquivo;
    arquivo = fopen("avl.txt","r");
    fseek(arquivo,0,SEEK_END);

    if(ftell(arquivo) == 0)
      return 0;

    fseek(arquivo,0,SEEK_SET);

    if(arquivo == NULL)
        return 0;

    else{
        while(!feof(arquivo)){
            fscanf(arquivo,"%d",&chave);
            inserechave(&(*R),chave);
        }
    }
    fclose(arquivo);
    return 1;
}

void EscreverArquivo(FILE* arquivo, int chave){
    arquivo = fopen("avl.txt", "a");
    fprintf(arquivo," %d",chave);
    fclose(arquivo);
}

void salvaNoArquivo(node*R, FILE* arquivo){
    if(R != NULL){
        salvaNoArquivo(R->esq,arquivo);
        fprintf(arquivo," %d", R->id);
        salvaNoArquivo(R->dir,arquivo);
    }
}


int main(int argc, char* argv[]){
    int op=-1, valor;
    FILE *arquivo;
    node *R=NULL;

    arquivo = fopen("avl.txt", "r");
    if(arquivo != NULL)
    {
        arquivo = fopen("avl.txt", "a");
        fclose(arquivo);
    }
    else{
        printf("problema ao abrir o arquivo");
    }
    carregaArquivo(&R);
    while(op!=0){
        printf("\n===================================================\n===================================================\n");
        printf("\n\t1- Insere numeros");
        printf("\n\t2- Exibir arvore");
        printf("\n\t3- Buscar chave");
        printf("\n\t4- Remover");
        printf("\n\t0- Sair");
        printf("\nOpcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:{
                printf("\nDigite um numero = ");
                scanf("%d",&valor);
                inserechave(&R,valor);
                EscreverArquivo(arquivo,valor);
                exibe(R,0);
                break;
            }
            case 2:{
                exibe(R,0);
                break;
            }
            case 3:{
                printf("\nBuscar a chave: ");
                scanf("%d",&valor);
                busca(R,valor);
                break;
            }

            case 4:{
                printf("\nDigite um numero = ");
                scanf("%d",&valor);
                removerchave(&R,valor);
                FILE* arquivo;
                arquivo = fopen("avl.txt", "w");
                salvaNoArquivo(R,arquivo);
                fclose(arquivo);
                exibe(R,0);
                break;
            }
        }
    }
}
