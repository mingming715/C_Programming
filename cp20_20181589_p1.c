#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
    int height;
    struct _NODE* link;
}NODE;

NODE *insertNode(NODE *pList, int height);
void printAll(NODE *pList);

int main(void)
{
    int n;
    int new_height;
    printf("Enter the number of students : ");
    scanf("%d", &n);

    NODE *pList;
    pList = NULL;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &new_height);
        pList = insertNode(pList, new_height);
    }
    printAll(pList);
    printf("\n");

    return 0;
}

NODE *insertNode(NODE *pList, int height)
{
    NODE *pNew;
    pNew = malloc(sizeof(NODE));
    
    pNew->link = NULL;
    pNew->height = height;
    
    NODE *pCur;
    NODE *pPre;
    if(pList == NULL)
    {
        pList = pNew;
    }
    else
    {
        if(height < pList->height)
        {
            pNew->link = pList;
            pList = pNew;
        }
        else
        {
            pCur = pList;
            pPre = pCur;
            while(pCur != NULL)
            {
                if(pCur->height > height)
                {
                    break;
                }
                pPre = pCur;
                pCur = pCur->link;
            }
            pPre->link = pNew;
            pNew->link = pCur;
        }
    }
    return pList;
}

void printAll(NODE *pList)
{
    while(pList!=NULL)
    {
        printf("%d ", pList->height);
        pList = pList->link;
    }
}
