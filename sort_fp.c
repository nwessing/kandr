#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            printf("invalid input\n");
            return 1;
        }

        char *flag = argv[i];
        while (*(++flag) != '\0') {
            switch(*flag) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("invalid input flag\n");
                    return 1;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_((void **) lineptr, 0, nlines - 1, 
            (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

// (int *(void *)(void *)) reverse(int (*comp)(void *, void *)) 
// {
//     return -1 * (*comp)
// }

void qsort_(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort_(v, left, last - 1, comp);
    qsort_(v, last+1, right, comp);
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

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
