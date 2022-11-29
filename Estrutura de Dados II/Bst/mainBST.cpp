// mainBST.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include "BST.h"


void PrintNode(Funcionario* node)
{
	if (node == nullptr) return;
	std::cout << "N:" << node->GetID()
		<< "(" << node->GetCategoria() << ")"
		<< "(" << node->GetNomes() << ")"
		<< "(" << node->GetCargo() << ")"
		<< "(" << node->GetSexo() << ")"
		<< "(" << node->GetSalario() << ")"
		<< "(" << node->GetIdade() << ")\n"
		<< " Parent:" << (node->GetParent() != nullptr ? node->GetParent()->GetID() : -1)
		<< " Left:" << (node->GetLeft() != nullptr ? node->GetLeft()->GetID() : -1)
		<< " Right:" << (node->GetRight() != nullptr ? node->GetRight()->GetID() : -1)
		<< " Degree: " << node->GetDegree()
		<< " Depth: " << node->GetDepth()
		<< " Height: " << node->GetHeight() << '\n';
}

void Insert(BST* bst)
{
	int ID;
	std::string Cat;
	std::string Cargo;
	std::string X;
	std::string Nome;
	int Idade;
	float Sal;
	std::cout << "Insira a ID: ";
	std::cin >> ID;
	std::cout << "Insira a Categoria de trabalho: ";
	std::cin >> Cat;
	std::cout << "Insira o Cargo: ";
	std::cin >> Cargo;
	std::cout << "Insira o Sexo: ";
	std::cin >> X;
	std::cout << "Insira a Idade: ";
	std::cin >> Idade;
	std::cout << "Insira o Nome: ";
	std::cin >> Nome;
	std::cout << "Insira o Salario: ";
	std::cin >> Sal;
	Funcionario* node = bst->Insert(ID,Cat,Cargo,X,Nome,Sal,Idade);
	if (node)
	{
		std::cout << "Node inserted:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(BST* bst)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	bst->Remove(num);
}

void Search(BST* bst)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	Funcionario* node = bst->Search(num);
	if (node)
	{
		std::cout << "Node found:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Exercicio_C(BST* bst)
{
	std::cout << bst->Exercicio_C() << '\n';
}

void Exercicio_D(BST* bst)
{
    std::string Sexo;
    std::cout<< "Digite o Sexo: ";
    std::cin>>Sexo;
	std::cout <<"O Número total dos Funcionarios com sexo informado é: "<<bst->Exercicio_D(Sexo) << '\n';
}

void Exercicio_E(BST* bst)
{
  std::string cat;
  std::cout<< "Digite a categoria do Funcionário: ";
  std::cin>>cat;
	std::cout <<"O Número total dos Funcionarios com categoria informado é: "<<bst->Exercicio_E(cat) << '\n';
}

void Exercicio_F(BST* bst)
{
  int idade;
  std::cout<< "Digite a idade: ";
  std::cin>>idade;
  std::cout << bst->Exercicio_F(idade) << '\n';
}

int main()
{
	BST* bst = new BST();
	int Identificacao[] = {4,2,6,1,3,5,8,7,9};
	const std::string Categoria[]= { "P", "P", "H", "P", "O", "H","P", "O", "H" };
	const std::string Nomes[]= { "Ana", "Bruno", "Claudia", "Deodoro", "Eduarda", "Fernando","Gabriela", "Humberto", "Iara" };
	const std::string Cargos[]= { "Administrador", "Gerente", "Administrador", "Gerente", "Chefe", "Gerente","Administrador", "Secretario", "Secretario" };
	const std::string Sexo[]= { "F", "M", "F", "M","F","M", "F","M", "F" };
	int Idades[] = { 56,37,45,20,42,26,47,53,39};
	float Salario[]= {20000,10000,20000,10000,30000,10000,20000,3000,3000};
	for (int i=0; i<9;i++)
		bst->Insert(*(Identificacao+i),(*(Categoria+i)),(*(Nomes+i)),(*(Cargos+i)),(*(Sexo+i)),(*(Idades+i)),(*(Salario+i)));

	
	int option = 0;
	do
	{
		std::cout << "*** BST Tree ***\n"
			<< "[1] Insert\n"
			<< "[2] Remove\n"
			<< "[3] Search\n"
      << "[4] Exercicio C\n"
      << "[5] Exercicio D\n"
      << "[6] Exercicio E\n"
      << "[7] Exercicio F\n"
			<< "[8] Clear\n"
			<< "[0] Exit\nOption: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(bst); break;
		case 2: Remove(bst); break;
		case 3: Search(bst); break;
    case 4: Exercicio_C(bst); break;
    case 5: Exercicio_D(bst); break;
    case 6: Exercicio_E(bst); break;
    case 7: Exercicio_F(bst); break;
		case 8: bst->Clear(); break;
		}

		std::cout << '\n';
	} while (option != 0);

	delete bst;
	return 0;
}
