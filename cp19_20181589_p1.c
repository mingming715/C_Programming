#include <stdio.h>

typedef struct _STAMP{
    char letter;
    struct _STAMP *next;
}STAMP;

int main(void)
{
    STAMP s1, s2, s3;
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &s1;
    int N;
    printf("Travel distance (cm): ");
    scanf("%d", &N);
    getchar();
    printf("Enter 3 letters for the stamps: ");
    scanf("%c%c%c", &(s1.letter), &(s2.letter), &(s3.letter));
    getchar();
    STAMP *current = &s1;

    for(int i=0; i<=N; i++)
    {
        printf("%c ", current->letter);
        current = current -> next;
    }

    printf("\n");

    return 0;
}
