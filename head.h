#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>

// Define boolean type
typedef enum { false, true } boolean;

// Unified data type 
typedef struct {
    int action;  
    int data;    
} Infotype;

typedef struct Node *address;
// Accessor macros for all structures
#define first(L)    (L).first
#define next(P)     (P)->next
#define info(P)     (P)->info
#define action(P)   (info(P).action)
#define data(P)     (info(P).data)


#endif
