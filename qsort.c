#include <stdio.h>

void swap(int v[], int i, int j)
{
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last+1, right);
}

int main()
{
    int array[] = {22, 7, 8, 34, 19, 16, 1 };

    qsort(array, 0, 6);

    for (int i = 0; i < 7; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}
