#include <stdio.h>

void unescape(char[], char[]);

int main()
{
    char target[1000] = {0};
    char source[1000] = {0};

    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        source[i] = c;
        i++;
    }
    source[i] = EOF;

    unescape(target, source);

    printf(target);

    return 0;
}

void unescape(char target[], char source[])
{
    int is = 0, is_escape = 0, it = 0;
    char chars;

    while ((chars = source[is]) != EOF) {
        if (is_escape) {
            switch (chars) {
                case '\\':
                    target[it] = '\\';
                    break;
                case 't':
                    target[it] = '\t';
                    break;
                case 'n':
                    target[it] = '\n';
                    break;
                default:
                    target[it] = chars;
                    break;
            }
            it++;
            is_escape = 0;
        } else if (chars == '\\') {
            is_escape = 1;
        } else {
            target[it] = chars;
            it++;
        }

        ++is;
    }

    // target[it] = EOF;
}