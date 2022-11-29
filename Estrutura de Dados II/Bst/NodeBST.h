// NodeBST.h.h
#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include <string>

class Funcionario
{
public:
	Funcionario(int ID, const std::string& Categoria, const std::string& Nome, const std::string& Cargo, const std::string& Sexo, int idade, float Salario, Funcionario* parent = nullptr, Funcionario* left = nullptr, Funcionario* right = nullptr);
	~Funcionario();

	void CopyDataFrom(const Funcionario* node);

	int GetID() const;
	void SetID(int ID);

	std::string GetCategoria() const;
	void SetCategoria(const std::string& Categoria);

	std::string GetNomes() const;
	void SetNomes(const std::string& Nomes);

	std::string GetCargo() const;
	void SetCargo(const std::string& Cargo);

	std::string GetSexo() const;
	void SetSexo(const std::string& Sexo);
	
  int GetIdade() const;
	void SetIdade(int idade);

	float GetSalario() const;
	void SetSalario(float Salario);
    
	Funcionario* GetParent() const;
	void SetParent(Funcionario* parent);

	Funcionario* GetLeft() const;
	void SetLeft(Funcionario* left);

	Funcionario* GetRight() const;
	void SetRight(Funcionario* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	int m_ID;
	std::string m_Categoria;
	std::string m_Nomes;
	std::string m_Cargo;
	std::string m_Sexo;
	int m_Idades;
	float m_Salario;

	Funcionario* m_Parent;
	Funcionario* m_Left;
	Funcionario* m_Right;

	int GetDepthInternal(const Funcionario* node) const;
	int GetHeightInternal(const Funcionario* node) const;
};

#endif