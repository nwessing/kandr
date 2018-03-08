#include <stdio.h>

main()
{
    int c, last_c;
    last_c = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (last_c == 0) {
                putchar(' ');
            }

            last_c = 1;
        } else {
            putchar(c);
            last_c = 0;
        }
    }
}