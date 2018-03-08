#include <stdio.h>

void escape(char[], char[]);

int main()
{
    char target[1000];
    char source[1000];

    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        source[i] = c;
        i++;
    }

    escape(target, source);

    printf(target);

    return 0;
}

void escape(char target[], char source[])
{
    int is = 0, it = 0;
    int chars;
    while ((chars = source[is]) != EOF) {
        switch (chars) {
            case '\n':
                target[it] = '\\';
                target[it+1] = 'n';
                ++it;
                break;
            case '\t':
                target[it] = '\\';
                target[it+1] = 't';
                ++it;
                break;
            default:
                target[it] = chars;
                break;
        }
        ++is;
        ++it;
    }
}