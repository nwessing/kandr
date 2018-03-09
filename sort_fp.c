#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
            int (*comp)(void *, void *),
            int (*compmod)(int));
int numcmp(char *, char *);
int strcmp_ignore_case(char *, char *);
int reverse(int);
int noop(int);

int main(int argc, char *argv[])
{
    int nlines;
    int is_numeric = 0;
    int is_reverse = 0;
    int is_fold = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            printf("invalid input\n");
            return 1;
        }

        char *flag = argv[i];
        while (*(++flag) != '\0') {
            switch(*flag) {
                case 'n':
                    is_numeric = 1;
                    break;
                case 'r':
                    is_reverse = 1;
                    break;
                case 'f':
                    is_fold = 1;
                    break;
                default:
                    printf("invalid input flag\n");
                    return 1;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_((void **) lineptr, 0, nlines - 1, 
            (int (*)(void *, void *))(is_numeric ? numcmp : (is_fold ? strcmp_ignore_case : strcmp)),
            is_reverse ? reverse : noop);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}


int reverse(int val)
{
    return val * -1;
}

int noop(int val)
{
    return val;
}

void qsort_(void *v[], int left, int right, int (*comp)(void *, void *), int (*compmod)(int))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if(compmod((*comp)(v[i], v[left])) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort_(v, left, last - 1, comp, compmod);
    qsort_(v, last+1, right, comp, compmod);
}

int numcmp(char *s1, char *s2) 
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A') + 'a';
    }

    return c;
}

int strcmp_ignore_case(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        // int diff = *s2 - *s1;
        char ls1 = to_lower(*s1);
        char ls2 = to_lower(*s2);

        if (ls2 > ls1) {
            return -1;
        } else if (ls1 > ls2) {
            return 1;
        }

        s1++;
        s2++;
    }

    if (*s1 != '\0') {
        return -1;
    }

    if (*s2 != '\0') {
        return 1;
    }

    return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
