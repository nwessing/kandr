#include <stdio.h>

int main()
{
    printf("Testing setbits(..)\n");
    printf("Expect e9, actual: %x\n", setbits(0xFF, 1, 4, 0x08));
    printf("Expect b8, actual: %x\n", setbits(0x99, 0, 6, 0x38));

    printf("\nTesting invert(..)\n");
    printf("Expect 49, actual: %x\n", invert(0x77, 1, 5));
    printf("Expect e6, actual: %x\n", invert(0xFA, 2, 3));
    // 1111 1010

    return 0;
}

/*
    return "x" with the "n" bits that begin at position "p"
    set to the rightmost "n" bits of "y" leaving the other
    bits unchanged
*/
int setbits(int x, int p, int n, int y)
{
    int ymask = ~(~0 << n);
    int xmask = (~0 << p + n) | ~(~0 << p);
    return (xmask & x) | (ymask & y);
}

/*
    returns "x" with the "n" bits that begin at position "p"
    inverted, leaving the other bits unchanged
*/
int invert(int x, int p, int n)
{
    int mask = ~((~0 << p + n) | ~(~0 << p));
    return (mask & ~x) | (~mask & x);
}

/*
    returns "x" rotated to the right be "n" positions
*/
int rightrot(int x, int n)
{
    return 0;
}