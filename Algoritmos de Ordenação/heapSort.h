

void subir (int *heap, int i)
{
    if (i > 0)
    {
        if (heap[i] > heap[i/2])
        {
            trocaPosicao (&heap[i], &heap[i/2]);
            subir (heap, i/2);
        }
    }
}

int maiorFilho (int tam, int *heap, int i)
{
    int maior = 2*i;
    if (2*i + 1 <= tam)
        if (heap[2*i + 1] >= heap[2*i])
            maior = 2*i + 1;
    return maior;
}

void descer (int tam, int *heap, int i)
{
    if (i <= tam/2)
    {
        int maior = maiorFilho (tam, heap, i);
        if (heap[i] < heap[maior])
        {
            trocaPosicao (&heap[i], &heap[maior]);
            descer (tam, heap, maior);
        }
    }
}

int insereCh (int tam, int *cap, int x, int *heap)
{
    int erro = 0;
    if (tam == *cap)
    {
        *cap *= 2;
        int *teste = (int *) realloc (heap, *cap * sizeof (int));
        if (teste)
            heap = teste;
        else
            erro = 1;
    }
    if (!erro)
    {
        tam++;
        heap[tam] = x;
        subir (heap, tam);
    }
    else
        printf ("\nERRO!\n");
    return tam;
}


int removeMaior (int tam, int *heap)
{
    if (tam)
    {
        heap[0] = heap[tam];
        tam--;
        descer (tam, heap, 0);
    }
    else
        printf ("\nHEAP VAZIO!\n");
    return tam;
}

void geraHeapS (int tam, int *vet) ///USANDO O ALGORITMO SUBIR.
{
    int i;
    for (i = 2; i <= tam; i++)
        subir (vet, i);
}

void geraHeapD (int tam, int *vet) ///USANDO O ALGORITMO DESCER. MAIS EFICIENTE: MENOS COMPARAÇÕES!
{
    int i;
    for (i = tam/2; i >= 0; i--)
        descer (tam,vet, i);
}

void heapSort (int tam, int *vet)
{
    geraHeapD (tam, vet);
    while (tam > 0)
    {
        trocaPosicao (&vet[0], &vet[tam]);
        tam--;
        descer (tam, vet, 0);
    }
}

void imprimeHeap (int tam, int *heap)
{
    int i;
    printf ("Heap =");
    for (i = 0; i <= tam; i++)
        printf (" %d;", heap[i]);
}
