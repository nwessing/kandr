#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int *x = 15, *y = 7;
    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}