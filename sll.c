#include "sll.h"

void CreateList(List *L) {
    first(*L) = NULL;
}

void Ins_Akhir(List *L, Infotype X) {
    address newNode = (address)malloc(sizeof(struct Node));
    info(newNode) = X;
    next(newNode) = NULL;

    if (first(*L) == NULL) {
        first(*L) = newNode;
    } else {
        address current = first(*L);
        while (next(current) != NULL) {
            current = next(current);
        }
        next(current) = newNode;
    }
}

void Del_Awal(List *L, Infotype *X) {
    if (first(*L) == NULL) {
        X->data = - 1;
        return;
    }
    address temp = first(*L);
    *X = info(temp);
    first(*L) = next(temp);
    free(temp);
}

boolean Search(List L, int questID) {
    address current = first(L);
    while (current != NULL) {
        if (data(current) == questID) return true;
        current = next(current);
    }
    return false;
}

void Ins_Awal(List *L, Infotype X){
	address newNode = (address)malloc(sizeof(struct Node));
	info(newNode) = X;
    next(newNode) = first(*L);
    first(*L) = newNode;
}

Infotype Del_AwalPop(List *L){
	Infotype error = {-1, -1};
    if (first(*L) == NULL) return error;

    address temp = first(*L);
    Infotype data = info(temp);
    first(*L) = next(temp);
    free(temp);
    return data;
}

/**************************************************
*****************Quests Feature********************
**************************************************/
void DisplayQuests(List L) {
    address current = first(L);
    if (current == NULL) printf("+++++No Quests Active!!!+++++\n");
    while (current != NULL) {
        printf("Quest %d\n", info(current).data);
        current = next(current);
    }
}

void Del_Quest(List *L, Infotype *X, int questID) {
    if (first(*L) == NULL) {
        X->data = -1; 
        return;
    }

    address prev = NULL;
    address current = first(*L);

    // Traverse to find the quest
    while (current != NULL && data(current) != questID) {
        prev = current;
        current = next(current);
    }

    if (current == NULL) {
        X->data = -1; // Quest not found
        return;
    }

    // Update pointers
    if (prev == NULL) {
        first(*L) = next(current); // Delete from front
    } else {
        next(prev) = next(current);
    }

    *X = info(current);
    free(current);
}
