#include "stack.h"
#include "sll.h"

void Push(Stack *S, Infotype X) {
    Ins_Awal(S, X);
}

Infotype Pop(Stack *S) {
    Del_AwalPop(S);
}

boolean isStackEmpty(Stack S) {
    return (first(S) == NULL);
}
