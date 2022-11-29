/*  Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 */

#include "pilha.h"
#include <iostream>
#include <locale.h>

Stack Create() 
{
    Stack stack = {
        {'\0'}, 
        0
    };
    return stack;
}

bool Push(Stack &stack, char value)
{
    if (IsEmpty(stack) == true) 
    {
        stack.caracteres[stack.topo] = value; 
        stack.topo++; 
        return true;
    }

    else if(Count(stack) < Size(stack)) 
    {
        stack.caracteres[stack.topo] = value; 
        stack.topo++;
        return true;
    }

    else
    {
        return false;
    }
}

char Pop(Stack &stack)
{
    if (IsEmpty(stack) == false) 
    {
        char auxiliar = stack.caracteres[stack.topo-1];
        stack.caracteres[stack.topo] = '\0';
        stack.topo--;
        return auxiliar;    
    }
    
    else
    {
        return '\0';
    }
}

char Top(const Stack &stack)
{
    if (IsEmpty(stack)) 
    {
        return '\0';
    }
        
    else
    {
        return IsEmpty(stack) ? '\0' : stack.caracteres[stack.topo-1]; 
        
    }
}

int Size(const Stack &stack)
{
  	return sizeof(stack.caracteres) / sizeof(stack.caracteres[0]);
}

int Count(const Stack &stack)
{
  return stack.topo;
}

bool IsEmpty(const Stack &stack)
{
  return stack.topo == 0;
}

void Clear(Stack &stack) 
{
    while (IsEmpty(stack) == false)
    {
        Pop(stack);
    }
}

void PrintTopCountSize(const Stack &stack) 
{
    char top = Top(stack);
    if (top == '\0')
        std::cout << "Topo: Pilha vazia.\n";
    else
        std::cout << "Topo: " << top << '\n';
    std::cout << "Elementos na pilha: " << Count(stack) << '/' << Size(stack)
        << ", a pilha " << (IsEmpty(stack) ? "está vazia" : "contêm elementos") << ".\n";
}

int main() 
{   
    setlocale(LC_CTYPE, "Portuguese");
    Stack stack = Create();
    PrintTopCountSize(stack);

    std::cout << "--------------------\n";
    std::string str = "Hello, World!";
    for (int i = 0; i < str.length(); i++)
    {
        
        Push(stack, str[i]);
        
        PrintTopCountSize(stack);
    }
    std::cout << "--------------------\n";
    char top;
    while (!IsEmpty(stack))
    {
        top = Pop(stack);
        std::cout << "Pop retornou: " << top << '\n';
        PrintTopCountSize(stack);
    }
    std::cout << "--------------------\n";
    for (const char& c : str)
        Push(stack, c);
    PrintTopCountSize(stack);

    std::cout << "--------------------\n";
    Clear(stack);
    PrintTopCountSize(stack);
}