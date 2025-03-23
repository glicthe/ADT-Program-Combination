#ifndef GAME_H
#define GAME_H
#include "head.h"
#include "sll.h"
#include "queue.h"
#include "stack.h"

List activeQuests;
Queue pendingEvents;
Stack actionHistory;
Infotype event;

void InitializeGame();
void UndoLastAction();

//Main View
void GameLoop();

//fungsi tambahan
void waitForEnter();
void clearScreen();
void clearBuffer();
#endif
