#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 11

typedef char BANK;          // 은행 이름
typedef unsigned ACCNUM;    // 계좌 번호
typedef char OWNER;         // 예금주 (계좌 주인)
typedef long BALANCE;       // 잔액
typedef enum {
    REGULAR, VIP
} MEMBER;                   // 우대 여부

typedef struct {
    BANK *bkName;
    ACCNUM accNum;
    OWNER *owner;
    BALANCE bal;
    MEMBER mem;
} ACCOUNT;

ACCOUNT acc[10];    // 계좌 배열 (최대 10개로 고정)
int accCnt = 0;     // 계좌 개수

void printAcc();
void createAcc(BANK* bName, OWNER* oName, BALANCE bal, MEMBER status);
void transaction(int from, int to, BALANCE amount);

int main() {
    int op, from, to, v;
    BANK str1[STR_SIZE];    // 은행 이름 입력받은 배열
    OWNER str2[STR_SIZE];   // 예금주 이름 입력받을 배열
    BALANCE am;             // 금액
    srand(time(NULL));      // seed 값 설정

    for(int i=0; i<10; i++)
    {
        acc[i].bkName = (char *)malloc(10*sizeof(char));
        acc[i].owner = (char *)malloc(10*sizeof(char));
    }

    while(1) {

        printf("1. Print accounts\n");
        printf("2. Create account\n");
        printf("3. Make transaction\n");
        printf("Otherwise, EXIT\n");
        printf("Select option: ");
        scanf("%d", &op);

        switch(op) {
            case 1: // Print
                printAcc();
                break;
            case 2: // Create
                printf("Enter bank name, owner's name, balance and VIP status (0: NO, 1: YES):\n");
                scanf("%s %s %ld %d", str1, str2, &am, &v);
                createAcc(str1, str2, am, (v == 1) ? VIP : REGULAR);
                break;
            case 3: // Transaction
                printf("Enter sender index, receiver index and amount:\n");
                scanf("%d %d %ld", &from, &to, &am);
                transaction(from, to, am);
                break;
            default: // EXIT
                printf("Bye!\n");
                return 0;
        }
        printf("-------------------\n");
    }
    return 0;
}

void printAcc() {

    for(int i=0; i<accCnt; i++)
    {
        printf("%d: %s %u %s %ld\n", i, acc[i].bkName, acc[i].accNum, acc[i].owner, acc[i].bal);
    }
    // Write your code here
}

void createAcc(BANK* bName, OWNER* oName, BALANCE bal, MEMBER status) {
        // Write your code here
    strcpy(acc[accCnt].bkName, bName);
    strcpy(acc[accCnt].owner, oName);
    
    acc[accCnt].bal = bal;
    acc[accCnt].mem = status;

    acc[accCnt].accNum = rand();

    accCnt++;
}

void transaction(int from, int to, BALANCE amount) {
    // Write your code her 
    
    if(acc[from].mem == 0)
    {
        acc[from].bal = acc[from].bal - amount - (amount * 0.05);
        acc[to].bal = acc[to].bal + amount;
    }
    else if(acc[from].mem == 1)
    {
        acc[from].bal = acc[from].bal - amount;
        acc[to].bal = acc[to].bal + amount;
    }
}
