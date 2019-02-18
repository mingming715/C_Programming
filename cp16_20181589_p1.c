#include <stdio.h>

 struct{
    struct{
        char Hall[3];
        int floor;
    } Where;
    struct{
        char menu[10];
        int num;
    } What;
} order;

int main(void)
{
    printf("Where? ");
    scanf("%s %d", (order.Where.Hall), &(order.Where.floor));
    printf("What? ");
    scanf("%s %d", (order.What.menu), &(order.What.num));
    printf("\n");
    printf("_________________________\n");
    printf("|                        |\n");
    printf("|     I want      |\n");
    printf("|   %d %-10s    |\n", order.What.num, order.What.menu);
    printf("|                   |\n");
    printf("|   Bring me on |\n");
    printf("|   %dF, Hall %-3s  |\n", order.Where.floor, order.Where.Hall);
    printf("|                   |\n");
    printf("-----   -----------------\n");
    printf("    |  /                 \n");
    printf("    | /                  \n");
    printf("    |/                   \n");
    printf("\n");
}
