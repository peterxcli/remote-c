#include <stdio.h>
#include <stdlib.h>

#include <string.h>
char *exist(const char *str, char *substr) {
    for (char *iter = (char *)str; *iter != '\0'; iter++)
        if (*iter == *substr)
            return iter;
    return NULL;
}
char *start;
char *gettoken(char *str, const char *sep) {
    if (str != NULL) {
        start = NULL;
        for (char *iter = str; *iter != '\0'; iter++) {
            if (exist(sep, iter) == NULL) {
                start = iter;
                break;
            }
        }
        if (start == NULL)
            return NULL;
    }
    char *ret = NULL;
    for (char *iter = start; *iter != '\0'; iter++) {
        if (exist(sep, iter) != NULL) {
            // puts(iter);
            *iter = '\0';
            ret = strdup(start);
            start = iter + 1;
            break;
        }
    }
    for (char *iter = start; *iter != '\0'; iter++) {
        if (exist(sep, iter) == NULL) {
            start = iter;
            break;
        }
    }
    if (ret != NULL && *ret == '\0') return NULL;
    return ret;
}
int main() {
    char buffer[4096];
    char *sep = " \t\n;,.?!";
    char *word;
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(buffer, 4095, stdin);
        for (word = gettoken(buffer, sep); word != NULL; word = gettoken(NULL, sep)) {
            printf("%s\n", word);
        }
    }
}
