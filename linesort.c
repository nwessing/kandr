#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define HEAPSIZE 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *heap, int maxheap);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char heap[HEAPSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, heap, HEAPSIZE)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getline(char*, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines, char *heap, int maxheap)
{
    int len, nlines;

    char *p = heap, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len - heap > maxheap) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
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

int getline(char *line, int maxlen)
{
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < maxlen) {
        *line = c;
        line++;
        i++;

        if (c == '\n') {
            break;
        }
    }

    return i;
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
