#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 100

#define TAM_REG 150 // EDITE AQUI ***************************

typedef struct _aluno {
  int RA;
  char primeiro_nome[20];
  char ultimo_nome[20];
  float nota[3];
} Aluno;




void geraArquivo(){

  //char url[]="dados.txt", linha[100];
  //char *nome, *ult_nome, *nota1, *nota2, *nota3;
  FILE *arq;
    //char copia[100];

  long int num;

  arq = fopen("dados.txt", "w");
  for(num=0;num<TAM_REG;num++){
    fprintf(arq, "%ld Leandro&Nogueira&10&10&10.4\n",num);  
  }

  fclose(arq);
  
}


int main()
{
    int n = 700000000;
   // printf("%d",n);

      int   comp_reg;
      int num_reg=TAM_REG; // NAO EDITE AQUI //numero de registros é importante /*EDITE AQUI*/
      Aluno a[num_reg], b; //cria o vetor do tamanho de numero de registros
      char buffer[BSIZE];




//Captura nomes no txt
	char url[]="dados.txt",
	     linha[100];
	char *nome, *ult_nome, *nota1, *nota2, *nota3;
	FILE *arq;
        char copia[100];

	int num=0;
  geraArquivo();
	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while((num<num_reg)&&(fgets(linha, sizeof(linha), arq))!=NULL )
		{

			//strcpy(copia,linha);
			nome = (char*)strtok(linha, "&");
			ult_nome=(char*)strtok(NULL, "&");
			nota1 =(char*)strtok(NULL, "&");
			nota2 =(char*)strtok(NULL, "&");
			nota3 =(char*)strtok(NULL, "&");
			//printf("%s\n%s\n%s\n%s\n%s", nome, ult_nome, nota1, nota2, nota3);


			a[num].RA = rand()%num_reg*10; //DEVE SER ALEATÓRIO
  			strcpy(a[num].primeiro_nome,nome);
 			strcpy(a[num].ultimo_nome,ult_nome);
 			a[num].nota[0]=atof(nota1);
			a[num].nota[1]=atof(nota2);
  			a[num].nota[2]=atof(nota3); //Converte notas de string p float

			//printf("\n--\n%s\n%s\n%.2f\n%.2f\n%.2f", a[num].primeiro_nome, a[num].ultimo_nome, a[num].nota[0], a[num].nota[1], a[num].nota[2]);

                                       num++;
		}


	fclose(arq);





  int   pos1,pos2,r;
  FILE *fp;

  fp = fopen("dados.bin","wb");





  /* cria 1o registro
  a[0].RA = 11111;
  sprintf(a[0].primeiro_nome,"Paula");
  sprintf(a[0].ultimo_nome,"Sinval");
  a[0].nota[0]=8.9;
  a[0].nota[1]=7.5;
  a[0].nota[2]=4.5;*/


  pos1 = 0; //numero de bytes ocupados no buffer

  memcpy(&(buffer[pos1]),&num_reg,sizeof(int));
  //printf("num_reg %d %s\n",num_reg,&(buffer[pos1]));
  pos1 += sizeof(int); //esta sendo ocuoado o numero de bytes de um inteiro no buffer

  for (r=0; r < num_reg; r++) {

    comp_reg =  //calcula quantos bytes serao ocupados no buffer
      sizeof(int) + // ra
      strlen(a[r].primeiro_nome)*(sizeof(char)) + // nome1
      1*sizeof(char) + // #
      strlen(a[r].ultimo_nome)*(sizeof(char)) + // nome2
      1*sizeof(char) + // #
      sizeof(float) + sizeof(float) + sizeof(float); // nota1 nota2 nota3
    //printf("--NOVO REG: %d\n",comp_reg);
/* Montando buffer*/

    // num total de bytes
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

//-----/---/----/---------/-----

/* Simulando a leitura do arquivo*/

  fp = fopen("dados.bin","r+");

  pos1 = 0;
  fread(&(buffer[pos1]),sizeof(char),BSIZE,fp);     /* le BSIZE bytes do arquivo para buffer*/

  memcpy(&num_reg,&(buffer[pos1]),sizeof(int));     // le um inteiro dop buffer para a variavel num_reg
  pos1 += sizeof(int);                              // atualiza posicao de leitura
  //printf("num_reg %d\n",num_reg);

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


