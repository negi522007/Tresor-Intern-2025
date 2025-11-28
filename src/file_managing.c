/*
** EPITECH PROJECT, 2025
** receipt
** File description:
** manage file
*/

#include "../include/receipt.h"

int find_file(void)
{
    char *str = NULL;
    char *to_find = NULL;
    size_t size = 0;
    char *cache = NULL;
    char command[200];
    getline(&cache, &size, stdin);
    printf("\n\033[93mPour afficher toutes les quittances, veuillez entrer le mot clé \'show\'. Si vous recherchez une quittance particulière, entrez le mot clé \'find\' suivi d'un mot (chaine de caractère) et on vous affichera toutes les quittances commportant ce mot dans leur nom:\033[0m  ");
    getline(&cache, &size, stdin);
    printf("\n\n");
    //printf("%s", cache);
    str = strtok(cache, " \n");
    to_find = strtok(NULL, " \n");
    //printf("%s %s %s", cache, str, to_find);
    if (!strcmp(str, "show"))
        sprintf(command, "ls -R | grep %s", "AA");
    else if (to_find && !strcmp(str, "find"))
        sprintf(command, "ls -R | grep %s", to_find);
    else {
        free(cache);
        printf("\033[91mVotre requête est invalide.\033[0m\n\n");
        exit (84);
    }
    system(command);
    free(cache);
    printf("\n\n");
    exit(0);
}