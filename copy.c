#include <stdio.h>

main()
{
    int c;

    printf("%d", EOF);

    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
}