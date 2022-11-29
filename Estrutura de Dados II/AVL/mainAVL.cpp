// mainAVL.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include "AVL.h"

void Insert(AVL* avl)
{
	int num;
	std::cout << "Insert number: ";
	std::cin >> num;
	
	std::string name;
	std::cout << "Insert name: ";
	std::cin >> name;
	
	int qtde;
	std::cout << "Insert stock: ";
	std::cin >> qtde;
	
	float valor;
	std::cout << "Insert price: ";
	std::cin >> valor;
	NodeAVL* node = avl->Insert(num,name,qtde,valor);
	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL* avl)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	avl->Remove(num);
}

void Search(AVL* avl)
{
	int id;
	std::cout << "Search food name: ";
	std::cin >> id;
	NodeAVL* node = avl->Search(id);
	if (node)
		std::cout << "Node found:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL* avl)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Predecessor(num);
	if (node)
		std::cout << "Predecessor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(AVL* avl)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Successor(num);
	if (node)
		std::cout << "Successor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(AVL* avl)
{
	NodeAVL* node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL* avl)
{
	NodeAVL* node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL* avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL* avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL* avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL* avl)
{
	avl->Clear();
}

void ProdutoEstoque(AVL* avl){
  std::string op;
  std::cout << "\nNome da comida: ";
  std::cin >> op;
  NodeAVL* node = avl->SearchInOrder(op);
  if (node)
		//std::cout << "Node found:\n" << node->ToString();
	    std::cout<<"\nNome: "<<node->GetNome()<<std::endl<<"Preco unitario: "<<node->GetValor()<<std::endl<<"Estoque: "<<node->GetQtde()<<std::endl
	    <<"Valor total do estoque de "<<node->GetNome()<<": R$ "<<node->GetQtde()*node->GetValor()<<std::endl;
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void SomaEstoque(AVL* avl){
  std::cout<<"Somatoria do Estoque: R$ "<<std::setprecision(2) << std::fixed <<avl->SomaProdutos()<<std::endl;
}

void EstoqueInferior(AVL* avl)
{
	int Stock;
	std::cout << "Quantidade: ";
	std::cin >> Stock;
	std::cout << avl->Exer5(Stock)<<std::endl;
}

int main()
{

	AVL* avl = new AVL();

	const int SIZE = 9;
	int ids[SIZE] = { 5, 4, 3, 1, 2, 7, 6, 8, 9 };
	std::string Nomes[SIZE]={"Banana","Repolho","Maca","Uva","Pera","Milho","Pao","Hamburger","Acerola"};
	int Quantidade[SIZE]= {58,78,53,57,81,97,74,66,86};
	float Valor[SIZE]={1.5,5,4.21,19.99,75.45,0.25,200,35,100};
	for (int i = 0; i < SIZE; ++i)
		avl->Insert(ids[i], Nomes[i],Quantidade[i],Valor[i]);

	int option = 0;
	do
	{
    std::cout << "\n*** Estoque de produtos ***\n\n"
      << "[1] Inserir produtos.\n"
      << "[2] Lista de produtos.\n"
      << "[3] Calcula valor em R$ do produto em Estoque.\n"
      << "[4] Calcula valor do Estoque.\n"
      << "[5] Mostra produtos inferiores a uma quantidade.\n"
      << "[6] Finaliza programa.\n\n"
      <<"Opcao: ";

		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(avl); break;
		//case 2: Remove(avl); break;
		//case 4: Predecessor(avl); break;
		//case 5: Successor(avl); break;
		//case 6: FindMin(avl); break;
		//case 7: FindMax(avl); break;
		//case 8: TraverseInOrder(avl); break;
		//case 9: TraversePreOrder(avl); break;
		//case 10: TraversePostOrder(avl); break;
		//case 11: Clear(avl); break;
    case 2: TraverseInOrder(avl); break;
    case 3: ProdutoEstoque(avl); break;
    case 4: SomaEstoque(avl); break;
    case 5: EstoqueInferior(avl); break;
		}

		std::cout << '\n';
	} while (option != 6);

	delete avl;
}
//#endif