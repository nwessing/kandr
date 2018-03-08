#include <stdio.h>

#define IS_LEAP_YEAR(year) year % 4 == 0 && year % 100 != 0 || year % 400 == 0

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = IS_LEAP_YEAR(year);

    if (month < 1 || month > 12) {
        printf("month must be between 1 and 12\n");
    }

    int daysInMonth = *(*(daytab + leap) + month);
    if (day < 1 || day > daysInMonth) {
        printf("day must be between 1 and %d\n", daysInMonth);
    }

    for (i = 1; i < month; i++) {
        day += (int) *(*(daytab + leap) + i);
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = IS_LEAP_YEAR(year);

    if (yearday <= 0) {
        printf("yearday must be greater than or equal to 0\n");
        return;
    }

    if (leap && yearday > 366) {
        printf("yearday must be 366 or less for a leap year\n");
        return;
    }

    if (!leap && yearday > 365) {
        printf("yearday must be 365 or less\n");
        return;
    }

    for (i = 1; yearday > *(*(daytab + leap) + i); i++) {
        yearday -= *(*(daytab + leap) + i);
    }

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    // printf("%d %d %d %d", daytab, *(*daytab), *(*daytab+1), *(*(daytab+1)+2));

    // return;

    day_of_year(1990, 9, 31);
    day_of_year(1990, 9, 0);
    printf("%d\n", day_of_year(2016, 2, 29));
    day_of_year(2017, 2, 29);

    printf("%d\n", day_of_year(1990, 9, 17));

    int pmonth;
    int pday;
    month_day(1990, 260, &pmonth, &pday);
    printf("%d-%d\n", pmonth, pday);

    month_day(1990, 0, &pmonth, &pday);
    month_day(1990, 366, &pmonth, &pday);

    month_day(2016, 366, &pmonth, &pday);
    printf("%d-%d\n", pmonth, pday);

    month_day(2016, 367, &pmonth, &pday);
}
