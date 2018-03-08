#include <stdio.h>
#include <time.h>

int main()
{
    int v[] =  { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50 };

    int bin1start = clock();
    // printf("%ld\n", bin1start);
    clock_t bin1result = binsearch1(38, v, 25);
    clock_t bin1score = clock() - bin1start;


    printf("bin1, answer: %d, time: %d\n", bin1result, bin1score);
}

int binsearch1(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid -1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;


    }

    return -1;
}