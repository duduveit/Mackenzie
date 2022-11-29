#include <stdio.h>
#include <stdlib.h>
/* Problema da seleção de atividades */

// 1º Tentativa -- começam primeiro - (0,6), (8,11), (12,14)

int ActivitySelectorA(int inicio[], int fim[], int n){
  printf("Seleção de atividades - Ordenação por começar primeiro\n\n");
  int i = 0;
  printf("Atividade %d\n", i+1);
  printf("INICIO = %d\t", inicio[i]);
  printf("Fim = %d\t", fim[i]);

  for (int j = 1; j < n; j++){
    if (inicio[j] > fim[i]){
      printf("\n\nAtividade %d", j+1);
      printf("\nINICIO = %d\t", inicio[j]);
      printf("Fim = %d\t", fim[j]);
      i = j;
    }
  }
  return 0;
}

//2º Tentativa -- demoram menos tempo - (3,5), (8,11), (12,14)
int ActivitySelectorB(int inicio[], int fim[], int n){
  printf("Seleção de atividades - Ordenação por frequência\n\n");
  int i = 0;
  printf("Atividade %d\n", i+1);
  printf("INICIO = %d\t", inicio[i]);
  printf("Fim = %d\t", fim[i]);

  for (int j = 1; j < n; j++){
    if (inicio[j] > fim[i]){
      printf("\n\nAtividade %d", j+1);
      printf("\nINICIO = %d\t", inicio[j]);
      printf("Fim = %d\t", fim[j]);
      i = j;
    }
  }
  return 0;
}

//3º Tentativa -- terminam primeiro - (1,4), (5,7), (8,11), (12,14)

int ActivitySelectorC(int inicio[], int fim[], int n){
  printf("Seleção de atividades - Ordenação por terminar primeiro\n\n");
  int i = 0;
  printf("Atividade %d\n", i+1);
  printf("INICIO = %d\t", inicio[i]);
  printf("Fim = %d\t", fim[i]);

  for (int j = 1; j < n; j++){
    if (inicio[j] >= fim[i]){
      printf("\n\nAtividade %d", j+1);
      printf("\nINICIO = %d\t", inicio[j]);
      printf("Fim = %d\t", fim[j]);
      i = j;
    }
  }
  return 0;
}
  
// Main

int main() {
  int inicioA[] = {0, 1, 2, 3, 3, 5, 5, 6, 8, 8, 12};
  int fimA[] = {6, 4, 13, 5, 8, 7, 9, 10, 11, 12, 14};

  int inicioB[] = {3, 5, 12, 1, 8, 5, 6, 8, 3, 0, 2};
  int fimB[] = {5, 7, 14, 4, 11, 9, 10, 12, 8, 6, 13};

  int inicioC[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  int fimC[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  
  int quantidade = sizeof(inicioA)/sizeof(inicioA[0]);

  ActivitySelectorA(inicioA, fimA, quantidade);
  ActivitySelectorB(inicioB, fimB, quantidade);
  ActivitySelectorC(inicioC, fimC, quantidade);
  return 0;
}