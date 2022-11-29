// NodeBST.cpp
#include "NodeBST.h"
#include "Utils.h"

Funcionario::Funcionario(int ID, const std::string& Categoria, const std::string& Nome, const std::string& Cargo, const std::string& Sexo, int idade, float Salario, Funcionario* parent, Funcionario* left, Funcionario* right)
	: m_ID(ID)
	, m_Categoria(Categoria)
  , m_Nomes(Nome)
	, m_Cargo(Cargo)
	, m_Sexo(Sexo)
	, m_Idades(idade)
	, m_Salario(Salario)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
{
}

Funcionario::~Funcionario()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

void Funcionario::CopyDataFrom(const Funcionario* node)
{
	m_ID = node->GetID();
	m_Categoria = node->GetCategoria();
	m_Sexo= node->GetSexo();
	m_Cargo= node->GetCargo();
	m_Nomes= node->GetNomes();
	m_Salario= node->GetSalario();
}

int Funcionario::GetID() const
{
	return m_ID;
}

void Funcionario::SetID(int id)
{
	m_ID = id;
}

std::string Funcionario::GetCategoria() const
{
	return m_Categoria;
}

void Funcionario::SetCategoria(const std::string& categoria)
{
	m_Categoria = categoria;
}

std::string Funcionario::GetNomes() const
{
	return m_Nomes;
}

void Funcionario::SetNomes(const std::string& Nomes)
{
	m_Nomes = Nomes;
}

std::string Funcionario::GetCargo() const
{
	return m_Cargo;
}

void Funcionario::SetCargo(const std::string& Cargo)
{
	m_Cargo = Cargo;
}

std::string Funcionario::GetSexo() const
{
	return m_Sexo;
}

void Funcionario::SetSexo(const std::string& sexo)
{
	m_Sexo = sexo;
}

int Funcionario::GetIdade() const
{
	return m_Idades;
}

void Funcionario::SetIdade(int idade)
{
	m_Idades = idade;
}

float Funcionario::GetSalario() const
{
	return m_Salario;
}

void Funcionario::SetSalario(float Salario)
{
	m_Salario = Salario;
}

Funcionario* Funcionario::GetParent() const
{
	return m_Parent;
}

void Funcionario::SetParent(Funcionario* parent)
{
	m_Parent = parent;
}

Funcionario* Funcionario::GetLeft() const
{
	return m_Left;
}

void Funcionario::SetLeft(Funcionario* left)
{
	m_Left = left;
}

Funcionario* Funcionario::GetRight() const
{
	return m_Right;
}

void Funcionario::SetRight(Funcionario* right)
{
	m_Right = right;
}

bool Funcionario::IsRoot() const
{
	return m_Parent == nullptr;
}

bool Funcionario::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int Funcionario::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int Funcionario::GetDepth() const
{
	return GetDepthInternal(this);
}

int Funcionario::GetDepthInternal(const Funcionario* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int Funcionario::GetHeight() const
{
	return GetHeightInternal(this);
}

int Funcionario::GetHeightInternal(const Funcionario* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}