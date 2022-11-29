// Cenário 2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int SaldoA=0;
int SaldoB=0;
pthread_mutex_t m1,m2;

void *Thread1(void *args){
  pthread_mutex_lock(&m1);
  int valor=*((int *)args);
  printf("\n Realizando tranferência de A para B");
  sleep(1);
  pthread_mutex_lock(&m2);
  sleep(1);
  int SaldoB_local=SaldoB-valor;
  int SaldoA_local=SaldoA+valor;
  pthread_mutex_unlock(&m2);
  SaldoA=SaldoA_local;
  SaldoB=SaldoB_local;
  pthread_mutex_unlock(&m1);
  pthread_exit(NULL);
  return (NULL);
}

void *Thread2(void *args){
  pthread_mutex_lock(&m2);
  int valor=*((int *)args);
  printf("\n Realizando tranferência de B para B");
  sleep(1);
  pthread_mutex_lock(&m1);
  sleep(1);
  int SaldoA_local=SaldoA-valor;
  int SaldoB_local=SaldoB+valor;
  pthread_mutex_unlock(&m1);
  SaldoA=SaldoA_local;
  SaldoB=SaldoB_local;
  pthread_mutex_unlock(&m2);
  pthread_exit(NULL);
  return(NULL);
}

int leituraClienteA (){
  FILE *A;
  int SaldoA;
  A = fopen ("SaldoA.txt", "r");
  if(A == NULL){
    printf("Problemas na leitura do arquivo da conta A.\n");
    return 0;
  }
  else{
     fscanf(A,"%d", &SaldoA);
  }
  return SaldoA;
}

int leituraClienteB (){
  FILE *B;
  int SaldoB;
  B = fopen ("SaldoB.txt", "r");
  if(B == NULL){
    printf("Problemas na leitura do arquivo da conta A.\n");
    return 0;
  }
  else{
     fscanf(B,"%d", &SaldoB);
  }
  return SaldoB;
}

int main()
{
    SaldoB=leituraClienteB();
    SaldoA=leituraClienteA();
    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);
    pthread_t thread[2];
    int ValorA;
    int ValorB;
    printf("Digite o valor de transferencia de B para A: ");
    scanf("%d",&ValorA);
    printf("Digite o valor de transferencia de A para B: ");
    scanf("%d",&ValorB);
    pthread_create(&thread[0],NULL,Thread1,(void *)&ValorA);
    pthread_create(&thread[1],NULL,Thread2,(void *)&ValorB);
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    sleep(1);
    printf("\n SaldoA %d",SaldoA);
    printf("\n SaldoB %d",SaldoB);
    FILE *A;
    A = fopen ("SaldoA.txt", "w");
    FILE *B;
    B = fopen ("SaldoB.txt", "w");
    fprintf(A,"%d",SaldoA);
    fprintf(B,"%d",SaldoB);
    fclose(A);
    fclose(B);
    return 0;
}