#include <stdio.h>

// Exercicio 1 -  Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. O seu programa deve a relação de notas necessárias, por exemplo para o valor 576.73 teríamos:

int algoritmo(int total, float* vetor){
  int maior, resto;
  int i = 0;
  int quantidade = 12;
  int S[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  while (i < quantidade){
    maior = vetor[i];
    resto = total%maior;
    if (resto == 0){
      S[i] = total/maior;
    }
    i++;
  }
  printf("%d", i);
  for (int j = 0; j < i;j++){
    printf(" %d ", S[j]);
  }
  return 0;
} 

void print(float *vetor, int n){
  for(int i = 0; i < n; i++){
    printf(" %d ", vetor[i]);
  }
  printf("\n");
}

int main(){
  float total;
  int quantidade = 12;
  printf("Digite um valor com duas casas decimais: ");
  scanf("%f", &total);
  float valores[12]= {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.1, 0.05, 0.01};

  //algoritmo(total, valores);
  
  return 0;
}