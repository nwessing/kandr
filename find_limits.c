#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char %d to %d\n", 0, UCHAR_MAX);

    return 0;
}