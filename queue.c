#include "queue.h"

/**************************************************
***************Main Queue Feature******************
**************************************************/
void CreateQueue(Queue *Q) {
    CreateList(Q);
}

void Enqueue(Queue *Q, Infotype X) {
    Ins_Akhir(Q, X);
}

void Dequeue(Queue *Q, Infotype *X) {
    Del_Awal(Q, X);
}

boolean isQueueEmpty(Queue Q) {
    return (first(Q) == NULL);
}


/**************************************************
*****************Events Feature********************
**************************************************/

// menampilkan semua events di dalam queue
void DisplayQueue(Queue Q) {
    if (isQueueEmpty(Q)) {
        printf("+++++No pending events!+++++\n");
        return;
    }

    printf("Pending Events:\n");
    address current = first(Q);
    while (current != NULL) {
        printf("[Event %d] ", data(current));
        // deskripsi untuk events
        switch (info(current).data) {
            case 101: printf("Monster Attack\n"); break;
            case 102: printf("Treasure Found\n"); break;
            case 103: printf("NPC Dialogue\n"); break;
            default: printf("Unknown Event\n");
        }
        current = next(current);
    }
}

void AddEvent(Queue *Q) {
    int eventID;
    printf("Enter Event ID (101, 102, or 103): ");
    scanf("%d", &eventID);
    Enqueue(Q, (Infotype){0, eventID});  // '0' menandai itu adalah event
}
