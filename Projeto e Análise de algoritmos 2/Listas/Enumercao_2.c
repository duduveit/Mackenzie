#include <stdio.h>


/* Exercicio 1*/
int consecutivo(int *r, int tamanho){
  int flag = 0;
  int m, i;
  for (m = 1; flag == 0 && m <= tamanho/2; m++) {
    for (i = 0; flag == 0 && i <= tamanho-2*m; i++) {
      flag = 1;
      for (int j = 0; flag == 1 && j < m; j++)
        if (r[i+j] != r[i+m+j])
          flag = 0;
    }
  }
  if (flag) {
    printf("i = %d e m = %d.\n", i-1, m-1);
  }
  else
    printf("Nao, nao existem dois segmentos iguais consecutivos.\n");
  return 0;
}
/*
int main() {
  int r[8] = {1, 2, 3, 1, 2, 3, 4, 5};
  consecutivo(r, 8);
  return 0;
}*/

/*Exercicio 2*/
int somamaxima(int *r, int tamanho){
  int i, k, j, soma;
  int m, n, somaMax = 0;
  for(i=1; i < tamanho; ++i){
      for(j=0; j < tamanho;++j){
          soma=0;
          for(k=0; k<i ;++k){
              if(j+k > tamanho-1) {break;}
              soma += r[j+k];
          }
          if(soma > somaMax){
              somaMax = soma;
              m = j;
              n = i;
          }
      }
  }
  for(j=0;j<n;++j)
  {
      printf("%d,",r[m+j]);
  }
  printf("\nSoma do segmento de soma maxima: %d", somaMax);
  return 0;
}
/*
int main(){
  int r[12] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
  somamaxima(r, 12);
  return 0;
}*/

/* Exercicio 3*/
int uniao(int *r, int *s, int m, int n) {
  int t[m + n];
  int num, i, j, k;
  j = i = k = 0;

  while (i < m && j < n) {
    if (r[i] < s[j]) {
      num = r[i];
      i++;} 
    else {
      num = s[j];
      j++;}

    if (k == 0 || t[k - 1] != num) {
      t[k] = num;
      k++;}
    }
  while (i < m) {
    t[k] = r[i];
    i++;
    k++;}
  while (j < n) {
    t[k] = s[j];
    j++;
    k++;}

  printf("A sequencia final ordenada é: \n");
  for (i = 0; i < k; i++)
    printf("%d\t", t[i]);
  printf("\n");
  return 0;
}

int main() {
  int r[5] = {1, 3, 5, 7, 9};
  int s[4] = {2, 4, 6, 8};
  uniao(r, s, 5, 4);
  return 0;
}
*/