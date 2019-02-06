#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *LINK;
} NODE;

NODE *head = NULL;

void InsertNodeAtFront(char a){
    NODE *pNew;
    pNew = malloc(sizeof(NODE));
    
    pNew->LINK = NULL;
    pNew->Data = a;

    if(head == NULL)
    {
        head = pNew;
    }
    else
    {
        pNew->LINK = head;
        head = pNew;
    }
}

void InsertNodeAtBack(char b){
	NODE *pNew;
    NODE *pCheck;
    pNew = malloc(sizeof(NODE));

    pCheck = head;

    pNew->LINK = NULL;
    pNew->Data = b;

    if(head == NULL)
    {
        head = pNew;
    }
    else
    {
        while(pCheck->LINK != NULL)
        {
            pCheck = pCheck->LINK;
        }
        pCheck->LINK = pNew;
    }
}

void PrintList(){
	NODE *ptr;
    ptr = head;

    while(ptr!=NULL)
    {
        printf("%c", ptr->Data);
        ptr = ptr->LINK;
    }
    printf("\n");
}

void DeleteNodeAtFront(){
	NODE *pCur;
    pCur = head;

    head = pCur->LINK;
    free(pCur);
}

void DeleteNodeAtBack(){
	NODE *pPre;
    NODE *pCur;
    
    pCur = pPre = head;

    while(pCur->LINK != NULL)
    {
        pPre = pCur;
        pCur = pCur->LINK;
    }
    pPre->LINK = pCur->LINK;
    free(pCur);
}

void main()
{
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();
	head = NULL;
	InsertNodeAtFront('n');
	InsertNodeAtFront('e');
	InsertNodeAtFront('p');
	InsertNodeAtBack('l');
	InsertNodeAtFront('o');
	InsertNodeAtBack('a');
	InsertNodeAtBack('b');
	PrintList();
	DeleteNodeAtFront();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	PrintList();
}
