// Cenário 1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int SaldoA=0;
int SaldoB=0;

void *Thread1(void *args){
    int valor=*((int *)args);
    printf("\n Realizando a primeira tranferência");
    int SaldoB_local=SaldoB-valor;
    int SaldoA_local=SaldoA+valor;
    sleep(2);
    SaldoA=SaldoA_local;
    SaldoB=SaldoB_local;
    return(NULL);
}

void *Thread2(void *args){
    int valor=*((int *)args);
    printf("\n Realizando a segunda tranferência");
    int SaldoA_local=SaldoA-valor;
    int SaldoB_local=SaldoB+valor;
    sleep(2);
    SaldoA=SaldoA_local;
    SaldoB=SaldoB_local;
    return(NULL);
}

int leituraClienteA (){
  FILE *entrada;
  int SaldoA;
  entrada = fopen ("SaldoA.txt", "r");
  if(entrada == NULL){
    printf("Problemas na leitura do arquivo da conta A.\n");
    return 0;
  }
  else{
     fscanf(entrada,"%d", &SaldoA);
  }
  return SaldoA;
}

int leituraClienteB (){
  FILE *entrada;
  int SaldoB;
  entrada = fopen ("SaldoB.txt", "r");
  if(entrada == NULL){
    printf("Problemas na leitura do arquivo da conta A.\n");
    return 0;
  }
  else{
     fscanf(entrada,"%d", &SaldoB);
  }
  return SaldoB;
}

int main()
{
    SaldoB=leituraClienteB();
    SaldoA=leituraClienteA();
    pthread_t thread[2];
    int ValorA;
    int ValorB;
    printf("Digite o valor de transferencia de B para A: ");
    scanf("%d",&ValorA);
    printf("Digite o valor de transferencia de A para B: ");
    scanf("%d",&ValorB);
    pthread_create(&thread[0],NULL,Thread1,(void *)&ValorA);
    pthread_create(&thread[1],NULL,Thread2,(void *)&ValorB);
    sleep(5);
    FILE *A;
    A = fopen ("SaldoA.txt", "w");
    FILE *B;
    B = fopen ("SaldoB.txt", "w");
    printf("\n SaldoA %d",SaldoA);
    printf("\n SaldoB %d",SaldoB);
    fprintf(A,"%d",SaldoA);
    fprintf(B,"%d",SaldoB);
    fclose(A);
    fclose(B);
    return 0;
}