#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int type;
    char name[10];
    union utemp{
        int i;
        float f;
        double d;
    }u;
}stemp;

void power(stemp *s);

int main(void)
{
    stemp *s;
    int n;
    int j;
    printf("Number of Iterations : ");
    scanf("%d", &n);

    s = (stemp *)malloc(sizeof(stemp) * n);

    for(j=0; j<n; j++)
    {
        printf("Type [1 for int, 2 for float, 3 for double] : ");
        scanf("%d", &s[j].type);
        if(s[j].type==1)
        {
            strcpy(s[j].name, "integer");
            printf("Enter a integer value : ");
            scanf("%d", &s[j].u.i);
            power(&s[j]);
        }
        else if(s[j].type==2)
        {
            strcpy(s[j].name, "float");
            printf("Enter a float value : ");
            scanf("%f", &s[j].u.f);
            power(&s[j]);
        }
        else if(s[j].type==3)
        {
            strcpy(s[j].name, "double");
            printf("Enter a double value : ");
            scanf("%lf", &s[j].u.d);
            power(&s[j]);
        }
    }

    printf("------------Result------------\n");

    for(j=0; j<n; j++)
    {
        if(s[j].type==1)
        {
            printf("|%-10s| : %d\n", s[j].name, s[j].u.i);
        }
        else if(s[j].type==2)
        {
            printf("|%-10s| : %f\n", s[j].name, s[j].u.f);
        }
        else if(s[j].type==3)
        {
            printf("|%-10s| : %lf\n", s[j].name, s[j].u.d);
        }
    }

    return 0;
}

void power(stemp *s)
{
    if(s->type == 1)
    {
        s->u.i = s->u.i * s->u.i;
    }
    else if(s->type == 2)
    {
        s->u.f = s->u.f * s->u.f;
    }
    else if(s->type == 3)
    {
        s->u.d = s->u.d * s->u.d;
    }
}
