/*
Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
04G
*/

#include <stdio.h>

#define infinity 99

int** leitura(int* destino, int* qntEsquinas){
  //Abertura do arquivo para leitura
  FILE  *fp;
  fp = fopen("Bombeiro.txt", "r");
  if(fp == NULL){
    printf("Erro abrindo o arq: Bombeiro.txt");
    exit(1);
  }
  //1º e 2º linha do arquivo representa o destino e as quantidades de esquina
  fscanf(fp, "%d", destino); 
  fscanf(fp, "%d", qntEsquinas);

  int i, j;
  //Alocar matriz quadrática da quantidade de esquinas
  int **mat = malloc(*qntEsquinas * sizeof(int*));

  for(i = 0; i < *qntEsquinas; i++)
      mat[i] = malloc(*qntEsquinas * sizeof(int));
  //Atribui valor infinito para todos os indices da matriz
  for(i = 0; i < *qntEsquinas; i++){
      for(j = 0; j < *qntEsquinas; j++)
          mat[i][j] = infinity;
  }
  //Mapeia as esquinas adjascentes com o tempo entre elas
  int Lin = 1, Col, Val;
  while(Lin != 0){
      fscanf(fp, "%d\t%d\t%d", &Lin, &Col, &Val);
      if (Lin == 0) break;
      mat[Lin-1][Col-1] = Val;
    }

  fclose(fp);
  
  return mat;
}

int tempoMaisRapido(int **mapa, int qntEsquinas, int destino, int *e, int *vetor, int *rota){
  //Vetor auxiliar com as esquinas
  int i;  
  //Vetor auxiliar com as esquinas
  for (i = 0; i < qntEsquinas; i++){
    e[i] = i;
    //Esquinas que vão para elas mesmas recebe tempo igual a 0
    mapa[i][i] = 0;
  }
  //Remove o 1º elemento do vetor
  e[0] = 99;
  //acessar -> m = rota inicial, n = esquina
  int m = 0;
  int j, menor, count = 0, indice = 0, tempo = 0;
  //Enquanto E não estiver vazio
  
  while (count != qntEsquinas){
    menor = 99;
    //Encontra a esquina de menor valor em E
    for (j =  0; j < qntEsquinas; j++){
      if(mapa[m][j] < menor && m!=j && e[i] != 99){
        menor = mapa[m][j];
        indice = j;
      }
    }
    //Remove a esquina de e
    e[indice] = 99;
    //soma o tempo
    tempo += mapa[m][indice];
    
    printf("rota: %d -> %d = %d, tempo = %d\n", m+1, indice+1, mapa[m][indice], tempo);
    if(indice+1 == destino) break;
    //Armazena a rota
    rota[count] = m;
    //calcula na proxima iteracao o menor tempo a partir da atual esquina
    m = indice;
    count++;
  }
  
  return tempo;
}


void clear(int e, int *vetor, int *rota, int **mapa, int qntEsquinas){
  for (int i = 0; i<qntEsquinas; i++) free(mapa[i]);
  free(mapa);
  free(e);
  free(vetor);
  free(rota);  
}

int main(){
  int destino, qntEsquinas, i, j;
  int *e = malloc(qntEsquinas * sizeof(int*));
  int *vetor = malloc(qntEsquinas * sizeof(int*));
  int *rota = malloc(qntEsquinas * sizeof(int*));
  int** mapa = leitura(&destino, &qntEsquinas);
  rota[0] = 0;

  int tempo = tempoMaisRapido(mapa, qntEsquinas, destino, e, vetor, rota);
  printf("\nRota até a esquina #%d:", destino);
  for(i = 0; i<qntEsquinas; i++){
    printf(" %d ", rota[i]+1);
  }
  
  printf("\n\nTempo calculado para a rota = %d", tempo);
  clear(e, vetor, rota, mapa, qntEsquinas);
  return 0;
}
  