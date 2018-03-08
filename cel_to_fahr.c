#include <stdio.h>

main()
{
    float cels, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;

    cels = lower;

    printf("  C      F\n");
    while(cels <= upper) {
        fahr = ((9.0/5.0) * cels)  + 32;
        printf("%3.0f %6.1f\n", cels, fahr);
        cels += step;
    }
}