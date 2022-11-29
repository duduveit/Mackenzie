// BST.h
#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"

class BST
{
public:
	BST();
	~BST();

	NodeBST* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;
	std::string TraverseDepthOrder() const;
  NodeBST* SearchInOrder( std::string food);

	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(std::string food) const;
	NodeBST* Successor(std::string food) const;

	NodeBST* SearchIterative(std::string food) const;
	NodeBST* Search(std::string food) const;
	NodeBST* Insert(std::string food, const Alimento& data);
	void Remove(std::string food);

private:
	NodeBST* m_Root;

	void Destroy(NodeBST *node);
	
	int GetDegreeInternal(const NodeBST* node) const;

	std::string TraverseInOrderInternal(const NodeBST* node) const;
	std::string TraversePreOrderInternal(const NodeBST* node) const;
	std::string TraversePostOrderInternal(const NodeBST* node) const;
	std::string TraverseDepthOrderInternal(const NodeBST* node) const;
  void SearchInOrderInternal(NodeBST* node, std::string &food, NodeBST*& found);

	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, std::string &food) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, std::string food, const Alimento& data);
	NodeBST* RemoveInternal(NodeBST* node, std::string food);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif
