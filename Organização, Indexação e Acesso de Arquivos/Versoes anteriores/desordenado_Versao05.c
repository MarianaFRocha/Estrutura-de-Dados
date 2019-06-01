
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gerador_de_dados.h"

#define BSIZE 100



typedef struct _aluno {
  int RA;
  char primeiro_nome[20];
  char ultimo_nome[20];
  float nota[3];
} Aluno;

void inserir(int ra, char *primeiro_nome, char *ultimo_nome, float nota[3]);


/*Variaveis globais*/
 int   pos1,pos2,r;
  FILE *fp;
   char buffer[100];



int main()
{

    int n = 700000000;
   // printf("%d",n);

      int   comp_reg;
      int num_reg= TAM_MAX ;/*editar na biblioteca*/
      Aluno a[num_reg], b; //cria o vetor do tamanho de numero de registros


	char linha[200];//Escolher tamanho adequado p linha /PS: nao funciona com ponteiro pois na linha 50 usa-se sizeof(linha)
	char *nome, *ult_nome, *nota1, *nota2, *nota3, *ra_aux;
	FILE *arq;

	int num=0;
       printf("kfsdasdsa");
      geraArquivo();


      /*Captura dados no txt*/
	arq = fopen("dados.txt", "r");

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while((num<num_reg)&&(fgets(linha, sizeof(linha), arq))!=NULL )
        {


            /*Separa dados do txt pelo separador &*/
            ra_aux = (char*)strtok(linha, "&");

            nome = (char*)strtok(NULL, "&");
            ult_nome=(char*)strtok(NULL, "&");
            nota1 =(char*)strtok(NULL, "&");

            nota2 =(char*)strtok(NULL, "&");
            nota3 =(char*)strtok(NULL, "&");
            //printf("%s\n%s\n%s\n%s\n%s", nome, ult_nome, nota1, nota2, nota3);

            /*Converte e copia dados para o vetor de alunos*/
            a[num].RA = atoi(ra_aux);
            strcpy(a[num].primeiro_nome,nome);
            strcpy(a[num].ultimo_nome,ult_nome);
            a[num].nota[0]=atof(nota1);
            a[num].nota[1]=atof(nota2);
            a[num].nota[2]=atof(nota3); //Converte notas de string para float

            //printf("\n--\n%s\n%s\n%.2f\n%.2f\n%.2f", a[num].primeiro_nome, a[num].ultimo_nome, a[num].nota[0], a[num].nota[1], a[num].nota[2]);

            num++; //Atualiza contador
        }

	fclose(arq);


/***************************************************************************/

 /*Criação do arquivo binario*/

  fp = fopen("dados.bin","wb");

  pos1 = 0; //Numero de bytes ocupados no buffer

  memcpy(&(buffer[pos1]),&num_reg,sizeof(int)); //Copia numero de registros para primeira posição do buffer
  //printf("num_reg %d %s\n",num_reg,&(buffer[pos1])); //buffer[pos] varia pq???
  pos1 += sizeof(int); //esta sendo ocuoado o numero de bytes de um inteiro no buffer

  for (r=0; r < num_reg; r++) {
    printf("num_reg %d %d\n",num_reg,(buffer[pos1]));
    comp_reg =  //calcula quantos bytes serao ocupados no buffer
      sizeof(int) + // ra
      strlen(a[r].primeiro_nome)*(sizeof(char)) + // nome1
      1*sizeof(char) + // #
      strlen(a[r].ultimo_nome)*(sizeof(char)) + // nome2
      1*sizeof(char) + // #
      sizeof(float) + sizeof(float) + sizeof(float); // nota1 nota2 nota3
    //printf("--NOVO REG: %d\n",comp_reg);

/* Montando buffer*/

    if (pos1+sizeof(int)>=BSIZE) {         //se a escrita de um int ultrapassar o tamanho do buffer.
      fwrite(buffer,sizeof(char),pos1,fp); //escreve o buffer em memoria e
      pos1 = 0;                            //esvazia buffer
    }
    memcpy(&(buffer[pos1]),&comp_reg,sizeof(int)); //escreve quantos bytes o registro ocupa no buffer
    //printf("comp_reg %s\n",&(buffer[pos1]));
    pos1+=sizeof(int);                             //atualiza numero de bytes ocupados no buffer

    // ra
    if (pos1+sizeof(int)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&a[r].RA,sizeof(int));
    //printf("ra %s\n",&(buffer[pos1]));
    pos1 += sizeof(int);

    // nome1 + #
    if (pos1+sizeof(char)*(strlen(a[r].primeiro_nome)+2)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),a[r].primeiro_nome,sizeof(char)*strlen(a[r].primeiro_nome));
    pos1 += sizeof(char)*strlen(a[r].primeiro_nome);
    buffer[pos1] = '#';
    //printf("nome1 %s\n",&(buffer[pos1-sizeof(char)*strlen(a[r].primeiro_nome)]));
    pos1 += 1*sizeof(char);

    // nome2 + #
    if (pos1+sizeof(char)*(strlen(a[r].ultimo_nome)+2)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),a[r].ultimo_nome,sizeof(char)*strlen(a[r].ultimo_nome));
    pos1 += sizeof(char)*strlen(a[r].ultimo_nome);
    buffer[pos1] = '#';
    //printf("nome2 %s\n",&(buffer[pos1-sizeof(char)*strlen(a[r].ultimo_nome)]));
    pos1 += 1*sizeof(char);

    // nota1
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&a[r].nota[0],sizeof(float));
    //printf("nota1 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);

    // nota2
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&a[r].nota[1],sizeof(float));
    //printf("nota2 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);

    // nota3
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&a[r].nota[2],sizeof(float));
    //printf("nota3 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);

  } // end for

  if (pos1>0) {
    //printf("final %s %d %d\n",buffer,strlen(buffer),pos1);
    fwrite(buffer,sizeof(char),pos1,fp);
  }

  fclose(fp);

/*************************************************************************/

/*
float no[3]={10,17,20};
inserir(07, "leandro", "nogueira", no);

num_reg++;

*/

/* Simulando a leitura do arquivo*/

  fp = fopen("dados.bin","r+");

  pos1 = 0;
  fread(&(buffer[pos1]),sizeof(char),BSIZE,fp);     /* le BSIZE bytes do arquivo para buffer*/

  memcpy(&num_reg,&(buffer[pos1]),sizeof(int));     // le um inteiro dop buffer para a variavel num_reg
  pos1 += sizeof(int);                              // atualiza posicao de leitura
  //printf("num_reg %d\n",num_reg);

  int chave;
//  printf("\nmanda a chave pa nois pesquisah: ");
//  scanf("%d",&chave);

  for (r=0; r < num_reg; r++) {

    // Verifico se posso ler NUM_TOTAL_BYTES
    if (pos1 > BSIZE-4) {
      // fseek(fp, posicao corrente - (offset), a partir do início do arquivo)
      fseek(fp,ftell(fp)-(BSIZE-pos1),SEEK_SET);  //posiciona ponteiro do arquivo no inicio do proximo registro
      fread(buffer,sizeof(char),BSIZE,fp);        //carrega o proximo registro desde o seu inicio
      pos1 = 0;
    }
    // Lendo NUM_TOTAL_BYTES
    memcpy(&comp_reg,&(buffer[pos1]),sizeof(int));
    //printf("NOVO REG: %d\n",comp_reg);


  //  buscar(&b.RA,&chave);


    pos1 += sizeof(int);

    // Verifico se o registro inteiro esta no buffer
    if (comp_reg > BSIZE-pos1) {
      fseek(fp,ftell(fp)-(BSIZE-pos1),SEEK_SET);
      pos1 = 0;
      fread(buffer,sizeof(char),BSIZE,fp);
    }

    /* copia demais campos do registro*/

    // ra
    memcpy(&b.RA,&(buffer[pos1]),sizeof(int));
    pos1 += sizeof(int);
    //printf("ra %d\n",b.RA);

    // nome1
    pos2 = pos1;
    while(buffer[pos2]!='#') pos2 += sizeof(char);
    memcpy(b.primeiro_nome,&(buffer[pos1]),pos2-pos1);
    b.primeiro_nome[pos2-pos1] = '\0';
    //printf("nome1 %d - %d = %d %s \n",pos2,pos1,pos2-pos1,b.primeiro_nome);

    //printf("MARCADOR %c\n",buffer[pos2]);

    // nome2
    pos1 = pos2 + sizeof(char);
    pos2 = pos1;
    while(buffer[pos2]!='#') pos2 += sizeof(char);
    memcpy(b.ultimo_nome,&(buffer[pos1]),pos2-pos1);
    b.ultimo_nome[pos2-pos1] = '\0';
    //printf("nome2 %d - %d = %d %s \n",pos2,pos1,pos2-pos1,b.ultimo_nome);

    //printf("MARCADOR %c\n",buffer[pos2]);
    pos1 = pos2 + sizeof(char);

    // nota1
    memcpy(&b.nota[0],&(buffer[pos1]),sizeof(float));
    pos1 += sizeof(float);
    //printf("nota %.2f\n",b.nota[0]);

    // nota2
    memcpy(&b.nota[1],&(buffer[pos1]),sizeof(float));
    pos1 += sizeof(float);
    //printf("nota %.2f\n",b.nota[1]);

    // nota3
    memcpy(&b.nota[2],&(buffer[pos1]),sizeof(float));
    pos1 += sizeof(float);
    //printf("nota %.2f\n",b.nota[2]);

    /* imprime o registro lido*/
    printf("%d %6d %s %s %.2f %.2f %.2f\n",
	   comp_reg,b.RA,b.primeiro_nome,b.ultimo_nome,b.nota[0],b.nota[1],b.nota[2]);
  }
  fclose(fp);




  return(0);




}

void inserir(int ra, char *primeiro_nome, char *ultimo_nome, float nota[3]){



  pos1 = 0; //Numero de bytes ocupados no buffer
  int a=1;
  memcpy(&(buffer[pos1]),&a,sizeof(int)); //Copia numero de registros para primeira posição do buffer
  //printf("num_reg %d %s\n",num_reg,&(buffer[pos1])); //buffer[pos] varia pq???
  pos1 += sizeof(int); //esta sendo ocuoado o numero de bytes de um inteiro no buffer


    int comp_reg =  //calcula quantos bytes serao ocupados no buffer
      sizeof(int) + // ra
      strlen(primeiro_nome)*(sizeof(char)) + // nome1
      1*sizeof(char) + // #
      strlen(ultimo_nome)*(sizeof(char)) + // nome2
      1*sizeof(char) + // #
      sizeof(float) + sizeof(float) + sizeof(float); // nota1 nota2 nota3
    //printf("--NOVO REG: %d\n",comp_reg);



    if (pos1+sizeof(int)>=BSIZE) {         //se a escrita de um int ultrapassar o tamanho do buffer.
      fwrite(buffer,sizeof(char),pos1,fp); //escreve o buffer em memoria e
      pos1 = 0;                            //esvazia buffer
    }
    memcpy(&(buffer[pos1]),&comp_reg,sizeof(int)); //escreve quantos bytes o registro ocupa no buffer
    pos1+=sizeof(int);                             //atualiza numero de bytes ocupados no buffer

    // ra
    if (pos1+sizeof(int)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&ra,sizeof(int));
    //printf("ra %s\n",&(buffer[pos1]));
    pos1 += sizeof(int);

    // nome1 + #
    if (pos1+sizeof(char)*(strlen(primeiro_nome)+2)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),primeiro_nome,sizeof(char)*strlen(primeiro_nome));
    pos1 += sizeof(char)*strlen(primeiro_nome);
    buffer[pos1] = '#';
    //printf("nome1 %s\n",&(buffer[pos1-sizeof(char)*strlen(a[r].primeiro_nome)]));
    pos1 += 1*sizeof(char);

    // nome2 + #
    if (pos1+sizeof(char)*(strlen(ultimo_nome)+2)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),ultimo_nome,sizeof(char)*strlen(ultimo_nome));
    pos1 += sizeof(char)*strlen(ultimo_nome);
    buffer[pos1] = '#';
    //printf("nome2 %s\n",&(buffer[pos1-sizeof(char)*strlen(a[r].ultimo_nome)]));
    pos1 += 1*sizeof(char);

    // nota1
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&nota[0],sizeof(float));
    //printf("nota1 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);

    // nota2
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&nota[1],sizeof(float));
    //printf("nota2 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);

    // nota3
    if (pos1+sizeof(float)>=BSIZE) {
      fwrite(buffer,sizeof(char),pos1,fp);
      pos1 = 0;
    }
    memcpy(&(buffer[pos1]),&nota[2],sizeof(float));
    //printf("nota3 %s\n",&(buffer[pos1]));
    pos1 += sizeof(float);


   /*Adicionar no arquivo*/ /*ESTA CRIANDO OURO ARQUIVO!*/
   fp = fopen("dados.bin","wb");
    /*printf("ant %p",fp);
    fseek(fp, 0, SEEK_END);
    printf("dent %p",fp);

    printf("%s\n", buffer);
    //fwrite(buffer,sizeof(char),pos1,fp);
    printf("p>%d\n", pos1);*/
}
