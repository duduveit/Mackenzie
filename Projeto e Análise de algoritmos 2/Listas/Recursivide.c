#include <stdio.h>

/* Exercicio 4*/
int potencia(int a, int n){
  if (n==0) return 1;
  else return a * potencia(a, n-1);
}

/* Exercicio 5*/
int MaxElemento(int array[], int tamanho, int indice)
{
  if (tamanho == 0) return array[indice];
  else
  {
    if (array[tamanho-1] > array[indice]) return MaxElemento(array, tamanho-1, tamanho-1);
    else return MaxElemento(array, tamanho-1, indice);
  }
}

int MenElemento(int array[], int tamanho, int indice)
{
  if (tamanho == 0) 
    return array[indice];
  else
  {
    if (array[tamanho] < array[indice]) 
      return MenElemento(array, tamanho-1, tamanho-1);
    else
      return MenElemento(array, tamanho-1, indice);
  }
}

int Soma (int array[], int tamanho)
{
  if (tamanho == 0) return 0;
  else
    return array[tamanho-1] + Soma(array, tamanho -1);
}

int SomaPares(int array[], int tamanho)
{
  if (tamanho == 0) return 0;
  else{
    if (array[tamanho-1] % 2 == 0) return array[tamanho-1] + SomaPares(array, tamanho -1); 
    else return SomaPares(array, tamanho -1);}
}

int Buscalinear (int array[], int tamanho, int elemento)
{
  if (tamanho == 0) return 0;
  else {
   if (array[tamanho-1] == elemento) return tamanho-1;
   else return Buscalinear(array, tamanho-1, elemento);
  } 
}

/* Exercicio 6 */
int produto(int a, int b)
{
  if (b == 1) return a;
  else
  {
    return a + produto(a, b-1);
  }
}
int main()
{
  printf("O produto de %d e %d é %d", 4, 5, produto(4, 5));
}