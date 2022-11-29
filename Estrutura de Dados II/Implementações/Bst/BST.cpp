// BST.cpp
#include "NodeBST.h"
#include "BST.h"
#include "Utils.h"
#include <sstream>
#include <queue> // TraverseDepthOrderInternal


BST::BST()
	: m_Root(nullptr)
{
}

BST::~BST()
{
	Clear();
}

Funcionario* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void BST::Destroy(Funcionario* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const Funcionario* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

float BST::Exercicio_C() const
{
  int Soma=0;
	return Exercicio_CInternal(m_Root,Soma);
}

float BST::Exercicio_CInternal(const Funcionario* node, int Soma) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		Soma=Soma+Exercicio_CInternal(node->GetLeft(),0);
		Soma=Soma+ node->GetSalario();
		Soma=Soma+Exercicio_CInternal(node->GetRight(),0);
		return Soma;
	}
	return 0;
}

int BST::Exercicio_D(const std::string& Sexo) const
{
    int Soma=0;
	return Exercicio_DInternal(m_Root,Soma,Sexo);
}

int BST::Exercicio_DInternal(const Funcionario* node, int Soma,const std::string& Sexo) const
{
	if (node != nullptr)
	{
		Soma=Soma+Exercicio_DInternal(node->GetLeft(),0,Sexo);
		if(node->GetSexo()==Sexo){
		    Soma++;
		}
		Soma=Soma+Exercicio_DInternal(node->GetRight(),0,Sexo);
		return Soma;
	}
	return 0;
}

int BST::Exercicio_E(const std::string& cat) const
{
  int Soma=0;
	return Exercicio_EInternal(m_Root,Soma,cat);
}

int BST::Exercicio_EInternal(const Funcionario* node, int Soma,const std::string& cat) const
{
	if (node != nullptr)
	{
		Soma=Soma+Exercicio_EInternal(node->GetLeft(),0,cat);
		if(node->GetCategoria()==cat){
		    Soma++;
		}
		Soma=Soma+Exercicio_EInternal(node->GetRight(),0,cat);
		return Soma;
	}
	return 0;
}

std::string BST::Exercicio_F(const int& idade) const
{
	return Exercicio_FInternal(m_Root, idade);
}

std::string BST::Exercicio_FInternal(const Funcionario* node, int idade) const
{
  std::ostringstream oss;
  if (node != nullptr){
		oss << Exercicio_FInternal(node->GetLeft(), idade);
    if (idade <= node->GetIdade()){
      		oss << node->GetID() <<'(' << node->GetCategoria() << ") "<<'(' << node->GetNomes() << ") "<<'(' << node->GetCargo() << ") "<< "(" << node->GetSexo() << ")"<< "(" << node->GetIdade() << ")"<< "(" << node->GetSalario() << ")\n";
    }
		oss << Exercicio_FInternal(node->GetRight(), idade);
		return oss.str();
  }
  return "";
}

Funcionario* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

Funcionario* BST::FindMinInternal(Funcionario* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

Funcionario* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

Funcionario* BST::FindMaxInternal(Funcionario* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

Funcionario* BST::Predecessor(int id) const
{
	Funcionario* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

Funcionario* BST::PredecessorInternal(Funcionario* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		Funcionario* current = node;
		Funcionario* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

Funcionario* BST::Successor(int id) const
{
	Funcionario* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

Funcionario* BST::SuccessorInternal(Funcionario* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		Funcionario* current = node;
		Funcionario* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

Funcionario* BST::SearchIterative(int id) const
{
	Funcionario* current = m_Root;
	while (current != nullptr && current->GetID() != id)
	{
		if (current->GetID() > id)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

Funcionario* BST::Search(int id) const
{
	return SearchInternal(m_Root, id);
}

Funcionario* BST::SearchInternal(Funcionario* node, int &id) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		return node;
	else if (node->GetID() > id)
		return SearchInternal(node->GetLeft(), id);
	else
		return SearchInternal(node->GetRight(), id);
}

Funcionario* BST::Insert(int id, const std::string& categoria, const std::string& nome, const std::string& cargo,const std::string& sexo,float idade,int salario)
{
	if (IsEmpty())
	{
		m_Root = new Funcionario(id, categoria, nome, cargo, sexo, idade, salario);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, id, categoria, nome, cargo, sexo, idade, salario);
}

Funcionario* BST::InsertInternal(Funcionario* node, Funcionario* parent, int id, const std::string& categoria, const std::string& nome,  const std::string& cargo, const std::string& sexo, float idade, int salario)
{
	if (node == nullptr)
		node = new Funcionario(id, categoria, nome, cargo, sexo, idade, salario, parent);
	else if (node->GetID() == id)
		return nullptr; // Error! Cannot insert duplicate.
	else if (node->GetID() > id)
		node->SetLeft(InsertInternal(node->GetLeft(), node, id, categoria, nome, cargo, sexo, idade, salario));
	else if (node->GetID() < id)
		node->SetRight(InsertInternal(node->GetRight(), node, id, categoria, nome, cargo, sexo, idade, salario));

	return node;
}

void BST::Remove(int id)
{
	RemoveInternal(m_Root, id);
}

Funcionario* BST::RemoveInternal(Funcionario* node, int id)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		node = RemoveNode(node);
	else if (node->GetID() > id)
		node->SetLeft(RemoveInternal(node->GetLeft(), id));
	else
		node->SetRight(RemoveInternal(node->GetRight(), id));
	
	return node;
}

Funcionario* BST::RemoveNode(Funcionario* node)
{
	Funcionario* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		Funcionario* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		Funcionario* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		Funcionario* predecessor = Predecessor(node->GetID());

		// Instead of only updating pointers, we are copying the data from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetID()));
	}

	return node;
}

void BST::UpdateParentChild(Funcionario* parent, const Funcionario* child, Funcionario* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}
