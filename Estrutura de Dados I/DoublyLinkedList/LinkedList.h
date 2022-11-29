/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
using namespace std;

struct Node
{
	int id;
	string nome;
	Node* next	;
	Node* previous;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();
void Destroy(LinkedList* list);
void Insert(LinkedList* list, int id, string nome);
void Append(LinkedList* list, int id, string nome);
Node* RemoveHead(LinkedList* list);
Node* RemoveTail(LinkedList* list);
Node* RemoveNode(LinkedList* list, int id); 
int Count(const LinkedList* list);
bool IsEmpty(const LinkedList* list);
void Clear(LinkedList* list);

Node* CreateNode(int id, string nome, Node* next, Node* prev);
void DestroyNode(Node* node);

#endif //  __LINKED_LIST_H__