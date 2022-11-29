#include <stdio.h>

/* Exercicio 1 - Escreva uma função recursiva que apresente números binários de tamanho n.*/

void print1(int *vetor, int n){
  for(int i = 0; i < n; i++){
    printf(" %d ", vetor[i]);
  }
  printf("\n");
}

int permuta1(int* binario, int n, int i, int n_count, int m_count){
  if (i == n) print1(binario, n);
  else {
    binario[i] = 0;
    permuta1(binario, n, i+1, n_count++, m_count);
    binario[i] = 1;
    permuta1(binario, n, i+1, n_count, m_count++);
  }
  return 0;
}
/*
int main() {
  int quantidade = 4;
  int binario[2] = {0};
  permuta1(binario, quantidade, 0);
  return 0;
}*/

//Exercicio 2 - Considere uma partida de futebol entre duas equipes A × B, cujo placar final é m × n, em que m e n são número de gols marcados por A e B, respectivamente. Escreva um algoritmo recursivo que imprima todas as possíveis sucessões de gols marcados. Por exemplo, para um placar final de 3 × 1, as possíveis sucessões de gols são “AAAB”, “AABA”, “ABAA” e “BAAA”


int print(char *r, int tam){
  for(int i = 0; i < tam; i++)
    printf(" %c ", r[i]);
  printf("\n");
  return 0;
} 

int jogo(char* placar, int golsA, int golsB, int i, int a_count, int b_count){
  if (i==golsA+golsB)
    print(placar, i);
  else{
    if(a_count < golsA){
      placar[i] = 'A';
      jogo(placar, golsA, golsB, i+1, a_count+1, b_count);
    }
    if (b_count < golsB){
      placar[i] = 'B';
      jogo(placar, golsA, golsB, i+1, a_count, b_count++);
    }
  }
}
/*
int main(){
  int m = 3;
  int n = 2;
  int total = m+n;
  char vetor[total];
  jogo(vetor, m, n, 0, 0, 0);
}
*/