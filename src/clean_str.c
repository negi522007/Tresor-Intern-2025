/*
** EPITECH PROJECT, 2025
** Epitech
** File description:
** clean string
*/

#include "../include/receipt.h"

char *clean(char *str, char *delim, char *ret)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; str[i] != '\0' &&
        (check_char(str[i], delim) == 0 || str[i] == '\n'); i++);
    for (; str[i] != '\0'; i++) {
        if (check_char(str[i], delim) == 0)
            k++;
        if (check_char(str[i], delim) == -1)
            k = 0;
        if (k == 1 || k == 0) {
            ret[j] = str[i];
            j++;
        }
    }
    ret[j] = '\0';
    return ret;
}

char *clean_str(char *str, char *delim)
{
    int i = 0;
    char *ret = strdup(str);

    ret = clean(str, delim, ret);
    for (i = strlen(ret) - 1; i >= 0 &&
        (check_char(ret[i], delim) == 0 || ret[i] == '\n'); i--);
    ret[i + 1] = '\0';
    return ret;
}
