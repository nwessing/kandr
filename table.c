#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

char *strdup_(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) 
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }

    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup_(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }

    if ((np->defn = strdup_(defn)) == NULL) {
        return NULL;
    }

    return np;
}

void undef(char *s)
{
    struct nlist *np;
    unsigned h = hash(s);
    np = hashtab[h];
    if (np == NULL) {
        return;
    }

    if (strcmp(s, np->name) == 0) {
        hashtab[h] = np->next;
        free(np->name);
        free(np->defn);
        free(np);
        return;
    }

    struct nlist *prev_np = np;
    while ((np = np->next) && np != NULL) {
        if (strcmp(s, np->name) == 0) {
            prev_np->next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            return;
        }
        prev_np = np;
    }
}

int main() 
{
    install("TEST", "ABC");
    install("macro", "cereal");

    printf("TEST: %s\n", lookup("TEST")->defn);
    printf("macro: %s\n", lookup("macro")->defn);

    install("TEST", "123");
    printf("TEST: %s\n", lookup("TEST")->defn);

    undef("TEST");
    printf("TEST: %s\n", lookup("TEST") == NULL ? "NULL" : "EXISTS");

    return 0;
}
