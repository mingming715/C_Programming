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
void printQueue(QUEUE* queue);

int main(void)
{
    QUEUE* queue_main;
    queue_main = (QUEUE *)malloc(sizeof(QUEUE));
    queue_main->count = 0;
    queue_main->front = NULL;
    queue_main->rear = NULL;
    int sangtae;
    char dataIn[10];
    while(1)
    {
        printf("Enter a command : ");
        scanf("%s", dataIn);
        if(strcmp(dataIn, "help")==0 || strcmp(dataIn, "dir")==0 || strcmp(dataIn, "mkdir")==0 || strcmp(dataIn, "cd")==0)
        {
            enqueue(queue_main, dataIn);
        }
        else if(strcmp(dataIn, "history")==0 || strcmp(dataIn, "h")==0)
        {
            printQueue(queue_main);

        }
        else if(strcmp(dataIn, "quit")==0 || strcmp(dataIn, "q")==0)
        {
            return 0;
        }
        else
        {
            printf("[%s] is invalid command!!\n", dataIn);
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

void printQueue(QUEUE *queue)
{
    QUEUE_NODE* ptr;
    int size=0;
    ptr = queue->front;
    size = queue->count;
    printf("queue count : %d\n", size);
    for(int i=0; i<size; i++)
    {
        printf("%s\n", ptr->command);
        ptr=ptr->next;
    }
}
