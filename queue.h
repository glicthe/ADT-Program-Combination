#ifndef QUEUE_H
#define QUEUE_H

#include "sll.h"

typedef List Queue;

void CreateQueue(Queue *Q);
void Enqueue(Queue *Q, Infotype X);
void Dequeue(Queue *Q, Infotype *X);
boolean isQueueEmpty(Queue Q);

void DisplayQueue(Queue Q);
void AddEvent(Queue *Q);

#endif
