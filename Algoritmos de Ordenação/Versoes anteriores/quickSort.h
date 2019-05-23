#include <stdio.h>
//#include "trocaPosicao.h"

//Chamem usando:
    //quickSort(vetor,0,tamanhoVetor-1); (vetor, posicaoinicaldovetor,tamanhovetorcomeçandocom0)
    //É um pouco mais complexo fazer retornar o vetor por conta da recursão, então deixei como void
void quickSort(int *c, int p, int r){

    if (p<r){
        int q=partition(c,p, r);
            quickSort(c, p, q-1);
            quickSort(c, q+1,r);
        }
    }



int partition(int *c, int p, int r){
    int x = c[r];
    int i = p-1;
    int j;
    for (j=p; j<r;j++){
        if (c[j]<=x){
            i = i +1;
            trocaPosicao(&c[i],&c[j]);
        }
    }
       trocaPosicao (&c[i+1],&c[r]);
    return i+1;
}
