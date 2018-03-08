#include <stdio.h>

int any(char[], char[]);

int main()
{
    char source[] = "Hello";
    char find[] = "oabc";
    printf("%d\n", any(source, find));
    return 0;
}

int any(char source[], char find[])
{
    char csource;
    for (int i = 0; (csource = source[i]) != '\0'; ++i) {
        char cfind;
        for (int j = 0; (cfind = find[j]) != '\0'; ++j) {
            if (cfind == csource) {
                return i;
            }
        }
    }

    return -1;
}