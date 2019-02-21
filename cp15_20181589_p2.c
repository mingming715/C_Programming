#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}point;

int main(void)
{
    double s1_length;
    double s2_length;
    double s3_length;

    point house;
    point* s1;
    point* s2;
    point* s3;

    printf("house (x y) : ");
    scanf("%d %d", &house.x, &house.y);

   s1 = (point *)malloc(sizeof(point));
   s2 = (point *)malloc(sizeof(point));
   s3 = (point *)malloc(sizeof(point));

   printf("s1 (x y) : ");
   scanf("%d %d", &(s1->x), &(s1->y));
   
   printf("s2 (x y) : ");
   scanf("%d %d", &(s2->x), &(s2->y));

   printf("s3 (x y) : ");
   scanf("%d %d", &(s3->x), &(s3->y));

   s1_length = sqrt((house.x - s1->x)*(house.x - s1->x) + (house.y - s1->y)*(house.y - s1->y));

   s2_length = sqrt((house.x - s2->x)*(house.x - s2->x) + (house.y - s2->y)*(house.y - s2->y));

   s3_length = sqrt((house.x - s3->x)*(house.x - s3->x) + (house.y - s3->y)*(house.y - s3->y));

   if((s1_length < s2_length) && (s1_length < s3_length))
   {
       printf("1 %lf\n", s1_length);
   }
   else if((s3_length < s1_length) && (s3_length < s2_length))
   {
       printf("3 %lf\n", s3_length);
   }
   else
   {
       printf("2 %lf\n", s2_length);
   }
}
