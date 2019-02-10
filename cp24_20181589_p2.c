#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char command[10];
    struct node* next;
}QUEUE_NODE;

typedef  struct {
    QUEUE_NODE *front;
    int count;
    QUEUE_NODE *rear;
}QUEUE;

void enqueue(QUEUE* queue, char* data);
int DequeuePrint(QUEUE* queue, char* dataOut);

int main(void)
{
    QUEUE* queue_main;
    queue_main = (QUEUE *)malloc(sizeof(QUEUE));
    queue_main->count = 0;
    queue_main->front = NULL;
    queue_main->rear = NULL;
    int sangtae;
    char dataIn[10];
    char dataOut[10];
    while(1)
    {
        printf(">>");
        scanf("%s", dataIn);
        if(strcmp(dataIn, "help")==0 || strcmp(dataIn, "dir")==0 || strcmp(dataIn, "mkdir")==0 || strcmp(dataIn, "cd")==0)
        {
            printf("[Valid] %s\n", dataIn);
            enqueue(queue_main, dataIn);
        }
        else if(strcmp(dataIn, "history")==0 || strcmp(dataIn, "h")==0)
        {
            while(DequeuePrint(queue_main, dataOut)==1)
            {
                printf("%s\n", dataOut);
            }

        }
        else if(strcmp(dataIn, "quit")==0 || strcmp(dataIn, "q")==0)
        {
            return 0;
        }
        else
        {
            printf("[Invalid]\n");
            continue;
        }
    }       
}

void enqueue(QUEUE* queue, char* data)
{
    QUEUE_NODE* newPtr;
    newPtr = malloc(sizeof(QUEUE_NODE));

    strcpy(newPtr->command, data);
    newPtr->next = NULL;

    if(queue->count == 0)
    {
        queue->front = newPtr;
    }
    else
    {
        queue->rear->next = newPtr;
    }
    (queue->count)++;
    queue->rear = newPtr;

    return;
}

int DequeuePrint(QUEUE* queue, char* dataOut)
{
    QUEUE_NODE* deleteLoc;

    if(queue->count == 0)
    {
        return 0;
    }
    strcpy(dataOut, queue->front->command);
    deleteLoc = queue->front;
    if(queue->count == 1)
    {
        queue->rear = queue->front = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }
    (queue->count)--;
    free(deleteLoc);

    return 1;
}
