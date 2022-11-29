#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>

#define INDEX 15
#define IDNAME 31
#define PATH 100



struct bin_tree {
  char id[IDNAME + 1];
  char path[PATH + 1];
  char tipo;
  int parada;
  struct bin_tree *dir_ant;
  struct bin_tree *prox[INDEX];
};
typedef struct bin_tree node;

int ValidateString (char *B){
        int i;
        for (i = 0; B[i] != '\0'; i++)
        {
               if (B[i]=='.')
              {
                    return 1;
              }
       }
       return 0;
}


void insert(node **tree, char* val, char type,int indice,char *caminho) {
  node *temp = NULL;
  if (!(*tree)) {
    temp = (node *)malloc(sizeof(node));
    temp->dir_ant = temp->prox[0] = NULL;
    for (int i = 0; i < IDNAME; i++)
      temp->id[i] = val[i];
    temp->tipo = type;
     for (int i = 0; caminho[i] != '\0'; i++)
        {
    temp->path[i]=caminho[i];
    temp->parada=indice+1;
}
    *tree = temp;
  }
  else  if(indice<INDEX){
    temp = (node *)malloc(sizeof(node));
    temp->dir_ant = (*tree);
    for (int i = 0; i < IDNAME; i++)
      temp->id[i] = val[i];
    temp->tipo = type;
    for (int i = 0; caminho[i] != '\0'; i++)
        {
    temp->path[i]=caminho[i];
    temp->parada=indice+1;
}
    (*tree)->prox[indice] = temp;
  }
  else{
    printf("Está cheio \n");
  }

}

void Remove(node *tree, int indice) {
  if ((tree)) {
    if (tree->prox[indice] != NULL) {
      node *temp = NULL;
      temp = (node *)malloc(sizeof(node));
      temp = tree->prox[indice];
      temp->dir_ant = NULL;
      tree->prox[indice] = NULL;
      free(temp);
    }
    return;
  }
}


void print_Profundidade(node *tree, int parada) {
  if (tree) {
    printf("%s\n", tree->id);
    for (int i = 0; i < parada; i++) {
        printf("%s\n",tree->prox[i]);
        
    }
    
}
}

void print(node *tree, int parada) {
  if (tree) {
    printf("%s\n", tree->id);
    for (int i = 0; i < parada; i++) {
        printf("[%i]\t%s\n",i,tree->prox[i]);
    }
  }
}

typedef struct _Plugin{
  char *handle;
} Plugin;

void fatal_error(char *message){
  perror(message);
  exit(EXIT_FAILURE);
}

Plugin* load_plugins(char* pluginDir, int* numPlugins){
  assert(pluginDir && numPlugins);
  DIR* dir = opendir(pluginDir);
  if (!dir)
  {
    fatal_error("opendir");
    return NULL;
  }

  struct dirent* dr;
  Plugin *plugins = NULL;
  int i = 0;
  while ((dr = readdir(dir)))
  {

    char *path = malloc(strlen(pluginDir) + strlen(dr->d_name) + 1);
    if (!path)
    {

      free(plugins);
      fatal_error("malloc");
      return NULL;
    }
    strcpy(path, pluginDir);
    strcat(path, dr->d_name);

    i++;
    Plugin* new_plugins = realloc(plugins, i * sizeof(Plugin));
    if (!new_plugins)
    {
      fatal_error("realloc");
      free(plugins);
      return NULL;
    }
    plugins = new_plugins;
    plugins[i - 1].handle = path;
    *numPlugins = i;
  }
  closedir(dir);
  return plugins;
}


int Read_DIR(node* root,char* DIR_PATH)
{
int parada=0;
  int nPlugins = 0;
  Plugin* plugins = load_plugins(DIR_PATH, &nPlugins);
  printf("Found %d plugins %p\n", nPlugins, plugins);
  for (int i = 0; i < nPlugins; ++i)
  {
    printf("[%d]: %s\n", i, plugins[i].handle);
    if(ValidateString(plugins[i].handle))
    	insert(&root,plugins[i].handle,'a',i,DIR_PATH);
    else
    	insert(&root,plugins[i].handle,'d',i,DIR_PATH);
    parada++;
  }
  printf("\n");
  print_Profundidade(root,parada);
  return parada;
}

node *Prox_Dir(node *tree, int indice) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp = tree->prox[indice];
  return temp;
}

node *Ant_Dir(node *tree) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp = tree->dir_ant;
  return temp;
}

int main(){

	node *root;
	root = NULL;
	int X=1;
	char DIR_PATH[PATH];
	int indice;
	printf("%s", DIR_PATH);
   	gets(DIR_PATH);
	insert(&root, "/", 'd',0,DIR_PATH);
    root->parada=Read_DIR(root,DIR_PATH);
    printf("\n");
 char caminho[PATH];
  int j = 0;
  int option;
  while (j==0){
    printf("\n[1] Criar diretório\n[2] Criar Arquivo\n[3] Mudar diretório corrente\n[4] Voltar um diretorio\n[5] Remover um arquivo\n[6] Apresentar a árvore realizando percurso em profundidade \n[7] Apresentar a árvore realizando um percurso em largura\n[8] Exit\nOption: ");
    scanf("%d", &option);
    switch (option){
      case 1:
        printf("Escreva o nome do Diretorio a ser Inserido: \n");
        scanf("%s", caminho);
        insert(&root,strcat(root->path,caminho), 'd', root->parada,root->path); 
        root->parada++;
        print(root,root->parada);
        break;
      case 2:
        printf("Escreva o nome do Arquivo a ser Inserido: \n");
        scanf("%s", caminho);
        insert(&root,strcat(root->path,caminho), 'a', root->parada,root->path); 
        root->parada++;
        print(root,root->parada);
        break;
      case 3:
      	X=1;
      	while(X){
      	print(root,root->parada);
        printf("Diretorio corrente:\n");
        scanf("%s", &caminho);
        printf("Indice:\n");
        scanf("%i", &indice);
        if(root->prox[indice]->tipo=='d')
		X--;
		
	}
        
        root->prox[indice]->parada=Read_DIR(root->prox[indice],caminho);
        root = Prox_Dir(root, indice);
        print(root,root->parada);
        break;
      case 4:
      	root = Ant_Dir(root);
        break;
      case 5:
        print(root,root->parada);
        printf("Indice:\n");
        scanf("%i", &indice);
        Remove(root, indice);
        break;
      case 6:
        printf("\n");
        print_Profundidade(root,root->parada);

        break;
      case 7:
        j++;
        break;
    case 8:
        j++;
        break;
      }
    }
    return 0;
}
