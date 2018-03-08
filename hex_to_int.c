#include <stdio.h>
#include <math.h>

int htoi(char[]);
char to_lower(char);

int main()
{
    printf("%d\n", htoi("11"));
    return 0;
}

int htoi(char input[])
{
    int end = 0;
    int length = strlen(input);

    if (length > 1 && input[0] == '0' && to_lower(input[1]) == 'x') {
        end = 2;
    }

    int result = 0;
    int exponent = 0;
    for (int i = length - 1; i >= end; --i) {
        char c = input[i];
        result += hex_dig_to_i(c) * pow(16, exponent);
        exponent++;
    }

    return result;
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A') + 'a';
    }

    return c;
}

int hex_dig_to_i(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    char lower_c = to_lower(c);
    if (lower_c >= 'a' && lower_c <= 'f') {
        return (lower_c - 'a') + 10;
    }

    return c;
}