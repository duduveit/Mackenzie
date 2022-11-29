// AVL.h
#ifndef __AVL_H__
#define __AVL_H__

#include "NodeAVL.h"

class AVL
{
public:
	AVL();
	~AVL();

	NodeAVL* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;

	NodeAVL* FindMin() const;
	NodeAVL* FindMax() const;

	NodeAVL* Predecessor(int id) const;
	NodeAVL* Successor(int id) const;

	NodeAVL* Search(int id) const;
  NodeAVL* SearchInOrder( std::string food);
	NodeAVL* Insert(int id, const std::string& data, int qtde,float valor);
	void Remove(int id);
  float SomaProdutos() const;
  std::string Exer5(int quant) const;

private:
	NodeAVL* m_Root;

	void Destroy(NodeAVL *node);
	
	int GetDegreeInternal(const NodeAVL* node) const;

	std::string TraverseInOrderInternal(const NodeAVL* node) const;
	std::string TraversePreOrderInternal(const NodeAVL* node) const;
	std::string TraversePostOrderInternal(const NodeAVL* node) const;

	NodeAVL* FindMinInternal(NodeAVL* node) const;
	NodeAVL* FindMaxInternal(NodeAVL* node) const;

	NodeAVL* PredecessorInternal(NodeAVL* node) const;
	NodeAVL* SuccessorInternal(NodeAVL* node) const;

	NodeAVL* SearchInternal(NodeAVL* node, int& id) const;
  void SearchInOrderInternal(NodeAVL* node, std::string &food, NodeAVL*& found);
  float SomaProdutosInternal(NodeAVL* node, float Soma) const;
	std::string Exer5Internal(NodeAVL* node, int quant) const;

	NodeAVL* InsertInternal(NodeAVL* node, NodeAVL* parent, int id, const std::string& data,int qtde, float valor);
	NodeAVL* RemoveInternal(NodeAVL* node, int id);
	NodeAVL* RemoveNode(NodeAVL* node);
	void UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild);

	NodeAVL* RotateLeft(NodeAVL* node);
	NodeAVL* RotateRight(NodeAVL* node);
	NodeAVL* RotateLeftRight(NodeAVL* node);
	NodeAVL* RotateRightLeft(NodeAVL* node);

	NodeAVL* Balance(NodeAVL* node);
};

#endif