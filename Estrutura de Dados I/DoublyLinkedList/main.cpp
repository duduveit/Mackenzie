/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 

    Referências usadas para auxiliar o código: 
    Materiais do professor 
*/

#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	Node* temp = list->head;
	int count = 0; 
	while (count != list->count)
	{
		cout << '[' <<temp->id << ']' << ' ' << temp->nome << '\n';
    temp = temp->next;
    ++count;
	}
  cout << '\n';
}   


void PrintReverse(const LinkedList* list)
{
	Node* temp = list->tail;
	int j = 0; 
	while (j != list->count)
	{
		cout << '[' << temp->id << ']' << ' ' << temp->nome << '\n';
    temp = temp->previous;
    j++;
	}
  cout << '\n';
}   


void PrintDoubleListInfo(const LinkedList* list)
{
    if (IsEmpty(list))
    {
        cout << "Lista vazia!\n";
    }
    else
    {
        cout << "Lista:\n";
        Print(list);
        cout << "Lista invertida:\n";
        PrintReverse(list);
    }
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    
    cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List) ***\n";
    
    LinkedList* list = Create();
    PrintDoubleListInfo(list);
    
    Insert(list, 1, "Carol");
    Insert(list, 2, "Eric");
    Insert(list, 3, "John");
    Append(list, 4, "Leo");
    Append(list, 5, "Julia");
    Append(list, 6, "Lisa");
    PrintDoubleListInfo(list);
    
    Clear(list);
    PrintDoubleListInfo(list);
    
    Insert(list, 11, "Paulo");
    Append(list, 22, "Thomas");
    Insert(list, 33, "Olga");
    Append(list, 44, "Bia");
    Insert(list, 55, "Angela");
    Append(list, 66, "Karen");
    Insert(list, 77, "Adauto");
    PrintDoubleListInfo(list);
    
    Node* temp = RemoveNode(list, 44);
    cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
    DestroyNode(temp);
    PrintDoubleListInfo(list);

    temp = RemoveHead(list);
    cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
    DestroyNode(temp);
    PrintDoubleListInfo(list);
    
    temp = RemoveTail(list);
    cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
    DestroyNode(temp);
    PrintDoubleListInfo(list);
    
    Destroy(list);
    
    cout << "Fim.\n";
    
}
