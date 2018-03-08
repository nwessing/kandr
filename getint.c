#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int n, array[SIZE], getint(int *);
int getch(void);
void ungetch(int);


int main()
{
    int result = 0;

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        // printf("%d\n", result);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    // while(getint(&result) != EOF) {
    // }

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) {
        // skip white space
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * (*pn) + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

#define BUFSIZE     100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}