/* Referências
https://stackoverflow.com/questions/33050350/reading-from-an-excel-file
*/
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "LinkedList.h"
using namespace std;

LinkedList* Read();
void Print(const LinkedList* list);
int AnaliseDeDadosA(LinkedList* list);
void AnaliseDeDadosB(LinkedList* list, int count);
int AnaliseDeDadosB1(LinkedList* list);
int AnaliseDeDadosB2(LinkedList* list,int Media);
int AnaliseDeDadosC(LinkedList* list);
string AnaliseDeDadosD(LinkedList* list);
int AnaliseDeDadosE(LinkedList* list);


LinkedList* Read()
{
  LinkedList* list = Create();
  ifstream inFile;
  
  string disciplina;
  string isbn;
  string titulo;
  string autor; 
  string edicao;
  string cidade;
  string editora; 
  string ano;
  string complementar; 
  inFile.open("bibliografia.csv");

  while (!inFile.eof()) 
  {  
      getline (inFile, disciplina, ';');
      getline (inFile, isbn, ';');
      getline (inFile, titulo, ';');
      getline (inFile, autor, ';');
      getline (inFile, edicao, ';');
      getline (inFile, cidade, ';');
      getline (inFile, editora, ';');
      getline (inFile, ano, ';');
      inFile >> complementar;
      Append(list, disciplina, isbn, titulo, autor, edicao, cidade, editora, ano, complementar);
  }
  
  inFile.close();
  Node* temp = RemoveHead(list);
  DestroyNode(temp);
  return list;
}

void Print(const LinkedList* list)
{
    for (Node* node = list->head; node != nullptr; node = node->next)
    {
        cout << "Disciplina: " << node->disciplina << endl;
        cout << "ISBN: " << node->isbn << endl;
        cout << "Titulo: " << node->titulo << endl;
        cout << "Autor: " << node->autor << endl;
        cout << "Edicao: " << node->edicao << endl;
        cout << "Cidade: " << node->cidade << endl;
        cout << "Editora: " << node->editora << endl;
        cout << "Ano: " << node->ano << endl;
        cout << "Complementar: " <<  node->complementar << endl;
        cout << "\n";
      
    }
    std::cout << '\n';
}

int AnaliseDeDadosA(LinkedList* list)
{
	int Br=0;
    for (Node* node = list->head; node != nullptr; node = node->next)
    {
    	string S=node->isbn;
    	if(S[4]=='8' && S[5]=='5'){
    		Br++;	
		}
    }
    return Br;
}

void AnaliseDeDadosB(LinkedList* list,int count)
{
	int Media=AnaliseDeDadosB1(list);
	int Num=AnaliseDeDadosB2(list, Media);
	cout<<"A media dos anos dos livros publicados é "<<Media;
  cout << "\n\nO número de livros que tem o ano lancado acima ou igual a media é: "<<Num<<"/"<<count<<endl;
	cout<<"\nE o número de livros que tem o ano lancado abaixo da media é: "<<count-Num<<"/"<<count<<endl;
}
int AnaliseDeDadosB1(LinkedList* list)
{
	int soma = 0;
  Node* node;
  for (node = list->head; node != nullptr; node = node->next)
  {
    int x = stoi(node->ano);
    soma = soma + x;
  }
    int Media= soma/(Count(list));
    return Media;
}
int AnaliseDeDadosB2(LinkedList* list,int Media)
{
  int Num = 0;
  Node* node;
  for (node = list->head; node != nullptr; node = node->next)
    {
     if(stoi(node->ano) >= Media)
    		Num++;	 
    }		
  return Num;
}

int AnaliseDeDadosC(LinkedList* list)
{
  int quant=0;
  for (Node* node = list->head; node != nullptr; node = node->next)
  {
    if(stoi(node->edicao)>=3) quant++;	
  }
  return quant;
}

string AnaliseDeDadosD(LinkedList* list)
{
  int Boston = 0, Cambridge = 0, Chicago = 0, Curitiba = 0, Hoboken = 0, Mineola = 0, NewYork = 0, PortoAlegre = 0, Princeton = 0, RioJaneiro = 0, SaoPaulo = 0;
  Node* node;
  for(node = list->head; node != nullptr; node = node->next)
    {
      string city = node->cidade;
      if (city == "Boston")Boston++;
      else if (city == "Cambridge")Cambridge++;
      else if (city == "Chicago")Chicago++;
      else if (city == "Curitiba")Curitiba++;
      else if (city == "Hoboken")Hoboken++;
      else if (city == "Mineola")Mineola++;
      else if (city == "New York")NewYork++;
      else if (city == "Porto Alegre")PortoAlegre++;
      else if (city == "Princeton")Princeton++;
      else if (city == "Rio de Janeiro")RioJaneiro++;
      else if (city == "São Paulo")SaoPaulo++;
    }
  int menor = 1;
  int indice = 0;
  string nomes[11] = {"Boston", "Cambridge", "Chicago", "Curitiba", "Hoboken", "Mineola", "New York", "Porto Alegre", "Princeton", "Rio de Janeiro", "SaoPaulo"};
  int vetor[11] = {Boston, Cambridge, Chicago, Curitiba, Hoboken, Mineola, NewYork, PortoAlegre, Princeton, RioJaneiro, SaoPaulo};
  for (int i = 0; i < 11; ++i)
    {
      if (vetor[i] <= menor)
      { 
        menor = vetor[i];
        indice = i;
      }
    }
  
  return nomes[indice];
}

int AnaliseDeDadosE(LinkedList* list)
{
  int Q=0;
    for (Node* node = list->head; node != nullptr; node = node->next)
    {
    	if(stoi(node->ano) >= 2010){
    		cout << "Disciplina: " << node->disciplina << endl;
        cout << "Titulo: " << node->titulo << endl;
        cout << "Ano: " << node->ano << endl;
        cout << "\n";
        Q++;
		  }
    }
  return Q;
}

int main()
{
  setlocale(LC_CTYPE, "Portuguese");
  
  std::string input;
	int option;
  LinkedList* leitura = Read();
  int x, y, total = Count(leitura);
  string cidade;
  do    
	{
		std::cout << "\n*** Analise de dados de um banco de dados ***\n"
			<< "[1] Ler os dados\n"
			<< "[2] Exibir os dados\n"
      << "[3] Análise de dados A\n"
      << "[4] Análise de dados B\n"
      << "[5] Análise de dados C\n"
      << "[6] Análise de dados D\n"
      << "[7] Análise de dados E\n"
			<< "[8] Encerrar programa\n"
			<< "Escolha uma opção: \n";
		std::cin >> input;

		try
		{
			option = stoi(input);
		}
		catch (const exception& e)
		{
			option = -1;
		}
		switch (option)
		{
  		case 1: 
        leitura; 
        cout << "A leitura foi realizada com sucesso\n";
        break;

  		case 2: 
        Print(leitura); 
        break;
      
      case 3:
        cout << "\nAnálise de dados A: \n\nQuantos livros foram publicados por editoras brasileiras, quantos livros foram publicados por editoras estrangeiras e suas respectivas porcentagens." << "\n";
        x = AnaliseDeDadosA(leitura);
        total = Count(leitura);     
        y = total - x;
        cout << "\n" << x << " livros são nacionais que corresponde a " << x*100/total << "% do total de livros \n";
        cout << y << " livros são estrangeiros que corresponde a " << y*100/total << "% do total de livros \n";
        break;
      
      case 4:
        cout << "\nAnálise de dados B:\n\nQual é o ano médio de publicação dos livros da lista. Quantos foram publicados antes e depois desse determinado ano." << "\n\n";
        AnaliseDeDadosB(leitura,(total));
        break;
      
      case 5:
        cout << "\nAnálise de dados C:\n\nQuantos livros possuem 3 ou mais edições publicadas." << "\n";
        x = AnaliseDeDadosC(leitura);
        cout << "\n" << x << " livros possuem 3 ou mais edições publicadas\n";
        break;
      
      case 6:
        cout << "\nAnálise de dados D: \n\nQual a cidade com o maior número de livros publicados/registrado." << "\n";
        cidade = AnaliseDeDadosD(leitura);
        cout << "\n" << cidade << " é a cidade com menos livros publicados\n";
        break;
      
      case 7:
        cout << "\nAnálise de dados E: \n\nQuais livros foram publicados após 2010." << "\n";
        x = AnaliseDeDadosE(leitura); 
        cout << "\n" << x << " livros foram publicados após 2010\n";
        break;
      
		default:
			if (option != 8)
				std::cout << "\n*** OPÇÃO INVÁLIDA! ***\n";
			break;
		}
	} while (option != 8);
  system("pause");
  return 0;
}

