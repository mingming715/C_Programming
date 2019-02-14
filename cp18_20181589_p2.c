#include <stdio.h>

typedef struct {
    int arr[10];
    char str[20];
    float f_arr[10];
}_struct;

typedef union {
    int arr[9];
    double d_arr[5];
    char str[39];
}_union;

int main(void)
{
    _struct s;
    _union u;

    int size_s;
    int size_u;

    size_s = sizeof(s.arr) + sizeof(s.str) + sizeof(s.f_arr);
    size_u = sizeof(u.d_arr);

    printf("sizeof(_struct) : %d, size_s = %d\n", (int)sizeof(_struct), size_s);
    printf("sizeof(_union) : %d, size_u = %d\n", (int)sizeof(_union), size_u);
}
