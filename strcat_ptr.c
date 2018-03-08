#include <stdio.h>

void strcat(char *s, char *t)
{
    while(*s) {
        s++;
    }

    while(*s++ = *t++);
}

void strcpy(char *s, char *t)
{
    while (*s++ = *t++);
}

int main()
{
    char source[] = {'T', 'e', 's', 't', '\0', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', '\0' };
    char *target = "12345abCD";

    strcat(source, target);

    printf("%s\n", source);

    strcpy(source, target);

    printf("%s\n", source);
    return 0;
}
