#include <stdio.h>
#include <stdbool.h> 
/* Exercicio 1*/
bool Lexico(int *r, int *s, int tamR, int tamS) 
{
  for (int i = 0; i < tamR; i++)
    if (r[i] < s[i]) 
      return 1;
    else if (r[i] > s[i]) return 0;
  if (tamR < tamS)
    return 1;
  return 0;
}
/*
int main ()
{
  int r[5] = {4, 1, 4, 5, 6};
  int s[6] = {4, 1, 2, 5, 6, 9};
  bool resultado = Lexico(r, s, 5, 6);
  printf("%d \n", resultado);
  return 0;
}*/

/* Exercicio 2 */
int Lexico(int *r, int *s, int tamR, int tamS)
{
  for (int i = 0; i < tamR; i++)
    if (r[i] < s[i]) 
      return 1;
    else if (r[i] > s[i]) return -1;
  if (tamR < tamS)
    return 1;
  else return 0;
}
/*
int main()
{
  int r[5] = {4, 1, 2, 5, 10};
  int s[5] = {4, 1, 2, 5, 9};
  int resultado = Lexico(r, s, 5, 5);
  printf("%d \n", resultado);
  return 0;
}*/

/*Exercicio 3*/
bool Subsequencia(int *r, int *s, int tamR, int tamS)
{
  if (tamR > tamS) 
    return 0;
  int indice = 0;
  for (int i = 0; i < tamS; i++)
    if(r[indice] == s[i]) 
      indice ++;
    if (indice == tamR) 
      return 1;
  return 0;
}
/*
int main()
{
  int r[4] = {2, 3, 5, 8};
  int s[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  bool resultado = Subsequencia(r, s, 4, 8);
  printf("%d \n", resultado);
  return 0;
}*/

/*Exercicio 4*/

bool segmento(int *r, int *s, int tamR, int tamS){
  if (tamR > tamS) return 0;
  int indice = 0;
  for (int i=0; i<tamS; i++) {
    if (r[indice] == s[i]) {
      indice = i;
      break;} }
  int count = 0;
  int j = 0;
  while (count < tamR)  {
      if (r[j] == s[indice]){
        count++;
        j++;
        indice++;}
      else
        break;}
  if (count == tamR) return 1;
  return 0;
}
/*
int main()
{
  int r[3] = {4, 5, 6};
  int s[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  bool resultado = segmento(r, s, 3, 8);
  printf("%d \n", resultado);
  return 0;
}

Exercicio 5*/

int quantidade(int *r, int tamanho)
{
 int elemento = r[0];
 int count = 0;
 for(int i = 0; i<tamanho; i++){
   if (elemento != r[i+1])
     count++;
     elemento = r[i+1];
   }
  count++;
  return count;
}
/*
int main (){
  int r[11] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
  int resultado = quantidade(r, 11);
  printf("%d \n", resultado);
  return 0;
}

Exercicio 6*/ 
int comprimento(int *r, int tamanho)
{
  int maior = 1;
  int comprimento = 1;
  for(int i = 0; i<tamanho-1; i++){
    if(r[i] < r[i+1])
      comprimento++;
    else{
      if (maior < comprimento){
        maior = comprimento;}
      comprimento = 1;
    }
  }  
  return maior;
}
/*
int main()
{
  int r[9] = {5, 10, 3, 2, 4, 7, 9, 8, 5};
  int resultado = comprimento(r, 9);
  printf("%d \n", resultado);
  return 0;
}
*/