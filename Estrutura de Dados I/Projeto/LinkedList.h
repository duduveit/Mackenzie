#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <iostream>

using namespace std;

struct Node
{
	string disciplina;
	string isbn;
	string titulo;
	string autor;
	string edicao;
	string cidade;
	string editora;
	string ano;
	string complementar;
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
void Append(LinkedList* list, string disciplina, string isbn, string titulo, string autor, string edicao, string cidade, string editora, string ano, string complementar);
Node* RemoveHead(LinkedList* list);
Node* RemoveTail(LinkedList* list);
Node* RemoveNode(LinkedList* list, string isbn); 
Node* GetHead(const LinkedList* list);
Node* GetTail(const LinkedList* list);
Node* GetNode(const LinkedList* list, string isbn);
int Count(const LinkedList* list);
bool IsEmpty(const LinkedList* list);
void Clear(LinkedList* list);
Node* CreateNode(string disciplina, string isbn, string titulo, string autor, string edicao, string cidade, string editora, string ano, string complementar, Node* next);
void DestroyNode(Node* node);
#endif //  __LINKED_LIST_H__