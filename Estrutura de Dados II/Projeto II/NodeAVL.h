/* 
NodeAVL.h

Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
Lucas Damasceno de Cunha Lima - 32132611
Lucas Iudi Corregliano Gallinari - 32138628
Thiago Aidar Figueiredo - 32144547
*/

#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>
#include "Alimento.h"

class NodeAVL
{
public:
	NodeAVL(const std::string& food, const Alimento& data, NodeAVL* parent = nullptr, NodeAVL* left = nullptr, NodeAVL* right = nullptr);
	~NodeAVL();

	void CopyDataFrom(const NodeAVL* node);

  std::string GetFood() const;
	void SetFood(std::string food);

	Alimento GetData() const;
	void SetData(const Alimento& data);

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
	std::string m_Food;
	Alimento m_Data;
	
	NodeAVL* m_Parent;
	NodeAVL* m_Left;
	NodeAVL* m_Right;

	int m_BalanceFactor;

	int GetDepthInternal(const NodeAVL* node) const;
	int GetHeightInternal(const NodeAVL* node) const;
};

#endif