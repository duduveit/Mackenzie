#include "LinkedList.h"
using namespace std;

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

void Append(LinkedList* list, string disciplina, string isbn, string titulo, string autor, string edicao, string cidade, string editora, string ano, string complementar)
{
	Node* node = CreateNode(disciplina, isbn, titulo, autor, edicao, cidade, editora, ano, complementar, nullptr);

	if (IsEmpty(list))
	{
		list->head = node;
	}
	else
	{
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
	}

	--list->count;

	toRemove->next = nullptr;	
	return toRemove;
}
int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}

void Clear(LinkedList* list)
{
	Node* node = list->head;
	Node* next = nullptr;

	while (node != nullptr)
	{
		next = node->next;
		DestroyNode(node);
		node = next;
	}

	list->head = list->tail = nullptr;
	list->count = 0;
}

Node* CreateNode(string disciplina, string isbn, string titulo, string autor, string edicao, string cidade, string editora, string ano, string complementar, Node* next)
{
	Node* node = new Node;
	node->disciplina = disciplina;
	node->isbn = isbn;
	node->titulo = titulo;
	node->autor = autor;
	node->edicao = edicao;
	node->cidade = cidade;
	node->editora = editora;
	node->ano = ano;
	node->complementar = complementar;
	node->next = next;

	return node;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}
