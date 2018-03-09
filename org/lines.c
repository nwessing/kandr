#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int getline_(char[], int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len + 1)) == NULL) {
            return -1;
        } else {
            // line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

int getline_(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n' || c == EOF) {
        s[i] = '\0';
        // ++i;
    }

    // s[i] = '\0';
    return i;
}