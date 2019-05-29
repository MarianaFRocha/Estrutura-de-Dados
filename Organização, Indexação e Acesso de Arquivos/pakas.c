#include <stdio.h>
#include <stdlib.h>
int main()
{


    char arq_antigo[] = "digdin.txt";
    char arq_novo[] = "dilma.txt";
    rename(arq_antigo, arq_novo);
    remove("mariana.txt");

    return 0;



}
