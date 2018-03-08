#include <stdio.h>

int strend(char *s, char *t)
{
    char *s_start = s;
    char *t_start = t;

    while (*s) {
        s++;
    }
    while (*t) {
        t++;
    }

    for(; t >= t_start; s--, t--) {
        if (s < s_start) {
            return 0;
        }

        if (*s != *t) {
            return 0;
        }
    }

    return 1;

}

int main()
{
    char *a = "abc1234";
    char *b = "34";
    char *c = "zabc1234";
    char *d = "fff";

    printf("%s ends with %s ? %d\n", a, b, strend(a, b));
    printf("%s ends with %s ? %d\n", a, c, strend(a, c));
    printf("%s ends with %s ? %d\n", a, d, strend(a, d));
}