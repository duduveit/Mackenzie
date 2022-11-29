/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 
*/

#include <iostream>
#include "LinkedList.h"

LinkedList* Create()
{
	LinkedList* list = new LinkedList;
	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

void Destroy(LinkedList* list)
{
	Clear(list);

	delete list;
	list = nullptr;
}

void Insert(LinkedList* list, int id, string nome)
{
	Node* node = CreateNode(id, nome, list->head, list->tail);
	
	if (IsEmpty(list))
	{
		list->tail = node;
		node->next = node->previous = node;
	}

	else
	{
		list->tail->next = node;
		list->head->previous = node;
	}

	list->head = node;
	++list->count;
}

void Append(LinkedList* list, int id, string nome)
{
	Node* node = CreateNode(id, nome, list->head, list->tail);

	if (IsEmpty(list))
	{
		list->head = node;
		
		node->next = node;
		node->previous = node;
	}
	else
	{
		list->head->previous = node;
    list->tail->next = node;
	}
	list->tail = node;

	++list->count;
}

Node* RemoveHead(LinkedList* list)
{
	if (IsEmpty(list))
	{
		return nullptr;
	}

	Node* toRemove = list->head;

	if (list->head == list->tail)
	{
		list->head = list->tail = nullptr;
    
	}
	else
	{
		list->head = list->head->next;
    list->head->previous = list->tail;
    list->tail->next = list->head;
	}
  toRemove->next = nullptr;
	toRemove->previous = nullptr;

	--list->count;

	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
	if (list->head == list->tail)
	{
		return RemoveHead(list);
	}

	Node* toRemove = list->head;
  Node* previous = nullptr;

  while (toRemove != list->tail)
  {
    previous = toRemove;
    toRemove = toRemove->next;
  }
  
  toRemove->next = toRemove->previous = nullptr;
  previous->next = list->head;
  list->head->previous = previous;

  list->tail = previous;
	--list->count;

	return toRemove;
}

Node* RemoveNode(LinkedList* list, int id)
{
	Node* toRemove = list->head;
	Node* previous = nullptr;

	while (toRemove != list->tail && toRemove->id != id)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	if (toRemove == list->head)
	{
		return RemoveHead(list);
	}
	else if (toRemove == list->tail)
	{
		return RemoveTail(list);
	}
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;
		toRemove->next->previous = previous;
		toRemove->next = nullptr;
		toRemove->previous = nullptr;

		--list->count;

		return toRemove;
	}

	return nullptr;
}

int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
  if (Count(list) == 0) return true;
  else return false;
  };

void Clear(LinkedList* list)
{
	if (list->head != nullptr)
	{

		Node* node;	
		Node* atual = list->head->next;
		
		while (atual != list->head)
		{
			node = atual->next;	
			DestroyNode(atual);
			atual = node;
		
		list->head = list->tail = nullptr;
		atual = node = nullptr;
		list->count = 0;
		}
	}
}

Node* CreateNode(int id, string nome, Node* next, Node* previous)
{
	Node* node = new Node;
	node->id = id;
	node->nome = nome;
	node->next = next;
	node->previous = previous;
	
	return node;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}