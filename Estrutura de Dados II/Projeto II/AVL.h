/* 
AVL.h

Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
Lucas Damasceno de Cunha Lima - 32132611
Lucas Iudi Corregliano Gallinari - 32138628
Thiago Aidar Figueiredo - 32144547
*/

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

	NodeAVL* FindMin() const;
	NodeAVL* FindMax() const;

	NodeAVL* Predecessor(std::string food) const;
	NodeAVL* Successor(std::string food) const;

	NodeAVL* Search(std::string food) const;
  NodeAVL* SearchInOrder( std::string food);
	NodeAVL* Insert(std::string food, const Alimento& data);
	void Remove(std::string food);

  std::string AVLtoCSV() const;

private:
	NodeAVL* m_Root;

	void Destroy(NodeAVL *node);
	
	int GetDegreeInternal(const NodeAVL* node) const;

	std::string TraverseInOrderInternal(const NodeAVL* node) const;

  void SearchInOrderInternal(NodeAVL* node, std::string &food, NodeAVL*& found);

	NodeAVL* FindMinInternal(NodeAVL* node) const;
	NodeAVL* FindMaxInternal(NodeAVL* node) const;

	NodeAVL* PredecessorInternal(NodeAVL* node) const;
	NodeAVL* SuccessorInternal(NodeAVL* node) const;

	NodeAVL* SearchInternal(NodeAVL* node, std::string& food) const;
	NodeAVL* InsertInternal(NodeAVL* node, NodeAVL* parent, std::string food, const Alimento& data);
  
	NodeAVL* RemoveInternal(NodeAVL* node, std::string food);
	NodeAVL* RemoveNode(NodeAVL* node);
	void UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild);

	NodeAVL* RotateLeft(NodeAVL* node);
	NodeAVL* RotateRight(NodeAVL* node);
	NodeAVL* RotateLeftRight(NodeAVL* node);
	NodeAVL* RotateRightLeft(NodeAVL* node);

	NodeAVL* Balance(NodeAVL* node);

  std::string AVLtoCSVInternal(const NodeAVL* node) const;

};

#endif