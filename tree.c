#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

struct tnode *talloc();
char *strdup(char *s);

struct tnode *addtree(struct tnode *node, char *word)
{
    if (node == NULL) {
        node = talloc();
        node->word = strdup(word);
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int comp = strcmp(word, node->word);
    if (comp == 0) {
        node->count++;
    } else if (comp > 0) {
        node->right = addtree(node->right, word);
    } else {
        node->left = addtree(node->left, word);
    }

    return node;
}

void treeprint(struct tnode *node)
{
    if (node != NULL) {
        treeprint(node->left);
        printf("%4d %s\n", node->count, node->word);
        treeprint(node->right);
    }
}

struct tnode *talloc()
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

int getword(char *word, int lim)
{
    int c, getch();
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch())) {

    }

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
