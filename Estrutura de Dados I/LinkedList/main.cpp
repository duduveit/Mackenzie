/*  
    Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 
*/

/*  
    Referências usadas para auxiliar o código: 
    Monitoria (Ricardo Carvalho Ribeiro)
    Materiais do professor 
*/

#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
  Node* temp = list->head;
  while (temp != nullptr)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << '\n';
}

void PrintListInfo(const LinkedList* list)
{
    if (IsEmpty(list))
    {
       cout << "Lista vazia!\n";
    }
    else
    {
        cout << "Lista: ";
        Print(list);
    }
}
  
int main()
{
 setlocale(LC_CTYPE, "Portuguese");
  cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
 
 LinkedList* list = Create();
 
 PrintListInfo(list);

 Insert(list, 1);
 Insert(list, 2);
 Insert(list, 3);
  
 Append(list, 4);
 Append(list, 5);
 Append(list, 6);
 PrintListInfo(list);
 Clear(list);
 PrintListInfo(list);
 
 Insert(list, 77);
 Append(list, 88);
 Insert(list, 99);
 Append(list, 3);
 Insert(list, 2);
 Append(list, 1);
 Insert(list, 0);
 PrintListInfo(list);
 
  
 Node* temp = RemoveNode(list, 3);
 
 cout << "Nó removido: " << temp->data << '\n';
 delete temp;
 PrintListInfo(list);
 
 temp = RemoveHead(list);
 cout << "Nó removido: " << temp->data << '\n';
 delete temp; 
 PrintListInfo(list);

 temp = RemoveTail(list);
 cout << "Nó removido: " << temp->data << '\n';
 delete temp;
 PrintListInfo(list);
 
 Destroy(list);
 
 cout << "Fim.\n";
}