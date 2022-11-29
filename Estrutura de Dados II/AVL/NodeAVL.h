// NodeAVL.h
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>

class NodeAVL
{
public:
	NodeAVL(int id, const std::string& nome,int qtde,float valorUnitario, NodeAVL* parent = nullptr, NodeAVL* left = nullptr, NodeAVL* right = nullptr);
	~NodeAVL();

	void CopyDataFrom(const NodeAVL* node);

	int GetID() const;
	//void SetID(int id);

	std::string GetNome() const;
	void SetNome(const std::string& data);
	
	int GetQtde() const;
	void SetQtde(int QTDE);
	
	float GetValor() const;
	void SetValor(float Valor);

	NodeAVL* GetParent() const;
	void SetParent(NodeAVL* parent);

	NodeAVL* GetLeft() const;
	void SetLeft(NodeAVL* left);

	NodeAVL* GetRight() const;
	void SetRight(NodeAVL* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

	int GetBalanceFactor() const;
	void UpdateBalanceFactor();

	std::string ToString() const;

private:
	int m_ID;
	std::string m_Nome;
	int m_qtde;
	float m_valorUnitario;
	
	
	NodeAVL* m_Parent;
	NodeAVL* m_Left;
	NodeAVL* m_Right;

	int m_BalanceFactor;

	int GetDepthInternal(const NodeAVL* node) const;
	int GetHeightInternal(const NodeAVL* node) const;
};

#endif