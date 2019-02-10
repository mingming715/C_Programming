#include <stdio.h>
#include <stdlib.h>
#define N_DAYS 31

typedef struct _DAY {
    int date;
    struct _DAY *next;
} DAY_NODE;

DAY_NODE *head;

void initCal();
void printCal();
int delDate(int);

int main() {
    int inp;

    initCal();
    printCal();

    printf(">>> Date to destroy: ");
    scanf("%d", &inp);
    while(inp > 0 && inp <= N_DAYS) {
        if(delDate(inp))
            printCal();
        else
            printf(">>> Date not found!\n");
        if(!head) {
            printf(">>> Calendar is destroyed...!\n");
            return 0;
        }
        printf(">>> Date to destroy: ");
        scanf("%d", &inp);
    }
    printCal();
    printf(">>> Calendar survived!\n");
    return 0;
}

void printCal() {
    int curDate = 1;
    DAY_NODE *iter = head;

    printf("----------------------\n");
    printf("  S  M  T  W  T  F  S\n");
    while(iter) {
        if(iter->date == curDate) {
            printf(" %2d%s", iter->date, iter->date % 7 ? "" : "\n");
            iter = iter->next;
        }
        else {
            printf("%s", curDate % 7 ? "   " : "\n");
        }
        curDate++;
    }
    printf("\n");
    printf("----------------------\n");
}

void initCal() {
    int i;
    DAY_NODE *iter;

    head = (DAY_NODE*) malloc(sizeof(DAY_NODE));
    head->date = 1;
    head->next = NULL;
    iter = head;

    for(int i = 2; i <= N_DAYS; i++) {
        iter->next = (DAY_NODE*) malloc(sizeof(DAY_NODE));
        iter = iter->next;
        iter->date = i;
        iter->next = NULL;
    }
}

int delDate(int target) {
    /// TODO : delete node with date TARGET and return 1 if success, else 0
    return 1;
}
