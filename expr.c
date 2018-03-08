#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

double stack[MAX_LEN];
int sp;
double pop();
void push(double);

int main(int argc, char *argv[])
{
    double result = 0;

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strlen(arg) == 1) {
            switch(arg[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    double op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    double op2_ = pop();
                    if (op2_ == 0.0) {
                        printf("ERROR: zero divisor\n");
                        return 1;
                    }
                    push(pop() / op2_);
                    break;
                default:
                    push(atof(arg));
                    break;
            }
        } else {
            push(atof(arg));
        }
    }

    printf("%f\n", pop());

    return 0;
}

void push(double val)
{
    if (sp >= MAX_LEN) {
        printf("ERROR: stack full");
        return;
    }

    // printf("%f\n", val);

    stack[sp] = val;
    sp++;
}

double pop()
{
    if (sp <= 0) {
        printf("ERROR: stack empty");
        return -1;
    }

    sp--;
    // printf("%f\n", stack[sp]);
    return stack[sp];
}