// Game State
#include <stdio.h>
#include "head.h"
#include "sll.h"
#include "queue.h"
#include "stack.h"
#include "game.h"


void InitializeGame() {
    CreateList(&activeQuests);
    CreateQueue(&pendingEvents);
    
    Enqueue(&pendingEvents, (Infotype){0, 101});
    Enqueue(&pendingEvents, (Infotype){0, 102});
}

void UndoLastAction() {
    if (isStackEmpty(actionHistory)) {
        printf("+++++Nothing to undo!+++++\n");
        return;
    }
    
    Infotype lastAction = Pop(&actionHistory);
    switch (lastAction.action) {
        case 1: 
            printf("+++++Undoing quest %d...+++++\n", lastAction.data);
            break;
        case 2:
            printf("+++++Re-queuing event %d...+++++\n", lastAction.data);
            Enqueue(&pendingEvents, lastAction);
            break;
    }
}

/**************************************************
*******************Main View***********************
**************************************************/
void GameLoop() {
    int choice;
    while (1) {
        printf("\n--- Quest Manager ---\n");
        printf("1. View Active Quests\n");
        printf("2. Accept New Quest\n");
        printf("3. Complete a Quest\n"); 
        printf("4. Add New Event\n");
        printf("5. View Pending Events\n");   
        printf("6. Process Next Event\n");
        printf("7. Undo Last Action\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clearBuffer();
        
        switch (choice) {
            case 1: 
                DisplayQuests(activeQuests);
                waitForEnter();
                break;
            case 2: {
                int questID;	
                printf("Enter quest ID: ");
                scanf("%d", &questID);
                clearBuffer();
                Infotype newQuest = {1, questID};
                Ins_Akhir(&activeQuests, newQuest);
                Push(&actionHistory, newQuest);
                waitForEnter();
                break;
           	}
           	case 3: {
           		int questID;
                Infotype completedQuest;
                DisplayQuests(activeQuests);
                printf("Enter Quest ID to complete: ");
                scanf("%d", &questID);
                Del_Quest(&activeQuests, &completedQuest, questID);
                if (completedQuest.data != -1) {
                    printf("Quest %d completed!\n", questID);
                    Push(&actionHistory, (Infotype){3, questID}); // Track for undo
                } else {
                    printf("Quest not found!\n");
                }
                break;
			}
            case 4: {
            	AddEvent(&pendingEvents);
            	waitForEnter();
                break;
           	}
           	case 5:
           		DisplayQueue(pendingEvents);
                waitForEnter();
				break;
                
 			case 6:
                Dequeue(&pendingEvents, &event);
                if (event.data != -1) {
                    Push(&actionHistory, (Infotype){2, event.data});
                }
                waitForEnter();
                break;
            case 7:
            	UndoLastAction();
            	waitForEnter();
                break;
            case 8:
            	exit(0);
            default:
                printf("+++++Invalid choice!+++++\n");
        }
        clearScreen();
    }
}

/**************************************************
*************For Cleareing Screen******************
**************************************************/
// Menunggu user untuk menekan Enter untuk lanjut
void waitForEnter() {
    printf("\nPress Enter To Continue...");
	getchar();
}

// Untuk Clear Buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Membersihkan layar
void clearScreen() {
    system("cls || clear");
}
