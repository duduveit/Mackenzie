// Eduardo Veit Ferrão - 32150180
// Leonardo Biagiotti Beloti - 32160062
// 4G - Projeto e Análise de alogitmos
// Professor - Leonardo Massayuki Takuno

#include <stdio.h>
#include <stdlib.h>

#define Tamanho 500

int* leitura(int* r, int* duracao, int* quantidade){
  FILE  *fp;
  fp = fopen("tape.in", "r");
  fscanf(fp, "%d %d", duracao, quantidade);

  int minutos, segundos, i = 0;
  while(i <= *quantidade){
    fscanf(fp, "%d\t%d", &minutos, &segundos);
    r[i] = minutos*60 + segundos;
    i++;
  }
  fclose(fp);
  return r;
}

int soma(int *r,int inicio, int fim){
  int soma = 0;
  for(int i = inicio; i<fim;i++)
    soma = soma + r[i];
  return soma;
}

int alocarGravacao(int* r, int tamanho, int duracao){
  for(int i = 0; i<tamanho; i++){
    if (soma(r, 0, i) < duracao && soma (r,i, tamanho) < duracao)
      return i;
  }
  return 0;
}

void swap(int *r, int i, int j){
	int aux = r[i];
	r[i] = r[j];
	r[j] = aux;
}

int permuta(int *r, int inicio, int tamanho, int duracao){
	if(inicio == tamanho){
    int terminoA = alocarGravacao(r,tamanho,duracao);
    if(terminoA != 0)
      return terminoA;    
  }
  else{
		for(int j = inicio; j < tamanho; j++){
			swap(r, inicio, j);
			int termino = permuta(r, inicio + 1, tamanho, duracao);  
      if (termino != 0) return termino;
			swap(r, inicio, j);
		}
	}
  return 0;
}

void imprimir(int *r, int inicio, int quantidade){
  for(int i = inicio; i < quantidade;i++){
    int min = r[i] / 60;
    printf("%d minutos %d segundos\n", min, r[i]-min*60);
  }
}

int main(){
  int vetor[Tamanho], duracao, quantidade;
  int *musicas = leitura(vetor, &duracao,&quantidade); 
  if(soma(musicas, 0, quantidade) >= duracao*60)
    printf("Impossivel gravar as musicas nessa fita"); 
  else{
    int terminoA = permuta(musicas,0, quantidade, duracao*60/2);
    if (terminoA != 0) {
      printf("\nLado A:\n");
      imprimir(musicas, 0, terminoA);
      printf("\nLado B:\n");
      imprimir(musicas, terminoA, quantidade);
    }
  }
  return 0;
} 