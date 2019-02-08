#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int count;
	struct node* top;
}STACK;

typedef struct node {
	char data;
	struct node* link;
}STACK_NODE;

void push(STACK* pStack, char ch) {
    STACK_NODE *pNew;

    pNew = (STACK_NODE*)malloc(sizeof(STACK_NODE));

    pNew->data = ch;
    pNew->link = pStack->top;
    pStack->top = pNew;
    pStack->count++;

    return;
}

int pop(STACK* pStack, char* ch) {
    STACK_NODE *pDlt;

    if(pStack->top)
    {
        *ch = pStack->top->data;
        pDlt = pStack->top;
        pStack->top = (pStack->top)->link;
        pStack->count--;
        free(pDlt);

        return 1;
    }
    else
    {
        return 0;
    }
	// TODO: remove an item from the stack
    // Before removing an item, check if stack is empty
}

int empty(STACK* pStack) {
    if(pStack->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
	// TODO: empty the stack
}

int solve(const char* str) {
	STACK* pStack = (STACK*)calloc(1, sizeof(STACK));
	pStack->top = NULL;
	pStack->count = 0;
	char ch = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			push(pStack, str[i]);
		}
		else {
			if (empty(pStack)) {
				free(pStack);
				return 0;
			}
			pop(pStack, &ch);
		}
	}
	int ans = empty(pStack);
	
    //free all nodes in pStack
	STACK_NODE* del = pStack->top;
    STACK_NODE* temp = NULL;
	while (del) {
		temp = del;
		del = del->link;
		free(temp);
	}
	free(pStack);
	return ans;
}

int main(void) {
	int T;
	char str[101];

	scanf("%d", &T);
	getchar();

    while (T--) {
		scanf("%s", str);
		if (solve(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
    return 0;
}
