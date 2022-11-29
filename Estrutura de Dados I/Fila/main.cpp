#include <iostream>
#include "fila.h"
#include <locale.h>

Queue Create() 
{
    Queue queue = {
        {'\0'}, 
        0,
        0,
        0
    };
    return queue;
}

bool Enqueue(Queue &queue, char value)
{
    if (IsEmpty(queue) == true) 
    {
        int N = Size(queue);
        queue.caracteres[queue.rear] = value; 
        queue.rear++;
        queue.count++;
        return true;
    }

    else if(Count(queue) < Size(queue)) 
    {
        int N = Size(queue);
        queue.caracteres[queue.rear] = value; 
        queue.rear++;
        queue.count++;
        return true;
    }

    else
    {
        return false;
    }
}

char Dequeue(Queue &queue)
{
    if (IsEmpty(queue) == false) 
    {
        char auxiliar = queue.caracteres[queue.front-1];
        queue.caracteres[queue.front] = '\0';
        queue.front--;
        return auxiliar;    
    }
    
    else
    {
        return '\0';
    }
}

char Front(const Queue &queue)
{
    if (IsEmpty(queue)) 
    {
        return '\0';
    }
        
    else
    {
        return queue.caracteres[queue.front-1]; 
    }
}

int Size(const Queue &queue)
{
    int length = sizeof(queue.caracteres) / sizeof(queue.caracteres[0]);
    return length;
}

int Count(const Queue &queue)
{
    return queue.count;
}

bool IsEmpty(const Queue &queue)
{
    if (queue.front == '\0')
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Clear(Queue &queue)
{
    while (IsEmpty(queue) == false)

    {
        Dequeue(queue);
    }
}



void PrintFrontCountSize(const Queue& queue)
{
    char front = Front(queue);
    if (front == '\0')
        std::cout << "Frente: Fila vazia.\n";
    else
        std::cout << "Frente: " << front << '\n';
    std::cout << "Elementos na fila: " << Count(queue) << '/' << Size(queue)
        << ", a fila " << (IsEmpty(queue) ? "está vazia" : "contém elementos") << ".\n";
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    Queue queue = Create();
    PrintFrontCountSize(queue);
    
    std::cout << "--------------------\n";
    std::string str = "Queue Hello, World!";
    for (int i = 0; i < str.length(); ++i)
    {
        if (!Enqueue(queue, str[i]))
            std::cout << "Fila cheia! Não foi possível inserir " << str[i] << '\n';
        PrintFrontCountSize(queue);
    }
    std::cout << "--------------------\n";
    char front;
    while (!IsEmpty(queue))
    {
        front = Dequeue(queue);
        std::cout << "Dequeue retornou: " << front << '\n';
        PrintFrontCountSize(queue);
    }
 
    std::cout << "--------------------\n";
    for (const char& c : str)
    {
        if (!Enqueue(queue, c))
            std::cout << "Fila cheia! Não foi possível inserir " << c << '\n';
    }
    PrintFrontCountSize(queue);
 
    std::cout << "--------------------\n";
    Clear(queue);
    PrintFrontCountSize(queue);
}