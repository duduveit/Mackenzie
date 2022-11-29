/*  Identificação dos alunos 
    Eduardo Veit Ferrão, 32150180 
    Leonardo Biagiotti Beloti, 32160062 */

#ifndef __PILHA_H__
#define __PILHA_H__

#include <iostream>

struct Stack 
{
    char caracteres[4096];
    int topo;
};

Stack Create();

bool Push(Stack &stack, char value);

char Pop(Stack &stack);

char Top(const Stack &stack);

int Size(const Stack &stack);

int Count(const Stack &stack);

bool IsEmpty(const Stack &stack);

void Clear(Stack &stack);

#endif