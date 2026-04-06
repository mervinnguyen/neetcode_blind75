/**
 * @file strCopy.c
 * @brief Implements a simple string copy function for null-terminated strings
 * @author Mervin Nguyen
 * @date 2026-03-28
 * @version 1.0.0
 */

#include <stdio.h>

void str_copy(char *s, char *d) {
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

int main(void) {
    char s[8] = "ABCDEFG"; 
    char d[8];              
    str_copy(s, d);
    printf("%s\n", d);
    return 0;
}