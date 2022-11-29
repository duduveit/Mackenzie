#include <stdio.h>

/* Exercicio 1*/ 
int mdcrecursivo(int x, int y){
  if (y<=x &&  x%y == 0) return y;
  else if (x<y) return mdcrecursivo(y, x);
  else return mdcrecursivo(y, x%y);
  }

int mdciterativo(int x, int y){
  int resto = 0;
  while (y!= 0){
    resto = x%y;
    x = y;
    y = resto;
  }
  return x;
}
/*
int main(void) {
  int x = 270;
  int y = 192;
  printf("Resultado do mdc recursivo de %d e %d é igual a %d", x, y, mdcrecursivo(x, y));
  printf("\nResultado do mdc iterativo de %d e %d é igual a %d", x, y, mdciterativo(x, y));
  printf("\nResultado do mdc recursivo de %d e %d é igual a %d", 35, 10, mdcrecursivo(35, 10));
  printf("\nResultado do mdc iterativo de %d e %d é igual a %d", 35, 10, mdciterativo(35, 10));
  printf("\nResultado do mdc recursivo de %d e %d é igual a %d", 10, 15, mdcrecursivo(10, 15));
  printf("\nResultado do mdc iterativo de %d e %d é igual a %d", 10, 15, mdciterativo(10, 15));
  printf("\nResultado do mdc recursivo de %d e %d é igual a %d", 31, 2, mdcrecursivo(31, 2));
  printf("\nResultado do mdc iterativo de %d e %d é igual a %d", 31, 2, mdciterativo(31, 2));
  return 0;
}*/

/* Exercicio 2*/
int mdc(int x, int y){
  if (x==y) return x;
  else if (x%2 == 0 && y%2 == 0) return 2*mdc(x/2, y/2);
  else if (x%2 == 0 && y%2 != 0) return mdc(x/2, y);  
  else if (x%2 != 0 && y%2 == 0) return mdc(x, y/2);
  else if (x%2 != 0 && y%2 != 0 && x > y) return mdc((x-y)/2, y);
  else if (x%2 != 0 && y%2 != 0 && x < y) return mdc(x, (y-x)/2);
}
/*
int main(void) {
  int x = 35;
  int y = 10;

  printf("Resultado do mdc de %d e %d é igual a %d", 270, 192, mdc(270, 192));
  printf("\nResultado do mdc de %d e %d é igual a %d", x, y, mdc(x, y));
  printf("\nResultado do mdc de %d e %d é igual a %d", 10, 15, mdc(10, 15));
  printf("\nResultado do mdc de %d e %d é igual a %d", 31, 2, mdc(31, 2));
  return 0;
}*/

/* Exercicio 3 */
int potenciacao(int x, int n){
  int base = 0;
  if (n==0) return 1;
  else if (n>0 && n%2 == 0) {
    base  = potenciacao(x, (n/2));
    return base * base;
  }
  else if (n>0 && n%2 != 0) {
    base = potenciacao(x, (n-1)/2);
    return x * base * base;
  }
}
/*
int main ()
{
 int x = 2;
 int n = 10;
  
 printf("Resultado de %d elevado a %d é igual a %d", x, n, potenciacao(x, n));
  return 0; 
}*/

/* Exercicio 4 */
int combinacao(int n, int m)
{
  if (m == 0 || m == n) return 1;
  else return combinacao(n-1, m) + combinacao (n-1, m-1);
}
/*
int main()
{
 int n = 10;
 int m = 5;
  
 printf("Resultado da combinacao de %d elementos tomados de %d a %d é igual a %d", n, m, m, combinacao(n, m));
  return 0;  
}*/

/* Exercicio 5 */
int MaxBitonic(int vetor[], int tamanho, int indice){
    if(tamanho == 0) return vetor[indice]; 
    else{
        if(vetor[tamanho - 1] > vetor[indice]) 
            return MaxBitonic(vetor, tamanho - 1, tamanho - 1);
        else
            return MaxBitonic(vetor, tamanho - 1, indice);
    }
}

int main()
{
  int vetor[10] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
  printf("O máximo elemento do vetor é %d", MaxBitonic(vetor, 10, 0));
  return 0;
}




