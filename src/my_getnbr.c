/*
** EPITECH PROJECT, 2025
** Epitech
** File description:
** get_nbr
*/

int my_getnbr(char *str)
{
    int sign = 1;
    int i = 2;
    int nbr = 0;

    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57) {
        nbr = ((nbr * 10) + str[i] - 48);
        i++;
    }
    nbr = nbr * sign;
    return nbr;
}
