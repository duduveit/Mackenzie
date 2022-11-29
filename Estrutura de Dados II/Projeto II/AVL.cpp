/* 
AVL.cpp

Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
Lucas Damasceno de Cunha Lima - 32132611
Lucas Iudi Corregliano Gallinari - 32138628
Thiago Aidar Figueiredo - 32144547
*/

#include "AVL.h"
#include "Utils.h"
#include <sstream>

AVL::AVL()
	: m_Root(nullptr)
{
}

AVL::~AVL(){
	Clear();
}

NodeAVL* AVL::GetRoot() const{
	return m_Root;
}

bool AVL::IsEmpty() const{
	return m_Root == nullptr;
}

void AVL::Clear(){
	Destroy(m_Root);
	m_Root = nullptr;
}

void AVL::Destroy(NodeAVL* node){
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int AVL::GetDegree() const{
	return GetDegreeInternal(m_Root);
}

int AVL::GetDegreeInternal(const NodeAVL* node) const{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int AVL::GetHeight() const{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string AVL::TraverseInOrder() const{
	return TraverseInOrderInternal(m_Root);
}

std::string AVL::TraverseInOrderInternal(const NodeAVL* node) const{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetFood() << "\n";
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}

NodeAVL* AVL::FindMin() const{
	return FindMinInternal(m_Root);
}

NodeAVL* AVL::FindMinInternal(NodeAVL* node) const{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeAVL* AVL::FindMax() const{
	return FindMaxInternal(m_Root);
}

NodeAVL* AVL::FindMaxInternal(NodeAVL* node) const{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeAVL* AVL::Predecessor(std::string food) const{
	NodeAVL* node = SearchInternal(m_Root, food);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeAVL* AVL::PredecessorInternal(NodeAVL* node) const{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Successor(std::string food) const{
	NodeAVL* node = SearchInternal(m_Root, food);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeAVL* AVL::SuccessorInternal(NodeAVL* node) const{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Search(std::string food) const{
  return SearchInternal(m_Root, food);
}

NodeAVL* AVL::SearchInternal(NodeAVL* node, std::string &food) const{
	if (node == nullptr)
		return nullptr;
	else if (node->GetFood() == food)
		return node;
	else if (node->GetFood() > food)
		return SearchInternal(node->GetLeft(), food);
	else
		return SearchInternal(node->GetRight(), food);
}

NodeAVL * AVL::SearchInOrder(std::string food){
  NodeAVL* busca = nullptr;
  SearchInOrderInternal(m_Root, food, busca);
  return busca;
}

void AVL::SearchInOrderInternal(NodeAVL* node, std::string &food, NodeAVL* &found){
  if (node != nullptr)
	{
		SearchInOrderInternal(node->GetLeft(), food, found);
		if(node->GetFood() == food) found = node;
		SearchInOrderInternal(node->GetRight(), food, found);
	}
}

NodeAVL* AVL::Insert(std::string food, const Alimento& data){
	if (IsEmpty())
	{
		m_Root = new NodeAVL(food, data);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, food, data);
}

NodeAVL* AVL::InsertInternal(NodeAVL* node, NodeAVL* parent, std::string food, const Alimento& data){
	if (node == nullptr)
		node = new NodeAVL(food, data, parent);
	else if (node->GetFood() == food)
		return nullptr; 
	else if (node->GetFood() > food)
		node->SetLeft(InsertInternal(node->GetLeft(), node, food, data));
	else if (node->GetFood() < food)
		node->SetRight(InsertInternal(node->GetRight(), node, food, data));

	node = Balance(node);
	return node;
}

void AVL::Remove(std::string food){
	RemoveInternal(m_Root, food);
}

NodeAVL* AVL::RemoveInternal(NodeAVL* node, std::string food){
	if (node == nullptr)
		return nullptr;
	else if (node->GetFood() == food)
		node = RemoveNode(node);
	else if (node->GetFood() > food)
		node->SetLeft(RemoveInternal(node->GetLeft(), food));
	else
		node->SetRight(RemoveInternal(node->GetRight(), food));
	
	node = Balance(node);
	return node;
}

NodeAVL* AVL::RemoveNode(NodeAVL* node){
	NodeAVL* parent = node->GetParent();

	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}

	else if (node->GetLeft() == nullptr)
	{
		NodeAVL* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}

	else if (node->GetRight() == nullptr)
	{
		NodeAVL* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
    }
	else
  {
		NodeAVL* predecessor = Predecessor(node->GetFood());

		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetFood()));
	}

	return node;
}

void AVL::UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild){
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

NodeAVL* AVL::RotateLeft(NodeAVL* node){
	if (node == nullptr) return nullptr;

	NodeAVL* newRoot = node->GetRight();
	if (newRoot == nullptr) return nullptr;

	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	NodeAVL* left = newRoot->GetLeft();
	node->SetRight(left);

	if (left != nullptr)
		left->SetParent(node);

	newRoot->SetLeft(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

NodeAVL* AVL::RotateRight(NodeAVL* node){
	if (node == nullptr) return nullptr;

	NodeAVL* newRoot = node->GetLeft();
	if (newRoot == nullptr) return nullptr;

	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	NodeAVL* right = newRoot->GetRight();
	node->SetLeft(right);

	if (right != nullptr)
		right->SetParent(node);

	newRoot->SetRight(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

NodeAVL* AVL::RotateLeftRight(NodeAVL* node){
	node->SetLeft(RotateLeft(node->GetLeft()));
	return RotateRight(node);
}

NodeAVL* AVL::RotateRightLeft(NodeAVL* node){
	node->SetRight(RotateRight(node->GetRight()));
	return RotateLeft(node);
}

NodeAVL* AVL::Balance(NodeAVL* node){
	if (node != nullptr)
	{
		node->UpdateBalanceFactor();
		int nodeBF = node->GetBalanceFactor();

		if (nodeBF == -2)
    {
			NodeAVL* left = node->GetLeft();
			left->UpdateBalanceFactor();
			int leftChildBF = left->GetBalanceFactor();

			if (leftChildBF == -1)
				node = RotateRight(node);
			else
				node = RotateLeftRight(node);
      }
		else if (nodeBF == 2)
    {
			NodeAVL* right = node->GetRight();
			right->UpdateBalanceFactor();
			int rightChildBF = right->GetBalanceFactor();

			if (rightChildBF == 1)
				node = RotateLeft(node);
			else
				node = RotateRightLeft(node);
		}
	}

	return node;
}

std::string AVL::AVLtoCSV() const{
	return AVLtoCSVInternal(m_Root);
}

std::string AVL::AVLtoCSVInternal(const NodeAVL* node) const{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << AVLtoCSVInternal(node->GetLeft());
    oss << node->GetFood() << "," << node->GetData().GetCal()
    << "," << node->GetData().GetCalFromFat()
    << "," << node->GetData().GetTotalFatg()
    << "," << node->GetData().GetTotalFatDv()
    << "," << node->GetData().GetSodiumG()
    << "," << node->GetData().GetSodiumDv()
    << "," << node->GetData().GetPotassiumG()
    << "," << node->GetData().GetPotassiumDv()
    << "," << node->GetData().GetCarbohyrateg()
    << "," << node->GetData().GetCarbohyrateDv()
    << "," << node->GetData().GetFiberg()
    << "," << node->GetData().GetFiberDv()
    << "," << node->GetData().GetSugarsg()
    << "," << node->GetData().GetProteing()
    << "," << node->GetData().GetVitADv()
    << "," << node->GetData().GetVitCDv()
    << "," << node->GetData().GetCalciumDv()
    << "," << node->GetData().GetIronDv()
    << "," << node->GetData().GetSaturatedFatDv()
    << "," << node->GetData().GetSaturatedFatmg()
    << "," << node->GetData().GetCholesterolDv()
    << "," << node->GetData().GetCholesterolmg()
    << ","<< node->GetData().GetFoodType() << "\n";
		oss << AVLtoCSVInternal(node->GetRight());
		return oss.str();
	}
  return "";
}
	