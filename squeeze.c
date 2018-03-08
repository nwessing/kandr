#include <stdio.h>

void squeeze(char[], char[]);

int main()
{
    char source[] = "Quick brown fox";
    squeeze(source, "o ");

    printf("%s\n", source);
    return 0;
}

void squeeze(char s[], char r[])
{
    char cs;
    int i = 0;
    int k = 0;

    while ((cs = s[i]) != '\0') {
        char cr;
        int j = 0;
        int allowed = 1;
        while ((cr = r[j]) != '\0') {
            if (cr == cs) {
                allowed = 0;
            }
            ++j;
        }
        if (allowed) {
            s[k++] = s[i];
        }
        ++i;
    }

    s[k] = '\0';
}