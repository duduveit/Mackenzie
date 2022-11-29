// BST.h
#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"

class BST
{
public:
	BST();
	~BST();

	Funcionario* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	float Exercicio_C() const;
  int Exercicio_D(const std::string& Sexo) const;
  int Exercicio_E(const std::string& cat) const;
  std::string Exercicio_F(const int& idade) const;

	Funcionario* FindMin() const;
	Funcionario* FindMax() const;

	Funcionario* Predecessor(int id) const;
	Funcionario* Successor(int id) const;

	Funcionario* SearchIterative(int id) const;
	Funcionario* Search(int id) const;
	Funcionario* Insert(int id, const std::string& data, const std::string& Cargo, const std::string& X,const std::string& Nomes,float Salario,int idade);
	void Remove(int id);

private:
	Funcionario* m_Root;

	void Destroy(Funcionario *node);
	
	int GetDegreeInternal(const Funcionario* node) const;

	float Exercicio_CInternal(const Funcionario* node,int Soma) const;
  int Exercicio_DInternal (const Funcionario* node, int Soma, const std::string& Sexo) const;
  int Exercicio_EInternal (const Funcionario* node, int Soma, const std::string& cat) const;
  std::string Exercicio_FInternal(const Funcionario* node, int idade) const;

	Funcionario* FindMinInternal(Funcionario* node) const;
	Funcionario* FindMaxInternal(Funcionario* node) const;

	Funcionario* PredecessorInternal(Funcionario* node) const;
	Funcionario* SuccessorInternal(Funcionario* node) const;

	Funcionario* SearchInternal(Funcionario* node, int &id) const;
	Funcionario* InsertInternal(Funcionario* node, Funcionario* parent, int id, const std::string& data, const std::string& Cargo, const std::string& X,const std::string& Nomes,float Salario, int idade);
	Funcionario* RemoveInternal(Funcionario* node, int id);
	Funcionario* RemoveNode(Funcionario* node);
	void UpdateParentChild(Funcionario* parent, const Funcionario* child, Funcionario* newChild);
};

#endif