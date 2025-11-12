/*
** EPITECH PROJECT, 2025
** Epitech
** File description:
** check char
*/

#include "../include/receipt.h"

int check_char(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return 0;
    }
    return -1;
}
