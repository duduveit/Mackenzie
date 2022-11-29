// NodeBST.h
#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include "Alimento.h"
#include <string>

class NodeBST
{
public:
	NodeBST(const std::string& food, const Alimento& data, NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST();

	void CopyDataFrom(const NodeBST* node);

	std::string GetFood() const;
	void SetFood(std::string food);

	Alimento GetData() const;
	void SetData(const Alimento& data);

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	std::string m_Food;
  Alimento m_Data; //Alimento é o novo m_Data 

	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
