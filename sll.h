#ifndef SLL_H
#define SLL_H

#include "head.h"

// Node structure
typedef struct Node {
    Infotype info;
    address next;
};

typedef struct {
    address first;
} List;

// SLL Functions
void CreateList(List *L);
void Ins_Akhir(List *L, Infotype X);
void Del_Awal(List *L, Infotype *X);
void Ins_Awal(List *L, Infotype X);
Infotype Del_AwalPop(List *L);

boolean Search(List L, int questID);
void DisplayQuests(List L);
void Del_Quest(List *L, Infotype *X, int questID);

#endif
