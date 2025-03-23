#ifndef STACK_H
#define STACK_H

#include "sll.h"

typedef List Stack;

void Push(Stack *S, Infotype X);
Infotype Pop(Stack *S);
boolean isStackEmpty(Stack S);

#endif
