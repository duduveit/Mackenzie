/*  Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 */

#ifndef __FILA_H__
#define __FILA_H__

#include <iostream>

struct Queue
{
    char caracteres[16];
    int front, rear, count;
};

Queue Create();

bool Enqueue(Queue &queue, char value);

char Dequeue(Queue &queue);

char Front(const Queue &queue);

int Size(const Queue &queue);

int Count(const Queue &queue);

bool IsEmpty(const Queue &queue);

void Clear(Queue &queue);

#endif