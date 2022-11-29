/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 
*/

#ifndef __LISTA_LIGADA_H__
#define __LISTA_LIGADA_H__
struct Node
{
	int data;
	Node* next;	
};
struct LinkedList
{
    int count;
    Node* head;
    Node* tail;
};

LinkedList* Create();

void Destroy(LinkedList* list);
void Insert(LinkedList* list, int value);
void Append(LinkedList* list, int value);
Node* RemoveHead(LinkedList* list);
Node* RemoveTail(LinkedList* list);
Node* RemoveNode(LinkedList* list, int value);
int Count(const LinkedList &list);
bool IsEmpty(const LinkedList* list);
void Clear(LinkedList* list);

#endif