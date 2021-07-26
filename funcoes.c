#include "funcoes.h"
#include <stdbool.h>


void convMaiusculo(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            s[c] = s[c] - 32;
        }
        c++;
    }
}

void removeSalto(char *s) {
    while (*s) {
        if (*s == '\n') {
            *s='\0';
        }
        s++;
    }
}

// Separa pro VÍRGULA
char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}
