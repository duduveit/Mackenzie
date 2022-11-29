/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 
*/

#include "LinkedList.h"
#include <iostream>

LinkedList* Create()
{
	LinkedList* list = new LinkedList;
	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr; 
	return list;
};

Node* CreateNode(int value)
{
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = nullptr;
  return new_node;
};

void Insert(LinkedList* list, int value)
{
	Node* new_node = CreateNode(value);
  
  new_node->data = value;
  new_node->next = list->head;
  if (IsEmpty(list)) list->tail = new_node;
  list->head = new_node;
  list->count ++;
};  

void Append(LinkedList* list, int value)
{
	Node* new_node = CreateNode(value);
  
  new_node->data = value;
  new_node->next = nullptr;
  if (IsEmpty(list)) list->head = new_node;
  else list->tail->next =  new_node;
  list->tail = new_node;
  list->count ++;
};

Node* RemoveHead(LinkedList* list)
{
  if (IsEmpty(list) == true) return nullptr;
  Node* toRemove = list->head;
  if (list->head == list->tail)
  {
    list->head = nullptr;
    list->tail = nullptr;
  }
  else list->head = list->head->next;
  list->count --;
  toRemove->next = nullptr;
  return toRemove;
};

Node* RemoveTail(LinkedList* list)
{
	if(list->count == 1) return RemoveHead(list);
  Node* toRemove = list->head;
  Node* previous = nullptr;
  while (toRemove != list->tail)
  {
    previous = toRemove;
    toRemove = toRemove->next;
  }
  previous->next = nullptr;
  list->tail = previous;
  list->count --;
  toRemove->next = nullptr;
  return toRemove;
};

Node* RemoveNode(LinkedList* list, int value)
{
  Node* toRemove = list->head;
  Node* previous = nullptr;
  while(toRemove != nullptr && toRemove->data != value)
  {
    previous = toRemove;
    toRemove = toRemove->next;
  }
  if (toRemove == nullptr) return NULL;
  else if (toRemove == list->head) return RemoveHead(list);
  else if (toRemove == list->tail) return RemoveTail(list);
  else
  {
    previous->next = toRemove->next;
    list->count --;
    toRemove->next = nullptr;
    return toRemove;
  }
};

int Count(const LinkedList* list)
{
  return list->count;
};


bool IsEmpty(const LinkedList* list)
{
  if (Count(list) == 0) return true;
  else return false;
  };

void Clear(LinkedList* list)
{
	Node* node = new Node();
  Node* next = new Node();
  node = list->head;
  next = nullptr;
  while (node!=nullptr)
  {
    next = node->next;  
    delete node;    
    node = next; 
  }
  list->head = nullptr;
  list->tail = nullptr;
  list->count = 0;
};

void Destroy(LinkedList* list)
{
	Clear(list);
  delete list;
};