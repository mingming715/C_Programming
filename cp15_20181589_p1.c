#include <stdio.h>

typedef struct{
    int hours;
    int minutes;
    int seconds;
}time;

int main(void)
{
    time start;
    time finish;
    time* startPtr;
    time* finishPtr;

    startPtr = &start;
    finishPtr = &finish;

    printf("Starting Time : ");
    scanf("%d %d %d", &(*startPtr).hours, &(*startPtr).minutes, &(*startPtr).seconds);
    printf("Finishing Time : ");
    scanf("%d %d %d", &(*finishPtr).hours, &(*finishPtr).minutes, &(*finishPtr).seconds);
    
    int diff = ((*finishPtr).hours - (*startPtr).hours)*3600 + ((*finishPtr).minutes - (*startPtr).minutes)*60 + ((*finishPtr).seconds - (*startPtr).seconds);

    int ans_hr, ans_min, ans_sec;

    ans_hr = diff/3600;
    ans_min = (diff%3600)/60;
    ans_sec = (diff%3600)%60;

    printf("%d : %d : %d\n", ans_hr, ans_min, ans_sec);

    return 0;
}
