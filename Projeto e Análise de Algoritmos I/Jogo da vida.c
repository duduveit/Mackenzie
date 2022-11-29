#include <stdio.h>
#include <stdlib.h>

void ImprimeMatriz(int **mat, int LIN, int COL)
{ 
  printf ("\nMatriz: \n");
  for(int i = 0; i < LIN-1; i++){
    if (i!=0)
    {
      for(int j = 0; j < COL-1; j++)
      {
        if (j != 0) 
        {
          printf("%2d ", mat[i][j]);
        }
      }
    }
    printf("\n");
  }
  /*
  printf ("\nMatriz: \n");
  for(int i = 0; i < LIN; i++)
  {
    for(int j = 0; j < COL; j++)
      printf("%2d ", mat[i][j]);
    printf("\n");
  }*/
}

void entradacelula(int **mat)
{
  int linha, coluna = 0;
  printf("\nInforme as células vivas: \n");
  int stoper = 0;
  while (stoper == 0)
    {
      printf("\nlinha: ");
      scanf("%i", &linha);
      if (linha < 0)
        break;
      printf("coluna: ");
      scanf("%i", &coluna);
      mat[linha][coluna] = 1;
    }
}

int entradalinha()
{
  int LIN;
  printf("Digite o número de linhas da matriz: ");
  scanf("%i", &LIN);
  LIN++;
  LIN++;
  return LIN;
}

int entradacoluna()
{
  int COL;
  printf("Digite o número de colunas da matriz: ");
  scanf("%i", &COL);
  COL++;
  COL++;
  return COL; 
}

int vizinhanca(int **mat, int linha, int coluna)
{
  int count = 0;
  if (mat[linha-1][coluna-1] == 1) ++count;
  if (mat[linha-1][coluna] == 1) ++count;
  if (mat[linha-1][coluna+1] == 1) ++count;
  if (mat[linha][coluna-1] == 1) ++count;
  if (mat[linha][coluna+1] == 1) ++count;
  if (mat[linha+1][coluna-1] == 1) ++count;
  if (mat[linha+1][coluna] == 1) ++count;
  if (mat[linha+1][coluna+1] == 1) ++count;
  return count;
}

int main()
{
  // Entrada de dados do usuário
  int LIN = entradalinha();
  int COL = entradacoluna();

  int **mat;
  int **Avizinhanca;
  int i, j;
  
  // Aloca a matriz de celulas
  mat = malloc (LIN * sizeof (int*));
  for (i=0; i < LIN; i++)
    mat[i] = malloc (COL * sizeof (int));
  
  // Aloca matriz de vizinhos
  Avizinhanca = malloc (LIN * sizeof (int*));
  for (i=0; i < LIN; i++)
    Avizinhanca[i] = malloc (COL * sizeof (int));
  
  // Preenche o conteúdo da matriz com 0 
  for (i=0; i < LIN; i++)
    for (j=0; j < COL; j++)
      mat[i][j] = 0;
  
  // Preenche o conteúdo da matriz com 0 
  for (i=0; i < LIN; i++)
    for (j=0; j < COL; j++)
      Avizinhanca[i][j] = 0;

  ImprimeMatriz(mat, LIN, COL);
  entradacelula(mat);
  ImprimeMatriz(mat, LIN, COL);
  
  
  int control = 1;
  while (control != 0)
  {
    printf("\nPressione qualquer tecla para rodar uma geração ou 0 (zero) para parar: ");
    scanf("%d", &control);
    
    //Código do jogo de uma nova geração
      for(i=1; i<LIN-1; i++)
      {
        for(j=1;j<COL-1;j++)
        {
            int vizinhos = vizinhanca(mat,i,j);
            printf("\nmatriz [%d][%d] tem %d vizinhos", i, j, vizinhos);
            Avizinhanca[i][j] = vizinhos;
            if((mat[i][j] ==1) && (Avizinhanca[i][j]==2 || Avizinhanca[i][j]==3))
              mat[i][j]=1;
            else if ((mat[i][j] == 1) && (Avizinhanca[i][j]==0 || Avizinhanca[i][j] == 1))
              mat[i][j]=0;
            else if ((mat[i][j] == 1) && (Avizinhanca[i][j]>=4))
              mat[i][j]=0;
            else if(mat[i][j]==0 && Avizinhanca[i][j]==3)
              mat[i][j]=1;
        }
      }
  ImprimeMatriz(Avizinhanca, LIN, COL);
  ImprimeMatriz(mat, LIN, COL);
  }
  
  // libera a memória da matriz
  for (i=0; i < LIN; i++)
    free (Avizinhanca[i]);
  free (Avizinhanca) ;
      
  // libera a memória da matriz
  for (i=0; i < LIN; i++)
    free (mat[i]);
  free (mat) ;
}